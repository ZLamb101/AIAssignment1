

#include "algorithm.h"
#include <queue>
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
    //add necessary variables here
	Puzzle * currentState = new Puzzle(initialState, goalState);
	Puzzle * nextState;
	queue<Puzzle*>  *Q = new queue<Puzzle*>();
	numOfStateExpansions = 0;
	maxQLength = 0;
	bool noResult = false;
	char temp;
	//cout << endl << "Beginning Algorithm";
	//cout << endl << "Current State is " << currentState->toString();
	while(!currentState->goalMatch()){
		//cout << endl << "Current State is " << currentState->toString() << " is NOT the goal state of " << goalState;
		numOfStateExpansions++;
		//cout << endl << "Number of state expansions is: " << numOfStateExpansions;
		//cout << endl << "Board state is: " << endl;
		//currentState->printBoard(); 
		if(currentState->canMoveUp()){
			nextState = currentState->moveUp();
			//cout << endl << "Can move up, new state is: ";
			//nextState->printBoard();
			if(!currentState->checkExpansionPath(nextState->toString())){
				Q->push(nextState);
			}
		}
		if(currentState->canMoveRight()){
			nextState = currentState->moveRight();
			//cout << endl << "Can move right, new state is: ";
			//nextState->printBoard();
			if(!currentState->checkExpansionPath(nextState->toString())){
				Q->push(nextState);
			}
		}
		if(currentState->canMoveDown()){
			nextState = currentState->moveDown();
			//cout << endl << "Can move down, new state is: ";
			//nextState->printBoard();
			if(!currentState->checkExpansionPath(nextState->toString())){
				Q->push(nextState);
			}
		}
		if(currentState->canMoveLeft()){
			nextState = currentState->moveLeft();
			//cout << endl << "Can move left, new state is: ";
			//nextState->printBoard();
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
    
	startTime = clock();
	
	// srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	// maxQLength= rand() % 1500; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY.
	// numOfStateExpansions = rand() % 800; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY

	
	
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	//path = "DDRRLLLUUURDLUDURDLUU";  //this is just a dummy path for testing the function
	if(noResult){
		path = "";
	} else{
		path = currentState->toString();
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
    //add necessary variables here


    //algorithm implementation
	// cout << "------------------------------" << endl;
 //    cout << "<<breadthFirstSearch_with_VisitedList>>" << endl;
 //    cout << "------------------------------" << endl;

	startTime = clock();
	
	srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	maxQLength= rand() % 800; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY.
	numOfStateExpansions = rand() % 600; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY


	
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	path = "DDRRLLLUUURDLUDURDLUU";  //this is just a dummy path for testing the function           
	return path;		
		
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string progressiveDeepeningSearch_No_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int ultimateMaxDepth){
    string path;
	clock_t startTime;
    //add necessary variables here


    //algorithm implementation
	// cout << "------------------------------" << endl;
 //    cout << "<<progressiveDeepeningSearch_No_VisitedList>>" << endl;
 //    cout << "------------------------------" << endl;

	startTime = clock();
	srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	maxQLength= rand() % 500; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY.
	numOfStateExpansions = rand() % 600; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY

	
	
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	path = "DDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUU";  //this is just a dummy path for testing the function           
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




