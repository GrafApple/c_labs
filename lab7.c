#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int a[n][n])
{
    int i,j;
    printf("Matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%4d", a[i][j]=rand()%101-50);
        }
    printf("\n");
    }
}

double chast(int n, int a[n][n])
{
    int i,j;
    double sled=0, proiz=0, chas;
    for(i=0; i<n; i++)
    {
        sled+=a[i][i];
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            proiz+=a[i][j]*a[j][i];
        }
    }
    chas=sled/proiz;
    return chas;        
}

int main()
{
    srand(time(NULL));
    int n;
    printf("Enter n-> ");
    scanf("%d", &n);
    int a[n][n];
    fill(n,a);
    printf("chas=%lf\n", chast(n,a));
    return 0;    
}
