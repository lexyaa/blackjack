#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n_pull=1;
int j, k;

int pulled_card1[52];
int pulled_card2[52];

char card[4][13][6]={
	{"hrtA ", "hrt2 ", "hrt3 ", "hrt4 ", "hrt5 ", "hrt6 ", "hrt7 ", "hrt8 ", "hrt9 ", "hrt10", "hrtJ ", "hrtQ ", "hrtK "},
	{"diaA ", "dia2 ", "dia3 ", "dia4 ", "dia5 ", "dia6 ", "dia7 ", "dia8 ", "dia9 ", "dia10", "diaJ ", "diaQ ", "diaK "},
	{"spdA ", "spd2 ", "spd3 ", "spd4 ", "spd5 ", "spd6 ", "spd7 ", "spd8 ", "spd9 ", "spd10", "spdJ ", "spdQ ", "spdK "},
	{"clvA ", "clv2 ", "clv3 ", "clv4 ", "clv5 ", "clv6 ", "clv7 ", "clv8 ", "clv9 ", "clv10", "clvJ ", "clvQ ", "clvK "}
	};
	
char holdCard[6][6];

int pull_card()
{
	int n, m;
	
	//pulling a card without repition
	while(n<n_pull)
	{
		srand((unsigned)time(NULL));
	    j=rand()%4;
	    k=rand()%13;
	    
	    pulled_card1[n_pull]=j;
	    pulled_card2[n_pull]=k;
	    
	    if(n_pull==52)
	    {
	    	printf("There is no card anymore!\n");
	    	game_end();
		}
		else if((pulled_card1[n]==j)&&(pulled_card2[n]==k))
		{
			continue;
		}
	    else
		{
			break;
		}
    }
    
    return n_pull++;
}

//printing the card
char print_card()
{
	int m=0;
	for(m=0;m<5;m++)
	{
		printf("%c", card[j][k][m]);
	}
	return 0;
}

char hold_card()
{
	int m;
	holdCard[n_pull][6]=card[j][k][m];
	for(m=0;m<5;m++)
	{
		printf("%c", card[j][k][m]);
	}
	return 0;
}

//sum of pulled card
int sum_card()
{
	
	int n_card[4][13]={
		{11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10},
		{11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10},
		{11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10},
		{11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10},
	};
	
	printf(" (sum=%d)", n_card[j][k]);
	
	return 0;
}

int betting(int n)
{
	//betDollar; betting the money
	int bet_I;
	
	int asset[5]={50, 50, 50, 50, 50};
	
	int betting[5]={1, 1, 1, 1, 1};
	
	do // betting the money of user
	{
		printf(" Your present asset is %d dollars\n", asset[0]);
	    printf(" Bet the money (only 1~%d) : ", asset[0]);
	    scanf("%d", &bet_I);
	    printf("\n\n You bet %d dollars\n", bet_I);
	    
	    if(bet_I<1||bet_I>asset[0])      //Letting user bet the money again when the user doesn't enter 1~asset
	     printf(" Please bet the money only 1~%d\n", asset[0]);
	} while(bet_I<1||bet_I>asset[0]);
	
	int i;// betting the money of computer players
	srand((unsigned)time(NULL));
	for(i=1;i<n;i++)
	{
		betting[i]=1+rand()%asset[i];
	    printf(" player%d bet %d dollars\n", i, betting[i]);
    }
}

int game_end()
{
	printf("Game over!\n the winner is ");
	return 0;
}

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
	
	betting(n_player);
    
    //offering card
    pull_card();
    print_card();
    holdCard[6][6]=0;
    hold_card();
    sum_card();
    
    
	return 0;
}
