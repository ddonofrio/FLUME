#ifndef FLUME_H
#define FLUME_H

#include <Arduino.h>

const float DEFAULT_VOLUME_PER_TICK = 0.001;

class FLUME {
public:
    FLUME(int pin);                  // Constructor
    void setVolumePerTick(float volumePerTick); // M�todo para establecer el volumen por tick
    void resetCounter();             // M�todo para resetear el contador
    long getAccumulatedTicks();      // M�todo para obtener los ticks acumulados
    float getAccumulatedVolume();    // M�todo para obtener el volumen acumulado
    float getFlowRate();             // M�todo para obtener el flow rate en tiempo real

private:
    int _pin;                        // Pin al que se conecta el caudal�metro
    volatile long _ticksValue;       // Ticks acumulados desde el �ltimo reset
    float _volumePerTick;            // Volumen representado por cada tick
    unsigned long _lastTime;         // �ltimo momento en el que se midi� el flujo

    static volatile long* _ticks;    // Puntero est�tico a los ticks
    static void _isr();              // ISR para incrementar el contador de ticks
};

#endif //FLUME_H
