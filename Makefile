CC = gcc
CFLAGS = -g -std=c11 -Werror -Wall -Wextra -pedantic-errors
LIBS = -lm -lprogbase

EXECUTABLE = ./a.out
SOURCE = ./src/*.c
INCLUDE = ./include

build:
	@ $(CC) -o $(EXECUTABLE) $(CFLAGS) $(LIBS) $(SOURCE) -I$(INCLUDE)

clean:
	@ rm -rf $(EXECUTABLE)
	@ rm -rf $(EXECUTABLE).dSYM

start: clean build
	@ ./$(EXECUTABLE)
