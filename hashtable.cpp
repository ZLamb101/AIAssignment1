#include <iostream>
#include "hashtable.h"

using namespace std;

HashTable::HashTable(){
	for(int i = 0; i < 370000; i++){
		table[i] = nullptr;
	}
}



bool HashTable::checkHash(const string &state){ // Return value tells us if the state will be added to the Q (true == add)
	int val = stoi(state);
	val %= 370000;
	if(table[val] == nullptr){ // State not found, adding to hash table & Q
		table[val] = new Node(state);
		return true;
	} else {
		if(checkList(table[val], state)){
			// State in list, do not add to Q
			return false;
		} else {
			// State not in list, adding to list and Q
			Node* ptr = table[val];
			while(ptr->next != nullptr){
				ptr = ptr->next;
			}
			Node* temp = new Node(state);
			ptr->next = temp;
			return true;
		}
	}
}

bool HashTable::checkList(Node* ptr, const string &state){
	do{
		if(ptr->state == state){
			return true; // Is in list
		}
		ptr = ptr->next;
	} while(ptr != nullptr)
	return false; // Is not in list
}