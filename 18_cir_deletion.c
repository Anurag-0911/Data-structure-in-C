#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int cir_deletion(struct node **head, struct node **tail, int *ele, int pos)
{
    int i;
    struct node *temp, *prev, *temp1;
    if (*head == NULL)
    {
        printf("As list is empty so,deletion is not possible \n");
        return -1;
    }
    else if (pos < 1)
    {
        printf("Invalid position,Please choose appropriate position\n");
        return -1;
    }
    else if (pos == 1)
    {
        temp = *head;
        *head = (*head)->next;
        (*tail)->next = *head;
        (*head)->prev = *tail;

        //  (*head)->prev = NULL;
        *ele = temp->data;
        free(temp);
        return 0;
    }
    else
    {
        temp = *head;
        i = 1;
        while (i < pos - 1 && temp->next != *head)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == *head)
        {
            printf("Deletion is not possible as postion exceeds the limit \n");
            return -1;
        }
        else
        {
            temp1 = temp->next;
            if (temp1->next != *head)
            {

                temp1->next->prev = temp;
                temp->next = temp1->next;
            }
            else
            {
                *tail = temp;
                temp->next = *head;
            }
            *ele = temp1->data;
            free(temp1);
            printf("\n%d is the deleted element", *ele);
            
            return 0;
        }
    }
}
void printElement(struct node **head)
{
    struct node *ptr;
    ptr = (*head);
    printf("\nElements in the linked list are: ");
    printf("%d ", ptr->data);
    ptr = ptr->next;
    while (ptr != *head)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head, *tail, *two, *three;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    two = (struct node *)malloc(sizeof(struct node));
    two->data = 6;
    head->next = two;
    three = (struct node *)malloc(sizeof(struct node));
    three->data = 7;
    two->next = three;
    three->next = head;
    head->prev = three;
    tail = three;
    int ele;
    printElement(&head);
    int pos;
    printf("\nchoose the position where you want deletion:\n");
    scanf("%d", &pos);
    cir_deletion(&head, &tail, &ele, pos);
    
    printf("\n New Elements in the linked list are: ");
    struct node *ptr = head;
    printf("%d ", ptr->data);
    ptr = ptr->next;
    while (ptr != head)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
