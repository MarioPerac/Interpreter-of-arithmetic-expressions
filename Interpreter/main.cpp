#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"

int main()
{
	try {
	

		string source {"5 + 4;a = 25 * 3 + 7 + 2 * -1 + 5; b =\n52 - 25 - 1\n; 25;\nprint(a);\nc = (((a))) + (-3 + b * (b +\na)) / 2;\nprint(b); print(c);"};

		Interpreter::Lexer lexer(source);
		Interpreter::Parser parser(lexer);
		Interpreter::Interpreter interpreter(parser);

		interpreter.interpret();
	
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
		return 0;
}
