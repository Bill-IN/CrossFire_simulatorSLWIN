/*
 * imp_playerTurns.c
 *
 *  Created on: 15 Apr 2017
 *      Author: SK
 */
#include<stdio.h>
#include"playerTurns.h"
#include"structdefs.h"
#include<string.h>
#include<stdlib.h>
#include"crossfireOperations.h"

void movePlayer(struct slot *player_slot)
{
	int choice;
	//Available adjacent slots:FIND A WAY TO HANDLE ERRORS PROPERLY

	//Must check corners first
	if(((player_slot->up)==NULL) && ((player_slot->left)==NULL))
	{
		puts("This position is not on the board");
		puts("This position is not on the board");
		printf("Press 3 to move right(%d, %d) \n",player_slot->right->row,player_slot->right->column);
		printf("Press 4 to move down(%d, %d) \n",player_slot->down->row,player_slot->down->column);
		scanf("%d", &choice);
	}

	else if(((player_slot->up)==NULL) && ((player_slot->right)==NULL))
	{
		printf("Press 1 to move left(%d, %d) \n",player_slot->left->row,player_slot->left->column);
		puts("This position is not on the board");
		puts("This position is not on the board");
		printf("Press 4 to move down(%d, %d) \n",player_slot->down->row,player_slot->down->column);
		scanf("%d", &choice);
	}

	else if(((player_slot->down)==NULL) && ((player_slot->right)==NULL))
	{
		printf("Press 1 to move left(%d, %d) \n",player_slot->left->row,player_slot->left->column);
		printf("Press 2 to move up (%d, %d) \n",player_slot->up->row,player_slot->up->column);
		puts("This position is not on the board");
		puts("This position is not on the board");
		scanf("%d", &choice);
	}

	else if(((player_slot->down)==NULL) && ((player_slot->left)==NULL))
	{
		puts("This position is not on the board");
		printf("Press 2 to move up (%d, %d) \n",player_slot->up->row,player_slot->up->column);
		printf("Press 3 to move right(%d, %d) \n",player_slot->right->row,player_slot->right->column);
		puts("This position is not on the board");
		scanf("%d", &choice);
	}

	//Checking edges
	else if((player_slot->left)==NULL)
	{
		puts("This position is not on the board");
		printf("Press 2 to move up (%d, %d) \n",player_slot->up->row,player_slot->up->column);
		printf("Press 3 to move right(%d, %d) \n",player_slot->right->row,player_slot->right->column);
		printf("Press 4 to move down(%d, %d) \n",player_slot->down->row,player_slot->down->column);
		scanf("%d", &choice);
	}

	else if((player_slot->right)==NULL)
	{
		printf("Press 1 to move left(%d, %d) \n",player_slot->left->row,player_slot->left->column);
		printf("Press 2 to move up (%d, %d) \n",player_slot->up->row,player_slot->up->column);
		puts("This position is not on the board");
		printf("Press 4 to move down(%d, %d) \n",player_slot->down->row,player_slot->down->column);
		scanf("%d", &choice);
	}

	else if((player_slot->up)==NULL)
	{
		printf("Press 1 to move left(%d, %d) \n",player_slot->left->row,player_slot->left->column);
		puts("This position is not on the board");
		printf("Press 3 to move right(%d, %d) \n",player_slot->right->row,player_slot->right->column);
		printf("Press 4 to move down(%d, %d) \n",player_slot->down->row,player_slot->down->column);
		scanf("%d", &choice);
	}

	else if((player_slot->down)==NULL)
	{
		printf("Press 1 to move left(%d, %d) \n",player_slot->left->row,player_slot->left->column);
		printf("Press 2 to move up (%d, %d) \n",player_slot->up->row,player_slot->up->column);
		printf("Press 3 to move right(%d, %d) \n",player_slot->right->row,player_slot->right->column);
		puts("This position is not on the board");
		scanf("%d", &choice);
	}


	else
	{
		printf("Press 1 to move left(%d, %d) \n",player_slot->left->row,player_slot->left->column);
		printf("Press 2 to move up (%d, %d) \n",player_slot->up->row,player_slot->up->column);
		printf("Press 3 to move right(%d, %d) \n",player_slot->right->row,player_slot->right->column);
		printf("Press 4 to move down(%d, %d) \n",player_slot->down->row,player_slot->down->column);
		scanf("%d", &choice);
	}

	puts("");

	//Checking slot location to determine value changes
	switch(choice)
	{
	case 1: *player_slot=*player_slot->left;
	printf("You are now at slot (%d, %d) \n\n",player_slot->row,player_slot->column);
	break;

	case 2: *player_slot=*player_slot->up;
	printf("You are now at slot (%d, %d) \n\n",player_slot->row,player_slot->column);
	break;

	case 3: *player_slot=*player_slot->right;
	printf("You are now at slot (%d, %d) \n\n",player_slot->row,player_slot->column);
	break;

	case 4: *player_slot=*player_slot->down;
	printf("You are now at slot (%d, %d) \n\n",player_slot->row,player_slot->column);
	break;

	default : puts("Please enter one of the numbers specified");
	}
}

void adjustStats(struct players *record)
{
	//Level Ground
	if(strcmp(record->player_slot->slot_name,"Level Ground")==0)
	{/*Do nothing*/}

	//Hill
	else if(strcmp(record->player_slot->slot_name,"Hill")==0)
	{
		if(record->Dexterity<50)
		{
			record->strength-=10;
		}

		else if(record->Dexterity>=60)
		{
			record->strength+=10;
		}

		//this is to cap the abilities so they don't go above 100 or below 0
		if(record->strength<0)
		{
			record->strength=0;
		}

		if(record->strength>100)
		{
			record->strength=100;
		}

	}

	//City
	else if(strcmp(record->player_slot->slot_name,"City")==0)
	{
		if(record->smartness>60)
		{
			record->magicSkills+=10;
		}

		else if(record->smartness<=50)
		{
			record->Dexterity-=10;
		}

		//this is to cap the abilities so they don't go above 100 or below 0
		if(record->Dexterity<0)
		{
			record->Dexterity=0;
		}

		if(record->magicSkills>100)
		{
			record->magicSkills=100;
		}
	}
}

int magicAttack(struct players record[],int no_players,int iteration)/*Problem here*/
{
	int j;
	int magic_power=record[iteration].smartness+record[iteration].magicSkills;

	if(magic_power<=150)//checks if character can perform a magic attack
	{
		printf("This character cannot perform a magic attack, due to the lack of smartness and magic skills, Please select a different move\n");
		return iteration-1;//basically restarts players turn as it sets the loop in main back one
	}

	else
	{
		printf("Please choose a target\n");//as there is no range limit, you can attack anyone regardless of there position, its pretty OP
		for(j=0;j<no_players;j++)
		{
			if(record[j].stillPlaying==FALSE)//Can't attack a dead player
			{
				continue;
			}

			if(j!=iteration)
			{
				printf("Press %d to attack: %s\n",record[j].Player_Num+1,record[j].name);//prints out the name and number of each player apart from the current player.
			}
		}

		//Choosing player to attack
		scanf("%d",&j);
		j=j-1;
		record[j].lifePoints=record[j].lifePoints-((0.5*record[iteration].magicSkills)+ (0.2*record[iteration].smartness));

		return iteration;
	}

}


/*Near Attack*/
int nearAttack(struct players record[],int no_players,int iteration){
	int i=iteration ;
	int n=0;
	int count=0;
	int j;
	int arrayA[no_players];//this array will store the players who are close enough for a near attack

	for(j=0;j<no_players;j++){
		if(record[j].stillPlaying==FALSE)
						{
							continue;
						}
		
		if((record[i].player_slot==record[j].player_slot  || record[j].player_slot==record[i].player_slot->right || record[j].player_slot==record[i].player_slot->left || record[j].player_slot==record[i].player_slot->up || record[j].player_slot==record[i].player_slot->down) && i !=j  ){
			arrayA[n]=j;//effectivley stores the player number, if the are close enough for a near attack
			n++;//increments arrayA=for another target
			count++;//used sort of like a boolean value,c doesnt really support boolean so im using count instead.
		}
	}

	if(count==0){
		printf("There is no opponent close enough for a near attack, Please choose another option\n");
		return i-1;//restarts turn
	}
	else{
		if(count==1){
			printf("There was only one possible target to attack, You attacked: %s\n",record[arrayA[0]].name);

			if(record[arrayA[0]].strength<=70){
				record[arrayA[0]].lifePoints=record[arrayA[0]].lifePoints-(record[i].strength*0.5);
			}
			else{
				record[i].lifePoints = record[i].lifePoints - (0.3*record[arrayA[0]].strength);

			}

			return iteration ;//will carry this attack out as there is only one target to hit so theres no choice, it will then finish this players turn
		}

		if(count >1){

			printf("there is more than one target legible for a near attack, please chose one\n");
			printf("please select a target\n");
			for(j=0;j<count;j++){//will print out all possible targets that are currently in the arrayA
				printf("Press %d to attack: %s\n",j+1,record[arrayA[j]].name);
			}

			scanf("%d",&j);
			j=j-1;//same as in magic attack
			if(record[arrayA[j]].strength<=70){
				record[arrayA[j]].lifePoints=record[arrayA[j]].lifePoints-(record[i].strength*0.5);
			}
			else if(record[arrayA[j]].strength>70){
				record[i].lifePoints = record[i].lifePoints - (0.3*record[arrayA[j]].strength);

			}

			return iteration ;//ends current players turn
		}

	}

	return iteration -1;
}


int DistantAttack(struct players record[],int no_players,int iteration)
{

	int n=0;
	int count=0;
	int j;
	int arrayB[no_players];//this array will store the players who are close enough for a near attack

	for(j=0;j<no_players;j++){
		
		if(record[j].stillPlaying==FALSE)
						{
							continue;
						}
		
		if(   ( (record[iteration].player_slot->column+2==record[j].player_slot->column && record[iteration].player_slot->row==record[j].player_slot->row ) \
				||(record[iteration].player_slot->column+4==record[j].player_slot->column && record[iteration].player_slot->row==record[j].player_slot->row ) \
				|| (record[iteration].player_slot->column+3==record[j].player_slot->column && record[iteration].player_slot->row==record[j].player_slot->row ) \

				/* bottom targets  */
				||(record[iteration].player_slot->row+2==record[j].player_slot->row && record[iteration].player_slot->column==record[j].player_slot->column )  \
				||(record[iteration].player_slot->row+3==record[j].player_slot->row && record[iteration].player_slot->column==record[j].player_slot->column )  \
				||(record[iteration].player_slot->row+4==record[j].player_slot->row && record[iteration].player_slot->column==record[j].player_slot->column )  \


				/* up targets   */
				||(record[iteration].player_slot->row-2==record[j].player_slot->row && record[iteration].player_slot->column==record[j].player_slot->column )  \
				||(record[iteration].player_slot->row-3==record[j].player_slot->row && record[iteration].player_slot->column==record[j].player_slot->column )  \
				||(record[iteration].player_slot->row-4==record[j].player_slot->row && record[iteration].player_slot->column==record[j].player_slot->column )  \


				/* left hand targets */
				||(record[iteration].player_slot->column-2==record[j].player_slot->column && record[iteration].player_slot->row==record[j].player_slot->row ) \
				||(record[iteration].player_slot->column-4==record[j].player_slot->column && record[iteration].player_slot->row==record[j].player_slot->row ) \
				|| (record[iteration].player_slot->column-3==record[j].player_slot->column && record[iteration].player_slot->row==record[j].player_slot->row ) \
		)	&& iteration !=j  ){
			arrayB[n]=j;//effectivley stores the player number, if the are close enough for a distant attack
			n++;//increments arrayB=for another target
			count++;//used sort of like a boolean value,c doesnt really support boolean so im using count instead.


		}
	}
	if(count==0){
		printf("There is no opponent close enough for a near attack, Please choose another option\n");
		return iteration-1;//restarts turn
	}
	else{
		if(count==1){
			printf("There was only one possible target to attack, You attacked: %s\n",record[arrayB[0]].name);

			if(record[arrayB[0]].strength<=70){
				record[arrayB[0]].lifePoints=record[arrayB[0]].lifePoints-(record[iteration].strength*0.5);
			}
			else{
				record[iteration].lifePoints = record[iteration].lifePoints - (0.3*record[arrayB[0]].strength);

			}

			return iteration;//will carry this attack out as there is only one target to hit so theres no choice, it will then finish this players turn
		}

		if(count >1){

			printf("there is more than one target legible for a near attack, please choose one\n");
			printf("please select a target\n");
			for(j=0;j<count;j++){//will print out all possible targets that are currently in the arrayB
				printf("Press %d to attack: %s\n",j+1,record[arrayB[j]].name);
			}

			scanf("%d",&j);
			j=j-1;//same as in magic attack
			if(record[arrayB[j]].Dexterity <= record[iteration].Dexterity)
			{
				puts("You missed\n");
				return iteration;
			}

			else if(record[iteration].Dexterity > record[arrayB[j]].Dexterity)
			{
				printf("You attacked %s \n", record[arrayB[j]].name);
				record[arrayB[j]].lifePoints=record[arrayB[j]].lifePoints-(0.3*record[iteration].strength);
				return iteration;
			}


			return iteration;//ends current players turn
		}

	}

	return iteration-1;
}
