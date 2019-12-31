#include <stdint.h>


class InputElement{

    public:
        uint8_t type;
        uint8_t param1;
        uint8_t param2;
};

class NoteOn : public InputElement{

    public:
        NoteOn(uint8_t note_);
        uint8_t note;
        
};

class CCOn : public InputElement{};

class CCValue : public InputElement{};

class SysOn : public InputElement{};