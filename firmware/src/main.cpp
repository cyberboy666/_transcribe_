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
uint8_t cmdNum;
uint8_t notes[128];
uint8_t cc[128];
uint8_t midiCommand, midiChannel, midiParam1, midiParam2;
uint8_t position;
bool hasUsbDevice;
bool dropZeroCC;

uint8_t switchStore[10];

uint8_t twoInputStore[6][2]; // 0=BACK_COLOR_MANUAL:174, 1=EDGE_COLOR_MANUAL:175, 2=COLOR_CORECT:217, 3=CENTER_WIPE:218, 4=SCENE_GRABER:219

uint8_t threeInputStore[1][2]; // 0=CHROMA_SET:214

uint8_t get_two_param_position(uint8_t inputCmd);
uint8_t get_three_param_position(uint8_t inputCmd);
uint8_t get_two_store_index(uint8_t inputCmd);

bool useFlatMidiMap;

bool readInputFromMidiDevice();
bool readInputFromMidiHost();
bool readInputFromMidiSerial();


void setCmd(uint16_t inputCmd, uint8_t inputParam = 0);
void setCmdSwitch(uint8_t inputCmd1, uint8_t inputCmd2, uint8_t switchIndex);
void setCmdToggle(uint8_t inputCmd, uint8_t offset, uint8_t switchIndex);
void setCmdToggle(uint8_t inputCmd, uint8_t offset, uint8_t switchIndex);
void setCmdStep(uint8_t inputCmd, uint8_t param, uint8_t offset);
void setCmdNoParam(uint8_t inputCmd);
void setCmdParam(uint8_t inputCmd, uint8_t param);
void setCmdParamRandom(uint8_t inputCmd);
void setCmdTwoParams(uint8_t inputCmd, uint8_t param, uint8_t position, uint8_t storeIndex);
void setCmdThreeParams(uint8_t inputCmd, uint8_t param, uint8_t position, uint8_t storeIndex);
void setPrefix(uint8_t inputCmd);
void setThisPrefix(char prefix[4]);
void removeTrailingUnderscore();


void setCustomMap(){
  // check the custom map
  if(midiCommand == MIDICOMMAND::NOTEON){
    // special note stuff here
  }
  else if(midiCommand == MIDICOMMAND::CC){
    if(midiParam1 == 0){setCmd(AVE55::A_B_MIX_LEVEL, midiParam2);}

    else if(midiParam1 == 1){setCmd(AVE55::CENTER_WIPE_X, midiParam2);}
    else if(midiParam1 == 2){setCmd(AVE55::CENTER_WIPE_Y, midiParam2);}
    else if(midiParam1 == 3){setCmd(AVE55::SCENE_GRABER_X, midiParam2);}
    else if(midiParam1 == 4){setCmd(AVE55::SCENE_GRABER_Y, midiParam2);}

    else if(midiParam1 == 7){setCmd(AVE55::A_B_MIX_LEVEL, midiParam2);}

    else if(midiParam1 == 16){setCmdStep(AVE55::A_BUS_STROBO_OFF, midiParam2, 6);}
    else if(midiParam1 == 17){setCmdStep(AVE55::A_BUS_MOSAIC_OFF, midiParam2, 6);}
    else if(midiParam1 == 18){setCmdStep(AVE55::A_BUS_PAINT_OFF, midiParam2, 6);}

    else if(midiParam1 == 20){setCmdStep(AVE55::B_BUS_STROBO_OFF, midiParam2, 6);}
    else if(midiParam1 == 21){setCmdStep(AVE55::B_BUS_MOSAIC_OFF, midiParam2, 6);}
    else if(midiParam1 == 22){setCmdStep(AVE55::B_BUS_PAINT_OFF, midiParam2, 6);}

    else if(midiParam1 == 32){setCmdToggle(AVE55::WIPE_SQUARE_CORNER_UL, 8, 0);}
    else if(midiParam1 == 33){setCmdSwitch(AVE55::A_BUS_SOURCE_1, AVE55::A_BUS_BACK_COLOR, 1);}
    else if(midiParam1 == 34){setCmdToggle(AVE55::WIPE_SQUARE_CORNER_UL, 8, 2);}
    else if(midiParam1 == 35){setCmdParamRandom(AVE55::A_B_MIX_LEVEL);}
  }
}

void setDefaultMap(){
  // check the default flatmap for midi channel 2 or 3
  if(useFlatMidiMap && midiChannel == 1){
    if(midiCommand == MIDICOMMAND::NOTEON){     
      cmdNum = AVE55::flat_notes_ch_two[midiParam1];
    }
    else if(midiCommand == MIDICOMMAND::CC){
      cmdNum = AVE55::flat_cc_ch_two[midiParam1];
    }
  }
  else if(useFlatMidiMap && midiChannel == 2){
    if(midiCommand == MIDICOMMAND::NOTEON){     
      cmdNum = AVE55::flat_notes_ch_three[midiParam1];
    }
  }
  if(cmdNum != 255){
    setCmd(cmdNum);
  }
}

void setup()
{
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

void loop()
{
  midiCommand = midiChannel = midiParam1 = midiParam2 = 0;
  position = 0;
  cmdNum = 255;
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

  setCustomMap();
  // setDefaultMap();

  removeTrailingUnderscore();

  // write the panasonic command to serial port
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

void setThisPrefix(char prefix[4]){
  for (uint8_t i = 0; i < 3; i++)
  {
    cmd[i] = prefix[i];
  }
}

void setPrefix(uint8_t inputCmd){



  if(inputCmd >= 0 && inputCmd <= 0) {setThisPrefix("VMX"); }
  else if(inputCmd >= 1 && inputCmd <= 37) {setThisPrefix("VWP"); }
  else if(inputCmd >= 40 && inputCmd <= 41) {setThisPrefix("VWD"); }
  else if(inputCmd >= 42 && inputCmd <= 44) {setThisPrefix("VWB"); }
  else if(inputCmd >= 40 && inputCmd <= 41) {setThisPrefix("VWD"); }
  else if(inputCmd >= 45 && inputCmd <= 52) {setThisPrefix("VWM"); }
  else if(inputCmd >= 53 && inputCmd <= 57) {setThisPrefix("_VW"); }
  else if(inputCmd >= 61 && inputCmd <= 63) {setThisPrefix("VWB"); }
  else if(inputCmd >= 70 && inputCmd <= 117) {setThisPrefix("VDE"); }
  else if(inputCmd >= 120 && inputCmd <= 121) {setThisPrefix("AML"); }
  else if(inputCmd >= 122 && inputCmd <= 125) {setThisPrefix("ALV"); }
  else if(inputCmd >= 126 && inputCmd <= 127) {setThisPrefix("AML"); }
  else if(inputCmd >= 130 && inputCmd <= 138) {setThisPrefix("VFD"); }
  else if(inputCmd >= 140 && inputCmd <= 148) {setThisPrefix("VBC"); }
  else if(inputCmd >= 150 && inputCmd <= 158) {setThisPrefix("VEC"); }
  else if(inputCmd >= 160 && inputCmd <= 164) {setThisPrefix("VBG"); }
  else if(inputCmd >= 174 && inputCmd <= 174) {setThisPrefix("_VB"); }
  else if(inputCmd >= 175 && inputCmd <= 175) {setThisPrefix("_VE"); }
  else if(inputCmd == 179 && inputCmd <= 179) {setThisPrefix("VMM"); }
  else if(inputCmd >= 180 && inputCmd <= 187) {setThisPrefix("_VDE"); }
  else if(inputCmd >= 190 && inputCmd <= 190) {setThisPrefix("_VAS"); }
  else if(inputCmd >= 191 && inputCmd <= 191) {setThisPrefix("_VF"); }
  else if(inputCmd >= 192 && inputCmd <= 192) {setThisPrefix("VMA"); }
  else if(inputCmd >= 197 && inputCmd <= 198) {setThisPrefix("VBC"); }
  else if(inputCmd >= 199 && inputCmd <= 199) {setThisPrefix("ZRS"); }
  else if(inputCmd >= 200 && inputCmd <= 209) {setThisPrefix("VCP"); }
  else if(inputCmd >= 210 && inputCmd <= 213) {setThisPrefix("VMX"); }
  else if(inputCmd >= 210 && inputCmd <= 213) {setThisPrefix("VCS"); }
  else if(inputCmd >= 215 && inputCmd <= 215) {setThisPrefix("ZUD"); }
  else if(inputCmd >= 216 && inputCmd <= 216) {setThisPrefix("ZEN"); }
  else if(inputCmd >= 217 && inputCmd <= 219) {setThisPrefix("VPS"); }
  else{
    Serial.print(inputCmd);
     Serial.print("<-found nothuing\n"); }

}

void setCmd(uint16_t inputCmd, uint8_t inputParam){
  // adjust for position on 2 or 3 input commands
  Serial.print("<-start set cmd\n");
  position = 0;
  if(inputCmd > 512){
    position = 2;
    inputCmd = inputCmd - 512;
  }
  else if(inputCmd > 256){
    position = 1;
    inputCmd = inputCmd - 256;
  }
  Serial.print(inputCmd);
  Serial.print("<-inputCmd after set position\n");
  Serial.print(position);
  Serial.print("<-position after set position\n");

  if(AVE55::is_one_input(inputCmd)){
    setCmdParam(inputCmd, inputParam);
  }
  else if(AVE55::is_two_input(inputCmd)){
    uint8_t storeIndex = get_two_store_index(inputCmd);
    setCmdTwoParams(inputCmd, inputParam, position, storeIndex);
  }
  if(AVE55::is_three_input(inputCmd)){
    setCmdThreeParams(inputCmd, inputParam, position, 0);
  }
  else{
  // no inputs
    setCmdNoParam(inputCmd);
  }
}

void setCmdSwitch(uint8_t inputCmd1, uint8_t inputCmd2, uint8_t switchIndex){
  if(switchStore[switchIndex] == 0){setCmd(inputCmd1); }
  else{ setCmd(inputCmd2); }
  switchStore[switchIndex] = (switchStore[switchIndex] + 1) % 2;
}

void setCmdToggle(uint8_t inputCmd, uint8_t offset, uint8_t switchIndex){
  inputCmd = (inputCmd + switchStore[switchIndex]) % offset;
  setCmd(inputCmd);
  switchStore[switchIndex] = (switchStore[switchIndex] + 1) % offset;
}


void setCmdStep(uint8_t inputCmd, uint8_t param, uint8_t offset){
  // uint8_t max is 65535
  int value = ( (param * offset) / 128 );

  inputCmd = (inputCmd + value);
  setCmd(inputCmd);
}

void setCmdParamRandom(uint8_t inputCmd){
  uint8_t randNumber = random(1,128);
  setCmd(inputCmd, randNumber);
}

void setCmdNoParam(uint8_t inputCmd){
  setPrefix(inputCmd);

  cmd[3] = ':';
  char hexParam[12] = {};
  sprintf(hexParam, "%03d", inputCmd);

  cmd[4] = hexParam[0];
  cmd[5] = hexParam[1];
  cmd[6] = hexParam[2];
}

void setCmdParam(uint8_t inputCmd, uint8_t param){
  setPrefix(inputCmd);

  char hexParam[12] = {};
  sprintf(hexParam, "%03d%02X", inputCmd, param*2);

  cmd[3] = ':';
  cmd[4] = hexParam[0];
  cmd[5] = hexParam[1];
  cmd[6] = hexParam[2];
  cmd[7] = hexParam[3];
  cmd[8] = hexParam[4];
}

void setCmdTwoParams(uint8_t inputCmd, uint8_t param, uint8_t position, uint8_t storeIndex){
  setPrefix(inputCmd);

  twoInputStore[storeIndex][position] = param;

  char hexParam[12] = {};
  sprintf(hexParam, "%03d%02X%02X", inputCmd, twoInputStore[storeIndex][0]*2, twoInputStore[storeIndex][1]*2);
  cmd[3] = ':';
  cmd[4] = hexParam[0];
  cmd[5] = hexParam[1];
  cmd[6] = hexParam[2];
  cmd[7] = hexParam[3];
  cmd[8] = hexParam[4];
  cmd[9] = hexParam[5];
  cmd[10] = hexParam[6];
}

void setCmdThreeParams(uint8_t inputCmd, uint8_t param, uint8_t position, uint8_t storeIndex){
  setPrefix(inputCmd);
  threeInputStore[storeIndex][position] = param;

  char hexParam[14] = {};
  sprintf(hexParam, "%03d%02X%02X%02X", inputCmd, threeInputStore[storeIndex][0]*2, threeInputStore[storeIndex][1]*2, threeInputStore[storeIndex][2]*2);
  cmd[3] = ':';
  cmd[4] = hexParam[0];
  cmd[5] = hexParam[1];
  cmd[6] = hexParam[2];
  cmd[7] = hexParam[3];
  cmd[8] = hexParam[4];
  cmd[9] = hexParam[5];
  cmd[10] = hexParam[6];
  cmd[11] = hexParam[5];
  cmd[12] = hexParam[6];
}

void removeTrailingUnderscore(){
  if (cmd[0] == '_'){
    for (uint8_t i = 0; i < 11; i++)
    {
      if (cmd[i+1] != 0x00){
        cmd[i] = cmd[i+1];
      }
      else{
        cmd[i] = 0x00;
      }
    }
  }
}

uint8_t get_two_param_position(uint8_t inputCmd){
  uint8_t position = 1;
  if(AVE55::flat_cc_ch_two[midiParam1+1] == cmdNum){position = 0;}
  return position;
}

uint8_t get_three_param_position(uint8_t inputCmd){
  uint8_t position = 2;
  if(AVE55::flat_cc_ch_two[midiParam1+1] == cmdNum && AVE55::flat_cc_ch_two[midiParam1+2] == cmdNum){position = 0;}
  else if(AVE55::flat_cc_ch_two[midiParam1+1] == cmdNum){position = 1;}
  return position;
}

uint8_t get_two_store_index(uint8_t inputCmd){
  uint8_t storeIndex = 0;
  if(inputCmd == 175) storeIndex=1;
  else if(inputCmd == 217) storeIndex=2;
  else if(inputCmd == 218) storeIndex=3;
  else if(inputCmd == 219) storeIndex=4;
  return storeIndex;
}