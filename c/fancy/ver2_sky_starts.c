#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

struct termios oldt;

void enable_raw_mode()
{
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void disable_raw_mode()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

#define cursor(x,y) printf("\033[%d;%dH",(x),(y))

void print_star(char c)
{
    switch (c)
    {
        case '*': printf("\033[97m*"); break;
        case '+': printf("\033[37m+"); break;
        case '.': printf("\033[90m."); break;
        default: putchar(' ');
    }
}

char evolve(char c)
{
    int r = rand() % 100;

    switch (c)
    {
        case '*': return (r < 30) ? '+' : '*';
        case '+': return (r < 40) ? '.' : '+';
        case '.': return (r < 50) ? ' ' : '.';
        case ' ': return (r < 3)  ? '.' : ' ';
    }
    return ' ';
}

void render(char *buffer, int col, int row)
{
    cursor(1,1);

    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x < col; x++)
        {
            print_star(buffer[y * col + x]);
        }
        putchar('\n');
    }

    printf("\033[0m");
    fflush(stdout);
}

int main()
{
    enable_raw_mode();
    atexit(disable_raw_mode);

    srand(time(NULL));

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    int col = w.ws_col;
    int row = w.ws_row / 2;

    char *buffer = malloc(col * row);

    char seed[] = { ' ', ' ', ' ', '.', '.', '+', '*' };
    int seed_len = sizeof(seed);

    for (int i = 0; i < col * row; i++)
        buffer[i] = seed[rand() % seed_len];

    printf("\033[2J");      // clear screen
    printf("\033[?25l");    // hide cursor

    while (1)
    {
        for (int i = 0; i < (col * row) / 20; i++)
        {
            int idx = rand() % (col * row);
            buffer[idx] = evolve(buffer[idx]);
        }

        render(buffer, col, row);
        usleep(50000 + rand() % 50000);
    }

    printf("\033[?25h");
    free(buffer);
}
