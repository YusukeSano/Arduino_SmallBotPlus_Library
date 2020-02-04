#ifndef SmallBotPlus_h
#define SmallBotPlus_h
#include "Arduino.h"

// MotorDriver Pin Assign on RDC.
#define M1_1  4 // Right motor
#define M1_2  9
#define M1_PWM  6
#define M2_1  7 // Left motor
#define M2_2  8
#define M2_PWM  5
#define PING_PIN  11 // Ultrasonic ranging sensor
#define BUTTON_PIN  12
#define LED_PIN  13

class SmallBotPlus {
public:
  void setup();
  int light();
  int slider();
  int sound();
  int resistance();
  long distance(int mode);
  void move(int Left, int Right);
  int Linetrace(int inside, int outside, int light);
};

#endif