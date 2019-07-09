SHELL = /bin/sh
EXE = test.x
CXX = gcc
CXXFLAGS = -O4 -Wall -Wextra

SRC = main.c 
OBJ=$(SRC:.c=.o)
INC =  include/chain.h #include/matrix.h

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
