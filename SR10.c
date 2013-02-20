//Exercise 10. Variant 3. Yaskovich Dmitry (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//defining header files
#include <stdlib.h>

#define QTY_1 10   //defining quantity of elements in arrays
#define QTY_2 8
#define QTY_3 6

int filling(int a, int b, int qty, int *array); //functions prototypes
int output(int qty, int *array);

int main(void)//main function
{
 int a,b,array_1[QTY_1],array_2[QTY_2]; //declaration of variables
 printf("Enter a and b: ");//input
 scanf("%d %d", &a,&b);
 filling(a,b,QTY_1,array_1);//filling arrays with numbers
 filling(a,b,QTY_2,array_2);
 output(QTY_1,array_1);//output of arrays
 output(QTY_2,array_2);
 fflush(stdin);//waiting for the user
 getchar();
 return 0;
}

int filling(int a, int b, int qty, int *array)//function of filling array
{
 int i;//declaration of variables
 for (i = 1; i <=qty; i++)//filling array
 {
  array[i-1]=a+b*rand()/RAND_MAX;
 }
}

int output(int qty, int *array)//function of output
{
 int i,j,cycles;//declaration of variables
 printf("|   Element   |");
 for (i = 1; i <=qty; i++) //repeats for all elements
 {
  printf(" %10d |",i);//output of element number
  if ((i%5==0)&&(i!=qty)) //catching end of line
  {
   printf("|    Value    |");
   for (j=5; j >=1; j--)//output of values
   {
	printf(" %10d |",(array[i-j]));
   }
	printf("|   Element   |");
  }
  else //or last element
  {
   if (i==qty)
   {
	if (i%5!=0)
	{
	 printf("\n");
	}
	printf("|    Value    |");//output of values
	if (i%5==0)
	 cycles=5;
	else
	 cycles=(i%5);
	for (j=cycles; j >=1; j--)
	{
	 printf(" %10d |",array[i-j]);
	}
	printf("\n\n"); //indent before next array
   }
  }
 }
}

