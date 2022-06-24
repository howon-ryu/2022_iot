#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
/* sw spi
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11 */
#define BME_CS 5 // cs for esp32 vspi
#define SEALEVELPRESSURE_HPA (1013.25)
//Adafruit_BME280 bme; // I2C
Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI
int delayTime;

void setup() {
Serial.begin(115200);
Serial.println(F("BME280 test"));
bool status;
// default settings
status = bme.begin();
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
void loop() {
printValues();
delay(delayTime);
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
