#include <AWS_IOT.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)
#include <Arduino_JSON.h> 
#include <WiFi.h>
AWS_IOT testButton;
Adafruit_BME280 bme; // I2C
//const char* ssid = "KAU-Guest";
//const char* password = "";
const char* ssid = "hotspot";
const char* password = "asdf1234";
char HOST_ADDRESS[]="a12rtt9ccs87p3-ats.iot.ap-northeast-2.amazonaws.com";
char CLIENT_ID[]= "ChoiESP32";
char sTOPIC_NAME[]= "esp32/led"; // subscribe topic name
char pTOPIC_NAME[]= "esp32/bme280"; // publish topic name
int status = WL_IDLE_STATUS;
int msgCount=0,msgReceived = 0;
char payload[512];
char rcvdPayload[512];
const int ledPin = 16;
const int buttonPin = 15; // pushbutton pin
unsigned long preMil = 0; 
const long intMil = 5000; 
int delayTime;
void mySubCallBackHandler (char *topicName, int payloadLen, char *payLoad)
{
strncpy(rcvdPayload,payLoad,payloadLen);
rcvdPayload[payloadLen] = 0;
msgReceived = 1;
}

void setup() {
Serial.begin(115200);
pinMode(ledPin,OUTPUT);
//++choi This is here to force the ESP32 to reset the WiFi and initialize correctly.
Serial.print("WIFI status = ");
Serial.println(WiFi.getMode());
WiFi.disconnect(true);
delay(1000);
WiFi.mode(WIFI_STA);
delay(1000);
Serial.print("WIFI status = ");
Serial.println(WiFi.getMode()); //++choi
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.println("Connecting to WiFi..");
}
Serial.println("Connected to wifi");

if(testButton.connect(HOST_ADDRESS,CLIENT_ID)== 0) {
Serial.println("Connected to AWS");
delay(1000);
if(0==testButton.subscribe(sTOPIC_NAME,mySubCallBackHandler)) {
Serial.println("Subscribe Successfull");
}
else {
Serial.println("Subscribe Failed, Check the Thing Name and Certificates");
while(1);
}
}
else {
Serial.println("AWS connection failed, Check the HOST Address");
while(1);
}
// initialize the pushbutton pin as an input
pinMode(buttonPin, INPUT);
delay(2000);
Serial.println(F("BME280 test"));
// default settings
status = bme.begin(0x76); // bme280 I2C address = 0x76
if (!status) {
Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
Serial.print(" ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
Serial.print(" ID of 0x56-0x58 represents a BMP 280,\n");
Serial.print(" ID of 0x60 represents a BME 280.\n");
Serial.print(" ID of 0x61 represents a BME 680.\n");
while (1) delay(10);
}
Serial.println("-- Default Test --");
delayTime = 1000;
Serial.println();
}
void printValues() {
Serial.print("Temperature = ");
Serial.print(bme.readTemperature());
Serial.println(" *C");
Serial.print("Pressure = ");
Serial.print(bme.readPressure() / 100.0F);
Serial.println(" hPa");
Serial.print("Approx. Altitude = ");
Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
Serial.println(" m");
Serial.print("Humidity = ");
Serial.print(bme.readHumidity());
Serial.println(" %");
Serial.println();
} 
void loop() {
if(msgReceived == 1) {
msgReceived = 0;
Serial.print("Received Message:");
Serial.println(rcvdPayload);
JSONVar myObj = JSON.parse(rcvdPayload);
JSONVar state = myObj["state"];
String led = (const char*) state["led"];
Serial.println(led);
if (led == "ON"){
  digitalWrite(ledPin, HIGH);
  }
else if(led == "OFF"){
  digitalWrite(ledPin,LOW);
  }
else{
  ;
  }
}
if((millis()-preMil) > intMil) {
// read the state of the pushbutton value
if (digitalRead(buttonPin)) {
float t = bme.readTemperature();
float h = bme.readHumidity();
preMil = millis();
  printValues();
delay(delayTime);
sprintf(payload,"{\"temp\":%f,\"humid\":%f}",t,h);
if(testButton.publish(pTOPIC_NAME,payload) == 0) { 
Serial.print("Publish Message:");
Serial.println(payload);
}
else
Serial.println("Publish failed");
}
} 

}
