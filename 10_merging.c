#include <stdio.h>
#define SIZEA 50
#define SIZEB 50
#define SIZEM 100
void merge(int[], int[], int[], int, int);
int main()
{
    int a[SIZEA], b[SIZEB], m[SIZEM],na,nb,i;
    do
    {
        printf("Enter the no. of elements (<=%d) in the array A \n", SIZEA);
        scanf("%d", &na);
        if (na <= 0 || na > SIZEA)
        {
           printf("Enter the value > 0 and <= %d", SIZEA);
           scanf("%d", &na);
        }
    } while (na <= 0 || na > SIZEA);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < na; i++)
    {
        printf("a[%d]:", i);
        scanf("%d", &a[i]);
    }
     do
    {
        printf("Enter the no. of elements (<=%d) in the array B \n", SIZEB);
        scanf("%d", &nb);
        if (nb <= 0 || nb > SIZEB)
        {
           printf("Enter the value > 0 and <= %d", SIZEB);
           scanf("%d", &nb);
        }
    } while (nb <= 0 || nb > SIZEB);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < nb; i++)
    {
        printf("b[%d]:", i);
        scanf("%d", &b[i]);
    }
    merge(a, b, m, na, nb);

    printf("The resultant array after merging:\n");
    for (int i = 0; i < (na + nb); i++)
    {
        printf("%d ", m[i]);
    }
    return 0;
}
//     merge(a, b, m, na, nb);                                        
    
//     printf("The resultant array after merging:\n");
//     for (int i = 0; i < (na + nb); i++);
//     {
//         printf("%d ", m[i]);
//     }
//     return 0;                                                     
// }
void merge(int a[],int b[],int m[],int na ,int nb)
{
    int i;
    for (int i = 0; i < (na + nb); i++)
    {
        if (i < na)
        {
            m[i] = a[i];
        }
        else if(i >= na)
        {
            m[i] = b[i-na];
        }
    }
    
}