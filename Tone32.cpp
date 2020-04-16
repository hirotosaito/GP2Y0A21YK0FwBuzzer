#include "Tone32.h"

void tone(uint8_t pin, unsigned int frequency, unsigned long duration, uint8_t channel)
{
    if (ledcRead(channel)) {
        log_e("Tone channel %d is already in use", ledcRead(channel));
        return;
    }
    ledcAttachPin(pin, channel);
    ledcWriteTone(channel, frequency);
    if (duration) {
        delay(duration);
        noTone(pin, channel);
    }    
}

void noTone(uint8_t pin, uint8_t channel)
{
    ledcDetachPin(pin);
    ledcWrite(channel, 0);
}

void TokinoUta(int PIN,int CHANNEL){
  tone(PIN, RA, 500, CHANNEL);
  noTone(PIN,CHANNEL);

  tone(PIN, RE, 700, CHANNEL);
  noTone(PIN,CHANNEL);

  tone(PIN, FA, 500, CHANNEL);
  noTone(PIN,CHANNEL);

  tone(PIN, RA, 500, CHANNEL);
  noTone(PIN,CHANNEL);

  tone(PIN, RE, 800, CHANNEL);
  noTone(PIN,CHANNEL);

  tone(PIN, FA, 700, CHANNEL);
  noTone(PIN,CHANNEL);
}