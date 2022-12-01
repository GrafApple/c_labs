#include <stdio.h>
#include <math.h>

double f(int n) {
    double h, x, intgr = 0;
    double a = 0;
    double b = 2;
    h = (b-a)/n;
    for (x = a ; x <= 2; x += h)
     {
        double func;
        if (x <= 1)
            func = cos(x)*exp(pow(-x,2));
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
