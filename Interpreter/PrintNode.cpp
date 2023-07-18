#include "PrintNode.h"
#include <iostream>

Interpreter::PrintNode::PrintNode(Node* valueNode) : valueNode(valueNode)
{
	valueString = this->valueNode->getValueString();
}

Interpreter::PrintNode::~PrintNode()
{
	delete valueNode;
}

