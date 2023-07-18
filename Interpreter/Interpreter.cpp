#include "Interpreter.h"
#include <exception>
#include "AssignmentNode.h"
#include "BinaryOperationNode.h"
#include "IntNode.h"
#include "PrintNode.h"
#include "StringNode.h"
#include <iostream>

int Interpreter::interpretBinaryOperation(Node& left, string operation, Node& right)
{
	if (operation == "+")
	{
		return left.getValue() + right.getValue();
	}
	else if(operation == "-")
	{
		return left.getValue() - right.getValue();
	}
	else if (operation == "*")
	{
		return left.getValue() * right.getValue();
	}
	else if (operation == "/")
	{
		if (right.getValue() != 0)
		{
			return left.getValue() / right.getValue();
		}
		else
		{
			throw std::exception("Division by zero!");
		}
	}
	
	throw std::exception("Semantic error.");
}

Interpreter::Interpreter::Interpreter(Parser parser) : parser(parser)
{
}

void Interpreter::Interpreter::interpret()
{
	Node* node = nullptr;

	while (parser.getToken().type != "EOF") 
	{
		
		if (parser.getToken().type != ";")
		{
			node = parser.expression(); 
			
		}
		else if(parser.getToken().type == ";")
		{
			if (interpretParseTree(node)) 
			{
				parser.next();
			}
		
		}
		else
		{
			throw std::exception("Missing terminator.");
		}

	}

	delete node;
}

bool Interpreter::Interpreter::interpretParseTree(Node* node)
{
	AssignmentNode* assignemetNode = dynamic_cast<AssignmentNode*>(node);

	if ( assignemetNode != nullptr)
	{
		parser.insertVariable(assignemetNode->getValueString(), assignemetNode->getValue());

		return true;
	}

	BinaryOperationNode* binOpNode = dynamic_cast<BinaryOperationNode*>(node);

	if (binOpNode != nullptr)
	{
		return true;
	}


	IntNode* intNode = dynamic_cast<IntNode*>(node);

	if (intNode != nullptr)
	{
		return true;
	}


	StringNode* stringNode = dynamic_cast<StringNode*>(node);

	if (stringNode != nullptr)
	{
		return true;
	}

	PrintNode* printNode = dynamic_cast<PrintNode*>(node);

	if (printNode != nullptr)
	{
		std::map<string, int> variables = parser.getVariables();

		if (variables.find(printNode->getValueString()) != variables.end())
		{
			std::cout << variables[printNode->getValueString()] << std::endl;
		}
		else
		{
			std::cout << printNode->getValueString() << std::endl;
		}
		return true;
	}

	return false; 
}
