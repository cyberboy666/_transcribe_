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

## default flatmap

midi_channel | midi_command | midi_value | mixer_command | note
--- | --- | --- | --- | ---
 2 | note_on | 0 | MIX_MODE | - 
 2 | note_on | 1 | WIPE_SQUARE_CORNER_UL | - 
 2 | note_on | 2 | WIPE_SQUARE_CORNER_DL | - 
 2 | note_on | 3 | WIPE_SQUARE_CORNER_DR | - 
 2 | note_on | 4 | WIPE_SQUARE_CORNER_UR | - 
 2 | note_on | 5 | WIPE_BLIND_L | - 
 2 | note_on | 6 | WIPE_BLIND_D | - 
 2 | note_on | 7 | WIPE_BLIND_R | - 
 2 | note_on | 8 | WIPE_BLIND_U | - 
 2 | note_on | 9 | WIPE_TRIANGLE_CORNER_UL | - 
 2 | note_on | 10 | WIPE_TRIANGLE_CORNER_DL | - 
 2 | note_on | 11 | WIPE_TRIANGLE_CORNER_DR | - 
 2 | note_on | 12 | WIPE_TRIANGLE_CORNER_UR | - 
 2 | note_on | 13 | WIPE_TRIANGLE_L | - 
 2 | note_on | 14 | WIPE_TRIANGLE_D | - 
 2 | note_on | 15 | WIPE_TRIANGLE_R | - 
 2 | note_on | 16 | WIPE_TRIANGLE_U | - 
 2 | note_on | 17 | WIPE_SQUARE | - 
 2 | note_on | 18 | WIPE_CIRCLE | - 
 2 | note_on | 19 | WIPE_OVALE | - 
 2 | note_on | 20 | WIPE_LOSANGE | - 
 2 | note_on | 21 | WIPE_I | - 
 2 | note_on | 22 | WIPE_MINUS | - 
 2 | note_on | 23 | WIPE_PLUS | - 
 2 | note_on | 24 | WIPE_SPECIAL_24 | - 
 2 | note_on | 25 | WIPE_SPECIAL_25 | - 
 2 | note_on | 26 | WIPE_SPECIAL_26 | - 
 2 | note_on | 27 | WIPE_SPECIAL_27 | - 
 2 | note_on | 28 | WIPE_SPECIAL_28 | - 
 2 | note_on | 29 | WIPE_SPECIAL_29 | - 
 2 | note_on | 30 | WIPE_SPECIAL_30 | - 
 2 | note_on | 31 | WIPE_SPECIAL_31 | - 
 2 | note_on | 32 | WIPE_SPECIAL_32 | - 
 2 | note_on | 33 | WIPE_SPECIAL_33 | - 
 2 | note_on | 34 | WIPE_SPECIAL_34 | - 
 2 | note_on | 35 | WIPE_SPECIAL_35 | - 
 2 | note_on | 36 | WIPE_SPECIAL_36 | - 
 2 | note_on | 37 | WIPE_SPECIAL_37 | - 
 2 | note_on | 38 | DIRECTION_ONE_WAY | - 
 2 | note_on | 39 | DIRECTION_REVERSE | - 
 2 | note_on | 40 | EDGE_NONE | - 
 2 | note_on | 41 | EDGE_BORDER | - 
 2 | note_on | 42 | EDGE_SOFT | - 
 2 | note_on | 43 | MULTI_BASIC | - 
 2 | note_on | 44 | MULTI_1 | - 
 2 | note_on | 45 | MULTI_2 | - 
 2 | note_on | 46 | MULTI_3 | - 
 2 | note_on | 47 | MODE_NORMAL | - 
 2 | note_on | 48 | MODE_COMPRESSION | - 
 2 | note_on | 49 | MODE_SLIDE | - 
 2 | note_on | 50 | MODE_PAIR | - 
 2 | note_on | 51 | MODE_SLIDE_COMPRESSION | - 
 2 | note_on | 52 | OPERATION_OVER | - 
 2 | note_on | 53 | OPERATION_REMOVE | - 
 2 | note_on | 54 | OPERATION_FLIP | - 
 2 | note_on | 55 | OPERATION_PUSH | - 
 2 | note_on | 56 | SPEDGE_NONE | - 
 2 | note_on | 57 | SPEDGE_BORDER | - 
 2 | note_on | 58 | SPEDGE_SOFT | - 
 2 | note_on | 59 | A_BUS_STROBO_OFF | - 
 2 | note_on | 60 | A_BUS_STROBO_STEP_1 | - 
 2 | note_on | 61 | A_BUS_STROBO_STEP_2 | - 
 2 | note_on | 62 | A_BUS_STROBO_STEP_3 | - 
 2 | note_on | 63 | A_BUS_STROBO_STEP_4 | - 
 2 | note_on | 64 | A_BUS_STROBO_STEP_5 | - 
 2 | note_on | 65 | A_BUS_MOSAIC_OFF | - 
 2 | note_on | 66 | A_BUS_MOSAIC_STEP_1 | - 
 2 | note_on | 67 | A_BUS_MOSAIC_STEP_2 | - 
 2 | note_on | 68 | A_BUS_MOSAIC_STEP_3 | - 
 2 | note_on | 69 | A_BUS_MOSAIC_STEP_4 | - 
 2 | note_on | 70 | A_BUS_MOSAIC_STEP_5 | - 
 2 | note_on | 71 | A_BUS_PAINT_OFF | - 
 2 | note_on | 72 | A_BUS_PAINT_STEP_1 | - 
 2 | note_on | 73 | A_BUS_PAINT_STEP_2 | - 
 2 | note_on | 74 | A_BUS_PAINT_STEP_3 | - 
 2 | note_on | 75 | A_BUS_PAINT_STEP_4 | - 
 2 | note_on | 76 | A_BUS_NEGATIVE_OFF | - 
 2 | note_on | 77 | A_BUS_NEGATIVE_ON | - 
 2 | note_on | 78 | A_BUS_FIELD_STILL_MODE | - 
 2 | note_on | 79 | A_BUS_FRAME_STILL_MODE | - 
 2 | note_on | 80 | A_BUS_COLOR_CORRECTOR_OFF | - 
 2 | note_on | 81 | A_BUS_COLOR_CORRECTOR_ON | - 
 2 | note_on | 82 | B_BUS_STROBO_OFF | - 
 2 | note_on | 83 | B_BUS_STROBO_STEP_1 | - 
 2 | note_on | 84 | B_BUS_STROBO_STEP_2 | - 
 2 | note_on | 85 | B_BUS_STROBO_STEP_3 | - 
 2 | note_on | 86 | B_BUS_STROBO_STEP_4 | - 
 2 | note_on | 87 | B_BUS_STROBO_STEP_5 | - 
 2 | note_on | 88 | B_BUS_MOSAIC_OFF | - 
 2 | note_on | 89 | B_BUS_MOSAIC_STEP_1 | - 
 2 | note_on | 90 | B_BUS_MOSAIC_STEP_2 | - 
 2 | note_on | 91 | B_BUS_MOSAIC_STEP_3 | - 
 2 | note_on | 92 | B_BUS_MOSAIC_STEP_4 | - 
 2 | note_on | 93 | B_BUS_MOSAIC_STEP_5 | - 
 2 | note_on | 94 | B_BUS_PAINT_OFF | - 
 2 | note_on | 95 | B_BUS_PAINT_STEP_1 | - 
 2 | note_on | 96 | B_BUS_PAINT_STEP_2 | - 
 2 | note_on | 97 | B_BUS_PAINT_STEP_3 | - 
 2 | note_on | 98 | B_BUS_PAINT_STEP_4 | - 
 2 | note_on | 99 | B_BUS_NEGATIVE_OFF | - 
 2 | note_on | 100 | B_BUS_NEGATIVE_ON | - 
 2 | note_on | 101 | B_BUS_FIELD_STILL_MODE | - 
 2 | note_on | 102 | B_BUS_FRAME_STILL_MODE | - 
 2 | note_on | 103 | B_BUS_COLOR_CORRECTOR_OFF | - 
 2 | note_on | 104 | B_BUS_COLOR_CORRECTOR_ON | - 
 2 | note_on | 105 | AUDIO_MIX_LEVEL_GLOBAL_FOLLOW_ON | - 
 2 | note_on | 106 | AUDIO_MIX_LEVEL_GLOBAL_FOLLOW_OFF | - 
 2 | note_on | 107 | AUDIO_MIX_LEVEL_SOURCE_4_FOLLOW_ON | - 
 2 | note_on | 108 | AUDIO_MIX_LEVEL_SOURCE_4_FOLLOW_OFF | - 
 2 | note_on | 109 | VIDEO_FADE_ON | - 
 2 | note_on | 110 | VIDEO_FADE_OFF | - 
 2 | note_on | 111 | AUDIO_FADE_ON | - 
 2 | note_on | 112 | AUDIO_FADE_OFF | - 
 2 | note_on | 113 | TITTLE_FADE_ON | - 
 2 | note_on | 114 | TITTLE_FADE_OFF | - 
 2 | note_on | 115 | FADE_TO_WHITE | - 
 2 | note_on | 116 | FADE_TO_BLACK | - 
 2 | note_on | 117 | FADE_TO_COLOR | - 
 2 | note_on | 118 | BACK_COLOR_WHITE | - 
 2 | note_on | 119 | BACK_COLOR_YELLOW | - 
 2 | note_on | 120 | BACK_COLOR_CYAN | - 
 2 | note_on | 121 | BACK_COLOR_GREEN | - 
 2 | note_on | 122 | BACK_COLOR_MAGENTA | - 
 2 | note_on | 123 | BACK_COLOR_RED | - 
 2 | note_on | 124 | BACK_COLOR_BLUE | - 
 2 | note_on | 125 | BACK_COLOR_BLACK | - 
 2 | note_on | 126 | BACK_COLOR_USER_COLOR | - 
 2 | note_on | 127 | EDGE_COLOR_WHITE | - 
 3 | note_on | 0 | EDGE_COLOR_YELLOW | - 
3 | note_on | 1 | EDGE_COLOR_CYAN | - 
3 | note_on | 2 | EDGE_COLOR_GREEN | - 
3 | note_on | 3 | EDGE_COLOR_MAGENTA | - 
3 | note_on | 4 | EDGE_COLOR_RED | - 
3 | note_on | 5 | EDGE_COLOR_BLUE | - 
3 | note_on | 6 | EDGE_COLOR_BLACK | - 
3 | note_on | 7 | EDGE_COLOR_USER_COLOR | - 
3 | note_on | 8 | COLOR_MODE_NORMAL | - 
3 | note_on | 9 | COLOR_MODE_VERTICAL | - 
3 | note_on | 10 | COLOR_MODE_HORIZONTAL | - 
3 | note_on | 11 | COLOR_MODE_LINES | - 
3 | note_on | 12 | COLOR_MODE_PALETTE | - 
3 | note_on | 13 | TITLE_COLOR_INTERNAL_BACK_COLOR | - 
3 | note_on | 14 | TITLE_COLOR_EXTERNAL | - 
3 | note_on | 15 | TITLE_EDGE_PATTERN_0_OFF | - 
3 | note_on | 16 | TITLE_EDGE_PATTERN_1 | - 
3 | note_on | 17 | TITLE_EDGE_PATTERN_2 | - 
3 | note_on | 18 | TITLE_EDGE_PATTERN_3 | - 
3 | note_on | 19 | TITLE_EDGE_PATTERN_4 | - 
3 | note_on | 20 | TITLE_EDGE_PATTERN_5 | - 
3 | note_on | 21 | A_BUS_EFFECT_ON | - 
3 | note_on | 22 | A_BUS_EFFECT_OFF | - 
3 | note_on | 23 | B_BUS_EFFECT_ON | - 
3 | note_on | 24 | B_BUS_EFFECT_OFF | - 
3 | note_on | 25 | A_BUS_STILL_ON | - 
3 | note_on | 26 | A_BUS_STILL_OFF | - 
3 | note_on | 27 | B_BUS_STILL_ON | - 
3 | note_on | 28 | B_BUS_STILL_OFF | - 
3 | note_on | 29 | FADE_BUTTON | - 
3 | note_on | 30 | TAKE_BUTTON | - 
3 | note_on | 31 | BACK_COLOR_COLOR_BARS | - 
3 | note_on | 32 | BACK_COLOR_NOT_COLOR_BARS | - 
3 | note_on | 33 | RESET_TO_FACTORY_SETTINGS | - 
3 | note_on | 34 | A_BUS_SOURCE_1 | - 
3 | note_on | 35 | A_BUS_SOURCE_2 | - 
3 | note_on | 36 | A_BUS_SOURCE_3 | - 
3 | note_on | 37 | A_BUS_SOURCE_4 | - 
3 | note_on | 38 | A_BUS_BACK_COLOR | - 
3 | note_on | 39 | B_BUS_SOURCE_1 | - 
3 | note_on | 40 | B_BUS_SOURCE_2 | - 
3 | note_on | 41 | B_BUS_SOURCE_3 | - 
3 | note_on | 42 | B_BUS_SOURCE_4 | - 
3 | note_on | 43 | B_BUS_BACK_COLOR | - 
3 | note_on | 44 | WIPE_MIX_BUTTON | - 
3 | note_on | 45 | LUM_KEY | - 
3 | note_on | 46 | CHROMA_KEY | - 
3 | note_on | 47 | UNDO | - 
3 | note_on | 48 | ENTER | - 
2 | cc | 0 | A_BUS_CHROMA_LEVEL | -
2 | cc | 1 | B_BUS_CHROMA_LEVEL | -
2 | cc | 2 | AUDIO_LEVEL_SOURCE_1 | -
2 | cc | 3 | AUDIO_LEVEL_SOURCE_2 | -
2 | cc | 4 | AUDIO_LEVEL_SOURCE_3 | -
2 | cc | 5 | AUDIO_LEVEL_SOURCE_4 | -
2 | cc | 6 | A_B_MIX_LEVEL | -
2 | cc | 7 | SPEED_SET | -
2 | cc | 8 | THRESHOLD_LUM_KEY | -
2 | cc | 9 | BACK_COLOR_MANUAL_X | -
2 | cc | 10 | BACK_COLOR_MANUAL_Y | -
2 | cc | 11 | EDGE_COLOR_MANUAL_X | -
2 | cc | 12 | EDGE_COLOR_MANUAL_Y | -
2 | cc | 13 | COLOR_CORECT_X | -
2 | cc | 14 | COLOR_CORECT_Y | -
2 | cc | 15 | CENTER_WIPE_X | -
2 | cc | 16 | CENTER_WIPE_Y | -
2 | cc | 17 | SCENE_GRABER_X | -
2 | cc | 18 | SCENE_GRABER_Y | -
2 | cc | 19 | CHROMA_SET_X | -
2 | cc | 20 | CHROMA_SET_Y | -
2 | cc | 21 | CHROMA_SET_Z | -
