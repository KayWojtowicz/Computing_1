/*

Author: Kay Wojtowicz
Date: 2/18/2022
Purpose: This program asks for the user to enter in a negative integer.
	If something other than a negative integer is entered- including 
	positive integers, 0, or charcaters- the program will respond stating
	a negative value must be entered and ask the user for a new value. The
	program will continue to do this until a negative value is entered.
Time Spent: 20 minutes

*/

#include <stdio.h>

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
	int x;
	int noc;

	printf("Please enter a negative integer: ");
	noc = scanf("%d", &x);

	while (noc != 1 || x >= 0)
	{
		printf("I'm sorry, you must enter a negative integer less than zero: ");
		clear_keyboard_buffer();
		noc = scanf("%d", &x);
	}

	printf("The negative integer was: %d", x);

	return 0;
}

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	
	while(c!= '\n')
	{
		scanf("%c", &c);
	}
	return;
}