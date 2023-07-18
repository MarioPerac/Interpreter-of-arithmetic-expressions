#pragma once
#include <string>
using std::string;

namespace Interpreter 
{
	class Node {
	protected:
		int value;
		string valueString;
	public:
		
		void setValue(int value);
		string getValueString() const;
		virtual int getValue() const;
	};

}
