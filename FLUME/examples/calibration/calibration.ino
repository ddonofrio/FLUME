#include <FLUME.h>

const int FLOW_METER_PIN = 2;  // Pin conectado al caudalímetro
FLUME flume(FLOW_METER_PIN);   // Crea una instancia del objeto FLUME

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 bps
}

void loop() {
  delay(1000);
  
  // Obtiene los ticks acumulados y el caudal
  long accumulatedTicks = flume.getAccumulatedTicks();
  float flowRate = flume.getFlowRate();

  // Muestra los ticks acumulados y el caudal
  Serial.print("Accumulated Ticks: ");
  Serial.println(accumulatedTicks);
  Serial.print("Flow Rate: ");
  Serial.println(flowRate);

  flume.resetCounter();
}
