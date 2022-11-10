#include <stdio.h>
#include <math.h>
int main()
{
    double x,f,h,s;
    int i=0;
    x=0;
    printf("Enter h (0<h<=2) \n");
    scanf("%lf",&h);
    s=2.00/h;
    if (h>0 && h<=2)
    {
    printf("\tx\tf(x)\n");
    printf("-----------------------\n");
    while(i<=s)
    {
        x=i*h;
        if(x>=0.00 && x<=1.00)
            f=cos(x)*exp(pow(-x,2));
        else
            f=log(x+1.00)-sqrt(4.00-x*x);
        
        printf("%lf\t%lf\n",x,f);
        i++;
    }
    }
    else 
    {
        printf("incorect h"); 
    }
    return 0;
}
