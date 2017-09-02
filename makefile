CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

PROGRAMS = Sort/mergesort.cpp main.cpp
# the build target executable:
TARGET = algorithms

run:  mergesort.o main.o
	$(CC) $(CFLAGS) -o run mergesort.o main.o

mergesort.o: Sort/mergesort.cpp
	$(CC) $(CFLAGS) -c Sort/mergesort.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) run *.o *~
