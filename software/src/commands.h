
// commands for panasonic ave55:
// command format:
// replace  "~0" with 2digit hex param value between 0-256 based on midi cc input value
// replace "~x" with 2digit hex param value between 0-256 based on midi cc input value AND save this value to the paramstore at index 'x'
// replace "*x" with 2digit hex param value between 0-256 from the parastore at index 'x'

#define A55_MIX_MODE "VMX:000"
#define A55_WIPE_SQUARE_CORNER_UL "VWP:001"
#define A55_WIPE_SQUARE_CORNER_DL "VWP:002"
#define A55_WIPE_SQUARE_CORNER_DR "VWP:003"
#define A55_WIPE_SQUARE_CORNER_UR "VWP:004"
#define A55_WIPE_BLIND_L "VWP:005"
#define A55_WIPE_BLIND_D "VWP:006"
#define A55_WIPE_BLIND_R "VWP:007"
#define A55_WIPE_BLIND_U "VWP:008"
#define A55_WIPE_TRIANGLE_CORNER_UL "VWP:009"
#define A55_WIPE_TRIANGLE_CORNER_DL "VWP:010"
#define A55_WIPE_TRIANGLE_CORNER_DR "VWP:011"
#define A55_WIPE_TRIANGLE_CORNER_UR "VWP:012"
#define A55_WIPE_TRIANGLE_L "VWP:013"
#define A55_WIPE_TRIANGLE_D "VWP:014"
#define A55_WIPE_TRIANGLE_R "VWP:015"
#define A55_WIPE_TRIANGLE_U "VWP:016"
#define A55_WIPE_SQUARE "VWP:017"
#define A55_WIPE_CIRCLE "VWP:018"
#define A55_WIPE_OVALE "VWP:019"
#define A55_WIPE_LOSANGE "VWP:020"
#define A55_WIPE_I "VWP:021"
#define A55_WIPE_MINUS "VWP:022"
#define A55_WIPE_PLUS "VWP:023"
#define A55_WIPE_SPECIAL_24 "VWP:024"
#define A55_WIPE_SPECIAL_25 "VWP:025"
#define A55_WIPE_SPECIAL_26 "VWP:026"
#define A55_WIPE_SPECIAL_27 "VWP:027"
#define A55_WIPE_SPECIAL_28 "VWP:028"
#define A55_WIPE_SPECIAL_29 "VWP:029"
#define A55_WIPE_SPECIAL_30 "VWP:030"
#define A55_WIPE_SPECIAL_31 "VWP:031"
#define A55_WIPE_SPECIAL_32 "VWP:032"
#define A55_WIPE_SPECIAL_33 "VWP:033"
#define A55_WIPE_SPECIAL_34 "VWP:034"
#define A55_WIPE_SPECIAL_35 "VWP:035"
#define A55_WIPE_SPECIAL_36 "VWP:036"
#define A55_WIPE_SPECIAL_37 "VWP:037"
#define A55_DIRECTION_ONE_WAY "VWD:040"
#define A55_DIRECTION_REVERSE "VWD:041"
#define A55_EDGE_NONE "VWB:042"
#define A55_EDGE_BORDER "VWB:043"
#define A55_EDGE_SOFT "VWB:044"
#define A55_MULTI_BASIC "VWM:045"
#define A55_MULTI_1 "VWM:046"
#define A55_MULTI_2 "VWM:047"
#define A55_MULTI_3 "VWM:048"
#define A55_MODE_NORMAL "VWM:049"
#define A55_MODE_COMPRESSION "VWM:050"
#define A55_MODE_SLIDE "VWM:051"
#define A55_MODE_PAIR "VWM:052"
#define A55_MODE_SLIDE_COMPRESSION "VW:053"
#define A55_OPERATION_OVER "VW:054"
#define A55_OPERATION_REMOVE "VW:055"
#define A55_OPERATION_FLIP "VW:056"
#define A55_OPERATION_PUSH "VW:057"
#define A55_SPEDGE_NONE "VWB:061"
#define A55_SPEDGE_BORDER "VWB:062"
#define A55_SPEDGE_SOFT "VWB:063"
#define A55_A_BUS_STROBO_OFF "VDE:070"
#define A55_A_BUS_STROBO_STEP_1 "VDE:071"
#define A55_A_BUS_STROBO_STEP_2 "VDE:072"
#define A55_A_BUS_STROBO_STEP_3 "VDE:073"
#define A55_A_BUS_STROBO_STEP_4 "VDE:074"
#define A55_A_BUS_STROBO_STEP_5 "VDE:075"
#define A55_A_BUS_MOSAIC_OFF "VDE:076"
#define A55_A_BUS_MOSAIC_STEP_1 "VDE:077"
#define A55_A_BUS_MOSAIC_STEP_2 "VDE:078"
#define A55_A_BUS_MOSAIC_STEP_3 "VDE:079"
#define A55_A_BUS_MOSAIC_STEP_4 "VDE:080"
#define A55_A_BUS_MOSAIC_STEP_5 "VDE:081"
#define A55_A_BUS_PAINT_OFF "VDE:082"
#define A55_A_BUS_PAINT_STEP_1 "VDE:083"
#define A55_A_BUS_PAINT_STEP_2 "VDE:084"
#define A55_A_BUS_PAINT_STEP_3 "VDE:085"
#define A55_A_BUS_PAINT_STEP_4 "VDE:086"
#define A55_A_BUS_NEGATIVE_OFF "VDE:087"
#define A55_A_BUS_NEGATIVE_ON "VDE:088"
#define A55_A_BUS_FIELD_STILL_MODE "VDE:089"
#define A55_A_BUS_FRAME_STILL_MODE "VDE:090"
#define A55_A_BUS_COLOR_CORRECTOR_OFF "VDE:091"
#define A55_A_BUS_COLOR_CORRECTOR_ON "VDE:092"
#define A55_A_BUS_CHROMA_LEVEL "VDE:093~0"
#define A55_B_BUS_STROBO_OFF "VDE:094"
#define A55_B_BUS_STROBO_STEP_1 "VDE:095"
#define A55_B_BUS_STROBO_STEP_2 "VDE:096"
#define A55_B_BUS_STROBO_STEP_3 "VDE:097"
#define A55_B_BUS_STROBO_STEP_4 "VDE:098"
#define A55_B_BUS_STROBO_STEP_5 "VDE:099"
#define A55_B_BUS_MOSAIC_OFF "VDE:100"
#define A55_B_BUS_MOSAIC_STEP_1 "VDE:101"
#define A55_B_BUS_MOSAIC_STEP_2 "VDE:102"
#define A55_B_BUS_MOSAIC_STEP_3 "VDE:103"
#define A55_B_BUS_MOSAIC_STEP_4 "VDE:104"
#define A55_B_BUS_MOSAIC_STEP_5 "VDE:105"
#define A55_B_BUS_PAINT_OFF "VDE:106"
#define A55_B_BUS_PAINT_STEP_1 "VDE:107"
#define A55_B_BUS_PAINT_STEP_2 "VDE:108"
#define A55_B_BUS_PAINT_STEP_3 "VDE:109"
#define A55_B_BUS_PAINT_STEP_4 "VDE:110"
#define A55_B_BUS_NEGATIVE_OFF "VDE:111"
#define A55_B_BUS_NEGATIVE_ON "VDE:112"
#define A55_B_BUS_FIELD_STILL_MODE "VDE:113"
#define A55_B_BUS_FRAME_STILL_MODE "VDE:114"
#define A55_B_BUS_COLOR_CORRECTOR_OFF "VDE:115"
#define A55_B_BUS_COLOR_CORRECTOR_ON "VDE:116"
#define A55_B_BUS_CHROMA_LEVEL "VDE:117"
#define A55_AUDIO_MIX_LEVEL_GLOBAL_FOLLOW_ON "AML:120"
#define A55_AUDIO_MIX_LEVEL_GLOBAL_FOLLOW_OFF "AML:121"
#define A55_AUDIO_LEVEL_SOURCE_1 "ALV:122"
#define A55_AUDIO_LEVEL_SOURCE_2 "ALV:123"
#define A55_AUDIO_LEVEL_SOURCE_3 "ALV:124"
#define A55_AUDIO_LEVEL_SOURCE_4 "ALV:125"
#define A55_AUDIO_MIX_LEVEL_SOURCE_4_FOLLOW_ON "AML:126"
#define A55_AUDIO_MIX_LEVEL_SOURCE_4_FOLLOW_OFF "AML:127"
#define A55_VIDEO_FADE_ON "VFD:130"
#define A55_VIDEO_FADE_OFF "VFD:131"
#define A55_AUDIO_FADE_ON "VFD:132"
#define A55_AUDIO_FADE_OFF "VFD:133"
#define A55_TITTLE_FADE_ON "VFD:134"
#define A55_TITTLE_FADE_OFF "VFD:135"
#define A55_FADE_TO_WHITE "VFD:136"
#define A55_FADE_TO_BLACK "VFD:137"
#define A55_FADE_TO_COLOR "VFD:138"
#define A55_BACK_COLOR_WHITE "VBC:140"
#define A55_BACK_COLOR_YELLOW "VBC:141"
#define A55_BACK_COLOR_CYAN "VBC:142"
#define A55_BACK_COLOR_GREEN "VBC:143"
#define A55_BACK_COLOR_MAGENTA "VBC:144"
#define A55_BACK_COLOR_RED "VBC:145"
#define A55_BACK_COLOR_BLUE "VBC:146"
#define A55_BACK_COLOR_BLACK "VBC:147"
#define A55_BACK_COLOR_USER_COLOR "VBC:148"
#define A55_EDGE_COLOR_WHITE "VEC:150"
#define A55_EDGE_COLOR_YELLOW "VEC:151"
#define A55_EDGE_COLOR_CYAN "VEC:152"
#define A55_EDGE_COLOR_GREEN "VEC:153"
#define A55_EDGE_COLOR_MAGENTA "VEC:154"
#define A55_EDGE_COLOR_RED "VEC:155"
#define A55_EDGE_COLOR_BLUE "VEC:156"
#define A55_EDGE_COLOR_BLACK "VEC:157"
#define A55_EDGE_COLOR_USER_COLOR "VEC:158"
#define A55_COLOR_MODE_NORMAL "VBG:160"
#define A55_COLOR_MODE_VERTICAL "VBG:161"
#define A55_COLOR_MODE_HORIZONTAL "VBG:162"
#define A55_COLOR_MODE_LINES "VBG:163"
#define A55_COLOR_MODE_PALETTE "VBG:164"
#define A55_TITLE_COLOR_INTERNAL_BACK_COLOR "VTC:165"
#define A55_TITLE_COLOR_EXTERNAL "VTC:166"
#define A55_TITLE_EDGE_PATTERN_0_OFF "VTE:167"
#define A55_TITLE_EDGE_PATTERN_1 "VTE:168"
#define A55_TITLE_EDGE_PATTERN_2 "VTE:169"
#define A55_TITLE_EDGE_PATTERN_3 "VTE:170"
#define A55_TITLE_EDGE_PATTERN_4 "VTE:171"
#define A55_TITLE_EDGE_PATTERN_5 "VTE:172"
#define A55_BACK_COLOR_MANUAL_X "VB:174~b*a"
#define A55_BACK_COLOR_MANUAL_Y "VB:174*b~a"
#define A55_EDGE_COLOR_MANUAL_X "VE:175~d*c"
#define A55_EDGE_COLOR_MANUAL_Y "VE:175*d~c"
#define A55_A_B_MIX_LEVEL "VMM:179~0"
#define A55_A_BUS_EFFECT_ON "VDE:180"
#define A55_A_BUS_EFFECT_OFF "VDE:181"
#define A55_B_BUS_EFFECT_ON "VDE:182"
#define A55_B_BUS_EFFECT_OFF "VDE:183"
#define A55_A_BUS_STILL_ON "VDE:184"
#define A55_A_BUS_STILL_OFF "VDE:185"
#define A55_B_BUS_STILL_ON "VDE:186"
#define A55_B_BUS_STILL_OFF "VDE:187"
#define A55_SPEED_SET "VAS:190~0"
#define A55_FADE_BUTTON "VF:191"
#define A55_TAKE_BUTTON "VMA:192"
#define A55_BACK_COLOR_COLOR_BARS "VBC:197"
#define A55_BACK_COLOR_NOT_COLOR_BARS "VBC:198"
#define A55_RESET_TO_FACTORY_SETTINGS "ZRS:199"
#define A55_A_BUS_SOURCE_1 "VCP:200"
#define A55_A_BUS_SOURCE_2 "VCP:201"
#define A55_A_BUS_SOURCE_3 "VCP:202"
#define A55_A_BUS_SOURCE_4 "VCP:203"
#define A55_A_BUS_BACK_COLOR "VCP:204"
#define A55_B_BUS_SOURCE_1 "VCP:205"
#define A55_B_BUS_SOURCE_2 "VCP:206"
#define A55_B_BUS_SOURCE_3 "VCP:207"
#define A55_B_BUS_SOURCE_4 "VCP:208"
#define A55_B_BUS_BACK_COLOR "VCP:209"
#define A55_WIPE_MIX_BUTTON "VMX:210"
#define A55_THRESHOLD_LUM_KEY "VMX:211~0"
#define A55_LUM_KEY "VMX:212"
#define A55_CHROMA_KEY "VMX:213"
#define A55_CHROMA_SET_X "VCS:214~e*f*g"
#define A55_CHROMA_SET_Y "VCS:214*e~f*g"
#define A55_CHROMA_SET_Z "VCS:214*e*f~g"
#define A55_UNDO "ZUD:215"
#define A55_ENTER "ZEN:216"
#define A55_COLOR_CORECT_X "VPS:217~l*m"
#define A55_COLOR_CORECT_Y "VPS:217*l~m"
#define A55_CENTER_WIPE_X "VPS:218~h*i"
#define A55_CENTER_WIPE_Y "VPS:218*h~i"
#define A55_SCENE_GRABER_X "VPS:219~j*k"
#define A55_SCENE_GRABER_Y "VPS:219*j~k"


// commands (wip) for panasonic mx30/50/70:

#define MX50_A_B_MIX_LEVEL "VMM:~0"

#define MX50_A_BUS_MOSAIC_OFF "VDE:AMSOF"
#define MX50_A_BUS_MOSAIC_STEP "VDE:AMS~0"


/*

1 VBC Back Color Select // param: VBC:a1a2b1b2
2 VBG Setting the gradation of Back Color // param: VBG:a[b1b2][c1c2]
3 VBM Setting for the coloring and color strength/tone of Back Color (Custom1) // param: VBM:a1a2b1b2c1c2
4 VBW Setting for the coloring and color strength/tone of Wash Color (Custom1) // param: VBW:a1a2b1b2c1c2
5 VCC Setting for the coloring of the selected source // param: VCC:ab1b2c1c2
6 VCG Setting for the color strength/tone of the selected source // param: VCG:ab1b2
7 VCY Setting for the coloring brightness of the selected source // param: VCY:ab1b2c1c2
8 VDE Setting for the digital effect of the selected source // param: VDE:ab1b2[c1[c2]][d1[d2]][e1[e2]]
9 VDM Setting for the multi strobe(=digital effect) of the selected source // param: VDM:abcd1d2
10 VCP Select the source for A bus, B bus // param: VCP:ab[c1c2][d]
11 VFD Mode Selection of Fade // param: VFD:abcd
12 VFA Execute the setting of Auto Fade Duration // param: VFA:a1a2a3
13 VFM Fade Level Setting // param: VFM:a1a2
14 VWP Wipe Pattern Setting // param: VWP:a1a2b1b2c
15 VWN Wipe Number Direct Setting // param: VWN:a1a2a3a4
16 VWD Wipe Direction Select // param: VWD:ab
17 VWB Wipe Edge Select // param: VWB:a1a2b1b2c1c2
18 VWS Aspect Ratio Setting for Square Wipe Pattern // param: VWS:ab1b2
19 VWX Transition Effect Setting // param: VWX:abcd1d2
20 VML Setting for Audio Link of MIX, WIPE // param: VML:a
21 VMA Execute Auto Take Speed Setting // param: VMA:a1a2a3
22 VMM Setting for WIPE/MIX Joy Stick Position Data // param: VMM:a1a2
23 VMP Setting for WIPE/MIX Joy Stick and Positional Data // param: VMP:a1a2b1b2c1c2d1d2d3
24 VMW Memory Read of Video for Program Output // param: VMW:a1a2b1b2
25 VPS Setting for Hold ON/OFF and position data of positioner // param: VPS:ab1b2c1c2d1d2d3
26 VPC Center ON/OFF Setting for positioner // param: VPC:a
27 VSB ON/OFF Setting for Scene Grab // param: VSB:a
28 VSD Key Level Setting for DSK // param: VSD:a1a2b1b2
29 VAS Setting for Execute of Auto Take, Auto Fade and Program Memory // param: VAS
30 VPG Execute and Register for 99 Event Memory  // param: VPG:ab1b2
31 VEA ON/OFF Setting for Video Effect // param: VEE:ab1b2c
32 VKS Slice and Slope Setting for KEY // param: VKS:a1a2b
33 VKL KEY Level Setting // param: VKL:a1a2
34 VKC KEY Crop Setting  // param: VKC:a1a2a3b1b2b3c1c2c3c4d1d2d3d4
35 VKX KEY Effect Setting // param: VKX:abcd1d2
36 VKR RGB Setting for Chroma Key // param: VKR:a1a2b1b2c1c2d
37 VDR Setting for Write and Preview to DSK // param: VDR:abc1c2de
38 VDI DSK ON/OFF Setting // param: VDI:abcd1d2
39 VDK DSK Execute // param: VDK
40 VDX DSK Effect Setting // param: VDX:abcd1d2
41 VDA DSK Effect ON/OFF Setting // param: VDA:a
42 VDS Slice and Slope setting for DSK // param: VDS:a1a2b
43 VDL DSK Key Level Setting // param: VDL:a1a2
44 AFD Fade Level Setting for Audio // param: AFD:ab1b2
45 AEA ON/OFF Setting for Audio Effect // param: AEA:a
46 VSL Video Input Select // param: VSL:ab1b2c
47 ASL Audio Input Select // param: ASL:ab1b2c
48 ZLP Setting for Screen Save of LCD Panel // param: ZLP:a
49 QLE Status Check of Current Joy Stick Position  // param: QLE
50 QAM Status Check of Current Audio Meter Data  // param: QAM
51 QCL Status Check of Current Chroma Key Color Data  // param: QCL
52 QPO Status Check of Current Position Data // param: QPO
53 VHC Color Cancel Setting for Chroma Key // param: VHC:a

*/

#define EXTRON_MAV_1x1 "1*1!"
#define EXTRON_MAV_2x1 "2*1!"
#define EXTRON_MAV_3x1 "3*1!"
#define EXTRON_MAV_4x1 "4*1!"
#define EXTRON_MAV_5x1 "5*1!"
#define EXTRON_MAV_6x1 "6*1!"
#define EXTRON_MAV_7x1 "7*1!"
#define EXTRON_MAV_8x1 "8*1!"

#define EXTRON_MAV_1x2 "1*2!"
#define EXTRON_MAV_2x2 "2*2!"
#define EXTRON_MAV_3x2 "3*2!"
#define EXTRON_MAV_4x2 "4*2!"
#define EXTRON_MAV_5x2 "5*2!"
#define EXTRON_MAV_6x2 "6*2!"
#define EXTRON_MAV_7x2 "7*2!"
#define EXTRON_MAV_8x2 "8*2!"

#define EXTRON_MAV_1x3 "1*3!"
#define EXTRON_MAV_2x3 "2*3!"
#define EXTRON_MAV_3x3 "3*3!"
#define EXTRON_MAV_4x3 "4*3!"
#define EXTRON_MAV_5x3 "5*3!"
#define EXTRON_MAV_6x3 "6*3!"
#define EXTRON_MAV_7x3 "7*3!"
#define EXTRON_MAV_8x3 "8*3!"

#define EXTRON_MAV_1x4 "1*4!"
#define EXTRON_MAV_2x4 "2*4!"
#define EXTRON_MAV_3x4 "3*4!"
#define EXTRON_MAV_4x4 "4*4!"
#define EXTRON_MAV_5x4 "5*4!"
#define EXTRON_MAV_6x4 "6*4!"
#define EXTRON_MAV_7x4 "7*4!"
#define EXTRON_MAV_8x4 "8*4!"

#define EXTRON_MAV_1x5 "1*5!"
#define EXTRON_MAV_2x5 "2*5!"
#define EXTRON_MAV_3x5 "3*5!"
#define EXTRON_MAV_4x5 "4*5!"
#define EXTRON_MAV_5x5 "5*5!"
#define EXTRON_MAV_6x5 "6*5!"
#define EXTRON_MAV_7x5 "7*5!"
#define EXTRON_MAV_8x5 "8*5!"

#define EXTRON_MAV_1x6 "1*6!"
#define EXTRON_MAV_2x6 "2*6!"
#define EXTRON_MAV_3x6 "3*6!"
#define EXTRON_MAV_4x6 "4*6!"
#define EXTRON_MAV_5x6 "5*6!"
#define EXTRON_MAV_6x6 "6*6!"
#define EXTRON_MAV_7x6 "7*6!"
#define EXTRON_MAV_8x6 "8*6!"

#define EXTRON_MAV_1x7 "1*7!"
#define EXTRON_MAV_2x7 "2*7!"
#define EXTRON_MAV_3x7 "3*7!"
#define EXTRON_MAV_4x7 "4*7!"
#define EXTRON_MAV_5x7 "5*7!"
#define EXTRON_MAV_6x7 "6*7!"
#define EXTRON_MAV_7x7 "7*7!"
#define EXTRON_MAV_8x7 "8*7!"

#define EXTRON_MAV_1x8 "1*8!"
#define EXTRON_MAV_2x8 "2*8!"
#define EXTRON_MAV_3x8 "3*8!"
#define EXTRON_MAV_4x8 "4*8!"
#define EXTRON_MAV_5x8 "5*8!"
#define EXTRON_MAV_6x8 "6*8!"
#define EXTRON_MAV_7x8 "7*8!"
#define EXTRON_MAV_8x8 "8*8!"


#define KRAMER_VS402_1x1 "\x01\x81\x81\x81"
#define KRAMER_VS402_2x1 "\x01\x82\x81\x81"
#define KRAMER_VS402_3x1 "\x01\x83\x81\x81"
#define KRAMER_VS402_4x1 "\x01\x84\x81\x81"
#define KRAMER_VS402_1x2 "\x01\x81\x82\x81"
#define KRAMER_VS402_2x2 "\x01\x82\x82\x81"
#define KRAMER_VS402_3x2 "\x01\x83\x82\x81"
#define KRAMER_VS402_4x2 "\x01\x84\x82\x81"