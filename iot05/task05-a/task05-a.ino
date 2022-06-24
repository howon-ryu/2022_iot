const int trigPin = 22;
const int echoPin = 21;
const int ledChannel = 0;
const int resolution = 8;
const int buzPin = 23;
const int duty = 128;
int sVal;
int nFrq[] = {/*131, 139, 147, 156, 165, 175*/
277,262, 294, 330, 349, 392,440,494,523};

void playNote(int note, int dur) {
ledcSetup(ledChannel, note , resolution);
ledcWrite(ledChannel, duty);
Serial.println(note);

//ledcSetup(ledChannel, 0, resolution);
}

void setup()
{
ledcAttachPin(buzPin, ledChannel);
Serial.begin(115200);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}
void loop()
{
long duration, distance;
//Triggering by 10us pulse
digitalWrite(trigPin, LOW); // trig low for 2us
delayMicroseconds(2);
digitalWrite(trigPin, HIGH); // trig high for 10us
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
//getting duration for echo pulse
duration = pulseIn(echoPin, HIGH);
//sound speed = 340 m/s = 34/1000 cm/us
//distance = duration * 34/1000 * 1/2
distance = duration * 17 / 1000;
if (distance>30){
  sVal = 131;
  }
else if(distance<=30&&distance>25){
  sVal = 175;
  
  }
else if(distance<=25&&distance>20){
  sVal = 262;
  }
else if(distance<=20&&distance>15){
  sVal = 294;
  }
else if(distance<=15&&distance>10){
  sVal = 330;
  }
else if(distance<=10&&distance>5){
  sVal = 349;
  }
else if(distance<=5&&distance>4){
  sVal = 392;
  }
else if(distance<=4&&distance>2){
  sVal = 440;
  }
else{
  sVal = 523;
  }
Serial.print(distance);
Serial.print("cm");
playNote(sVal, 50);
Serial.println();
delay(50);


}
