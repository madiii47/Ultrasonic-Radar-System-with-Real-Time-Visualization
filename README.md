Ultrasonic Radar System with Real-Time Visualization
A hardware-software co-design project that implements a localized radar system using an Arduino UNO microcontroller for data acquisition and Processing IDE for real-time graphical visualization. The system continuously scans a 180-degree field of view to detect object proximity and distance, utilizing a synchronized buzzer for physical proximity alerts.

System Features
Automated 180-degree Scanning: Driven by a SG90 servo motor executing continuous micro-steps from 0 to 180 degrees and back.

Time-of-Fight (ToF) Distance Calculation: Leverages ultrasonic sound wave reflections to compute target distances in real time.

Dynamic Hardware Alerts: Integrates a physical buzzer subsystem that triggers an audio alert when a target breaches a preset danger threshold.

Real-Time Radar Display: Features an interactive, radar-like software UI that highlights detected obstacles dynamically using color-coded metrics.

Working Principle
The system relies on the physical Time-of-Flight (ToF) principle of high-frequency ultrasonic waves.

Hardware Scanning: The Arduino steps the servo motor sequentially across a 180-degree arc. At every angular interval, the HC-SR04 sensor emits a high-frequency sonic burst.

Distance Extraction: If an object is present, the waves reflect back and are captured by the receiver. The Arduino calculates the physical distance using the sound propagation delay equation:

Distance = (Time of Flight * Speed of Sound) / 2

Data Streaming and Visualization: The computed angle and distance parameters are packed and piped sequentially to a host PC over standard Serial Communication (UART protocol at a 9600 baud rate). The Processing software environment decodes the stream to render a live sweep animation, painting detected objects as active targets on screen.

Hardware Specifications and Pin Mapping
Component List
Microcontroller: Arduino UNO

Distance Sensor: HC-SR04 Ultrasonic Sensor

Actuator: SG90 Micro Servo Motor

Alert Subsystem: 5V Active Buzzer

Prototyping: Breadboard, USB Interface Cable, and Solid/Stranded Jumper Wires
Pin Connection TableComponentComponent PinArduino UNO PinHC-SR04 Ultrasonic SensorVCC5VTrig (Trigger)Digital Pin 10EchoDigital Pin 11GNDGNDSG90 Servo MotorPower (Red)5VSignal (Yellow/Orange)Digital Pin 12Ground (Brown/Black)GNDBuzzerPositive (+)Digital Pin 7Negative (-)GND
