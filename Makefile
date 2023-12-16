.PHONY:all run clean
all: calculator
clean: 
	rm -rf calculator *.o
run: calculator
	./calculator
main.o: main.c
	gcc -c main.c
bin.o: bin.c
	gcc -c bin.c
oct.o: oct.c
	gcc -c oct.c
hex.o: hex.c
	gcc -c hex.c
functions.o: functions.c 
	gcc -c functions.c
calculator: main.o bin.o oct.o hex.o functions.o 
	gcc main.o bin.o oct.o hex.o functions.o -o calculator