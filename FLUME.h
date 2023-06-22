#ifndef FLUME_H
#define FLUME_H

#include <Arduino.h>

const float DEFAULT_VOLUME_PER_TICK = 0.001;

class FLUME {
public:
    FLUME(int pin);                  // Constructor
    void setVolumePerTick(float volumePerTick); // Método para establecer el volumen por tick
    void resetCounter();             // Método para resetear el contador
    long getAccumulatedTicks();      // Método para obtener los ticks acumulados
    float getAccumulatedVolume();    // Método para obtener el volumen acumulado
    float getFlowRate();             // Método para obtener el flow rate en tiempo real

private:
    int _pin;                        // Pin al que se conecta el caudalímetro
    volatile long _ticksValue;       // Ticks acumulados desde el último reset
    float _volumePerTick;            // Volumen representado por cada tick
    unsigned long _lastTime;         // Último momento en el que se midió el flujo

    static volatile long* _ticks;    // Puntero estático a los ticks
    static void _isr();              // ISR para incrementar el contador de ticks
};

#endif //FLUME_H
