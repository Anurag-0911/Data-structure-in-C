#include <stdio.h>
#define SIZE 50
void quicksort(int[], int, int);
int main()
{
    int a[SIZE],i,n,first,last;
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
    quicksort(a,first = 0,last = i -  1);
    
    printf("The resultant array is:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void quicksort(int a[] ,int first ,int last)
{
int i, j, pivot, temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(a[i] <= a[pivot] && i < last)
            i++;
            while(a[j] > a[pivot])
            j--;
             if(i < j)
             {
                 temp = a[i];
                 a[i] = a[j];
                 a[j] = temp;
             }
        }

            temp = a[pivot];
            a[pivot] = a[j];
            a[j] = temp;
            quicksort(a,first,j-1);
            quicksort(a,j+1,last);
    }
    
}
