/*************************************************************************
* Programmer: Kyler Little
* Class: CptS 121; Lab Section 11
* Programming Assignment: Programming Project 4
* Date: 10/1/2016                                                                    *
* Description: This program executes a game called "craps." It involves
			   much user input- specifically whether or not he/she wants
			   to play, bank balance, wager, to roll, and to play again.
			   Essentially, the game is a dice game based on random
			   chance.
************************************************************************/

#include "craps.h"

int main(void)
{
	/*Seed value plugged into random number generator. Guarantees
	that die1 and die2 are actually random (well- as random as
	computer generated numbers can be)*/
	srand((unsigned int)time(NULL));

	/*Variable Declarations*/
	int die1 = 0, die2 = 0;
	int check_wager = 0, sum_dice = 0, point_value = 0;
	int result = 0;
	double initial_bank_balance = 0.0, current_bank_balance = 0.0;
	double wager_amount = 0.0;
	char answer1 = '\0', answer2 = '\0', answer3 = '\0', play_again = '\0';

	print_game_rules();
	answer1 = play_game();
	if (answer1 == YES)
	{
		initial_bank_balance = get_bank_balance();
		do
		{
			int count = 1; //count initialized to one to discount first roll and reset to one
			/*Also, count must be initialized here, so that it resets
			for every new game. Otherwise, chatter messages wouldn't
			work properly.*/
			wager_amount = get_wager_amount();
			check_wager = check_wager_amount(wager_amount, initial_bank_balance);
			while (check_wager == NOT_OKAY)
			{
				system("cls");
				printf("You don't have that much money! Try again.\n");
				printf("Available Balance: $%.2lf\n", current_bank_balance);
				wager_amount = get_wager_amount();
				check_wager = check_wager_amount(wager_amount, initial_bank_balance);
			}
			chatter_messages(1, -99, initial_bank_balance, current_bank_balance, wager_amount);
			/*entered -99 so it cuts through first 3 if statements in count = 1 section*/
			answer2 = ready_2_roll_dice();
			if (answer2 == YES)
			{
				die1 = roll_die();
				die2 = roll_die();
				sum_dice = calculate_sum_dice(die1, die2);
				printf("%d and %d\n", die1, die2);
				printf("Sum: %d\n", sum_dice);
				if (is_win_loss_or_point(sum_dice) == WIN)
					/*For the following three branches in the "flow"
					of the program, I let the count be 1 since it will
					always be one, even if the player is playing a new
					game...*/
				{
					chatter_messages(1, WIN, initial_bank_balance, current_bank_balance, wager_amount);
					current_bank_balance = adjust_bank_balance(initial_bank_balance, wager_amount, WIN);
					printf("Current Bank Balance: %.2lf\n", current_bank_balance);
				}
				else if (is_point_loss_or_neither == LOSS)
				{
					chatter_messages(1, LOSS, initial_bank_balance, current_bank_balance, wager_amount);
					current_bank_balance = adjust_bank_balance(initial_bank_balance, wager_amount, LOSS);
					printf("Current Bank Balance: %.2lf\n", current_bank_balance);
				}
				else
				{
					point_value = sum_dice;
					chatter_messages(1, NEITHER, initial_bank_balance, current_bank_balance, wager_amount);
					printf("%d\n", point_value);
					do
					{
						answer3 = ready_2_roll_dice();
						if (answer3 == YES)
						{
							die1 = roll_die();
							die2 = roll_die();
							sum_dice = calculate_sum_dice(die1, die2);
							result = is_point_loss_or_neither(sum_dice, point_value);
							count += 1;  //adds one to count through each iteration
							printf("You rolled a... %d\n", sum_dice);
							if (result == WIN)
							{
								current_bank_balance = adjust_bank_balance(initial_bank_balance, wager_amount, WIN);
								initial_bank_balance = current_bank_balance; //when it goes back thru the loop, will allow better to bet as much as he/she has
								chatter_messages(count, WIN, initial_bank_balance, current_bank_balance, wager_amount);
								printf("$%.2lf\n", current_bank_balance);
							}
							else if (result == LOSS)
							{
								current_bank_balance = adjust_bank_balance(initial_bank_balance, wager_amount, LOSS);
								initial_bank_balance = current_bank_balance; //if player plays again, they can now bet as much as their current balance
								chatter_messages(count, LOSS, initial_bank_balance, current_bank_balance, wager_amount);
								printf("$%.2lf\n", current_bank_balance);
							}
							else
							{
								chatter_messages(count, NEITHER, initial_bank_balance, current_bank_balance, wager_amount);
							}
						}
						else
						{
							system("pause");
							system("cls");
						}
					} while (result == NEITHER);
				}
			}
			else
			{
				system("pause");
				system("cls");
			}
			play_again = play_game_again();
			system("cls");
			printf("New Balance: $%.2lf\n", current_bank_balance);
		} while (play_again == YES);
	}
	else
	{
		system("pause");
		system("cls");
	}
	return 0;
}