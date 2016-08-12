/*****************************************************************
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

#include <fstream>
#include <iostream>     //cin, cout, cerr, etc.
#include <cstdlib>      //exit(), etc.
#include <string.h>
#include <cctype>      //iscntrl(int)
#include <iomanip>     //smanip setw(int);

#define START_BYTE 170

int main(int argc, char* argv[]){
char data[256];
char ch;
char *in;
unsigned char c;
int startbyte;
int type;
int low;
int high;
int checksum;
int i = 0;
int sum = 0;

if((argc != 2) || strcmp(argv[1], "/?") == 0){                                                    //CHECK TO SEE IF FILE OPEN
        std::cout << "Problem" << '\n'  << std::endl;
        std::exit(0);                                      //IF FILE DID NOT OPEN PRINT ERROR AND EXIT
    }

 std::ifstream from(argv[1]);

while(from.get(ch)){             //MADE CUSTOM PARSER
 c = ch;
 startbyte = int(c);            //READ START BYTES
 sum = startbyte;               //SAVE START BYTE

 if(int(c) == START_BYTE){      //CHECKS THE FIRST BYTE OF THE BIN FILE IF IT EQUAL TO THE START BYTE PROCEED 

 from.get(ch);                 //READ IN TYPE VALUE CAUSE START BYTE WAS CORRECT
 c = ch;
 type = int(c);
 
if(type == 0){	               //This is STATE MACHINE DEALS WITH  ASCII
  from.get(ch);
  c = ch;
  low = int(c);          //low byte is read in
  sum += low;

  from.get(ch);
  c = ch;
  high = int(c);          //high byte is read in
  sum += high;
  
  while(i++ < low){ 
   from.get(ch);
   data[i-1] = ch;
   c = ch;                    //reads in payload
   sum += int(c);
  }
  
  
  std::cout << std::endl;
 
 from.get(ch);
 c = ch;
 checksum = int(c);
 std::cout << "This is my start byte: " << startbyte << std::endl;
 std::cout << "This is my high byte:  " << high << std::endl;
 std::cout << "This is my low byte: " << low << std::endl;
 std::cout << "This is my checksum: " << checksum << std::endl;
 std::cout << "This is my sum being checked: " << sum % 256  << std::endl;
 if((sum % 256) == checksum){      //IF SUM AND CHECKSUM MATCH PRINT PAYLOAD
  std::cout << "String: ";
  i = 0;
  while(i++ < low){
  c = data[i-1];
  std::cout << c;
}
 std::cout << std::endl;
}
else                             //IF SUM AND CHECKSUM DONT MATCH UP THERE IS PROBLEM
 std::cout << "CHECKSUM ERROR: DATA CORRUPTED" << std::endl;
}
else if(type == 1){            //THIS IS INTEGER STATE MACINE
  from.get(ch);
  c = ch;
  low = int(c);               //low byte is read in
  sum += low;

  from.get(ch);
  c = ch;
  high = int(c);             //high byte is read in
  sum += high;

  while(i++ < low){
   from.get(ch);
   data[i-1] = ch;
   in = data;                 //reads in payload
   c = ch;
   sum += int(c);
  }

  std::cout << std::endl;

 from.get(ch);
 c = ch;
 checksum = int(c);
 std::cout << "This is my start byte: " << startbyte << std::endl;
 std::cout << "This is my high byte:  " << high << std::endl;
 std::cout << "This is my low byte: " << low << std::endl;
 std::cout << "This is my checksum: " << checksum << std::endl;
 std::cout << "This is my sum being checked: " << sum % 256 + 1 << std::endl;  //-1 to correct for type value vs byte
 if((sum % 256 + 1) == checksum)
 std::cout << "Integer: " << *(int*)in << std::endl;
 else
 std::cout << "DATA CORRUPTED: CHECKSUMS DO NOT MATCH" << std::endl;
}
else if(type == 2){           //THIS IS A FLOAT STATE MACHINE

  from.get(ch);
  c = ch;
  low = int(c);    //low byte
  sum += low;

  from.get(ch);
  c = ch;
  high = int(c);   //high byte
  sum += high;

  while(i++ < low){
   from.get(ch);
   data[i-1] = ch;            //reads in payload
   in = data;
   c = ch;
   sum += int(c);
  }

  std::cout << std::endl;

 from.get(ch);
 c = ch;
 checksum = int(c);
 std::cout << "This is my start byte: " << startbyte << std::endl;
 std::cout << "This is my high byte:  " << high << std::endl;
 std::cout << "This is my low byte: " << low << std::endl;
 std::cout << "This is my checksum: " << checksum << std::endl;
 std::cout << "This is my sum being checked: " << sum % 256 + 2  << std::endl;  //-2 to correct for type value vs byte
 if((sum % 256 + 2) == checksum)
 std::cout << "Float: " << *(float*)in << std::endl; 
 else
 std::cout << "DATA CORRUPTED: CHECKSUMS DO NOT MATCH" << std::endl;
}

else if(int(c) == 3){            //THIS IS A DOUBLE STATE MACHINE

  from.get(ch);
  c = ch;
  low = int(c);             //reads in low byte
  sum += low;

  from.get(ch);
  c = ch;
  high = int(c);             //reads in high byte
  sum += high;

  while(i++ < low){
   from.get(ch);
   data[i-1] = ch;            //reads in payload
   in = data;
   c = ch;
   sum += int(c);
  }

 from.get(ch);
 c = ch;
 checksum = int(c);

 std::cout << "This is my start byte: " << startbyte << std::endl;
 std::cout << "This is my high byte:  " << high << std::endl;
 std::cout << "This is my low byte: " << low << std::endl;
 std::cout << "This is my checksum: " << checksum << std::endl;
 std::cout << "This is my sum being checked: " << sum % 256 + 3  << std::endl;  // -3 to correct for type value vs byte
 
 if((sum % 256 + 3) == checksum)
 std::cout << "Double: " << *(double*)in << std::endl;
 else
 std::cout << "DATA CORRUPTED: CHECKSUMS DO NOT MATCH" << std::endl;
}

}
else
 sum = 0;   //RESET SUM IN CASE ANY VALUES GOT SAVED
}
}

