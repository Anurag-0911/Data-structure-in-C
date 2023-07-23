#include <stdio.h>  
#include <stdlib.h>
#define MAX 20
#define SUCCESS 0
#define ERROR -1
struct node
{
    int item[MAX];
    int rear;
    int front;
};

int Enqueue(struct node *qptr, int data)
{    
    if ((qptr->front % MAX) == ((qptr->rear + 1) % MAX))
    {
        printf("Queue is full!\n");
        return ERROR;
    }
    else
    {
        if (qptr->front == -1)
        {
            qptr->front++;
        }
        
        (qptr->rear)++;
        qptr->item[(qptr->rear) % MAX] = data;
        printf("%d is the Enqued element.\n",data);
        return SUCCESS;
    } 
} 

int Dequeue(struct node *qptr, int *data)
{
    if (qptr->front == -1)
    {
        printf("Queue is empty!\n");
        return ERROR;
    }
    else
    {
        *data = qptr->item[(qptr->front) % MAX];
        if ((qptr->front) % MAX == (qptr->rear) % MAX)
        {
            qptr->rear = -1;
            qptr->front = -1;
        }
        else
        {
            qptr->front++;
        }
        printf("%d is the Dequed element.\n", *data);
        return SUCCESS;
    }
}

void display(struct node q)
{ 
    if (q.front == -1)
    {
        printf("Queue is empty!");
    }
    else
    {
        printf("The Queue is:\n");
        while (q.front <= q.rear)
        {
            printf("%d \n", q.item[(q.front) % MAX]);
            q.front++;
        }
    }
}
int main()
{
    struct node q;
    int data, user_ch, status;
    q.front = -1;
    q.rear = -1;
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
            Enqueue(&q, data);
        }
        else if (user_ch == 2)
        {
            Dequeue(&q, &data);
        }
        else if (user_ch == 3)
        {
            printf("The Element in the Queue are:\n");
            display(q);
        }
    } while (user_ch != 0);
    return 0;
}
