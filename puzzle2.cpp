#include "Puzzle2.h"
#include  <cmath>
#include  <assert.h>

using namespace std;

//////////////////////////////////////////////////////////////
//constructor
//////////////////////////////////////////////////////////////
Puzzle2::Puzzle2(const Puzzle2 &p) : path(p.path){
	
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    board[i][j] = p.board[i][j];
		    goalBoard[i][j] = p.goalBoard[i][j];
		}
	}	
	
	x0 = p.x0;
	y0 = p.y0;
	//path = p.path;
	pathLength = p.pathLength;
	hCost = p.hCost;
	fCost = p.fCost;	
	strBoard = toString(); //uses the board contents to generate the string equivalent
	
}

//////////////////////////////////////////////////////////////
//constructor
//inputs:  initial state, goal state
//////////////////////////////////////////////////////////////
Puzzle2::Puzzle2(string const elements, string const goal){
	
	int n;
	
	n = 0;	
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    board[i][j] = elements[n] - '0';
		    if(board[i][j] == 0){
			    x0 = j;
			    y0 = i;
			 }
		    n++;
		} 
	}
		
	///////////////////////
	n = 0;
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    goalBoard[i][j] = goal[n] - '0';
		    n++;
		} 
	}		
	///////////////////////	
	path = "";
	pathLength=0;
	hCost = 0;
	fCost = 0;
	strBoard = toString();	
}


void Puzzle2::updateHCost(heuristicFunction hFunction){
	hCost = h(hFunction);
}

void Puzzle2::updateFCost(){
	fCost = hCost + pathLength;
}

int Puzzle2::getFCost(){
	return fCost;
}

int Puzzle2::getHCost(){
	return hCost;
}

int Puzzle2::getGCost(){
	return pathLength;
}

//Heuristic function implementation
int Puzzle2::h(heuristicFunction hFunction){
	
	int sum=0;
	int h=0;
	int numOfMisplacedTiles=0;
	
	switch(hFunction){
		case misplacedTiles:			      
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					if(goalBoard[i][j] != board[i][j]){
						if(board[i][j] != 0){
							numOfMisplacedTiles++;
						}
					}
				}
			}	
            h = numOfMisplacedTiles; 					
		    break;
		         
		case manhattanDistance:
		    for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					int num = board[i][j];
					if(num == 0){
						continue;
					}
					for(int k = 0; k < 3; k++){
						for(int l = 0; l < 3; l++){
							if (goalBoard[k][l] == num){
								sum += abs(i-k) + abs(j-l);
								k=3;
								break;
							}
						}
					}
				}
			}
		    h = sum; 					
		    break;              
	};
	return h;
}


//converts board state into its string representation
string Puzzle2::toString(){
  int n;
  string stringPath;
  
  n=0;
  for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){			    
		    stringPath.insert(stringPath.end(), board[i][j] + '0');
		    n++;
		} 
  }
  
  return stringPath;
}



bool Puzzle2::goalMatch(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(goalBoard[i][j] != board[i][j]){
				return false;
			}
		}
	}
	return true;
}

bool Puzzle2::canMoveLeft(){
   return (x0 > 0);
	
}

const string Puzzle2::getPath(){
	return path;
}

bool Puzzle2::canMoveRight(){
	return (x0 < 2);	
}


bool Puzzle2::canMoveUp(){

   return (y0 > 0);
	
}

bool Puzzle2::canMoveDown(){

   return (y0 < 2);
	
}

///////////////////////////////////////////////

Puzzle2 *Puzzle2::moveLeft(){
	
	Puzzle2 *p = new Puzzle2(*this);
	
	
   if(x0 > 0){
		
		p->board[y0][x0] = p->board[y0][x0-1];
		p->board[y0][x0-1] = 0;
		
		p->x0--;
		
		p->path = path + "L";
		p->pathLength = pathLength + 1;  
	}
	p->strBoard = p->toString();

	return p;
	
}


Puzzle2 *Puzzle2::moveRight(){
	
   Puzzle2 *p = new Puzzle2(*this);
	
	
   if(x0 < 2){
		
		p->board[y0][x0] = p->board[y0][x0+1];
		p->board[y0][x0+1] = 0;
		
		p->x0++;
		
		p->path = path + "R";
		p->pathLength = pathLength + 1; 
     	
		
	}
	
	p->strBoard = p->toString();
	
	return p;
	
}


Puzzle2 *Puzzle2::moveUp(){
	
   Puzzle2 *p = new Puzzle2(*this);
	
	
   if(y0 > 0){
		
		p->board[y0][x0] = p->board[y0-1][x0];
		p->board[y0-1][x0] = 0;
		
		p->y0--;
		
		p->path = path + "U";
		p->pathLength = pathLength + 1;  
	
		
	}
	p->strBoard = p->toString();
	
	return p;
	
}

Puzzle2 *Puzzle2::moveDown(){
	
   Puzzle2 *p = new Puzzle2(*this);
	
	
   if(y0 < 2){
		
		p->board[y0][x0] = p->board[y0+1][x0];
		p->board[y0+1][x0] = 0;
		
		p->y0++;
		
		p->path = path + "D";
		p->pathLength = pathLength + 1;  
		
		
	}
	p->strBoard = p->toString();	
	
	return p;
	
}

/////////////////////////////////////////////////////


void Puzzle2::printBoard(){
	cout << "board: "<< endl;
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		  cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int Puzzle2::getPathLength(){
	return pathLength;
}

