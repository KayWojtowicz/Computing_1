/*

Author: Kay Wojtowicz
Date: 2/15/2022
Answer to question: What happens if the integer that you type is again big? Say 500000?
Why is this behavior different than what you saw with your daily6?
	If the integer is very large the program will be able to complete it and produce all of the values.
	This program utilizes loops which continually repreat until the condition is no longer met. This is
	different than recursion because it does not store the values as it goes through but rather produces
	them. This allows loops to go to high values with a code like this while recusrion programs will have
	to bail out before it can reach the end because the program lacks the storage to hold all of the values
	for such a large integer.
*/

#include <stdio.h>

void loop_down_to_zero();

void loop_up_to_int();

int main(int argc, char* argv[])
{
	int x;
	printf("Please enter a positive number: ");
	scanf("%d", &x);
	loop_down_to_zero(x);
	printf("****\n");
	loop_up_to_int(x);
	
	return 0;
}

void loop_down_to_zero(int x)
{
	int y=x;
	
	while (y > -1)
	{
		printf("%d\n", y);
		y = y - 1;
	}
	return;
}

void loop_up_to_int(int x)
{
	int z=0;

	while (z<=x)
	{
		printf("%d\n", z);
		z = z + 1;
	}
	return;
}