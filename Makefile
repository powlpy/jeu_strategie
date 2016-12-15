all : comp
	g++ -o strategie_game *.o -lgf0 -lboost_system

clean : rm *.o

comp : *.cpp
	g++ -c *.cpp -Wall #-Werror