#include <Arduino.h>
#include "runtimer.h"

int voltPin = A5;
int voltWrde;
int groenPin = 10;
int groenWrde;
int groenWrdeF;

unsigned long time;

intervalTimer displayWaardenTimer(1000);

void setup() {
  pinMode(voltPin,INPUT);
  pinMode(groenPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  voltWrde = analogRead(voltPin);
  
  groenWrde = (255./1023.)*voltWrde;
  groenWrdeF = 255-groenWrde;
  analogWrite(groenPin, groenWrdeF);
  time = millis();

  if (displayWaardenTimer.expired())
  {
    Serial.print("Waarde sensor: ");
    Serial.print(groenWrde);
    Serial.print(", ");
    Serial.print("Felheid Licht: ");
    Serial.println(groenWrdeF);

    Serial.print(time /1000);
    Serial.print(" seconden");
    Serial.println();
  }
}