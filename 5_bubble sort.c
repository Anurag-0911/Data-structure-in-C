#include <stdio.h>
#define SIZE 50
void sort(int[], int);
int main()
{
    int a[SIZE],b,i,n;
    do
    {
        printf("Enter the no. of elements (<=%d) in the array A \n", SIZE);
        scanf("%d", &n);
        if (n <= 0 || n > SIZE)
        {
           printf("Enter the value > 0 and <= %d", SIZE);
           scanf("%d", &n);
        }
    } while (n <= 0 || n > SIZE);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        printf("a[%d]:", i);
        scanf("%d", &a[i]);
    }
    sort(a,n);

    printf("The resultant array after sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
void sort(int a[],int n)
{
    int i,j,b;
    for (i = 0; i < n; i++)
    {
       for(j = i + 1; j < n; j++)
       {
           if(a[i] > a[j])
           {
               b = a[i];
               a[i] = a[j];
               a[j] = b;
           }
       }
    }
}