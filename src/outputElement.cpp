// #include "outputElement.h"
// #include "commands.h"
// using namespace AVE55;

// OutputElement::OutputElement(uint8_t type_, char cmd_[8]){
//     for(uint8_t i = 0; i < 8; i++){
//         cmd[i] = cmd_[i];
//     }
//     type = type_;
// }

// OutputElement::OutputElement(uint8_t type_, char cmd_[8], char cmd2_[8]){
//     for(uint8_t i = 0; i < 8; i++){
//         cmd[i] = cmd_[i];
//         cmd2[i] = cmd2_[i];
//     }
//     type = type_;
// }

// // OutputElement::OutputElement(uint8_t type_, char *cmdArray_[8]){
// //     for(uint8_t i = 0; i < 8; i++){
// //         for(uint8_t j = 0; j < 2; j++){
// //             cmdArray[i][j] = cmdArray_[i][j];
// //         }
// //     }
// //     type = type_;
// // }

// void OutputElement::getCmd(char *buf){
//     if(type != 3){
//         for(uint8_t i = 0; i < 8; i++){
//             buf[i] = cmd[i];
//         }
//     }
//     else{
//         if(switchIndex){
//             for(uint8_t i = 0; i < 8; i++){
//                 buf[i] = cmd;
//             }
//         }
//         else{
//             for(uint8_t i = 0; i < 8; i++){
//                 buf[i] = cmd2[i];
//             }
//         }

//         switchIndex = !switchIndex;
//     }

// }
 
// void OutputElement::updateParamX(uint8_t x){
//     paramX = x;
// }

// void OutputElement::updateParamY(uint8_t y){
//     paramY = y;
// }