/***********************************************************
Author: Kay Wojtowicz
Date: 2/14/2022
Purpose: The purpose of this code is to utilized scanf safely in order to create a new integer from a value given by the user.
***********************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
	int number;
	printf("Please enter a positive integer: ");
	scanf("%d", &number);

	if (number % 2 == 0)
	{
		printf("The next value of the number is: %d\n", number / 2);
	}
	else
	{
		printf("The next value of the number is: %d\n", (number * 3) + 1);
	}
	return 0;
}