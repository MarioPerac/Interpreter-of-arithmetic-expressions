#include "Token.h"

Interpreter::Token::Token()
{
}

Interpreter::Token::Token(string type, string value) : type(type), value(value)
{
}
