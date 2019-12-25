#include "transcriber.h"


void Transcriber::begin(bool useUsbClient=true, bool useSerial=false, bool useUsbHost=false){

    Serial1.begin(9600);
    Serial.begin(9600);

};

void Transcriber::update(){

  midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();
    if (rx.header != 0) {
      callMap(rx);
    }
  } while (rx.header != 0);

};

void Transcriber::map(InputElement input, OutputElement output){
    mappingList[mappingIndex] = Mapping(input, output);
    mappingIndex++;
};

void Transcriber::callMap(midiEventPacket_t rx){
      Serial.print("Received: ");
      Serial.print(rx.header, HEX);
      Serial.print("-");
      Serial.print(rx.byte1, HEX);
      Serial.print("-");
      Serial.print(rx.byte2, HEX);
      Serial.print("-");
      Serial.println(rx.byte3, HEX);
    // Serial.write(rx);
}

void Transcriber::serialWrite(String cmd){
  Serial1.write(2);
  Serial1.write(cmd.c_str());
  Serial1.write(3);

};