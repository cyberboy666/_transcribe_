#include <stdint.h>
#include <Arduino.h>

class OutputElement{
    public:
        virtual String getCommand(){};
};

class Button : public OutputElement{ 

public:
    Button(String command);
    String getCommand() override;
    String cmd;

};

// class Switch : public OutputElement{};

// class Slider : public OutputElement{};

// class Slider2 : public OutputElement{};

// class Step : public OutputElement{};

