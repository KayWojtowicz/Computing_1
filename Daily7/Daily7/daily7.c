#include <stdio.h>

/***********************************************
Author: Kay Wojtowicz
Date: 02/08/2022
Purpose: this code's purpose is print the number it is given in binary`
***********************************************/

void print_binary(int number);

int main(int argc, char* argv[])
{
	print_binary(43);
	printf("\n");
	return 0;
}

void print_binary(int number)
{
	if (number == 0)
	{
		return;
	}

	else
	{
		print_binary(number / 2);
		printf("%d", number % 2);
	}
}