// GTA V Online Mission for IV
// Mission: Saints and Devils
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   7

void main(void)
{
	int i, loc;
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	CLEAR_ZONE(-188.731, -264.028, 14.6965, 300.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	SET_PARKED_CAR_DENSITY_MULTIPLIER(0.0);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);
	INIT_SETTINGS(-188.731, -264.028, 14.6965, 90.0);
	while ( ++num_items < MAX_PAGES ) selection_mem[num_items] = 0;
	while ( !IS_PLAYER_SCRIPT_CONTROL_ON(GetPlayerIndex()) ) WAIT(1000);

    while (TRUE)
    {
		WAIT(0);
		GET_CHAR_COORDINATES(GetPlayerPed(), &px, &py, &pz);
		GET_CHAR_HEADING(GetPlayerPed(), &ph);
		
		if(objrc == 0)
		{
			DRAW_MENU();
			PRINT_MAIN_LOGO(0.41, 0.05, "Saints and Devils");
			PRINT_DESC(0.17, 0.11, "I have bad news and good news. Bad news is: my nephew  has been sexually abused inside the church ");
			PRINT_DESC(0.17, 0.13, "by a pedophile priest. Good news is:  I want him dead and vanished from milky way! He  is  hiding ");
			PRINT_DESC(0.17, 0.15, "somewhere around the church surrounded by a bunch of bodyguards to keep his ass alive. He's always");
			PRINT_DESC(0.17, 0.17, "carrying his laptop  full of naked child pictures! Get his laptop at any costs and bring it back  ");
			PRINT_DESC(0.17, 0.19, "to LCPD Police Dept.");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			MANAGE_PLAYER();
			POLICE(0, 0);
			MANAGE_ACTORS(17);
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel,  BLIP_COLOR_WHITE, -193.573, -262.88, 14.6306, 0.0, 35000, 0);
			SPAWN_ACTOR(0,  MODEL_M_M_BUSINESS_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -279.305, -283.851, 15.6371, 270.0, 0);
			SPAWN_ACTOR(1,  MODEL_M_M_BUSINESS_03, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -279.294, -280.79,  15.6162, 270.0, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_BUSINESS_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -276.636, -279.039, 14.6154, 270.0, 0);
			SPAWN_ACTOR(3,  MODEL_M_Y_BUSINESS_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -276.707, -287.999, 14.627 , 270.0, 0);
			SPAWN_ACTOR(4,  MODEL_M_M_BUSINESS_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -278.044, -292.383, 14.6324, 270.0, 0);
			SPAWN_ACTOR(5,  MODEL_M_M_BUSINESS_03, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -276.802, -295.652, 14.2135, 270.0, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_BUSINESS_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -281.076, -273.306, 15.6328, 270.0, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_BUSINESS_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -278.166, -271.82,  14.6334, 270.0, 0);
			SPAWN_ACTOR(8,  MODEL_M_M_BUSINESS_03, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -277.565, -277.729, 15.0262, 270.0, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_BUSINESS_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -285.402, -296.32,  14.1053, 270.0, 0);
			objrc++;
		}
		

		if(objrc == 2)
		{
			PRINT_TXT("Take out the ~R~bodyguards~S~");
			
			if(peds[0].retc == 2 && peds[1].retc == 2 && peds[2].retc == 2 && peds[3].retc == 2 && peds[4].retc == 2 && peds[5].retc == 2 && peds[6].retc == 2 && peds[7].retc == 2 && peds[8].retc == 2 && peds[9].retc == 2)
			{
				objrc++;
			}	
		}
		
		if(objrc == 3)
		{
			PRINT_TXT("Take out the ~R~bodyguards~S~");	
			SPAWN_VEHICLE(1, MODEL_PMP600, NOBLIP, -290.713, -326.573, 11.5142, 300.0, vhealth, 1);
			SPAWN_ACTOR_INSIDE_CAR(10, 1, 10, MODEL_M_M_BUSINESS_02, WEAPON_MP5,  BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
			SPAWN_ACTOR_INSIDE_CAR(11, 1, 0,  MODEL_M_M_BUSINESS_03, WEAPON_MP5,  BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
			SPAWN_ACTOR_INSIDE_CAR(12, 1, 1,  MODEL_M_Y_BUSINESS_01, WEAPON_MP5,  BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
			SPAWN_ACTOR_INSIDE_CAR(13, 1, 2,  MODEL_M_Y_BUSINESS_02, WEAPON_MP5,  BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
			GO_AFTER_PLAYER_WITH_VEHICLE(10, 1);
			objrc++;
		}

		if(objrc == 4)
		{
			PRINT_TXT("Take out the ~R~bodyguards~S~");
			
			GENERATE_RANDOM_INT_IN_RANGE(0, 1, &loc);
			
			if(loc == 0)
			{
				SPAWN_ACTOR(14,  MODEL_M_O_MOBSTER, WEAPON_UNARMED, BLIP_COLOR_CYAN, 100, 100, 2000, 2000, -335.81, -297.858, 9.69452,  94.0, 0);
				SET_CHAR_AS_ENEMY(peds[14].actor, FALSE);
				SPAWN_ACTOR(15,  MODEL_M_M_BUSINESS_02, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 100, -337.579, -299.368, 9.62293, 94.0, 0);
				SPAWN_ACTOR(16,  MODEL_M_M_BUSINESS_02, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 100, -339.495, -296.369, 9.55039, 94.0, 0);
				SPAWN_ACTOR(17,  MODEL_M_M_BUSINESS_02, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 100, -333.575, -297.682, 9.88057, 94.0, 0);
				TASK_COMBAT(peds[15].actor, GetPlayerPed());
				TASK_COMBAT(peds[16].actor, GetPlayerPed());
				TASK_COMBAT(peds[17].actor, GetPlayerPed());
			}
			
			if(loc == 1)
			{
				SPAWN_ACTOR(14,  MODEL_M_O_MOBSTER, WEAPON_UNARMED, BLIP_COLOR_CYAN, 100, 100, 2000, 2000, -280.614, -243.531, 14.4845, 91.0, 0);
				SET_CHAR_AS_ENEMY(peds[14].actor, FALSE);
				SPAWN_ACTOR(15,  MODEL_M_M_BUSINESS_02, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 100, -290.936, -240.948, 14.1926, 91.0, 0);
				SPAWN_ACTOR(16,  MODEL_M_M_BUSINESS_02, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 100, -291.333, -244.848, 14.1755, 91.0, 0);
				SPAWN_ACTOR(17,  MODEL_M_M_BUSINESS_02, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 100, -295.628, -240.739, 13.965 , 91.0, 0);
				TASK_COMBAT(peds[15].actor, GetPlayerPed());
				TASK_COMBAT(peds[16].actor, GetPlayerPed());
				TASK_COMBAT(peds[17].actor, GetPlayerPed());
			}
			
			peds[14].objhash = laptop;
			TASK_SMART_FLEE_CHAR_PREFERRING_PAVEMENTS(peds[14].actor, GetPlayerPed(), 200.0, -2);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
		
		if(objrc == 5)
		{
			MANAGE_PICKUP(14);
			
			if(peds[14].retc == 1)
			{
				PRINT_TXT("Steal the ~b~priest laptop~s~");		
			}
			
			if(peds[14].retc == 2)
			{
				PRINT_TXT("The ~b~laptop~s~ has been dropped. Steal it!");
			}
			
			if(peds[14].objretc == 2 && peds[14].retc == 2)
			{
				objrc++;
				PLAY_CHECKPOINT_SOUND();
			}
		}
	
		if(objrc == 6)
		{
			SET_MISSION_CHECKPOINT(0, -407.047, 276.527, 10.9233, 5.0, "Deliver the ~b~laptop~s~ to ~Y~LCPD Police Dept~S~");
		}

		if(objrc == 7)
		{
			MISSION_COMPLETE("", 20000);
		}
	}
}