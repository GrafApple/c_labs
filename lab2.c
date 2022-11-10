#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    printf("Enter x {-1.7715 < x < 0.7715} -> ");
    scanf("%lf", &x);
    if (x>=-1.7715f && x<=0.7715f)
    {
        double y = (pow(2, x)+pow(2, -x)/2);
        double z = sqrt(2+y-pow(y, 2));
        printf("y(x) = %lf, z(y) = %lf\n", y, z);
    }
    else
        printf("Value (x) is wrong!\n");
    return 0;
}
