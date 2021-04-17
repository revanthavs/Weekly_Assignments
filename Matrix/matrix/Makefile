# Makefile contents here

OBJ = matrix.o
LINK_TARGET = matrix
REBUILDABLES = $(OBJ) $(LINK_TARGET)

CC = g++
CC_FLAGS = -Wall -O2 -g -c 

all: $(LINK_TARGET)

$(LINK_TARGET): $(OBJ)
	$(CC) -o $(LINK_TARGET) $(OBJ)

matrix.o: matrix.cpp matrix.h
	$(CC) $(CC_FLAGS) matrix.cpp

clean:
	rm -f $(REBUILDABLES)