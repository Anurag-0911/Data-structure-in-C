#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* search(struct node*,int);
int main()
{
    int val;
    struct node *element_ptr, *head, *tail, *two, *three;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    two = (struct node*)malloc(sizeof(struct node));
    two->data = 6;
    head->next = two;
    three = (struct node*)malloc(sizeof(struct node));
    three->data = 7;
    two->next = three;
    three->next = NULL;
    element_ptr = search(head,val);
    if(element_ptr != NULL)
    printf("Element found at position %d ");
    else
        printf("Element not found");
        return 0;
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
struct node *search(struct node*head,int val)
{
    struct node*ptr = head;
    printElement(head);
    printf("\nsearching the list for value:\n");
    scanf("%d",&val);
    while(ptr != NULL)
    {
        if(ptr -> data == val)
        {
            return ptr;
        }
        else
        {
            ptr = ptr -> next;
        }
    }
    return NULL;
}        