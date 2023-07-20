#include <stdio.h>
#define SIZE 50
void swap(int[], int);
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
    swap(a,n);
    
    printf("The resultant array is:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void swap(int a[],int n)
{
    int i,j,b;
    for(i = 0;i < n; i++)
    {
        for(j = 0; j < i+1; j++)
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






