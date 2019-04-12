#include <string>
#include <iostream>
#include <deque> 

using namespace std;


enum heuristicFunction{misplacedTiles, manhattanDistance};


class Puzzle2{
		
private:

    string path;
    int pathLength;
    int hCost;
    int fCost;
        
    int goalBoard[3][3];
    
    int x0, y0; //coordinates of the blank or 0-tile
    
    int board[3][3];
    
public:
    
    string strBoard;
     

    Puzzle2(const Puzzle2 &p); //Constructor
    Puzzle2(string const elements, string const goal);
     
    void printBoard();
    
    int h(heuristicFunction hFunction);
     

    void updateFCost(); 
    void updateHCost(heuristicFunction hFunction); 
	 	  
	 
    bool goalMatch();
	string toString();
	
    string getString(){
		return strBoard;
	 }
    
    bool canMoveLeft();
    bool canMoveRight();
    bool canMoveUp();
    bool canMoveDown();  

	  
    Puzzle2 * moveLeft();
    Puzzle2 * moveRight();
    Puzzle2 * moveUp();
    Puzzle2 * moveDown();
	 
	 
    const string getPath();
    
    int getPathLength();
    int getFCost();
	int getHCost();
	int getGCost();	
	
};
