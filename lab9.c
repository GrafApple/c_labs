#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[255];
    fgets(str,255,stdin);//считывает символы из потока и сохраняет их в виде строки
    int i=0,sim=1,slv=1;
    while(str[i]==' ' || str[i]==',' || str[i]=='.')
    {
        i++;
    }
    while(str[i]!='\n')
    {
        if (sim==slv)
            {
                printf("%c",str[i]);
            }
        if (str[i]==' ' || str[i]==',' || str[i]=='.') 
            {
                slv++;
                sim=0;
            }
            sim++;
            i++;
    }
    return 0;
    }
