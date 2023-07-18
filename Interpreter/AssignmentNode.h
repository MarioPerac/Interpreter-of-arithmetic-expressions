#pragma once
#include "Node.h"
#include "StringNode.h"

namespace Interpreter
{
	class AssignmentNode :	public Node
	{
	private:
		Node* variable;
		Node* valueNode;
	public:
		AssignmentNode(Node* variable, Node* valueNode);
		~AssignmentNode();
	};
}

