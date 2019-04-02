
#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <ctime>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

#include "puzzle.h"
#include "hashtable.h"
#include "node.h"

const heuristicFunction HEURISTIC_FUNCTION=manhattanDistance;


//Function prototypes
string progressiveDeepeningSearch_No_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int ultimateMaxDepth);


string breadthFirstSearch_with_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime);
bool isVisited(const vector<string> *VisitedList,const string &state);

string breadthFirstSearch(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime);

string uniformCost_ExpandedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, 
                               float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions);

string aStar_ExpandedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, 
                               float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions, heuristicFunction heuristic);

#endif