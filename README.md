# Smart_Street_Light_System
Smart  street light system using IR sensor and LDR with Arduion

This project implements a smart street light system using an **IR sensor** and a **photoresistor (LDR)**.  
The light turns ON only when it is dark and motion is detected, helping save energy.

---

🔧 Components Used
- Arduino Uno
- IR Sensor Module
- LDR (Photoresistor)
- 10kΩ Resistor
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires

---

⚙️ Working Principle
1. The LDR checks whether it is day or night.
2. If it is night (low light condition):
   - The IR sensor detects motion.
   - The street light turns ON.
3. If there is no motion or it is daytime:
   - The light remains OFF.

---

🔌 Circuit Connections
| Component | Arduino Pin |
1. IR sensor| Arduion Pin |
    ~ VCC - 5V
    ~ GND - GND
    ~ OUT - D2
2.   LED    | Arduion Pin |
    ~ Cathode(-) - GND
    ~ Anode(+)  - D9
     220Ω Resistor between anode and D9 pin.
 3.   LDR   | Arduion Pin |
     ~ one side - 5V
     ~ other side - A0
     10kΩ Resistor between other side and A0 pin.
---

💻 Arduino Code
// Smart Street Light using IR Sensor and LDR

int ldrPin = A0;
int irPin = 2;
int ledPin = 9;

int threshold = 500;

void setup() {
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int irValue = digitalRead(irPin);

  if (ldrValue < threshold && irValue == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}

---

📸 Output

~ Street light turns ON only at night when motion is detected.
~ Saves electricity and reduces manual control.

🚀 Future Improvements

~ Use multiple LEDs for multiple street lights
~ Add dimming using PWM
~ Connect to IoT for remote monitoring

👨‍🎓 Author

DeepthigaPrem
ECE / PSNACET
