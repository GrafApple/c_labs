#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio_ext.h>

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

void wheel(int n, int c, int last_num_print[n]) {
    for (int i = 0; i < n - 1; i += 1) {
        last_num_print[i] = last_num_print[i + 1];
    }
    last_num_print[n] = c;
}

int main()
{
    int c;
    int count=0;
    int i, n = 4, end_c, print = 1;
    int last_num[n], last_num_print[n];
    for (i = 0; i < n; i += 1) {
        last_num[i] = 0;
        last_num_print[i] = 0;
    }

    int end_num[] = {27, 91, 53, 126};

    while (true) {
        c = mygetch();
        for (i = 0; i < n - 1; i += 1) {
            last_num[i] = last_num[i + 1];
            last_num_print[i] = last_num_print[i + 1];
        }
        last_num[n-1] = c;
        last_num_print[n-1] = c;
        end_c = 0;
        for (i = 0; i < n; i += 1) {
            if (last_num[i] == end_num[i]) {
                end_c += 1;
            }
        }
        if (n == end_c) {
            break;
        }
        print = 1;
        for (i = 0; i < n; i += 1) {
            if (last_num_print[i] == 27) {
                if ((last_num_print[i] == 27 && last_num_print[i+1] == 79) || (last_num_print[i] == 91 && last_num_print[i+1] == 49)){
                    print = 0;
                    wheel(n, c, last_num_print);
                    wheel(n, c, last_num_print);
                    __fpurge(stdin);
                    break;
                }  
                print = 0;
             }
        }
        if (print == 1) {
            if(c!='~'){
                printf("%c", c);
            }
            if(isalpha(c)!=0){
                count++;
            }
        }
    }
    printf("\n");
    printf("count = %d", count);
    printf("\n");
    return 0;
}
