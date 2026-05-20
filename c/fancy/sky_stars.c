#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// libs to get window size
#include <sys/ioctl.h>
#include <unistd.h>
// read keyboard
#include <unistd.h>
#include <termios.h>

struct termios oldt;

void enable_raw_mode() {
    struct termios newt;

    tcgetattr(STDIN_FILENO, &oldt); // save old settings
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO); // canonical + echo

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

// draw character at certain position
#define cursor(x,y) printf("\033[%d;%dH",(x),(y))

char deevolution(char c)
{
    switch(c)
    {
        case '*':
            c = '+';
            break;
        case '+':
            c = '.';
            break;
        case '.':
            c = ' ';
            break;
        case ' ':
            if (rand() % 100 > 50)
                c = '*';
            break;
        default:
            c = ' ';
    }
    return c;
}

void print_star(char c)
{
    switch(c)
    {
        case '*':
            printf("\033[97m*");
            break;
        case '+':
            printf("\033[37m+");
            break;
        case '.':
            printf("\033[90m.");
            break;

        default:
            putchar(' ');
    }
}

void print_buffer(char* buffer, int col, int row)
{
    cursor(1,1);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // change of a shooting star
            if (rand() % 100 == 0)
            {
                for (int i = 0; i < 5; i++)
                {
                    putchar('.');
                    cursor(i + 1, j + 1);
                    putchar('*');
                }
            }
            print_star(buffer[i * col + j]);
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
    int row, col;
    // get windows size
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    col = w.ws_col;
    row = w.ws_row;

    char choice[] = {
        '*',
        '+', '+',
        '.', '.', '.', '.',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
    };
    int choice_len = sizeof(choice) / sizeof(char);
    char c = ' ';
    char* buffer = malloc(col * (row/2) );

    srand(time(NULL));
    
    for (int i = 0; i < col * (row/2) ; i++)
    {
        c = choice[ rand() % choice_len ];
        buffer[i] = c;
    }
        
    print_buffer(buffer, col, row/2);
    
    // hide cursor
    printf("\033[?25l");
    while (1)
    { 
        for (int i = 0; i < rand() % ((col * row) / 5) ; i++)
        {
            int rand_index = rand() % (col * (row/2));
            c = buffer[rand_index];
            c = deevolution(c);
            buffer[i] = c;
        }
        
        print_buffer(buffer, col, row/2);
        usleep(300000);
    }
    // show cursor
    printf("\033[?25h");

    free(buffer);
    disable_raw_mode();
}
