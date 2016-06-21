// GTA V Online Mission for IV
// Mission: All in the game
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   4

void main(void)
{
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	CLEAR_ZONE(-285.757, 1539.86, 20.4198, 200.0);
	INIT_SETTINGS(-1474.77, 1118.16, 23.0135, 271.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	CLEAR_ZONE(-1164.27, 672.434, 11.2206, 200.0);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);
	while ( ++num_items < MAX_PAGES ) selection_mem[num_items] = 0;
	while ( !IS_PLAYER_SCRIPT_CONTROL_ON(GetPlayerIndex()) ) WAIT(1000);
	
	while (TRUE)
    {
		WAIT(0);
		GET_CHAR_COORDINATES(GetPlayerPed(), &px, &py, &pz);
		GET_CHAR_HEADING(GetPlayerPed(), &ph);
		
		if (objrc == 0) 
		{
			DRAW_MENU();
			PRINT_MAIN_LOGO(0.41, 0.05, "All in the game");
			PRINT_DESC(0.34, 0.11, "Recreation of GTA V Online mission \"All in the game\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}	
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			POLICE(0, 0);
			ALTER_WANTED_LEVEL(GetPlayerIndex(), 0);
			MANAGE_PLAYER();
			MANAGE_ACTORS(9);
			MANAGE_VEHICLES(4);
			MANAGE_UNIQUE_VEHICLE_STATUS(1);
			LOCK_TIME_OF_DAY();
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, -1468.08, 1118.99, 22.9749, 180.0, 25000, 0);
			SPAWN_ACTOR(0, MODEL_M_Y_GAFR_LO_01, WEAPON_MP5, BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -288.902, 1537.98,  20.4198, 0.000, 0);
			SPAWN_ACTOR(1, MODEL_M_Y_GAFR_LO_02, WEAPON_MP5, BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -288.816, 1540.91,  20.4198, 180.0, 0);
			SPAWN_ACTOR(2, MODEL_M_Y_GAFR_HI_01, WEAPON_MP5, BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -283.1,   1540.83,  20.4198, 0.000, 0);
			SPAWN_ACTOR(3, MODEL_M_Y_GAFR_HI_02, WEAPON_MP5, BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -296.319, 1561.28,   20.418, 0.000, 0);
			SPAWN_VEHICLE(1, MODEL_REBLA, BLIP_COLOR_CYAN, -285.757, 1539.86, 20.4198, 0.0, 2000, 0);
			TASK_CHAT_WITH_CHAR(peds[0].actor, peds[1].actor, 1, 1);
			TASK_CHAT_WITH_CHAR(peds[1].actor, peds[0].actor, 0, 1);
			PLAY_CHECKPOINT_SOUND();
			objrc++;			
		}
		
		if(objrc == 2)
		{
			PRINT_TXT("Repo the ~b~Rebla~S~");
			
			if(DOES_VEHICLE_EXIST(vehs[1].car))
			{
				if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car))
				{
					SET_SENSE_RANGE(peds[0].actor, 100);
					SET_SENSE_RANGE(peds[1].actor, 100);
					SET_SENSE_RANGE(peds[2].actor, 100);
					SET_SENSE_RANGE(peds[3].actor, 100);				
					objrc++;
				}
			}
		}
		
		if(objrc == 3)
		{
			if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car) && CHECK_WANTED_LEVEL() == 0 || !IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car) && CHECK_WANTED_LEVEL() == 0)
			{
				GOTO_LOCATION_WITH_VEHICLE(1, 0, -1477.68, 1125.49, 20.0449, "Deliver the ~b~car~S~ to the ~Y~dealership~S~", "Repo the ~b~Rebla~S~");	
			}
			
			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -354.432, 1403.02, 12.4, 130.00000000, 130.00000000, 130.00000000, 0) && !DOES_VEHICLE_EXIST(vehs[2].car) && vehs[2].retc != 2)
			{
				SPAWN_VEHICLE(2, MODEL_LANDSTALKER, NOBLIP, -354.432, 1403.02, 12.4, 0.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(4, 2, 10, MODEL_M_Y_GAFR_HI_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(5, 2, 0,  MODEL_M_Y_GAFR_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(4, 2);
			}
			
			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -872.364, 1163.52, 18.0094, 130.00000000, 130.00000000, 130.00000000, 0) && !DOES_VEHICLE_EXIST(vehs[3].car) && vehs[3].retc != 2)
			{
				SPAWN_VEHICLE(3, MODEL_LANDSTALKER, NOBLIP, -872.364, 1163.52, 18.0094, 270.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(6, 3, 10, MODEL_M_Y_GAFR_HI_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(7, 3, 0,  MODEL_M_Y_GAFR_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(6, 3);
			}
			
			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -1412.22, 1255.99, 23.9687, 80.00000000, 80.00000000, 80.0000000, 0) && !DOES_VEHICLE_EXIST(vehs[4].car) && vehs[4].retc != 2)
			{
				SPAWN_VEHICLE(4, MODEL_LANDSTALKER, NOBLIP, -1412.22, 1255.99, 23.9687, 221.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(8, 4, 10, MODEL_M_Y_GAFR_HI_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(9, 4, 0,  MODEL_M_Y_GAFR_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(8, 4);
			}				
		}
		
		if(objrc == objend)
		{
			MISSION_COMPLETE("", 10000);
		}
	}
}