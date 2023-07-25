#include <stdio.h>

void clear_keyboard_buffer(void);

void player_one_answer();
void player_two_answer();

void play_again();

int main(int argc, char* argv[])
{
	char playerone;
	char playertwo;
	char noc;
	char again;

	do
	{
		printf("Player one it is your turn!\n");
		printf("Please chose (r)ock, (p)aper, or (s)cissors: ");
		noc = scanf("%c", &playerone);

		player_one_answer(playerone);

		printf("Player two it is your turn!\n");
		printf("Please chose (r)ock, (p)aper, or (s)cissors: ");
		noc = scanf("%c", &playertwo);

		player_two_answer(playertwo);

		switch (playerone)
		{
		case 'r':
		case 'R':
			if (playertwo == 'p' || playertwo == 'P')
			{
				printf("Paper covers rock. Player two wins!\n");
			}
			else if (playertwo == 's' || playertwo == 'S')
			{
				printf("Rock breaks scissors. Player one wins!\n");
			}
			else
			{
				printf("Draw, nobody wins!\n");
			}
			break;

		case 'p':
		case 'P':
			if (playertwo == 'r' || playertwo == 'R')
			{
				printf("Paper covers rock. Player one wins!\n");
			}
			else if (playertwo == 's' || playertwo == 'S')
			{
				printf("Scissors cuts paper. Player two wins!\n");
			}
			else
			{
				printf("Draw, nobody wins!\n");
			}
			break;
			
		case 's':
		case 'S':
			if (playertwo == 'p' || playertwo == 'P')
			{
				printf("Scissors cut paper. Player one wins!\n");
			}
			else if (playertwo == 'r' || playertwo == 'R')
			{
				printf("Rock breaks scissors. Player two wins!\n");
			}
			else
			{
				printf("Draw, nobody wins!\n");
			}
			break;
		}

		printf("Would you wish to play again? (y/n): ");
		noc = scanf("%c", &again);

		play_again(again);

	} while (again == 'y' || again == 'Y');

	return 0;
}

void player_one_answer(char ans) 
{
	//Ensure the answer given by player one is valid
	
	char noc;

	while (ans != 'r' && ans != 'R' && ans != 'p' && ans != 'P' && ans != 's' && ans != 'S')
	{
		printf("I'm sorry, but you must enter 'r', 'p', or 's' \n");
		printf("Please chose (r)ock, (p)aper, or (s)cissors: ");
		clear_keyboard_buffer();
		noc = scanf("%c", &ans);
	}
	return;
}

void player_two_answer(char ans)
{
	//Ensure the answer given by player two is valid
	
	char noc;

	while (ans != 'r' && ans != 'R' && ans != 'p' && ans != 'P' && ans != 's' && ans != 'S')
	{
		printf("I'm sorry, but you must enter 'r', 'p', or 's' \n");
		printf("Please chose (r)ock, (p)aper, or (s)cissors: ");
		clear_keyboard_buffer();
		noc = scanf("%c", &ans);
	}
	return;
}

void play_again(char ans)
{
	//Ensure the answer if the player wants to continue is valid
	char noc;

	while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N')
	{
		printf("I'm sorry, but you must print either 'y' or 'n'\n");
		printf("Would you wish to play again? (y/n): "); 
		clear_keyboard_buffer();
		noc = scanf("%c", &ans);
	}
	return;
}

void clear_keyboard_buffer(void)
{
	char c;
	int noc;
	scanf("%c", &c);

	while (c != '\n')
	{
		noc = scanf("%c", &c);
	}
	return;
}