##############################################################################################
## Program Filename:	Makefile
## Author:				Lyon Kee
## Date:					5/25/2020
## Description:		Makefile for the program
## Input:				-
## Output:				-
##############################################################################################
CC=g++ -std=c++11 -g
EXE_FILE=wumpus

$(EXE_FILE): Game.o Room.o Event.o Wumpus.o Bats.o Pit.o Gold.o Empty.o prog.o
	$(CC) *.o -o $(EXE_FILE)

prog.o: prog.cpp
	g++ -c prog.cpp

Game.o: Game.h Game.cpp
	g++ -c Game.cpp

Room.o: Room.h Room.cpp
	g++ -c Room.cpp

Event.o: Event.h Event.cpp
	g++ -c Event.cpp

Wumpus.o: Wumpus.h Wumpus.cpp
	g++ -c Wumpus.cpp

Bats.o: Bats.h Bats.cpp
	g++ -c Bats.cpp

Pit.o: Pit.h Pit.cpp
	g++ -c Pit.cpp

Gold.o: Gold.h Gold.cpp
	g++ -c Gold.cpp

Empty.o: Empty.h Empty.cpp
	g++ -c Empty.cpp

clean:
	rm -f *.o $(EXE_FILE)
.PHONY:clean
