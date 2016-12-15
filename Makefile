all : comp
	g++ -o strategie_game *.o -lgf0 -lboost_system

clean : rm *.o

comp : *.cpp
	g++ -std=c++11 -c *.cpp -Wall #-Werror