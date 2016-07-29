hw8 : main.o array.o
	g++ main.o array.o -o hw8

main.o : main.cpp array.h
	g++ -c main.cpp

array.o : array.cpp array.h
	g++ -c array.cpp
	
	
clean :
	rm *.o
	rm hw8
