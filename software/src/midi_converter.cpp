// #include <usbmidi.h>
// #include <SPI.h>

// void setup() {
//   Serial1.begin(31250); //MIDI baudrate
// }

// void loop() {
//   //Handle USB communication
//   USBMIDI.poll();

//   //Forward MIDI
//   while(USBMIDI.available()) Serial1.write(USBMIDI.read());
//   Serial1.flush();
//   while(Serial1.available()) USBMIDI.write(Serial1.read());
//   USBMIDI.flush();
// }