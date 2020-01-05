#include "inputElement.h"
#include "outputElement.h"
#include "commands.h"
#include "midievents.h"
#include <usbmidi.h>
#include <Arduino.h>
#include <stdint.h>

class Mapping{

public:
    Mapping(){};
    Mapping(InputElement input_, OutputElement output_){
        input = input_;
        output = output_;
    };
    InputElement input;
    OutputElement output;
};

class MidiMessage{
    public:
        uint8_t command = 0;
        uint8_t channel = 0;
        uint8_t param1 = 0;
        uint8_t param2 = 0;
};

class Transcriber{

public:
    void begin(bool useUsbClient=true, bool useSerial=false, bool useUsbHost=false);
    void update();

    template <class in, class out>
    void map (in input, out output){
        mappingList[mappingIndex] = Mapping(input, output);
        mappingIndex++;
    }


    // void map(InputElement &input, OutputElement &output);

    MidiMessage readMidiInput();
    int checkMap(MidiMessage midi_message);
    void callOutputCommand(int matchedIndex, uint8_t midiParam1);
    void serialWrite(char cmd[]);
    void serialWriteParam(char cmd[], uint8_t param);

    Mapping mappingList[50];
    int mappingIndex = 0;
};

