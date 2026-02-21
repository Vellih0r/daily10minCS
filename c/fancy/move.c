#include <stdio.h>
// libs to get window size
#include <sys/ioctl.h>
#include <unistd.h>
// read keyboard
#include <unistd.h>
#include <termios.h>

struct termios oldt;

void enable_raw_mode() {
    struct termios newt;

    tcgetattr(STDIN_FILENO, &oldt); // сохранить старые настройки
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO); // выключаем canonical + echo

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

// draw carachter at certain position
#define cursor(x,y) printf("\033[%d;%dH",(x),(y))
struct Vector2
{
    int x;
    int y;
    char sprite;
};

void drawField(int, int, struct Vector2 *);

int main()
{
    enable_raw_mode();
    int row, col;
    char c;
    // get windows size
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    row = w.ws_row;
    col = w.ws_col;

    // create player
    struct Vector2 player;
    player.x = row/2;
    player.y = col/2;
    player.sprite = '@';

    printf("Columns: %d\n", col);
    printf("Rows: %d\n", row);

    drawField(row, col, &player);
    while( (c = getchar()) != 'q')
    {
        // remove player from prev pos 
        cursor(player.x, player.y);
        printf(".");
        if (c == 'h')
        {
            if (player.y == 1)
                {player.y = col-1;}
            else
                {player.y--;}
        }
        else if (c == 'j')
        {
            if (player.x == row-1)
                {player.x = 1;}
            else
                {player.x++;}
        }
        else if (c == 'k')
        {
            if (player.x == 1)
                {player.x = row-1;}
            else
                {player.x--;}
        }
        else if (c=='l')
        {
            if (player.y == col-1)
                {player.y = 1;}
            else
                {player.y++;}
        }
        // draw player at new pos
        cursor(player.x, player.y);
        printf("%c", player.sprite);
        //drawField(row, col, &player);
    }
    return 0;
}

void drawField(int row, int col, struct Vector2 *p)
{
    for (int i=0; i<col; i++)
    {
        for (int j=0; j<row; j++)
        {
            if (p->x == j && p->y == i)
            {
                cursor(j,i);
                printf("%c", p->sprite);
                continue;
            }
            cursor(j,i);
            printf(".");
        }
    }
}
