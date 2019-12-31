# _transcribe_
for midi control of panasonic video mixers

## idea / overview

promicro setup : https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/all

.... some links here, explaining ...

- take midi in (see different ways below)
- send serial out (for ave55)
- convert to r232 with max232 chip
- connect to 3.5 trs jack

https://arduinodiy.wordpress.com/2012/03/19/serial-connection-for-your-arduino-atmega

wiring max232n : 

![image](https://user-images.githubusercontent.com/12017938/71274322-665fc980-2354-11ea-928c-a6fc264001fb.png)

![image](https://user-images.githubusercontent.com/12017938/71275155-a030d000-2354-11ea-98e1-16ea6839eb72.png)

![image](https://user-images.githubusercontent.com/12017938/71278010-b6d82680-2356-11ea-99df-124c4aaaf7f1.png)

## want to support for : 

### usb midi device

usb midi from a host ie computer, pi etc, this should be the easiest to implement

### serial midi

from din midi devices - for this would have to have 2 serial ports, one listening to midi in, and one writing to ave55 out, i thin k the best thing to try is midi on the hardware serial and ave55 on [AltSoftSerial](https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html)

### usb midi host

from things like nano control - needs a host shield - maybe like [this](https://www.aliexpress.com/item/32942427334.html) one : 

reading midi from host and outputting as serial : https://github.com/felis/USB_Host_Shield_2.0/blob/master/examples/USBH_MIDI/USB_MIDI_converter/USB_MIDI_converter.ino
question about mini-host and pro-micro : https://github.com/felis/USB_Host_Shield_2.0/issues/392
an old thread talking about hooking these up together : https://forum.sparkfun.com/viewtopic.php?t=34873
another thread about hooking these up: https://forum.pjrc.com/threads/43357-Teensy-with-mini-USB-host-shield-(chineese)

## want to also support other mixers with similar controls

- mx50 ?
- others ??

## some ideas of ideal structure

- an intial flag for configuring what input to listen to ... (also what the output device is)
- a list of mappings between serial commands and midi notes/ccs
- continuous controls -> cc values (ie mix position...)
- buttons -> notes or cc (sources, )
- switches (toggles) -> single note/cc (ie pressing once for on, again for off ?)
- range of values (steps) -> cc values (ie paint0, paint1, paint2, paint3)

## some things to check / try / do

- try with the level-shifter circuit
- try with smaller caps
- try with altSoftSerial
- try with serial midi input (how?)
- try with usb midi host sheild
- implement other types of commands
- create a pcb design