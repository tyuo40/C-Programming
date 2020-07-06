//Homework 3 CS222 John Parsons G00961220

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char *getDateAndTime();
int getInteger(char *str);
void dec2hex(long x);
long dec2oct(long x); 
long dec2bin(long x);

int main(void)
{
	long dec,oct,bin,input2;
	char time,name[30],buf[64],input[10], filename[32];
	FILE *ptr_file;	
	
	printf("\nPlease enter your name: ");                    //Initial input gathered, name and date displayed
	fgets(name, 30, stdin);
	printf("\n%s", name);
	printf("Today's	date and time: %s\n",getDateAndTime());
	
	while(1==1)
	{
	printf("Enter an integer (1-1000000) or type x to exit: "); //Main function loop that asks for input
	fgets(buf, 64, stdin);
	dec = getInteger(buf);
	if(dec==-999)
		{
		printf("Goodbye!"); //Program termination if x is entered
		break;
		}
	bin = dec2bin(dec);
	oct = dec2oct(dec);
	printf("\nDecimal: %d \n", dec); //Conversion functions are called and the corresponding values are displayed to the user
	printf("Hexadecimal: ");
	dec2hex(dec);
	printf("\n");
	printf("Octal: %ld \n", oct);
	printf("Binary: %ld\n\n", bin);
	printf("\nSave to a file? (y/n)"); //User is prompted with option to save, if yes the user is prompted for a filename
	fgets(input, 10, stdin);
	printf("\n");
	input2 = getInteger(input);
	if (input2==-999)
	{
		printf("Enter file name: ");
		scanf("%s", filename);
		ptr_file = fopen(filename, "w");
		if (ptr_file == 0)
		{
			printf("Invalid file name please try again."); //Error handling for filenames
			continue;
		}
		else
		{
			fprintf(ptr_file,"\n%s", name);
			fprintf(ptr_file,"Today's	date and time: %s\n",getDateAndTime()); //Conversion output is put into file with custom filename
			fprintf(ptr_file,"\nDecimal: %d \n", dec);
			fprintf(ptr_file,"Hexadecimal: ");
			long remainder,quotient;	
			int	i=1,j,temp;	
			char hex[100];
			quotient = dec;	
			while(quotient!=0)
			{	
				temp = quotient % 16;	
				if(	temp<10)	
				{temp =temp + 48;}	 //This is the entire hex function separate from the UDF because of the print statement having difficulty writing to the file
				else
				{temp = temp	+ 55;}	
				hex[i++]= temp;	
				quotient = quotient/16;
			}
			for(j = i-1	; j> 0;j--)	
			{fprintf(ptr_file,"%c",hex[j]);}	
			fprintf(ptr_file,"\n");
			fprintf(ptr_file,"Octal: %ld \n", oct);
			fprintf(ptr_file,"Binary: %ld\n\n", bin);
			fclose(ptr_file);	
			printf("\nFile saved.\n");
			printf("Goodbye!\n");
			break;
		}
	}
	}

	return 0;
	
}

char *getDateAndTime()	 //Function gets the date and time from the computer
{	
	time_t t;	
	time(&t);	
	return ctime(&t);	
}

int getInteger(char *str)  //Input from user for the initial decimal value is converted from array to integer format
{
	if((str[0]=='x')|| (str[0]=='y'))
		{
		return -999;
		}
	return atoi(str);
}

long dec2bin(long x)  //UDF for converting decimal to binary notation
{	
    long long unsigned i=1,binary=0;
	int rem;
    while (x!=0)
    {
        rem=x%2;
        x = x/2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}

long dec2oct(long x) //UDF for converting decimal to octal notation
{
    long i=1,octal=0;
	int rem;
    while (x!=0)
    {
        rem=x%8;
        x = x/8;
        octal+=rem*i;
        i*=10;
    }
    return octal;
}

void dec2hex(long x) //UDF for converting decimal to hexadecimal notation
{
	long remainder,quotient;	
	int	i=1,j,temp;	
	char hex[100];
	quotient = x;	
	while(quotient!=0)
	{	
		temp = quotient % 16;	
		if(	temp<10)	
		{temp =temp + 48;}	
		else
		{temp = temp	+ 55;}	
		hex[i++]= temp;	
		quotient = quotient/16;
	}
	for(j = i-1	; j> 0;j--)	
	{printf("%c",hex[j]);}	
}
















	
