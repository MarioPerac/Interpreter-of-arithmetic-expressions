#include "AssignmentNode.h"

Interpreter::AssignmentNode::AssignmentNode(Node* variable, Node* valueNode) : variable(variable), valueNode(valueNode)
{
	this->value = valueNode->getValue();
	valueString = variable->getValueString();
}

Interpreter::AssignmentNode::~AssignmentNode()
{
	delete variable;
	delete valueNode;
}


