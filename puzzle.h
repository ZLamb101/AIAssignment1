#include <string>
#include <iostream>
#include <deque> 

using namespace std;

/*
 *Puzzle class used for algorithms that make use of the expansion path
 */


class Puzzle{
		
private:

    string path;
    int pathLength;
    int hCost;
    int fCost;
    int depth; 
        
    int goalBoard[3][3];
    
    int x0, y0; //coordinates of the blank or 0-tile
    
    int board[3][3];

    deque<string> expansionPath;
    
public:
    
    string strBoard;
     

    Puzzle(const Puzzle &p); //Constructor
    Puzzle(string const elements, string const goal);
     
    void printBoard();

    void updateFCost(); 
    void updateDepth(){
		 depth++;
	}		 
	 	  
	 
    bool goalMatch();
	string toString();
	
    string getString(){
		return strBoard;
	 }
    
    bool canMoveLeft();
    bool canMoveRight();
    bool canMoveUp();
    bool canMoveDown();  

    bool checkExpansionPath(const string&);

//----------------------------------------
//these functions will be useful for Progressive Deepening Search    
	 bool canMoveLeft(int maxDepth);
	 bool canMoveDown(int maxDepth);
	 bool canMoveRight(int maxDepth);
	 bool canMoveUp(int maxDepth);	 
//----------------------------------------
	  
    Puzzle * moveLeft();
    Puzzle * moveRight();
    Puzzle * moveUp();
    Puzzle * moveDown();
	 
	 
    const string getPath();
    
    void setDepth(int d);
    int getDepth();

    int getCurrentDepth();
    
    int getPathLength();
    int getFCost();
	int getHCost();
	int getGCost();	
	
};
