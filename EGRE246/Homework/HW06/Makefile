hw6 : main.o circle.o
	g++ main.o circle.o -o hw6 -lm

main.o : main.cpp circle.h
	g++ -c main.cpp 

circle.o : circle.cpp circle.h
	g++ -c circle.cpp -lm
	
	
clean :
	rm *.o
	rm hw6
