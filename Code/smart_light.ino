// Smart Street Light using IR Sensor and LDR

int ldrPin = A0;     // LDR connected to analog pin A0
int irPin = 2;       // IR sensor connected to digital pin 2
int ledPin = 9;      // Street light LED connected to digital pin 9

int ldrValue = 0;
int threshold = 300; // Adjust based on your environment

void setup() {
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(ldrPin);
  int irValue = digitalRead(irPin);

  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" | IR Value: ");
  Serial.println(irValue);

  // Check if it's dark and motion is detected
  if (ldrValue < threshold || irValue == LOW) {
    digitalWrite(ledPin, HIGH); // Turn ON street light
  } else {
    digitalWrite(ledPin, LOW);  // Turn OFF street light
  }

  delay(200);
}

