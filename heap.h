#ifndef __PUZZLE_H__
#define __PUZZLE_H__
#include "puzzle2.h"
#endif

#include <iostream>
#include <vector>





using namespace std;

class Heap { 
	private: 
		vector<Puzzle2*> data;
		int last;//last index 
		int deletions; //< Number of deletion comparisons
	public: 
		Heap(){last=-1; deletions=0;}  // constructor, consider  data[i]=0 an empty slot 
		~Heap() { };//destructor 
		void InsertHeap(Puzzle2* newpiece); 
		void deleteAtIndex(int ix);
		bool checkHeap(const string& state, int fCost);		//Checks if the given state is already in the heap. If given state is smaller, swap puzzle pieces
		Puzzle2* getRootData();
		bool empty();
		int size();
		int getDeletions();
};

