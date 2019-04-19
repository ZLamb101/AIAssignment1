
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
	// Loop until the goal state is found or the Queue is empty
	while(!currentState->goalMatch()){
		numOfStateExpansions++;
		/*
		 * For all four directions:
		 * Checks if a given move is possible
		 * If so, checks whether it is on the puzzle pieces' path
		 * If not, add to the queue
		 */
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
		//If the queue is empty, there is no solution so break out of the loop
		if(Q->size() == 0){
			noResult = true;
			break;
		}
		//If the Q is bigger than previously recorded max length, replace max length
		if(Q->size() > maxQLength){
			maxQLength = Q->size();
		}
		delete currentState;
		//Get the new state to expand from the front of the queue and delete it from the queue
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
	Puzzle2 * currentState = new Puzzle2(initialState, goalState);
	Puzzle2 * nextState;
	queue<Puzzle2*>  *Q = new queue<Puzzle2*>();
	HashTable *VisitedList = new HashTable();
	numOfStateExpansions = 0;
	maxQLength = 0;
	bool noResult = false;
	// Loop until the goal state is found or the Queue is empty
	while(!currentState->goalMatch()){
		numOfStateExpansions++;
		/*
		 * For all four directions:
		 * Checks if a given move is possible
		 * If so, checks whether the state has been visited by looking it up in the hash table
		 * If not, add to the queue
		 */
		if(currentState->canMoveUp()){
			nextState = currentState->moveUp();
			if(VisitedList->checkHash(nextState->toString())){
				Q->push(nextState);
			} else{
				delete nextState;
			}
		}
		if(currentState->canMoveRight()){
			nextState = currentState->moveRight();
			if(VisitedList->checkHash(nextState->toString())){
				Q->push(nextState);
			} else{
				delete nextState;
			}
		}
		if(currentState->canMoveDown()){
			nextState = currentState->moveDown();
			if(VisitedList->checkHash(nextState->toString())){
				Q->push(nextState);
			} else{
				delete nextState;
			}
		}
		if(currentState->canMoveLeft()){
			nextState = currentState->moveLeft();
			if(VisitedList->checkHash(nextState->toString())){
				Q->push(nextState);
			} else{
				delete nextState;
			}
		}
		//If the queue is empty, there is no solution so break out of the loop
		if(Q->size() == 0){
			noResult = true;
			break;
		}
		//If the Q is bigger than previously recorded max length, replace max length
		if(Q->size() > maxQLength){
			maxQLength = Q->size();
		}
		//Get the new state to expand from the front of the queue and delete it from the queue
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
// Search Algorithm:  Progressive Deepening Search No Visited List
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string progressiveDeepeningSearch_No_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int ultimateMaxDepth){
	string path;
	clock_t startTime;
	startTime = clock();
	Puzzle * currentState = new Puzzle(initialState, goalState);
	Puzzle * nextState;
	stack<Puzzle*>  *Q = new stack<Puzzle*>();
	numOfStateExpansions = 0;
	maxQLength = 0;
	// Set the Current depth to 1
	int C = 1;
	// Loop until the goal state is found or the Queue is empty
	while(!currentState->goalMatch()){
		numOfStateExpansions++;
		/*
		 * For all four directions:
		 * Checks if a given move is possible
		 * If so, checks whether the state has been expanded
		 * If not, add to the queue
		 */
		if(currentState->canMoveUp(C)){
			nextState = currentState->moveUp();
			if(!currentState->checkExpansionPath(nextState->toString())){
					Q->push(nextState);
			} else{
				delete nextState;
			}
		}
		if(currentState->canMoveRight(C)){
			nextState = currentState->moveRight();
			if(!currentState->checkExpansionPath(nextState->toString())){
					Q->push(nextState);
			} else{
				delete nextState;
			}
		}
		if(currentState->canMoveDown(C)){
			nextState = currentState->moveDown();
			if(!currentState->checkExpansionPath(nextState->toString())){
					Q->push(nextState);
			} else{
				delete nextState;
			}
		}
		if(currentState->canMoveLeft(C)){
			nextState = currentState->moveLeft();
			if(!currentState->checkExpansionPath(nextState->toString())){
					Q->push(nextState);
			} else{
				delete nextState;
			}
		}
		//If the Q is bigger than previously recorded max length, replace max length
		if(Q->size() > maxQLength){
			maxQLength = Q->size();
		}
		//If Q is empty, check whether the current depth exceeds the max depth (50). If so break, otherwise reset to original state
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
// Search Algorithm:  Uniform Cost with Expanded List
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
	Puzzle2 * currentState = new Puzzle2(initialState, goalState);
    Puzzle2 * nextState;
    Heap  *Q = new Heap();
    HashTable *ExpandedList = new HashTable();
    numOfStateExpansions = 0;
    maxQLength = 0;
    bool noResult = false;
    // Loop until the goal state is found or the Queue is empty
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
			/*
			 * For all four directions:
			 * Checks if a given move is possible
			 * If so, checks whether the state has been visited in the hashtable
			 * Updates the FCost
			 * Checks the heap for the given state and chooses the one with the best cost to keep
			 * If it's not in the heap, insert it
			 */
			if(currentState->canMoveUp()){
				nextState = currentState->moveUp();
				if(ExpandedList->checkHashNoAdd(nextState->toString())){
					nextState->updateFCost();
					if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
						Q->InsertHeap(nextState);
					} else{
						delete nextState;
					}
				}  else {
					delete nextState;
				}
			}
			if(currentState->canMoveRight()){
				nextState = currentState->moveRight();
				if(ExpandedList->checkHashNoAdd(nextState->toString())){
					nextState->updateFCost();
					if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
						Q->InsertHeap(nextState);
					} else{
						delete nextState;
					}
				}  else {
					delete nextState;
				}
			}
			if(currentState->canMoveDown()){
				nextState = currentState->moveDown();
				if(ExpandedList->checkHashNoAdd(nextState->toString())){
					nextState->updateFCost();
					if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
						Q->InsertHeap(nextState);
					} else{
						delete nextState;
					}
				}  else {
					delete nextState;
				}
			}
			if(currentState->canMoveLeft()){
				nextState = currentState->moveLeft();
				if(ExpandedList->checkHashNoAdd(nextState->toString())){
					nextState->updateFCost();
					if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
						Q->InsertHeap(nextState);
					} else{
						delete nextState;
					}
				}  else {
					delete nextState;
				}
			}
			//If the Q is bigger than previously recorded max length, replace max length
			if(Q->size() > maxQLength){
				maxQLength = Q->size();
			}
			delete currentState;
			//If the queue is empty, there is no solution so break out of the loop
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
// Search Algorithm:  A* with expanded list
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
	Puzzle2 * currentState = new Puzzle2(initialState, goalState);
    Puzzle2 * nextState;
    Heap  *Q = new Heap();
    HashTable *ExpandedList = new HashTable();
    numOfStateExpansions = 0;
    maxQLength = 0;
    bool noResult = false;
    // Loop until the goal state is found or the Queue is empty
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
			/*
			 * For all four directions:
			 * Checks if a given move is possible
			 * If so, checks whether the state has been visited in the hashtable
			 * Updates the FCost
			 * Checks the heap for the given state and chooses the one with the best cost to keep
			 * If it's not in the heap, insert it
			 */
			if(currentState->canMoveUp()){
				nextState = currentState->moveUp();
				if(ExpandedList->checkHashNoAdd(nextState->toString())){
					nextState->updateHCost(heuristic);
					nextState->updateFCost();
					if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
						Q->InsertHeap(nextState);
					} else {
						delete nextState;
					}
				}  else {
					delete nextState;
				}
			}
			if(currentState->canMoveRight()){
				nextState = currentState->moveRight();
				if(ExpandedList->checkHashNoAdd(nextState->toString())){
					nextState->updateHCost(heuristic);
					nextState->updateFCost();
					if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
						Q->InsertHeap(nextState);
					} else {
						delete nextState;
					}
				}  else {
					delete nextState;
				}
			}
			if(currentState->canMoveDown()){
				nextState = currentState->moveDown();
				if(ExpandedList->checkHashNoAdd(nextState->toString())){
					nextState->updateHCost(heuristic);
					nextState->updateFCost();
					if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
						Q->InsertHeap(nextState);
					} else {
						delete nextState;
					}
				}  else {
					delete nextState;
				}
			}
			if(currentState->canMoveLeft()){
				nextState = currentState->moveLeft();
				if(ExpandedList->checkHashNoAdd(nextState->toString())){
					nextState->updateHCost(heuristic);
					nextState->updateFCost();
					if(!Q->checkHeap(nextState->toString(), nextState->getFCost())){
						Q->InsertHeap(nextState);
					} else {
						delete nextState;
					}
				}  else {
					delete nextState;
				}
			}
			//If the Q is bigger than previously recorded max length, replace max length
			if(Q->size() > maxQLength){
				maxQLength = Q->size();
			}
			delete currentState;
			//If the queue is empty, there is no solution so break out of the loop
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