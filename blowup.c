// GTA V Online Mission for IV
// Mission: Blow Up
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   6

void main(void)
{
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	INIT_SETTINGS(-935.6, 1303.53, 24.5299, 96.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	CLEAR_ZONE(-941.134, 1302.45, 24.3726, 200.0);
	//SET_PARKED_CAR_DENSITY_MULTIPLIER(0.0);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);
	DISABLE_CAR_GENERATORS(1, 1);
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
			PRINT_MAIN_LOGO(0.45, 0.05, "Blow Up");
			PRINT_DESC(0.38, 0.11, "Recreation of GTA V Online mission \"Blow up\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}	
		
		if(objrc > objstart && objrc != objend)
		{
			POLICE(1, 3);
			MANAGE_PLAYER();
			MANAGE_VEHICLES(8);
			PRINT_LIVES();
			LOCK_TIME_OF_DAY();
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, -941.134, 1302.45, 24.37268, 0.0, 25000, 0);
			CLEAR_ZONE(-1070.14, 1462.64, 24.7918, 80.0);
			SPAWN_VEHICLE(1,    MODEL_COQUETTE, NOBLIP, -1084.07, 1463.48, 24.7918, 180.0, vhealth, 1);
			SPAWN_VEHICLE(2,     MODEL_BANSHEE, NOBLIP, -1078.54, 1464.4,  24.7918, 180.0, vhealth, 1); 
			SPAWN_VEHICLE(3,    MODEL_INFERNUS, NOBLIP, -1087.6,  1469.24, 24.7918, 180.0, vhealth, 1);
			SPAWN_VEHICLE(4,       MODEL_REBLA, NOBLIP, -1081.16, 1470.26, 24.7918, 180.0, vhealth, 1);
			SPAWN_VEHICLE(5, MODEL_LANDSTALKER, NOBLIP, -1076.21, 1470.02, 24.7918, 180.0, vhealth, 1);
			SPAWN_VEHICLE(6,       MODEL_PRIMO, NOBLIP, -1067.43, 1469.74, 24.7918, 180.0, vhealth, 1);
			SPAWN_VEHICLE(7,       MODEL_SABRE, NOBLIP, -1071.32, 1470.01, 24.7918, 180.0, vhealth, 1);
			SPAWN_VEHICLE(8,       MODEL_COMET, NOBLIP, -1074.82, 1464.59, 24.7918, 180.0, vhealth, 1);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
		
		if(objrc == 2)
		{
			SET_MISSION_CHECKPOINT(0, -1066.07, 1457.14, 22.5199, 3.0, "Go to the ~Y~rival dealership~S~");

			if(CHECK_WANTED_LEVEL() == 1)
			{
				PRINT_TXT("Lose the cops");
			}
		}
		
		if(objrc == 3)
		{
			ADD_CAR_BLIP(1, BLIP_COLOR_RED);
			ADD_CAR_BLIP(2, BLIP_COLOR_RED);
			ADD_CAR_BLIP(3, BLIP_COLOR_RED);
			ADD_CAR_BLIP(4, BLIP_COLOR_RED);
			ADD_CAR_BLIP(5, BLIP_COLOR_RED);
			ADD_CAR_BLIP(6, BLIP_COLOR_RED);
			ADD_CAR_BLIP(7, BLIP_COLOR_RED);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
		
		if(objrc == 4)
		{
			PRINT_TXT("Destroy the ~R~cars~S~");
			
			if(vehs[1].retc == 2 || vehs[2].retc == 2 || vehs[3].retc == 2 || vehs[4].retc == 2 || vehs[5].retc == 2 || vehs[6].retc == 2 || vehs[7].retc == 2 || vehs[8].retc == 2)
			{
				PLAY_SOUND_FROM_POSITION(-1, "SHOP_ALARMS_RANDOM", -1078.5, 1469.5, 24.7918);
			}
			
			if(vehs[1].retc == 2 && vehs[2].retc == 2 && vehs[3].retc == 2 && vehs[4].retc == 2 && vehs[5].retc == 2 && vehs[6].retc == 2 && vehs[7].retc == 2 && vehs[8].retc == 2)
			{
				ALTER_WANTED_LEVEL(GetPlayerIndex(), 3);
				APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
				objrc++;
				PLAY_CHECKPOINT_SOUND();
			}
		}
		
		if(objrc == 5)
		{	
			if(CHECK_WANTED_LEVEL() == 1)
			{
				PRINT_TXT("Lose the cops");
			}
	
			DISABLE_CAR_GENERATORS(0, 0);
			SET_MISSION_CHECKPOINT(0, -1477.68, 1125.49, 20.0449, 5.0, "Go to the ~Y~dealership~S~");
		}
		
		if(objrc == objend)
		{	
			MISSION_COMPLETE("", 10000);
		}
	}
}