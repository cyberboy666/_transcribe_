#include "outputElement.h"
#include "commands.h"
using namespace AVE55;

OutputElement::OutputElement(uint8_t type_, char cmd_[8]){
    for(int i = 0; i < 8; i++){
        cmd[i] = cmd_[i];
    }
    type = type_;
}

void OutputElement::getCmd(char *buf){
    for(int i = 0; i < 8; i++){
        buf[i] = cmd[i];
    }
}

bool OutputElement::hasParam(){
    if(type == 1){return true;}
    return false;
}

