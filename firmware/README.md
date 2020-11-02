this is where i will describe the default midi-mapping and explain how to write / customise it yourself,

also a detailed guide on how to download / flash the firmware...

...

# how to flash the firmware

coming soon...

# default midi mappings

_transcribe_ has two seperate ways of mapping midi commands to panasonic-mixer commands.

### custom map

the __custom map__ is a mapping of midi notes and cc values to specific panasonic mixer commands. it only maps the commands that seem useful and does it in layout that makes sense for the controller being used. this mapping is useful for controlling with a fixed external midi controller - the _default custom map_ will be my personal setup using a korg nanokontroller, but this is just an example that should edit to fit your controller and layout. this map allows for using _special mappings_ that can map multiple functions to a single slider or include oscilaotors / randomness aswell. this map uses ch1.

### default flatmap

the __default flatmap__ is a direct map of every command the mixer has mapped to a fixed midi value. commands that require one or more parameters are mapped to midi cc and commands that do not are mapped to midi note_on messages. there are more commands than can fit on a single midi channel so these are currently spread over two channels - ch2 and ch3. this mapping is useful for controlling with custom software or applications where you have a lot of control over the sending interface

## default custom map

midi_channel | midi_command | midi_value | mixer_command | note
--- | --- | --- | --- | ---
1 | cc | 0 | A_B_MIX_LEVEL | -
1 | cc | 1 | CENTER_WIPE_X | -
1 | cc | 2 | CENTER_WIPE_Y | -
