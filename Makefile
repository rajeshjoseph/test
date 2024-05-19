exename=test
OBJ=obj
INC=inc
SRC=src

INCFLAG=-I$(INC)
CC=gcc
CFLAGS=-g -Wall -Werror $(INCFLAG)
LFLAGS= -L/usr/local/lib

INCLUDES:= $(wildcard $(INC)/*.h)
SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SOURCES))

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDES)
	$(CC) -c -o $@ $< $(CFLAGS)

$(exename):$(OBJECTS)
	$(CC) -o $@ $^ $(LFLAGS)

clean:
	rm -f test
	rm -f $(OBJ)/*.o
