

#include "algorithm.h"
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
    //add necessary variables here
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
			}
		}
		if(currentState->canMoveRight()){
			nextState = currentState->moveRight();
			if(!currentState->checkExpansionPath(nextState->toString())){
				Q->push(nextState);
			}
		}
		if(currentState->canMoveDown()){
			nextState = currentState->moveDown();
			if(!currentState->checkExpansionPath(nextState->toString())){
				Q->push(nextState);
			}
		}
		if(currentState->canMoveLeft()){
			nextState = currentState->moveLeft();
			if(!currentState->checkExpansionPath(nextState->toString())){
				Q->push(nextState);
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

    //algorithm implementation
	// cout << "------------------------------" << endl;
 //    cout << "<<breadthFirstSearch>>" << endl;
 //    cout << "------------------------------" << endl;
    
	
	
	// srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	// maxQLength= rand() % 1500; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY.
	// numOfStateExpansions = rand() % 800; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY

	
	
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	//path = "DDRRLLLUUURDLUDURDLUU";  //this is just a dummy path for testing the function
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
    //add necessary variables here
	Puzzle * currentState = new Puzzle(initialState, goalState);
	Puzzle * nextState;
	queue<Puzzle*>  *Q = new queue<Puzzle*>();
	vector<string> *VisitedList = new vector<string>();
	numOfStateExpansions = 0;
	maxQLength = 0;
	bool noResult = false;
	while(!currentState->goalMatch()){
		numOfStateExpansions++;
		if(currentState->canMoveUp()){
			nextState = currentState->moveUp();
			if(!currentState->checkExpansionPath(nextState->toString())){
				if(!isVisited(VisitedList, nextState->toString())){
					VisitedList->push_back(nextState->toString());
					Q->push(nextState);
				}
			}
		}
		if(currentState->canMoveRight()){
			nextState = currentState->moveRight();
			if(!currentState->checkExpansionPath(nextState->toString())){
				if(!isVisited(VisitedList, nextState->toString())){
					VisitedList->push_back(nextState->toString());
					Q->push(nextState);
				}
			}
		}
		if(currentState->canMoveDown()){
			nextState = currentState->moveDown();
			if(!currentState->checkExpansionPath(nextState->toString())){
				if(!isVisited(VisitedList, nextState->toString())){
					VisitedList->push_back(nextState->toString());
					Q->push(nextState);
				}
			}
		}
		if(currentState->canMoveLeft()){
			nextState = currentState->moveLeft();
			if(!currentState->checkExpansionPath(nextState->toString())){
				if(!isVisited(VisitedList, nextState->toString())){
					VisitedList->push_back(nextState->toString());
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

    //algorithm implementation
	// cout << "------------------------------" << endl;
 //    cout << "<<breadthFirstSearch>>" << endl;
 //    cout << "------------------------------" << endl;
	
	// srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	// maxQLength= rand() % 1500; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY.
	// numOfStateExpansions = rand() % 800; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY

	
	
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	//path = "DDRRLLLUUURDLUDURDLUU";  //this is just a dummy path for testing the function
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
    //add necessary variables here
	Puzzle * currentState = new Puzzle(initialState, goalState);
	Puzzle * nextState;
	stack<Puzzle*>  *Q = new stack<Puzzle*>();
	numOfStateExpansions = 0;
	maxQLength = 0;
	int C = 1;
	bool noResult = false;
	while(!currentState->goalMatch()){
		numOfStateExpansions++;
		if(currentState->canMoveUp(C)){
			nextState = currentState->moveUp();
			if(!currentState->checkExpansionPath(nextState->toString())){
					Q->push(nextState);
					if(noResult){
						noResult = false;
					}
			}
		}
		if(currentState->canMoveRight(C)){
			nextState = currentState->moveUp();
			if(!currentState->checkExpansionPath(nextState->toString())){
					Q->push(nextState);
					if(noResult){
						noResult = false;
					}
			}
		}
		if(currentState->canMoveDown(C)){
			nextState = currentState->moveUp();
			if(!currentState->checkExpansionPath(nextState->toString())){
					Q->push(nextState);
					if(noResult){
						noResult = false;
					}
			}
		}
		if(currentState->canMoveLeft(C)){
			nextState = currentState->moveUp();
			if(!currentState->checkExpansionPath(nextState->toString())){
					Q->push(nextState);
					if(noResult){
						noResult = false;
					}
			}
		}
		if(Q->empty()){
			if(noResult){
				break;
			}
			C++;
		}
		if(((C-1) == (Q->top()->getCurrentDepth())) && ((currentState->getCurrentDepth()+1) == (Q->top()->getCurrentDepth()))){
				noResult = true;
		}
		delete currentState;
		currentState = Q->top();
		Q->pop();
	}
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
string uniformCost_ExpandedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, 
                               float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions){
											 
   string path;
   clock_t startTime;
   
   numOfDeletionsFromMiddleOfHeap=0;
   numOfLocalLoopsAvoided=0;
   numOfAttemptedNodeReExpansions=0;


    // cout << "------------------------------" << endl;
    // cout << "<<uniformCost_ExpandedList>>" << endl;
    // cout << "------------------------------" << endl;
	actualRunningTime=0.0;	
	startTime = clock();
	srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	maxQLength= rand() % 200; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY.
	numOfStateExpansions = rand() % 200; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY


	
	
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	path = "DDRRLLLUUURDLUDURDLUU"; //this is just a dummy path for testing the function
	             
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


    // cout << "------------------------------" << endl;
    // cout << "<<aStar_ExpandedList>>" << endl;
    // cout << "------------------------------" << endl;
	actualRunningTime=0.0;	
	startTime = clock();
	srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	maxQLength= rand() % 200; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY.
	numOfStateExpansions = rand() % 200; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY


	
	
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	path = "DDRRLLLUUURDLUDURDLUU"; //this is just a dummy path for testing the function
	             
	return path;		
		
}




