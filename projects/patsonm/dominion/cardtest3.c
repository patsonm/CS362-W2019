
/*Michael Patson*/
//reveals cards from deck until two treasure


#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"
#include "assert.h"

#define TESTCARD "adventure"


int main()
{
    
    
    int returnValue;
    int count;
    struct gameState G;
    //change these variables to test
    int players=2;
    int randomSeed=1;
    int hand[10]={curse, smithy, mine, gardens, great_hall, salvager, sea_hag, adventurer, duchy, tribute};
    //int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
    //create a hand to pass in
    
    
     printf("Card Test 3:\n");
    printf("adventure :\n");
    
    //if game is created, print 
    returnValue=initializeGame(players,hand,randomSeed, &G);
    if(returnValue == 0){
    {
   
    printf("**Gamestate Created**\n");  
    printf("\n");
    }
	int intialHand;
     intialHand= G.handCount[G.whoseTurn];
	//check card value has changed
    
	
    returnValue=cardEffect(adventurer, 0, 0, 0, &G, 10, 0);
    if(returnValue==0){
    printf("Pass: Card ran successfully");
        printf("\n");}
    
     if(returnValue!=0){
    printf("FAIL: Card did not run successfully");
     printf("\n");}    
        
    int newHand;
    newHand= G.handCount[G.whoseTurn];
    if((intialHand+2)==newHand){
    printf("PASS: New hand is two more, two cards were drawn");
    printf("\n");}
     if((intialHand+2)!=newHand){
    printf("FAil: Two cards were not drawn");
     printf("\n");}
    int x;
    for(x = 0; x < G.handCount[G.whoseTurn]; x++){
		if (G.hand[G.whoseTurn][x] == copper || G.hand[G.whoseTurn][x] == silver || G.hand[G.whoseTurn][x] == gold){
			count++;
		}
			
        }
	if(count==2){
    printf("PASS: Two Treasure Cards are in hand");
    printf("\n");}
        if(count!=2){
    printf("FAIL: There are not two treasure cards in hand");
    printf("\n");}
    }
        printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}