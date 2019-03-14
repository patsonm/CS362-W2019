/*TThis unit tests the shuffle ability
*/

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"
#include "assert.h"


int main(int argc, char ** argv){
    int returnValue, returnValue2;
    
    struct gameState G;
    //change these variables to test
    int players=2;
    int randomSeed=1;
    int hand[10]={curse, smithy, mine, gardens, great_hall, salvager, sea_hag, adventurer, silver, gold};
    //int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
    //create a hand to pass in
    
     //if game is created, print 
    returnValue=initializeGame(players,hand,randomSeed, &G);
    if(returnValue == 0){
    {
    printf("Unit Test 3:\n");
    printf("**Gamestate Created**\n");  
    printf("\n");
    }
    
    //test a valid number
    G.deckCount[1] = 5;
	returnValue2 = shuffle(1, &G);
	if (returnValue2 == 0)
    {
    printf("Deck was shuffled succesfully\n");
    printf("\n");
    }
    
    //test a bad value for the deck size
    //a negative value should return 1
	G.deckCount[1] = -5;
	returnValue2 = shuffle(1, &G);
    
	if (returnValue2 == -1)
    {
    printf("Deck was shuffled succesfully\n");
    printf("\n");
    }
    }
    //test was a success
     printf("This test was a success");
    printf("\n");
    printf("\n");
  return 0;
}

