#include <iostream>
#include "node.h"

using namespace std;

Node::Node(const string& newstate){
	state = newstate;
	next = nullptr;
}