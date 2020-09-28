CC=g++ -std=c++11
EXE_FILE=run_prog

$(EXE_FILE): *.o prog.cpp
	$(CC) *.cpp -o $(EXE_FILE)
	./$(EXE_FILE)

menu.o: menu.cpp menu.h pizza.h
	$(CC) -c menu.cpp

order.o: order.h order.cpp
	$(CC) -c order.cpp

restaurant.o: order.h emp_hours.h menu.h restaurant.cpp
	$(CC) -c restaurant.cpp

pizza.o: pizza.h pizza.cpp
	$(CC) *.pizza.cpp

clean:
	rm -f *.o $(EXE_FILE)
.PHONY: clean
