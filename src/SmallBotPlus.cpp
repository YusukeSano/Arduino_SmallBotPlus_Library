#include "SmallBotPlus.h"
#include "Arduino.h"

void SmallBotPlus::setup()
{
  // initialize the digital pin.
  pinMode(M1_1, OUTPUT);
  pinMode(M1_2, OUTPUT);
  pinMode(M1_PWM, OUTPUT);
  pinMode(M2_1, OUTPUT);
  pinMode(M2_2, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(PING_PIN,OUTPUT);
}

int SmallBotPlus::light()
{
  // reading light sensor
  return analogRead(A2);
}

int SmallBotPlus::slider()
{
  // reading slider
  return analogRead(A3);
}

int SmallBotPlus::sound()
{
  // reading sound sensor
  return analogRead(A4);
}
int SmallBotPlus::resistance()
{
  // reading resistance sensor
  return analogRead(A5);
}

long SmallBotPlus::distance(int mode)
{
  long duration, inches, cm;
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(PING_PIN, OUTPUT);
  digitalWrite(PING_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING_PIN, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(PING_PIN, INPUT);
  duration = pulseIn(PING_PIN, HIGH);

  // convert the time into a distance
  if(mode == 0){
    cm = duration / 29 / 2;
    return cm;
  }else{
    inches = duration / 74 / 2;
    return inches;
  }
}

void SmallBotPlus::move(int Left, int Right)
{
    digitalWrite(M1_1, HIGH);
    digitalWrite(M1_2, LOW);
    analogWrite(M1_PWM, Right); // MotorSpeed PWMvalue max:255
    digitalWrite(M2_1, HIGH);
    digitalWrite(M2_2, LOW);
    analogWrite(M2_PWM, Left);
}

int SmallBotPlus::Linetrace(int inside, int outside, int lightvalue)
{
  digitalWrite(LED_PIN, HIGH);// White LED lighting(Auxiliary light of brightness sensor)
  int threshold = SmallBotPlus().slider();
  if (lightvalue > threshold) {
    // Right turn
    SmallBotPlus().move(outside, inside);
    return 1;
  } else {
    // Left turn
    SmallBotPlus().move(inside, outside);
    return -1;
  }
}