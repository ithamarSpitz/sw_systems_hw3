all: stringProg

main.o: main.c
	gcc -Wall -g -c main.c

stringProg: main.o
	gcc -Wall -g -o stringProg main.o -lm

.PHONY: clean

clean:
	rm -f *.o stringProg