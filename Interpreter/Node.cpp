#include "Node.h"

void Interpreter::Node::setValue(int value)
{
    this ->value = value;
}

string Interpreter::Node::getValueString() const
{
    return valueString;
}

int Interpreter::Node::getValue() const
{
    return value;
}
