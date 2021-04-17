# Makefile contents here

OBJ = exercise5.o
LINK_TARGET = exercise5
REBUILDABLES = $(OBJ) $(LINK_TARGET)

CC = g++
CC_FLAGS = -Wall -O2 -g -c 

all: $(LINK_TARGET)

$(LINK_TARGET): $(OBJ)
	$(CC) -o $(LINK_TARGET) $(OBJ)

exercise5.o: exercise5.cpp
	$(CC) $(CC_FLAGS) exercise5.cpp

clean:
	rm -f $(REBUILDABLES)