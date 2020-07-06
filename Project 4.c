//Homework 4 CS222 John Parsons G00961220
//Could not finish locality report

#include <stdio.h>
#include <time.h>	
#include <string.h>
#include <stdlib.h>	

struct address_t
{
	char ali[11];  //Eleven bytes designated, (10 for max string and 1 for null byte ending)
	int i1,i2,i3,i4;
};

char *getDateAndTime();
int Read_Data_File(struct address_t *address);
void Generate_Locality_Rpt(int, struct address_t * address, char name);
void Generate_Alias_List(int, struct address_t * address, char name);
void bubble(int, struct address_t * address);
int	locality_t[100][2];            //Integer array to store locality pairs

FILE *inputfile;
FILE *ptr_file1;
FILE *ptr_file2;

int main(void)
{
	
	struct address_t data[100];
	int x = Read_Data_File(data);
	char time,buf[30];
	
	printf("\nPlease enter your name: ");   //Initial input gathered
	fgets(buf, 30, stdin);
	char name = buf[30];
	Generate_Alias_List(x,data, name);     	//Function calls to create output files
	Generate_Locality_Rpt(x,data, name);
	return 0;
}

char *getDateAndTime()	 //Function extracts the date and time from the computer
{	
	time_t t;	
	time(&t);	
	return ctime(&t);
}

int Read_Data_File(struct address_t *address)
{
	FILE *inputfile;
	int var=0;
	char line[50];
	
	inputfile = fopen("CS222_Inet.txt", "r");
	do
	{
		fgets(line, 50, inputfile); //Gets each line from the file in a loop
		if (strstr(line, "none") == NULL)
		{									
			sscanf(line, "%d.%d.%d.%d %s", &address[var].i1, &address[var].i2,
			&address[var].i3, &address[var].i4, address[var].ali); //Populates address structure members
			var++;
		}
	}
	while (strstr(line, "none") == NULL);
	fclose(inputfile);
	return var;
}

void Generate_Locality_Rpt(int var, struct address_t * address, char name)
{
	FILE *ptr_file1;
	ptr_file1 = fopen("222LocalityReport.txt", "w");
	fprintf(ptr_file1,"Today's	date and time: %s",getDateAndTime());
	fprintf(ptr_file1,"CS222 Network Locality Report\n" );
	fclose(ptr_file1);
}

void Generate_Alias_List(int var, struct address_t * address, char name)
{
	FILE *ptr_file2;
	int x;
	
	ptr_file2 = fopen("222AliasList.txt", "w");
	fprintf(ptr_file2,"Today's	date and time: %s",getDateAndTime());
	fprintf(ptr_file2,"CS222 Network Alias Listing\n\n" );
	bubble(var, address);

	for(x=0;x<var;x++)  //Loop to go through each address member and output to file
	{
		fprintf(ptr_file2, "%-18s %d.%d.%d.%d\n",address[x].ali, //Formats alias spacing 18 spaces
		address[x].i1, address[x].i2, address[x].i3, address[x].i4);
	}
	fclose(ptr_file2);
}

void bubble(int var, struct address_t * address)	//Bubble sort function that accepts addresses
{
	int i,j;
	for ( i=1; i<var; i++)
	{
		for ( j=0; j < (var-1); j++)
			{
			if (strcmp(address[j].ali, address[j+1].ali) >0)
				{
				struct address_t temp = address[j]; //Compares addresses and prepares for sort
				address[j] = address[j+1];
				address[j+1] = temp;
				}
			}
	} 
}






