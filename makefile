#format is target-name: target dependencies
#{-tab-}actions

# MACRO definitions
CC  = gcc
CFLAG = -std=c99 -Wall

# All Targets
all: operation

#Executable operation depends on the files operation.o operation_function.o
operation: operation.o operation_function.o
	$(CC) $(CFLAG) -o operation operation.o operation_function.o

# operation.o depends on the source and header files
operation.o: operation.c operation_function.h
	$(CC) $(CFLAG) -c operation.c

# operation_function.o depends on the source and header files
operation_function.o: operation_function.c operation_function.h
	$(CC) $(CFLAG) -c operation_function.c

# test cases
test: operation
		operation 1 2 3 4
		operation -5 0 -6 0
		operation 0 4 0 6
		operation 5 8 0 -1
		operation 0 5.5 0.25 5
		operation 0 0 5 5
		operation 6 6 0 0
		
#Clean the build directory
clean:
	rm -f *.o operation
