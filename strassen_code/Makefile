SHELL = /bin/sh
EXE = strassen_test.x
CXX = gcc
CXXFLAGS = -O4 -Wall -Wextra

SRC= main.c src/matrix.c src/strassen.c src/strassen_improved.c
OBJ=$(SRC:.c=.o)
INC = include/matrix.h include/strassen.h include/strassen_improved.h

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .c .o

all: $(EXE)

.PHONY: all

%.o: %.cc $(INC)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(EXE): $(OBJ)
	$(CXX) $^ -o $(EXE)

clean:
	@rm -rf $(OBJ) $(EXE) .*~ include/*~ *~ src/*~ *~

.PHONY: clean all

format:
	clang-format -i $(SRC)

.PHONY: format
