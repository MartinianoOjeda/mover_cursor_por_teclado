#include "func.h"

int main() {
    int game_over = 0;
    char key = 0;
    int t = 0;

    system("cls");

    current_dir[0] = 10;
    current_dir[1] = 10;


    while(!game_over) {
        printCursor(current_dir[0], current_dir[1], CURSOR);
        if(kbhit()) {
            previous_dir[0] = current_dir[0];
            previous_dir[1] = current_dir[1];
            
            key = getch();
            game_over = (key == ESC);
            current_dir[0] += (key == RIGHT) - (key == LEFT);
            current_dir[1] += (key == DOWN) - (key == UP);
        }
        //Sleep(FRAMERATE);
        //t += FRAMERATE;
        //if(t >= SPEED) {
            moveCursor(current_dir[0], previous_dir[0], current_dir[1], previous_dir[1], CURSOR, SPACE);
            //t = 0;
        //}
    }

    return 0;
}