#include <stdio.h>
#define SIZE 100
int linearSearch(int [], int, int);
int main()
{
    int a[SIZE], i, key, pos, n;
    do
    {
        printf("Enter the no. of elements (<=%d) in the array \n", SIZE);
        scanf("%d", &n);
        if (n <= 0 || n > SIZE)
           printf("Enter the value > 0 and <= %d", SIZE);
    }
    while(n <= 0 || n > SIZE);
    printf("Enter the elements of the array:\n");
    for (i = 1; i <= n; i++)
    {
        printf("a[%d]:", i);
        scanf("%d", &a[i]);
    }
    printf("Enter the Search key\n");
    scanf("%d", &key);
    pos = linearSearch(a, n, key);
    if(pos == -1)
        printf("The search key is not in the array\n");
    else
        printf("The search key %d is found at the location %d\n", key, pos);
    return 0;
}
int linearSearch(int b[], int size, int skey)
{
    int i;
    for(i=1; i<=size; i++)
    {
        if(b[i] == skey)
        return i;
    }
    return -1;
}
