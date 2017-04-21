/*
 * structdefs.h
 *
 *  Created on: 7 Mar 2017
 *      Author: SK
 */

#ifndef STRUCTDEFS_H_
#define STRUCTDEFS_H_


//Constants:size of board and distance from some slot to another
#define BOARD_SIZE 7//Board must be size 7 for assignment so this can be left as a constant
#define REQ_DISTANCE 3//******This can vary depending on type of attack******

/*
 * Definition of boolean types
 * This avoids using <stdbool.h>
 */
typedef int bool;
enum boolean{FALSE, TRUE};

//Struct definitions
struct players
{
	char name[30];
	char type[30];
	int Player_Num;
	int lifePoints;
	int luck;
	int smartness;
	int Dexterity;
	int strength;
	int magicSkills;
	enum boolean stillPlaying;

	struct slot *player_slot;
};

struct slot{
	//row number
	int row;
	//column number
	int column;
	//Location associated with slot;Level Ground,City or Hill
	char slot_name[30];
	// adjacent left slot
	struct slot *left;
	// adjacent right slot
	struct slot *right;
	// adjacent up slot
	struct slot *up;
	// adjacent down slot
	struct slot *down;
}slot;



#endif /* STRUCTDEFS_H_ */
