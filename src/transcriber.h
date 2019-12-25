#include "inputElement.h"
#include "outputElement.h"
#include "commands.h"
#include "midievents.h"
#include <MIDIUSB.h>

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

class Transcriber{

public:
    void begin(bool useUsbClient=true, bool useSerial=false, bool useUsbHost=false);
    void update();

    void map(InputElement input, OutputElement output);

    void callMap(midiEventPacket_t rx);
    void serialWrite(String cmd);

    Mapping mappingList[20];
    int mappingIndex = 0;
};

