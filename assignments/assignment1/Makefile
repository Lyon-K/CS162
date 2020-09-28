CC=g++ -std=c++11
EXE_FILE=wizard_run

$(EXE_FILE): run_wizard.cpp catalog.o
	$(CC) run_wizard.cpp catalog.o -o $(EXE_FILE)

catalog.o: catalog.h catalog.cpp
	$(CC) -c catalog.cpp

clean:
	rm -f *.o $(EXE_FILE)
.PHONY:clean
