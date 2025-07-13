
## 🚪 RFID Based Door Lock System (Arduino UNO + RC522 + Relay)

### 🔧 How It Works (Simple Steps)

This project lets you **control a door or solenoid lock using RFID cards**. Only authorized cards can unlock the door for a short time. Unauthorized cards will trigger a buzzer and red light.

---

### 📑 Process Overview

#### 1. 🔌 **Connect the Hardware**

* Plug the **RC522 RFID module** to Arduino using SPI.
* Connect a **relay module** to control a **solenoid lock or electric strike**.
* Attach **LEDs and buzzer** for feedback.

You’ll need:

* Arduino UNO
* RC522 RFID Reader
* Relay Module
* Solenoid Lock / Door Strike
* Green & Red LEDs
* Buzzer
* Jumper Wires & Breadboard

#### 2. 📥 **Upload the Code**

* Open the provided `.ino` file in the `Arduino IDE`.
* Select the correct **COM port** and **board type (Arduino UNO)**.
* Click **Upload**.

#### 3. 🧾 **Scan RFID Card**

* Open **Serial Monitor** at `9600 baud`.
* Tap any RFID card/tag to the reader.
* You will see its **UID printed** in the Serial Monitor.

#### 4. ✅ **Add UID to Code**

* Copy the UID printed (like `04 A2 1C B3`) from Serial Monitor.
* Replace the placeholder in this line of code:

```cpp
if (content.substring(1) == "XX XX XX XX")
```

➡️ Like this:

```cpp
if (content.substring(1) == "04 A2 1C B3")
```

* Save and re-upload the code.

#### 5. 🔓 **Test the System**

* Tap the **authorized RFID card**:

  * ✅ Green LED turns ON
  * ✅ Relay unlocks the door (2 seconds)
* Tap **unauthorized cards**:

  * ❌ Red LED turns ON
  * ❌ Buzzer beeps (Access Denied)

---

### 💡 Extra Tips

* Make sure to **power the solenoid** with an **external power supply** (not from Arduino).
* Always use a **flyback diode** across the solenoid to protect components.
* You can add **multiple UID cards** for multiple users.

---
