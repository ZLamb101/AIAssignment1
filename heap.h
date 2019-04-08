#include <iostream>

using namespace std;

class Heap { 
	private: 
		vector<Puzzle*> data;
		int last;//last index 
		int deletionComparisons; //< Number of deletion comparisons
	public: 
		Heap(){last=-1; insertComparisons = 0; deletionComparisons=0;}  // constructor, consider  data[i]=0 an empty slot 
		~Heap() { };//destructor 
		void InsertHeap(Puzzle* newpiece); 
		void DeleteRoot(); 
		Puzzle* getRootData();
		int getDeletionComparisons();
};