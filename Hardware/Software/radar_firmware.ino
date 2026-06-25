#include <Servo.h>

// Define pins for Ultrasonic Sensor
const int trigPin = 10;   // Orange wire
const int echoPin = 11;   // Brown wire

// Define pin for Servo Motor
const int servoPin = 12;  // Yellow wire

// Define pin for Buzzer
const int buzzerPin = 9;  // Connect to Buzzer (+)

Servo radarServo;

// Safety distance threshold in centimeters
const int dangerZone = 15; 

void setup() {
  Serial.begin(9600);
  
  // Configure pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  radarServo.attach(servoPin);
}

void loop() {
  // Sweep from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    radarServo.write(angle);
    delay(30); 
    
    int distance = getDistance();
    checkRadarAlert(distance);
    
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.println(".");
  }
  
  // Sweep back from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    radarServo.write(angle);
    delay(30);
    
    int distance = getDistance();
    checkRadarAlert(distance);
    
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.println(".");
  }
}

// Function to calculate distance
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  if (distance > 40 || distance == 0) {
    distance = 40; 
  }
  
  return distance;
}

// Function to handle the buzzer alert logic
void checkRadarAlert(int distance) {
  if (distance < dangerZone) {
    // Play a tone (1000 Hz) for a short duration
    tone(buzzerPin, 1000);
    
    // Dynamically adjust delay based on closeness (closer = faster beeping)
    int beepDelay = map(distance, 2, dangerZone, 20, 150);
    delay(beepDelay);
    
    noTone(buzzerPin);
  } else {
    // Ensure buzzer is off if nothing is in the danger zone
    noTone(buzzerPin);
  }
}
