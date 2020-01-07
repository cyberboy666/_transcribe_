
#include <AltSoftSerial.h>
// #include <usbh_midi.h>
// #include <usbhub.h>
#include "src/transcriber.h"

int RXLED = 17;
Transcriber transcriber;
AltSoftSerial altSerial;

void setup() {
  altSerial.begin(9600);

  Serial1.begin(9600);
  Serial.begin(9600);
  transcriber.begin();


  // NoteOn input(MIDINOTE::C4);
  // OutputElement output("BUTTON", AVE55::MIX_MODE);
    // transcriber.map(input, output);

    transcriber.map(InputElement(INTYPE::NOTE, MIDINOTE::C4), OutputElement(OUTTYPE::SWITCH, AVE55::MIX_MODE));
    transcriber.map(InputElement(INTYPE::CCVALUE, 0), OutputElement(OUTTYPE::SLIDER, AVE55::A_B_MIX_LEVEL));
    transcriber.map(InputElement(INTYPE::CCVALUE, 1, INTYPE::CCVALUE, 2), OutputElement(OUTTYPE::SLIDER_TWO, AVE55::CENTER_WIPE));

    // char* switchCommands[2] = {AVE55::A_BUS_SOURCE_1, AVE55::A_BUS_BACK_COLOR};
    // transcriber.map(InputElement(INTYPE::NOTE, MIDINOTE::C4SHARP), OutputElement(OUTTYPE::SWITCH, AVE55::A_BUS_SOURCE_1, AVE55::A_BUS_BACK_COLOR));
    // transcriber.map(InputElement(INTYPE::NOTE, MIDINOTE::C4SHARP), OutputElement(OUTTYPE::SWITCH, switchCommands));


  // transcriber.map(InputElement(NoteOn(61)), OutputElement(Button(AVE55::A_BUS_MOSAIC_STEP_1)));
  // transcriber.map(InputElement(NoteOn(62)), OutputElement(Button(AVE55::A_BUS_MOSAIC_STEP_2)));
  // transcriber.map(InputElement(NoteOn(63)), OutputElement(Button(AVE55::A_BUS_MOSAIC_STEP_3)));
  // transcriber.map(InputElement(NoteOn(64)), OutputElement(Button(AVE55::A_BUS_MOSAIC_STEP_4)));
  pinMode(RXLED, OUTPUT);
}


void loop() {

  transcriber.update();

  // altSerial.write(2);
  // altSerial.write("VMX:000");
  // altSerial.write(3);
  // delay(1000);

  // digitalWrite(RXLED, LOW);
  // Serial1.write(2);
  // Serial1.write(86);
  // Serial1.write(77);
  // Serial1.write(88);
  // Serial1.write(58);
  // Serial1.write(48);
  // Serial1.write(48);
  // Serial1.write(48);
  // // Serial1.write("VCP:200"); // 86 67 80 58 50 48 48 // 86 77 88 58 48 48 48 
  // Serial1.write(3);
  // delay(1000);
  // digitalWrite(RXLED, HIGH);
  // Serial1.write(2);
  // Serial1.write(86);
  // Serial1.write(67);
  // Serial1.write(80);
  // Serial1.write(58);
  // Serial1.write(50);
  // Serial1.write(48);
  // Serial1.write(51);
  // // Serial1.write("VCP:203"); // 86 67 80 58 50 48 51 
  // Serial1.write(3);
  // delay(1000);

}
