CXX = gcc
OPT = -O4
SOURCE = main.c include/binary_heap.h src/binary_heap.c
FLAG = -Wall -Wextra

all: main.x

main.x:
	$(CXX) -o $@ $(SOURCE) $(FLAG)

clean:
	@rm -r *.x

.PHONY: clean all