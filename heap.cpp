#include "heap.h"


using namespace std;

void Heap::InsertHeap(Puzzle* newpiece){
	data.emplace_back(newpiece);
	last++;  
	if (last==0) {return;}                                 //only one item in Heap  
	int child_index=last;   
	int par_index=0;   
	bool swapping=true;   
	while (swapping){                                      //fix the heap     
		swapping=false; 
		if(child_index%2==0) {par_index=child_index/2-1;}    //right
		else {par_index=child_index/2;}                      //left     
		if(par_index>=0){
      Puzzle* temp_child = data.at(child_index);
			Puzzle* temp_par = data.at(par_index);
			if(temp_child->getFCost() < temp_par->getFCost()){
				swap(data[child_index],data[par_index]); 
				swapping=true; 
				child_index=par_index; 
			}   
		} 
	} 
}

void Heap::DeleteRoot(){
  data[0]=data[last];
  data[last]=0;
  last--;
  //fixing the heap
  int parentindex=0;
  int leftindex=parentindex*2+1;
  int rightindex=parentindex*2+2;
  bool swapping=true;
  while(swapping){
    swapping=false;
    Puzzle* temp_left = data.at(leftindex);
    Puzzle* temp_right = data.at(rightindex);
    Puzzle* temp_par = data.at(parentindex);
    if( leftindex <= last && rightindex <= last){
      deletionComparisons++;
      if( temp_right->getFCost() > temp_left->getFCost() ){       //follow left
        deletionComparisons++;
        if(temp_left->getFCost() < temp_par->getFCost()){
          swap(data[leftindex], data[parentindex]);
          parentindex=leftindex;
          swapping=true;
        }
      } else{                                                     //OR follow right
			deletionComparisons++;
        if(temp_right->getFCost() < temp_par->getFCost()){
		  	  swap(data[rightindex], data[parentindex]);
          parentindex=rightindex;
          swapping=true;
        }
      }
    }
    else{                                                         //in this case, there is no right child, only left child
      if(leftindex<=last){
              deletionComparisons++;
        if(temp_left->getFCost() < temp_par->getFCost()){
            swap(data[leftindex], data[parentindex]);
            parentindex=leftindex;
            swapping=true;
        }
      }
    }
    leftindex=parentindex*2+1;
    rightindex=parentindex*2+2;
  }
}

bool checkHeap(Puzzle* toCompare){    //Checks if the given state is already in the heap. If given state is smaller, swap puzzle pieces
  
}

Puzzle* Heap::getRootData(){
	return data[0];
}

int Heap::getDeletionComparisons(){
	return deletionComparisons;
}