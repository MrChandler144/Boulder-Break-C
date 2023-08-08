/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

/***********************************************************/
/***********************************************************/
/******* ADD THE REQUIRED FUNCTIONS BELOW THIS POINT *******/
/***********************************************************/
/***********************************************************/

// Task One: InitialiseStory
void InitialiseStory(char* paragraph)
{
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
	"Tommy has fallen down a hole, and the union is\n"
	"too lazy to rescue him! Help him roll boulders,\n"
	"plug holes and make his daring escape, so that\n"
	"he can be reunited with Gina, his true love <3\n\n"
	
	"Make sure to grab any treasure you find, shiny\n"
	"trinkets and coins so you can make it I swear!"
		;

/*
Tommy's got his six-string in hock
Now he's holding in what he used to make it talk
So tough, it's tough
Gina dreams of running away
When she cries in the night, Tommy whispers
Baby, it's okay, someday
We've got to hold on to what we've got
It doesn't make a difference if we make it or not
We've got each other and that's a lot for love
We'll give it a shot
Woah, we're half way there
Woah, livin' on a prayer
Take my hand, we'll make it I swear
Woah, livin' on a prayer
Livin' on a prayer
Oh, we've got to hold on, ready or not
You live for the fight when it's all that you've got
Woah, we're half way there
Woah, livin' on a prayer
Take my hand, we'll make it I swear
Woah, livin' on a prayer
Woah, we're half way there
Woah, livin' on a prayer
Take my hand, we'll make it I swear
Woah, livin' on a prayer
Woah, we're half way there
Woah, livin' on a prayer
Take my hand, we'll make it I swear
Woah, livin' on a prayer";
*/
	
	int i;
	for (i=0; i<1998; i++)
	{
		paragraph[i]=story[i];
	}
	
	//printf("%s", paragraph);
}

// Task Two: PrintCave
void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
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
			if (cave[rows][cols] == '1')
			{
				printf("#");
			}
			else if (cave[rows][cols] == '0')
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
			index=10*rows + cols;
			cave[rows][cols]=layout[index];
		}
		// end of a row, go to next one
		//printf("\n");
	}
}

int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	//check the outer walls
	int i;
	for (i=0; i<length; i++)
	{
		if ((cave[i][0]!='1') || (cave[0][i]!='1') || (cave[i][length-1]!='1') || (cave[length-1][i]!='1'))
		{
			// so it wasn't wall
			//printf("\n got past 1. I is %d\n", i);
			//printf("%c %c %c %c", cave[i][0],cave[0][i],cave[i][length-1],cave[length-1][i]);
			if (!((cave[i][0]=='E') || (cave[0][i]=='E') || (cave[i][length-1]=='E') || (cave[length-1][i]=='E')))
			{
				// and it wasn't an exit. there's a hole
				// printf("\n returning 0\n");
				return 0;
			}
		}
	}
	return 1;
}

int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	// set up our nested for loops 
	int rows;
	int cols;
	rows=length;
	cols=length;
	
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
	}
	return 1;
	//printf("\n one exit\n");
}

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	// set up our nested for loops 
	int rows;
	int cols;
	rows=length;
	cols=length;
	
	
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
					// and not in the corners
					if (((rows+cols)==0) || ((rows+cols)==length-1) || ((rows+cols)==2*length-2))
					{
						// failed
						// we'll handle this here b/c all the failed ones have left the loop
					} else {
						// this is what we're looking for here
						// we've been culling the bad ones
						return 1;
					}
				}
			}
		}
	}
	// so uh yeah if it gets here it should have failed
	return 0;
}

void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element)
{
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	// set up our nested for loops 
	int rows;
	int cols;
	rows=length;
	cols=length;
	
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
		if (cave[row][col] != '0')
		{
			// so not a space, don't go ahead
			doWeGoQ=0;
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
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	// set up our nested for loops 
	int rows;
	int cols;
	rows=length;
	cols=length;
	
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
	// I don't trust CAVE_SIZE
	int length = CAVE_SIZE;
	// length is 10
	
	// set up our nested for loops 
	int rows;
	int cols;
	rows=length;
	cols=length;
	
	// surely we just rotate the cave [clockwise] and only check up
	// it's far better
	// alright to start:
	//						w	none
	//						a	once
	//						s	twice
	//						d	thrice
	if (move == 's')
	{
		RotateCave(cave);
	}
	else if (move == 'd')
	{
		RotateCave(cave);
		RotateCave(cave);
	}
	else if (move == 'w')
	{
		RotateCave(cave);
		RotateCave(cave);
		RotateCave(cave);
	}
	
	// and now we need to make sure we rotate again when we're done
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
					// should probably also handle hole filling mechanics here vv
		// (player coords don't change)
		// if a boulder rolls into a hole, they both disappear
			// handled above
		// boudler rolls until stopped
			//(hits hole, treasure, another boulder or wall)
			// really means it's != an empty
		// (boulder won't be pushed through the exit)
	// also needs to return 1 if the player falls into a hole
	// and it has to return 2 if the player hits the exit
	
	// ok is the player moving into a wall
	// if yes, don't do it. Do nothing
	if (cave[playerRow][playerCol-1] == '1')
	{
		// a wall is put down as 1
		// we're trying to move into a wall
		// don't do it
		// also we need to return a number
		
		// do nothing
		return 0;
		
	}
	
	// ok nice 1 down three to go
	// aha
	if (cave[playerRow][playerCol-1] == 'O')
	{
		// it's a boulder!
		// can we actually roll it?
		// need a space or a hole
		if ((cave[playerRow][playerCol-1] == 'O') || (cave[playerRow][playerCol-1] == '*'))
		{	
			// O is boulder, * is hole
		
			// can roll
			// boulder needs to roll now
			
			// figure out where it rolls to
			int boulderCol=playerCol-1;
			while (cave[playerRow][boulderCol-1]!='0')
			{
				boulderCol--;
				// so when this stops, boulderCol is pointing at an empty square,
				// and we tried to index the full square above it
			}
			
			// also check if it fell into a hole
			if (cave[playerRow][boulderCol-1] == '*')
			{
				// delete both
				cave[playerRow][boulderCol]='0';
				cave[playerRow][boulderCol-1]='0';
			}
			
		} else {
			// can't roll
			// don't do anything
		}
		
		// now we need to return something
		// so uh if we're in this loop we're hittng a boulder and not moving
		// and definitely not exitng a cave or falling into holes
		// so
		return 0;
	}
	
	// and now we've handled boulders and is the player moving into a wall
	// now we handle the special cases
	
	// if it hits treasure we just overwrite
	
	// look after the special return conditions
		// hole?
	if (cave[playerRow][playerCol-1] == '*')
	{
		// delete player
		cave[playerRow][playerCol]=0;
		
		// and return
		return 1;
	}
	
		// exit?
	if (cave[playerRow][playerCol-1] == 'E')
	{
		// ayyy good work
		// show player at the exit position
		cave[playerRow][playerCol-1] = 'X';
		
		// and return
		return 2;
	}
	
	// if you get to this point literally nothing cool has happened
	// you're just making a move
	// because we put a return in all the special cases
	// so just make the move
	cave[playerRow][playerCol-1] = 'X';
	// and be sure to delete where you were before
	cave[playerRow][playerCol] = '0';
	
	// don't forget to rotate the cave back to the OG position
		if (move == 's')
	{
		RotateCave(cave);
		RotateCave(cave);
		RotateCave(cave);
	} else if (move == 'd')
	{
		RotateCave(cave);
		RotateCave(cave);
	} else if (move == 'w')
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
	while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
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
//printf("632\n");
	PrintCave(cave);
/*printf("what the cave actually is");


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
			printf("%c", cave[rows][cols]);
		}
		printf("\n");
	}
*/
//printf("634\n");
	while (!gameOver) {
		gameOver = MakeMove(cave, GetMove());
		PrintCave(cave);
		if (gameOver == 1) {
			printf("\n\nGAME OVER!! \nYou died!\n\n");
		} else if (gameOver == 2) {
			printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
		}
	}

	return 0;
}