
// make tones by using pwm
// freq -> pitch
// duty -> volume (?)
// setting PWM properties
//const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
const int buzPin = 23;
const int duty = 128;
// variables
int sVal;
int dur;
int k;
int j;

int del;
int index1=0;
// notes
//enum Notes {C3=0, CS3, D3, DS3, E3, F3};
int nFrq[] = {/*131, 139, 147, 156, 165, 175*/
262,277,294,311,330,349,370,392,415,440,466,494,523,0};
int ndel[] = {2000,1500,1000,750,500,375,250};
void playNote(int note, int dur) {

ledcSetup(ledChannel, nFrq[note], resolution);
ledcWrite(ledChannel, duty);
//Serial.println(note);
//delay(ndel[dur]);
delay(ndel[dur]);
//Serial.println(ndel[dur]);
ledcSetup(ledChannel, 0, resolution);
//exit(0);

}
void testplay(int note, int dur){
  
  Serial.println(nFrq[note]);
  Serial.println(ndel[dur]);
  }
void setup() {
Serial.begin(115200);
ledcAttachPin(buzPin, ledChannel);
}
void loop(){
if (Serial.available() > 0) {

String inputStr = Serial.readStringUntil('\n');
//sVal = Serial.read();
//String inputStr = String(sVal);
for (int i = 0; i<98;i= i+2)
{
String st1 = String(inputStr[i]);
String st2 = String(inputStr[i+1]);
if(st1=="a"){
  st1 = "10";}
if (st1 =="b"){
  st1 ="11";}
if(st1=="c"){
  st1 = "12";}
if(st1==","){
  st1 = "13";}
  k = st1.toInt();
j = st2.toInt();
Serial.println(inputStr);
Serial.println(inputStr[i]);
Serial.println(inputStr[i+1]);
Serial.println(k);
Serial.println(j);
playNote(k, j);
//testplay(k,j);

//exit(0);
}


}
}
