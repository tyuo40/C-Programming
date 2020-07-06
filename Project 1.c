//Homework 1 CS222 John Parsons G00961220

#include <stdio.h>
int main(void)
{
	int number;
	//scan for input store to "number" variable
	printf("Enter an integer:");
	scanf("%d",&number);
	
	//is number negative?
	if (number<0)
	{
		printf("%d is negative.\n",number);
		if (number%2==0)
		printf("Even number");
		if (number%2==1)
		printf("Odd number");
		
	}
	//is number zero?
	if (number == 0)
	{
		printf( "%d is zero.\n",number);
		printf("Number is zero");
	}
	//must be non-negative number
	if (number >0)
	{
		printf("%d is positive.\n",number);
		if (number%2==0)
		printf("Even number");
		if (number%2==1)
		printf("Odd number");
	}
	return 0;
}

