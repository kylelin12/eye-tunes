test: songnode.o eyetunes.o main.o
	gcc -o test songnode.o eyetunes.o main.o

songnode.o: ./songnode/songnode.c ./songnode/songnode.h
	gcc -c ./songnode/songnode.c

eyetunes.o: ./songlibrary/eyetunes.c ./songlibrary/eyetunes.h
	gcc -c ./songlibrary/eyetunes.c

main.o: main.c ./song/song.h ./songnode/songnode.h ./songlibrary/eyetunes.h
	gcc -c main.c

run: test
	./test

clean:
	rm *.o