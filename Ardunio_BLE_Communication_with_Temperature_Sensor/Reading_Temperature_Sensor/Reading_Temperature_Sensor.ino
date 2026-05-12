#include <OneWire.h>
#include <DallasTemperature.h>

// DS18B20 data wire connected to Arduino pin 2
#define ONE_WIRE_BUS 2

// Setup oneWire instance
OneWire oneWire(ONE_WIRE_BUS);

// Pass oneWire reference to DallasTemperature
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  Serial.println("DS18B20 Temperature Sensor Ready");
}

void loop() {
  // Request temperature from all sensors
  sensors.requestTemperatures();

  // Read temperature in Celsius
  float tempC = sensors.getTempCByIndex(0);

  // Convert to Fahrenheit
  float tempF = (tempC * 9.0 / 5.0) + 32.0;

  // Check if reading is valid
  if (tempC == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Sensor not connected!");
    return;
  }

  // Print results
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" °C  |  ");
  Serial.print(tempF);
  Serial.println(" °F");

  delay(1000); // Wait 1 second between readings
}