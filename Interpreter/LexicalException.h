#pragma once
#include <exception>
class LexicalException : public std::exception
{
private:
	char* message;
	char unexpected_Character;
	int line_exception;
public:
	LexicalException(char unexpected_char, int line);
	~LexicalException();
	virtual const char* what() const throw();
		
};

