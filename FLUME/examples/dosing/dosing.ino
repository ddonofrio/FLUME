#include <FLUME.h>

FLUME flume(2);
int waterPumpPin = 3;
int target = 100;

void setup() {
  Serial.begin(9600);
  pinMode(waterPumpPin, OUTPUT);
  analogWrite(waterPumpPin, 0);
  flume.resetCounter();
}

bool run = true;
float duty = 255;
const unsigned long interval = 500;
unsigned long currentMillis = millis();
unsigned long previousMillis = currentMillis;

void loop() {
  if (run) {

    if (flume.getAccumulatedTicks() >= target * 0.9) {
      duty = map(flume.getAccumulatedTicks(), target * 1.5, 0, 0, 255);
    }

    if (flume.getAccumulatedTicks() >= target) {
      duty = 0;
      run = false;
    }
    analogWrite(waterPumpPin, duty);


    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      Serial.print("Accumulated Ticks: ");
      Serial.print(flume.getAccumulatedTicks());
      Serial.print(" | Target: ");
      Serial.print(target);
      Serial.print(" | Duty: ");
      Serial.println(duty);
    }
  }
}
