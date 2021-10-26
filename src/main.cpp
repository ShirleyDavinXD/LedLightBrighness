#include <Arduino.h>
#include "runtimer.h"

int voltPin = A5;
int voltWrde;
int groenPin = 10;
int groenWrde;
int groenWrdeF;

intervalTimer writeOutputTimer(100);
intervalTimer readInputTimer(25);
intervalTimer displayWaardenTimer(500);

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
  if (writeOutputTimer.expired())
  {
    Serial.print("Waarde sensor: ");
    Serial.print(groenWrde);
    Serial.print(", ");
    Serial.print("Felheid Licht: ");
    Serial.println(groenWrdeF);
  }
  
}