
#include "hashtable.h"
#include "algorithm.h"
#include "heap.h"
#include <queue>
#include <stack>
using namespace std;



///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Breadth-First Search 
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string breadthFirstSearch(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime){
    string path;
	clock_t startTime;
	startTime = clock();
	Puzzle * currentState = new Puzzle(initialState, goalState);
	Puzzle * nextState;
	queue<Puzzle*>  *Q = new queue<Puzzle*>();
	numOfStateExpansions = 0;
	maxQLength = 0;
	bool noResult = false;
	while(!currentState->goalMatch()){
		numOfStateExpansions++;
		if(currentState->canMoveUp()){
			nextState = currentState->moveUp();
			if(!currentState->checkExpansionPath(nextState->toString())){
				Q->push(nextState);
			} else{
				delete nextState;
			}
		}
		if(currentState->canMoveRight()){
			nextState = currentState->moveRight();
			if(!currentState->checkExpansionPath(nextState->toString())){
				Q->push(nextState);
			} else{
				delete nextState;
			}
		}
		if(currentState->canMoveDown()){
			nextState = currentState->moveDown();
			if(!currentState->checkExpansionPath(nextState->toString())){
				Q->push(nextState);
			} else{
				delete nextState;
			}
		}
		if(currentState->canMoveLeft()){
			nextState = currentState->moveLeft();
			if(!currentState->checkExpansionPath(nextState->toString())){
				Q->push(nextState);
			} else{
				delete nextState;
			}
		}
		if(Q->size() == 0){
			noResult = true;
			break;
		}
		if(Q->size() > maxQLength){
			maxQLength = Q->size();
		}
		delete currentState;
		currentState = Q->front();
		Q->pop();
	}
	
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	if(noResult){
		path = "";
	} else{
		path = currentState->getPath();
	}           
	return path;			
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Breadth-First Search with VisitedList
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string breadthFirstSearch_with_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime){
    string path;
	clock_t startTime;
	startTime = clock();
	Puzzle * currentState = new Puzzle(initialState, goalState);
	Puzzle * nextState;
	queue<Puzzle*>  *Q = new queue<Puzzle*>();
	HashTable *VisitedList = new HashTable();
	numOfStateExpansions = 0;
	maxQLength = 0;
	bool noResult = false;
	while(!currentState->goalMatch()){
		numOfStateExpansions++;
		if(currentState->canMoveUp()){
			nextState = currentState->moveUp();
			if(!currentState->checkExpansionPath(nextState->toString())){
				if(VisitedList->checkHash(nextState->toString())){
					Q->push(nextState);
				}
			}
		}
		if(currentState->canMoveRight()){
			nextState = currentState->moveRight();
			if(!currentState->checkExpansionPath(nextState->toString())){
				if(VisitedList->checkHash(nextState->toString())){
					Q->push(nextState);
				}
			}
		}
		if(currentState->canMoveDown()){
			nextState = currentState->moveDown();
			if(!currentState->checkExpansionPath(nextState->toString())){
				if(VisitedList->checkHash(nextState->toString())){
					Q->push(nextState);
				}
			}
		}
		if(currentState->canMoveLeft()){
			nextState = currentState->moveLeft();
			if(!currentState->checkExpansionPath(nextState->toString())){
				if(VisitedList->checkHash(nextState->toString())){
					Q->push(nextState);
				}
			}
		}
		if(Q->size() == 0){
			noResult = true;
			break;
		}
		if(Q->size() > maxQLength){
			maxQLength = Q->size();
		}
		delete currentState;
		currentState = Q->front();
		Q->pop();
	}
	
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	if(noResult){
		path = "";
	} else{
		path = currentState->getPath();
	}           
	return path;
}
	

bool isVisited(const vector<string> *VisitedList, const string &state){
	if (find(VisitedList->begin(), VisitedList->end(), state) != VisitedList->end() ){
		return true;
	} else {
		return false;
	}
}


string progressiveDeepeningSearch_No_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int ultimateMaxDepth){
	string path;
	clock_t startTime;
	startTime = clock();
	Puzzle * currentState = new Puzzle(initialState, goalState);
	Puzzle * nextState;
	stack<Puzzle*>  *Q = new stack<Puzzle*>();
	numOfStateExpansions = 0;
	maxQLength = 0;
	int C = 1;
	while(!currentState->goalMatch()){
		numOfStateExpansions++;
		if(currentState->canMoveUp(C)){
			nextState = currentState->moveUp();
			if(!currentState->checkExpansionPath(nextState->toString())){
					Q->push(nextState);
			}
		}
		if(currentState->canMoveRight(C)){
			nextState = currentState->moveRight();
			if(!currentState->checkExpansionPath(nextState->toString())){
					Q->push(nextState);
			}
		}
		if(currentState->canMoveDown(C)){
			nextState = currentState->moveDown();
			if(!currentState->checkExpansionPath(nextState->toString())){
					Q->push(nextState);
			}
		}
		if(currentState->canMoveLeft(C)){
			nextState = currentState->moveLeft();
			if(!currentState->checkExpansionPath(nextState->toString())){
					Q->push(nextState);
			}
		}
		if(Q->size() > maxQLength){
			maxQLength = Q->size();
		}
		if(Q->empty()){
			C++;
			if(C > 50){
				break;
			}
			delete currentState;
			currentState = new Puzzle(initialState, goalState);
			continue;
		}
		delete currentState;
		currentState = Q->top();
		Q->pop();
	}
	if(C > 50){
		path = "";
	} else{
		path = currentState->getPath();
	} 
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);   
	return path;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string uniformCost_ExpandedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, 
                               float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions){
											 
   string path;
   clock_t startTime;
   
   numOfDeletionsFromMiddleOfHeap=0;
   numOfLocalLoopsAvoided=0;
   numOfAttemptedNodeReExpansions=0;
	actualRunningTime=0.0;	
	startTime = clock();
	Puzzle * currentState = new Puzzle(initialState, goalState);
    Puzzle * nextState;
    Heap  *Q = new Heap();
    HashTable *ExpandedList = new HashTable();
    numOfStateExpansions = 0;
    maxQLength = 0;
    bool noResult = false;
	while(!currentState->goalMatch()){
		if(!ExpandedList->checkHash(currentState->toString())){
			// State has previously been expanded
			delete currentState;
			if(Q->empty()){
				noResult = true;
				break;
			}
			// Find next best cost
			currentState = Q->getRootData();
			Q->deleteAtIndex(0);
			continue;
		} else {
			numOfStateExpansions++;
			if(currentState->canMoveUp()){
				nextState = currentState->moveUp();
				if(!currentState->checkExpansionPath(nextState->toString())){
					if(ExpandedList->checkHashNoAdd(nextState->toString())){
						nextState->updateFCost();
						if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
							Q->InsertHeap(nextState);
						}
					}
				}
			}
			if(currentState->canMoveRight()){
				nextState = currentState->moveRight();
				if(!currentState->checkExpansionPath(nextState->toString())){
					if(ExpandedList->checkHashNoAdd(nextState->toString())){
						nextState->updateFCost();
						if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
							Q->InsertHeap(nextState);
						}
					}
				}
			}
			if(currentState->canMoveDown()){
				nextState = currentState->moveDown();
				if(!currentState->checkExpansionPath(nextState->toString())){
					if(ExpandedList->checkHashNoAdd(nextState->toString())){
						nextState->updateFCost();
						if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
							Q->InsertHeap(nextState);
						}
					}
				}
			}
			if(currentState->canMoveLeft()){
				nextState = currentState->moveLeft();
				if(!currentState->checkExpansionPath(nextState->toString())){
					if(ExpandedList->checkHashNoAdd(nextState->toString())){
						nextState->updateFCost();
						if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
							Q->InsertHeap(nextState);
						}
					}
				}
			}
			if(Q->size() > maxQLength){
				maxQLength = Q->size();
			}
			delete currentState;
			if(Q->empty()){
				noResult = true;
				break;
			}
			// Find next best cost
			currentState = Q->getRootData();
			Q->deleteAtIndex(0);
		}
	}

//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	if(noResult){
		path = "";
	} else{	
		path = currentState->getPath();  
	}       
	return path;				
}




///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string aStar_ExpandedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, 
                               float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions, heuristicFunction heuristic){
											 
    string path;
    clock_t startTime;
    numOfDeletionsFromMiddleOfHeap=0;
    numOfLocalLoopsAvoided=0;
    numOfAttemptedNodeReExpansions=0;
	actualRunningTime=0.0;	
	startTime = clock();
	Puzzle * currentState = new Puzzle(initialState, goalState);
    Puzzle * nextState;
    Heap  *Q = new Heap();
    HashTable *ExpandedList = new HashTable();
    numOfStateExpansions = 0;
    maxQLength = 0;
    bool noResult = false;
	while(!currentState->goalMatch()){
		if(!ExpandedList->checkHash(currentState->toString())){
			// State has previously been expanded
			delete currentState;
			if(Q->empty()){
				noResult = true;
				break;
			}
			// Find next best cost
			currentState = Q->getRootData();
			Q->deleteAtIndex(0);
			continue;
		} else {
			numOfStateExpansions++;
			if(currentState->canMoveUp()){
				nextState = currentState->moveUp();
				if(!currentState->checkExpansionPath(nextState->toString())){
					if(ExpandedList->checkHashNoAdd(nextState->toString())){
						nextState->updateHCost(heuristic);
						nextState->updateFCost();
						if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
							Q->InsertHeap(nextState);
						}
					}
				}
			}
			if(currentState->canMoveRight()){
				nextState = currentState->moveRight();
				if(!currentState->checkExpansionPath(nextState->toString())){
					if(ExpandedList->checkHashNoAdd(nextState->toString())){
						nextState->updateHCost(heuristic);
						nextState->updateFCost();
						if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
							Q->InsertHeap(nextState);
						}
					}
				}
			}
			if(currentState->canMoveDown()){
				nextState = currentState->moveDown();
				if(!currentState->checkExpansionPath(nextState->toString())){
					if(ExpandedList->checkHashNoAdd(nextState->toString())){
						nextState->updateHCost(heuristic);
						nextState->updateFCost();
						if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
							Q->InsertHeap(nextState);
						}
					}
				}
			}
			if(currentState->canMoveLeft()){
				nextState = currentState->moveLeft();
				if(!currentState->checkExpansionPath(nextState->toString())){
					if(ExpandedList->checkHashNoAdd(nextState->toString())){
						nextState->updateHCost(heuristic);
						nextState->updateFCost();
						if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
							Q->InsertHeap(nextState);
						}
					}
				}
			}
			if(Q->size() > maxQLength){
				maxQLength = Q->size();
			}
			delete currentState;
			if(Q->empty()){
				noResult = true;
				break;
			}
			// Find next best cost
			currentState = Q->getRootData();
			Q->deleteAtIndex(0);
		}
	}
//***********************************************************************************************************
	numOfDeletionsFromMiddleOfHeap = Q->getDeletions();
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	if(noResult){
		path = "";
	} else {	
		path = currentState->getPath();  
	}       
	return path;	
}




