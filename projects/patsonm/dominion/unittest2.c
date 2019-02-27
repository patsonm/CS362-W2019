/*TThis unit tests, the ability to buy cards
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
    {
    printf("Unit Test 2:\n");
    printf("**Gamestate Created**\n");  
    printf("\n");
    }
    
    
    //in the random hande the user had silver and gold; the return should be 5
    returnValue=updateCoins(1, &G, 0);
    
    if(returnValue == 0){
    {
    printf("PASS: Coins were updated successful\n");
    printf("\n");
    }
    
        //five was randomy picked
        //silver and gold 2+3
    if(G.coins==5)
    {
        printf("PASS: Coins value is correct\n");
        printf("\n");
    }
        
      if(G.coins!=5)
    {
        printf("FAIL: Coins value is correct\n");
        printf("\n");
    }   
    
    }
    //test was a success
     printf("This test was a success");
    printf("\n");
    printf("\n");
  return 0;
}