#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 0
#define ERROR -1
struct node
{
    int info;
    struct node *link;
};

int Enqueue(struct node **front, struct node **rear, int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Dynamic memory allocation failed \n");
        return ERROR;
    }
    else
    {
        new_node->info = data;
        new_node->link = NULL;
        if (*rear == NULL)
        {
            *rear = new_node;
            *front = *rear;
        }
        else
        {
            (*rear)->link = new_node;
            *rear = new_node;
        }
        printf("%d is the Enqued element.\n",data);
        return SUCCESS;
    }
}
int Dequeue(struct node **front, struct node **rear, int *data)
{
    struct node *temp;
    if (*front == NULL)
    {
        printf("Queue is Empty!");
        return ERROR;
    }
    else
    {
        temp = *front;
        *data = (*front)->info;
        *front = (*front)->link;
        free(temp);
        if (*front == NULL)
            *rear = NULL;
        printf("%d is the Dequed element.\n", *data);
    }
    return SUCCESS;
}
void display(struct node *front)
{
    struct node *ptr = front;
    if (ptr == NULL)
        printf("Queue is Empty!");
    else
    {
        while (ptr != NULL)
        {
            printf("%d\n", ptr->info);
            ptr = ptr->link;
        }
    }
}
int main()
{
    struct node *front = NULL, *rear = NULL;
    int data, user_ch, status;
    do
    {
        printf("\nEnter 1 for Enqueuing the element \n");
        printf("Enter 2 for Dequeuing the element\n");
        printf("Enter 3 for Displaying the Queue\n");
        printf("Enter 0 to exit the Program\n");
        printf("Enter: ");
        scanf("%d", &user_ch);

        if (user_ch == 1)
        {

            printf("Enter the element for Enqueuing: \n");
            scanf("%d", &data);
            Enqueue(&front, &rear, data);
        }
        else if (user_ch == 2)
        {
            Dequeue(&front, &rear, &data);
        }
        else if (user_ch == 3)
        {
            printf("The Element in the Queue are:\n");
            display(front);
        }
    } while (user_ch != 0);
    return 0;
}
