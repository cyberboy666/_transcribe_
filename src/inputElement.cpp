#include "inputElement.h"


InputElement::InputElement(uint8_t _type,  uint8_t _param1){
    type = _type;
    param1 = _param1;
};

InputElement::InputElement(uint8_t _type_x,  uint8_t _param1_x, uint8_t _type_y,  uint8_t _param1_y){
    type = _type_x;
    param1 = _param1_x;
    type_y = _type_y;
    param1_y = _param1_y;
};

uint8_t InputElement::getTypeHex(){
    if(type == 0){ return 0x90;}
    else if(type == 1){ return 0xB0;}
    return 0;
};