#pragma once
#include "Node.h"
#include <string>
namespace Interpreter
{
	class StringNode : public Node
	{
	private:
		std::string term;
	public:
		StringNode(std::string term);
		std::string getString();
	};

}
