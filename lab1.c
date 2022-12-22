#include <stdio.h>

int minik(int a, int b)
{
if (a<b) return a;
else return b;
}

int main()
{
int a, b, c, x, y;
printf("Enter a -> ");
scanf("%d", &a);
printf("Enter b -> ");
scanf("%d", &b);
printf("Enter c -> ");
scanf("%d", &c);
printf("Enter x -> ");
scanf("%d", &x);

y=minik(a, minik(b,c));
if (y<=x && y%7==0) printf("%d", y);

else
{
if (y==a) printf("%f", (float)a/(c+b));
else if (y==c) printf("%f", (float)c/(a+b));
else if (y==b) printf("%f", (float)b/(a+c));
}

return 0;
}
Footer
