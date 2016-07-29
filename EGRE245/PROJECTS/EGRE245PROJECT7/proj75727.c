//Project #7
//EGRE245 SPRING 2015
//JOHN C. WRAY

#include <stdio.h>
#define UP 1
#define DOWN 0
#define EXIT 9
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4
#define BOARDSIZE 25

void move(int *turtleposition, int direction, int pen, int steps, int lastxposition[], int lastyposition[]);

int main(void){
  int input = 0, pen = UP, direction = EAST, steps = 0, turtle[BOARDSIZE][BOARDSIZE] = {0}, i = 0, j = 0, lastxposition[2] = {0}, lastyposition[2] = {0};
  int *turtleposition, *x, *y;
    turtleposition = &turtle[0][0];
    x = &lastxposition[0];
    y = &lastyposition[0];
    printf("Proj. #7 - John C. Wray\n");
    printf("USER The following commands are valid:\n");
    printf(" 1 \t pen up\n");
    printf(" 2 \t pen down\n");
    printf(" 3 \t turn right 90 degrees\n");
    printf(" 4 \t turn left 90 degrees\n");
    printf("5 x\t move forward x spaces\n");
    printf(" 6 \t Output the Board\n");
    printf(" 9 \t End of Data\n");
    
    while(input != EXIT)
    {
    scanf("%d", &input);
    
    switch(input){
    case 1: pen = UP; break;
    case 2: pen = DOWN; *turtleposition = 1; break;
    case 3: if(direction < 4) direction++; else direction = 1; break;
    case 4: if(direction > 1) direction--; else direction = 4; break;
    case 5: scanf("%d", &steps); move(turtleposition, direction, pen, steps,lastxposition, lastyposition); turtleposition = &turtle[*y][*x]; break;
    case 6:
//**********************************************************************************//OUTPUTS GAMEBOARD//
  printf("                       1                   2\n");
  printf("   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 \n");
  printf("  +-------------------------------------------------+\n");
            for(i = 0; i < BOARDSIZE; i++)
            {   printf("%2d|",i);
                for(j = 0; j < BOARDSIZE; j++)
                {printf("%c ", (turtle[i][j] == 0) ? ' ':'*'); if(j==24) printf("\b|%-2d\n",i);}
            }
  printf("  +-------------------------------------------------+\n");
  printf("   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 \n");
  printf("                       1                   2\n");
//*********************************************************************************//OUTPUTS GAMEBOARD//
    }
    }
    return 0;
}
void move(int *turtleposition, int direction, int pen, int steps, int lastxposition[], int lastyposition[])
{
    int *x, *y, i = 0;
    x = &lastxposition[0];
    y = &lastyposition[0];
    if(pen == UP || pen == DOWN)
    {
    switch(direction)
        {
            case NORTH: for(i = steps; i > 0; i--) if(*y > 0) {turtleposition -= 25; if(pen == DOWN) *turtleposition = 1; (*y)--;} break;
            case EAST:  for(i = steps; i > 0; i--) if(*x < 24){++turtleposition; if(pen == DOWN) *turtleposition = 1; (*x)++;} break;
            case SOUTH: for(i = steps; i > 0; i--) if(*y < 24){turtleposition += 25; if(pen == DOWN) *turtleposition = 1; (*y)++;} break;
            case WEST:  for(i = steps; i > 0; i--) if(*x > 0) {--turtleposition; if(pen == DOWN) *turtleposition = 1; (*x)--;} break;
        }
    }
}

