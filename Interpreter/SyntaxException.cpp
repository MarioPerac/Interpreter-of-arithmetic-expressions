#include "SyntaxException.h"

SyntaxException::SyntaxException(std::string unexpectedExp, int line)
{
	std::string message = "Unexpected character: " + unexpectedExp;
	message += " in line ";
	message += std::to_string(line_exception);

	this->message = new char[message.size() + 1];
	std::copy(message.begin(), message.end(), this->message);
	this->message[message.size()] = '\0';
}

SyntaxException::~SyntaxException()
{
	delete[] message;
}

const char* SyntaxException::what() const throw()
{
	return message;
}
