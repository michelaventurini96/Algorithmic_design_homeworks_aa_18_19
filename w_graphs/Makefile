CXX = gcc
OPT = -O4
SOURCE = main.c dijkstra_heap.h dijkstra_heap.c dijkstra_array.h dijkstra_array.c 
FLAG = -Wall -Wextra

all: main.x

main.x:
	$(CXX) -o $@ $(SOURCE) $(FLAG)

clean:
	@rm -r *.x

.PHONY: clean all
