this is where i will describe the default midi-mapping and explain how to write / customise it yourself,

also a detailed guide on how to download / flash the firmware...

...

# how to flash the firmware

- clone/download this git repo

## easiest way (gui)

- install [visual studio code](https://code.visualstudio.com/download)
- within vscode go to _extensions_ , search and install __platformio__
- in vscode open the folder `/_transcribe_/firmware`
- attach the pro-micro to computer via usb and press `upload` on platformio toolbar at bottom of screen

## cmdline way (if you dont want to install vscode)

- install [platformio-core](https://docs.platformio.org/en/latest/core/installation.html)
- `cd <location to repo>/_transcribe_/firmware`
- `pio run -t upload`

![image](https://user-images.githubusercontent.com/12017938/97863854-f6f28e80-1d07-11eb-9040-006e1a201af5.png)

# setting the midi map

the code that sets the midi map is [here](https://github.com/langolierz/_transcribe_/blob/master/firmware/src/main.cpp#L48-L89)

for example look at this line:

```
else if(midiParam1 == 64){setCmd(A55_A_BUS_SOURCE_1);}
```
this is saying if the _midiParam1_ (cc channel) is 1 then send the command __A55_A_BUS_SOURCE_1__ -> which we can see is defined [here](https://github.com/langolierz/_transcribe_/blob/master/firmware/src/commands.h#L182) to be "VCP:200"


# default midi mappings

_transcribe_ has two seperate ways of mapping midi commands to panasonic-mixer commands.

### custom map

the __custom map__ is a mapping of midi notes and cc values to specific panasonic mixer commands. it only maps the commands that seem useful and does it in layout that makes sense for the controller being used. this mapping is useful for controlling with a fixed external midi controller - the _default custom map_ will be my personal setup using a korg nanokontroller, but this is just an example that should edit to fit your controller and layout. this map allows for using _special mappings_ that can map multiple functions to a single slider or include oscilaotors / randomness aswell. this map uses ch1.

## default custom map

midi_channel | midi_command | midi_value | mixer_command | note
--- | --- | --- | --- | ---
1 | cc | 0 | A_B_MIX_LEVEL | -
1 | cc | 1 | CENTER_WIPE_X | -
1 | cc | 2 | CENTER_WIPE_Y | -
