hw1 : main.o functions.o
	gcc main.o functions.o -o hw1

main.o: functions.c functions.h
	gcc main.c -c

functions.o: functions.c
	gcc functions.c -c

clean:
	rm *.o hw1
