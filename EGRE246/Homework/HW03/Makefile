hw3 : main.o rainfall.o
	gcc main.o rainfall.o -o hw3

main.o: main.c rainfall.h
	gcc -c main.c

rainfall.o: rainfall.c
	gcc -c rainfall.c

clean:
	rm *.o hw3