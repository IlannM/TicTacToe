TicTacToe: main.o functions.o time.o random.o
	g++ main.o functions.o time.o random.o -o TicTacToe

main.o: main.cpp
	g++ -c main.cpp

functions.o: functions.cpp functions.hpp
	g++ -c functions.cpp

time.o: time.cpp time.hpp
	g++ -c time.cpp

random.o: random.cpp random.hpp
	g++ -c random.cpp

clear:
	rm *.o TicTacToe.exe TicTacToeGameExport.txt
