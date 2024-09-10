#include <SoftwareSerial.h>

// Define the pins for the MP3 shield on the Uno
#define TX_PIN 10  // Connect to RX of DY-SV5W
#define RX_PIN 11  // Connect to TX of DY-SV5W

// Software serial for the MP3 shield
SoftwareSerial mp3(TX_PIN, RX_PIN);

void setup() {
  // Initialize serial communication with the Mega
  Serial.begin(9600);

  // Initialize serial communication with MP3 shield
  mp3.begin(9600);
  
  delay(500);  // Allow the MP3 shield to initialize
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the command from the Mega
    if (command >= 'A' && command <= 'N') {  // Check if command is within expected range ('A' to 'N' for 14 switches)
      playSound(command - 'A' + 1);  // Play corresponding sound (1 to 14)
    }
  }
}

void playSound(int soundNumber) {
  // Send command to play the specific sound file
  mp3.write(0xAA);  // Start byte
  mp3.write((uint8_t)0x07);  // Command for playing a file (cast to uint8_t)
  mp3.write((uint8_t)0x02);  // Data length (cast to uint8_t)
  mp3.write((uint8_t)0x00);  // High byte of the file number (cast to uint8_t)
  mp3.write((uint8_t)soundNumber);  // Low byte of the file number (cast to uint8_t)
  mp3.write((uint8_t)0xAC);  // Checksum (cast to uint8_t)
}
