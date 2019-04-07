MMain.exe	: Main.o node.o hashtable.o graphics2.o puzzle.o algorithm.o 
	g++ -O2 -std=c++11 -o Main.exe Main.o node.o hashtable.o graphics2.o puzzle.o algorithm.o  -l gdi32 -static-libgcc -static-libstdc++
			
Main.o	: Main.cpp node.h hashtable.h graphics2.h puzzle.h algorithm.h 
	g++ -O2 -std=c++11 -c -Wno-write-strings Main.cpp
	
puzzle.o : puzzle.cpp puzzle.h
	g++ -O2 -std=c++11 -c -Wno-write-strings  puzzle.cpp
	
algorithm.o	: algorithm.cpp algorithm.h 
	g++ -O2 -std=c++11 -c -Wno-write-strings algorithm.cpp

graphics2.o  : graphics2.cpp graphics2.h
	g++ -O2 -std=c++11 -c -Wno-write-strings graphics2.cpp

hashtable.o : hashtable.cpp hashtable.h
	g++ -O2 -std=c++11 -c -Wno-write-strings hashtable.cpp

node.o : node.cpp node.h
	g++ -O2 -std=c++11 -c -Wno-write-strings node.cpp

clean:
	del *.o
	del *.exe
	



