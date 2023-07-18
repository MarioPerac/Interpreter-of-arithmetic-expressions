#include "BinaryOperationNode.h"
#include "Interpreter.h"

Interpreter::BinaryOperationNode::BinaryOperationNode(Node* left, string operation, Node* right) : operation(operation)
{
	this->left = left;
	this->right = right;
	this->value = interpretBinaryOperation(*left, operation, *right);
	valueString = std::to_string(this->value);
}

Interpreter::BinaryOperationNode::~BinaryOperationNode()
{
	delete left;
	delete right;
}




