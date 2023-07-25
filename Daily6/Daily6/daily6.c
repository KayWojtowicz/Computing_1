/*
Author: Kay Wojtowicz
Date; 2/7/2022


Answer to question: If the integer is too large, there would not be enough storage to hold the integer value.
	Recursion works by having a function call itself and therefore it holds all of the outputs until the end
	of the program is reach at which time the program will return all of the outputs it is hold. Therefore,
	when the number is too large, the function will be called too many times so the program can not continue
	recall the function and the program will stop and just spit out the values it already has stored.
*/


#include <stdio.h>

void count_down_to_zero(int number);

void count_up_to_n(int number);

int main(int argc, char* argv[])
{
	count_down_to_zero(10);
	printf("****\n");
	count_up_to_n(10);
	return 0;
}

void count_down_to_zero(int number)
{
	if (number > -1)
	{
		printf("%d\n", number);
		count_down_to_zero(number - 1);
	}
	return;
}

void count_up_to_n(int number)
{
	if (number > -1)
	{
		count_up_to_n(number - 1);
		printf("%d\n", number);
	}
	return;
}