#include <stdio.h>
#include <stdlib.h>
#define RSIZE 100
#define CSIZE 100
struct node
{
    int r, c, val;
    struct node *nextInRow, *nextInColumn;
}
void input_element(int *A, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("Enter the elements in the Sparsed Matrix: \n [%d] [%d]: ", i + 1, j + 1);
            scanf("%d", (A + i * col) + j);
        }
    }
}
int arr_to_link(int *A, struct node *row_head[], struct node *col_head[], int row, int col)
{
    int i, j;
    struct node *new_node, *row_temp[row], *col_temp[col];
    for (i = 0; i < row; i++)
    {
        row_temp[i] = row_head[i];
    }
    for (j = 0; j < col; j++)
    {
        col_temp[j] = col_head[j];
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (*((A + i * col) + j) != 0)
            {
                new_node = (struct node *)malloc(sizeof(struct node));
                if (new_node == NULL)
                {
                    printf("Memory allocation failed");
                    return -1;
                }
                else
                {
                    new_node->r = i;
                    new_node->c = j;
                    new_node->val = *((A + i * col) + j);
                    new_node->nextInRow = NULL;
                    new_node->nextInColumn = NULL;
                    if (row_head[i] == NULL)
                    {
                        row_head[i] = new_node;
                        row_temp[i] = new_node;
                    }
                    else
                    {
                        row_temp[i]->nextInRow = new_node;
                        row_temp[i] = new_node;
                    }
                    if (col_head[j] == NULL)
                    {
                        col_head[j] = new_node;
                        col_temp[j] = new_node;
                    }
                    else
                    {
                        col_temp[j]->nextInColumn = new_node;
                        col_temp[j] = new_node;
                    }
                }
            }
        }
    }
}
void PrintMatrix(struct node *row_head[], int row, int col)
{
    int i, j, k;
    for (i = 0; i < row; i++)
    {
        struct node *temp = row_head[i];
        k = 0;
        while (temp != NULL)
        {
            if (temp->c == k)
            {
                printf("%d ", temp->val);
                temp = temp->nextInRow;
                k++;
            }
            else
            {
                printf("0 ");
                k++;
            }
        }
        for (j = 0; j < col - k; j++)
        {
            printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    int i, j, row, col;

    do
    {
        printf("Enter the number of rows of your matrix: \n");
        scanf("%d", &row);
        if (row <= 0 || row > RSIZE)
        {
            printf("Choose the no. of rows between 0 to %d: \n", RSIZE);
        }
    } while (row <= 0 || row > RSIZE);
    do
    {
        printf("Enter the number of coloums of your matrix: \n");
        scanf("%d", &col);
        if (col <= 0 || col > CSIZE)
        {
            printf("Choose the no. of coloumns between 0 to %d: \n", CSIZE);
        }
    } while (col <= 0 || col > CSIZE);
    int A[row][col];
    input_element(&A[0][0], row, col);
    struct node *row_head[row], *col_head[col];
    for (i = 0; i < row; i++)
    {
        row_head[i] = NULL;
    }
    for (j = 0; j < row; j++)
    {
        col_head[j] = NULL;
    }
    arr_to_link(&A[0][0], row_head, col_head, row, col);
    PrintMatrix(row_head,row,col);
    return 0;
}