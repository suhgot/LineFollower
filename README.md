# 🤖 Line Follower — Project_2.ino

> An Arduino-based line follower program that reads sensor input and makes movement decisions to follow a line.

---

## 🛠 Project Overview

This project reads line sensor values and decides whether to move straight, turn left, or turn right to follow a path.  

---

## 📋 File: `Project_2.ino`

This is the main Arduino sketch. It handles:

- Reading sensor input  
- Applying logic to determine direction  
- Controlling outputs based on decisions  

---

## ⚙️ How It Works

1. Continuously reads sensor values  
2. Determines the robot's position relative to the line  
3. Outputs direction commands accordingly  
4. Loops to keep the robot aligned on the line  

---

## 💡 Usage

```arduino
// Upload `Project_2.ino` to your Arduino board
// Adjust any thresholds or logic in the code if needed
// Place your robot on a track and run the program
