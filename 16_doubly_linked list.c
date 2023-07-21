#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
int list(struct node **head, int n)
{
    if (n == 0)
    {
        *head == NULL;
    }
    else if (n > 0)
    {
        struct node *ptr;
        struct node *new_node;
        new_node = (struct node *)malloc(sizeof(struct node));
        *head = new_node;
        ptr = *head;
        printf("Enter the elements is list:\n");
        scanf("%d", &ptr->data);
        int i;
        for (i = 1; i < n; i++)

        {
            new_node = (struct node *)malloc(sizeof(struct node));
            ptr->next = new_node;
            new_node->prev = ptr;
            ptr = new_node;
            scanf("%d", &ptr->data);
        }
    }
}
struct node *insertion(struct node **head, struct node **tail, int ele, int pos)
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
            new_node->prev = NULL;
            new_node->next = *head;
            (*head)->prev = new_node;
            *head = new_node;
        }
        else
        {
            temp = *head;
            i = 1;
            while (i < pos - 1 && temp->next != NULL)
            {
                i++;
                temp = temp->next;
            }
            if (temp->next != NULL)
            {
                new_node->next = temp->next;
                temp->next->prev = new_node;
                temp->next = new_node;
                new_node->prev = temp;

                //     new_node->prev = temp;
                //     new_node->next = temp->next;
            }
            else
            {
                new_node->prev = temp;
                temp->next = new_node;
                new_node->next = NULL;
                *tail = new_node;
            }
        }
    }
}
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
    int ele, pos, user_ch, n;
    struct node *head = NULL;
    struct node *tail = NULL;
    do
    {
        printf("Enter how many element you want to insert in doubly linked list:  ");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("Please choose the positive integer\n");
        }
    } while (n < 0);
    list(&head, n);

    do
    {
        printf("\nEnter 1 for Insertion in doubly linked list\n");
        printf("Enter 2 for Deletion in doubly linked list\n");
        printf("Enter 0 to exit the Program\n");
        printf("Enter what you want: ");
        scanf("%d", &user_ch);

        if (user_ch == 1)
        {
            printf("Enter the Element you want to insert in linked list: ");
            scanf("%d", &ele);
            printf("Enter the position where you want to insert:");
            scanf("%d", &pos);
            insertion(&head, &tail, ele, pos);
            printElement(head);
        }
        else if (user_ch == 2)
        {
            printf("Enter the position where you want to delete:");
            scanf("%d", &pos);
            deletion(&head, &tail, &ele, pos);
            printElement(head);
        }
    } while (user_ch != 0);
    return 0;
}