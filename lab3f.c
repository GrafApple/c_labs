#include <stdio.h>
#include <math.h>
int main()
{
    double x,f,h,s;
    x=0;
    printf("Enter h (0<h<=2) \n");
    scanf("%lf",&h);
    s=2.00/h;
    if (h>0 && h<=2)
    {
    printf("\tx\tf(x)\n");
    printf("--------------------------\n");
    for(int i=0;i<=s;i++)
    {
        x=i*h;
        if(x>=0 && x<=1)
            f=cos(x)*exp(pow(-x,2));
        else
            f=log(x+1)-sqrt(4-x*x);
        printf("%lf\t%lf\n",x,f);
    }
    }
    else 
    {
        printf("incorect h"); 
    }
    return 0;
}
