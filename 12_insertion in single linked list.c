#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *insertion(struct node **head, struct node **tail, int ele, int pos)
{
    int i;
    struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Dynamic memory allocation failed,insertion cannot be done \n");
        return NULL;
    }
    else
    {
        new_node->data = ele;
        if (pos < 1)
        {
            printf("Inappropriate position \n");
            return NULL;
        }
        else if (*head == NULL)
        {
            new_node->next = NULL;
            *head = *tail = new_node;
            return (new_node);
        }
        else if (pos == 1)
        {
            new_node->next = *head;
            *head = new_node;
            return (new_node);
        }
        else
        {
            temp = *head;
            i = 1;
            while (i < pos - 1 && temp != NULL)
            {
                temp = temp->next;
                i++;
            }
        }
        if ((temp == NULL) || (i == pos - 1) && (temp->next == NULL))
        {
            new_node->next = NULL;
            (*tail)->next = new_node;
            (*tail) = new_node;
            return (new_node);
        }
        else
        {
            new_node->next = temp->next;
            temp->next = new_node;
            return (new_node);
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
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    two = (struct node*)malloc(sizeof(struct node));
    two->data = 6;
    head->next = two;
    three = (struct node*)malloc(sizeof(struct node));
    three->data = 7;
    two->next = three;
    three->next = NULL;
    int ele;
    printElement(head);
    printf("\nEnter which element you want to insert:\n");
    scanf("%d", &ele);
    int pos;
    printf("choose the position where you want to insert:\n");
    scanf("%d", &pos);
    insertion(&head, &tail, ele, pos);
    printf("\nElement to be inserted is: %d\n", ele);
    printf("\nNew Elements are:  ");
    struct node *ptr = head;
    while (ptr != NULL)    
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
