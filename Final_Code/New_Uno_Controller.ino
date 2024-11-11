#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Setup for LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD setup for 16x2 display

// Communication with Mega
SoftwareSerial megaSerial(10, 11);  // RX, TX (Uno's pins 10 and 11)

// Variable to track the score
long score = 0;

void setup() {
  Serial.begin(9600);      // Debugging
  megaSerial.begin(9600);  // Communication with Mega

  lcd.init();              // Initialize the LCD
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Score: ");
}

void loop() {
  if (megaSerial.available()) {
    char incomingChar = megaSerial.read();  // Read the incoming byte
    
    static String commandBuffer = "";  // Store the entire command
    if (incomingChar != '\n') {
      commandBuffer += incomingChar;  // Add incoming character to the buffer
    } else {
      // Process the full command once a newline character is received
      processCommand(commandBuffer);
      commandBuffer = "";  // Clear the buffer
    }
  }
}

// Function to process the command from the Mega
void processCommand(String command) {
  Serial.print("Received command: ");
  Serial.println(command);
  
  int delimiterIndex = command.indexOf(':');
  if (delimiterIndex != -1) {
    String commandType = command.substring(0, delimiterIndex);
    String value = command.substring(delimiterIndex + 1);
    
    Serial.print("Command type: ");
    Serial.println(commandType);
    Serial.print("Value: ");
    Serial.println(value);

    if (commandType == "SCORE") {
      long newScore = value.toInt();  // Update the score

    if (newScore >= 0) {
        score = newScore;
        Serial.print("Updated score to: ");
        Serial.println(score);
        updateScoreDisplay();
      } else {
        Serial.println("Invalid score received, ignoring.");
      }
    }
  }
}

// Function to update the score on the LCD display
void updateScoreDisplay() {
  lcd.setCursor(7, 0);
  lcd.print("     ");   // Clear previous score
  lcd.setCursor(7, 0);
  lcd.print(score);     // Print the new score on the display
  Serial.print("Displayed score: ");
  Serial.println(score);
}
