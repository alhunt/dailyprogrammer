vpath %.c src test

CC=gcc
CFLAGS=-I./src
CFLAGST=-I./test -I./src

clmul: main.o clmul.o
	$(CC) -o clmul main.o clmul.o $(CFLAGS)

clmul_test: clmul clmul_test.o
	$(CC) -o clmul_test clmul_test.o clmul.o $(CFLAGST)

.PHONY: test
test: clmul_test
	./clmul_test

.PHONY: clean
clean:
	rm -f ./*.o
