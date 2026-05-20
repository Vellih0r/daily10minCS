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

void print_buffer(char* buffer, int col, int row)
{
    cursor(1,1);

    for (int i = 0; i < col * row; i++)
    {
        putchar(buffer[i]);
    }

    fflush(stdout);
}

int main()
{
    enable_raw_mode();
    int row, col;
    // get windows size
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    col = w.ws_col;
    row = w.ws_row;

    char choice[] = {'*', '.', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int choice_len = sizeof(choice) / sizeof(char);
    char c = ' ';
    char* buffer1 = malloc(col * (row/2) );
    char* buffer2 = malloc(col * (row/2) );

    srand(time(NULL));
    
    int change = 1;
    while (1)
    {
        for (int i = 0; i < col * (row/2) ; i++)
        {
            c = choice[ rand() % choice_len ];
            if (change == 1)
            {
                buffer1[i] = c;
            }
            else
            {
                buffer2[i] = c;
            }
        }
        
        cursor(row/2,col/2+1);
        if (change == 1)
        {
            print_buffer(buffer1, col, row/2);
        }
        else
        {
            print_buffer(buffer2, col, row/2);
        }
        
        usleep(300000);

        change = change * -1;
    }

    free(buffer1);
    free(buffer2);
}
