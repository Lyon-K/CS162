CC=g++ -std=c++11
EXE_FILE=run_prog

$(EXE_FILE): animal.o monkey.o moss_piglets.o sea_otter.o sloth.o zoo.o prog.cpp
	clear
	$(CC) *.o  prog.cpp -o $(EXE_FILE)
	./$(EXE_FILE)

animal.o: animal.h animal.cpp
	$(CC) -c animal.cpp

monkey.o: monkey.h monkey.cpp animal.o
	$(CC) -c monkey.cpp

moss_piglets.o: moss_piglets.h moss_piglets.cpp animal.o
	$(CC) -c moss_piglets.cpp

sea_otter.o: sea_otter.h sea_otter.cpp animal.o
	$(CC) -c sea_otter.cpp

sloth.o: sloth.h sloth.cpp animal.o
	$(CC) -c sloth.cpp

zoo.o: zoo.h zoo.cpp
	$(CC) -c zoo.cpp

clean:
	rm -f *.o $(EXE_FILE)
.PHONY: clean
