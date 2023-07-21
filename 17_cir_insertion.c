#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *cir_insertion(struct node **head, struct node **tail, int ele, int pos)
{
    int i;
    struct node *new_node, *temp;

    new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = ele;
    if (new_node == NULL)
    {
        printf("Dynamic memory allocation failed,insertion cannot be done \n");
        return NULL;
    }
    else
    {
        if (pos < 1)
        {
            printf("Inappropriate position,Choose the position carefully \n");
            return NULL;
        }
        else if (pos == 1)
        {
            new_node->next = *head;
            new_node->prev = *tail;
            (*tail)->next = new_node;
            (*head)->prev = new_node;
            *head = new_node;
        }
        else
        {
            temp = *head;
            i = 1;
            while (i < pos - 1 && temp->next != (*head))
            {
                i++;
                temp = temp->next;
            }
            if (temp->next != (*head))
            {
                new_node->next = temp->next;
                temp->next->prev = new_node;
                new_node->prev = temp;
                temp->next = new_node;

                //     new_node->prev = temp;
                //     new_node->next = temp->next;
            }
            else
            {
                new_node->prev = temp;
                new_node->next = *head;
                temp->next = new_node;
            }
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
    printf("\nEnter which element you want to insert:\n");
    scanf("%d", &ele);
    int pos;
    printf("choose the position where you want to insert:\n");
    scanf("%d", &pos);
    cir_insertion(&head, &tail, ele, pos);
    printf("\nElement to be inserted is: %d\n", ele);
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
