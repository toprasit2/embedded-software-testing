CFLAGS = -Wall
LDFLAGS = -lm
CC = gcc
MAIRU = -fprofile-arcs
AR = -ftest-coverage
RAI = -fPIC
NI = -O0

LDLIBS_CMOCKA = -lcmocka

all:	binary_search.o
		$(CC) binary_search.o -o binary_search

binary_search.o: ./src/binary_search.h
		$(CC) -c $(MAIRU) $(AR) $(RAI) $(NI) ./src/binary_search.c -I./src

test_binary_search.o: ./src/binary_search.h
		$(CC) -c $(MAIRU) $(AR) $(RAI) $(NI) ./tests/test_binary_search.c -I./src

test_binary_search:  binary_search.o test_binary_search.o
		$(CC) $(LDLIBS_CMOCKA) $(MAIRU) $(AR) $(RAI) $(NI) binary_search.o test_binary_search.o -o test_binary_search

coverage_binary_search: binary_search.o test_binary_search.o
		$(CC) $(LDLIBS_CMOCKA) $(MAIRU) $(AR) $(RAI) $(NI) binary_search.o test_binary_search.o

clean:
		@rm -f *.o binary_search test_binary_search
		@rm -f *.gcno
		@rm -f *.gcda

tests: test_binary_search
		@./test_binary_search

coverage: coverage_binary_search
		@gcovr .