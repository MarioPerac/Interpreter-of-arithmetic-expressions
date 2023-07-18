#pragma once
#include "Node.h"
#include "Parser.h"
#include "map"
#include "AssignmentNode.h"
#include "BinaryOperationNode.h"
#include "StringNode.h"
#include "IntNode.h"


namespace Interpreter {

	class Interpreter
	{
	private:
		Parser parser;
	public:
		Interpreter(Parser parser);
		void interpret();
		bool interpretParseTree(Node* node);
		friend int interpretBinaryOperation(Node& left, string operation, Node& right);
	};
	int interpretBinaryOperation(Node& left, string operation, Node& right);
}

