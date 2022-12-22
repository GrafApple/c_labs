#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int m, int a[n][m])
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%4d", a[i][j]=rand()%101-50);
        }
        printf("\n");
    }
}

double chast(int n, int m, int a[n][m])
{
    int i,j;
    double sled=0, proiz=0, chas;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
            {
                sled+=a[i][j];
            }
        }
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
    int n,m;
    printf("Enter n-> ");
    scanf("%d", &n);
    printf("Enter m-> ");
    scanf("%d", &m);
    int a[n][m];
    fill(n,m,a);
    printf("%lf\n", chast(n,m,a));
    return 0;    
}
