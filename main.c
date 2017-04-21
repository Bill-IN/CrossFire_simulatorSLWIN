/*
 * main.c
 *
 *  Created on: 10 Mar 2017
 *      Author: SK
 */
/*24 Feb 2017
 *Admin
 *15:33:56
 *Comp10050project
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
//#include "slots.h"
#include "players.h"
#include "structdefs.h"
#include"crossfireOperations.h"
#include"playerTurns.h"


int main()
{
	/*Mandatory declarations*/
	setvbuf(stdout, NULL, _IOLBF, 0);//Printing in eclipse requires this line.
	srand(time(NULL));

	/*Slot variable declarations*/

		struct slot *upLeft;//pointer to slot (0,0)

		struct slot *upRight;//pointer to slot (0,boardSize -1)

		struct slot *downLeft;//pointer to slot (boardSize - 1, 0)

		struct slot *downRight;//pointer to slot (boardSize - 1, boardSize -1)

	/*Array index variables and no. players*/
	int num_players,i,choice,players_playing,winner;

	/*Players setup*/
	printf("Please enter the number of players:\n");
	scanf("%d",&num_players);
	players_playing=num_players;//players_playing=number of players currently playing the game(Initially all players are playing)
	printf("\n\n");

	//Game start only if two players have joined
	if(num_players<=1 || num_players>6){
		printf("error too many or not enough players\n");
		return (0);
	}

	//Creating players
	struct players record[num_players]; //Initializes the struct players record array
	PlayerCreation(record,num_players);//passes are players array and the variable k which in this case is equal to the number of players
	printf("\n");
	playerPrint(record,num_players);//passes players array and the variable k which in this case is equal to the number of players
	printf("\n");


	/*Slots setup*/
	createBoard(BOARD_SIZE,&upLeft, &upRight, &downLeft, &downRight,record,num_players);//Creates the board

	puts("-----------------------------");

	/*Player moves*/
for(i=0;i<num_players;i++){
	printf("lifepoints:%d | currently at slot (%d, %d)\n\n", record[i].lifePoints,record[i].player_slot->row,record[i].player_slot->column);
}

	while(players_playing>0)
	{

		//Going through each player's turn
		for(i=0;i<num_players;i++)
		{

				if(record[i].lifePoints<=0)//Player is dead
				{
					record[i].stillPlaying=FALSE;//Can't play anymore
					players_playing-=1;
					printf("****%s****\n", record[i].name);
					printf("||| player %d:%s is DEAD ;-) ;-) ||| \n", record[i].Player_Num+1,record[i].name);
				}

				if(record[i].stillPlaying==FALSE)//Player has left
				{
					continue;//Skip turn
				}

				else if(record[i].stillPlaying==TRUE)
				{
					printf("****%s****\n", record[i].name);
					printf("lifepoints:%d | currently at slot (%d, %d)\n\n", record[i].lifePoints,record[i].player_slot->row,record[i].player_slot->column);

					//Displaying different options for each player
					puts("Please press 1 to move");
					puts("Please press 2 to attack");
					puts("Please press 3 to leave");
					scanf("%d", &choice);
					puts("");


					if(choice==1)
					{
						movePlayer(record[i].player_slot);
						adjustStats(&record[i]);
					}

					if(choice==2)
					{
						puts("Please press 1 to perform magic attack");
						puts("Please press 2 to perform near attack");
						puts("Please press 3 to perform distant attack");
						scanf("%d", &choice);
						puts("");

						switch(choice)
						{
							case 1: i=magicAttack(record,num_players,i);
									break;

							case 2: i=nearAttack(record,num_players,i);
									break;

							case 3:	i=DistantAttack(record,num_players,i);
									break;

							default : puts("Please enter one of the listed numbers");
						}
					}

					if(choice==3)
					{
						record[i].stillPlaying=FALSE;//Not playing anymore
						players_playing-=1;
					}

					if(choice<1 || choice>3)
					{
						i=i-1;//Repeat iteration
					}

					winner=i;
				}
		}


		/*Conditions for game termination*/
		if(players_playing==0)
		{
			puts("|-|-|-|-|-|-Everybody left the game.GAME OVER-|-|-|-|-|-|");
			return -1738;//End the game
		}

		if(players_playing==1 && record[winner].stillPlaying==TRUE)
		{
			printf("__*****player %d:%s is the winner!!!!!!*****__", record[winner].Player_Num+1,record[winner].name);
			return 31337;//End the game
		}
	}
	return 0;
}


