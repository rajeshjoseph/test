exename=test
OBJ=obj
INC=inc
SRC=src

INCFLAG=-I$(INC)
CC=gcc
CFLAGS=-g -Wall -Werror $(INCFLAG)
LFLAGS=-rdynamic

INCLUDES:= $(wildcard $(INC)/*.h)
SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SOURCES))

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDES)
	$(CC) -c -o $@ $< $(CFLAGS)

$(exename):$(OBJECTS)
	$(CC) $(LFLAGS) -o $@ $^

clean:
	rm -f test
	rm -f $(OBJ)/*.o
