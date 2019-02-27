
/*Michael Patson*/
//reveals cards from deck until two treasure

//This is the random test for the adventure card
//the time library is used to randomization

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"
#include "assert.h"
#include <time.h>

#define TESTCARD "adventure"


int main()
{
    //set num of test here
    int numTest =100;
    
    //game counter varaibles
    int gameStateCreated=0;
    int cardRun=0;
    int cardRunFail=0;
    int cardFunctionFail=0;
    int cardFunction=0;
    int treasureFail=0;
    int treasure=0;
    
    
    struct gameState G;
    struct gameState S;
    
    for (int z=0; z < numTest; z++){
    int returnValue;
    int count;
    //change these variables to test
    //select random amount of players between 2 and 4
    //per dominip rules
    int r, n, k;
    n=4;
    k=2;
    r = rand() % (n + 1) + k;
    int players=r;
    
    
    //select random seed between 1-500
    
    n=50;
    k=1;
    r = rand() % (n + 1) + k;
    
    int randomSeed=r;
    int hand[10]={curse, smithy, mine, gardens, great_hall, salvager, sea_hag, adventurer, duchy, tribute};
    //int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
    //create a hand to pass in
    
    //if game is created, print 
    returnValue=initializeGame(players,hand,randomSeed, &G);
    
        
        //set gamestates equal
    S=G;
    if(returnValue == 0){
    {
    gameStateCreated++;
    //printf("**Gamestate Created**\n");  
    //printf("\n");
    }
	int intialHand;
     intialHand= G.handCount[G.whoseTurn];
	//check card value has changed
    
	
    returnValue=cardEffect(great_hall, 0, 0, 0, &G, 10, 0);
    if(returnValue==0){
    //printf("Pass: Card ran successfully");
        cardRun++;
       // printf("\n");
    }
    
     if(returnValue!=0){
    //printf("FAIL: Card did not run successfully");
     //printf("\n");
         cardRunFail++;
     }    
        
    int newHand;
    newHand= S.handCount[S.whoseTurn];
    if((intialHand+2)==newHand){
    //printf("PASS: New hand is two more, two cards were drawn");
    //printf("\n");
    cardFunction++;
    }
     if((intialHand+2)!=newHand){
    //printf("FAil: Two cards were not drawn");
     //printf("\n");
      cardFunctionFail++;
     }
    int x;
    for(x = 0; x < G.handCount[G.whoseTurn]; x++){
		if (G.hand[G.whoseTurn][x] == copper || G.hand[G.whoseTurn][x] == silver || G.hand[G.whoseTurn][x] == gold){
			count++;
		}
			
        }
	if(count==2){
    //printf("PASS: Two Treasure Cards are in hand");
    //printf("\n")
    treasure++;   
        ;
    }
        if(count!=2){
    //printf("FAIL: There are not two treasure cards in hand");
    //printf("\n");
    treasureFail++;        
        }
    }
        //printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
    }
    
    
    printf("Random Card Test :\n");
    printf("Adventure :\n");
    printf("The Test was run %d times\n", numTest);
    printf("Game States Created:  %d\n", gameStateCreated);
    printf("Card was successfully run:  %d\n", cardRun);
    printf("Card was UNsuccessfully run:  %d\n", cardRunFail);
   printf("Two cards were successfully drawn:  %d\n", cardFunction);
     printf("Two cards were UNsuccessfully drawn:  %d\n", cardFunctionFail);
      printf("The treasure amount in hand increased by two:  %d\n", treasure);
     printf("The treasure amount in hand did not increase:  %d\n", treasureFail);
     printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
   
    
    
	return 0;
}