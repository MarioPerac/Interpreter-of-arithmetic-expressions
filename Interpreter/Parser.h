#pragma once
#include "Lexer.h"
#include "Node.h"
#include <map>

namespace Interpreter {

	class Parser
	{
	private:
		Lexer lexer;
		Token token;
		std::map<string, int> variables;
	public:
		std::map<string, int> getVariables() const;
		bool insertVariable(string variable, int value);
		Parser(Lexer lexer);
		Node* expression();
		Node* term();
		Node* factor();
		Token getToken();
		void next();

	};
}


