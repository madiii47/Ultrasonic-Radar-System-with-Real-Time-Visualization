# Ultrasonic Radar System with Real-Time Visualization

A hardware-software co-design project that implements a localized radar system using an Arduino UNO microcontroller for data acquisition and Processing IDE for real-time graphical visualization. The system continuously scans a 180-degree field of view to detect object proximity and distance, utilizing a synchronized buzzer for physical proximity alerts.

---

## System Features

* **Automated 180-degree Scanning:** Driven by a SG90 servo motor executing continuous micro-steps from 0 to 180 degrees and back.
* **Time-of-Fight (ToF) Distance Calculation:** Leverages ultrasonic sound wave reflections to compute target distances in real time.
* **Dynamic Hardware Alerts:** Integrates a physical buzzer subsystem that triggers an audio alert when a target breaches a preset danger threshold.
* **Real-Time Radar Display:** Features an interactive, radar-like software UI that highlights detected obstacles dynamically using color-coded metrics.

---

## Working Principle

The system relies on the physical Time-of-Flight (ToF) principle of high-frequency ultrasonic waves.

1. **Hardware Scanning:** The Arduino steps the servo motor sequentially across a 180-degree arc. At every angular interval, the HC-SR04 sensor emits a high-frequency sonic burst.
2. **Distance Extraction:** If an object is present, the waves reflect back and are captured by the receiver. The Arduino calculates the physical distance using the sound propagation delay equation:
   
   Distance = (Time of Flight * Speed of Sound) / 2

3. **Data Streaming and Visualization:** The computed angle and distance parameters are packed and piped sequentially to a host PC over standard Serial Communication (UART protocol at a 9600 baud rate). The Processing software environment decodes the stream to render a live sweep animation, painting detected objects as active targets on screen.

---

## Hardware Specifications and Pin Mapping

### Component List

* **Microcontroller:** Arduino UNO
* **Distance Sensor:** HC-SR04 Ultrasonic Sensor
* **Actuator:** SG90 Micro Servo Motor
* **Alert Subsystem:** 5V Active Buzzer
* **Prototyping:** Breadboard, USB Interface Cable, and Solid/Stranded Jumper Wires

### Pin Connection Table

| Component | Component Pin | Arduino UNO Pin |
| :--- | :--- | :--- |
| HC-SR04 Ultrasonic Sensor | VCC | 5V |
| | Trig (Trigger) | Digital Pin 10 |
| | Echo | Digital Pin 11 |
| | GND | GND |
| SG90 Servo Motor | Power (Red) | 5V |
| | Signal (Yellow/Orange) | Digital Pin 12 |
| | Ground (Brown/Black) | GND |
| Buzzer | Positive (+) | Digital Pin 7 |
| | Negative (-) | GND |

---

## Project Structure

```text
├── Hardware/
│   └── radar_firmware.ino    # Arduino sketch for sensor control and data transmission
├── Software/
│   └── radar_ui.pde          # Processing script for graphical radar visualization
└── Docs/
    └── Project_Report.pdf    # Full documentation and circuit references
```
How to Setup and Run
Hardware Assembly: Wire the hardware components together on a breadboard using the designated Pin Connection Table.

Deploy Firmware:

Open Hardware/radar_firmware.ino in the Arduino IDE.

Connect your Arduino UNO to your PC via a USB cable.

Select your board type, match the correct COM port, and hit Upload.

Launch Visualization:

Download and launch the Processing IDE.

Open Software/radar_ui.pde.

Verify that the serial index string matches the COM port assigned to your Arduino board.

Run the Processing script to open up your real-time graphical radar interface.
