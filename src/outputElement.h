#include <stdint.h>
#include <Arduino.h>

class OutputElement{
    public:
        OutputElement(){};
        OutputElement(uint8_t type_,  char cmd_[8]);
        OutputElement(uint8_t type_,  char cmd_[8], char cmd2_[8]);
        // OutputElement(uint8_t type_,  char *cmdArray_[8]);
        uint8_t type;
        uint8_t paramX = 0;
        uint8_t paramY = 0;
        bool switchIndex = false;
        char cmd[8];
        char cmd2[8];
        // char cmdArray[8][2];
        void getCmd(char *buf);
        void updateParamX(uint8_t x);
        void updateParamY(uint8_t y);
};

// class Switch : public OutputElement{};

// class Slider : public OutputElement{};

// class Slider2 : public OutputElement{};

// class Step : public OutputElement{};

