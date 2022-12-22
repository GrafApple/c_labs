#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool rec(unsigned int n, unsigned int g)
{
    if(g>n/2)return true;
    return n%g ? rec(n,++g):false;
}
bool cyc(unsigned int n)
{
    for (unsigned int i=2;i<n;i++)
        if(n%i==0)
        return false;
    return true;
} 
int main()
{
 unsigned int n,g;
 g=2;
 printf ("vvedite chislo\t");
 scanf("%u",&n);
printf("cycle result=%d\nRec result=%d\n",cyc(n),rec(n,g));
}
Footer
