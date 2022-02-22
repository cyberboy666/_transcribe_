# WIP _transcribe_

for midi control of panasonic video mixers.

__disclaimer__ _this project is a work in progress. dont order any boards or expect things to be clear or make sense just yet. if you would like to help or test however pls email me : langolierz@gmail.com_

## background

some people in the video-art community are performing with old hardware video-mixers such as in the Pansonic_WJ_AVE and Pansonic_WJ_MX lines. some of these mixers have a RS232 serial for interfacing with them digitally. this is especially useful for live performace where sequencing can assist physical actions. there are some cool examples of software specifically written to interface with these mixers (such as [Freds excel app](https://a2m2.ch/fred/wj-ave55.htm) and  [Klifs MaxPatch](https://vimeo.com/161662975) ) , but many more programs and devices that are made to interface digitally using MIDI.

the aim of this project is to create a small utility module that can __\_transcribe\___ _MIDI_, a protocal used commonly in live/performance instruments to the specific _RS232 panasonic video-mixer spec_ , to better equipt these retired workstations for their new life of glamour on stage

## supported video-mixers:

- panasonic wj_ave55 wip
- (not yet) panasonic wj_mx20
- (not yet) panasonic wj_mx30
- (not yet) panasonic wj_mx50
- (not yet) panasonic wj_mx70
- more ? if you have another mixer or any old equipment with rs232 (or maybe rs422 - i dunno yet..) and a spec-sheet maybe we can add support for it ?

## hardware features

- input USB-midi from a USB-HOST such as a computer or rpi
- input serial-midi from older midi devices (din)
- input USB-midi for a USB-DEVICE such as a korg nanokontroller or otherwise
- output RS232-serial commands to control panasonic video-mixers
- all these interfaces are bi-directional and so can be modified with firmware to do other useful things (eg like a USB-DEVICE -> SERIAL converter)

## software features

- mapping of notes or cc presses to commands (BUTTON)
- mapping of cc values to continous controls, like a-b mix or key-amount (SLIDER)
- mapping of two cc channels to 2d continous controls like xy-position or colour-select (JOYSTICK)
- mapping of notes or cc presses to alternating commands (SWITCH)
- mapping of notes or cc presses to a rotating selection of consecutive commands (CYCLE)
- mapping of cc values to a partitioned selection of consecutive commands (STEP)

(extenable to more such as random, random-walks, ossilators etc ...?)
