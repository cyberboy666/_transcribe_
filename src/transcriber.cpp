#include "transcriber.h"




void Transcriber::begin(bool useUsbClient=true, bool useSerial=false, bool useUsbHost=false){
  
};

void Transcriber::update(){
  // read midi input
  MidiMessage midiMessage = readMidiInput();

  if(midiMessage.command == 0){return;}
  // check for input in mapping
	int matchedIndex = checkMap(midiMessage);
  if(matchedIndex< 0){return;}
  // call output command
  callOutputCommand(matchedIndex, midiMessage.param2);

};



MidiMessage Transcriber::readMidiInput(){
  USBMIDI.poll();
  MidiMessage midiMessage;
  if(USBMIDI.available()){
    //Skip to beginning of next message (silently dropping stray data bytes)
    while(!(USBMIDI.peek() & 0x80)) USBMIDI.read();

    uint8_t first = USBMIDI.read();

    midiMessage.command = first & 0xF0; // command
    midiMessage.channel = first & 0xF; // channel
    midiMessage.param1 = USBMIDI.read(); // param 1
    midiMessage.param2 = USBMIDI.read(); // param 2

    USBMIDI.flush();
  }
  return midiMessage;
}

int Transcriber::checkMap(MidiMessage midiMessage){

  for(int i=0; i<mappingIndex; i++){

    if(midiMessage.command == mappingList[i].input.getTypeHex() && midiMessage.param1 == mappingList[i].input.param1){
      return i;
    }
  }
  return -1;
}

void Transcriber::callOutputCommand(int matchedIndex, uint8_t midiParam){
  bool hasParam = mappingList[matchedIndex].output.hasParam();

  char cmd[8] = {};
  mappingList[matchedIndex].output.getCmd(cmd);

  if(hasParam){
    serialWriteParam(cmd, midiParam);
  }
  else{
    serialWrite(cmd);
  }
  
}

void Transcriber::serialWrite(char cmd[]){


  Serial1.write(2);
  Serial1.write(cmd);
  Serial1.write(3);

  
  // Serial.write(2);
  // Serial.write(cmd.c_str());
  // Serial.write(3);

};

void Transcriber::serialWriteParam(char cmd[], uint8_t param){
Serial.print(param * 2);
Serial.print(" - ");
String hexParam =  String(param * 2, HEX);
hexParam.toUpperCase();
Serial.print(hexParam);

  Serial1.write(2);
  Serial1.write(cmd);
  // Serial1.write(hexParam);
  Serial1.write(hexParam.c_str());
  Serial1.write(3);

  
  // Serial.write(2);
  // Serial.write(cmd.c_str());
  // Serial.write(3);

};