# 🚗 Intelligent Vehicle Speed Control System (RFID-Based)

An embedded system designed to **automatically regulate vehicle speed** in restricted and high-risk zones using **RFID technology**.  
Whenever the vehicle passes through an area with a specific RFID tag (School Zone, Hospital Zone, etc.), the system **limits the motor speed** accordingly.

---

## 📌 Features

- 📡 Detects RFID tag for different restricted zones  
- ⚡ Automatically adjusts vehicle speed using PWM  
- 🚦 Supports multiple predefined speed limit zones  
- 🛠 Fully built using **Arduino + RFID RC522 + Motor Driver**  
- 🔌 Simple and low-cost circuit  
- 🧪 Supports simulation (Tinkercad/Proteus)

---

## 🧩 System Architecture

---

## 🔧 Components Used

| Component | Description |
|----------|-------------|
| Arduino Uno | Main controller |
| RFID RC522 Module | Reads RFID tags |
| L293D Motor Driver | Controls motor speed |
| DC Motor | Represents vehicle |
| RFID Tags | Different restricted zones |
| Jumper wires | Connections |

---

## 🧠 Working Principle

1. Arduino continuously scans for an RFID tag  
2. When a card is detected, its **UID** is read  
3. The UID is compared with predefined zone UIDs  
4. According to the zone:  
   - School Zone → **speed limited to 40%**  
   - Hospital Zone → **speed limited to 30%**  
   - Normal Area → **full speed restored**  
5. Motor speed is controlled using **PWM on Pin 5**

---

## 🖥 Source Code

The complete Arduino code is available inside:



