#include <stdio.h>
#define MAX 100
#define ERROR -1
#define SUCCESS 0
int stack_push(int[], int *, int *);
int stack_pop(int[], int *, int *);
void display(int[],int);
int main()
{
    int stack[MAX], item, top = -1, user_ch;
    do
    {
        printf("\nEnter 1 for Pushing in Stack\n");
        printf("Enter 2 for Poping in Stack\n");
        printf("Enter 3 for Displaying the Stack\n");
        printf("Enter 0 to exit the Program\n");
        printf("Enter: ");
        scanf("%d", &user_ch);

        if (user_ch == 1)
        {

            printf("Enter the element for stack push: \n");
            scanf("%d", &item);
            stack_push(stack, &top, &item);
        }
        else if (user_ch == 2)
        {

            stack_pop(stack, &top, &item);
        }
        else if(user_ch == 3)
        {
            display(stack,top);
        } 
    } while (user_ch != 0);
    return 0;
}
int stack_push(int stack[], int *top, int *item)
{
    if (*top == (MAX - 1))
    {
        printf("Stack overflow and hence push operation is unsuccessful\n");
        return ERROR;
    }
    else
    {
        (*top)++;
        stack[*top] = *item;
        printf("Push operation for item %d is successfully completed\n", *item);
        return SUCCESS;
    }
}
int stack_pop(int stack[], int *top, int *item)
{
    if (*top == -1)
    {
        printf("Stack underflow and hence pop operation is unsuccessful\n");
        return ERROR;
    }
    else
    {
        *item = stack[*top];
        (*top)--;
        printf("Pop operation for item %d is successfully completed\n", *item);
        return SUCCESS;
    }
}
void display(int stack[],int top)
{
    int i;
    printf("\n The stack is as follows:");
    if(top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(i = top;i>=0;i--)
        printf("\n %d",stack[i]);
    }
}
