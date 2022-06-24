#include <EEPROM.h>

const int ledChannel = 0;
const int resolution = 8;
const int buzPin = 23;
const int duty = 128;

// variables
int vNote=0, vDur=0, i ;
int eep;
const int dDur = 250; // default duration

// notes
//enum Notes {C3=0, CS3, D3, DS3, E3, F3};
int nFrq[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523};
int nDur[] = { 2000, 1500, 1000, 750, 500, 375, 250 };

void playNote(int note, int dur) {
  // 소리 묵음
  if (note == -1) {
    ledcSetup(ledChannel, 0, resolution);
    ledcWrite(ledChannel, 0);
  }
  else {
    ledcSetup(ledChannel, nFrq[note], resolution);
    ledcWrite(ledChannel, duty);
  }
  Serial.println(String(note)+","+String(dur));
  delay(nDur[dur]);
}

void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);
  // attach the channel to the GPIOs
  ledcAttachPin(buzPin, ledChannel);
  eep=0;
  i=1;
  if(EEPROM.read(0)=='l'){
    for(int i = 1; i < 512; i+=2){
      int eepnote = EEPROM.read(i);
      int eepdur = EEPROM.read(i+1);
      playNote(eepnote, eepdur);
    }
  }
}

void loop(){
  
  if (Serial.available() > 0) {
    vNote = Serial.read();
    Serial.println(vNote);
    if(vNote=='<'){
      vNote = Serial.read();
      eep=1;
      EEPROM.write(0, 'l');
    }      
    if (Serial.available() > 0) {
      vDur = Serial.read();
      if (vDur <= '6' && vDur >= '0')
        vDur -= '0';
      else vDur = dDur;
      if (vNote <= '9' && vNote >= '0')
        vNote -= '0';
      else if (vNote <= 'c' && vNote >= 'a')
        vNote = vNote - 'a' + 10;
      else if(vNote == ',')
        vNote = -1; // rest
      else if(vNote == '>')
        vNote = -1;
      playNote(vNote, vDur);
      if(eep==1){
        EEPROM.write(i, vNote);
        EEPROM.write(i+1, vDur);
        i+=2;
        EEPROM.commit();
      }
    }
  }
}
