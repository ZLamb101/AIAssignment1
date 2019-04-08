#include <iostream>
#include "node.h"

using namespace std;

class HashTable{
	
	private:
		Node* table[370000];

	public:
		HashTable();
		~HashTable();

		bool checkHash(const string &state);
		bool checkList(Node* ptr, const string &state);
		bool checkHashNoAdd(const string &state);
};