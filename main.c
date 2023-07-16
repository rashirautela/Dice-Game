//includes for the required header files
#include <stdio.h>
#include <stdlib.h>
#include "dicegame.h"
#include <time.h>

//The main() function with both the parameters
int main(int argc, char* argv[])
{
	// Initializing the srand() to start the random generator
        srand(time(NULL));
	// Initializing the player-1 and player-2 points to 0
        int player1Points = 0;
        int player2Points = 0;
	// Initializing all other required variables
        int roundsNum, i, typeRound, dice, scoredPoints, temp;

        int firstPlayer = 1;
        int secondPlayer = 2;
        int currentPlayer = getRandomNumber(1,2);

	// Asking the user for the number of rounds to run the game
        printf("Enter the number of rounds: ");
        scanf("%d", &roundsNum);
	// Calling printPlayerPoints() function to print the initial player points which will be 0
	printPlayerPoints(player1Points, player2Points);
	// Setting up the loop to go through all the rounds one at a time
        for( i = 0; i < roundsNum; i++ )
	{
		// Calling the corresponding functions to get the information for this round - type, dice, points
                typeRound = getRoundType( );
                dice = getRandomNumber(1,6);
                scoredPoints = getRoundPoints(typeRound);
		// Printing round number
                printf("\nROUND %d\n", i + 1);
                printf("--------\n");
		// Printing current player
                printf("Player\t: %d ",currentPlayer);
	        // Calling printRoundInfo() to print the round information
		printRoundInfo(typeRound, dice, scoredPoints);
                
		// MAIN GAME LOGIc

                if(dice % 2 != 0 && currentPlayer == 1)
                        player1Points = player1Points + scoredPoints;
                else if(dice % 2 == 0 && currentPlayer == 2)
                        player2Points = player2Points + scoredPoints;
                else if(dice % 2 == 0 && currentPlayer == 1)
                {
                        player1Points = player1Points - scoredPoints;
                        currentPlayer = 2;
                }
                else if(dice % 2 != 0 && currentPlayer == 2)
                {
                        player2Points = player2Points - scoredPoints;
                        currentPlayer = 1;
                }

                printPlayerPoints(player1Points, player2Points);
	}
	printf("\nGAME OVER!!\n");
	// Comparing the final points for player-1 and player-2 to print the winner
        if(player1Points > player2Points)
                printf("P1 Won\n");
        else
                printf("P2 Won\n");
	
        return 0;
}