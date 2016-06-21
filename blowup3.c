// GTA V Online Mission for IV
// Mission: Blow Up 3
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
	CLEAR_ZONE(-1164.27, 672.434, 11.2206, 50.0);
	CLEAR_ZONE(748.906, -269.827, 5.82396, 50.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	SET_PED_NON_CREATION_AREA(-992.409, 262.955, 4.37742, -1031.3,  281.673, 4.37742);
	INIT_SETTINGS(-1169.78, 681.05, 11.6027, 181.0);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);
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
			PRINT_MAIN_LOGO(0.44, 0.05, "Blow Up 3");
			PRINT_DESC(0.37, 0.11, "Recreation of GTA V Online mission \"Blow up 3\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			POLICE(0, 0);
			ALTER_WANTED_LEVEL(GetPlayerIndex(), 0);
			MANAGE_PLAYER();
			MANAGE_ACTORS(15);
			MANAGE_VEHICLES(9);
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, -1164.27, 672.434, 11.2206, 181.0, 25000, 0);
			SPAWN_ACTOR(0, MODEL_M_M_BUSINESS_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 0, -992.409, 262.955, 4.37742, 0.0, 0);
			SPAWN_ACTOR(1, MODEL_M_M_BUSINESS_03, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, -1001.88, 258.918, 4.37742, 0.0, 0);
			SPAWN_ACTOR(2, MODEL_M_M_BUSINESS_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, -1016.38, 261.094, 4.3079,  0.0, 0);
			SPAWN_ACTOR(3, MODEL_M_M_BUSINESS_03, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 0, -1005.86, 278.581, 4.37742, 0.0, 0);
			SPAWN_ACTOR(4, MODEL_M_M_BUSINESS_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, -1008.72, 289.956, 4.37742, 0.0, 0);
			SPAWN_ACTOR(5, MODEL_M_M_BUSINESS_03, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 0, -1031.3,  281.673, 4.37742, 0.0, 0);
			SPAWN_VEHICLE(1,    MODEL_COQUETTE, BLIP_COLOR_RED, -1024.57, 265.359, 4.37742, 0.0, vhealth, 1);
			SPAWN_VEHICLE(2,       MODEL_COMET, BLIP_COLOR_RED, -1020.42, 265.424, 4.37742, 0.0, vhealth, 1);
			SPAWN_VEHICLE(3,    MODEL_INFERNUS, BLIP_COLOR_RED, -1016.06, 265.663, 4.37742, 0.0, vhealth, 1);
			SPAWN_VEHICLE(4,       MODEL_REBLA, BLIP_COLOR_RED, -1030.28, 278.582, 4.37741, 0.0, vhealth, 1);
			SPAWN_VEHICLE(5, MODEL_LANDSTALKER, BLIP_COLOR_RED, -1001.74, 266.064, 4.37742, 0.0, vhealth, 1);
			SPAWN_VEHICLE(6,      MODEL_PMP600, BLIP_COLOR_RED, -995.987, 266.296, 4.37741, 0.0, vhealth, 1);
			PLAY_CHECKPOINT_SOUND();
			objrc++;			
		}
		
		if(objrc == 2)
		{
			PRINT_TXT("Destroy the ~R~vehicles~S~");
			
			if(vehs[1].retc == 2 && vehs[2].retc == 2 && vehs[3].retc == 2 && vehs[4].retc == 2 && vehs[5].retc == 2 && vehs[6].retc == 2)
			{
				objrc++;
				PLAY_CHECKPOINT_SOUND();
			}
		}
		
		if(objrc == 3)
		{
			SET_MISSION_CHECKPOINT(0, -1477.68, 1125.49, 20.0449, 5.0, "Go to the ~Y~dealership~S~");
			
			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -1188.8, 377.399, 4.37792, 120.00000000, 120.00000000, 120.00000000, 0) && !DOES_VEHICLE_EXIST(vehs[7].car) && vehs[7].retc != 2)
			{
				SPAWN_VEHICLE(7, MODEL_LANDSTALKER, NOBLIP, -1188.8, 377.399, 4.37792, 270.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(4, 7, 10, MODEL_M_M_BUSINESS_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(5, 7, 0,  MODEL_M_M_BUSINESS_03, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(4, 7);
			}
			
			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -1244.09, 830.75, 19.5726, 100.00000000, 100.00000000, 100.00000000, 0) && !DOES_VEHICLE_EXIST(vehs[8].car) && vehs[8].retc != 2)
			{
				SPAWN_VEHICLE(8, MODEL_LANDSTALKER, NOBLIP, -1244.09, 830.75, 19.5726, 175.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(6, 8, 10, MODEL_M_M_BUSINESS_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(7, 8, 0,  MODEL_M_M_BUSINESS_03, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(6, 8);
			}
			
			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -1296.47, 1056.86, 19.5781, 100.00000000, 100.00000000, 100.00000000, 0) && !DOES_VEHICLE_EXIST(vehs[9].car) && vehs[9].retc != 2)
			{
				SPAWN_VEHICLE(9, MODEL_LANDSTALKER, NOBLIP, -1296.47, 1056.86, 19.5781, 183.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(8, 9, 10, MODEL_M_M_BUSINESS_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(9, 9, 0,  MODEL_M_M_BUSINESS_03, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(8, 9);
				OVERRIDE_NEXT_RESTART(-1296.47, 1056.86, 19.5781, 70.00);
			}
	
			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -1290.54, 1027.5, 19.3338, 100.00000000, 100.00000000, 100.00000000, 0) && !DOES_VEHICLE_EXIST(vehs[10].car) && vehs[10].retc != 2)
			{
				SPAWN_VEHICLE(10, MODEL_LANDSTALKER, NOBLIP, -1290.54, 1027.5,  19.3338, 0.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(10, 10, 10, MODEL_M_M_BUSINESS_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(11, 10, 0,  MODEL_M_M_BUSINESS_03, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(10, 10);
				OVERRIDE_NEXT_RESTART(-1290.54, 1027.5,  19.3338, 0.0);
			}	
		}
		
		if(objrc == 4)
		{
			MISSION_COMPLETE("", 10000);
		}
	}
}