 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

void fill(int n, int a[])
{
    int i;
    for (i=0; i<n; i++)
    {
        a[i]=rand()%101-50;
    }    
}

int max_mas(int a[], int n)
{
    int max1 =-51, max2=-51, max3=-51;
    int i1=-1, i2=-1, i3=-1;
    int i, j, ind;
    for(i=0; i<n; i++)
    {
        if((max1<a[i])&&(i!=i1))
        {
            max1=a[i];
            i1=i;
        }
    }
    for(i=0; i<n; i++)
    {
        if((max2<a[i])&&(i!=i1))
        {
            max2=a[i];
            i2=i;
        }
    }
    for(j=0; j<n; j++)
    {
        if((j!=i1)&&(j!=i2)&&(max3<a[j]))
        {
            max3=a[j];
            i3=j;
        }
    }
    printf("i1=%d\n", i1);
    printf("i2=%d\n", i2);
    printf("i3=%d\n", i3);
    printf("max1=%d\n", max1);
    printf("max2=%d\n", max2);
    printf("max3=%d\n", max3);
    ind=(i1+i2+i3)%n;
    a[ind]=(max1*max2*max3)-(max1+max2+max3);
    return (max1*max2*max3)-(max1+max2+max3);
}

int main()
{
    srand(time(NULL));
    int n, max;
    printf("Enter n-> ");
    scanf("%d", &n);
    int A[n];
    fill(n,A);
    int i;
    for (i=0; i<n; i++)
    {
        printf("%4d", A[i]);
    }
    printf("\n");
    max=max_mas(A,n);
    printf("Razn=%d", max);
    printf("\n");
    return 0;
}
