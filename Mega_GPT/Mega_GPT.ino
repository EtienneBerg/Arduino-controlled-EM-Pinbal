#include <SoftwareSerial.h>

// Define pins for 14 leaf switches on the Mega
const int switchPins[14] = {2, 3, 4, 5, 6, 7, 8, 9, 22, 23, 24, 25, 26, 27};

// Scores for each switch
const int scores[14] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140};

// Serial communication pins with Arduino Uno
#define TX_PIN 18  // Use TX1 (pin 18) for Serial1 communication
#define RX_PIN 19  // Use RX1 (pin 19) for Serial1 communication

// Score variable
volatile int totalScore = 0;

void setup() {
  // Set up serial communication with Arduino Uno
  Serial1.begin(9600); // Serial1 on Mega uses RX1/TX1 (pins 19 and 18)

  // Set up leaf switches as inputs with pull-up resistors
  for (int i = 0; i < 14; i++) {
    pinMode(switchPins[i], INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(switchPins[i]), switchTriggered, FALLING);
  }
}

void loop() {
  // Main loop does nothing; everything is handled by interrupts
}

void switchTriggered() {
  // Identify which switch triggered the interrupt and update score
  for (int i = 0; i < 14; i++) {
    if (digitalRead(switchPins[i]) == LOW) { // Check if this switch is triggered
      totalScore += scores[i];  // Increment score for the corresponding switch
      Serial1.write('A' + i);  // Send a command to Uno to play the corresponding sound ('A' for switch 0, 'B' for switch 1, etc.)
      delay(100);  // Debounce delay
    }
  }
}
