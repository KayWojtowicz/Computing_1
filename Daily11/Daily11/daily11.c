/*
	Author: Kay Wojtowicz
	Date: 2/25/2022
	Time Spent: 40 minutes
	Purpose: My program asks the user for a value. If the value is not 
		between 1 and 79, they will be asked to enter another value until 
		they provide a value within that range. When they do give this
		value the program will type out that many asterisks and will then exit.
*/

#include <stdio.h>

void draw_line();

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
	int numb;
	int noc;

	printf("Please enter the number of asterisks you want in your line: ");
	noc = scanf("%d", &numb);

		while (numb > 79 || numb < 1)
		{
			printf("I'm sorry, that number is unrecognizableor out of range, try [1-79]: ");
			clear_keyboard_buffer();
			noc = scanf("%d", &numb);
		}

		if (numb <= 79 && numb >= 1)
		{
			draw_line(numb);
		}

	return 0;
}

void draw_line(int numb)
{	
	int new = numb;

	while(new > 0)
	{
		printf("*");
		new = new - 1;
	}
	
	printf("\n");

	return;
}

void clear_keyboard_buffer(void)
{
	char c;
	int noc;
	scanf("%c", &c);

	while (c != '\n')
	{
		noc=scanf("%c", &c);
	}
	return;
}