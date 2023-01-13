#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fail()
{
    printf("Memory allocation failure!\n");
    exit(EXIT_FAILURE);
}

void fill(int n, int m, int *a)
{
    int i, j;
    printf("Starting matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%4d", a[i*m+j] = rand () % 101-50);
        printf("\n");
    }
}

double chas(int n, int m, int *a)
{
    int j,i;
    double dia=0,pr=0,ch;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            if(i==j) 
                dia+=a[i*m+j];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            {
                pr+=a[i*m+j]*a[j*m+i];
            }
    }
    ch=dia/pr;
    return ch;
}
int main ()
{
    srand(time(NULL));
    int n, m;
    printf("Number of lines n -> ");
    scanf("%d", &n);
    printf("Number of columns m -> ");
    scanf("%d", &m);
    int *a=(int *)malloc(n*m*sizeof(int));
    if (!a)
        fail();
    fill(n, m, a);
    printf("%lf\n",chas(n,m,a));
    free(a);
    return 0;
}
