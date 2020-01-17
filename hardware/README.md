# _transcribe_ hardware

this is the hardware section of _transcribe_ - a project created to control panasonic video_mixers with midi.

# BOM

ref | part | source | source-id | section
--- | --- | --- | --- | ---
? | _transcribe_ pcb | me? or a fab-house | ...  | all
? | sparkfun pro-micro 5v | [ali](https://www.aliexpress.com/item/1348800135.html) [amazon](https://www.amazon.com/OSOYOO-ATmega32U4-arduino-Leonardo-ATmega328/dp/B012FOV17O/), [sparkfun](https://www.sparkfun.com/products/12640) | - | A
? | max232n ic | tayda | A-034 | B
? | 0.1uF caps | tayda | A-4008 | B
? | 3.5mm TSR jacks | tayda | A-853 | B , C
? | din jacks | tayda | A-1010 | B , C
? | dsub9 | tayda | A-300 | B , C
? | 6n137 | tayda | A-871 | C
? | resistors and diode | tayda | - | C
? | USB-host sheild mini | [ali](https://www.aliexpress.com/item/32842815739.html) [amazon](https://www.amazon.com/HiLetgo-Development-Compatible-Interface-Arduino/dp/B01EWW9R1E/) | - | D
? |  78L33 regulator | tayda | A-492 | D


## potential additional parts to add : 

- version for arduino nano ? (dont need regulator)
- 74hc14 inverter for buffered serial midi out ? or transistor inverter ?
- power caps (main for usb-host , but also for in general )
- switches to select serial-midi TRS standard , and/or din option ?
- a dsub9 / dsub9 breakout

## assemble guide :

blah blah blah

IF USING USB_HOST_MIDI YOU __MUST CUT A TRACE__ ON THE BOARD ! heres how - ...

# explaining the sections of _transcribe_

 _transcribe_ is based around an arduino micro controller. included in this circuit are a number of different ways to input midi and output serial. you can choose which sections to populate based on your personal requirements.

## A - micro-conntroller - centre

this is the brain of the circuit and is __required__ to make it do anything. i am using a sparkfun pro-micro 5v, which uses micro-usb as power. (it is likely this circuit will also work with an arduino nano - which will require a seperate version of the pcb - but watch this space)

## B - rs232 serial - output(/input)

panasonic video mixers (and other older devices) use a different serial standard (RS232) to micro-controllers (ttl). in this section serial commands from the uC are level-shifted to be recongised by these devices. _only obmit this section if you are not interested in controlling old (rs232) gear_. the data is exposed on a 3.5mm TRS (stereo) jack; tip - input, ring - output, sleave - ground.

NOTE - although not used by the default firmware, the hardware also allows rs232 serial input, so this porject could be modified to also control something _from_ old gear

## C - serial midi - input(/output)

the uC (in A) can act as a USB midi _device_. this means it can be controlled by a USB midi _host_ (such as a computer running abeton, or a raspberry pi). this section includes the additional circuity to also control it with serial-midi (often seen on older instruments with din5 type plugs)

NOTE - although din5 plugs are often used for connecting old gear with serial midi, these sockets can be bulky and sometimes difficult to find. for this reason newer gear supporting serial-midi often use TRS jacks - leaving the standard-conversion to cables. i would use 3.5mm TRS (stereo) also for midi in and out, with tip - midi data (din-pin4), ring - midi plus (din-pin5), sleave - unconnected (or include a switch to swap tip/ring...)

NOTE - although not used by the default firmware, the hardware also allows serial-midi output, so this project could be modified to also output serial midi

_obmit this section if you are not interested in interfacing with 'old style' serial midi_

## D USB-midi HOST

the uC (in A) can act as a USB midi _device_. this means it can be controlled by a USB midi _host_ (such as a computer running abeton, or a raspberry pi). this section includes additional circuitry to allow the uC to also act as a USB midi __HOST__. this means it can be controlled by a USB midi _device_ such as a korg nanokontroller (or many other external usb-midi controllers/ gear). _obmit this section if you are not interested in controlling from a usb-midi device_

# section summary

## video-mixer controlling options:

- control rs232-mixer with usb-midi from host : A + B
- control rs232-mixer with serial-midi : A + B + C
- control rs232-mixer with usb-midi from device : A + B + D

## some bonus converting options:

- convert usb-midi controller to serial midi : A + C + D
- convert rs232 commands to serial-midi : A + B + C
- use a ps3 controller to send serial-midi : A + C + D
