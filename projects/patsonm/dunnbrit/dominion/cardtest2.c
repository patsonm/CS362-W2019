/*This is the card test for the Greate hall

int funcGreatHall(struct gameState *state, int currentPlayer, int handPos)
        {
          //+1 Card
          drawCard(currentPlayer, state);

          //+1 Actions
            //bug at -- instead of ++
          state->numActions--;

          //discard card from hand
          discardCard(handPos, currentPlayer, state, 0);
          return 0;
        }


//same player
//+1 Card (increase hand)
    +1 Action(increase action)
*/



#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"
#include "assert.h"
#define TESTCARD "Great Hall"

int main(){
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
    printf("Card Test 2:\n");
    printf("Great Hall:\n");
    printf("**Gamestate Created**\n");  
    printf("\n");
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
    if(result==0){
    printf("PASS: Greathall ran");
        printf("\n");
    
    player2=G.whoseTurn;
    if(player1==player2){
    printf("PASS: Same Player is Active");
    printf("\n");}
    
    if(player1!=player2){
    printf("FAIL: Same Player is Active");
    printf("\n");} 
        
    actions2=G.numActions;
    if(actions==actions2){
    printf("PASS: Same number of actions left");
    printf("\n");}
        
     if(actions!=actions2){
    printf("FAIL: Same number of actions left");
    printf("\n");}    
    
    handCount2=G.handCount[1];
    if(handCount2==handCount1){
    printf("PASS: Hand Count has increased");
    printf("\n");}
        
    if(handCount2!=handCount1){
    printf("FAIL: Hand Count has increased");
    printf("\n");}    
        
    }
    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
     return 0;
}
         
         