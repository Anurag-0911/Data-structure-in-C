#include <stdio.h>
#define SIZE 50
void bubblesort(int[], int);
void insertionsort(int[], int); 
void selectionsort(int[], int);
void quicksort(int[], int, int);
int main()
{
    int a[SIZE], i, n, m, first, last;
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
    do
    {
        printf("Choose in which way(from 1 to 5)you want to sort your array:\n");
        scanf("%d", &m);
        if (m <= 0 || m > 5)
        {
            printf("Invalid input,Please choose the number from 1 to 5\n");
            scanf("%d", &m);
        }
    } while (m <= 0 || m > 6);

    do
    {
        switch (m)
        {
        case 1:
            bubblesort(a, n);
            printf("You have chosen bubblesort.\n The resultant array after bubblesorting:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }

        case 2:
            insertionsort(a, n);
            printf("You have chosen insertionsort.\nThe resultant array after insertionsorting:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }

        case 3:
            selectionsort(a, n);
            printf("You have chosen selectionsort.\nThe resultant array after selectionsorting:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }

        case 4:
            quicksort(a, first = 0, last = i - 1);
            printf("You have chosen quicksort.\nThe resultant array after quicksorting:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }

        case 5:
            break;
        }
        do
        {
            printf("Choose in which way(from 1 to 5)you want to sort your array:\n");
            scanf("%d", &m);
            if (m <= 0 || m > 5)
            {
                printf("Invalid input,Please choose the number from 1 to 5\n");
                scanf("%d", &m);
            }
        } while (m <= 0 || m > 6);
    } while (m > 0 || m < 6);

    return 0;
}

void bubblesort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void insertionsort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i <= n - 1; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j = j - 1;
            a[j + 1] = temp;
        }
    }
}
void selectionsort(int a[], int n)
{
    int i, j, minm, temp;
    for (i = 0; i < n - 1; i++)
    {
        minm = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[minm])
            {
                minm = j;
            }
        }

        temp = a[minm];
        a[minm] = a[i];
        a[i] = temp;
    }
}
void quicksort(int a[], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (a[i] <= a[pivot] && i < last)

                i++;
            while (a[j] > a[pivot])
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}
