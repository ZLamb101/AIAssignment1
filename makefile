MMain.exe	: Main.o node.o hashtable.o heap.o graphics2.o puzzle.o puzzle2.o algorithm.o 
	g++ -O2 -std=c++11 -o Main.exe Main.o node.o hashtable.o heap.o graphics2.o puzzle.o puzzle2.o algorithm.o  -l gdi32 -static-libgcc -static-libstdc++
			
Main.o	: Main.cpp node.h hashtable.h heap.h graphics2.h puzzle.h puzzle2.h algorithm.h 
	g++ -O2 -std=c++11 -c -Wno-write-strings Main.cpp
	
puzzle.o : puzzle.cpp puzzle.h
	g++ -O2 -std=c++11 -c -Wno-write-strings  puzzle.cpp

puzzle2.o : puzzle2.cpp puzzle2.h
	g++ -O2 -std=c++11 -c -Wno-write-strings  puzzle2.cpp
	
algorithm.o	: algorithm.cpp algorithm.h 
	g++ -O2 -std=c++11 -c -Wno-write-strings algorithm.cpp

graphics2.o  : graphics2.cpp graphics2.h
	g++ -O2 -std=c++11 -c -Wno-write-strings graphics2.cpp

hashtable.o : hashtable.cpp hashtable.h
	g++ -O2 -std=c++11 -c -Wno-write-strings hashtable.cpp

node.o : node.cpp node.h
	g++ -O2 -std=c++11 -c -Wno-write-strings node.cpp

heap.o : heap.cpp heap.h
	g++ -O2 -std=c++11 -c -Wno-write-strings heap.cpp



clean:
	del *.o
	del *.exe
	



