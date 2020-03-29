#include <stdint.h>
#include <Arduino.h>

namespace AVE55{

// default flatmap
const uint8_t flat_notes_ch_two[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 61, 62, 63, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 120, 121, 126, 127, 130, 131, 132, 133, 134, 135, 136, 137, 138, 140, 141, 142, 143, 144, 145, 146, 147, 148, 150};
const uint8_t flat_notes_ch_three[128] = {151, 152, 153, 154, 155, 156, 157, 158, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 180, 181, 182, 183, 184, 185, 186, 187, 191, 192, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 212, 213, 215, 216};
const uint8_t flat_cc_ch_two[128] = {93, 117, 122, 123, 124, 125, 179, 190, 211, 174, 174, 175, 175, 217, 217, 218, 218, 219, 219, 214, 214, 214};

//oneInput controls:
//A_BUS_CHROMA_LEVEL:93, B_BUS_CHROMA_LEVEL:117, AUDIO_LEVEL_SOURCE_1:122, AUDIO_LEVEL_SOURCE_2:123, AUDIO_LEVEL_SOURCE_3:124, AUDIO_LEVEL_SOURCE_4:125, A_B_MIX_LEVEL:179, SPEED_SET:190, THRESHOLD_LUM_KEY:211
// const uint8_t oneParamControl[10] = {93, 117, 122, 123, 124, 125, 179, 190, 211};
//twoInput controls:
// 0=BACK_COLOR_MANUAL:174, 1=EDGE_COLOR_MANUAL:175, 2=COLOR_CORECT:217, 3=CENTER_WIPE:218, 4=SCENE_GRABER:219
// const uint8_t twoParamControl[5] = {174, 175, 217, 218, 219};
//threeInput controls:
// 0=CHROMA_SET:214
// const uint8_t threeParamControl[1] = {214};
bool is_one_input(uint8_t cmd){
    return cmd == 93 || cmd == 117 || cmd == 122 || cmd == 123 || cmd == 124 || cmd == 125 || cmd == 179 || cmd == 190 || cmd == 211;
}

bool is_two_input(uint8_t cmd){
    return cmd == 174 || cmd == 175 || cmd == 217 || cmd == 218 || cmd == 219;
}

bool is_three_input(uint8_t cmd){
    return cmd == 214;
}

const uint8_t MIX_MODE = 0; // VMX:000 - Mix mode /Out of WIPE 
const uint8_t WIPE_SQUARE_CORNER_UL = 1; // VWP:001 - Video Wipe Pattern 
const uint8_t WIPE_SQUARE_CORNER_DL = 2; // VWP:002 - Video Wipe Pattern 
const uint8_t WIPE_SQUARE_CORNER_DR = 3; // VWP:003 - Video Wipe Pattern 
const uint8_t WIPE_SQUARE_CORNER_UR = 4; // VWP:004 - Video Wipe Pattern 
const uint8_t WIPE_BLIND_L = 5; // VWP:005 - Video Wipe Pattern 
const uint8_t WIPE_BLIND_D = 6; // VWP:006 - Video Wipe Pattern 
const uint8_t WIPE_BLIND_R = 7; // VWP:007 - Video Wipe Pattern 
const uint8_t WIPE_BLIND_U = 8; // VWP:008 - Video Wipe Pattern 
const uint8_t WIPE_TRIANGLE_CORNER_UL = 9; // VWP:009 - Video Wipe Pattern 
const uint8_t WIPE_TRIANGLE_CORNER_DL = 10; // VWP:010 - Video Wipe Pattern 
const uint8_t WIPE_TRIANGLE_CORNER_DR = 11; // VWP:011 - Video Wipe Pattern 
const uint8_t WIPE_TRIANGLE_CORNER_UR = 12; // VWP:012 - Video Wipe Pattern 
const uint8_t WIPE_TRIANGLE_L = 13; // VWP:013 - Video Wipe Pattern 
const uint8_t WIPE_TRIANGLE_D = 14; // VWP:014 - Video Wipe Pattern 
const uint8_t WIPE_TRIANGLE_R = 15; // VWP:015 - Video Wipe Pattern 
const uint8_t WIPE_TRIANGLE_U = 16; // VWP:016 - Video Wipe Pattern 
const uint8_t WIPE_SQUARE = 17; // VWP:017 - Video Wipe Pattern 
const uint8_t WIPE_CIRCLE = 18; // VWP:018 - Video Wipe Pattern 
const uint8_t WIPE_OVALE = 19; // VWP:019 - Video Wipe Pattern 
const uint8_t WIPE_LOSANGE = 20; // VWP:020 - Video Wipe Pattern 
const uint8_t WIPE_I = 21; // VWP:021 - Video Wipe Pattern 
const uint8_t WIPE_MINUS = 22; // VWP:022 - Video Wipe Pattern 
const uint8_t WIPE_PLUS = 23; // VWP:023 - Video Wipe Pattern 
const uint8_t WIPE_SPECIAL_24 = 24; // VWP:024 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_25 = 25; // VWP:025 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_26 = 26; // VWP:026 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_27 = 27; // VWP:027 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_28 = 28; // VWP:028 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_29 = 29; // VWP:029 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_30 = 30; // VWP:030 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_31 = 31; // VWP:031 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_32 = 32; // VWP:032 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_33 = 33; // VWP:033 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_34 = 34; // VWP:034 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_35 = 35; // VWP:035 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_36 = 36; // VWP:036 - Video Special Wipe Pattern 
const uint8_t WIPE_SPECIAL_37 = 37; // VWP:037 - Video Special Wipe Pattern 
const uint8_t DIRECTION_ONE_WAY = 40; // VWD:040 - Wipe Direction 
const uint8_t DIRECTION_REVERSE = 41; // VWD:041 - Wipe Direction 
const uint8_t EDGE_NONE = 42; // VWB:042 - Edge/Border 
const uint8_t EDGE_BORDER = 43; // VWB:043 - Edge/Border   ! 50 
const uint8_t EDGE_SOFT = 44; // VWB:044 - Edge/Border ! 50 
const uint8_t MULTI_BASIC = 45; // VWM:045 - Multi Wipe 
const uint8_t MULTI_1 = 46; // VWM:046 - Multi Wipe    ! 47 
const uint8_t MULTI_2 = 47; // VWM:047 - Multi Wipe    ! 47 
const uint8_t MULTI_3 = 48; // VWM:048 - Multi Wipe    ! 47 
const uint8_t MODE_NORMAL = 49; // VWM:049 - Wipe Mode 
const uint8_t MODE_COMPRESSION = 50; // VWM:050 - Wipe Mode 
const uint8_t MODE_SLIDE = 51; // VWM:051 - Wipe Mode 
const uint8_t MODE_PAIR = 52; // VWM:052 - Wipe Mode 
const uint8_t MODE_SLIDE_COMPRESSION = 53; // VW:053 - Wipe Mode 
const uint8_t OPERATION_OVER = 54; // VW:054 - Wipe Operation 
const uint8_t OPERATION_REMOVE = 55; // VW:055 - Wipe Operation 
const uint8_t OPERATION_FLIP = 56; // VW:056 - Wipe Operation 
const uint8_t OPERATION_PUSH = 57; // VW:057 - Wipe Operation 
const uint8_t SPEDGE_NONE = 61; // VWB:061 - Special Edge 
const uint8_t SPEDGE_BORDER = 62; // VWB:062 - Special Edge 
const uint8_t SPEDGE_SOFT = 63; // VWB:063 - Special Edge 
const uint8_t A_BUS_STROBO_OFF = 70; // VDE:070 - Video digital effect 
const uint8_t A_BUS_STROBO_STEP_1 = 71; // VDE:071 - Video digital effect 
const uint8_t A_BUS_STROBO_STEP_2 = 72; // VDE:072 - Video digital effect 
const uint8_t A_BUS_STROBO_STEP_3 = 73; // VDE:073 - Video digital effect 
const uint8_t A_BUS_STROBO_STEP_4 = 74; // VDE:074 - Video digital effect 
const uint8_t A_BUS_STROBO_STEP_5 = 75; // VDE:075 - Video digital effect 
const uint8_t A_BUS_MOSAIC_OFF = 76; // VDE:076 - Video digital effect 
const uint8_t A_BUS_MOSAIC_STEP_1 = 77; // VDE:077 - Video digital effect 
const uint8_t A_BUS_MOSAIC_STEP_2 = 78; // VDE:078 - Video digital effect 
const uint8_t A_BUS_MOSAIC_STEP_3 = 79; // VDE:079 - Video digital effect 
const uint8_t A_BUS_MOSAIC_STEP_4 = 80; // VDE:080 - Video digital effect 
const uint8_t A_BUS_MOSAIC_STEP_5 = 81; // VDE:081 - Video digital effect 
const uint8_t A_BUS_PAINT_OFF = 82; // VDE:082 - Video digital effect 
const uint8_t A_BUS_PAINT_STEP_1 = 83; // VDE:083 - Video digital effect 
const uint8_t A_BUS_PAINT_STEP_2 = 84; // VDE:084 - Video digital effect 
const uint8_t A_BUS_PAINT_STEP_3 = 85; // VDE:085 - Video digital effect 
const uint8_t A_BUS_PAINT_STEP_4 = 86; // VDE:086 - Video digital effect 
const uint8_t A_BUS_NEGATIVE_OFF = 87; // VDE:087 - Video digital effect 
const uint8_t A_BUS_NEGATIVE_ON = 88; // VDE:088 - Video digital effect 
const uint8_t A_BUS_FIELD_STILL_MODE = 89; // VDE:089 - Video digital effect 
const uint8_t A_BUS_FRAME_STILL_MODE = 90; // VDE:090 - Video digital effect 
const uint8_t A_BUS_COLOR_CORRECTOR_OFF = 91; // VDE:091 - Video digital effect 
const uint8_t A_BUS_COLOR_CORRECTOR_ON = 92; // VDE:092 - Video digital effect 
const uint8_t A_BUS_CHROMA_LEVEL = 93; // VDE:093 - xx Video digital effect    xx = (ASCII HEX1H_17H 
const uint8_t B_BUS_STROBO_OFF = 94; // VDE:094 - Video digital effect 
const uint8_t B_BUS_STROBO_STEP_1 = 95; // VDE:095 - Video digital effect 
const uint8_t B_BUS_STROBO_STEP_2 = 96; // VDE:096 - Video digital effect 
const uint8_t B_BUS_STROBO_STEP_3 = 97; // VDE:097 - Video digital effect 
const uint8_t B_BUS_STROBO_STEP_4 = 98; // VDE:098 - Video digital effect 
const uint8_t B_BUS_STROBO_STEP_5 = 99; // VDE:099 - Video digital effect 
const uint8_t B_BUS_MOSAIC_OFF = 100; // VDE:100 - Video digital effect 
const uint8_t B_BUS_MOSAIC_STEP_1 = 101; // VDE:101 - Video digital effect 
const uint8_t B_BUS_MOSAIC_STEP_2 = 102; // VDE:102 - Video digital effect 
const uint8_t B_BUS_MOSAIC_STEP_3 = 103; // VDE:103 - Video digital effect 
const uint8_t B_BUS_MOSAIC_STEP_4 = 104; // VDE:104 - Video digital effect 
const uint8_t B_BUS_MOSAIC_STEP_5 = 105; // VDE:105 - Video digital effect 
const uint8_t B_BUS_PAINT_OFF = 106; // VDE:106 - Video digital effect 
const uint8_t B_BUS_PAINT_STEP_1 = 107; // VDE:107 - Video digital effect 
const uint8_t B_BUS_PAINT_STEP_2 = 108; // VDE:108 - Video digital effect 
const uint8_t B_BUS_PAINT_STEP_3 = 109; // VDE:109 - Video digital effect 
const uint8_t B_BUS_PAINT_STEP_4 = 110; // VDE:110 - Video digital effect 
const uint8_t B_BUS_NEGATIVE_OFF = 111; // VDE:111 - Video digital effect 
const uint8_t B_BUS_NEGATIVE_ON = 112; // VDE:112 - Video digital effect 
const uint8_t B_BUS_FIELD_STILL_MODE = 113; // VDE:113 - Video digital effect 
const uint8_t B_BUS_FRAME_STILL_MODE = 114; // VDE:114 - Video digital effect 
const uint8_t B_BUS_COLOR_CORRECTOR_OFF = 115; // VDE:115 - Video digital effect 
const uint8_t B_BUS_COLOR_CORRECTOR_ON = 116; // VDE:116 - Video digital effect 
const uint8_t B_BUS_CHROMA_LEVEL = 117; // VDE:117 - xx   Video digital effect    xx = (ASCII HEX 01H_17H 
const uint8_t AUDIO_MIX_LEVEL_GLOBAL_FOLLOW_ON = 120; // AML:120 - Audio 
const uint8_t AUDIO_MIX_LEVEL_GLOBAL_FOLLOW_OFF = 121; // AML:121 - Audio 
const uint8_t AUDIO_LEVEL_SOURCE_1 = 122; // ALV:122 - xx Audio   (xx is ASCII 00H_1AH 
const uint8_t AUDIO_LEVEL_SOURCE_2 = 123; // ALV:123 - xx Audio   (xx is ASCII 00H_1AH 
const uint8_t AUDIO_LEVEL_SOURCE_3 = 124; // ALV:124 - xx Audio   (xx is ASCII 00H_1AH 
const uint8_t AUDIO_LEVEL_SOURCE_4 = 125; // ALV:125 - xx Audio   (xx is ASCII 00H_1AH 
const uint8_t AUDIO_MIX_LEVEL_SOURCE_4_FOLLOW_ON = 126; // AML:126 - Audio 
const uint8_t AUDIO_MIX_LEVEL_SOURCE_4_FOLLOW_OFF = 127; // AML:127 - Audio 
const uint8_t VIDEO_FADE_ON = 130; // VFD:130 - Fade 
const uint8_t VIDEO_FADE_OFF = 131; // VFD:131 - Fade 
const uint8_t AUDIO_FADE_ON = 132; // VFD:132 - Fade 
const uint8_t AUDIO_FADE_OFF = 133; // VFD:133 - Fade 
const uint8_t TITTLE_FADE_ON = 134; // VFD:134 - Fade 
const uint8_t TITTLE_FADE_OFF = 135; // VFD:135 - Fade 
const uint8_t FADE_TO_WHITE = 136; // VFD:136 - Fade 
const uint8_t FADE_TO_BLACK = 137; // VFD:137 - Fade 
const uint8_t FADE_TO_COLOR = 138; // VFD:138 - Fade 
const uint8_t BACK_COLOR_WHITE = 140; // VBC:140 - Set background color 
const uint8_t BACK_COLOR_YELLOW = 141; // VBC:141 - Set background color 
const uint8_t BACK_COLOR_CYAN = 142; // VBC:142 - Set background color 
const uint8_t BACK_COLOR_GREEN = 143; // VBC:143 - Set background color 
const uint8_t BACK_COLOR_MAGENTA = 144; // VBC:144 - Set background color 
const uint8_t BACK_COLOR_RED = 145; // VBC:145 - Set background color 
const uint8_t BACK_COLOR_BLUE = 146; // VBC:146 - Set background color 
const uint8_t BACK_COLOR_BLACK = 147; // VBC:147 - Set background color 
const uint8_t BACK_COLOR_USER_COLOR = 148; // VBC:148 - Set background color  set by 174 
const uint8_t EDGE_COLOR_WHITE = 150; // VEC:150 - Set edge color 
const uint8_t EDGE_COLOR_YELLOW = 151; // VEC:151 - Set edge color 
const uint8_t EDGE_COLOR_CYAN = 152; // VEC:152 - Set edge color 
const uint8_t EDGE_COLOR_GREEN = 153; // VEC:153 - Set edge color 
const uint8_t EDGE_COLOR_MAGENTA = 154; // VEC:154 - Set edge color 
const uint8_t EDGE_COLOR_RED = 155; // VEC:155 - Set edge color 
const uint8_t EDGE_COLOR_BLUE = 156; // VEC:156 - Set edge color 
const uint8_t EDGE_COLOR_BLACK = 157; // VEC:157 - Set edge color 
const uint8_t EDGE_COLOR_USER_COLOR = 158; // VEC:158 - Set edge color    set by 175 
const uint8_t COLOR_MODE_NORMAL = 160; // VBG:160 - Color Mode 
const uint8_t COLOR_MODE_VERTICAL = 161; // VBG:161 - Color Mode 
const uint8_t COLOR_MODE_HORIZONTAL = 162; // VBG:162 - Color Mode 
const uint8_t COLOR_MODE_LINES = 163; // VBG:163 - Color Mode 
const uint8_t COLOR_MODE_PALETTE = 164; // VBG:164 - Color Mode 
const uint8_t TITLE_COLOR_INTERNAL_BACK_COLOR = 165; // VTC:165 - Title colr  internal color _ using back color 
const uint8_t TITLE_COLOR_EXTERNAL = 166; // VTC:166 - Title color    external color _ controlled by titler 
const uint8_t TITLE_EDGE_PATTERN_0_OFF = 167; // VTE:167 - Tittle pattern 
const uint8_t TITLE_EDGE_PATTERN_1 = 168; // VTE:168 - Tittle pattern 
const uint8_t TITLE_EDGE_PATTERN_2 = 169; // VTE:169 - Tittle pattern 
const uint8_t TITLE_EDGE_PATTERN_3 = 170; // VTE:170 - Tittle pattern 
const uint8_t TITLE_EDGE_PATTERN_4 = 171; // VTE:171 - Tittle pattern 
const uint8_t TITLE_EDGE_PATTERN_5 = 172; // VTE:172 - Tittle pattern 
const uint8_t BACK_COLOR_MANUAL = 174; // VB:174 - xxyy  Set user color xx = B_Y (ASCII HEX 00H_FFH) yy = R_Y (ASCII HEX 00H_FFH 
const uint8_t EDGE_COLOR_MANUAL = 175; // VE:175 - xxyy  Set user color xx = B_Y (ASCII HEX 00H_FFH) yy = R_Y (ASCII HEX 00H_FFH 
const uint8_t A_B_MIX_LEVEL = 179; // VMM:179 - xx    POTENTIOMETRE 00= A, FF= B 
const uint8_t A_BUS_EFFECT_ON = 180; // VDE:180 - BUTTON 
const uint8_t A_BUS_EFFECT_OFF = 181; // VDE:181 - BUTTON 
const uint8_t B_BUS_EFFECT_ON = 182; // VDE:182 - BUTTON 
const uint8_t B_BUS_EFFECT_OFF = 183; // VDE:183 - BUTTON 
const uint8_t A_BUS_STILL_ON = 184; // VDE:184 - BUTTON 
const uint8_t A_BUS_STILL_OFF = 185; // VDE:185 - BUTTON 
const uint8_t B_BUS_STILL_ON = 186; // VDE:186 - BUTTON 
const uint8_t B_BUS_STILL_OFF = 187; // VDE:187 - BUTTON 
const uint8_t SPEED_SET = 190; // VAS:190 - xx    POTENTIOMETRE   xx = (ASCII HEX 01H_FFH 
const uint8_t FADE_BUTTON = 191; // VF:191 - BUTTON 
const uint8_t TAKE_BUTTON = 192; // VMA:192 - BUTTON 
const uint8_t BACK_COLOR_COLOR_BARS = 197; // VBC:197 - test 
const uint8_t BACK_COLOR_NOT_COLOR_BARS = 198; // VBC:198 - test 
const uint8_t RESET_TO_FACTORY_SETTINGS = 199; // ZRS:199 - Reset 
const uint8_t A_BUS_SOURCE_1 = 200; // VCP:200 - BUTTON 
const uint8_t A_BUS_SOURCE_2 = 201; // VCP:201 - BUTTON 
const uint8_t A_BUS_SOURCE_3 = 202; // VCP:202 - BUTTON 
const uint8_t A_BUS_SOURCE_4 = 203; // VCP:203 - BUTTON 
const uint8_t A_BUS_BACK_COLOR = 204; // VCP:204 - BUTTON 
const uint8_t B_BUS_SOURCE_1 = 205; // VCP:205 - BUTTON 
const uint8_t B_BUS_SOURCE_2 = 206; // VCP:206 - BUTTON 
const uint8_t B_BUS_SOURCE_3 = 207; // VCP:207 - BUTTON 
const uint8_t B_BUS_SOURCE_4 = 208; // VCP:208 - BUTTON 
const uint8_t B_BUS_BACK_COLOR = 209; // VCP:209 - BUTTON 
const uint8_t WIPE_MIX_BUTTON = 210; // VMX:210 - BUTTON 
const uint8_t THRESHOLD_LUM_KEY = 211; // VMX:211 - xx    BUTTON  (xx = ASCII HEX 00H FFH 
const uint8_t LUM_KEY = 212; // VMX:212 - BUTTON 
const uint8_t CHROMA_KEY = 213; // VMX:213 - BUTTON 
const uint8_t CHROMA_SET = 214; // VCS:214 - xxyyzz   BUTTON  3 couleurs en mémoire ? 
const uint8_t UNDO = 215; // ZUD:215 - BUTTON 
const uint8_t ENTER = 216; // ZEN:216 - BUTTON 
const uint8_t COLOR_CORECT = 217; // VPS:217 - xxyy   POSITION 
const uint8_t CENTER_WIPE = 218; // VPS:218 - xxyy    POSITION    (xx = horizontal) (yy _ vertical) (ASCII HEX 00H_FFH 
const uint8_t SCENE_GRABER = 219; // VPS:219 - xxyy   POSITION 

}