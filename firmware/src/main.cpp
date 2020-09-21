#include <usbh_midi.h>
#include <usbhub.h>
#include <SPI.h>
#include <usbmidi.h>
#include "midievents.h"
#include "commands.h"
#include <AltSoftSerial.h>

AltSoftSerial altSerial;
USB Usb;
USBH_MIDI  Midi(&Usb);
uint16_t pid, vid;
char cmd[14] = {};
uint8_t notes[128];
uint8_t cc[128];
uint8_t midiCommand, midiChannel, midiParam1, midiParam2;
uint8_t position;
bool hasUsbDevice;
bool dropZeroCC;

uint8_t switchStore[20];
uint8_t paramStore[127];

bool useFlatMidiMap;

bool readInputFromMidiDevice();
bool readInputFromMidiHost();
bool readInputFromMidiSerial();


void setCmd(char* inputCmd, uint8_t inputParam = 0);
void setCmdSwitch(char* inputCmd1, char* inputCmd2, uint8_t switchIndex);
void setCmdToggle(char* inputCmd, uint8_t start, uint8_t offset, uint8_t switchIndex);
void setCmdStep(char* inputCmd, uint8_t param, uint8_t start, uint8_t offset);

void setCmdParamRandom(char* inputCmd);



void setCustomMap(){
  // check the custom map
  if(midiCommand == MIDICOMMAND::NOTEON){
    // special note stuff here
  }
  else if(midiCommand == MIDICOMMAND::CC){
    if(midiParam1 == 0){setCmd(A55_A_B_MIX_LEVEL, midiParam2);}

    else if(midiParam1 == 1){setCmd(A55_CENTER_WIPE_X, midiParam2);}
    else if(midiParam1 == 2){setCmd(A55_CENTER_WIPE_Y, midiParam2);}
    else if(midiParam1 == 3){setCmd(A55_A_BUS_SOURCE_2, midiParam2);}
    else if(midiParam1 == 2){setCmd(A55_CENTER_WIPE_Y, midiParam2);}
    else if(midiParam1 == 3){setCmd(A55_SCENE_GRABER_X, midiParam2);}
    else if(midiParam1 == 4){setCmd(A55_SCENE_GRABER_Y, midiParam2);}
    else if(midiParam1 == 5){setCmd(A55_COLOR_CORECT_X, midiParam2);}
    else if(midiParam1 == 6){setCmd(A55_COLOR_CORECT_Y, midiParam2);}

    else if(midiParam1 == 7){setCmd(A55_THRESHOLD_LUM_KEY, midiParam2);}

    else if(midiParam1 == 16){setCmdStep(A55_A_BUS_STROBO_OFF, midiParam2, 70, 6);}
    else if(midiParam1 == 17){setCmdStep(A55_A_BUS_MOSAIC_OFF, midiParam2, 76, 6);}
    else if(midiParam1 == 18){setCmdStep(A55_A_BUS_PAINT_OFF, midiParam2, 82, 6);}

    else if(midiParam1 == 20){setCmdStep(A55_B_BUS_STROBO_OFF, midiParam2, 94, 6);}
    else if(midiParam1 == 21){setCmdStep(A55_B_BUS_MOSAIC_OFF, midiParam2, 100, 6);}
    else if(midiParam1 == 22){setCmdStep(A55_B_BUS_PAINT_OFF, midiParam2, 106, 6);}

    else if(midiParam1 == 32){setCmdToggle(A55_WIPE_SQUARE_CORNER_UL, 1, 16, 0);}
    else if(midiParam1 == 33){setCmdToggle(A55_WIPE_SQUARE, 17, 7, 9);}
    else if(midiParam1 == 34){setCmdToggle(A55_DIRECTION_ONE_WAY, 40, 2, 2);}
    else if(midiParam1 == 35){setCmdParamRandom(A55_A_B_MIX_LEVEL);}

    else if(midiParam1 == 48){setCmd(A55_WIPE_MIX_BUTTON);}
    else if(midiParam1 == 49){setCmd(A55_LUM_KEY);}

    else if(midiParam1 == 50){setCmdToggle(A55_A_BUS_EFFECT_ON, 180, 2, 5);}
    else if(midiParam1 == 51){setCmdToggle(A55_B_BUS_EFFECT_ON, 182, 2, 6);}
    else if(midiParam1 == 52){setCmdToggle(A55_B_BUS_COLOR_CORRECTOR_OFF, 115, 2, 7);}
    else if(midiParam1 == 53){setCmdToggle(A55_A_BUS_COLOR_CORRECTOR_OFF, 91, 2, 8);}
    else if(midiParam1 == 54){setCmdToggle(A55_A_BUS_NEGATIVE_OFF, 87, 2, 3);}
    else if(midiParam1 == 55){setCmdToggle(A55_B_BUS_NEGATIVE_OFF, 111, 2, 4);}

    else if(midiParam1 == 64){setCmd(A55_A_BUS_SOURCE_1);}
    else if(midiParam1 == 65){setCmd(A55_A_BUS_SOURCE_2);}
    else if(midiParam1 == 66){setCmd(A55_A_BUS_SOURCE_3);}
    else if(midiParam1 == 67){setCmd(A55_A_BUS_SOURCE_4);}
    else if(midiParam1 == 68){setCmd(A55_B_BUS_SOURCE_1);}
    else if(midiParam1 == 69){setCmd(A55_B_BUS_SOURCE_2);}
    else if(midiParam1 == 70){setCmd(A55_B_BUS_SOURCE_3);}
    else if(midiParam1 == 71){setCmd(A55_B_BUS_SOURCE_4);}
  }
}

void setup(){
  Serial1.begin(31250);
  Serial.begin(9600);
  altSerial.begin(9600);

  hasUsbDevice = false;
  vid = pid = 0;
  switchStore[2] = {};
  useFlatMidiMap = true;
  dropZeroCC = true; // to ignore 'note_off' cc messages

  if (Usb.Init() == 0){ // means it is successful
    hasUsbDevice = true;
    delay( 200 );
    }
}

void loop(){
  midiCommand = midiChannel = midiParam1 = midiParam2 = 0;
  position = 0;
  memset(&cmd[0], 0, sizeof(cmd));
  bool hasMessage = false;

  if(hasUsbDevice){hasMessage = readInputFromMidiDevice();} // check from the usbhost-sheild first if connected
  if(!hasMessage){hasMessage = readInputFromMidiHost();} // if nothing check the usb on the arduino
  if(!hasMessage){hasMessage = readInputFromMidiSerial();} // if still nothing check the serial port  
  if(!hasMessage){return;}

  if(midiCommand == 0){return;}
 // ignore cc note_off messages (at cost of no zero on slider)
  if(midiCommand == MIDICOMMAND::CC && midiParam2 == 0 && dropZeroCC){return;} 

  Serial.print(midiParam1);
  Serial.print("<-note (midiParam1)\n");
  Serial.print(midiChannel);
  Serial.print("<-channel  (midiChannel)\n");
  Serial.print(midiCommand);
  Serial.print("<-command (midiCommand)\n"); 
  // midiParam2 = midiParam2 - 64; // weird off by 64 bug ??
  Serial.print(midiParam2);
  Serial.print("<-value (midiParam2)\n\n");

  if(midiChannel == 0){setCustomMap();}
  // else{setDefaultMap();}

  // write the command to serial port
  Serial.print("\n");
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

    Serial1.write(first);
    Serial1.write(midiParam1);
    Serial1.write(midiParam2);

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

  midiCommand = first & 0xF0; // command 0b11110000 = 0xF0
  midiChannel = first & 0xF; // channel 0b00001111 = 0xF
  midiParam1 = Serial1.read(); // param 1
  midiParam2 = Serial1.read(); // param 2

  // Serial1.flush();
  while(Serial1.available()){Serial1.read();}

  return true;
}

void setCmd(char* inputCmd, uint8_t inputParam){

  Serial.print(inputCmd);
  Serial.print("<-- input command\n");
  strcpy(cmd, inputCmd);

  // replace special chars in serial message
  for (uint8_t i = 0; i < 11; i++){
    if(cmd[i] == 0x00 || cmd[i+1] == 0x00){ return; }

    if(cmd[i] == '~' && cmd[i+1] == '0'){
      // replace with midi param -> dont save in store
      char hexParam[4] = {};
      sprintf(hexParam, "%02X", inputParam*2);
      cmd[i] = hexParam[0];
      cmd[i+1] = hexParam[1];
    }
    if(cmd[i] == '~' && cmd[i+1] != '0'){
      // replace with midi param and save to store
      paramStore[int(cmd[i+1])] = inputParam*2;

      char hexParam[4] = {};
      sprintf(hexParam, "%02X", inputParam*2);
      cmd[i] = hexParam[0];
      cmd[i+1] = hexParam[1];
    }
    if(cmd[i] == '*'){
      // replace with store param

      char hexParam[4] = {};
      sprintf(hexParam, "%02X", paramStore[int(cmd[i+1])]);
      cmd[i] = hexParam[0];
      cmd[i+1] = hexParam[1];
    }

  }

}

void setCmdSwitch(char* inputCmd1, char* inputCmd2, uint8_t switchIndex){
  if(switchStore[switchIndex] == 0){setCmd(inputCmd1); }
  else{ setCmd(inputCmd2); }
  switchStore[switchIndex] = (switchStore[switchIndex] + 1) % 2;
}

void setCmdToggle(char* inputCmd, uint8_t start, uint8_t offset, uint8_t switchIndex){
  int value = start + switchStore[switchIndex];
  char charValue[6] = {};
  sprintf(charValue, "%03d", value);
  // this is hardcoded to replace a 3digit number at the 4th in command
  // need to refactor this if using differnt cmds to this
  inputCmd[4] = charValue[0];
  inputCmd[5] = charValue[1];
  inputCmd[6] = charValue[2];

  setCmd(inputCmd);
  switchStore[switchIndex] = (switchStore[switchIndex] + 1) % offset;
}

void setCmdStep(char* inputCmd, uint8_t param, uint8_t start, uint8_t offset){
  int value = start + ( (param * offset) / 128 );
  char charValue[6] = {};
  sprintf(charValue, "%03d", value);
  // this is hardcoded to replace a 3digit number at the 4th in command
  // need to refactor this if using differnt cmds to this
  inputCmd[4] = charValue[0];
  inputCmd[5] = charValue[1];
  inputCmd[6] = charValue[2];


  setCmd(inputCmd);
}

void setCmdParamRandom(char* inputCmd){
  uint8_t randNumber = random(1,128);
  setCmd(inputCmd, randNumber);
}
