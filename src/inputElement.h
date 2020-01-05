#include <stdint.h>
#include <Arduino.h>

class InputElement{

    public:
        InputElement(){};
        InputElement(uint8_t type_,  uint8_t _param1);
        uint8_t type;
        uint8_t param1;
        uint8_t param2;
        uint8_t getTypeHex();
};

// class CCOn : public InputElement{};

// class CCValue : public InputElement{};

// class SysOn : public InputElement{};