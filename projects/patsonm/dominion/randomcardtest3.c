//testcard for smithy

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"
#include "assert.h"
#include <time.h>

#define TESTCARD "smithy"

int main(){
    
    //set num of teset here
    int numTest=100;
    
    //variables for counting results
    int gameStateCreated=0;
    int smithyNotRun=0;
    int smithyRun=0;
    int handDecreased=0;
    int handIncreased=0;
    int handEqual=0;
    int sameplayer=0;
    int differentplayer=0;
    int deckDecrease=0;
    int deckIncrease=0;
        
    
    
    printf("Before LOOp\n");
    for (int z=0; z < numTest; z++)
    {
printf("In LOOp\n");
    int returnValue;
    struct gameState G;
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
    
    
    int hand[10]={curse, smithy, mine, gardens, great_hall, salvager, sea_hag, adventurer, silver, gold};
    //int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
    //create a hand to pass in
    
    
    //if game is created, print 
    returnValue=initializeGame(players,hand,randomSeed, &G);
printf("gamestate:\n");
    if(returnValue == 0)
    {
    gameStateCreated++;
    //printf("**Gamestate Created**\n");  
    //printf("\n");
    }
  
    printf("gamestateupdated:\n");
    //intial hand count
    int handCount1=G.handCount[1];
    int player1=G.whoseTurn;
    int deckCountInitial= G.deckCount[1];
    //player should try three cards
  
	
	//test valid input
    printf("runsmithy:\n");
    returnValue = cardEffect(smithy, 0, 0, 0, &G, 1, 0);
	//returnValue = funcSmithy(&G, 4);
	printf("card effect run:\n");
	
    if(returnValue==0)
    {
        //printf("PASS:smithy run");
        //printf("\n");
        smithyRun++;
    }
    
    if(returnValue!=0)
    {
        //printf("FAIL: smithy not run");
        //printf("\n");
        smithyNotRun++;
    }
    //second hand count
    int handCount2=G.handCount[1];
    int player2=G.whoseTurn;
    int deckCountInitial2= G.deckCount[1];
    printf("Handcount1:\n");
    if(handCount2>=(handCount1+3)){
        //printf("PASS: Hand size was increased");
        //printf("\n");
        handIncreased++;
    }
     printf("Handcount2:\n");
    if(handCount2==handCount1){
        //printf("FAIL: Hand size was not increased");
        //printf("\n");
        handEqual++;
    }
     printf("Handcount3:\n");
    if(handCount2<=(handCount1+3)){
        //printf("PASS: Hand size was decreased");
        //printf("\n");
        handDecreased++;
    }
    printf("PLay1:\n");
    //still same palyer is active
    if(player1==player2){
    //printf("PASS: Same Player is Active");
    //printf("\n");
    sameplayer++;
    }
    printf("PLay2:\n");
    if(player1!=player2){
    //printf("FAIL: Same Player is not Active");
    //printf("\n");
    differentplayer++;
    }       
     printf("Deck1:\n");   
    //deck count decreased    
    if(deckCountInitial>deckCountInitial2) {
    //printf("Pass: Deck was decreased");
    //printf("\n");
    deckDecrease++;
    }
        printf("Deck2:\n");
    if(deckCountInitial<deckCountInitial2) {
    //printf("FAIL: Deck was NOT decreased");
    //printf("\n");
    deckIncrease++;
        
    }
	printf("The Test was run %d times\n", z);
    }
        
    
    printf("Random Card Test 1:\n");
    printf("Smithy:\n");

    
    
    printf("The Test was run %d times\n", numTest);
    printf("Game States Created:  %d\n", gameStateCreated);
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
    