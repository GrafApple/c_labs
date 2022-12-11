#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int arr[])
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] = rand() % 101 - 50;
}
void print(int n, int arr[])
{
    int i;
    for (i = 0; i < n; i++)
        printf("%4d", arr[i]);
    printf("\n");
}
void print3largest(int arr[], int arr_size)
{
    int i, first, second, third,i1,i2,i3;
    if (arr_size < 3) {
        printf(" Invalid Input ");
        return;
    }
    third = first = second = -100;
    for (i = 0; i < arr_size; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second) {
            third = second;
            second = arr[i];
        }
        else if (arr[i] > third)
            third = arr[i];
    }
     for(i=0;i<arr_size;i++)
     {
         if(arr[i]==first)
         {
             i1=i;
         }
         else if(arr[i]==second && i1!=i)
         {
             i2=i;
         }
         else if(arr[i]==third && i1!=i && i2!=i)
         {
             i3=i;
         }
     }
     
     int index=((i1+i2+i3)%arr_size); 
     int raz=(first*second*third)-((first+second+third)%index);
     printf("Three largest elements are %d %d %d\n", first, second, third);
     printf("Indexes: %d %d %d\n",i1,i2,i3);
     printf("Raznost: %d",raz);
}
int main()
{
    srand(time(NULL));
    int size;
    scanf("%d",&size);
    int arr[size];
    fill(size,arr);
    print(size,arr);
    print3largest(arr, size);
    return 0;
}
