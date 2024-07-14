#include <unistd.h>  // Provides access to the POSIX operating system API.
#include <termios.h> // Used for controlling terminal I/O characteristics.
#include <fcntl.h>   // Provides an interface for file descriptor manipulation.
#include <stdio.h>   // Standard input-output header.
#include <stdlib.h>  // Standard library for memory allocation, process control, etc.

int kbhit(void);

int main()
{
    while (1) // Keeps the program running indefinitely.
    {
        if (kbhit()) // Calls kbhit() to check if a key has been pressed.
        {
            switch (getchar()) // Executes different actions based on the key pressed
            { 
            case 'w':
                printf("The typed key: w\n");
                break;
            case 'a':
                printf("The typed key: a\n");
                break;
            case 's':
                printf("The typed key: s\n");
                break;
            case 'd':
                printf("The typed key: d\n");
                break;
            case 'q':
                printf("The typed key: q\n");
                printf("Do you want to quit? (y/n) then press Enter: ");
                kbhit();
                switch (getchar())
                {
                case 'y':
                    exit(0);
                    break;
                case 'n':
                    break;
                }
                break;
            }
        }
    }
}

// receiving inputs from keyboard
int kbhit(void)
{
    // -----------------------------------------------
    // termios Structs (oldt, newt): Store terminal settings.
    struct termios oldt, newt;
    int ch;
    int oldf;
    // -----------------------------------------------
    // Saving Current Terminal Settings
    tcgetattr(STDIN_FILENO, &oldt); 
    // -----------------------------------------------
    // Modifying Terminal Settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    // ICANON: Disables canonical mode, making input available immediately.
    // ECHO: Disables echoing of input characters.
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    // -----------------------------------------------
    // Setting Non-blocking Mode
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    // -----------------------------------------------
    // Checking for Key Press
    ch = getchar();
    // If a key is pressed, it's read into ch
    // -----------------------------------------------
    // Restoring Terminal Settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    // -----------------------------------------------
    // Return Key Press Status
    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
