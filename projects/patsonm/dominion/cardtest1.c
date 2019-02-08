/*This is the card test for the smithy
1. Current player should receive exactly 3 cards.

2. 3 cards should come from his own pile.

3. No state change should occur for other players.

4. No state change should occur to the victory card piles and kingdom card piles.


int funcSmithy(struct gameState *state, int handPos)
{
    int i = 0;
    int currentPlayer = whoseTurn(state);
      //+3 Cards
    //BUG, <= was previouls <
      for (i = 0; i <= 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
}
*/


#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"
#include "assert.h"
#define TESTCARD "smithy"

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
    printf("Card Test 1:\n");
    printf("Smithy:\n");
    printf("**Gamestate Created**\n");  
    printf("\n");
    }
    
    //intial hand count
    int handCount1=G.handCount[1];
    int player1=G.whoseTurn;
    int deckCountInitial= G.deckCount[1];
    //player should try three cards
  
	
	//test valid input
    
   returnValue = cardEffect(smithy, 0, 0, 0, &G, 10, 0);
	//returnValue = smithyFunc(&G, 4);
	
	
    if(returnValue==0)
    {
        printf("PASS:smithy run");
        printf("\n");
    }
    
    if(returnValue!=0)
    {
        printf("FAIL: smithy not run");
        printf("\n");
    }
    //second hand count
    int handCount2=G.handCount[1];
    int player2=G.whoseTurn;
    int deckCountInitial2= G.deckCount[1];
    
    if(handCount2>=(handCount1+3)){
        printf("PASS: Hand size was increased");
        printf("\n");
    }
    
    if(handCount2==handCount1){
        printf("FAIL: Hand size was not increased");
        printf("\n");
    }
    
    if(handCount2<=(handCount1+3)){
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
        
    //deck count decreased    
    if(deckCountInitial>deckCountInitial2) {
    printf("Pass: Deck was decreased");
    printf("\n");}
        
    if(deckCountInitial<deckCountInitial2) {
    printf("FAIL: Deck was NOT decreased");
    printf("\n");}
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}
    