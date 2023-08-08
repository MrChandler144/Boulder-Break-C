/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define CAVE_SIZE 10

// this one only updates if you press a key (a valid key, one of wasd)

/***********************************************************/
/***********************************************************/
/******* ADD THE REQUIRED FUNCTIONS BELOW THIS POINT *******/
/***********************************************************/
/***********************************************************/

// My own part: getKey (if the user inputs a key, I want to know)
char getKey(void)
{
    // this one delays the game while reading inputs, and also reads in inputs as well
	char move;
	
	// valid numbers are 97, 100, 115, 119
	
	if ( _kbhit() )
	{
		// a key was pressed
		
		// Stores the pressed key in char move
		move = _getch();
		
		// was it valid
		if ((move == 97) || (move == 100) || (move == 115) || (move == 119))
		{
			// a valid move
			
			return move;
		} else {
			// invalid move
			return 'n';
		}
	} else {
		// no keyboard hit
		
		return 'n';
	}
}

// Task One: InitialiseStory
void InitialiseStory(char* paragraph)
{
	// makes a story to tell at the start of the game
	
	char story[1998]=
	"\n\n~~~~~\n\nOnce upon a time not so long ago...\n\n"
	
	"Tommy used to work in the mines, union's been on strike\n"
	"He's down on his luck, it's tough, so tough\n\n"
	
	"Gina works the diner all day working for her man\n"
	"She brings home her pay, for love, for love\n\n"
	
	"She says, we've got to hold on to what we've got\n"
	"It doesn't make a difference if we make it or not\n"
	"We've got each other and that's a lot for love\n"
	"We'll give it a shot\n\n"
	
	"Woah, we're half way there\n"
	"Woah, livin' on a prayer\n"
	"Take my hand, we'll make it I swear\n"
	"Woah, livin' on a prayer"
	
	"\n\n~~~~~\n\n"
	
   //1234567890 234567890 234567890 234567890 234567890 234567890
	"Due to egregious health and safety violations, Tommy has\n"
	"gotten stuck  in the mines, and the union is too lazy to\n"
	"rescue him! Collect the lost treasure (+), roll boulders\n"
	"(O) and plug treacherous holes (*) so Tommy can find his\n"
	"way out to Gina, who is waiting for her one true love <3\n"
	;
	
	int i;
	for (i=0; i<1998; i++)
	{
		paragraph[i]=story[i];
	}
}

// Task Two: PrintCave

void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// This function prints out the cave. It takes an integer array as input, and prints out the decipohered contents to the user
	
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	// set up our nested for loops 
	int rows;
	int cols;
	rows=length;
	cols=length;
	
	
	for (rows=0; rows<length; rows++)
	{
		for (cols=0; cols<length; cols++)
		{
			if (cave[rows][cols] == 1)
			{
				printf("#");
			}
			else if (cave[rows][cols] == 0)
			{
				printf(" ");
			}
			else if (cave[rows][cols] == 'E')
			{
				printf(" ");
			}
			else if (cave[rows][cols] == 'X')
			{
				printf("X");
			}
			else if (cave[rows][cols] == '*')
			{
				printf("*");
			}
			else if (cave[rows][cols] == '+')
			{
				printf("+");
			}
			else if (cave[rows][cols] == 'O')
			{
				printf("O");
			}
		}
		// end of a row, go to next one
		printf("\n");
	}
}

void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout)
{
	// This function takes a string turns it into a CAVE_SIZE by CAVE_SIZE array, read like a book
	
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	// set up our nested for loops 
	int rows;
	int cols;
	rows=length;
	cols=length;
	
	int index;	
	for (rows=0; rows<length; rows++)
	{
		for (cols=0; cols<length; cols++)
		{
			index=length*rows + cols;
			cave[rows][cols]=layout[index];
		}
	}
	
	// and now, all the 1s and 0s are characters instead of ints
	// so change that
	for (rows=0; rows<length; rows++)
	{
		for (cols=0; cols<length; cols++)
		{
			if (cave[rows][cols]=='0')		// meant to be a character here
			{
				cave[rows][cols]=0;
			}
		}
	}
	for (rows=0; rows<length; rows++)
	{
		for (cols=0; cols<length; cols++)
		{
			if (cave[rows][cols]=='1')		// meant to be a character here
			{
				cave[rows][cols]=1;
			}
		}
	}
}

int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// This function checks that the outer perimeter of an array is either 1 or 'E'
	// The IsBorderComplete() function should return true if every element of the outer border of the cave is either a wall or an exit position, and false otherwise.
	
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	//check the outer walls
	int i;
	for (i=0; i<length; i++)
	{
		if ((cave[i][0]!=1) || (cave[0][i]!=1) || (cave[i][length-1]!=1) || (cave[length-1][i]!=1))
		{
			// so it wasn't wall
			//printf("\n got past 1. I is %d\n", i);
			//printf("%c %c %c %c", cave[i][0],cave[0][i],cave[i][length-1],cave[length-1][i]);
			if ((cave[i][0]=='E') || (cave[0][i]=='E') || (cave[i][length-1]=='E') || (cave[length-1][i]=='E'))
			{
				// there was an exit here. This is fine
			} else {
				// there  wasn't an exit, or a wall. there's a hole
				// printf("\n returning 0\n");
				return 0;
			}
		}
	}
	return 1;
}

int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// This function checks an int array to make sure there is exactly one 'E' element in it
	// The IsExitUnique() function should return true if there is exactly one exit position in the cave array, and false otherwise.
	
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	// set up our nested for loops 
	int rows;
	int cols;
	
	// alright three conditions for failure
	// gaps on outside of wall
	// there's not exactly one exit
	// exit is in the right spot
	
	// count the exits
	int numExits=0;
	for (rows=0; rows<length; rows++)
	{
		for (cols=0; cols<length; cols++)
		{
			if (cave[rows][cols] == 'E')
			{
				numExits++;
			}
		}
	}
	if (numExits!=1)
	{
		// not exactly one exit
		return 0;
	} else {
		return 1;
		//printf("\n one exit\n");
	}
}

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// This function checks an int array to make sure there is an 'E' on the border, but not in the corners
	// The IsExitAccessible() function should return true if there is an exit position located on the outside border of the cave and not in a corner, and false otherwise.
	
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	// set up our nested for loops 
	int rows;
	int cols;
	
	// check that the exit is in a good place
	for (rows=0; rows<length; rows++)
	{
		for (cols=0; cols<length; cols++)
		{
			if (cave[rows][cols] == 'E')
			{
				// found the exit
				// check it's on the border
				if (((rows*cols)==0) || (rows==length-1) || (cols==length-1))
				{
					// if we get here it is on the border
					// now check if it's not in the corners (we know its on the border)
					if (((rows+cols)==0) || ((rows+cols)==length-1) || ((rows+cols)==2*(length-1)))
					{
						// if we get here it is in the corners. Not good.
						// failed
						// and I mean if it's in the corners and failed we might as well return something here
						return 0;
					} else {
						// this is what we're looking for here
						// we've been culling the bad ones
						// if it gets here it's on the edge, but not in the corners
						return 1;
					}
				}
			}
		}
	}
	// so uh yeah if it gets here it should have failed (b/c it wasn't on the edge)
	// return false
	return 0;
}

void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element)
{
	// This function adds elements of the game into the array that is displayed to the user
	
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	// set up our nested for loops 
	int rows;
	int cols;
	
	// and main code
	int doWeGoQ;
	doWeGoQ=1;
	
	// conditions for not being placed	
		// must be empty space
		// out of bounds
		// only one player
	
	if ((row>=length) || (col>=length))
	{
		// out of bounds
		doWeGoQ=0;
	}
	
	if (doWeGoQ==1)
	{
		// inside bounds, I can index the array now
		if (cave[row][col] != 0)
		{
			// so not a space, don't go ahead
			doWeGoQ=0;
			// so we're not going to overwrite ANYTHING
		}
	}
	
	// ok so now we have all the variables to know if we should do something
	// and now we place
	
	// player is X
	// boulder is O
	// hole is *
	// treasure is +
	
	if (doWeGoQ==1)
	{
		// this is what I do instead of typing break
		
		// check the first letter of the input to see what we have to slap down
		
		if (element[0]=='p')
		{
			// it's a Player
			
			// check that number of players = 0;
			
			int playersQ;
			playersQ=0;
			
			// straight up index the entire array :)
			for (rows=0; rows<length; rows++)
			{
				for (cols=0; cols<length; cols++)
				{
					if (cave[rows][cols]=='X')
					{
						// yes players
						playersQ=1;
					}
				}
			}
			if (playersQ == 0)
			{
				// no players down already
				cave[row][col]='X';
			}
		}
		
		if (element[0]=='b')
		{
			// it's a Boulder
			cave[row][col]='O';
		}
		
		if (element[0]=='h')
		{
			// it's a Hole
			cave[row][col]='*';
		}
		
		if (element[0]=='t')
		{
			// it's a Treasure
			cave[row][col]='+';
		}
	}
}

void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// This function rotates a square array of size CAVE_SIZE by CAVE_SIZE 90 degrees clockwise
	
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	// set up our nested for loops 
	int rows;
	int cols;
	
	// rotate 90 degrees clockwise
	/*
	123 --> 741
	456     852
	789     963
	
	// so we read up, one row to the next (on the right)
	// so top line (0,0) to (2,0) is (0,2) to (0,0)
	// middle line (0,1) to (2,1) is (1,2) to (1,0)
	// bottom line (0,2) to (2,2) is (2,2) to (2,0)
	*/
	
	int temp[CAVE_SIZE][CAVE_SIZE];
	for (rows=0; rows<length; rows++)
	{
		for (cols = 0; cols<length; cols++)
		{
			temp[rows][cols] = cave[length-1-cols] [rows];
			//   cons  diff         change          const
			//   row   col          row             col
		}
	}
	
	// make cave be equal to temp
	for (rows=0; rows<length; rows++)
	{
		for (cols = 0; cols<length; cols++)
		{
			cave[rows][cols]=temp[rows][cols];
		}
	}
}

int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{
	// This function is responsible for making the move the user inputs
	
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	// set up our nested for loops 
	int rows;
	int cols;
	
	// surely we just rotate the cave [clockwise] and only check up
	// it's far better
	// alright to start:
	//						w	none
	//						a	once
	//						s	twice
	//						d	thrice
	if (move == 'a')
	{
		RotateCave(cave);
	} else if (move == 's')
	{
		RotateCave(cave);					//YOU CHANGE THE ROW!!!!!!!!!!!! 
		RotateCave(cave);
	} else if (move == 'd')
	{
		RotateCave(cave);
		RotateCave(cave);
		RotateCave(cave);
	}
	
	// and we need to make sure we rotate again when we're done
	// but now we check if a move up is good
	
	// find player coords
	int playerRow, playerCol;
	playerRow=0;
	playerCol=0;
	for (rows=0; rows<length; rows++)
	{
		for (cols = 0; cols<length; cols++)
		{
			if (cave[rows][cols]=='X')
			{
				playerRow=rows;
				playerCol=cols;
			}
		}
	}
	
	// and now we check if it's a valid move!
	
	// cannot move into walls of the cave
		// so check if is a wall and cancel if true
	// push boulder mechanics
		// boulder must be directly above player
		// boulder must be able to roll up
			// so is empty, or a hole
					// should probably also handle hole filling mechanics here (vv)
		// (player coords don't change)
		// if a boulder rolls into a hole, they both disappear
			// handled above
		// boudler rolls until stopped
			//(hits hole, treasure, another boulder or wall)
			// really means it's != an empty (b/c not hitting the player aha)
		// (we can assume the boulder won't be pushed through the exit)
	// also needs to return 1 if the player falls into a hole
	// and it has to return 2 if the player hits the exit
	
	// ok is the player moving into a wall
	// if yes, don't do it. Do nothing
	if (cave[playerRow-1][playerCol] == 1)
	{
		// a wall is put down as 1
		// we're trying to move into a wall
		// don't do it
		// also we need to return a number
		
		// we're about to return
		// rotate the cave back
		if (move == 'a')
		{
			RotateCave(cave);
			RotateCave(cave);
			RotateCave(cave);
		} else if (move == 's')
		{
			RotateCave(cave);
			RotateCave(cave);
		} else if (move == 'd')
		{
			RotateCave(cave);
		}
		
		// do nothing
		return 0;
	}
	
	// ok nice 1 down three to go
	// aha
	if (cave[playerRow-1][playerCol] == 'O')
	{
		// it's a boulder!
		// can we actually roll it?
		// need a space or a hole
		if ((cave[playerRow-2][playerCol] == 0) || (cave[playerRow-2][playerCol] == '*'))
		{	
			// O is boulder, 0 is a space, * is hole
		
			// can roll
			// boulder needs to roll now
			
			// figure out where it rolls to
			int boulderRow=playerRow-1;
			while (cave[boulderRow-1][playerCol]==0)
			{
				boulderRow--;
				// so when this stops, boulderRow is pointing at a square,
				// and we tried to index the square above it, but it wasn't a empty spot
				// so boulderRow is the row it can roll to unobstructed
				// so if the one above is a hole, then we should remove the boulder
				// otherwise if it's not a hole it's a treasure or wall or something
				// and we roll the boulder up to boulderRow
			}

			// also check if it fell into a hole
			if (cave[boulderRow-1][playerCol] == '*')
			{
				// delete both
				cave[playerRow-1][playerCol]=0;		// the boulder
				cave[boulderRow-1][playerCol]=0;	// the hole
			}
			else
			{
				// it didn't fall into a hole
				// move the boulder
				cave[boulderRow][playerCol]='O';
				// delete old boulder
				cave[playerRow-1][playerCol]=0;
			}
			
		} else {
			// can't roll
			// don't do anything
			// ok nice
		}
		
		// thus ends the boulder mechanics
		// we're about to return
		// rotate the cave back
		if (move == 'a')
		{
			RotateCave(cave);
			RotateCave(cave);
			RotateCave(cave);
		} else if (move == 's')
		{
			RotateCave(cave);
			RotateCave(cave);
		} else if (move == 'd')
		{
			RotateCave(cave);
		}
		
		// now we need to return something
		// so uh if we're in this loop we're hittng a boulder and not moving
		// and definitely not exiting a cave or falling into a hole
		// so
		return 0;
	}
	
	// and now we've handled boulders and is the player moving into a wall
	// now we handle the special cases
	
	// if it hits treasure we just overwrite
	
	// look after the special return conditions
		// hole?
	if (cave[playerRow-1][playerCol] == '*')
	{
		// delete player
		cave[playerRow][playerCol]=0;
		
		// we're about to return
		// rotate the cave back
		if (move == 'a')
		{
			RotateCave(cave);
			RotateCave(cave);
			RotateCave(cave);
		} else if (move == 's')
		{
			RotateCave(cave);
			RotateCave(cave);
		} else if (move == 'd')
		{
			RotateCave(cave);
		}
		
		// and return
		return 1;
	}
	
		// exit?
	if (cave[playerRow-1][playerCol] == 'E')
	{
		// ayyy good work
		// show player at the exit position
		cave[playerRow-1][playerCol] = 'X';
		// delete the old player
		cave[playerRow][playerCol] = 0;
		
		// we're about to return
		// rotate the cave back
		if (move == 'a')
		{
			RotateCave(cave);
			RotateCave(cave);
			RotateCave(cave);
		} else if (move == 's')
		{
			RotateCave(cave);
			RotateCave(cave);
		} else if (move == 'd')
		{
			RotateCave(cave);
		}
		
		// and return
		return 2;
	}
	
	// if you get to this point literally nothing cool has happened
	// you're just making a move
	// because we put a return in all the special cases
	// so just make the move
	cave[playerRow-1][playerCol] = 'X';
	// and be sure to delete where you were before
	cave[playerRow][playerCol] = 0;
	
	// don't forget to rotate the cave back to the OG position
		if (move == 'a')
	{
		RotateCave(cave);
		RotateCave(cave);
		RotateCave(cave);
	} else if (move == 's')
	{
		RotateCave(cave);
		RotateCave(cave);
	} else if (move == 'd')
	{
		RotateCave(cave);
	}
	
	
	// return your value
	// all the special cases have returned a value by now
	return 0;
}



/***********************************************************/
/***********************************************************/
/********* DO NOT MODIFY ANY CODE BELOW THIS POINT *********/
/***********************************************************/
/***********************************************************/

/* GetMove() returns the entered character. Invalid characters ignored */
char GetMove(void)
{
	char move;
	printf("\nEnter move: ");
	scanf("%c", &move);
	// Ignore any characters that are invalid
	while ((move != 'w') && (move != 'a') && (move  != 's') && (move != 'd')) {
		scanf("%c", &move);
	}
	return move;
}

/* The Boulder Break simulation */
int main(void)
{
	char story[2000];
	char layout[200] = "1111111111111000001111000000111000000001100000000E10010000011100000011111000001111111001111111111111";
	int cave[CAVE_SIZE][CAVE_SIZE] = {0};
	int gameOver = 0;

	InitialiseStory(story);
	InitialiseCave(cave, layout);
	AddItem(cave, 2, 4, "boulder");
	AddItem(cave, 5, 6, "boulder");
	AddItem(cave, 4, 8, "hole");
	AddItem(cave, 1, 4, "treasure");
	AddItem(cave, 4, 5, "player");
	
	/*char story[2000];
	char layout[200] = "11111100011000E1000111111";
	int cave[CAVE_SIZE][CAVE_SIZE] = {0};
	int gameOver = 0;
	
	InitialiseStory(story);
	InitialiseCave(cave, layout);
	AddItem(cave, 2, 3, "boulder");
	AddItem(cave, 3, 1, "treasure");
	AddItem(cave, 1, 2, "player");*/

	printf("ENGGEN131 - C Project 2022\n");
	printf("                          ... presents ...\n");
	printf("______   _____  _     _        ______  _______  ______\n");
	printf("|_____] |     | |     | |      |     \\ |______ |_____/\n");
	printf("|_____] |_____| |_____| |_____ |_____/ |______ |    \\_\n");
	printf("______   ______ _______ _______ _     _\n");
	printf("|_____] |_____/ |______ |_____| |____/ \n");
	printf("|_____] |    \\_ |______ |     | |    \\_\n");
	printf("\n");
	printf("%s\n", story);
	printf("\nMove the player (X) using the keys 'w', 'a', 's', 'd'\n");
	printf("Good luck!\n\n\n");

	/* Main game loop */
	PrintCave(cave);
	char move, move2;
	move = 'n';
	while (gameOver == 0)
	{
		move2 = getKey();	
		if (move2 != 'n')
		{
			// we got a key, do something
			move=move2;
			gameOver = MakeMove(cave, move); //GetMove());
			PrintCave(cave);
			if (gameOver == 1)
			{
				printf("\n\nGAME OVER!! \nYou died!\n\n");
			} else if (gameOver == 2)
			{
				printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
			}
		}
		
	}

	return 0;
}