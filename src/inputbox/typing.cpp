#include <inputbox.hpp>

std::string InputBox::getText(int index)
{
    return inputs[index]->getText();
}

void InputBox::setText(int index, std::string text)
{
    if (index != -1 && index < (int) inputs.size())
    {
        inputs[index]->typing(text);
    }
}

void InputBox::setText(std::string text)
{
    if (typingIndex != -1)
    {
        inputs[typingIndex]->typing(text);
    }
}

