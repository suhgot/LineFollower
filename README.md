# 🤖 Line Follower — Project_2.ino

> An Arduino-based line follower project that lets a robot follow a line using sensors and motor control.

---

## 🛠 Project Overview

This project uses sensors to detect a line on the ground and controls motors to follow the line automatically. Ideal for robotics beginners or anyone wanting to build a basic autonomous robot.  

---

## 📋 File: `Project_2.ino`

This is the main sketch for the line follower robot. It includes:

- Reading input from line sensors  
- Decision logic to determine if the robot should go straight, turn left, or turn right  
- Driving motors accordingly  
- Possibly calibration/thresholding of sensor values  

---

## ⚙️ How It Works

1. Sensor values are continuously read.  
2. Based on thresholds, the code decides which direction the robot should move.  
3. Motors are driven to steer the robot so it stays on the line.  
4. Loops to keep updating while powered.

---

## 💡 Usage

To use this code:

```arduino
// Upload `Project_2.ino` to your Arduino:
// 1. Connect line sensors (e.g. photoresistor) to analog/digital pins.
// 2. Connect motors via the driver.
// 3. Power everything safely.
// 4. Optionally, adjust sensor thresholds or calibration values in the code.

// Then:
// Press Upload in Arduino IDE
// Place robot on a line (usually black line on white background).
// Watch the robot follow the line!
