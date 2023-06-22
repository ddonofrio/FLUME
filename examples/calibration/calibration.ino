#include <FLUME.h>

const int FLOW_METER_PIN = 2;  
FLUME flume(FLOW_METER_PIN);   

void setup() {
  Serial.begin(9600); 
}

void loop() {
  delay(1000);
  
  long accumulatedTicks = flume.getAccumulatedTicks();
  float flowRate = flume.getFlowRate();

  Serial.print("Accumulated Ticks: ");
  Serial.println(accumulatedTicks);
  Serial.print("Flow Rate: ");
  Serial.println(flowRate);

  flume.resetCounter();
}
