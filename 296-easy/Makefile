vpath %.c src test

CC=gcc
CFLAGS=-I./src
CFLAGST=-I./test -I./src

12days: main.o 12days.o
	$(CC) -o 12days main.o 12days.o $(CFLAGS)

12days_test: 12days 12days_test.o
	$(CC) -o 12days_test 12days_test.o 12days.o $(CFLAGST)

.PHONY: test
test: 12days_test
	./12days_test

.PHONY: clean
clean:
	rm -f ./*.o
