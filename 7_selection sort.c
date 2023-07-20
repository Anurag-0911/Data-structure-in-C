#include <stdio.h>
#define SIZE 50
void selectionsort(int[], int);
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
    selectionsort(a,n);

    printf("The resultant array is:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void selectionsort(int a[],int n)
{
    int i,j,minm,temp;
    for(i = 0;i < n-1; i++)
    {
        minm = i;
        for(j = i + 1;j < n;j++)
        {
            if(a[j] < a[minm])
            {
                minm = j;
            }
        }
            
            temp = a[minm];
            a[minm] = a[i];
            a[i] = temp;
    }
}
