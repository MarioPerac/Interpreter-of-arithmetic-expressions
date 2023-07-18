#include "Parser.h"
#include "SyntaxException.h"
#include "IntNode.h"
#include "BinaryOperationNode.h"
#include "Token.h"
#include "StringNode.h"
#include "AssignmentNode.h"
#include "PrintNode.h"

bool Interpreter::Parser::insertVariable(string variable, int value)
{
	variables.insert({ variable, value });

	return true;
}

std::map<string, int> Interpreter::Parser::getVariables() const
{
	return variables;
}

Interpreter::Parser::Parser(Lexer lexer) : lexer(lexer)
{
	next();
}

Interpreter::Node* Interpreter::Parser::expression()
{
	Node* term = this->term();

		if (token.type == "+")
		{
			next();
			Node* expression = this->expression();
			BinaryOperationNode* binOpNode = new BinaryOperationNode(term, "+", expression);
			return binOpNode;
		}
		else if (token.type == "-")
		{
			next();
			Node* newTerm = nullptr;

			if (token.type == "int" && lexer.inRangeCheck(1) && lexer.peekForOneToken().type != "*" && lexer.peekForOneToken().type != "/")
			{
				newTerm = new BinaryOperationNode(BinaryOperationNode(term, "-", this->factor()));
				delete term;
				token.type = "int";
				token.value = std::to_string(newTerm->getValue());
				return expression();

			}
			else
			{
				Node* expression = this->expression();
				BinaryOperationNode* binOpNode = new BinaryOperationNode(term, "-", expression);
				return binOpNode;
			}
		}
		else if (token.type == "=")
		{
			next();
			Node* expression = this->expression();
			AssignmentNode* assigmentNode = new AssignmentNode(term, expression);
			return assigmentNode;
		}
		else if (token.value == "print")
		{
			next();
			Node* expression = this->expression();
			PrintNode* printNode = new PrintNode(expression);
			return printNode;
			
		}
	
		return term;
}

Interpreter::Node* Interpreter::Parser::term()
{
	Node* factor = nullptr;

	if (token.type == "(")
	{
			next();
			factor = expression(); 

			if(token.type != ")")
				throw SyntaxException(token.type, lexer.getLine());

			next();
	}
	else 
	{

		factor = this->factor();

		if(token.value != "print")
			next();
	}	
	
		if (token.type == "/")
		{
			next();
			Node* newFactor = nullptr;

			if (token.type == "int")
			{
				newFactor = new BinaryOperationNode(BinaryOperationNode(factor, "/", this->factor()));
				delete factor;
				token.type = "int";
				token.value = std::to_string(newFactor->getValue());
				return term();

			}
			else
			{
				Node* term = this->term();
				BinaryOperationNode* binOpNode = new BinaryOperationNode(factor, "/", term);
				return binOpNode;
			}
		}
		else if (token.type == "*")
		{
			next();

			Node* term = this->term();
			BinaryOperationNode* binOpNode = new BinaryOperationNode(factor, "*", term);
			return binOpNode;
		}

	return factor;
}

Interpreter::Node* Interpreter::Parser::factor()
{
	if (token.type == "int")
	{
		IntNode* node = new IntNode(std::stoi(token.value));
		return node;
	}
	else if (token.type == "string")
	{
		if (token.value == "print" && lexer.inRangeCheck(1) && lexer.peekForOneToken().type != "(")
		{
			throw SyntaxException(token.type, lexer.getLine());
		}
		StringNode* node = new StringNode(token.value);

		string term = node->getString();

		if(term != "print" && variables.find(term) != variables.end())
		{
			node->setValue(variables[term]);
		}
		
		return node;
	}
	else
		throw SyntaxException(token.type, lexer.getLine());
}

Interpreter::Token Interpreter::Parser::getToken()
{
	return this->token;
}


void Interpreter::Parser::next()
{
	token = lexer.next();
}
