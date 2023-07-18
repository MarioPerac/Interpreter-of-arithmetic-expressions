#pragma once
#include "Node.h"

namespace Interpreter {

	class BinaryOperationNode : public Node
	{
	private:
		Node* left; 
		string operation;
		Node* right;
	public:
		BinaryOperationNode(Node* left, string operation, Node* right);
		~BinaryOperationNode();
	};
}
