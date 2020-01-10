// #include "transcriber.h"


// // USB Usb;
// // //USBHub Hub(&Usb);
// // USBH_MIDI  Midi(&Usb);
// // uint16_t pid, vid;

// void Transcriber::begin(bool useUsbClient=true, bool useSerial=false, bool useUsbHost=false){
//   Serial1.begin(9600);
//   Serial.begin(9600);

// // set up usb host
//   // vid = pid = 0;
//   if (Usb.Init() == -1) {
//     while (1); //halt
//   }//if (Usb.Init() == -1...
//   delay( 200 );
// };

// void Transcriber::update(){
//   // read midi device input
//   // MidiMessage midiMessage = readMidiDeviceInput();
// // read midi host input
//   MidiMessage midiMessage = readMidiHostInput();

//   if(midiMessage.command == 0){return;}
//   Serial.print(midiMessage.command);
//   // check for input in mapping
// 	uint8_t matchedIndex = checkMap(midiMessage);
//   if(matchedIndex< 0){return;}
//   // call output command
//   callOutputCommand(matchedIndex, midiMessage.param1, midiMessage.param2);

// };



// MidiMessage Transcriber::readMidiDeviceInput(){
//   USBMIDI.poll();
//   MidiMessage midiMessage;
//   if(USBMIDI.available()){
//     //Skip to beginning of next message (silently dropping stray data bytes)
//     while(!(USBMIDI.peek() & 0x80)) USBMIDI.read();

//     uint8_t first = USBMIDI.read();

//     midiMessage.command = first & 0xF0; // command
//     midiMessage.channel = first & 0xF; // channel
//     midiMessage.param1 = USBMIDI.read(); // param 1
//     midiMessage.param2 = USBMIDI.read(); // param 2

//     USBMIDI.flush();
//   }
//   return midiMessage;
// }

// MidiMessage Transcriber::readMidiHostInput(){
//   Usb.Task();
//   uint8_t bufMidi[3];
//   MidiMessage midiMessage;
//   uint16_t  rcvd;

//   if (Midi.RecvData(&rcvd,  bufMidi) == 0 ) {
//       uint8_t first = bufMidi[1];
//       midiMessage.command = first & 0xF0; // command
//       midiMessage.channel = first & 0xF; // channel
//       midiMessage.param1 = bufMidi[2]; // param 1
//       midiMessage.param2 = bufMidi[3]; // param 2

//       // Serial.print(bufMidi[3]);
//       // Serial.print(midiMessage.channel);
//       // Serial.print("<-channel");
//       // Serial.print(midiMessage.param1);
//       // Serial.print("<-param1");
//       // Serial.print(midiMessage.param2);
//       // Serial.print("<-param2");
//   }
//   return midiMessage;
// }

// uint8_t Transcriber::checkMap(MidiMessage midiMessage){

//   for(uint8_t i=0; i<mappingIndex; i++){

//     if(midiMessage.command == mappingList[i].input.getTypeHex() && (midiMessage.param1 == mappingList[i].input.param1 || midiMessage.param1 == mappingList[i].input.param1_y)){
//       return i;
//     }
//   }
//   return -1;
// }

// void Transcriber::callOutputCommand(uint8_t matchedIndex, uint8_t midiParam1, uint8_t midiParam2){

//   char cmd[8] = {};
//   mappingList[matchedIndex].output.getCmd(cmd);

//   uint8_t outputType = mappingList[matchedIndex].output.type;
//   if(outputType == 0 or outputType == 3){
//     serialWrite(cmd);
//   }
//   else if(outputType == 1){
//     serialWriteParam(cmd, midiParam2);
//   }
//   else if(outputType == 2){
//     uint8_t param1 = mappingList[matchedIndex].input.param1;
//     uint8_t param1_y = mappingList[matchedIndex].input.param1_y;

//     if(midiParam1 == param1){
//       uint8_t paramY = mappingList[matchedIndex].output.paramY;
//       serialTwoWriteParams(cmd, midiParam2, paramY);
//       mappingList[matchedIndex].output.updateParamX(midiParam2);
//     }
//     else if(midiParam1 == param1_y){
//       uint8_t paramX = mappingList[matchedIndex].output.paramX;
//       serialTwoWriteParams(cmd, paramX, midiParam2);
//       mappingList[matchedIndex].output.updateParamY(midiParam2);
//     }
//   }
// }

// void Transcriber::serialWrite(char cmd[]){

//   Serial1.write(2);
//   Serial1.write(cmd);
//   Serial1.write(3);
// }

// void Transcriber::serialWriteParam(char cmd[], uint8_t param){
//   String hexParam =  String(param * 2, HEX);
//   hexParam.toUpperCase();

//   Serial1.write(2);
//   Serial1.write(cmd);
//   Serial1.write(hexParam.c_str());
//   Serial1.write(3);
// }

// void Transcriber::serialTwoWriteParams(char cmd[], uint8_t param1, uint8_t param2){

//   Serial1.write(2);
//   Serial1.write(cmd);
//   char hexParam1[2];
//   sprintf(hexParam1, "%02X", param1*2);
//   Serial1.write(hexParam1);
//   char hexParam2[2];
//   sprintf(hexParam2, "%02X", param2*2);
//   Serial1.write(hexParam2);
//   Serial1.write(3);
// }