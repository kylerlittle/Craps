/*Guard Code:
This is in case another function of the same name exists in
another file.wq
*/
#ifndef PA_4
#define PA_4

/*Defined Macro Constants*/
#define OKAY 99
#define NOT_OKAY 100
#define YES 'y'
#define NO 'n'
#define WIN 1
#define LOSS 0
#define NEITHER -1

/*Standard Libaries*/
#include <stdio.h>   //printf(), scanf()
#include <stdlib.h>   // rand(), srand()
#include <time.h>    // time()


/*Function Prototypes with Description Blocks*/

/*************************************************************
* Function: print_game_rules
* Description: Prints out the game rules of "craps"
* Input parameters: None
* Returns: Nothing
* Preconditions: None.
* Postconditions: Rules are printed to screen.
*************************************************************/
void print_game_rules(void);

/*************************************************************
* Function: play_game
* Description: Prompts user to play game.
* Input parameters: None
* Returns: "y" or "n"
* Preconditions: None.
* Postconditions: "y" or "n" is returned.
*************************************************************/
char play_game(void);

/*************************************************************
* Function: get_bank_balance
* Description: Prompts user for an initial bank balance, from
which wagering amount will be added/subtracted. The player-
entered bank balance is returned.
* Input parameters: None
* Returns: User-entered bank balance.
* Preconditions: None.
* Postconditions: User-entered bank balance returned.
*************************************************************/
double get_bank_balance(void);

/*************************************************************
* Function: get_wager_amount
* Description: Prompts the user for a wager amount on a
particular roll. The wager amount is returned.
* Input parameters: None
* Returns: Wager amount.
* Preconditions: None.
* Postconditions: Wager amount is returned (entered by user).
*************************************************************/
double get_wager_amount(void);

/*************************************************************
* Function: check_wager_amount
* Description: Determines if wager amount is allowable based
on player's bank balance.
* Input parameters: Wager & Bank Balance
* Returns: If player's wager exceeds bank balance, 0 is
returned- meaning false. Else, player's wager is acceptable, 
and 1 is returned.
* Preconditions: Player has entered bank balance & wager.
* Postconditions: 0 (not okay) or 1 (okay) is returned.
*************************************************************/
int check_wager_amount(double wager, double bank_balance);

/*************************************************************
* Function: ready_2_roll_dice
* Description: Asks user if ready to roll the die.
* Input parameters: None
* Returns: YES or NO (defined as constants)
* Preconditions: None.
* Postconditions: 'y' or 'n' is returned.
*************************************************************/
char ready_2_roll_dice(void);

/*************************************************************
* Function: roll_die
* Description: This function generates a random integer
			   between 1 and 6.
* Input parameters: None
* Returns: A random integer between 1-6.
* Preconditions: None.
* Postconditions: Random integer 1-6 is returned.
*************************************************************/
int roll_die(void);

/*************************************************************
* Function: calculate_sum_dice
* Description: Sums result of two dice rolls.
* Input parameters: Die 1 & Die 2 integers.
* Returns: Sum of Die 1 and Die 2
* Preconditions: Dice has been rolled twice.
* Postconditions: Integer 2-12 returned (sum of die).
*************************************************************/
int calculate_sum_dice(int die1_value, int die2_value);

/*************************************************************
* Function: is_win_loss_or_point
* Description: FIRST DIE ROLL. If sum is 7 or 11, player wins
and 1 is returned (true). If sum is 2, 3, or 12 (called
"craps"), player loses and 0 is returned. Else, the sum
becomes the player's point_value and -1 is returned.
* Input parameters: Sum of first die roll.
* Returns: 1 (win), 0 (loss), or -1 (roll again)
* Preconditions: First dice roll in particular game.
* Postconditions: Win, loss, or point_value assigned.
*************************************************************/
int is_win_loss_or_point(int sum_dice);

/*************************************************************
* Function: is_point_loss_or_neither
* Description: Determines the result of any successive roll
after the first roll. If die sum is point_value, a 1 is 
returned (a win). If sum of roll is a 7, 0 returned (a loss).
Else, -1 is returned (roll again).
* Input parameters: Sum of Two Die & Point_Value.
* Returns: 1 (win), 0 (loss), or -1 (roll again)
* Preconditions: First roll already done. Point_value is
assigned and 2nd+ die roll used.
* Postconditions: Win, loss, or roll again.
*************************************************************/
int is_point_loss_or_neither(int sum_dice, int point_value);

/*************************************************************
* Function: adjust_bank_balance
* Description: This function adjusts bank balance based on
win/loss or neither. If 1 (win), wager amount added to bank
balance. If 0 (loss), wager amount subtracted from bank
balance. If -1 (neither), original bank balance is returned.
* Input parameters: Bank_Balance, Wager_Amount, Win/Loss/
Neither Integer (1, 0, or -1)
* Returns: Bank Balance.
* Preconditions: Die have been rolled at least once, wager
has been made, and bank balance entered.
* Postconditions: Bank Balance adjusted or =
*************************************************************/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);

/*************************************************************
* Function: chatter_messages
* Description: This function prints out messages to the user 
throughout the game, based on the current situation. For
example, if the user doesn't wager very much many (over 5%)
of bank account, the "House" might say something like,
"Why not bet a little more?"
* Input parameters: Number_Roles, Win_Loss_Neither,
Initial Bank Balance, Current Bank Balance, Wager
* Returns: Nothing
* Preconditions: Die has been rolled once. Wager has been
made. Bank Balance has been entered.
* Postconditions: Random integer 1-6 is returned.
*************************************************************/
void chatter_messages(int number_roles, int win_loss_neither, double initial_bank_balance, double current_bank_balance, double wager);

/*************************************************************
* Function: play_again
* Description: Prompts user to play again.
* Input parameters: None
* Returns: "y" or "n"
* Preconditions: None.
* Postconditions: "y" or "n" is returned.
*************************************************************/
char play_game_again(void);
#endif 