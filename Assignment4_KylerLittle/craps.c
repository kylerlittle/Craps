#include "craps.h"

void print_game_rules(void)
{
	printf("You are playing craps!\n\n");
	printf("RULES:\n");
	printf("A player rolls two dice. Each die has six faces, numbered\n");
	printf("1-6. After the dice have come to rest, the sum of the dots\n");
	printf("on the two upward faces is calculated. If the sum is 7 or 11\n");
	printf("on the first throw, the player wins and gains his/her wager\n");
	printf("amount. If the sum is 2, 3, or 12, the player loses.\n");
	printf("Otherwise, the player must have rolled a 4, 5, 6, 8, 9, or 10.\n");
	printf("This becomes the player's point value. To win, you must\n");
	printf("continue rolling the dice until you make your point value\n");
	printf("again. However, if you roll a 7 before making your point,\n");
	printf("then you lose.\n\n");
	printf("Would you like to play? <y/n>\n");
}
char play_game(void)
{
	char answer = '\0';
	scanf("%c", &answer);
	if (answer == 'y')
	{
		printf("Awesome! Let's begin.\n");
		return YES;
	}
	else
	{
		printf("That's okay! Maybe another time.\n");
		return NO;
	}
}
double get_bank_balance(void)
{
	double bank_balance = 0.0;
	printf("Please enter your bank balance: $");
	scanf("%lf", &bank_balance);
	return bank_balance;
}
double get_wager_amount(void)
{
	double wager = 0.0;
	printf("How much would you like the wager?\n");
	printf("$");
	scanf("%lf", &wager);
	return wager;
}
int check_wager_amount(double wager, double bank_balance)
{
	if (bank_balance >= wager)
	{
		return OKAY;
	}
	else
	{
		return NOT_OKAY;
	}
}
char ready_2_roll_dice(void)
{
	
	char answer = '\0';
	do
	{
		printf("Ready to roll? <y/n>\n");
		scanf(" %c", &answer);  //space padding so compiler knows not to accept a whitespace character
		if (answer != YES)
		{
			printf("That's okay! I can wait.\n");
			system("pause");
			system("cls"); //must make sure there is a pause before hand
						   /*The pause is caused by the scanf, so it's okay.*/
		}
		else
		{
			return YES;
		}
	} while (answer != YES);  //input validation loop
	printf("The result is...\n");
	/*if (answer == 'y')
	{
		printf("The result is...\n");
		return YES;
	}
	else
	{
		printf("That's okay! I can wait. Enter <y/n> when ready.\n");
		return NO;
	}*/
}
int roll_die(void)
{
	int die_value = 0;
	/*Any integer divided by 6 will have a remainder between 0
	and 5; thus, I add one to make the possible integers 1-6*/
	die_value = (rand() % 6) + 1;  
	return die_value;
}
int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum = die1_value + die2_value;
	return sum;
}
int is_win_loss_or_point(int sum_dice)
{
	if ((sum_dice == 7) | (sum_dice == 11))
	{
		return WIN;
	}
	else if ((sum_dice == 2) | (sum_dice == 3) | (sum_dice == 12))
	{
		return LOSS;
	}
	else
	{
		return NEITHER;   //roll again; sum_dice is point_value
	}
}
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	if (sum_dice == point_value)
	{
		return WIN;
	}
	else if (sum_dice == 7)
	{
		return LOSS;
	}
	else
	{
		return NEITHER;  //roll again
	}
}
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	if (add_or_subtract == 1)
	{
		return bank_balance + wager_amount;
	}
	else if (add_or_subtract == 0)
	{
		return bank_balance - wager_amount;
	}
	else
	{
		return bank_balance;
	}
}
void chatter_messages(int number_roles, int win_loss_neither, double initial_bank_balance, double current_bank_balance, double wager)
{
	if (number_roles == 1)
	{
		if (win_loss_neither == WIN)
		{
			printf("WINNER! Nice roll!\n");
		}
		else if (win_loss_neither == LOSS)
		{
			printf("That's unfortunate... Better luck next time!\n");
		}
		else if (win_loss_neither == NEITHER)
		{
			printf("Your point value is: ");
		}
		/*Note that wager comments are put here, so that they will
		be short-circuited later on.*/
		else if (wager <= (0.1*initial_bank_balance))
		{
			printf("Low better, I see. Maybe you'll risk it more next time.\n");
		}
		else if (wager >= (0.75*initial_bank_balance))
		{
			printf("High roller! I like it.\n");
		}
		else
		{
			printf("Okay! Good wager.\n");
		}
	}
	else  //count > 1
	{
		if (win_loss_neither == WIN)
		{
			printf("Congrats! You made the point!\n");
			printf("Current Bank Balance: ");
		}
		else if (win_loss_neither == LOSS)
		{
			printf("Tough luck. Maybe next time.\n");
			printf("Current Bank Balance: ");
		}
		else //NEITHER 
		{
			if (number_roles == 5)
			{
				printf("I bet you're starting to get antsy...\n");
			}
			else if (number_roles == 8)
			{
				printf("How have you not won or lost already?!\n");
			}
			else
			{
				printf("Neither win, nor loss.\n");
			}
		}
	}
}
char play_game_again(void)
{
	char answer = '\0';
	printf("Play again? <y/n>\n");
	scanf(" %c", &answer);
	if (answer == 'y')
	{
		printf("Sweet! Let's play again.\n");
		return YES;
	}
	else
	{
		printf("That's okay. Thanks for playing!\n");
		return NO;
	}
}