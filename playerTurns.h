/*
 * playerTurns.h
 *
 *  Created on: 15 Apr 2017
 *      Author: SK
 */

#ifndef PLAYERTURNS_H_
#define PLAYERTURNS_H_

#include"structdefs.h"

//Function to move player to desired adjacent slot
void movePlayer(struct slot *player_slot);

//This function adjusts the stats of a player upon moving to a new slot as necessary
void adjustStats(struct players *record);

/*Magic Attack*/
int magicAttack(struct players record[],int no_players,int iteration);

/*Near Attack*/
int nearAttack(struct players record[],int no_players,int iteration);

/*distantAttack*/
int DistantAttack(struct players record[],int no_players,int iteration);















#endif /* PLAYERTURNS_H_ */
