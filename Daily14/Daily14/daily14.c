#include <stdio.h>

/*
Author: Kay Wojtowicz
Date: 3/23/2022
Purpose: This code allows the user to choose if they want to convert weight or length or to exit. There
	are no actual calculations done in this code but it is able to call functions which would later be
	made to do actual conversions.
Sources of Help: None
Time spent: 30 minutes
*/

int inital_question(void);
void convert_lengths(void);
void convert_weight(void);
void clear_keyboard_buffer(void);

	int main(int argc, char* argv[])
{
	int answer_one;
	
	do
	{
		answer_one = inital_question();

		if (answer_one == 1)
		{
			convert_lengths();
		}
		else if (answer_one == 2)
		{
			convert_weight();
		}
	} while (answer_one != 0);
	return 0;
}

int inital_question(void)
{
	int noc;
	int answer;

	do
	{
		printf("Do you want to convert \n \t 0) Quit \n \t 1) Length \n \t 2) weight\n");
		noc = scanf("%d", &answer);
		clear_keyboard_buffer();

		if (answer < 0 || answer > 2)
		{
			printf("I'm sorry that answer is invalid. Please enter either 0, 1, or 2.\n");
		}
	} while (answer < 0 || answer > 2);

	return answer;
}

void convert_lengths(void)
{
	printf("you converted length!\n");
	return;
}

void convert_weight(void)
{
	printf("You converted weight!\n");
	return;
}

void clear_keyboard_buffer(void)
{
	char c;
	int noc;

	noc = scanf("%c", &c);

	while (c != '\n')
	{
		noc = scanf("%c", &c);
	}

	return;
}