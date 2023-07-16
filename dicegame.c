#include "dicegame.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber( int min, int max ) //function to generate random values
{
        return (rand() % (max - min + 1) + min);
}
ROUNDTYPE getRoundType( ) //function to get round type randomly
{
        int probability = getRandomNumber(0,9); 
        if (probability < 2) 
                return BONUS;
        else if (probability < 5)
                return DOUBLE; 
        else 
                return REGULAR;
}
int getRoundPoints( ROUNDTYPE roundType ) //function to get points on the basis of round type
{
        int points = getRandomNumber(1,10) * 10;
        if(roundType == BONUS)
                return 200;
        else if(roundType == DOUBLE)
                return (2*points);
        else    
                return points;
}
void printPlayerPoints( int p1, int p2 ) //function to print the initial player points
{
        printf("P1\t: %d\nP2\t: %d\n", p1, p2);
}
void printRoundInfo( ROUNDTYPE t, int dice, int points ) //function to print the round information
{
        if(t == BONUS)
                printf("\nType\t: BONUS\n");
        else if(t == DOUBLE)
                printf("\nType\t: DOUBLE\n");
        else
                printf("\nType\t: REGULAR\n");
        printf("Dice\t: %d\n", dice);
        printf("Points\t: %d\n", points);
}
