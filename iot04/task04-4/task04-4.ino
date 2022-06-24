// make tones by using pwm
// freq -> pitch
// duty -> volume (?)
// setting PWM properties
//const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
const int buzPin = 1;
const int duty = 128;
// variables
int sVal;
// notes
//enum Notes {C3=0, CS3, D3, DS3, E3, F3};
int nFrq[] = {/*131, 139, 147, 156, 165, 175*/
277,262, 294, 330, 349, 392,440,494,523};
void playNote(int note, int dur) {
ledcSetup(ledChannel, nFrq[note], resolution);
ledcWrite(ledChannel, duty);
Serial.println(note);
delay(1000);
}
void setup() {
Serial.begin(115200);
ledcAttachPin(buzPin, ledChannel);
}
void loop(){
if (Serial.available() > 0) {
sVal = Serial.read();
playNote(sVal-0x30, 250);
}
}
