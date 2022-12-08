#include <stdio.h>
#include <math.h>

double f(int n) {
    double h, i, intgr = 0;
    double a = 0;
    double b = 2;
    double x;
    double func;
    h = (b-a)/n; 
    for (i = 0; i < n; i++)
    {
        x=a+i*h+h*0.5;
         if (x <= 1)
            func = cos(x)*exp(-x*x);
        else
            func = log(x+1)-sqrt(4-x*x);
        intgr += func;
    }
    intgr *= h;
    return intgr;
}
int main() {
    double e;
    printf("Введите точность > ");
    scanf("%lf", &e);
    int n = 1;
    double intgr1 = 0;
    double intgr2 = 1;
    while ((fabs(intgr2 - intgr1) / 3) >= e) {
            n *= 2;
            intgr1 = intgr2;
            intgr2 = f(n * 2);
    }
    printf("%lf\n", intgr2);
    return 0;
}
