#define timeSeconds 20
// Set GPIOs for LED and PIR Motion Sensor
const int led[] = {16,17,5};


const int motionSensor = 36;
// Timer: Auxiliary variables
unsigned long now = millis();
unsigned long lastTrigger[] = {0,0,0};
boolean startTimer[] = {false,false,false};
int count = 0;
// Checks if motion was detected, sets LED HIGH and starts a timer
void IRAM_ATTR detectsMovement() {

if(count%3==0){
  Serial.println("MOTION DETECTED!!!");
digitalWrite(led[0], HIGH);

startTimer[0] = true;
lastTrigger[0] = millis();
count = count+1;
  }
else if(count%3==1){
  Serial.println("MOTION DETECTED!!!");
digitalWrite(led[1], HIGH);

startTimer[1] = true;
lastTrigger[1] = millis();
count = count+1;
  }
 else if(count%3==2){
  Serial.println("MOTION DETECTED!!!");
digitalWrite(led[2], HIGH);

startTimer[2] = true;
lastTrigger[2] = millis();
count = count+1;
  }
}
void setup() {
// Serial port for debugging purposes
Serial.begin(115200);
// PIR Motion Sensor mode INPUT_PULLUP
pinMode(motionSensor, INPUT_PULLUP);
// Set motionSensor pin as interrupt, assign interrupt function and set RISING mode
attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);
// Set LED to LOW
pinMode(led[0], OUTPUT);
digitalWrite(led[0], LOW);
pinMode(led[1], OUTPUT);
digitalWrite(led[1], LOW);
pinMode(led[2], OUTPUT);
digitalWrite(led[2], LOW);
}
void loop() {
// Current time
now = millis();
// Turn off the LED after the number of seconds defined in the timeSeconds variable
for (int i =0; i<3; i++){
  if (startTimer[i] && (now - lastTrigger[i] > (timeSeconds*1000))) {
Serial.println("Motion stopped...");
digitalWrite(led[i], LOW);

startTimer[i] = false;
}
  }


}
