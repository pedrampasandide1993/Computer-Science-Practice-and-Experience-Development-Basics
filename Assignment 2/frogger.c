#include <unistd.h>  // used in kbhit()
#include <termios.h> // used in kbhit()
#include <fcntl.h>   // used in kbhit()
// CODE: include the necessary library(s)

// Game constants
#define WIDTH 64
#define HEIGHT 10

// Game global variables
int frogX, frogY;
char lanes[HEIGHT][WIDTH + 1] = {
    "xxx..xxx..xxx..xxxxxxxxxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxx..xxxxx", // lane0 (wall/end lane)
    "...xxxx..xxxxxx.......xxxx.....xx...xxxx.....xxxxxx...xxxxx.....", // lane1
    "....xxxx.....xxxx.....xxxx.......xxxxxxx.....xx....xxxxxx.......", // lane2
    "..xxx.....xxx.....xxx.....xxx...xxx....xx....xxxx....xx......xx.", // lane3
    "................................................................", // lane4 (safe lane)
    "....xxxx.......xxxx.........xxxx.......xxxx......xxxx....xxxx...", // lane5
    ".....xx...xx...xx......xx....xx.......xx..xx.xx......xx.......xx", // lane6
    "..xxx.....xx......xxxx..xx......xxxx......xxxx.......xxx...xxx..", // lane7
    "..xx.....xx.......xx.....xx.....xx..xx.xx........xx....xx.......", // lane8
    "................................................................"  // lane9 (start lane)
};
int speeds[HEIGHT] = {0, -2, +1, -1, 0, +2, -1, -1, +1, 0};

// Function prototypes (Foward declared)
void initGame();
// CODE: Declare all functions here but the implementation must be after int main()

int main()
{
    initGame();
    int counter = 0;
    while (1)
    {
        input();
        // (counter % 5 == 0) return either 0 or 1
        logic(counter % 5 == 0); // Update lanes every 5th iteration (t seconds)
        draw();
        usleep(200000); // Sleep for t/5 seconds (200 milliseconds)
        counter++;
    }
    return 0;
}

void initGame()
{
    // The initial position of "F" (Frog) in lane9
    // When frogY == 0 the game is over
    frogX = WIDTH / 2;
    frogY = HEIGHT - 1;
}

// printing the board every
void draw()
{
    // Use "cls" for Windows. Following line everytime cleans the previous prints
    system("clear");

    // CODE: print the position of Frog (frogX and frogY) with char 'F' and lanes[][]
    
    // Everytime the following line is going to be printed
    printf("Use W, A, S, D to move. Reach the top to win!\n");
}

// updating frogY and frogX based on user input from kbhit()
void input()
{
    if (kbhit())
    {
        switch (getchar())
        {
            // CODE: update the poistion of frog (frogY/frogX) based on inputs from kbhit()
        }

        // CODE: Ensure frog stays within boundaries

        // CODE: Check for collisions with 'x'
        // if there is a collision the game is over and exit(0)
    }
}

void logic(int updateLanes)
{
    // CODE: if (counter % 5 == 0) then updateLanes = 1
    // and if updateLanes = 1 then:
    // First: for i = 0; i < HEIGHT call function updateLane(i)
    // Second: Check win condition (If frogY == 0 you win then exit(0))
    // Note: The collision condition was already check in function input()
}

void updateLane(int lane)
{
    // CODE: lanes[lane] must be updated based on speeds[lane]
    // (moving left or right based on their speed)
}

// receiving inputs from keyboard
int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
