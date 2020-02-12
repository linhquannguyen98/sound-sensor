//contains screen manipulation function, such as clearscreen(0, gotoxy(),
//setcColor(), etc
#include "comm.h"
#include "screen.h"
#include <stdio.h>
/*
	function definition of clearscrenn()
	This function uses VT100 escap sequence \ESC[2J to make the whole
	terminal screen empty.
	argument: no
	return: no
*/
void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);
}
/*
	function definition of gotoxy()
	This function uses VT100 escape sequence \ESC[row;rolH to set cursor
	to a specific location on the terminal screen
	argument:	row number, 1 is top row
				col number, 1 is left column
	return: no
*/
void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}
/*
	function definition of setColor()
	This function uses ESC[1;color to set color to a specific component
	on the terminal screen.
	argument: color, BLACK = 30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE;
	return: no
*/
void setColor(int color){
	printf("%c[1;%dm",ESC, color);
	fflush(stdout);
}
/*
	function definition of bar()
	This function uses for loop and if-condition to draw the bars for defining
	the strength of the sound signal.
	argument:	col number
				dB number
	return: no
*/
void bar(int col, double dB){
	int i;
	for (i = 0; i <dB/4; i++){
		gotoxy(25-i, col+1);
#ifndef UNICODE
		printf("%c", '*');
#else
		if(i<60/4) setColor(WHITE);
		else if (i<80/4) setColor(YELLOW);
		else setColor(RED);
		printf("%s", BAR);
#endif
	}
}
