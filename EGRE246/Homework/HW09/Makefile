hw9: main.o parser.o  
	g++ main.o parser.o -o hw9

main.o: main.cpp parser.h 
	g++ -c main.cpp

parser.o: parser.cpp parser.h 
	g++ -c parser.cpp

clean:
	rm *.o hw9  

	
