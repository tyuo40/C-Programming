//Homework 2 CS222 John Parsons G00961220

#include <stdio.h>

int get_input();
void display(int n);

int	main(void) //Main function calls getinput UDF then display UDF. Lastly, determines if the number is divisible by 9 evenly.
{
	int x = get_input();
	display(x);
	if (x%9 == 0) 
	{printf("%d is divisible by 9\n",x);}
	if (x%9 != 0)
	{printf("%d is not divisible by 9\n",x);}
	
	return	0;	
}	
void display(int n) //Loops through integer separating digits and displaying them
{	
	int c;
	
	while(n!=0)
	{
	c = n%10;
	printf("%d\n", c);
	n = n/10;
	}
}

int get_input() //Gets input from user and determines if input is valid
{
	int x;
	int i;
	i = 1;
	while (i=1)
	{
	printf("Enter an integer (1-999999): ");
	scanf("%d",&x);
	if(x<=999999 && x>=1)
	{break;}
	else
	{printf("Invalid input, please re-enter an integer");}
	}
	return x;
}