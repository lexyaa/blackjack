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
	
	printf("\n，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，\n，，，，，，，，，，，，，，Game Start，，，，，，，，，，，，，，，\n");
	printf("，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，\n，，，，，，，，，，，，，，，Round %d，，，，，，，，，，，，，，，，\n，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，\n", n_round);
	
	//betDollar; betting the money
	int bet_I;
	
	int asset[5];
	
	asset[0]=50;
	asset[1]=50;
	asset[2]=50;
	asset[3]=50;
	asset[4]=50;
	
	do // betting the money of user
	{
		printf(" Your present asset is %d dollars\n", asset[0]);
	    printf(" Bet the money (only 1~%d) : ", asset[0]);
	    scanf("%d", &bet_I);
	    printf("\n\n You bet %d dollars\n", bet_I);
	    
	    if(bet_I<1||bet_I>asset[0])      //Letting user bet the money again when the user doesn't enter 1~asset
	     printf(" Please bet the money only 1~%d\n", asset[0]);
	} while(bet_I<1||bet_I>asset[0]);
	
	int i; // betting the money of computer players
	srand((unsigned)time(NULL));
	for(i=1;i<n_player;i++)
	 printf(" player%d bets %d dollars\n", i, 1+rand()%asset[i]);
	
	//cardset
	
	int heartA=11; //value for calculating
	int heart2=2;
	int heart3=3;
	int heart4=4;
	int heart5=5;
	int heart6=6;
	int heart7=7;
	int heart8=8;
	int heart9=9;
	int heart10=10;
	int heartJ=10;
	int heartQ=10;
	int heartK=10;
	
	int diaA=11;
	int dia2=2;
	int dia3=3;
	int dia4=4;
	int dia5=5;
	int dia6=6;
	int dia7=7;
	int dia8=8;
	int dia9=9;
	int dia10=10;
	int diaJ=10;
	int diaQ=10;
	int diaK=10;
	
	int spadeA=11;
	int spade2=2;
	int spade3=3;
	int spade4=4;
	int spade5=5;
	int spade6=6;
	int spade7=7;
	int spade8=8;
	int spade9=9;
	int spade10=10;
	int spadeJ=10;
	int spadeQ=10;
	int spadeK=10;
	
	int clovA=11;
	int clov2=2;
	int clov3=3;
	int clov4=4;
	int clov5=5;
	int clov6=6;
	int clov7=7;
	int clov8=8;
	int clov9=9;
	int clov10=10;
	int clovJ=10;
	int clovQ=10;
	int clovK=10;
	
	//cardset
	char card[4][13][7]={
		{"hrtA", "hrt2", "hrt3", "hrt4", "hrt5", "hrt6", "hrt7", "hrt8", "hrt9", "hrt10", "hrtJ", "hrtQ", "hrtK"},
		{"diaA", "dia2", "dia3", "dia4", "dia5", "dia6", "dia7", "dia8", "dia9", "dia10", "diaJ", "diaQ", "diaK"},
		{"spdA", "spd2", "spd3", "spd4", "spd5", "spd6", "spd7", "spd8", "spd9", "spd10", "spdJ", "spdQ", "spdK"},
		{"clvA", "clv2", "clv3", "clv4", "clv5", "clv6", "clv7", "clv8", "clv9", "clv10", "clvJ", "clvQ", "clvK"}
	};
	
	srand((unsigned)time(NULL));
	int j=rand()%4;
	int k=rand()%13;
	
	int m;
	
	for(m=0;m<4;m++)
	{
		printf("%c", card[j][k][m]);
	}
	return 0;
}
