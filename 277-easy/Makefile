vpath %.c src test

CC=gcc
CFLAGS=-I./src
CFLAGST=-I./test

fractions: main.o fractions.o
	$(CC) -o fractions main.o fractions.o $(CFLAGS)

fractions_test: fractions fractions_test.o
	$(CC) -o fractions_test fractions_test.o $(CFLAGST) $(CFLAGS)

.PHONY: test
test: fractions_test
	./fractions_test
.PHONY: clean
clean:
	rm -f ./*.o
