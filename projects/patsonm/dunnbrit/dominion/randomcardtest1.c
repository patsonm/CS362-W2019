//testcard for smithy

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"
#include "assert.h"
#include <time.h>

#define TESTCARD "smithy"


int main()
{
    //set num of test here
    int numTest =5000;
    
    //variables for checking game
    int gameStateCreated, smithyRun, smithyNotRun, handIncreased, handDecreased, handEqual, sameplayer, differentplayer, deckDecrease, deckIncrease;
    
    gameStateCreated=0;
    smithyRun=0;
    smithyNotRun=0;
    handIncreased=0;   
    handDecreased=0;   
    handEqual=0;   
    sameplayer=0;
    differentplayer=0;
    deckDecrease=0;
    deckIncrease=0;
    
    
    //create games tates
    
    struct gameState G;
    struct gameState S;
    

    for (int z=0; z < numTest; z++)
    {
        int returnValue;
        
        struct gameState G;
        struct gameState S;
         //change these variables to test
        //select random amount of players between 2 and 4
        //per dominip rules
        int r, n, k;
        n=4;
        k=2;
        r = rand() % (n + 1) + k;
        int players=r;


        //select random seed between 1-500

        n=500;
        k=1;
        r = rand() % (n + 1) + k;

        int randomSeed=r;
        int hand[10]={curse, smithy, mine, gardens, great_hall, salvager, sea_hag, adventurer, duchy, tribute};
        
         returnValue=initializeGame(players,hand,randomSeed, &G);
        
        if(returnValue == 0)
            {
            gameStateCreated++;
            //printf("**Gamestate Created**\n");  
            //printf("\n");
            }
        S=G;
        //intial hand count
        int handCount1=G.handCount[1];
        int player1=G.whoseTurn;
        int deckCountInitial= G.deckCount[1];
        //player should try three cards

	
	       //test valid input
    
        returnValue = cardEffect(smithy, 0, 0, 0, &G, 10, 0);
         if(returnValue==0)
        {
        //printf("PASS:smithy run");
        //printf("\n");
             smithyRun++;
        }
        
        if(returnValue!=0)
        {
        //printf("PASS:smithy run");
        //printf("\n");
             smithyNotRun++;
        }
        
        
        int handCount2=S.handCount[1];
        int player2=S.whoseTurn;
        int deckCountInitial2= S.deckCount[1];
      //same hand?
        if(handCount2>=(handCount1+3)){
        handIncreased++;
        }   
        
        if(handCount2==handCount1){
        handEqual++;
        }
        
        if(handCount2<(handCount1+3)){
        handDecreased++;
        }
        //same player
        if(player1==player2){
        sameplayer++;
        }

        if(player1!=player2){
        differentplayer++;
        } 
        
        //deck count decreased    
        if(deckCountInitial>deckCountInitial2) {
           deckDecrease++; 
        }
        
        if(deckCountInitial<=deckCountInitial2) {
        deckIncrease++;
        }
        
       
        
        
    
    }
    printf("The Test was run %d times\n", numTest);
    //printf("Game States Created:  %d\n", gameStateCreated);
    printf("Card was successfully run:  %d\n", smithyRun);
    printf("Fail: Card was UNsuccessfully run:  %d\n", smithyNotRun);
    
   printf("The Hand Increased (intended results):  %d\n", handIncreased);
     printf("Fail: Hand did not increase, it decreased:  %d\n", handDecreased);
       printf("Fail: Hand count is equal:  %d\n", handEqual);
    
      printf("Same player is active (intended result):  %d\n", sameplayer);
     printf("Fail: Player should not change:  %d\n", differentplayer);
    
    printf("Deck count decreased (intended result):  %d\n", deckDecrease);
     printf("Fail Deck count did not decrease:  %d\n", deckIncrease);
     printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
        
        
  
        
	return 0;
}
    