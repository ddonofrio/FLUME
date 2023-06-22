#include "FLUME.h"

volatile long* FLUME::_ticks = nullptr;

FLUME::FLUME(int pin) : _pin(pin), _ticksValue(0), _volumePerTick(DEFAULT_VOLUME_PER_TICK) {
    _ticks = &_ticksValue;
    pinMode(_pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(_pin), FLUME::_isr, RISING);
    _lastTime = millis();
}

void FLUME::setVolumePerTick(float volumePerTick) {
    _volumePerTick = volumePerTick;
}

void FLUME::resetCounter() {
    noInterrupts();
    *_ticks = 0;
    _lastTime = millis();
    interrupts();
}

long FLUME::getAccumulatedTicks() {
    noInterrupts();
    long ticks = *_ticks;
    interrupts();
    return ticks;
}

float FLUME::getAccumulatedVolume() {
    return getAccumulatedTicks() * _volumePerTick;
}

float FLUME::getFlowRate() {
    unsigned long now = millis();
    float flowRate = 1000.0 * getAccumulatedTicks() / (now - _lastTime);
    return flowRate;
}

void FLUME::_isr() {
    (*_ticks)++;                 
}
