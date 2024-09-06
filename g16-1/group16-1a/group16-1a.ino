int inputPin = A1; // Define the analog input pin

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
  pinMode(inputPin, INPUT); // Set the input pin as an input
}

void loop() {
  int sensorValue = analogRead(inputPin); // Read the analog value from the sensor
  Serial.print("Analog Value: "); // Print a label
  Serial.println(sensorValue); // Print the sensor value
  delay(1000); // Wait for 1 second before taking another reading
}
