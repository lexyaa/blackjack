#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	//getNumber; get the number of player
	int n_player;
	
	do
	{
	    printf(" enter the number of player (only 1~5, including you) : ");
	    scanf("%d", &n_player);
	    
		if(n_player>5||n_player<1)     //Letting user enter a integer again when the user doesn't enter 1~5
		 printf("\n  Please enter the number only 1~5");
	} while(n_player>5||n_player<1);
	
	//the number of round
	int n_round=1;
	
	printf("\n，，，，，，，，，，，，，，Game Start，，，，，，，，，，，，，，，，\n");
	printf("，，，，，，，，，，，，，，，Round %d，，，，，，，，，，，，，，，，，\n", n_round);
	
	//betDollar; betting dollars
	int bet_I;
	
	int asset[5];
	
	asset[0]=50;
	asset[1]=50;
	asset[2]=50;
	asset[3]=50;
	asset[4]=50;
	
	printf(" Your present asset is %d dollars\n", asset[0]);
	printf(" Bet the money (only 1~%d) : ", asset[0]);
	scanf("%d", &bet_I);
	printf("\n\n You bet %d dollars\n", bet_I);
	
	int i;
	srand((unsigned)time(NULL));
	for(i=1;i<n_player;i++)
	 printf(" player%d bet %d dollars\n", i, 1+rand()%asset[i]);

	return 0;
}
