#include <iostream>

using namespace std;

class Node{
	private:
		Node * next;
		string state;

	public:
		Node(const string& newstate);
};

