/*This unit test for numHandCards function
This functions returns the number of card in a hand
//creates a game state
//returns number of cards in hand
*/

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"
#include "assert.h"


int main(int argc, char ** argv){
    int returnValue;
    struct gameState G;
    //change these variables to test
    int players=2;
    int randomSeed=1;
    int hand[10]={curse, smithy, mine, gardens, great_hall, salvager, sea_hag, adventurer, silver, gold};
    //int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
    //create a hand to pass in
    
    
    //if game is created, print 
    returnValue=initializeGame(players,hand,randomSeed, &G);
    assert(returnValue == 0);
    
    printf("Unit Test 1:\n");
    printf("**Gamestate Created**\n");  
    printf("\n");
    
    int n;
    n = 10;
    
    returnValue=G.handCount[1];
    printf("%d", returnValue);
    if(returnValue == n)
    {
    printf("PASS: numHandCards returns the correct value\n"); 
    //printf("%d", n);    
    printf("\n");
    }
    
    if(returnValue != n)
    {
    printf("Fail: numHandCards Returns the correct value\n"); 
    //printf("%d", n);    
    printf("\n");
    }
    
    
    printf("This test was a success");
    printf("\n");
    printf("\n");

    
    return 0;
    
    
    
}