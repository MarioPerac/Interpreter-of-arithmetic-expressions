#include "LexicalException.h"
#include <string>
#include <iostream>


LexicalException::LexicalException(char unexpected_char, int line) : unexpected_Character(unexpected_char), line_exception(line)
{
	std::string message = "Unexpected character: ";
	message.push_back(unexpected_Character);
	message += " in line ";
	message += std::to_string(line_exception);

	this->message = new char[message.size() + 1];
	std::copy(message.begin(), message.end(), this->message);
	this->message[message.size()] = '\0';
}

LexicalException::~LexicalException()
{
	delete[] message;
}


const char* LexicalException::what() const throw()
{
	return message;
}
