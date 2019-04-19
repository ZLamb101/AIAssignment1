#ifndef __PUZZLE_H__
#define __PUZZLE_H__
#include "puzzle2.h"
#endif

#include <iostream>
#include <vector>





using namespace std;


/*
 * A min heap that stores puzzle pieces in order defined by their corresponding heuristic values
 * To be used in the A* and Uniform Cost algorithms
 */


class Heap { 
	private: 
		vector<Puzzle2*> data;
		int last;											// Position of the last element as an index
		int deletions; 										// Number of deletion comparisons
	public: 
		Heap(){last=-1; deletions=0;}
		~Heap() { };
		void InsertHeap(Puzzle2* newpiece); 				// Inserts a new puzzle piece into the correct position in the heap
		void deleteAtIndex(int ix);							// Deletes the puzzle piece at a given index and re-arranges heap accordingly
		bool checkHeap(const string& state, int fCost);		// Checks if the given state is already in the heap. If given state is smaller, swap puzzle pieces
		Puzzle2* getRootData();								// Returns the puzzle piece at the root
		bool empty();										// Checks if the heap is empty
		int size();											// Returns the size of the heap
		int getDeletions();									// Returns the number of deletions
};

