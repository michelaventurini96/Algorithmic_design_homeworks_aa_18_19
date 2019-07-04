CXX = gcc
OPT = -O4
SOURCE = main.c include/binary_heap.h src/binary_heap.c \
	include/insertion.h src/insertion.c include/bucket.h src/bucket.c include/radix.h src/radix.c \
	include/count.h src/count.c include/select.h src/select.c
FLAG = -Wall -Wextra

all: main.x

main.x:
	$(CXX) -o $@ $(SOURCE) $(FLAG)

clean:
	@rm -r *.x

.PHONY: clean all