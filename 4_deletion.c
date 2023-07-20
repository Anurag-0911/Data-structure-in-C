#include<stdio.h>
#define SIZE 100
//Function for deleting element in an array
int deletion (int[], int, int, int);
int
main ()
{
  int a[SIZE], n, num, loc, i;
  do
    {
      printf ("Enter the number of elements in array (<=%d): \n", SIZE);
      scanf ("%d", &n);
      if (n <= 0 || n > SIZE)
	printf ("Please Enter the number between 1 to %d \n ", SIZE);
    }
  while (n <= 0 || n > SIZE);
  printf ("Enter the values of the arrays \n");
  for (i = 0; i < n; i++)
    {
      printf ("a[%d]:", i);
      scanf ("%d", &a[i]);
    }
  do
    {
      printf("Enter the location from which you want to delete your number:\n");
      scanf ("%d", &loc);
      if (loc < 0 || loc > SIZE)
	printf ("Invalid location! Please choose valid location for deletion.\n");
    }
  while (loc < 0 || loc > SIZE);
  deletion (a, n, num, loc);
  printf ("Now the resultant array is:\n");
  for (i = 0; i < n-1; i++)
    {
      printf ("%d ", a[i]);
    }
    return 0;
}

int deletion (int a[], int n, int num, int loc)
{
  int i;
  for(i = loc;i<n-1;i++)
     a[i]=a[i+1];
     
     n = n-1;
     return n;
}     
