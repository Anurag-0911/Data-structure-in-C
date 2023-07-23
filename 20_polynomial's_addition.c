#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef;
    int expo;
    struct node *next;
};
int poly(struct node **head, struct node **tail, int len)
{
    if (len == 0)
    {
        *head = NULL;
    }
    else
    {
        struct node *new_node, *temp;
        new_node = (struct node *)malloc(sizeof(struct node));
        temp = new_node;
        if (new_node == NULL)
        {
            printf("Memory allocation failed");
            return -1;
        }
        else
        {
            *head = new_node;
            printf("Enter the coefficient: ");
            scanf("%d", &new_node->coef);
            printf("Enter the exponent: ");
            scanf("%d", &new_node->expo);
            int i = 1;
            while (i != len)
            {
                new_node = (struct node *)malloc(sizeof(struct node));
                temp->next = new_node;
                temp = new_node;
                if (new_node == NULL)
                {
                    printf("Memory allocation failed");
                    return 0;
                }
                else
                {
                    printf("Enter the coefficient: ");
                    scanf("%d", &new_node->coef);
                    printf("Enter the exponent: ");
                    scanf("%d", &new_node->expo);
                }
                i++;
            }
            new_node->next = NULL;
            *tail = new_node;
        }
    }
}
void printElement(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->coef);
        printf("%d  ", ptr->expo);
        ptr = ptr->next;
    }
    printf("\n");
}
void merg(struct node **head1, struct node **tail1, struct node **head2, struct node **tail2, struct node **head3, struct node **tail3)
{
    if (*head1 == NULL)
    {
        *head3 = *head2;
        *tail3 = *tail2;
    }
    else if (*head2 == NULL)
    {
        *head3 = *head1;
        *tail3 = *tail1;
    }
    else
    {
        *head3 = *head1;
        (*tail1)->next = *head2;
        (*tail3) = *tail2;
    }
}
// void sort(struct node **head, struct node **tail)
// {
//     struct node *ptr1 = *head;
//     struct node *ptr2 = *head;
//     int c;
//     while (ptr1 != *tail)
//     {
//         while (ptr2 != *tail)
//         {
//             if (ptr1->expo < ptr2->expo)
//             {
//                 c = ptr1->expo;
//                 ptr1->expo = ptr2->next->expo;
//                 ptr2->next->expo = c;
//                 c = ptr1->coef;
//                 ptr1->coef = ptr2->next->coef;
//                 ptr2->next->coef = c;
//             }
//             ptr2 = ptr2->next;
//         }
//         ptr1 = ptr1->next;
//         ptr2 = ptr1;
//     }
// }
int main()
{
    struct node *head1 = NULL, *tail1 = NULL;
    struct node *head2 = NULL, *tail2 = NULL;
    struct node *head3 = NULL, *tail3 = NULL;

    int len;
    do
    {
        printf("Enter the number of terms in your first polynomial:\n");
        scanf("%d", &len);
        if (len < 0)
        {
            printf("Term should be greater than or equal to 0");
        }
    } while (len < 0);
    poly(&head1, &tail1, len);
    do
    {
        printf("Enter the number of terms in your second polynomial:\n");
        scanf("%d", &len);
        if (len < 0)
        {
            printf("Term should be greater than or equal to 0");
        }
    } while (len < 0);
    poly(&head2, &tail2, len);
    printf("First polynomial is as follows:\n");
    printElement(head1);
    printf("Second polynomial is as follows:\n");
    printElement(head2);
    merg(&head1, &tail1, &head2, &tail2, &head3, &tail3);
    sort(&head3, &tail3);
    printf("Resultant polynomial after adding both polynomials is:\n");
    printElement(head3);
}
