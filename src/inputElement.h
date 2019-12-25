
class InputElement{};

class NoteOn : public InputElement{

private:
    int note;

public:
    NoteOn(int note_);
};

class CCOn : public InputElement{};

class CCValue : public InputElement{};

class SysOn : public InputElement{};