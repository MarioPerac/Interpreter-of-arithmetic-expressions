#include "Lexer.h"
#include <ctype.h>
#include "LexicalException.h"

namespace Interpreter {
	Lexer::Lexer()
	{
	}

	Lexer::Lexer(string input) 
	{
		source = input;
		sourcePosition = 0;
		sourceLine = 0;
		lastReadChar = ' ';
	}

	int Lexer::getLine() const
	{
		return sourceLine;
	}

	Token Lexer::peekForTwoTokens() 
	{
		if (sourcePosition + 2 < source.length())
		{
			char lastChar = lastReadChar;
			char previousLine = sourceLine;
			int previousPosition = sourcePosition;

			next();
			Token second = next();

			lastReadChar = lastChar;
			sourceLine = previousLine;
			sourcePosition = previousPosition;

			return second;
		}

		throw std::exception("Peek out of range.");

	}

	Token Lexer::peekForOneToken()
	{
		if (sourcePosition + 1 < source.length())
		{
			char lastChar = lastReadChar;
			char previousLine = sourceLine;
			int previousPosition = sourcePosition;

			Token second = next();

			lastReadChar = lastChar;
			sourceLine = previousLine;
			sourcePosition = previousPosition;

			return second;
		}

		throw std::exception("Peek out of range.");

	}

	Token Lexer::next()
	{
		while (source.length() > sourcePosition &&  isspace(source[sourcePosition]))
		{
			if (source[sourcePosition] == '\n')
				++sourceLine;

			++sourcePosition;
		}

		if (sourcePosition == source.length())
			return Token("EOF");
		else if (sourcePosition > source.length())
			throw std::exception("Out of range.");

		string buffer = "";

		if (isdigit(source[sourcePosition]))
		{
			do
			{
				buffer += source[sourcePosition];
				++sourcePosition;

			} while (source.length() > sourcePosition && isdigit(source[sourcePosition]));
			lastReadChar = source[sourcePosition - 1];
			return Token("int", buffer);
		}
		
		if (source[sourcePosition] == '*')
		{
			lastReadChar = '*';
			++sourcePosition;
			return Token("*");
		}
		
		if (source[sourcePosition] == '/')
		{
			lastReadChar = '/';
			++sourcePosition;
			return Token("/");
		}
		
		if (source[sourcePosition] == '+')
		{
			lastReadChar = '+';
			++sourcePosition;
			return Token("+");
		}

		if (source[sourcePosition] == '-') 
		{
			if (lastReadChar == '+' || lastReadChar == '-' || lastReadChar == '/' || lastReadChar == '*' || lastReadChar == '(' || lastReadChar == ' ')
			{
				++sourcePosition;

				if (isdigit(source[sourcePosition]))
				{
					do
					{
						buffer += '-';
						buffer += source[sourcePosition];
						++sourcePosition;

					} while (source.length() > sourcePosition && isdigit(source[sourcePosition]));
					lastReadChar = source[sourcePosition - 1];
					return Token("int", buffer);
				}
			}
			else
			{
				lastReadChar = '-';
				++sourcePosition;
				return Token("-");
			}
		}

		if (isalpha(source[sourcePosition]))
		{
			do
			{
				buffer += source[sourcePosition];
				++sourcePosition;

			} while (source.length() > sourcePosition && isalpha(source[sourcePosition]));
			
			lastReadChar = source[sourcePosition - 1];
			return Token("string", buffer);
		}

		if (source[sourcePosition] == ';')
		{
			lastReadChar = ';';
			++sourcePosition;
			return Token(";");
		}

		if (source[sourcePosition] == '=')
		{
			lastReadChar = '=';
			++sourcePosition;
			return Token("=");
		}

		if (source[sourcePosition] == '(')
		{
			lastReadChar = '(';
			++sourcePosition;
			return Token("(");
		}

		if (source[sourcePosition] == ')')
		{
			lastReadChar = ')';
			++sourcePosition;
			return Token(")");
		}
		
		throw LexicalException(source[sourcePosition], sourceLine);
	}

	bool Lexer::inRangeCheck(int addition)
	{
		if (sourcePosition + addition < source.length())
			return true;

		return false;
	}
}

