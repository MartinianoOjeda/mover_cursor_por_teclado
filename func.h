#include <stdio.h>
#include <Windows.h>
#include <conio.h>

//KEYS
#define ESC 27
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

//CHAR
#define CURSOR 254
#define SPACE 32

#define FRAMERATE 16 //16MS IGUAL A 60FPS APROX
#define SPEED 150

void gotoXY(int, int);
void printCursor(int, int, char);
void moveCursor(int, int, int, int, char, char);

//DIRECTION VECTOR
//direction[0] = x direction[1] = y
typedef int direction[2];

direction current_dir, previous_dir;


void gotoXY(int x, int y) {
    printf("%c[%d;%dH", ESC, y, x);
}

void printCursor(int x, int y, char c) {
    printf("%c[1;%dm", ESC, 32); // color rojo (32) al caracter impreso
    gotoXY(x, y);
    
    printf("%c", c);
    printf("%c[0m", ESC); //reestablece el color por defecto de la consola
}

void moveCursor(int x, int px, int y, int py, char c, char pc) {
    gotoXY(px, py);
    printf("%c", pc);
    printCursor(x, y, c);

}
