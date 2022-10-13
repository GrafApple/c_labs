#include<stdio.h>

int minik(int a, int b){
    if (a<b) return a;
    else return b;
}
int main(){
    int a=8, b=90, c=7, x=50, y;
    y=minik(a,minik(b,c));
    if (y<=x && y%7==0) printf("%d",y);
    else
    {
        if (y==a){ 
        
        printf("%f", (float)a/(c+b));}
        else if (y==b){ 
        
        printf("%f", (float)b/(c+a));}
        else if (y==c){
        
        printf("%f", (float)c/(a+b));}
    }
    return 0;
}