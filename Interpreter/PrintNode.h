#pragma once
#include "Node.h"

namespace Interpreter
{
  class PrintNode : public Node
  { 
  private:
	  Node* valueNode;
  public:
	  PrintNode(Node* valueNode);
	  ~PrintNode();
  };
}


