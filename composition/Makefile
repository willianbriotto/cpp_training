#TODO - Identify and compile source file automatic
CC=g++
CFLAGS=-Wall -Werror -Wextra -g
ROOT_DIR=$(realpath .)

LIST_FILES = main.cpp Date.h Date.cpp Employee.h Employee.cpp

# Enable this to do logging
#CFLAGS += -DDO_VERBOSE

all:
	$(CC) $(CFLAGS)  $(LIST_FILES) -o composition

clean:
	rm composition
