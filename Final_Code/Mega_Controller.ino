// Pin Definitions for switches
//const int alllanes = 5;
const int laneASwitch = 2;//reg
const int laneBSwitch = 11;//reg
const int laneCSwitch = 12;//reg
const int laneDSwitch = 13;//reg
const int spinnerSwitch = 52;
const int bottomLaneSwitch = 26;
const int alleyRolloverSwitch = 4;
//const int alllaneswitch = 5;
const int rolloverswitchA = 6;//reg reg
const int rolloverswitchB = 7;//7
const int rolloverswitchC = 8;//8
const int rolloverswitchD = 10;  //reg


// Bonus Point LEDs
const int bonusLight1000 = 30;
const int bonusLight2000 = 30;
const int bonusLight3000 = 32;
const int bonusLight4000 = 32;
const int bonusLight5000 = 34;
const int bonusLight6000 = 38;
const int bonusLight7000 = 36;
const int bonusLight8000 = 44;
const int bonusLight9000 = 42;
const int bonusLight10000 = 40;
//extra bonus
const int greenBonusLight = 48;
const int redBonusLight = 46;
//alley lights
const int alleyScoreBonusLight = 47;//special
const int alleySpecialBonus500 = 28;
const int alleySpecialBonus1000 = 24;
const int alleySpecialBonus2000 = 51;
const int alleySpecialBonus3000 = 45;
const int alleySpecialBonus4000 = 49;
const int alleySpecialBonus5000 = 53;
const int alleySpecialBonusRed = 51;
const int alleyLed = 3;
const int spinnerLed = 50; 


// Lane LEDs
const int laneALed = 37;//almal reg
const int laneBLed = 39;//*
const int laneCLed = 41;//*
const int laneDLed = 43;//*

//variables to count lane led ontime
bool laneALedON = false;
unsigned long laneALedTime = 0;
bool laneBLedON = false;
unsigned long laneBLedTime = 0;
bool laneCLedON = false;
unsigned long laneCLedTime = 0;
bool laneDLedON = false;
unsigned long laneDLedTime = 0;

bool alleyLEDON = false;
unsigned long alleyLEDTime = 0;

// Rollover LEDs
const int rolloverALed = 35;//Almal reg
const int rolloverBLed = 31; //*
const int rolloverCLed = 9; //*
const int rolloverDLed = 33;//*

//variables to count rollover led ontime
bool rolloverALedON = false;
unsigned long rolloverATime = 0;
bool rolloverBLedON = false;
unsigned long rolloverBTime = 0;
bool rolloverCLedON = false;
unsigned long rolloverCTime = 0;
bool rolloverDLedON = false;
unsigned long rolloverDTime = 0;

// Scoring Variables
int score = 0;
int bonusScore = 1000;
int maxBonusScore = 15000;
int alleyScore = 0;
int maxAlleyScore = 5000;
bool bonusLit = false;    //*** Not Used
bool spinnerLit = false;  //*** Not Used
bool alleyArrowsLit = false;

// For Bonus Score LEDs
unsigned long bonusLedTime = 0;
bool bonusLedOn = false;
int currentBonusLed = 0;

// For Alley Bonus LEDs
unsigned long alleyBonusLedTime = 0;
bool alleyBonusLedOn = false;
int currentAlleyBonusLed = 0;

// Setup function
void setup() {
  Serial.begin(9600);  // For debugging
  Serial1.begin(9600); // Communication with Arduino Uno
  
  // Set all LED pins as OUTPUT
  pinMode(bonusLight1000, OUTPUT);          //****        chechk bonus values
  pinMode(bonusLight2000, OUTPUT);
  pinMode(bonusLight3000, OUTPUT);
  pinMode(bonusLight4000, OUTPUT);
  pinMode(bonusLight5000, OUTPUT);
  pinMode(bonusLight6000, OUTPUT);
  pinMode(bonusLight7000, OUTPUT);
  pinMode(bonusLight8000, OUTPUT);
  pinMode(bonusLight9000, OUTPUT);
  pinMode(bonusLight10000, OUTPUT);

  pinMode(alleySpecialBonus500, OUTPUT);
  pinMode(alleySpecialBonus1000, OUTPUT);
  pinMode(alleySpecialBonus2000, OUTPUT);
  pinMode(alleySpecialBonus3000, OUTPUT);
  pinMode(alleySpecialBonus4000, OUTPUT);
  pinMode(alleySpecialBonus5000, OUTPUT);


  pinMode(greenBonusLight, OUTPUT);
  pinMode(redBonusLight, OUTPUT);
  pinMode(alleyScoreBonusLight, OUTPUT);
  pinMode(laneALed, OUTPUT);
  pinMode(laneBLed, OUTPUT);
  pinMode(laneCLed, OUTPUT);
  pinMode(laneDLed, OUTPUT);
  pinMode(rolloverALed, OUTPUT);
  pinMode(rolloverBLed, OUTPUT);
  pinMode(rolloverCLed, OUTPUT);
  pinMode(rolloverDLed, OUTPUT);
  pinMode(alleyLed, OUTPUT);
  pinMode(spinnerLed, OUTPUT);


  // Set switch pins as INPUT_PULLUP (using internal pull-up resistors)
  pinMode(laneASwitch, INPUT_PULLUP);
  pinMode(laneBSwitch, INPUT_PULLUP);
  pinMode(laneCSwitch, INPUT_PULLUP);
  pinMode(laneDSwitch, INPUT_PULLUP);
  pinMode(spinnerSwitch, INPUT_PULLUP);
  pinMode(bottomLaneSwitch, INPUT_PULLUP);
  pinMode(alleyRolloverSwitch, INPUT_PULLUP);
  pinMode(rolloverswitchA, INPUT_PULLUP);
  pinMode(rolloverswitchB, INPUT_PULLUP);
  pinMode(rolloverswitchC, INPUT_PULLUP);
  pinMode(rolloverswitchD, INPUT_PULLUP);
}

// Main loop
void loop() {
//                                                                ****   rollover switches    ****
  if (digitalRead(rolloverswitchA) == LOW) {
    score+=100;
    digitalWrite(rolloverALed, HIGH);
    rolloverALedON = true;
    rolloverATime = millis();
    playSoundTarget();
    sendScoreToUno();
    Serial.println("AAAA");
    Serial.println(score);
  }
   if (digitalRead(rolloverswitchB) == LOW) {
    score+=100;
    digitalWrite(rolloverBLed, HIGH);
    rolloverBLedON = true;
    rolloverBTime = millis();
    playSoundTarget();
    sendScoreToUno();
    Serial.println("BBBB");
    Serial.println(score);
  }
   if (digitalRead(rolloverswitchC) == LOW) {
    score+=100;
    digitalWrite(rolloverCLed, HIGH);
    rolloverCLedON = true;
    rolloverCTime = millis();
    playSoundTarget();
    sendScoreToUno();
    Serial.println("CCCC");
    Serial.println(score);
   }
   if (digitalRead(rolloverswitchD) == LOW) {
    score+=100;
    digitalWrite(rolloverDLed, HIGH);
    rolloverDLedON = true;
    rolloverDTime = millis();
    playSoundTarget();
    sendScoreToUno();
    Serial.println("DDDD");
    Serial.println(score);
  }

  //                                                                         ****    LANES   ****
  if (digitalRead(bottomLaneSwitch) == LOW) {
    score += 1000;
    playSoundTarget();
    sendScoreToUno();
    Serial.println("BOT!!!: ");
    Serial.println(score);
  }

  if (digitalRead(laneASwitch) == LOW) {
    handleLaneScore(laneALed, 300, laneALedON, laneALedTime);
    Serial.print("Lane A!");
  }
  if (digitalRead(laneBSwitch) == LOW) {
    handleLaneScore(laneBLed, 300, laneBLedON, laneBLedTime);
     Serial.print("Lane B!");
  }
  if (digitalRead(laneCSwitch) == LOW) {
    handleLaneScore(laneCLed, 300, laneCLedON, laneCLedTime);
     Serial.print("Lane C!");
  }
  if (digitalRead(laneDSwitch) == LOW) {
    handleLaneScore(laneDLed, 300, laneDLedON, laneDLedTime);
     Serial.print("Lane D!");
  }





                                                                                  //****    Test LED timing and elay    ****
  if (rolloverALedON && (millis() - rolloverATime >= 2000)) {
    digitalWrite(rolloverALed, LOW);
    rolloverALedON = false;
  }
   if (rolloverBLedON && (millis() - rolloverBTime >= 2000)) {
    digitalWrite(rolloverBLed, LOW);
    rolloverBLedON = false;
  }
   if (rolloverCLedON && (millis() - rolloverCTime >= 2000)) {
    digitalWrite(rolloverCLed, LOW);
    rolloverCLedON = false;
  }
   if (rolloverDLedON && (millis() - rolloverDTime >= 2000)) {
    digitalWrite(rolloverDLed, LOW);
    rolloverDLedON = false;
  }
//      ****    LANEs LED   ****
  if (laneALedON && (millis() - laneALedTime >= 2000)) {
    digitalWrite(laneALed, LOW);
    laneALedON = false;
  }
  if (laneBLedON && (millis() - laneBLedTime >= 2000)) {
    digitalWrite(laneBLed, LOW);
    laneBLedON = false;
  }
  if (laneCLedON && (millis() - laneCLedTime >= 2000)) {
    digitalWrite(laneCLed, LOW);
    laneCLedON = false;
  }
  if (laneDLedON && (millis() - laneDLedTime >= 2000)) {
    digitalWrite(laneDLed, LOW);
    laneDLedON = false;
  }

                                                                                  // Turn off bonus score LED after 2 seconds
  if (bonusLedOn && (millis() - bonusLedTime >= 2000)) {
    digitalWrite(currentBonusLed, LOW);
    bonusLedOn = false;
  }

                                                                                  // Turn off alley bonus LED after 2 seconds
  if (alleyBonusLedOn && (millis() - alleyBonusLedTime >= 2000)) {
   digitalWrite(currentAlleyBonusLed, LOW);
    alleyBonusLedOn = false;
  }

  if (alleyLEDON && (millis() - alleyLEDTime >= 2000)) {
    digitalWrite(alleyLed, LOW);
    alleyLEDON = false;
  }







                                                                                  // Handle Spinner Switch
  if (digitalRead(spinnerSwitch) == LOW) {
    if (spinnerLit) {
      score += 100; // Spinner lit, 100 points
    } else {
      score += 10;  // Spinner not lit, 10 points
    }

    playSoundTarget(); // Play sound for target hit
    sendScoreToUno(); // Send score to Arduino Uno
    Serial.print("Spinner!!!!!!");
    Serial.println(score);
  }

                                                                        //  ****  Handle Aladdin's Alley Rollover Switch  ****

  if (digitalRead(alleyRolloverSwitch) == LOW) {
    alleyScore += 20;
    digitalWrite(alleyLed, HIGH);
    if (alleyScore > maxAlleyScore) {
      alleyScore = maxAlleyScore; // Cap bonus score at max
    }
    score += alleyScore;
     turnOffAllAlleyBonusLeds();

// Activate the corresponding alley bonus LED
  if (alleyScore == 500) {
    digitalWrite(alleySpecialBonus500, HIGH);
      currentAlleyBonusLed = alleySpecialBonus500;
  } else if (alleyScore == 1000) {
    digitalWrite(alleySpecialBonus1000, HIGH);
      currentAlleyBonusLed = alleySpecialBonus1000;
  } else if (alleyScore == 2000) {
    digitalWrite(alleySpecialBonus2000, HIGH);
      currentAlleyBonusLed = alleySpecialBonus2000;
  } else if (alleyScore == 3000) {
    digitalWrite(alleySpecialBonus3000, HIGH);
      currentAlleyBonusLed = alleySpecialBonus3000;
  } else if (alleyScore == 4000) {
    digitalWrite(alleySpecialBonus4000, HIGH);
      currentAlleyBonusLed = alleySpecialBonus4000;
  } else if (alleyScore == 5000) {
    digitalWrite(alleySpecialBonus5000, HIGH);
      currentAlleyBonusLed = alleySpecialBonus5000;
  }

  playSoundBonus();  // Play bonus sound
  sendScoreToUno();  // Send score to Arduino Uno
  alleyBonusLedOn = true;
  alleyBonusLedTime = millis();
  alleyLEDON = true;
  alleyLEDTime = millis();
  }

}



                                                                          //        ****  Fucntions    ****




// Function to handle lane scores
void handleLaneScore(int laneLed, int points, bool &laneOn, unsigned long &laneTime) {
  score += points;
  bonusScore += 1000;
  if (bonusScore > maxBonusScore) {
    bonusScore = maxBonusScore;
  }
  turnOffAllBonusScoreLeds();

if (bonusScore == 1000) {
    digitalWrite(bonusLight1000, HIGH);
      currentBonusLed = bonusLight1000;
  } else if (bonusScore == 2000) {
    digitalWrite(bonusLight2000, HIGH);
      currentBonusLed = bonusLight2000;
  } else if (bonusScore == 3000) {
    digitalWrite(bonusLight3000, HIGH);
      currentBonusLed = bonusLight3000;
  } else if (bonusScore == 4000) {
    digitalWrite(bonusLight4000, HIGH);
      currentBonusLed = bonusLight4000;
  } else if (bonusScore == 5000) {
    digitalWrite(bonusLight5000, HIGH);
      currentBonusLed = bonusLight5000;
  } else if (bonusScore == 6000) {
    digitalWrite(bonusLight6000, HIGH);
      currentBonusLed = bonusLight6000;
  } else if (bonusScore == 7000) {
    digitalWrite(bonusLight7000, HIGH);
      currentBonusLed = bonusLight7000;
  } else if (bonusScore == 8000) {
    digitalWrite(bonusLight8000, HIGH);
      currentBonusLed = bonusLight8000;
  } else if (bonusScore == 9000) {
    digitalWrite(bonusLight9000, HIGH);
      currentBonusLed = bonusLight9000;
  } else if (bonusScore == 10000) {
    digitalWrite(bonusLight10000, HIGH);
      currentBonusLed = bonusLight10000;
  }

  digitalWrite(laneLed, HIGH);
  playSoundBonus();
  sendScoreToUno();
  laneOn = true;
  laneTime = millis();
  bonusLedOn = true;
  bonusLedTime = millis();
}

// Function to send the current score to the Arduino Uno
void sendScoreToUno() {
  Serial1.print("SCORE:");
  Serial1.println(score);  // Send score data to Uno

  Serial.print("Send Score to Uno: Score = ");
  Serial.println(score);
}

// Function to play sound for target hits
void playSoundTarget() {
  Serial1.println("SOUND:TARGET");  // Send sound command to Uno      ***     ***     ***     ***     Changed form print to println and took ou \n after TARGET
}

// Function to play sound for bonus increments
void playSoundBonus() {
  Serial1.println("SOUND:BONUS");  // Send sound command to Uno
}

void turnOffAllAlleyBonusLeds() {
  digitalWrite(alleySpecialBonus500, LOW);
  digitalWrite(alleySpecialBonus1000, LOW);
  digitalWrite(alleySpecialBonus2000, LOW);
  digitalWrite(alleySpecialBonus3000, LOW);
  digitalWrite(alleySpecialBonus4000, LOW);
  digitalWrite(alleySpecialBonus5000, LOW);
}
void turnOffAllBonusScoreLeds() {
  digitalWrite(bonusLight1000, LOW);
  digitalWrite(bonusLight2000, LOW);
  digitalWrite(bonusLight3000, LOW);
  digitalWrite(bonusLight4000, LOW);
  digitalWrite(bonusLight5000, LOW);
  digitalWrite(bonusLight6000, LOW);
  digitalWrite(bonusLight7000, LOW);
  digitalWrite(bonusLight8000, LOW);
  digitalWrite(bonusLight9000, LOW);
  digitalWrite(bonusLight10000, LOW);
}


