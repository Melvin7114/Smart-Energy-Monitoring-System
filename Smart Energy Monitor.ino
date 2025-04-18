 // Smart Energy Monitoring System - Basic Version
// Components: ESP32, ACS712, ZMPT101B

// Sensor Pins
const int voltagePin = 34; // ZMPT101B (Analog)
const int currentPin = 35; // ACS712 (Analog)

// Calibration Constants (adjust as needed)
float voltageCalibration = 0.085; // V per unit
float currentCalibration = 0.100; // A per unit

// Variables
float voltage = 0;
float current = 0;
float power = 0;
float energy = 0;
unsigned long lastMillis = 0;

void setup() {
  Serial.begin(9600);
  delay(2000); // Give time to settle
  Serial.println("Smart Energy Monitor Started");
}

void loop() {
  voltage = readVoltage();
  current = readCurrent();
  power = voltage * current;

  // Energy calculation (Watt-hour)
  unsigned long now = millis();
  float timeDiff = (now - lastMillis) / 1000.0;
