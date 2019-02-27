//Test card fro create hall

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"
#include "assert.h"
#include <time.h>


#define TESTCARD "Great Hall"

int main(){
    
    
     //set num of teset here
    int numTest=100;
    
    //variables for counting results
    int gameStateCreated=0;
    
    
    int GreatHallNotRun=0;
    int GreatHallRun=0;
    int sameplayer=0;
    int differentplayer=0;
    int actionsSame=0;
    int actionsDifferent=0;
    int handDecreased=0;
    int handEqual=0;
    

        struct gameState G;
    struct gameState S;
    
    
    for (int z=0; z < numTest; z++){
    
    
    
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
    
    if(returnValue == 0)
    {
    gameStateCreated++;
    //printf("**Gamestate Created**\n");  
    //printf("\n");
    }    
        
    
    int player1=G.whoseTurn;
    int player2;
    int actions=G.numActions;
    int actions2;
    int handCount1=G.handCount[1];
    int handCount2;
    //same player
    //+1 Card (increase hand)
    //+1 Action(increase action)
    int result;
    result= cardEffect(great_hall, 0, 0, 0, &G, 10, 0);
     //set gamestates equal
    S=G;
    if(result==0){
    //printf("PASS: Greathall ran");
        //printf("\n");
        GreatHallRun++;
    }
        
        
    if(result!=0){
    //printf("Fail: Greathall ran");
        //printf("\n");
        GreatHallNotRun++;
    }    
    
    player2=S.whoseTurn;
    if(player1==player2){
    //printf("PASS: Same Player is Active");
    //printf("\n");
    sameplayer++;
    }
    
    if(player1!=player2){
    //printf("FAIL: Same Player is Active");
    //printf("\n");
    differentplayer++;
    } 
        
    actions2=S.numActions;
    if(actions==actions2){
    //printf("PASS: Same number of actions left");
    //printf("\n");
        actionsSame++;
    }
        
     if(actions!=actions2){
    //printf("FAIL: Same number of actions left");
    //printf("\n");
         actionsDifferent++;
     }    
    
    handCount2=S.handCount[1];
    if(handCount2<=handCount1){
    //printf("PASS: Hand Count has equal, one card removed");
    //printf("\n");
        handEqual++;
    
    }
        
    if(handCount2>handCount1){
    //printf("FAIL: Hand Count has increased");
    //printf("\n");
        handDecreased++;
    
    }    
        
    
        
    
    
    
        
       
}
    
    printf("Random Card Test 2:\n");
    printf("Great Hall:\n");
    
    printf("The Test was run %d times\n", numTest);
    //printf("Game States Created:  %d\n", gameStateCreated);
    printf("Card was successfully run:  %d\n", GreatHallRun);
    printf("Fail: Card was UNsuccessfully run:  %d\n", GreatHallNotRun);
     printf("Same player is active (intended result):  %d\n", sameplayer);
     printf("Fail: Player should not change:  %d\n", differentplayer);
    printf("Same player is active (intended result):  %d\n", sameplayer);
     printf("Fail: Player should not change:  %d\n", differentplayer);

     printf("The Hand Number of actions is same (intended results):  %d\n", actionsSame);
     printf("Fail: Number of actions different:  %d\n", actionsDifferent);
     
    printf("The hand is equal to old hand size after draw (intended result): %d\n" , handEqual);
    printf("Fail: There is a hand mismatch: %d\n" , handDecreased);

    
    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
        
        return 0;
}
    
    
         
         