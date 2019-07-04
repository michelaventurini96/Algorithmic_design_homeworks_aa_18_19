CXX = gcc
OPT = -O4
SOURCE = main.c include/dijkstra_heap.h src/dijkstra_heap.c include/dijkstra_array.h \
	src/dijkstra_array.c 
FLAG = -Wall -Wextra

all: main.x

main.x:
	$(CXX) -o $@ $(SOURCE) $(FLAG)

clean:
	@rm -r *.x

.PHONY: clean all
