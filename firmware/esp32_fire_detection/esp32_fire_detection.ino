
#include <DHT.h>  // Library for DHT11 temperature and humidity sensor

// Define the pins connected to the sensors and LED
#define MQ2_PIN 34       // MQ2 smoke sensor analog output pin
#define FLAME_PIN 32     // Flame sensor analog output pin
#define DHT_PIN 4        // DHT11 sensor data pin
#define LED_PIN 2        // LED pin for fire warning
#define DHT_TYPE DHT11   // Specify the sensor type as DHT11

// Create a DHT sensor object
DHT dht(DHT_PIN, DHT_TYPE);

// Set threshold values for detecting fire conditions
int smokeLimit = 1800;     // Smoke detection threshold
int flameLimit = 1000;     // Flame detection threshold
float tempLimit = 50.0;    // Temperature threshold in Celsius

void setup() {
  // Start serial communication for displaying sensor readings
  Serial.begin(115200);

  // Configure sensor pins as input and LED pin as output
  pinMode(MQ2_PIN, INPUT);
  pinMode(FLAME_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  // Keep the LED OFF initially
  digitalWrite(LED_PIN, LOW);

  // Initialize the DHT11 sensor
  dht.begin();

  // Display project information in the Serial Monitor
  Serial.println("Automatic Fire Detection Prototype");
  Serial.println("Suppression activation: SIMULATION ONLY");
}

void loop() {
  // Read smoke and flame sensor values
  int smokeValue = analogRead(MQ2_PIN);
  int flameValue = analogRead(FLAME_PIN);

  // Read temperature and humidity from the DHT11 sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check whether the smoke level exceeds the limit
  bool smokeDetected = smokeValue > smokeLimit;

  // Check whether the flame sensor value is below the limit
  bool flameDetected = flameValue < flameLimit;

  // Check whether the temperature reaches the set limit
  // isnan() checks whether the temperature reading is invalid
  bool highTemperature = !isnan(temperature) &&
                        temperature >= tempLimit;

  // Fire is detected if any one of the conditions is true
  bool fireDetected = smokeDetected ||
                      flameDetected ||
                      highTemperature;

  // Print a separator before displaying sensor readings
  Serial.println("\n-------------------------");

  // Display the smoke sensor value
  Serial.print("Smoke value: ");
  Serial.println(smokeValue);

  // Display the flame sensor value
  Serial.print("Flame value: ");
  Serial.println(flameValue);

  // Check whether the DHT11 readings are valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 reading failed");
  } else {
    // Display temperature in Celsius
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    // Display relative humidity as a percentage
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  // If any fire condition is detected
  if (fireDetected) {
    // Turn ON the LED as a warning indicator
    digitalWrite(LED_PIN, HIGH);

    // Display the fire warning message
    Serial.println("WARNING: POSSIBLE FIRE DETECTED");

    // Simulate a suppression request without activating equipment
    Serial.println("SUPPRESSION REQUEST - SIMULATION ONLY");
    Serial.println("REAL EXTINGUISHER NOT CONNECTED");

  } else {
    // If no fire condition is detected, turn OFF the LED
    digitalWrite(LED_PIN, LOW);

    // Display the normal status message
    Serial.println("No warning condition detected");
  }

  // Wait for one second before the next sensor reading
  delay(1000);
}
