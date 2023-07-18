#pragma once
#include "Token.h"
#include <string>
using string = std::string;


namespace Interpreter {

	class Lexer
	{
	private:
		string source;
		int sourcePosition;
		int sourceLine;
		char lastReadChar;
	public:
		Lexer();
		Lexer(string input);
		int getLine() const; 
		Token next();
		Token peekForTwoTokens();
		Token peekForOneToken();
		bool inRangeCheck(int addition);


	};
}

