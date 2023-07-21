#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int deletion(struct node **head, struct node **tail, int *ele, int pos)
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
        temp->next = NULL;
        (*head)->prev = NULL;
        *ele = temp->data;
        free(temp);
        return 0;
    }
    else
    {
        temp = *head;
        i = 1;
        while (i < pos - 1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            printf("Deletion is not possible as postion exceeds the limit \n");
            return -1;
        }
        else
        {
            temp1 = temp->next;
            if (temp1->next != NULL)
            {
                temp1->next->prev = temp;
                temp->next = temp1->next;
            }
            else
            {
                *tail = temp;
                temp->next = NULL;
            }
            *ele = temp1->data;
            free(temp1);
            return 0;
        }
    }
}
void printElement(struct node *ptr)
{
    printf("\nElements in the linked list are: ");
    while (ptr != NULL)
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
    three->next = NULL;
    // int ele;
    // printf("Enter which element you want to insert:\n");
    // scanf("%d", &ele);
    int pos, ele;
    printElement(head);
    printf("\nChoose the position from where you want to delete element:\n");
    scanf("%d", &pos);
    deletion(&head, &tail, &ele, pos);
    printf("\n%d is the deleted element", ele);
    printf("\nNew Elements are:  ");
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
