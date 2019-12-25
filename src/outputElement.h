
class OutputElement{};

class Button : public OutputElement{ 

private:
    char cmd[8];

public:
    Button(char command[8]);
};

class Switch : public OutputElement{};

class Slider : public OutputElement{};

class Slider2 : public OutputElement{};

class Step : public OutputElement{};

