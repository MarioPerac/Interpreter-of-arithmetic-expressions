#include "IntNode.h"

Interpreter::IntNode::IntNode(int intValue) 
{
	this->value = intValue;
	valueString = std::to_string(this->value);
}
