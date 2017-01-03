vpath %.c src test

CC=gcc
CFLAGS=-I./src -g
CFLAGST=-I./test -I./src -g

parentheses: main.o parentheses.o
	$(CC) -o parentheses main.o parentheses.o $(CFLAGS)

parentheses_test: parentheses parentheses_test.o
	$(CC) -o parentheses_test parentheses_test.o parentheses.o $(CFLAGST)

.PHONY: test
test: parentheses_test
	./parentheses_test

.PHONY: clean
clean:
	rm -f ./*.o
