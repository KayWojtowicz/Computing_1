/*
	Author: Kay Wojtowicz
	Date: 3/8/2022
	Purpose: The purpose of this program is to allow two users to play rock, paper, scissors. They
		are able to continue playing until they decide they are done. Also if an invalid answer is
		given the user will be trapped in a loop until a valid on is given.	This rogram utilizes 
		enumerated types to make it easier to follow when looking through the code.
	Time Spent: 30 minutes
*/

#include <stdio.h>

void clear_keyboard_buffer(void);
int user_wishes_to_continue(void);

enum choice { ROCK, PAPER, SCISSORS };
typedef enum choice Choice;

Choice get_choice(void);

int main(int argc, char* argv[])
{
	Choice player_one;
	Choice player_two;
	do
	{
		printf("Player one it is your turn!\n");
		player_one = get_choice();

		printf("Player two it is your turn!\n");
		player_two = get_choice();
		
		switch (player_one)
		{
		case ROCK:
			if (player_two == PAPER)
				printf("Paper covers rock. Player two wins!\n");
			else if (player_two == SCISSORS)
				printf("Rock breaks scissors. Player one wins!\n");
			break;

		case PAPER:
			if (player_two == ROCK)
				printf("Paper covers rock. Player one wins!\n");
			else if (player_two == SCISSORS)
				printf("Scissors cut paper. Player two wins!\n");
			break;

		case SCISSORS:
			if (player_two == ROCK)
				printf("Rock breaks scissors. Player two wins!\n");
			else if (player_two == PAPER)
				printf("Scissors cut paper. Player one wins!\n");
			break;
		default:
			printf("Draw, nobody wins!\n");
		}

	} while (user_wishes_to_continue());

	return 0;
}

Choice get_choice(void)
{
	char ans;
	char noc;
	Choice answer;
	
	do
	{
		printf("Please chose (r)ock, (p)aper, or (s)cissors: "); 
		noc = scanf("%c", &ans);
		clear_keyboard_buffer();

		if (ans != 'r' && ans != 'R' && ans != 'p' && ans != 'P' && ans != 's' && ans != 'S')
		{
			printf("I'm sorry, I don't understand.\n");
		}

	} while (ans != 'r' && ans != 'R' && ans != 'p' && ans != 'P' && ans != 's' && ans != 'S');

	switch (ans)
	{
	case 'r':
	case 'R':
		answer = ROCK;
		break;
	case 'p':
	case 'P':
		answer = PAPER;
		break;
	case 's':
	case 'S':
		answer = SCISSORS;
		break;
	}
	
	return answer;
}

int user_wishes_to_continue(void)
{
	char ans;
	char noc;

	printf("Do you wish to continue (y/n): ");
	noc = scanf("%c", &ans);
	clear_keyboard_buffer();
	
	while(ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N')
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
	int noc;
	
	noc = scanf("%c", &c);

	while (c != '\n')
	{
		noc = scanf("%c", &c);
	}
	
	return;
}