homework2 : main.o functions.o
	gcc main.o functions.o -o homework2

main.o: main.c homework2.h
	gcc -c main.c

functions.o: functions.c
	gcc -c functions.c

clean:
	rm *.o homework2
