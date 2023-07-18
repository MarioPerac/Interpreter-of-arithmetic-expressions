#pragma once
#include <string>
using string = std::string;


namespace Interpreter {

	class Token
	{
	public:
		string type;
		string value;
		Token();
		Token(string type, string value = ""); 
		
	};
}


