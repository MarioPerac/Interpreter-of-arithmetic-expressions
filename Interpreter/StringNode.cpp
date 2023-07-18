#include "StringNode.h"

Interpreter::StringNode::StringNode(std::string term) : term(term)
{
	valueString = this->term;
}

std::string Interpreter::StringNode::getString()
{
	return term;
}
