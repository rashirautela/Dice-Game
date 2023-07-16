// header guard
#ifndef dicegame_h
#define dicegame_h

typedef enum ROUNDTYPE { BONUS,DOUBLE,REGULAR } ROUNDTYPE;

//function prototypes
int getRandomNumber( );
ROUNDTYPE getRoundType( );
int getRoundPoints( ROUNDTYPE roundType );
void printPlayerPoints( int p1, int p2 );
void printRoundInfo( ROUNDTYPE t, int dice, int points );

#endif