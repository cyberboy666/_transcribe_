whenever i start a project i like to keep a list of ideas, thoughts, srceen-caps and todo lists in one place

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

from din midi devices - for this would have to have 2 serial ports, one listening to midi in, and one writing to ave55 out, i thin k the best thing to try is midi on the hardware serial and ave55 on [AltSoftSerial](https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html) , altSoftSerial on pro micro is missing the input pin , but it seems this can be modded in without too much trouble : https://forum.arduino.cc/index.php?topic=339587.0

### usb midi host

from things like nano control - needs a host shield - maybe like [this](https://www.aliexpress.com/item/32942427334.html) one : 

reading midi from host and outputting as serial : https://github.com/felis/USB_Host_Shield_2.0/blob/master/examples/USBH_MIDI/USB_MIDI_converter/USB_MIDI_converter.ino
question about mini-host and pro-micro : https://github.com/felis/USB_Host_Shield_2.0/issues/392
an old thread talking about hooking these up together : https://forum.sparkfun.com/viewtopic.php?t=34873
another thread about hooking these up: https://forum.pjrc.com/threads/43357-Teensy-with-mini-USB-host-shield-(chineese)

### further research into using the usb-host:

- it seems that the vbus (5v) needs to be cut from the vcc (3.3v) , here is best example : https://www.arduino.cn/thread-81435-1-1.html
- i need a 3.3v power source for the usb-host , prob best bet is a L78L33 (18c, up to 100ma) or LM1117T (99c up to 800ma)
- for the wiring , in theroy a level-shifter should be used between 5v arduino and 3.3v ic (74HC125) , but people have reported success with a arduio nano , which is also 5v so im thinking maybe this will also just work ?? but other places suggest it wont ,, im not sure - should try this circuit with a 3.3board too ?
- also a 100uF cap in line with the power is reccomended here : https://www.pjrc.com/teensy/td_libs_USBHostShield.html

- for the wiring , it should look something like this :

host | pro-micro | name
--- | --- | ---
5 | ? | ss
6 | 16 | mosi
7 | 14 | miso
8 | 15 | sck
2 | ? | int
1 | vcc | 5v
9 | regulator | 3.3v
3 | gnd | gnd
4 | rst | rst

- also suggested to wire rst to power ... 

![HOST](https://user-images.githubusercontent.com/12017938/71743665-6a680d00-2e65-11ea-9b93-f5de6802a3c6.JPG)
![image](https://user-images.githubusercontent.com/12017938/71743326-933bd280-2e64-11ea-9e26-02f71ec2c89f.png)

## other panansonic (or other) mixers

- panasonic ave55 is rs232 on a stereo 3.5mm jack

- mx50 has a rs232 / rs422 switch , the interface is a 9pin dsub (with a bunch of confusing swtiches / settings)
- mx30 has 9pin dbus with rs232
- mx20 has serial on a mini-din , it says rs422 - hard to tell if it will work or how to make it ...
mx70 has 9pin dsub with rs232 also
- others ??

## some ideas of ideal structure

- ~~a list of mappings between serial commands and midi notes/ccs~~
- ~~continuous controls -> cc values (ie mix position...)~~
- ~~buttons -> notes or cc (sources, )~~
- ~~switches (toggles) -> single note/cc (ie pressing once for on, again for off ?)~~
- ~~range of values (steps) -> cc values (ie paint0, paint1, paint2, paint3)~~

## some things to check / try / do

- try with the level-shifter circuit - i tried but it didnt work - maybe my circuit was wrong tho
- ~~try with smaller caps~~ this works horray
- ~~try with altSoftSerial~~ - seems to work
- ~~try with serial midi input (how?) maybe i will need to work with 2 arduinos , one for sending midi another for receiving~~
- ~~try with usb midi host sheild~~ 
- implement other types of commands (random / osolatoer etc .. )
- create a pcb design
