test: linkedlist.o eyetunes.o main.o
	gcc -o test linkedlist.o eyetunes.o main.o

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

eyetunes.o: eyetunes.c eyetunes.h
	gcc -c eyetunes.c

main.o: main.c linkedlist.h eyetunes.h
	gcc -c main.c

run: test
	./test

clean:
	rm *.o
	rm *~