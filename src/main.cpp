#include <Arduino.h>

int voltPin = A5;
int voltWrde;
int groenPin = 10;
int groenWrde;
int groenWrdeF;

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
  
  Serial.print(groenWrde);
  Serial.print(", ");
  Serial.println(groenWrdeF);
}