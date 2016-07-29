/******************************************************************
 * Program #: [HW9]
 *
 * Programmer: John C. Wray
 *
 * Due Date: [12-4-2015]
 *
 * EGRE 246, Fall 2015       Instructor: Dr. Tim Bakker
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: 
 *
 * Input: 
 *
 * Output: 
 *
 ******************************************************************/


#include <iostream>
#include <string>

const int START = 1;
const int TYPE = 1;
const int SIZE = 2;
const int CHK = 1;
const int MAX_SIZE = 1024;


enum ParseState{START1, TYPE1, SIZELOW1, SIZEHIGH1, PAYLOAD1, CHECKSUM1};

enum TypeID{asciiType, integerType, floatType, doubleType};

class parser{

	private:
		ParseState State;
		unsigned int Size, i;
		unsigned char Type;
		unsigned char Chk;
		unsigned char Data[MAX_SIZE];
		
	public:
		// Constructor
		parser();
		
		// Destructor
		~parser();
		
		// Parse function
		bool parse(unsigned char);
		
		// Process data function
		void process(void);
		
};
