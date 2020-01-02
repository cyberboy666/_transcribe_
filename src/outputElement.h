#include <stdint.h>
#include <Arduino.h>

class OutputElement{
    public:
        OutputElement(){};
        OutputElement(char type_[8],  char cmd_[8]);
        char type[8];
        char cmd[8];
        void getCmd(char *buf);
};

// class Switch : public OutputElement{};

// class Slider : public OutputElement{};

// class Slider2 : public OutputElement{};

// class Step : public OutputElement{};

