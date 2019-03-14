/*
 * cardtest4.c
 *
 The Villager card allows 
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "villager"

int main() {
    
    int returnValue;
    struct gameState G;
    //change these variables to test
    int players=2;
    int randomSeed=1;
    int hand[10]={curse, smithy, mine, gardens, great_hall, salvager, sea_hag, adventurer, silver, gold};
    //int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
    //create a hand to pass in
    
    int player1=G.whoseTurn;
    int player2;
    int actions=G.numActions;
    int actions2;
    int handCount1=G.handCount[1];
    int handCount2;
    int deckCountInitial= G.deckCount[1];
    int deckCountInitial2;
    //if game is created, print 
    returnValue=initializeGame(players,hand,randomSeed, &G);
    assert(returnValue == 0);
    {
    printf("Card Test 4:\n");
    printf("Villager:\n");
    printf("**Gamestate Created**\n");  
    printf("\n");
    }    
    
    //call the card
    returnValue=cardEffect(great_hall, 0, 0, 0, &G, 10, 0);
    
    player2=G.whoseTurn;
    actions2=G.numActions;
    handCount2=G.handCount[1];
    deckCountInitial2= G.deckCount[1];
    
    if(returnValue==0){
    printf("Pass: Card ran successfully");
        printf("\n");}
    
    if(returnValue!=0){
    printf("FAIL: Card did not run successfully");
     printf("\n");}  
    
    
    
    if(handCount2>(handCount1)){
        printf("PASS: Hand size was increased");
        printf("\n");
    }
    
    if(handCount2==handCount1){
        printf("FAIL: Hand size was not increased");
        printf("\n");
    }
    
    if(handCount2<=(handCount1+1)){
        printf("PASS: Hand size was decreased");
        printf("\n");
    }
    
    //still same palyer is active
    if(player1==player2){
    printf("PASS: Same Player is Active");
    printf("\n");
    }
    
    if(player1!=player2){
    printf("FAIL: Same Player is not Active");
    printf("\n");
    }       
    
    
    if(actions==actions2){
    printf("PASS: Same number of actions left");
    printf("\n");}
        
     if(actions!=actions2){
    printf("FAIL: Same number of actions left");
    printf("\n");} 
    
    //deck count decreased    
    if(deckCountInitial>deckCountInitial2) {
    printf("Pass: Deck was decreased");
    printf("\n");}
        
    if(deckCountInitial<deckCountInitial2) {
    printf("FAIL: Deck was NOT decreased");
    }
    
    
    
    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
    
return 0;    
    
}


