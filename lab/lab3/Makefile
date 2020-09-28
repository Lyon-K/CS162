CC=g++
EXE_FILE=run_prog

$(EXE_FILE): *.cpp
	$(CC) *.cpp -o $(EXE_FILE)

# $(EXE_FILE): *.o prog.cpp
# 	$(CC) *.o prog.cpp -o $(EXE_FILE)

# pizza.o: pizza.cpp pizza.h
# 	$(CC) -c pizza.cpp

clean:
	rm -f *.o $(EXE_FILE)
.PHONY: clean
