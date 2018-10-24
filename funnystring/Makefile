CFLAGS = -Wall
LDFLAGS = -lm
CC = gcc

LDLIBS_CMOCKA = -lcmocka

all:	funny_main.o funny_string.o
		$(CC) funny_main.o funny_string.o -o funny_string
	
funny_main.o: ./src/funny_string.h
		$(CC) -c ./src/funny_main.c -I./src 

funny_string.o: ./src/funny_string.h
		$(CC) -c ./src/funny_string.c -I./src

test_funny_string: test_funny_string.o funny_string.o 
		$(CC) $(LDLIBS_CMOCKA) funny_string.o test_funny_string.o -o test_funny_string
	
test_funny_string.o: ./src/funny_string.h
		$(CC) -c ./tests/test_funny_string.c -I./src

clean:
		@rm -f *.o funny_string test_funny_string

tests: test_funny_string
		@./test_funny_string