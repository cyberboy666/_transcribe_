#include "inputElement.h"


InputElement::InputElement(uint8_t type_,  uint8_t _param1){
    type = type_;
    param1 = _param1;
};

uint8_t InputElement::getTypeHex(){
    if(type == 0){ return 0x90;}
    else if(type == 1){ return 0xB0;}
    return 0;
}
