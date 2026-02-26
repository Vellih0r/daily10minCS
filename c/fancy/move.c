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
#define cursor(x,y) printf("\033[%d;%dH",(y),(x))
struct Body
{
    int x;
    int y;
    char sprite;
};

void drawField(int, int, struct Body *);
void spawn_apple(int, int, struct Body *);

int main()
{
    enable_raw_mode();
    int row, col;
    char c;
    // get windows size
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    row = w.ws_col;
    col = w.ws_row;
    // create apple
    struct Body apple;
    apple.x = row/2;
    apple.y = col/4;
    apple.sprite = 'a';

    spawn_apple(row, col, &apple);

    // create player
    struct Body player;
    player.x = row/2;
    player.y = col/2;
    player.sprite = '@';

    drawField(row, col, &player);
    cursor(apple.x, apple.y);
    printf("%c", apple.sprite);
    cursor(player.x, player.y);
    while( (c = getchar()) != 'q')
    {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        if (w.ws_row != row || w.ws_col != col)
        {
            row = w.ws_col;
            col = w.ws_row;
            drawField(row, col, &player);
        }

        // remove player from prev pos 
        cursor(player.x, player.y);
        printf(".");
        if (c == 'h')
        {
            if (player.x == 1)
                {player.x = row-1;}
            else
                {player.x--;}
        }
        else if (c == 'j')
        {
            if (player.y == col-1)
                {player.y = 1;}
            else
                {player.y++;}
        }
        else if (c == 'k')
        {
            if (player.y == 1)
                {player.y = col-1;}
            else
                {player.y--;}
        }
        else if (c=='l')
        {
            if (player.x == row-1)
                {player.x = 1;}
            else
                {player.x++;}
        }
        // draw player at new pos
        cursor(player.x, player.y);
        printf("%c", player.sprite);
        // eat apple and spawn new one
        if (player.x == apple.x &&  player.y == apple.y)
        {
            printf("Apple!");
            spawn_apple(row, col, &apple);
        }
        cursor(player.x, player.y);
    }
    return 0;
}

void drawField(int row, int col, struct Body *p)
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

void spawn_apple(int row, int col, struct Body *a)
{
    a->x = row/4;
    a->y = col/4; 
    cursor(a->x, a->y);
    printf("%c", a->sprite);
}
