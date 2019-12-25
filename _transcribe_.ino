#include "src/transcriber.h"

int RXLED = 17;
Transcriber transcriber;

void setup() {

  InputElement input(NoteOn(MIDINOTE::C4));
  OutputElement output(Button(AVE55::WIPE_SQUARE));

  transcriber.begin();
  transcriber.map(input, output);
  pinMode(RXLED, OUTPUT);
}


void loop() {

  transcriber.update();
}
