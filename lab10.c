 #include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fail()
{
    printf("Memory allocation failure!\n");
    exit(EXIT_FAILURE);
}

void fill(int n, int *a)
{
    int i, j;
    printf("Starting matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%4d", a[i*n+j] = rand () % 101-50);
        printf("\n");
    }
}

double chas(int n, int *a)
{
    int j,i;
    double dia=0,pr=0,ch;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if(i==j) 
                dia+=a[i*n+j];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            {
                pr+=a[i*n+j]*a[j*n+i];
            }
    }
    ch=dia/pr;
    return ch;
}
int main ()
{
    srand(time(NULL));
    int n;
    printf("Razmer n -> ");
    scanf("%d", &n);
    int *a=(int *)malloc(n*sizeof(int));
    if (!a)
        fail();
    fill(n,a);
    printf("%lf\n",chas(n,a));
    free(a);
    return 0;
}
