#include <iostream>
#include <string>

class TextInput
{
public:
    virtual void add(char c)
    {
        buf_ += c;
    }

    std::string getValue()
    {
        return buf_;
    }

private:

    std::string buf_;
};

class NumericInput : public TextInput
{
public:

    void add(char c) override
    {
        if(!std::isdigit(c))
        {
            return;
        }

        TextInput::add(c);
    }
};

int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}

