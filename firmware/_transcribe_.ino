
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
bool hasUsbDevice;

uint8_t twoParamStore[2][2];
uint8_t switchStore[2];

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
void setPrefix(uint8_t cmdNum);
void setThisPrefix(char prefix[4]);
void setCmdNum(uint8_t cmdNum);

// struct Note {
//   char cmd[8];
//   uint8_t note;
//   Note(){}
//   Note(char _cmd[8], uint8_t _note){
//     for (uint8_t i = 0; i < 8; i++)
//     {
//       cmd[i] = _cmd[i];
//     }
//     note = _note;
//   }
// };

// struct XX {
//   char cmd[8];
//   uint8_t xx; 
// };

// struct XXYY {
//   char cmd[8];
//   uint8_t xx; 
//   uint8_t yy; 
//   uint8_t xx_store;
//   uint8_t yy_store;
// };
// struct XXYYZZ {
//   char cmd[8];
//   uint8_t xx; 
//   uint8_t yy; 
//   uint8_t zz; 
//   uint8_t xx_store;
//   uint8_t yy_store;
//   uint8_t zz_store;
// };

// Note notes[10];
// Note xyz[1];




void mapMidiNote(){

  /*-- loop notes --*/

  // for( uint8_t i = 0; i < sizeof(notes); i ++) {
  //   if ( midiParam1 == notes[i].note ) {
  //     setCmd( notes[i].cmd );
  //   }
  // }

setCmdNum(AVE55::notes[midiParam1]);
  // if(midiParam1 == 82){setCmd(AVE55::MIX_MODE); }
  // else if(midiParam1 == 81){setCmd(AVE55::A_BUS_BACK_COLOR); }
  // else if(midiParam1 == 81){setCmd(AVE55::A_BUS_SOURCE_1); }
  // else if(midiParam1 == 83){setCmdSwitch(AVE55::A_BUS_SOURCE_1, AVE55::A_BUS_BACK_COLOR, 0);}
  // else if(midiParam1 == 84){setCmdToggle(AVE55::WIPE_SQUARE_CORNER_UL, 8, 1);}

// if (midiParam1 == 60){setCmd(AVE55::WIPE_SQUARE_CORNER_UL);}
// else if (midiParam1 == 61){setCmd(AVE55::WIPE_SQUARE_CORNER_DL);}
// else if (midiParam1 == 62){setCmd(AVE55::WIPE_SQUARE_CORNER_DR);}
// else if (midiParam1 == 63){setCmd(AVE55::WIPE_SQUARE_CORNER_UR);}

}

void mapMidiCC(){
  // if(midiParam1 == 0){setCmdParam(AVE55::A_B_MIX_LEVEL, midiParam2);}
  // else if(midiParam1 == 1){setCmdTwoParams(AVE55::CENTER_WIPE, midiParam2, 0, 0);}
  // else if(midiParam1 == 2){setCmdTwoParams(AVE55::CENTER_WIPE, midiParam2, 1, 0);}
  // else if(midiParam1 == 3){setCmdStep(AVE55::WIPE_SQUARE_CORNER_UL, midiParam2, 8);}
  // else if(midiParam1 == 71){setCmdToggle(AVE55::WIPE_SQUARE_CORNER_UL, 8, 1);}\

}

void setup()
{
  Serial1.begin(31250);
  Serial.begin(9600);
  altSerial.begin(9600);

  hasUsbDevice = false;
  vid = pid = 0;
  twoParamStore[2][2] = {};
  switchStore[2] = {};

  if (Usb.Init() == 0){ // means it is successful
    hasUsbDevice = true;
    delay( 200 );
    }


}

void loop()
{
  midiCommand = midiChannel =midiParam1 = midiParam2 = 0;
  memset(&cmd[0], 0, sizeof(cmd));
  bool hasMessage = false;

  if(hasUsbDevice){hasMessage = readInputFromMidiDevice();} // check from the usbhost-sheild first if connected
  if(!hasMessage){hasMessage = readInputFromMidiHost();} // if nothing check the usb on the arduino
  if(!hasMessage){hasMessage = readInputFromMidiSerial();} // if still nothing check the serial port  
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

  if(Serial1.available() < 3){ return false;}
  //Skip to beginning of next message (silently dropping stray data bytes)
  while(!(Serial1.peek() & 0x80)){ Serial1.read(); }
  if(Serial1.available() < 3){ return false;}
  uint8_t first = Serial1.read();

  midiCommand = first & 0xF0; // command
  midiChannel = first & 0xF; // channel
  midiParam1 = Serial1.read(); // param 1
  midiParam2 = Serial1.read(); // param 2

  // Serial1.flush();
  while(Serial1.available()){Serial1.read();}
  return true;
}

void setCmd(char inputCmd[8]){
    for(uint8_t i = 0; i < 8; i++){
      cmd[i] = inputCmd[i];
  }
}

void setThisPrefix(char prefix[4]){

  Serial.print(prefix);
  Serial.print("<-cmd prefix\n");

  for (uint8_t i = 0; i < 3; i++)
  {
    cmd[i] = prefix[i];
  }
}

void setPrefix(uint8_t note){
// char id[4] = {};

  Serial.print(note);
  Serial.print("<-note\n");

if (note >= 0 && note <= 8) setThisPrefix("VFD");
if (note >= 9 && note <= 12) setThisPrefix("AML");
if (note >= 13 && note <= 22) setThisPrefix("VCP");
if (note >= 23 && note <= 76) setThisPrefix("VDE");
if (note >= 77 && note <= 87) setThisPrefix("VBC");
if (note >= 90 && note <= 91) setThisPrefix("VMX");
if (note >= 92 && note <= 96) setThisPrefix("VBG");
if (note >= 98 && note <= 97) setThisPrefix("VWD");
if (note >= 104 && note <= 99) setThisPrefix("VWB");
if (note >= 105 && note <= 113) setThisPrefix("VEC");
if (note >= 114 && note <= 114) setThisPrefix("ZEN");
if (note >= 115 && note <= 115) setThisPrefix("VF");
if (note >= 123 && note <= 116) setThisPrefix("VWM");
if (note >= 128 && note <= 124) setThisPrefix("VW:");
if (note >= 129 && note <= 129) setThisPrefix("ZRS");
if (note >= 130 && note <= 130) setThisPrefix("VMA");
if (note >= 131 && note <= 131) setThisPrefix("ZUD");
if (note >= 132 && note <= 133) setThisPrefix("VTC");
if (note >= 134 && note <= 139) setThisPrefix("VTE");
if (note >= 176 && note <= 140) setThisPrefix("VWP");



}

void setCmdNum(uint8_t cmdNum){
  setPrefix(cmdNum);
  // Serial.print(cmd);
  // Serial.print("<-cmd prefix\n");
  cmd[3] = ':';
  char hexParam[12] = {};
  sprintf(hexParam, "%03d", cmdNum);

    cmd[4] = hexParam[0];
    cmd[5] = hexParam[1];
    cmd[6] = hexParam[2];

  Serial.print(cmd);
  Serial.print("<-cmd full\n");

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



