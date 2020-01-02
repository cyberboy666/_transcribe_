#include "outputElement.h"
#include "commands.h"
using namespace AVE55;

OutputElement::OutputElement(char type_[8], char cmd_[8]){
    for(int i = 0; i < 8; i++){
        type[i] = type_[i];
        cmd[i] = cmd_[i];
    }
}

void OutputElement::getCmd(char *buf){
    for(int i = 0; i < 8; i++){
        buf[i] = cmd[i];
    }
}



