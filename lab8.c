#include <ctype.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}
int main()
{
    int count = 0;
    unsigned char a;
    for(;;)
    {
        a = mygetch();
        if(isalpha(a))
            count++;
        printf("%c", a);
        if(a == 0x21)
            break;
    }
    if (count != 0)
    {
        printf("\nKKolichestvo bukv: %d", count);
    }
    else
    {
        printf("\nBBukv net!");
    }
    return 0;
}
