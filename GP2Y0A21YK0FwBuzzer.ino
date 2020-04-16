#include "Tone32.h"
#include "SharpIR.h"
#include <Wire.h>

#define ANALOG_PIN 27
#define BUZZER_PIN 16
#define BUZZER_CHANNEL 0

int strength = 0;
int bg_strength = 0;

SharpIR mysensor(ANALOG_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("START TAKING THE BACKGROUND DATA. PLS GET OUT THE ROOM");
  delay(5000);
  bg_strength = mysensor.ir_strength();
}

void loop() {
  int current_value;
  for(int i = 0;1;i++)
  {
    strength = mysensor.ir_strength();
    float ratio = ((float)strength - (float)bg_strength)/(float)(bg_strength);
    Serial.print("TIME STAMP:");
    Serial.print(i);
    Serial.print(" ");
    Serial.print("strength:");
    Serial.print(strength);
    Serial.print(" ");
    Serial.print("bg strength:");
    Serial.print(bg_strength);
    Serial.print(" ");
    Serial.print("ratio:");
    Serial.print(ratio);
    Serial.println(" ");

    if(ratio > 1.5) 
    {
      tone(BUZZER_PIN, RA, 10, BUZZER_CHANNEL);
      noTone(BUZZER_PIN,BUZZER_CHANNEL);
    }

    delay(10);
  }
} 
