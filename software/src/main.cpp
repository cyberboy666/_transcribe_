#include <usbh_midi.h>
#include <usbhub.h>
#include <SPI.h>
#include <usbmidi.h>
#include "midievents.h"
#include "commands.h"
#include <AltSoftSerial.h>
#include "OneButton.h"


OneButton button1(A8, true);
AltSoftSerial altSerial;
USB Usb;
USBH_MIDI  Midi(&Usb);
uint16_t pid, vid;
char cmd[14] = {};
uint8_t notes[128];
uint8_t cc[128];
uint8_t midiCommand, midiChannel, midiParam1, midiParam2;
uint8_t position;
bool hasUsbDevice = 0;
bool dropZeroCC;
bool showHasUsbDevice = 0;
unsigned long time_now = 0;


uint8_t switchStore[20];
uint8_t paramStore[127];

int incomingByte = 0; // for incoming serial data

bool useFlatMidiMap;

bool flip = false;

bool readInputFromMidiDevice();
bool readInputFromMidiHost();
bool readInputFromMidiSerial();
void connect_usb_midi();
void logUsbDeviceStatus();
void logMessageToSerial();

void setCmd(char* inputCmd, uint8_t inputParam = 0);
void setCmdNoReplace(char* inputCmd);
void setCmdSwitch(char* inputCmd1, char* inputCmd2, uint8_t switchIndex);
void setCmdToggleAVE55(char* inputCmd, uint8_t start, uint8_t offset, uint8_t switchIndex);
void setCmdStepAVE55(char* inputCmd, uint8_t param, uint8_t start, uint8_t offset);

void setCmdToggleMX50(char* inputCmd, uint8_t maxValue, uint8_t switchIndex);
void setCmdStepMX50(char* inputCmd, uint8_t param, uint8_t maxValue);
void setCmdParamRandom(char* inputCmd);



void setDelugeExtronMap(){

  if(midiCommand == MIDICOMMAND::NOTEON){
    if(midiParam1 == 60){setCmdNoReplace(EXTRON_MAV_1x1);}
    else if(midiParam1 == 62){setCmdNoReplace(EXTRON_MAV_1x2);}
    else if(midiParam1 == 64){setCmdNoReplace(EXTRON_MAV_1x3);}
    else if(midiParam1 == 65){setCmdNoReplace(EXTRON_MAV_2x1);}
    else if(midiParam1 == 67){setCmdNoReplace(EXTRON_MAV_2x2);}
    else if(midiParam1 == 69){setCmdNoReplace(EXTRON_MAV_2x3);}
    else if(midiParam1 == 71){setCmdNoReplace(EXTRON_MAV_3x1);}
    else if(midiParam1 == 72){setCmdNoReplace(EXTRON_MAV_3x2);}
    else if(midiParam1 == 74){setCmdNoReplace(EXTRON_MAV_3x3);}
  }
}

void setAVE55nanokontrolMap(){

  if(midiCommand == MIDICOMMAND::NOTEON){
    // put note commands here
  }
  else if(midiCommand == MIDICOMMAND::CC){
    // slider row:
    if(midiParam1 == 0){setCmd(A55_A_B_MIX_LEVEL, midiParam2);}
    else if(midiParam1 == 1){setCmd(A55_THRESHOLD_LUM_KEY, midiParam2);}
    else if(midiParam1 == 2){setCmd(A55_CENTER_WIPE_X, midiParam2);}
    else if(midiParam1 == 3){setCmd(A55_CENTER_WIPE_Y, midiParam2);}
    else if(midiParam1 == 4){setCmd(A55_SCENE_GRABER_X, midiParam2);}
    else if(midiParam1 == 5){setCmd(A55_SCENE_GRABER_Y, midiParam2);}
    else if(midiParam1 == 6){setCmd(A55_COLOR_CORECT_X, midiParam2);}
    else if(midiParam1 == 7){setCmd(A55_COLOR_CORECT_Y, midiParam2);}

    // knob row
    else if(midiParam1 == 16){setCmdStepAVE55(A55_A_BUS_STROBO_OFF, midiParam2, 70, 6);}
    else if(midiParam1 == 17){setCmdStepAVE55(A55_A_BUS_MOSAIC_OFF, midiParam2, 76, 6);}
    else if(midiParam1 == 18){setCmdStepAVE55(A55_A_BUS_PAINT_OFF, midiParam2, 82, 6);}
    // else if(midiParam1 == 19){setCmdStepAVE55(A55_A_BUS_PAINT_OFF, midiParam2, 82, 6);}
    else if(midiParam1 == 20){setCmdStepAVE55(A55_B_BUS_STROBO_OFF, midiParam2, 94, 6);}
    else if(midiParam1 == 21){setCmdStepAVE55(A55_B_BUS_MOSAIC_OFF, midiParam2, 100, 6);}
    else if(midiParam1 == 22){setCmdStepAVE55(A55_B_BUS_PAINT_OFF, midiParam2, 106, 6);}
    // else if(midiParam1 == 23){setCmdStepAVE55(A55_A_BUS_PAINT_OFF, midiParam2, 82, 6);}

    // top row buttons (S)
    else if(midiParam1 == 32){setCmdToggleAVE55(A55_WIPE_SQUARE_CORNER_UL, 1, 16, 0);}
    else if(midiParam1 == 33){setCmdToggleAVE55(A55_WIPE_SQUARE, 17, 7, 9);}
    else if(midiParam1 == 34){setCmdToggleAVE55(A55_DIRECTION_ONE_WAY, 40, 2, 2);}
    else if(midiParam1 == 35){setCmdParamRandom(A55_A_B_MIX_LEVEL);}
    // else if(midiParam1 == 36){setCmdToggleAVE55(A55_WIPE_SQUARE_CORNER_UL, 1, 16, 0);}
    // else if(midiParam1 == 37){setCmdToggleAVE55(A55_WIPE_SQUARE, 17, 7, 9);}
    // else if(midiParam1 == 38){setCmdToggleAVE55(A55_DIRECTION_ONE_WAY, 40, 2, 2);}
    // else if(midiParam1 == 39){setCmdParamRandom(A55_A_B_MIX_LEVEL);}
    
    // middle row buttons (M)
    else if(midiParam1 == 48){setCmd(A55_WIPE_MIX_BUTTON);}
    else if(midiParam1 == 49){setCmd(A55_LUM_KEY);}
    else if(midiParam1 == 50){setCmdToggleAVE55(A55_A_BUS_EFFECT_ON, 180, 2, 5);}
    else if(midiParam1 == 51){setCmdToggleAVE55(A55_B_BUS_EFFECT_ON, 182, 2, 6);}
    else if(midiParam1 == 52){setCmdToggleAVE55(A55_A_BUS_NEGATIVE_OFF, 87, 2, 3);}
    else if(midiParam1 == 53){setCmdToggleAVE55(A55_B_BUS_NEGATIVE_OFF, 111, 2, 4);}
    else if(midiParam1 == 54){setCmdToggleAVE55(A55_B_BUS_COLOR_CORRECTOR_OFF, 115, 2, 7);}
    else if(midiParam1 == 55){setCmdToggleAVE55(A55_A_BUS_COLOR_CORRECTOR_OFF, 91, 2, 8);}

    // bottom row buttons (R)
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

void setMX50nanokontrolMap(){

  if(midiCommand == MIDICOMMAND::NOTEON){
    // put note commands here
  }
  else if(midiCommand == MIDICOMMAND::CC){
    // slider row:
    if(midiParam1 == 0){setCmd(MX50_A_B_MIX_LEVEL, midiParam2);}
    else if(midiParam1 == 1){setCmd(MX50_THRESHOLD_LUM_KEY, midiParam2);}
    else if(midiParam1 == 2){setCmd(MX50_CENTER_WIPE_X, midiParam2);}
    else if(midiParam1 == 3){setCmd(MX50_CENTER_WIPE_Y, midiParam2);}
    else if(midiParam1 == 4){setCmd(MX50_KEY_SLICE, midiParam2);}
    // else if(midiParam1 == 5){setCmd(MX50_SCENE_GRABER_Y, midiParam2);}
    // else if(midiParam1 == 6){setCmd(MX50_COLOR_CORECT_X, midiParam2);}
    // else if(midiParam1 == 7){setCmd(MX50_COLOR_CORECT_Y, midiParam2);}

    // knob row
    else if(midiParam1 == 16){setCmd(MX50_COLOR_CORRECT_X, midiParam2);}
    else if(midiParam1 == 17){setCmd(MX50_COLOR_CORRECT_Y, midiParam2);}
    else if(midiParam1 == 18){setCmd(MX50_COLOR_CORRECT_GAIN, midiParam2);}
    // else if(midiParam1 == 19){setCmd(MX50_B_BUS_COLOR_CORRECT_Y, midiParam2);}

    else if(midiParam1 == 20){setCmdStepMX50(MX50_STROBO, midiParam2, 62);}
    else if(midiParam1 == 21){setCmdStepMX50(MX50_MOSAIC, midiParam2, 30);}
    else if(midiParam1 == 22){setCmdStepMX50(MX50_PAINT, midiParam2, 7);}
    // else if(midiParam1 == 23){setCmdStepAVE55(A55_A_BUS_PAINT_OFF, midiParam2, 82, 6);}

    // top row buttons (S)

    else if(midiParam1 == 32){setCmdSwitch(MX50_A_BUS_COLOR_CORRECT_ON, MX50_A_BUS_COLOR_CORRECT_OFF, 0);}
    else if(midiParam1 == 33){setCmdSwitch(MX50_B_BUS_COLOR_CORRECT_ON, MX50_B_BUS_COLOR_CORRECT_OFF, 1);}
    else if(midiParam1 == 34){setCmdSwitch(MX50_SCENE_GRABER_ON, MX50_SCENE_GRABER_OFF, 2);}
    else if(midiParam1 == 35){setCmdParamRandom(MX50_A_B_MIX_LEVEL);}
    else if(midiParam1 == 36){setCmd(MX50_A_BUS_STROBO_OFF);}
    else if(midiParam1 == 37){setCmd(MX50_A_BUS_MOSAIC_OFF);}
    else if(midiParam1 == 38){setCmd(MX50_A_BUS_PAINT_OFF);}
    else if(midiParam1 == 39){setCmdToggleMX50(MX50_WIPE, 40, 5);}
    
    // middle row buttons (M)
    // else if(midiParam1 == 48){setCmd(A55_WIPE_MIX_BUTTON);}
    // else if(midiParam1 == 49){setCmd(MX50_WIPE_NUMBER);}
    else if(midiParam1 == 50){setCmdSwitch(MX50_A_BUS_EFFECT_ON, MX50_A_BUS_EFFECT_OFF, 3);}
    else if(midiParam1 == 51){setCmdSwitch(MX50_B_BUS_EFFECT_ON, MX50_B_BUS_EFFECT_OFF, 4);}
    else if(midiParam1 == 52){setCmd(MX50_A_BUS_NEGATIVE_OFF);}
    else if(midiParam1 == 53){setCmd(MX50_A_BUS_NEGATIVE_ON);}
    else if(midiParam1 == 54){setCmd(MX50_B_BUS_NEGATIVE_OFF);}
    else if(midiParam1 == 55){setCmd(MX50_B_BUS_NEGATIVE_ON);}

    // bottom row buttons (R)
    else if(midiParam1 == 64){setCmd(MX50_A_BUS_SOURCE_1);}
    else if(midiParam1 == 65){setCmd(MX50_A_BUS_SOURCE_2);}
    else if(midiParam1 == 66){setCmd(MX50_A_BUS_SOURCE_3);}
    else if(midiParam1 == 67){setCmd(MX50_A_BUS_SOURCE_4);}
    else if(midiParam1 == 68){setCmd(MX50_B_BUS_SOURCE_1);}
    else if(midiParam1 == 69){setCmd(MX50_B_BUS_SOURCE_2);}
    else if(midiParam1 == 70){setCmd(MX50_B_BUS_SOURCE_3);}
    else if(midiParam1 == 71){setCmd(MX50_B_BUS_SOURCE_4);}
  }
}

void setup(){
  altSerial.begin(31250);
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8N1); // use SERIAL_7O1 for mx50, ,default (SERIAL_8N1) for kramer, ave55 and extron // 
  button1.attachClick(connect_usb_midi);

  hasUsbDevice = false;
  vid = pid = 0;
  switchStore[2] = {};
  useFlatMidiMap = true;
  dropZeroCC = true; // to ignore 'note_off' cc messages

  connect_usb_midi();

}

void loop(){
  button1.tick();
  logUsbDeviceStatus();
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

  if(midiChannel == 0){setAVE55nanokontrolMap();}

  logMessageToSerial();


  if(cmd[0] == 0){return;}
  Serial1.write(2);
  Serial1.write(cmd);
  Serial1.write(3);

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

    altSerial.write(first);
    altSerial.write(midiParam1);
    altSerial.write(midiParam2);

    USBMIDI.flush();
    return true;
  }
  return false;
}

bool readInputFromMidiSerial(){

  if(altSerial.available() < 3){ return false;}
  //Skip to beginning of next message (silently dropping stray data bytes)
  while(!(altSerial.peek() & 0x80)){ altSerial.read(); }
  if(altSerial.available() < 3){ return false;}
  uint8_t first = altSerial.read();

  midiCommand = first & 0xF0; // command 0b11110000 = 0xF0
  midiChannel = first & 0xF; // channel 0b00001111 = 0xF
  midiParam1 = altSerial.read(); // param 1
  midiParam2 = altSerial.read(); // param 2

  // altSerial.flush();
  while(altSerial.available()){altSerial.read();}

  return true;
}

void setCmd(char* inputCmd, uint8_t inputParam){

  // Serial.print(inputCmd);
  // Serial.print("<-- input command\n");
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

void setCmdNoReplace(char* inputCmd){

  Serial.print(inputCmd);
  Serial.print("<-- input command\n");
  strcpy(cmd, inputCmd);

}

void setCmdSwitch(char* inputCmd1, char* inputCmd2, uint8_t switchIndex){
  if(switchStore[switchIndex] == 0){setCmd(inputCmd1); }
  else{ setCmd(inputCmd2); }
  switchStore[switchIndex] = (switchStore[switchIndex] + 1) % 2;
}

void setCmdToggleAVE55(char* inputCmd, uint8_t start, uint8_t offset, uint8_t switchIndex){
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

void setCmdStepAVE55(char* inputCmd, uint8_t param, uint8_t start, uint8_t offset){
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

void setCmdStepMX50(char* inputCmd, uint8_t param, uint8_t maxValue){
  strcpy(cmd, inputCmd);
  char maxHex[6] = {};
  sprintf(maxHex, "%X", maxValue+1);
  int maxHexSize = 0;
  for (uint8_t i = 0; i < 6; i++){
    if(maxHex[i] != 0 ){maxHexSize++;}
  }
  int value = (param * maxValue) / 128;
  char valueHex[6] = {};

  if(maxHexSize == 1){ sprintf(valueHex, "%1X", value);}
  else if(maxHexSize == 2){sprintf(valueHex, "%02X", value);}
  else{sprintf(valueHex, "%X", value);}

  for(uint8_t i = 0; i < 11; i++){
    if(cmd[i] == '~' ){
      for(uint8_t j=0; j < 6; j++){
        if(valueHex[j] != 0){cmd[i+j] = valueHex[j];}
      }
    }
  }

setCmd(cmd);
}

void setCmdToggleMX50(char* inputCmd, uint8_t maxValue, uint8_t switchIndex){
  strcpy(cmd, inputCmd);
  char valueChar[4] = {};
  sprintf(valueChar, "%02d", switchStore[switchIndex]);
  for(uint8_t i = 0; i < 11; i++){
    if(cmd[i] == '~' ){
      for(uint8_t j=0; j < 4; j++){
        if(valueChar[j] != 0){cmd[i+j] = valueChar[j];}
      }
    }
  }

  switchStore[switchIndex] = (switchStore[switchIndex] + 1) % maxValue; 
}

void logMessageToSerial(){
  Serial.print(midiParam1);
  Serial.print("<-note (midiParam1)\n");
  Serial.print(midiChannel);
  Serial.print("<-channel  (midiChannel)\n");
  Serial.print(midiCommand);
  Serial.print("<-command (midiCommand)\n"); 
  // midiParam2 = midiParam2 - 64; // weird off by 64 bug ??
  Serial.print(midiParam2);
  Serial.print("<-value (midiParam2)\n\n");

  // write the command to serial port
  Serial.print("\n");
  Serial.print(cmd);
  Serial.print("<-cmd\n");
}

void connect_usb_midi() {
  Serial.println("Button 1 click.");
    if (Usb.Init() == 0){ // means it is successful
      hasUsbDevice = true;
    }
  showHasUsbDevice = 1;
  time_now = millis();
} // click1

void logUsbDeviceStatus(){
  if(showHasUsbDevice && millis() > time_now + 400){
    Serial.print(Midi.GetAddress() != 0);
    Serial.print("<--attached device\n");
    showHasUsbDevice = 0;
    time_now = 0;
  }
}