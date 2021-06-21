OBJS	= build/cmatrix.o build/main.o
SOURCE	= cmatrix.c tests/main.c
HEADER	= cmatrix.h
OUT	= build/tests
CC	 = gcc -fopenmp
FLAGS	 = -g -c -Wall
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

build/cmatrix.o: cmatrix.c
	$(CC) $(FLAGS) cmatrix.c -o build/cmatrix.o

build/main.o: tests/main.c
	$(CC) $(FLAGS) tests/main.c -o build/main.o


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)