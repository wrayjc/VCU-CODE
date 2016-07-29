/********************************************************************************
 * Program #: Homework #5                                                       *
 *                                                                              *
 * Programmer: John Wray                                                        *
 *                                                                              *
 * Due Date: Friday, October 10, 2015                                           *
 *                                                                              *
 * EGRE 246, Fall 2015      Instructor: Dr. Tim Bakker                          *
 *                                                                              *
 * Pledge: I have neither given nor received unauthorized aid on this program.  *
 *                                                                              *
 * Description: INPUTS A FILE AND OUTPUT CONTENTS IN HEXADECIMAL                *
 *                                                                              *
 ********************************************************************************/

#include <stdlib.h>
#include <fstream>      //file streams and operations
#include <iostream>     //cin, cout, cerr, etc.
#include <cstdlib>      //exit(), etc.
#include <string.h>
#include <cctype>      //iscntrl(int)
#include <iomanip>     //smanip setw(int);
#define MAX_COLUMN 16
#define MAX_ROW 20
int main(int argc, char* argv[]){
    
    char ch[MAX_ROW];
    unsigned char c;
    int column_position = 0, row_position = 0;
    
    if((argc != 2) || strcmp(argv[1], "/?") == 0){         //CHECK TO SEE IF FILE OPEN
        std::cout << "Binary File Viewer" << '\n' << "Usage: hw5 [input filename]" << std::endl;
        std::exit(0);                                      //IF FILE DID NOT OPEN PRINT ERROR AND EXIT
    }
    
    std::ifstream from(argv[1]);
    
    while(from.get(ch[column_position]))                  //READ IN BYTE BY BYTE
    {
        if(column_position == MAX_COLUMN){
            std::cout << "     ";
            for(column_position = 0; column_position < 16; column_position++)
                if(iscntrl(int(ch[column_position])))     //IF CONTROL CHAR PRINT OUT .
                    std::cout << ".";
                else
                    std::cout << ch[column_position];
            std::cout <<  std::endl;
            row_position++;
            column_position = 0;
        }
        else{
            c = ch[column_position++];
            std::cout << std::setw(2) << std::uppercase  << std::hex;   //FORMAT OUTPUT TO HEXADECIMAL
            std::cout << int(c) << " ";
        }
        
        if(row_position == MAX_ROW){                                   //EVERY 20 LINES REQUEST INPUT TO CONTINUE
            std::cout << "Press ENTER to continue" << std::endl;
            if(std::cin.ignore(1)){
                row_position = 0;
                continue; 
            }  
        }
    }
    
    from.close();                                       //CLOSE FILE
    return 0;
}
