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

void Heap::deleteAtIndex(int ix){
  data[ix]=data[last];
  data[last]=0;
  last--;
  //fixing the heap

  int parentindex = ix/2;
  Puzzle* temp_current = data[ix];
  Puzzle* temp_parent = data[parentindex];
  if(ix == 0 || temp_parent->getFCost() < temp_current->getFCost()){ // Filter down
	  int leftindex = ix*2+1;
	  int rightindex = ix*2+2;
	  bool swapping=true;
	  while(swapping){
	    swapping=false;
	    Puzzle* temp_left = data.at(leftindex);
	    Puzzle* temp_right = data.at(rightindex);
	    Puzzle* temp_par = data.at(ix);
	    if( leftindex <= last && rightindex <= last){
	      deletionComparisons++;
	      if( temp_right->getFCost() > temp_left->getFCost() ){       //follow left
	        deletionComparisons++;
	        if(temp_left->getFCost() < temp_par->getFCost()){
	          swap(data[leftindex], data[ix]);
	          ix=leftindex;
	          swapping=true;
	        }
	      } else{                                                     //OR follow right
			deletionComparisons++;
	        if(temp_right->getFCost() < temp_par->getFCost()){
			  	swap(data[rightindex], data[ix]);
	          	ix=rightindex;
	          	swapping=true;
	        }
	      }
	    }
	    else{                                                         //in this case, there is no right child, only left child
	      if(leftindex<=last){
	              deletionComparisons++;
	        if(temp_left->getFCost() < temp_par->getFCost()){
	            swap(data[leftindex], data[ix]);
	            ix=leftindex;
	            swapping=true;
	        }
	      }
	    }
	    leftindex = ix*2+1;
	    rightindex = ix*2+2;
	  }
	} else { // Filter up
		while(ix != 0){
			parentindex = ix/2;
			temp_current = data[ix];
			temp_parent = data[parentindex];
			if(temp_current->getFCost() < temp_parent->getFCost()){
				swap(data[ix], data[parentindex]);
				ix = parentindex;
			} else {
				break;
			}
		}
	}
}


// Return false to insert the value, return true to not insert.
bool Heap::checkHeap(const string& state, int fCost){    //Checks if the given state is already in the heap. If given state is smaller, swap puzzle pieces
  for(int i = 0; i < data.size(); i++){
  	Puzzle* temp = data.at(i);
  	if(temp->toString() == state){
  		if(temp->getFCost() <= fCost){
  			return true;
  		} else{
  			deleteAtIndex(i);
  			return false;
  		}
  	}
  }
  return false; // Must insert
}

Puzzle* Heap::getRootData(){
	return data[0];
}

int Heap::getDeletionComparisons(){
	return deletionComparisons;
}