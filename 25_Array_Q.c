#include <stdio.h>
#include <stdlib.h>
#define MAX_Q 20
#define SUCCESS 0
#define ERROR -1
struct queue
{
    int item[MAX_Q];
    int front;
    int rear;
};
int Enqueue(struct queue *qptr, int data)
{
    if ((qptr)->rear == MAX_Q - 1)
    {
        printf("Queue is full!");
        return ERROR;
    }
    else
    {
        (qptr)->rear++;
        (qptr)->item[(qptr)->rear] = data;
        printf("%d is the Enqued element.\n",data);
        return SUCCESS;
    }
}
int Dequeue(struct queue *qptr, int *data)
{
    if ((qptr)->front > (qptr)->rear)
    {
        printf("Queue is empty!");
        return ERROR;
    }
    else
    {
        *data = (qptr)->item[(qptr)->front];
        (qptr)->front++;
        printf("%d is the Dequed element.\n",*data);
        return SUCCESS;
    }
}
void display(struct queue q)
{
    int i;
    if (q.front > q.rear)
        printf("Queue is Empty!");
    else
    {
        printf("The Queue is: \n");
        for (i = q.front; i <= q.rear; i++)
            printf("%d \n", q.item[i]);
    }
}
int main()
{
    struct queue q;
    int data, user_ch;
    q.front = 0;
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
            display(q);
        }
    } while (user_ch != 0);
    return 0;
}
