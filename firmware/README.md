this is where i will describe the default midi-mapping and explain how to write / customise it yourself,

also a detailed guide on how to download / flash the firmware...

...

# how to flash the firmware

coming soon...

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
