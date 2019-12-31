#include "inputElement.h"


NoteOn::NoteOn(uint8_t note_){
    type = 0x90;
    param1 = note_;
};
