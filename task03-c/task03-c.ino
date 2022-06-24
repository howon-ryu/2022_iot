// <Task 03-1>
// set pin numbers
const int buttonPin = 15; // the number of the pushbutton pin
const int ledPin = 16; // the number of the LED pin
const int touchPin = 4;
const int threshold = 40;
int touchValue;
boolean flag= false;
// variable for storing the pushbutton status
int buttonState = 0;
void setup() {
Serial.begin(115200);
// initialize the pushbutton pin as an input
pinMode(buttonPin, INPUT);
// initialize the LED pin as an output
pinMode(ledPin, OUTPUT);
}
void loop() {
// read the state of the pushbutton value
buttonState = digitalRead(buttonPin);

touchValue = touchRead(touchPin);
//Serial.print(touchValue);
// check if the pushbutton is pressed.
// if it is, the buttonState is HIGH
if (buttonState == HIGH || touchValue<threshold) {
// turn LED on
digitalWrite(ledPin, HIGH);

flag = !flag;
} else {
// turn LED off
digitalWrite(ledPin, LOW);
}
delay(250);
if (flag == 0){
  Serial.println(buttonState);
  Serial.println(flag);

  }

}
