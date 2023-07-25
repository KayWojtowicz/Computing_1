/*
	Author: Kay Wojtowicz
	Date: 3/25/2022
	Purpose: To allow two people to play rock, paper, scissors, as many times as they please.
		If an invalid answer is given the game will trap the user in a loop until a valid
		answer is provided and then program will continue from there.
	Time Spent: 3 hours
*/

#include <stdio.h>

void clear_keyboard_buffer(void);
int user_wishes_to_continue(void);

char player_one_answer();
char player_two_answer();

int main(int argc, char* argv[])
{
	char player_one;
	char player_two;
	char noc;
	char answer;

	do
	{
		printf("Player one it's your turn!\n");
		player_one = player_one_answer();

		printf("Player two it's your turn!\n");
		player_two = player_two_answer();

		switch (player_one)
		{
		case 'r':
		case 'R':
			if (player_two == 'p' || player_two == 'P')
			{
				printf("Paper covers rock. Player two wins!\n");
			}
			else if (player_two == 's' || player_two == 'S')
			{
				printf("Rock breaks scissors. Player one wins!\n");
			}
			else
				printf("Draw, nobody wins!\n");
			break;

		case 'p':
		case 'P':
			if (player_two == 'r' || player_two == 'R')
			{
				printf("Paper covers rock. Player one wins!\n");
			}
			else if (player_two == 's' || player_two == 'S')
			{
				printf("Scissors cuts paper. Player two wins!\n");
			}
			else
				printf("Draw, nobody wins!\n");
			break;

		case 's':
		case 'S':
			if (player_two == 'r' || player_two == 'R')
			{
				printf("Rock breaks scissors. Player two wins!\n");
			}
			else if (player_two == 'p' || player_two == 'P')
			{
				printf("Scissors cut paper. Player one wins!\n");
			}
			else
				printf("Draw, nobody wins!\n");
			break;
			printf("Draw, nobody wins!\n");
		}

	} while (user_wishes_to_continue());

	return 0;
}

char player_one_answer() 
{
	//Ensure the answer given by player one is valid
	
	char noc;
	char ans;

	do
	{
		printf("Please chose (r)ock, (p)aper, or (s)cissors: ");
		noc = scanf("%c", &ans);
		clear_keyboard_buffer();
		if (ans != 'r' && ans != 'R' && ans != 'p' && ans != 'P' && ans != 's' && ans != 'S')
		{
			printf("I'm sorry, but you must enter 'r', 'p', or 's' \n");
		}
	} while (ans != 'r' && ans != 'R' && ans != 'p' && ans != 'P' && ans != 's' && ans != 'S');

	return ans;
}

char player_two_answer()
{
	//Ensure the answer given by player two is valid
	
	char noc;
	char ans;

	do
	{
		printf("Please chose (r)ock, (p)aper, or (s)cissors: ");
		noc = scanf("%c", &ans);
		clear_keyboard_buffer();
		if (ans != 'r' && ans != 'R' && ans != 'p' && ans != 'P' && ans != 's' && ans != 'S')
		{
			printf("I'm sorry, but you must enter 'r', 'p', or 's' \n");
		}
	} while (ans != 'r' && ans != 'R' && ans != 'p' && ans != 'P' && ans != 's' && ans != 'S');

	return ans;
}

int user_wishes_to_continue(void)
{
	char ans;
	char noc;

	printf("Do you wish to continue (y/n): ");
	noc = scanf("%c", &ans);
	clear_keyboard_buffer();

	while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N')
	{
		printf("I'm sorry, but you must enter 'y' or 'n'\n");
		printf("Would you wish to play again? (y/n): ");
		clear_keyboard_buffer();
		noc = scanf("%c", &ans);
		clear_keyboard_buffer();
	}

	return ans == 'y' || ans == 'Y';
}

void clear_keyboard_buffer(void)
{
	char c;
	char noc;
	scanf("%c", &c);

	while (c != '\n')
	{
		noc = scanf("%c", &c);
	}
	return;
}