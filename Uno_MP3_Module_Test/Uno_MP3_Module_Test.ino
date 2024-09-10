 
/* DYSV5Wsoftserialv7
    Just plays track 5 with 2 sec gap after playing
    

    Arduino UNO unsing software Serial

    Player on Serial 1 (pins 18-19)
    busyPin = 8 //receives busy signal from DY-SV5W
    
*/
#include "SoftwareSerial.h"

SoftwareSerial mySerial(10, 11); // RX, TX
//variables always required to work DY-SV5W
const int busyPin = 8;//change to any suitable digital pin
byte commandLength;
byte command[6];
int checkSum = 0;

//my variables for demo sketch
int trackNum = 1;
int playStatus; //0 playing 1 stopped 2 waiting to start next track
unsigned long lastCheckTime;
unsigned long currentMillis;
int busyPinstate;

void playTrack(int soundTrack) {
  //select track
  //Serial.print("soundTrack: ");
  //Serial.println(soundTrack);
  command[0] = 0xAA;//first byte says it's a command
  command[1] = 0x07;
  command[2] = 0x02;
  command[3] = highByte(soundTrack);//snh...track HIGH bit
  command[4] = lowByte(soundTrack);//SNL... track low bit
  checkSum = 0;
  for (int q = 0; q < 5; q++) {
    checkSum +=  command[q];
  }
  command[5] = lowByte(checkSum);//SM check bit... low bit of the sum of all previous values
  commandLength = 6;
  sendCommand();
}

//plays whatever track has been paused or 1st track if nothing selected
//May need to be selected after putting into random mode
void play() {
  command[0] = 0xAA;//first byte says it's a command
  command[1] = 0x02;
  command[2] = 0x00;
  command[3] = 0xAC;
  commandLength = 4;
  sendCommand();
}
//selects random mode
void randomMode() {
  command[0] = 0xAA;//first byte says it's a command
  command[1] = 0x18;
  command[2] = 0x01;
  command[3] = 0x03;//random
  checkSum = 0;
  for (int q = 0; q < 4; q++) {
    checkSum +=  command[q];
  }
  command[4] = lowByte(checkSum);//SM check bit... low bit of the sum of all previous values
  commandLength = 5;
  sendCommand();

  //play() needs to be selected if you want the random tracks to start playing instantly
  play();
}

//sets the device volume...0 - 30
void playbackVolume(int vol) {
  if (vol > 30) { //check within limits
    vol = 30;
  }
  command[0] = 0xAA;//first byte says it's a command
  command[1] = 0x13;
  command[2] = 0x01;
  command[3] = vol;//volume
  checkSum = 0;
  for (int q = 0; q < 4; q++) {
    checkSum +=  command[q];
  }
  command[4] = lowByte(checkSum);//SM check bit... low bit of the sum of all previous values
  commandLength = 5;
  sendCommand();
}

//sends the command
void sendCommand() {
  int q;
  for (q = 0; q < commandLength; q++) {
    mySerial.write(command[q]);
    Serial.print(command[q], HEX);
  }
  Serial.println("End");
}

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600);
  Serial.println("DYSV5Wsoftserialv7");

  pinMode(busyPin, INPUT);//pin to read from DY-SV5W buyPin
  
  playbackVolume(20);//sets volume to lvl 17
}



void loop() {
  currentMillis = millis();//stores time in millis() for non blocking timings
  busyPinstate = digitalRead(busyPin);
  if (busyPinstate > 0) { //nothing playing
    if (playStatus < 1) {
      playStatus = 1;
      lastCheckTime = currentMillis;//set system ready for 2 sec delay
    }
  }
  switch (playStatus) {
    case 1:
      if (currentMillis - lastCheckTime >= 2000) { //2000 = 2 seconds of silence between tracks
        playStatus = 2;
        //Just selecting a new track
        //this could have been something like 
        //trackNum = random(1,5);
        //trackNum = 5;//fixed track number
        playTrack(trackNum);
        trackNum++;
        if(trackNum > 6){
          trackNum = 1;  
        }
      }
      break;
    case 2:
      if(busyPinstate < 1){
        playStatus = 0;  
      }
      break;
    default:
      break;
  }
}