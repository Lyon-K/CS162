CC = g++ -std=c++11
EXE_FILE = assignment5

$(EXE_FILE): test_linked_list.o node.hpp linked_list.hpp
	$(CC) *.o *.hpp -o $(EXE_FILE)
	clear
	./$(EXE_FILE)

test_linked_list.o: test_linked_list.cpp linked_list.hpp
	g++ -c test_linked_list.cpp

# node.o: node.hpp
# 	g++ -c node.hpp

# linked_list.o: linked_list.hpp node.hpp
# 	g++ -c linked_list.hpp

clean:
	rm -f *.o $(EXE_FILE)
.PHONY:clean