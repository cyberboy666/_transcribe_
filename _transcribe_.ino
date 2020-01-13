


// #include <AltSoftSerial.h>
// #include "src/transcriber.h"

// int RXLED = 17;
// Transcriber transcriber;
// AltSoftSerial altSerial;

// void setup() {
  // altSerial.begin(9600);

  // transcriber.begin();


  // NoteOn input(MIDINOTE::C4);
  // OutputElement output("BUTTON", AVE55::MIX_MODE);
    // transcriber.map(input, output);

    // transcriber.map(InputElement(INTYPE::NOTE, MIDINOTE::C4), OutputElement(OUTTYPE::SWITCH, AVE55::MIX_MODE));
    // transcriber.map(InputElement(INTYPE::CCVALUE, 0), OutputElement(OUTTYPE::SLIDER, AVE55::A_B_MIX_LEVEL));
    // transcriber.map(InputElement(INTYPE::CCVALUE, 1, INTYPE::CCVALUE, 2), OutputElement(OUTTYPE::SLIDER_TWO, AVE55::CENTER_WIPE));

    // char* switchCommands[2] = {AVE55::A_BUS_SOURCE_1, AVE55::A_BUS_BACK_COLOR};
    // transcriber.map(InputElement(INTYPE::NOTE, MIDINOTE::C4SHARP), OutputElement(OUTTYPE::SWITCH, AVE55::A_BUS_SOURCE_1, AVE55::A_BUS_BACK_COLOR));
    // transcriber.map(InputElement(INTYPE::NOTE, MIDINOTE::C4SHARP), OutputElement(OUTTYPE::SWITCH, switchCommands));


  // transcriber.map(InputElement(NoteOn(61)), OutputElement(Button(AVE55::A_BUS_MOSAIC_STEP_1)));
  // transcriber.map(InputElement(NoteOn(62)), OutputElement(Button(AVE55::A_BUS_MOSAIC_STEP_2)));
  // transcriber.map(InputElement(NoteOn(63)), OutputElement(Button(AVE55::A_BUS_MOSAIC_STEP_3)));
  // transcriber.map(InputElement(NoteOn(64)), OutputElement(Button(AVE55::A_BUS_MOSAIC_STEP_4)));
//   pinMode(RXLED, OUTPUT);
// }


// void loop() {

//   transcriber.update();
// }


//   // altSerial.write(2);
//   // altSerial.write("VMX:000");
//   // altSerial.write(3);
//   // delay(1000);

//   // digitalWrite(RXLED, LOW);
//   // Serial1.write(2);
//   // Serial1.write(86);
//   // Serial1.write(77);
//   // Serial1.write(88);
//   // Serial1.write(58);
//   // Serial1.write(48);
//   // Serial1.write(48);
//   // Serial1.write(48);
//   // // Serial1.write("VCP:200"); // 86 67 80 58 50 48 48 // 86 77 88 58 48 48 48 
//   // Serial1.write(3);
//   // delay(1000);
//   // digitalWrite(RXLED, HIGH);
//   // Serial1.write(2);
//   // Serial1.write(86);
//   // Serial1.write(67);
//   // Serial1.write(80);
//   // Serial1.write(58);
//   // Serial1.write(50);
//   // Serial1.write(48);
//   // Serial1.write(51);
//   // // Serial1.write("VCP:203"); // 86 67 80 58 50 48 51 
//   // Serial1.write(3);
//   // delay(1000);

// }


// an experiment in uglier but maybe less bloated design ...

#include <usbh_midi.h>
#include <usbhub.h>
#include <SPI.h>
#include <usbmidi.h>
#include "src/midievents.h"
#include "src/commands.h"
#include <AltSoftSerial.h>

AltSoftSerial altSerial;
USB Usb;
USBH_MIDI  Midi(&Usb);
uint16_t pid, vid;
char cmd[12] = {};
uint8_t midiCommand, midiChannel, midiParam1, midiParam2;

uint8_t twoParamStore[2][2];
uint8_t switchStore[2];

int incomingByte = 0; // for testing only


bool readInputFromMidiDevice();
bool readInputFromMidiHost();
bool readInputFromMidiSerial();

void setCmd(char inputCmd[8]);
void setCmdSwitch(char inputCmd1[8], char inputCmd2[8], uint8_t switchIndex);
void setCmdToggle(char inputCmd[8], uint8_t offset, uint8_t switchIndex);
void setCmdToggle(char inputCmd[8], uint8_t offset, uint8_t switchIndex);
void setCmdStep(char inputCmd[8], uint8_t param, uint8_t offset);
void setCmdParam(char inputCmd[8], uint8_t param);
void setCmdTwoParams(char inputCmd[8], uint8_t param, uint8_t position, uint8_t storeIndex);



void mapMidiNote(){
  if(midiParam1 == 82){setCmd(AVE55::MIX_MODE); }
  // else if(midiParam1 == 81){setCmd(AVE55::A_BUS_BACK_COLOR); }
  // else if(midiParam1 == 81){setCmd(AVE55::A_BUS_SOURCE_1); }
  else if(midiParam1 == 83){setCmdSwitch(AVE55::A_BUS_SOURCE_1, AVE55::A_BUS_BACK_COLOR, 0);}
  // else if(midiParam1 == 84){setCmdToggle(AVE55::WIPE_SQUARE_CORNER_UL, 8, 1);}
}

void mapMidiCC(){
  if(midiParam1 == 0){setCmdParam(AVE55::A_B_MIX_LEVEL, midiParam2);}
  else if(midiParam1 == 1){setCmdTwoParams(AVE55::CENTER_WIPE, midiParam2, 0, 0);}
  else if(midiParam1 == 2){setCmdTwoParams(AVE55::CENTER_WIPE, midiParam2, 1, 0);}
  else if(midiParam1 == 3){setCmdStep(AVE55::WIPE_SQUARE_CORNER_UL, midiParam2, 8);}
  else if(midiParam1 == 71){setCmdToggle(AVE55::WIPE_SQUARE_CORNER_UL, 8, 1);}\

}

void setup()
{
  Serial1.begin(31250);
  Serial.begin(9600);
  altSerial.begin(9600);

  vid = pid = 0;
  twoParamStore[2][2] = {};
  switchStore[2] = {};

  // if (Usb.Init() == -1) {
  //   while (1); //halt
  // }//if (Usb.Init() == -1...
  // delay( 200 );
}



void loop()
{
  midiCommand = midiChannel =midiParam1 = midiParam2 = 0;
  memset(&cmd[0], 0, sizeof(cmd));
  bool hasMessage = false;

  // hasMessage = readInputFromMidiDevice(); // check from the usbhost-sheild first
  hasMessage = readInputFromMidiHost();
//   if(!hasMessage){hasMessage = readInputFromMidiHost();} // if nothing check the usb on the arduino
  if(!hasMessage){hasMessage = readInputFromMidiSerial();} // if still nothing check the serial port  
// hasMessage = readInputFromMidiSerial();
  if(!hasMessage){return;}


  if(midiCommand == 0){return;}
  if(midiChannel != 0){return;}

  Serial.print(midiParam1);
  Serial.print("<-note\n");
  Serial.print(midiChannel);
  Serial.print("<-channel\n");
  Serial.print(midiCommand);
  Serial.print("<-command\n"); 
  // midiParam2 = midiParam2 - 64; // weird off by 64 bug ??
  Serial.print(midiParam2);
  Serial.print("<-value\n\n");

  if(midiCommand == MIDICOMMAND::NOTEON){mapMidiNote();}
  else if(midiCommand == MIDICOMMAND::CC){mapMidiCC();}

  Serial.print(cmd);
  Serial.print("<-cmd\n");
  if(cmd[0] == 0){return;}

  altSerial.write(2);
  altSerial.write(cmd);
  altSerial.write(3);
}

bool readInputFromMidiDevice(){
    Usb.Task();
    char buf[20];
    uint8_t bufMidi[3];
    uint16_t  rcvd;

  if (Midi.RecvData( &rcvd,  bufMidi) == 0 ) {
    uint8_t first =  bufMidi[1];
    midiCommand = first & 0xF0;
    midiChannel = first & 0xF;
    midiParam1 = bufMidi[2];
    midiParam2 = bufMidi[3];
    return true;
    }
  return false;
}

bool readInputFromMidiHost(){

  USBMIDI.poll();
  if(USBMIDI.available()){
    //Skip to beginning of next message (silently dropping stray data bytes)
    while(!(USBMIDI.peek() & 0x80)) USBMIDI.read();

    uint8_t first = USBMIDI.read();

    midiCommand = first & 0xF0; // command
    midiChannel = first & 0xF; // channel
    midiParam1 = USBMIDI.read(); // param 1 (note)
    midiParam2 = USBMIDI.read(); // param 2 (value)

    USBMIDI.flush();
    return true;
  }
  return false;
}

bool readInputFromMidiSerial(){

  if(Serial1.available() > 2){

    //Skip to beginning of next message (silently dropping stray data bytes)
    while(!(Serial1.peek() & 0x80)) Serial1.read();

    uint8_t first = Serial1.read();

    midiCommand = first & 0xF0; // command
    midiChannel = first & 0xF; // channel
    midiParam1 = Serial1.read(); // param 1
    midiParam2 = Serial1.read(); // param 2

    // Serial1.flush();
    while(Serial1.available()){Serial1.read();}
    return true;
  }

  return false;
}

void setCmd(char inputCmd[8]){
    for(uint8_t i = 0; i < 8; i++){
      cmd[i] = inputCmd[i];
  }
}

void setCmdSwitch(char inputCmd1[8], char inputCmd2[8], uint8_t switchIndex){
  if(switchStore[switchIndex] == 0){
      for(uint8_t i = 0; i < 7; i++){
        cmd[i] = inputCmd1[i];
      }
  }
  else{
      for(uint8_t i = 0; i < 7; i++){
        cmd[i] = inputCmd2[i];
      }
  }
  switchStore[switchIndex] = (switchStore[switchIndex] + 1) % 2;
}

void setCmdToggle(char inputCmd[8], uint8_t offset, uint8_t switchIndex){
  uint8_t cmdNumInt = 0;
  char cmdNum[4] = {inputCmd[4], inputCmd[5], inputCmd[6]};
  cmdNumInt = atoi(cmdNum);
  cmdNumInt = (cmdNumInt + switchStore[switchIndex]) % offset;
  Serial.print(cmdNumInt);
  Serial.print("<-cmdNumInt\n");

    for(uint8_t i = 0; i < 4; i++){
      cmd[i] = inputCmd[i];
    }
  char hexParam[12] = {};
  sprintf(hexParam, "%03d", cmdNumInt);

    cmd[4] = hexParam[0];
    cmd[5] = hexParam[1];
    cmd[6] = hexParam[2];

  switchStore[switchIndex] = (switchStore[switchIndex] + 1) % offset;
}


void setCmdStep(char inputCmd[8], uint8_t param, uint8_t offset){
  // uint16_t max is 65535
  int value = ( (param * offset) / 128 );
  uint8_t cmdNumInt = 0;
  char cmdNum[4] = {inputCmd[4], inputCmd[5], inputCmd[6]};
  cmdNumInt = atoi(cmdNum);
  cmdNumInt = (cmdNumInt + value);
  Serial.print(value);
  Serial.print("<-Intvalue\n");

    for(uint8_t i = 0; i < 4; i++){
      cmd[i] = inputCmd[i];
    }
  char hexParam[12] = {};
  sprintf(hexParam, "%03d%", cmdNumInt);

    cmd[4] = hexParam[0];
    cmd[5] = hexParam[1];
    cmd[6] = hexParam[2];

}

void setCmdParam(char inputCmd[8], uint8_t param){
  char hexParam[2] = {};
  sprintf(hexParam, "%02X", param*2);

    for(uint8_t i = 0; i < 7; i++){
      cmd[i] = inputCmd[i];
    }
  cmd[7] = hexParam[0];
  cmd[8] = hexParam[1];
}

void setCmdTwoParams(char inputCmd[8], uint8_t param, uint8_t position, uint8_t storeIndex){
  twoParamStore[storeIndex][position] = param;

  char hexParam[8] = {};
  sprintf(hexParam, "%02X%02X", twoParamStore[storeIndex][0]*2, twoParamStore[storeIndex][1]*2);
    for(uint8_t i = 0; i < 7; i++){
      cmd[i] = inputCmd[i];
    }

  cmd[7] = hexParam[0];
  cmd[8] = hexParam[1];
  cmd[9] = hexParam[2];
  cmd[10] = hexParam[3];
}