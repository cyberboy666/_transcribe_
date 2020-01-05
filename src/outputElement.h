#include <stdint.h>
#include <Arduino.h>

class OutputElement{
    public:
        OutputElement(){};
        OutputElement(uint8_t type_,  char cmd_[8]);
        uint8_t type;
        char cmd[8];
        void getCmd(char *buf);
        bool hasParam();
};

// class Switch : public OutputElement{};

// class Slider : public OutputElement{};

// class Slider2 : public OutputElement{};

// class Step : public OutputElement{};

