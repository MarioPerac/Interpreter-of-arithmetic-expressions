#pragma once
#include <exception>
#include <string>
class SyntaxException : public std::exception
{
private:
	char* message;
	std::string unexpectedExpression;
	int line_exception;
public:
	SyntaxException(std::string unexpectedExp, int line);
	~SyntaxException();
	virtual const char* what() const throw();
};

