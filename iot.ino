#include <ESP8266WiFi.h>

#define FLAME_SENSOR_PIN D5  // Digital pin D1 (GPIO 5)
#define RELAY_PIN D2         // Digital pin D2 (GPIO 4)
#define GAS_SENSOR_PIN A0    // Analog pin A0

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(FLAME_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Turn off the relay initially
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  // Read the flame sensor state (digital)
  int flameState = digitalRead(FLAME_SENSOR_PIN);
  
  // Read the gas sensor level (analog)
  int gasLevel = analogRead(GAS_SENSOR_PIN);
  
  // Print gas level to serial monitor
  Serial.print("Gas Level: ");
  Serial.println(gasLevel);
  
  // If flame is detected
  if (flameState == LOW) {  // Assuming LOW means flame detected
    Serial.println("Flame detected! Turning on the relay.");
    digitalWrite(RELAY_PIN, HIGH); // Turn on the relay
    
  } else {
    Serial.println("No flame detected. Relay is off.");
    digitalWrite(RELAY_PIN, LOW); // Turn off the relay
  }
  
  // Small delay to avoid spamming the serial monitor
  delay(1000);
}