/*TThis unit tests the getCostfunction
*/

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"
#include "assert.h"


int main(int argc, char ** argv)
{
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
    assert(returnValue == 0);
    {
    printf("Unit Test 4:\n");
    printf("**Gamestate Created**\n");  
    printf("\n");
    }
    
   
	
	//curse
	returnValue = curse;
	returnValue2 = getCost(returnValue);
	if(returnValue2 == 0)
    {
    printf("Card 0, Curse, Success:\n");
    }
    if(returnValue2 != 0)
    {
    printf("Card 0, Curse, Fail:\n");
    }
    
    //estate
    returnValue = estate;
	returnValue2 = getCost(returnValue);
	if(returnValue2 == 2)
    {
    printf("Card 2, Estate, Success:\n");
    }
    
    if(returnValue2 != 2)
       {
    printf("Card 0, Estate, Fail:\n");
    }
    
    //duchy
    returnValue = duchy;
	returnValue2 = getCost(returnValue);
	if(returnValue2 == 5){
        
    printf("Card 3, Duchy, Success:\n");
    }
    if(returnValue2 != 5){
    printf("Card 3, Duchy, Fail:\n");
    }
    
    
    //fakecard
    returnValue = -1;
	returnValue2 = getCost(returnValue);
	if(returnValue2 == -1){
    printf("Fake Card Success:\n");
    }
  if(returnValue2 != -1){
    printf("Fake Card Fail:\n");
    }
    
    //test was a success
     printf("This test was a success");
    printf("\n");
    printf("\n");
  
       return 0;
       

       }
       

       
      