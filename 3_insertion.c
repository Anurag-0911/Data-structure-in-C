#include<stdio.h>
#define SIZE 100
//Function for inserting element in an array
int insertion (int[], int, int, int);
int main ()
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
  printf ("Enter the number which you want to insert:\n");
  scanf ("%d", &num);
  do
    {
      printf
	("Enter the location at which you want to insert your number:\n");
      scanf ("%d", &loc);
      if (loc <= 0 || loc > SIZE)
	printf ("Invalid location! Please choose valid location.");
    }
  while (loc <= 0 || loc > SIZE);
  insertion (a, n, num, loc);
  printf ("Now the resultant array is:\n");
  for (i = 0; i <= n; i++)
    {
      printf ("%d ", a[i]);
    }

  return 0;
}

int
insertion (int arr[], int n, int num, int loc)
{
  int i;
  if ((loc - 1) > n)
    loc = n + 1;
  for (i = (n - 1); i >= (loc - 1); i--)
    {
      arr[i + 1] = arr[i];
    }
  arr[loc - 1] = num;
  return 0;
}
