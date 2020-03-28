#include <stdint.h>
#include <Arduino.h>

namespace OUTTYPE{
    const uint8_t BUTTON = 0;
    const uint8_t SLIDER = 1;
    const uint8_t SLIDER_TWO = 2;
    const uint8_t SWITCH = 3;
}

namespace AVE55{

// const uint8_t notes[177] = {133, 132, 137, 138, 136, 131, 130, 135, 134, 121, 120, 127, 126, 204, 200, 201, 202, 203, 209, 205, 206, 207, 208, 91, 92, 181, 180, 89, 90, 76, 77, 78, 79, 80, 81, 87, 88, 82, 83, 84, 85, 86, 185, 184, 70, 71, 72, 73, 74, 75, 115, 116, 183, 182, 113, 114, 100, 101, 102, 103, 104, 105, 111, 112, 106, 107, 108, 109, 110, 187, 186, 94, 95, 96, 97, 98, 99, 147, 146, 197, 142, 143, 144, 198, 145, 148, 140, 141, 213, 212, 0, 210, 162, 163, 160, 164, 161, 40, 41, 43, 42, 44, 62, 61, 63, 157, 156, 152, 153, 154, 155, 158, 150, 151, 216, 91, 50, 49, 52, 51, 46, 47, 48, 45, 53, 56, 54, 57, 55, 199, 192, 215, 166, 165, 167, 168, 169, 170, 171, 172, 6, 5, 7, 8, 18, 21, 20, 22, 19, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 17, 2, 3, 1, 4, 10, 11, 9, 12, 14, 13, 15, 16};

const uint8_t flat_notes_ch_two[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 61, 62, 63, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 120, 121, 126, 127, 130, 131, 132, 133, 134, 135, 136, 137, 138, 140, 141, 142, 143, 144, 145, 146, 147, 148};
const uint8_t flat_notes_ch_three[128] = {150, 151, 152, 153, 154, 155, 156, 157, 158, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 180, 181, 182, 183, 184, 185, 186, 187, 191, 192, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 212, 213, 215, 216};
const uint8_t flat_cc_ch_two[128] = {93, 117, 122, 123, 124, 125, 179, 190, 211, 174, 174, 175, 175, 217, 217, 218, 218, 219, 219, 214, 214,214};

bool is_one_input(uint8_t cmd){
    return cmd == 93 || cmd == 117 || cmd == 122 || cmd == 123 || cmd == 124 || cmd == 125 || cmd == 179 || cmd == 190 || cmd == 211;
}

bool is_two_input(uint8_t cmd){
    return cmd == 174 || cmd == 175 || cmd == 217 || cmd == 218 || cmd == 219;
}

bool is_three_input(uint8_t cmd){
    return cmd == 214;
}

//oneInput controls:
//A_BUS_CHROMA_LEVEL:93, B_BUS_CHROMA_LEVEL:117, AUDIO_LEVEL_SOURCE_1:122, AUDIO_LEVEL_SOURCE_2:123, AUDIO_LEVEL_SOURCE_3:124, AUDIO_LEVEL_SOURCE_4:125, A_B_MIX_LEVEL:179, SPEED_SET:190, THRESHOLD_LUM_KEY
// const uint8_t oneParamControl[10] = {93, 117, 122, 123, 124, 125, 179, 190, 211};
//twoInput controls:
// 0=BACK_COLOR_MANUAL:174, 1=EDGE_COLOR_MANUAL:175, 2=COLOR_CORECT:217, 3=CENTER_WIPE:218, 4=SCENE_GRABER:219
// const uint8_t twoParamControl[5] = {174, 175, 217, 218, 219};
//threeInput controls:
// 0=CHROMA_SET:214
// const uint8_t threeParamControl[1] = {214};

const uint8_t MIX_MODE = 0; // Mix mode /Out of WIPE
const uint8_t WIPE_SQUARE_CORNER_UL = 1; // Video Wipe Pattern
const uint8_t WIPE_SQUARE_CORNER_DL = 2; // Video Wipe Pattern
const uint8_t WIPE_SQUARE_CORNER_DR = 3; // Video Wipe Pattern
const uint8_t WIPE_SQUARE_CORNER_UR = 4; // Video Wipe Pattern
const uint8_t WIPE_BLIND_L = 5; // Video Wipe Pattern
const uint8_t WIPE_BLIND_D = 6; // Video Wipe Pattern
const uint8_t WIPE_BLIND_R = 7; // Video Wipe Pattern
const uint8_t WIPE_BLIND_U = 8; // Video Wipe Pattern
const uint8_t WIPE_TRIANGLE_CORNER_UL = 9; // Video Wipe Pattern
const uint8_t WIPE_TRIANGLE_CORNER_DL = 10; // Video Wipe Pattern
const uint8_t WIPE_TRIANGLE_CORNER_DR = 11; // Video Wipe Pattern
const uint8_t WIPE_TRIANGLE_CORNER_UR = 12; // Video Wipe Pattern
const uint8_t WIPE_TRIANGLE_L = 13; // Video Wipe Pattern
const uint8_t WIPE_TRIANGLE_D = 14; // Video Wipe Pattern
const uint8_t WIPE_TRIANGLE_R = 15; // Video Wipe Pattern
const uint8_t WIPE_TRIANGLE_U = 16; // Video Wipe Pattern
const uint8_t WIPE_SQUARE = 17; // Video Wipe Pattern
const uint8_t WIPE_CIRCLE = 18; // Video Wipe Pattern
const uint8_t WIPE_OVALE = 19; // Video Wipe Pattern
const uint8_t WIPE_LOSANGE = 20; // Video Wipe Pattern
const uint8_t WIPE_I =21; // Video Wipe Pattern
const uint8_t WIPE_MINUS =22; // Video Wipe Pattern
const uint8_t WIPE_PLUS =23; // Video Wipe Pattern
const uint8_t WIPE_SPECIAL_24 =24; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_25 =25; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_26 =26; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_27 =27; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_28 =28; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_29 =29; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_30 =30; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_31 =31; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_32 =32; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_33 =33; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_34 =34; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_35 =35; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_36 =36; // Video Special Wipe Pattern
const uint8_t WIPE_SPECIAL_37 =37; // Video Special Wipe Pattern
const uint8_t DIRECTION_ONE_WAY =40; // Wipe Direction
const uint8_t DIRECTION_REVERSE =41; // Wipe Direction
const uint8_t EDGE_NONE =42; // Edge/Border
const uint8_t EDGE_BORDER =43; // Edge/Border	! 50
const uint8_t EDGE_SOFT =44; // Edge/Border	! 50
const uint8_t MULTI_BASIC =45; // Multi Wipe
const uint8_t MULTI_1 =46; // Multi Wipe	! 47
const uint8_t MULTI_2 =47; // Multi Wipe	! 47
const uint8_t MULTI_3 =48; // Multi Wipe	! 47
const uint8_t MODE_NORMAL =49; // Wipe Mode
const uint8_t MODE_COMPRESSION =50; // Wipe Mode
const uint8_t MODE_SLIDE =51; // Wipe Mode
const uint8_t MODE_PAIR =52; // Wipe Mode
const uint8_t MODE_SLIDE_COMPRESSION =53; // Wipe Mode
const uint8_t OPERATION_OVER =54; // Wipe Operation
const uint8_t OPERATION_REMOVE =55; // Wipe Operation
const uint8_t OPERATION_FLIP =56; // Wipe Operation
const uint8_t OPERATION_PUSH =57; // Wipe Operation
const uint8_t SPEDGE_NONE =61; // Special Edge
const uint8_t SPEDGE_BORDER =62; // Special Edge
const uint8_t SPEDGE_SOFT =63; // Special Edge
const uint8_t A_BUS_STROBO_OFF =70; // Video digital effect
const uint8_t A_BUS_STROBO_STEP_1 =71; // Video digital effect
const uint8_t A_BUS_STROBO_STEP_2 =72; // Video digital effect
const uint8_t A_BUS_STROBO_STEP_3 =73; // Video digital effect
const uint8_t A_BUS_STROBO_STEP_4 =74; // Video digital effect
const uint8_t A_BUS_STROBO_STEP_5 =75; // Video digital effect
const uint8_t A_BUS_MOSAIC_OFF =76; // Video digital effect
const uint8_t A_BUS_MOSAIC_STEP_1 =77; // Video digital effect
const uint8_t A_BUS_MOSAIC_STEP_2 =78; // Video digital effect
const uint8_t A_BUS_MOSAIC_STEP_3 =79; // Video digital effect
const uint8_t A_BUS_MOSAIC_STEP_4 =80; // Video digital effect
const uint8_t A_BUS_MOSAIC_STEP_5 =81; // Video digital effect
const uint8_t A_BUS_PAINT_OFF =82; // Video digital effect
const uint8_t A_BUS_PAINT_STEP_1 =83; // Video digital effect
const uint8_t A_BUS_PAINT_STEP_2 =84; // Video digital effect
const uint8_t A_BUS_PAINT_STEP_3 =85; // Video digital effect
const uint8_t A_BUS_PAINT_STEP_4 =86; // Video digital effect
const uint8_t A_BUS_NEGATIVE_OFF =87; // Video digital effect
const uint8_t A_BUS_NEGATIVE_ON =88; // Video digital effect
const uint8_t A_BUS_FIELD_STILL_MODE =89; // Video digital effect
const uint8_t A_BUS_FRAME_STILL_MODE =90; // Video digital effect
const uint8_t A_BUS_COLOR_CORRECTOR_OFF =91; // Video digital effect
const uint8_t A_BUS_COLOR_CORRECTOR_ON =92; // Video digital effect
const uint8_t A_BUS_CHROMA_LEVEL =93; // xx	Video digital effect 	xx =(ASCII HEX1H_17H
const uint8_t B_BUS_STROBO_OFF =94; // Video digital effect
const uint8_t B_BUS_STROBO_STEP_1 =95; // Video digital effect
const uint8_t B_BUS_STROBO_STEP_2 =96; // Video digital effect
const uint8_t B_BUS_STROBO_STEP_3 =97; // Video digital effect
const uint8_t B_BUS_STROBO_STEP_4 =98; // Video digital effect
const uint8_t B_BUS_STROBO_STEP_5 =99; // Video digital effect
const uint8_t B_BUS_MOSAIC_OFF = 100; // Video digital effect
const uint8_t B_BUS_MOSAIC_STEP_1 = 101; // Video digital effect
const uint8_t B_BUS_MOSAIC_STEP_2 = 102; // Video digital effect
const uint8_t B_BUS_MOSAIC_STEP_3 = 103; // Video digital effect
const uint8_t B_BUS_MOSAIC_STEP_4 = 104; // Video digital effect
const uint8_t B_BUS_MOSAIC_STEP_5 = 105; // Video digital effect
const uint8_t B_BUS_PAINT_OFF = 106; // Video digital effect
const uint8_t B_BUS_PAINT_STEP_1 = 107; // Video digital effect
const uint8_t B_BUS_PAINT_STEP_2 = 108; // Video digital effect
const uint8_t B_BUS_PAINT_STEP_3 = 109; // Video digital effect
const uint8_t B_BUS_PAINT_STEP_4 = 110; // Video digital effect
const uint8_t B_BUS_NEGATIVE_OFF = 111; // Video digital effect
const uint8_t B_BUS_NEGATIVE_ON = 112; // Video digital effect
const uint8_t B_BUS_FIELD_STILL_MODE = 113; // Video digital effect
const uint8_t B_BUS_FRAME_STILL_MODE = 114; // Video digital effect
const uint8_t B_BUS_COLOR_CORRECTOR_OFF = 115; // Video digital effect
const uint8_t B_BUS_COLOR_CORRECTOR_ON = 116; // Video digital effect
const uint8_t B_BUS_CHROMA_LEVEL = 117; // xx	Video digital effect 	xx =(ASCII HEX 01H_17H
const uint8_t AUDIO_MIX_LEVEL_GLOBAL_FOLLOW_ON = 120; // Audio
const uint8_t AUDIO_MIX_LEVEL_GLOBAL_FOLLOW_OFF = 121; // Audio
const uint8_t AUDIO_LEVEL_SOURCE_1 = 122; // xx	Audio	(xx is ASCII 00H_1AH
const uint8_t AUDIO_LEVEL_SOURCE_2 = 123; // xx	Audio	(xx is ASCII 00H_1AH
const uint8_t AUDIO_LEVEL_SOURCE_3 = 124; // xx	Audio	(xx is ASCII 00H_1AH
const uint8_t AUDIO_LEVEL_SOURCE_4 = 125; // xx	Audio	(xx is ASCII 00H_1AH
const uint8_t AUDIO_MIX_LEVEL_SOURCE_4_FOLLOW_ON = 126; // Audio
const uint8_t AUDIO_MIX_LEVEL_SOURCE_4_FOLLOW_OFF = 127; // Audio
const uint8_t VIDEO_FADE_ON = 130; // Fade
const uint8_t VIDEO_FADE_OFF = 131; // Fade
const uint8_t AUDIO_FADE_ON = 132; // Fade
const uint8_t AUDIO_FADE_OFF = 133; // Fade
const uint8_t TITTLE_FADE_ON = 134; // Fade
const uint8_t TITTLE_FADE_OFF = 135; // Fade
const uint8_t FADE_TO_WHITE = 136; // Fade
const uint8_t FADE_TO_BLACK = 137; // Fade
const uint8_t FADE_TO_COLOR = 138; // Fade
const uint8_t BACK_COLOR_WHITE = 140; // Set background color
const uint8_t BACK_COLOR_YELLOW = 141; // Set background color
const uint8_t BACK_COLOR_CYAN = 142; // Set background color
const uint8_t BACK_COLOR_GREEN = 143; // Set background color
const uint8_t BACK_COLOR_MAGENTA = 144; // Set background color
const uint8_t BACK_COLOR_RED = 145; // Set background color
const uint8_t BACK_COLOR_BLUE = 146; // Set background color
const uint8_t BACK_COLOR_BLACK = 147; // Set background color
const uint8_t BACK_COLOR_USER_COLOR = 148; // Set background color	set by 174
const uint8_t EDGE_COLOR_WHITE = 150; // Set edge color
const uint8_t EDGE_COLOR_YELLOW = 151; // Set edge color
const uint8_t EDGE_COLOR_CYAN = 152; // Set edge color
const uint8_t EDGE_COLOR_GREEN = 153; // Set edge color
const uint8_t EDGE_COLOR_MAGENTA = 154; // Set edge color
const uint8_t EDGE_COLOR_RED = 155; // Set edge color
const uint8_t EDGE_COLOR_BLUE = 156; // Set edge color
const uint8_t EDGE_COLOR_BLACK = 157; // Set edge color
const uint8_t EDGE_COLOR_USER_COLOR = 158; // Set edge color	set by 175
const uint8_t COLOR_MODE_NORMAL = 160; // Color Mode
const uint8_t COLOR_MODE_VERTICAL = 161; // Color Mode
const uint8_t COLOR_MODE_HORIZONTAL = 162; // Color Mode
const uint8_t COLOR_MODE_LINES = 163; // Color Mode
const uint8_t COLOR_MODE_PALETTE = 164; // Color Mode
const uint8_t TITLE_COLOR_INTERNAL_BACK_COLOR = 165; // Title colr	internal color _ using back color
const uint8_t TITLE_COLOR_EXTERNAL = 166; // Title color	external color _ controlled by titler
const uint8_t TITLE_EDGE_PATTERN_0_OFF = 167; // Tittle pattern
const uint8_t TITLE_EDGE_PATTERN_1 = 168; // Tittle pattern
const uint8_t TITLE_EDGE_PATTERN_2 = 169; // Tittle pattern
const uint8_t TITLE_EDGE_PATTERN_3 = 170; // Tittle pattern
const uint8_t TITLE_EDGE_PATTERN_4 = 171; // Tittle pattern
const uint8_t TITLE_EDGE_PATTERN_5 = 172; // Tittle pattern
const uint8_t BACK_COLOR_MANUAL = 174; // xxyy	Set user color xx = B_Y (ASCII HEX 00H_FFH) yy = R_Y (ASCII HEX 00H_FFH
const uint8_t EDGE_COLOR_MANUAL = 175; // xxyy	Set user color xx = B_Y (ASCII HEX 00H_FFH) yy = R_Y (ASCII HEX 00H_FFH
const uint8_t A_B_MIX_LEVEL = 179; // xx	POTENTIOMETRE 00=A, FF=B
const uint8_t A_BUS_EFFECT_ON = 180; // BUTTON
const uint8_t A_BUS_EFFECT_OFF = 181; // BUTTON
const uint8_t B_BUS_EFFECT_ON = 182; // BUTTON
const uint8_t B_BUS_EFFECT_OFF = 183; // BUTTON
const uint8_t A_BUS_STILL_ON = 184; // BUTTON
const uint8_t A_BUS_STILL_OFF = 185; // BUTTON
const uint8_t B_BUS_STILL_ON = 186; // BUTTON
const uint8_t B_BUS_STILL_OFF = 187; // BUTTON
const uint8_t SPEED_SET = 190; // xx	POTENTIOMETRE	xx =(ASCII HEX 01H_FFH
const uint8_t FADE_BUTTON = 191; // BUTTON
const uint8_t TAKE_BUTTON = 192; // BUTTON
const uint8_t BACK_COLOR_COLOR_BARS = 197; // test
const uint8_t BACK_COLOR_NOT_COLOR_BARS = 198; // test
const uint8_t RESET_TO_FACTORY_SETTINGS = 199; // Reset
const uint8_t A_BUS_SOURCE_1 = 200; // BUTTON
const uint8_t A_BUS_SOURCE_2 = 201; // BUTTON
const uint8_t A_BUS_SOURCE_3 = 202; // BUTTON
const uint8_t A_BUS_SOURCE_4 = 203; // BUTTON
const uint8_t A_BUS_BACK_COLOR = 204; // BUTTON
const uint8_t B_BUS_SOURCE_1 = 205; // BUTTON
const uint8_t B_BUS_SOURCE_2 = 206; // BUTTON
const uint8_t B_BUS_SOURCE_3 = 207; // BUTTON
const uint8_t B_BUS_SOURCE_4 = 208; // BUTTON
const uint8_t B_BUS_BACK_COLOR = 209; // BUTTON
const uint8_t WIPE_MIX_BUTTON = 210; // BUTTON
const uint8_t THRESHOLD_LUM_KEY = 211; // xx	BUTTON	(xx = ASCII HEX 00H FFH
const uint8_t LUM_KEY = 212; // BUTTON
const uint8_t CHROMA_KEY = 213; // BUTTON
const uint8_t CHROMA_SET = 214; // xxyyzz	BUTTON	3 couleurs en mémoire ?
const uint8_t UNDO = 215; // BUTTON
const uint8_t ENTER = 216; // BUTTON
const uint8_t COLOR_CORECT = 217; // xxyy	POSITION
const uint8_t CENTER_WIPE = 218; // xxyy	POSITION	(xx = horizontal) (yy _ vertical) (ASCII HEX 00H_FFH
const uint8_t SCENE_GRABER = 219; // xxyy	POSITION


/*
const char MIX_MODE[8] = "VMX:000"; // Mix mode /Out of WIPE
const char WIPE_SQUARE_CORNER_UL[8] = "VWP:001"; // Video Wipe Pattern
const char WIPE_SQUARE_CORNER_DL[8] = "VWP:002"; // Video Wipe Pattern
const char WIPE_SQUARE_CORNER_DR[8] = "VWP:003"; // Video Wipe Pattern
const char WIPE_SQUARE_CORNER_UR[8] = "VWP:004"; // Video Wipe Pattern
const char WIPE_BLIND_L[8] = "VWP:005"; // Video Wipe Pattern
const char WIPE_BLIND_D[8] = "VWP:006"; // Video Wipe Pattern
const char WIPE_BLIND_R[8] = "VWP:007"; // Video Wipe Pattern
const char WIPE_BLIND_U[8] = "VWP:008"; // Video Wipe Pattern
const char WIPE_TRIANGLE_CORNER_UL[8] = "VWP:009"; // Video Wipe Pattern
const char WIPE_TRIANGLE_CORNER_DL[8] = "VWP:010"; // Video Wipe Pattern
const char WIPE_TRIANGLE_CORNER_DR[8] = "VWP:011"; // Video Wipe Pattern
const char WIPE_TRIANGLE_CORNER_UR[8] = "VWP:012"; // Video Wipe Pattern
const char WIPE_TRIANGLE_L[8] = "VWP:013"; // Video Wipe Pattern
const char WIPE_TRIANGLE_D[8] = "VWP:014"; // Video Wipe Pattern
const char WIPE_TRIANGLE_R[8] = "VWP:015"; // Video Wipe Pattern
const char WIPE_TRIANGLE_U[8] = "VWP:016"; // Video Wipe Pattern
const char WIPE_SQUARE[8] = "VWP:017"; // Video Wipe Pattern
const char WIPE_CIRCLE[8] = "VWP:018"; // Video Wipe Pattern
const char WIPE_OVALE[8] = "VWP:019"; // Video Wipe Pattern
const char WIPE_LOSANGE[8] = "VWP:020"; // Video Wipe Pattern
const char WIPE_I[8] = "VWP:021"; // Video Wipe Pattern
const char WIPE_MINUS[8] = "VWP:022"; // Video Wipe Pattern
const char WIPE_PLUS[8] = "VWP:023"; // Video Wipe Pattern
const char WIPE_SPECIAL_24[8] = "VWP:024"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_25[8] = "VWP:025"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_26[8] = "VWP:026"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_27[8] = "VWP:027"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_28[8] = "VWP:028"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_29[8] = "VWP:029"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_30[8] = "VWP:030"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_31[8] = "VWP:031"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_32[8] = "VWP:032"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_33[8] = "VWP:033"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_34[8] = "VWP:034"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_35[8] = "VWP:035"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_36[8] = "VWP:036"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_37[8] = "VWP:037"; // Video Special Wipe Pattern
const char DIRECTION_ONE_WAY[8] = "VWD:040"; // Wipe Direction
const char DIRECTION_REVERSE[8] = "VWD:041"; // Wipe Direction
const char EDGE_NONE[8] = "VWB:042"; // Edge/Border
const char EDGE_BORDER[8] = "VWB:043"; // Edge/Border	! 50
const char EDGE_SOFT[8] = "VWB:044"; // Edge/Border	! 50
const char MULTI_BASIC[8] = "VWM:045"; // Multi Wipe
const char MULTI_1[8] = "VWM:046"; // Multi Wipe	! 47
const char MULTI_2[8] = "VWM:047"; // Multi Wipe	! 47
const char MULTI_3[8] = "VWM:048"; // Multi Wipe	! 47
const char MODE_NORMAL[8] = "VWM:049"; // Wipe Mode
const char MODE_COMPRESSION[8] = "VWM:050"; // Wipe Mode
const char MODE_SLIDE[8] = "VWM:051"; // Wipe Mode
const char MODE_PAIR[8] = "VWM:052"; // Wipe Mode
const char MODE_SLIDE_COMPRESSION[8] = "VW:053"; // Wipe Mode
const char OPERATION_OVER[8] = "VW:054"; // Wipe Operation
const char OPERATION_REMOVE[8] = "VW:055"; // Wipe Operation
const char OPERATION_FLIP[8] = "VW:056"; // Wipe Operation
const char OPERATION_PUSH[8] = "VW:057"; // Wipe Operation
const char SPEDGE_NONE[8] = "VWB:061"; // Special Edge
const char SPEDGE_BORDER[8] = "VWB:062"; // Special Edge
const char SPEDGE_SOFT[8] = "VWB:063"; // Special Edge
const char A_BUS_STROBO_OFF[8] = "VDE:070"; // Video digital effect
const char A_BUS_STROBO_STEP_1[8] = "VDE:071"; // Video digital effect
const char A_BUS_STROBO_STEP_2[8] = "VDE:072"; // Video digital effect
const char A_BUS_STROBO_STEP_3[8] = "VDE:073"; // Video digital effect
const char A_BUS_STROBO_STEP_4[8] = "VDE:074"; // Video digital effect
const char A_BUS_STROBO_STEP_5[8] = "VDE:075"; // Video digital effect
const char A_BUS_MOSAIC_OFF[8] = "VDE:076"; // Video digital effect
const char A_BUS_MOSAIC_STEP_1[8] = "VDE:077"; // Video digital effect
const char A_BUS_MOSAIC_STEP_2[8] = "VDE:078"; // Video digital effect
const char A_BUS_MOSAIC_STEP_3[8] = "VDE:079"; // Video digital effect
const char A_BUS_MOSAIC_STEP_4[8] = "VDE:080"; // Video digital effect
const char A_BUS_MOSAIC_STEP_5[8] = "VDE:081"; // Video digital effect
const char A_BUS_PAINT_OFF[8] = "VDE:082"; // Video digital effect
const char A_BUS_PAINT_STEP_1[8] = "VDE:083"; // Video digital effect
const char A_BUS_PAINT_STEP_2[8] = "VDE:084"; // Video digital effect
const char A_BUS_PAINT_STEP_3[8] = "VDE:085"; // Video digital effect
const char A_BUS_PAINT_STEP_4[8] = "VDE:086"; // Video digital effect
const char A_BUS_NEGATIVE_OFF[8] = "VDE:087"; // Video digital effect
const char A_BUS_NEGATIVE_ON[8] = "VDE:088"; // Video digital effect
const char A_BUS_FIELD_STILL_MODE[8] = "VDE:089"; // Video digital effect
const char A_BUS_FRAME_STILL_MODE[8] = "VDE:090"; // Video digital effect
const char A_BUS_COLOR_CORRECTOR_OFF[8] = "VDE:091"; // Video digital effect
const char A_BUS_COLOR_CORRECTOR_ON[8] = "VDE:092"; // Video digital effect
const char A_BUS_CHROMA_LEVEL[8] = "VDE:093"; // xx	Video digital effect 	xx =(ASCII HEX 01H_17H
const char B_BUS_STROBO_OFF[8] = "VDE:094"; // Video digital effect
const char B_BUS_STROBO_STEP_1[8] = "VDE:095"; // Video digital effect
const char B_BUS_STROBO_STEP_2[8] = "VDE:096"; // Video digital effect
const char B_BUS_STROBO_STEP_3[8] = "VDE:097"; // Video digital effect
const char B_BUS_STROBO_STEP_4[8] = "VDE:098"; // Video digital effect
const char B_BUS_STROBO_STEP_5[8] = "VDE:099"; // Video digital effect
const char B_BUS_MOSAIC_OFF[8] = "VDE:100"; // Video digital effect
const char B_BUS_MOSAIC_STEP_1[8] = "VDE:101"; // Video digital effect
const char B_BUS_MOSAIC_STEP_2[8] = "VDE:102"; // Video digital effect
const char B_BUS_MOSAIC_STEP_3[8] = "VDE:103"; // Video digital effect
const char B_BUS_MOSAIC_STEP_4[8] = "VDE:104"; // Video digital effect
const char B_BUS_MOSAIC_STEP_5[8] = "VDE:105"; // Video digital effect
const char B_BUS_PAINT_OFF[8] = "VDE:106"; // Video digital effect
const char B_BUS_PAINT_STEP_1[8] = "VDE:107"; // Video digital effect
const char B_BUS_PAINT_STEP_2[8] = "VDE:108"; // Video digital effect
const char B_BUS_PAINT_STEP_3[8] = "VDE:109"; // Video digital effect
const char B_BUS_PAINT_STEP_4[8] = "VDE:110"; // Video digital effect
const char B_BUS_NEGATIVE_OFF[8] = "VDE:111"; // Video digital effect
const char B_BUS_NEGATIVE_ON[8] = "VDE:112"; // Video digital effect
const char B_BUS_FIELD_STILL_MODE[8] = "VDE:113"; // Video digital effect
const char B_BUS_FRAME_STILL_MODE[8] = "VDE:114"; // Video digital effect
const char B_BUS_COLOR_CORRECTOR_OFF[8] = "VDE:115"; // Video digital effect
const char B_BUS_COLOR_CORRECTOR_ON[8] = "VDE:116"; // Video digital effect
const char B_BUS_CHROMA_LEVEL[8] = "VDE:117"; // xx	Video digital effect 	xx =(ASCII HEX 01H_17H
const char AUDIO_MIX_LEVEL_GLOBAL_FOLLOW_ON[8] = "AML:120"; // Audio
const char AUDIO_MIX_LEVEL_GLOBAL_FOLLOW_OFF[8] = "AML:121"; // Audio
const char AUDIO_LEVEL_SOURCE_1[8] = "ALV:122"; // xx	Audio	(xx is ASCII 00H_1AH
const char AUDIO_LEVEL_SOURCE_2[8] = "ALV:123"; // xx	Audio	(xx is ASCII 00H_1AH
const char AUDIO_LEVEL_SOURCE_3[8] = "ALV:124"; // xx	Audio	(xx is ASCII 00H_1AH
const char AUDIO_LEVEL_SOURCE_4[8] = "ALV:125"; // xx	Audio	(xx is ASCII 00H_1AH
const char AUDIO_MIX_LEVEL_SOURCE_4_FOLLOW_ON[8] = "AML:126"; // Audio
const char AUDIO_MIX_LEVEL_SOURCE_4_FOLLOW_OFF[8] = "AML:127"; // Audio
const char VIDEO_FADE_ON[8] = "VFD:130"; // Fade
const char VIDEO_FADE_OFF[8] = "VFD:131"; // Fade
const char AUDIO_FADE_ON[8] = "VFD:132"; // Fade
const char AUDIO_FADE_OFF[8] = "VFD:133"; // Fade
const char TITTLE_FADE_ON[8] = "VFD:134"; // Fade
const char TITTLE_FADE_OFF[8] = "VFD:135"; // Fade
const char FADE_TO_WHITE[8] = "VFD:136"; // Fade
const char FADE_TO_BLACK[8] = "VFD:137"; // Fade
const char FADE_TO_COLOR[8] = "VFD:138"; // Fade
const char BACK_COLOR_WHITE[8] = "VBC:140"; // Set background color
const char BACK_COLOR_YELLOW[8] = "VBC:141"; // Set background color
const char BACK_COLOR_CYAN[8] = "VBC:142"; // Set background color
const char BACK_COLOR_GREEN[8] = "VBC:143"; // Set background color
const char BACK_COLOR_MAGENTA[8] = "VBC:144"; // Set background color
const char BACK_COLOR_RED[8] = "VBC:145"; // Set background color
const char BACK_COLOR_BLUE[8] = "VBC:146"; // Set background color
const char BACK_COLOR_BLACK[8] = "VBC:147"; // Set background color
const char BACK_COLOR_USER_COLOR[8] = "VBC:148"; // Set background color	set by 174
const char EDGE_COLOR_WHITE[8] = "VEC:150"; // Set edge color
const char EDGE_COLOR_YELLOW[8] = "VEC:151"; // Set edge color
const char EDGE_COLOR_CYAN[8] = "VEC:152"; // Set edge color
const char EDGE_COLOR_GREEN[8] = "VEC:153"; // Set edge color
const char EDGE_COLOR_MAGENTA[8] = "VEC:154"; // Set edge color
const char EDGE_COLOR_RED[8] = "VEC:155"; // Set edge color
const char EDGE_COLOR_BLUE[8] = "VEC:156"; // Set edge color
const char EDGE_COLOR_BLACK[8] = "VEC:157"; // Set edge color
const char EDGE_COLOR_USER_COLOR[8] = "VEC:158"; // Set edge color	set by 175
const char COLOR_MODE_NORMAL[8] = "VBG:160"; // Color Mode
const char COLOR_MODE_VERTICAL[8] = "VBG:161"; // Color Mode
const char COLOR_MODE_HORIZONTAL[8] = "VBG:162"; // Color Mode
const char COLOR_MODE_LINES[8] = "VBG:163"; // Color Mode
const char COLOR_MODE_PALETTE[8] = "VBG:164"; // Color Mode
const char TITLE_COLOR_INTERNAL_BACK_COLOR[8] = "VTC:165"; // Title colr	internal color _ using back color
const char TITLE_COLOR_EXTERNAL[8] = "VTC:166"; // Title color	external color _ controlled by titler
const char TITLE_EDGE_PATTERN_0_OFF[8] = "VTE:167"; // Tittle pattern
const char TITLE_EDGE_PATTERN_1[8] = "VTE:168"; // Tittle pattern
const char TITLE_EDGE_PATTERN_2[8] = "VTE:169"; // Tittle pattern
const char TITLE_EDGE_PATTERN_3[8] = "VTE:170"; // Tittle pattern
const char TITLE_EDGE_PATTERN_4[8] = "VTE:171"; // Tittle pattern
const char TITLE_EDGE_PATTERN_5[8] = "VTE:172"; // Tittle pattern
const char BACK_COLOR_MANUAL[8] = "VB:174"; // xxyy	Set user color xx = B_Y (ASCII HEX 00H_FFH) yy = R_Y (ASCII HEX 00H_FFH
const char EDGE_COLOR_MANUAL[8] = "VE:175"; // xxyy	Set user color xx = B_Y (ASCII HEX 00H_FFH) yy = R_Y (ASCII HEX 00H_FFH
const char A_B_MIX_LEVEL[8] = "VMM:179"; // xx	POTENTIOMETRE 00=A, FF=B
const char A_BUS_EFFECT_ON[8] = "VDE:180"; // BUTTON
const char A_BUS_EFFECT_OFF[8] = "VDE:181"; // BUTTON
const char B_BUS_EFFECT_ON[8] = "VDE:182"; // BUTTON
const char B_BUS_EFFECT_OFF[8] = "VDE:183"; // BUTTON
const char A_BUS_STILL_ON[8] = "VDE:184"; // BUTTON
const char A_BUS_STILL_OFF[8] = "VDE:185"; // BUTTON
const char B_BUS_STILL_ON[8] = "VDE:186"; // BUTTON
const char B_BUS_STILL_OFF[8] = "VDE:187"; // BUTTON
const char SPEED_SET[8] = "VAS:190"; // xx	POTENTIOMETRE	xx =(ASCII HEX 01H_FFH
const char FADE_BUTTON[8] = "VF:191"; // BUTTON
const char TAKE_BUTTON[8] = "VMA:192"; // BUTTON
const char BACK_COLOR_COLOR_BARS[8] = "VBC:197"; // test
const char BACK_COLOR_NOT_COLOR_BARS[8] = "VBC:198"; // test
const char RESET_TO_FACTORY_SETTINGS[8] = "ZRS:199"; // Reset
const char A_BUS_SOURCE_1[8] = "VCP:200"; // BUTTON
const char A_BUS_SOURCE_2[8] = "VCP:201"; // BUTTON
const char A_BUS_SOURCE_3[8] = "VCP:202"; // BUTTON
const char A_BUS_SOURCE_4[8] = "VCP:203"; // BUTTON
const char A_BUS_BACK_COLOR[8] = "VCP:204"; // BUTTON
const char B_BUS_SOURCE_1[8] = "VCP:205"; // BUTTON
const char B_BUS_SOURCE_2[8] = "VCP:206"; // BUTTON
const char B_BUS_SOURCE_3[8] = "VCP:207"; // BUTTON
const char B_BUS_SOURCE_4[8] = "VCP:208"; // BUTTON
const char B_BUS_BACK_COLOR[8] = "VCP:209"; // BUTTON
const char WIPE_MIX_BUTTON[8] = "VMX:210"; // BUTTON
const char THRESHOLD_LUM_KEY[8] = "VMX:211"; // xx	BUTTON	(xx = ASCII HEX 00H FFH
const char LUM_KEY[8] = "VMX:212"; // BUTTON
const char CHROMA_KEY[8] = "VMX:213"; // BUTTON
const char CHROMA_SET[8] = "VCS:214"; // xxyyzz	BUTTON	3 couleurs en mémoire ?
const char UNDO[8] = "ZUD:215"; // BUTTON
const char ENTER[8] = "ZEN:216"; // BUTTON
const char COLOR_CORECT[8] = "VPS:217"; // xxyy	POSITION
const char CENTER_WIPE[8] = "VPS:218"; // xxyy	POSITION	(xx = horizontal) (yy _ vertical) (ASCII HEX 00H_FFH
const char SCENE_GRABER[8] = "VPS:219"; // xxyy	POSITION
*/
}

