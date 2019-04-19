#include <iostream>
#include "node.h"

using namespace std;

/*
 * Utilized for fast look up of given states
 * No hashing function required due to all states being unique numbers already
 * Collisions avoided by using a linked list at each given index
 */

class HashTable{
	
	private:
		Node* table[370000];	// An array of Node pointers

	public:
		HashTable();
		~HashTable();

		bool checkHash(const string &state);					// Checks if given state has already been visited. If it hasn't, add it
		bool checkList(Node* ptr, const string &state);			// If a collision occured, checks the linked list associated with the given index
		bool checkHashNoAdd(const string &state);				//Checks if given state has already been visited. Do not add
};