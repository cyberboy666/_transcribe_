// #include <usbmidi.h>
// #include <SPI.h>
// #include <AltSoftSerial.h>

// AltSoftSerial altSerial;

// void setup() {
// //   Serial1.begin(31250); //MIDI baudrate
//   altSerial.begin(31250);
// }

// void loop() {
//   //Handle USB communication
//   USBMIDI.poll();

//   //Forward MIDI
//   while(USBMIDI.available()){
// altSerial.write(USBMIDI.read());
// // Serial.write("receiving");
//   }
   
//   altSerial.flush();
//   while(altSerial.available()) Serial.write(altSerial.read());
//   USBMIDI.flush();

// }