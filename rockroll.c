// GTA V Online Mission for IV
// Mission: Rockford Roll
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
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	CLEAR_ZONE(-1468.08, 1118.99, 22.9749, 50.0);
	SET_PARKED_CAR_DENSITY_MULTIPLIER(0.5);
	INIT_SETTINGS(-1474.77, 1118.16, 23.0135, 271.0);
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
			PRINT_MAIN_LOGO(0.42, 0.05, "Rockford Roll");
			PRINT_DESC(0.35, 0.11, "Recreation of GTA V Online mission \"Rockford Roll\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			MANAGE_PLAYER();
			POLICE(1, 3);
			MANAGE_VEHICLES(1);
			MANAGE_ACTORS(2);
			MANAGE_UNIQUE_VEHICLE_STATUS(1);
			CLEAR_AREA_OF_OBJECTS(-1477.68, 1125.49, 20.0449, 20.0);
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, -1468.08, 1118.99, 22.9749, 180.0, 25000, 0);
			SPAWN_VEHICLE(1, MODEL_INFERNUS, BLIP_COLOR_CYAN, -25.112, 1125.06, 15.4743, 347.0, vhealth, 0);
			SPAWN_VEHICLE(2, MODEL_PMP600, NOBLIP, -21.8411, 1093.56, 14.6532, 93.0, vhealth, 1);
			SPAWN_ACTOR(0,  MODEL_M_M_TENNIS,  WEAPON_UNARMED, NOBLIP, accuracy, ehealth, armour, 0, -22.4482, 1127.92, 16.0112, 91.0, 0);
			SPAWN_ACTOR_INSIDE_CAR(1, 2, 10, MODEL_M_M_BUSINESS_02, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 100, 0);
			SPAWN_ACTOR_INSIDE_CAR(2, 2, 0,  MODEL_M_M_BUSINESS_03, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 100, 0);
			TASK_MOBILE_CONVERSATION(peds[0].actor, 0);
			SET_CHAR_WANTED_BY_POLICE(peds[0].actor, FALSE);
			SET_CHAR_WANTED_BY_POLICE(peds[1].actor, FALSE);
			SET_CHAR_WANTED_BY_POLICE(peds[2].actor, FALSE);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
		
		if(objrc == 2)
		{
			if(DOES_VEHICLE_EXIST(vehs[1].car))
			{
				if((!IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car) && CHECK_WANTED_LEVEL() == 0))
				{
					PRINT_TXT("Retrieve the ~b~car~s~");
				}
			}
			
			if(DOES_VEHICLE_EXIST(vehs[1].car))
			{
				if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car))
				{
					ALTER_WANTED_LEVEL(GetPlayerIndex(), 3);
					APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
					SET_PED_IS_BLIND_RAGING(peds[0].actor, TRUE);
					SET_SENSE_RANGE(peds[0].actor, 100);
					TASK_COMBAT(peds[0].actor, GetPlayerPed());
					GO_AFTER_PLAYER_WITH_VEHICLE(1, 2);
					ADD_ACTOR_BLIP(1, BLIP_COLOR_RED);
					ADD_ACTOR_BLIP(2, BLIP_COLOR_RED);
					PLAY_CHECKPOINT_SOUND();
					objrc++;
				}
			}
		}
			
		if(objrc == 3)
		{
			if(CHECK_WANTED_LEVEL() == 1)
			{
				PRINT_TXT("Lose the cops");
			}
			
			if(CHECK_WANTED_LEVEL() == 0)
			{
				GOTO_LOCATION_WITH_VEHICLE(1, 2, -1477.68, 1125.49, 20.0449, "Deliver the ~b~car~S~ to the ~Y~dealership~S~", "Retrieve the ~b~car~S~");	
			}
		}		
		
		if(objrc == 4)
		{
			if(CHECK_WANTED_LEVEL() == 1)
			{
				PRINT_TXT("Lose the cops");
			}
			
			if(CHECK_WANTED_LEVEL() == 0)
			{
				STOP_CAR_BREAKING(vehs[1].car, 1);
				TASK_LEAVE_CAR(GetPlayerPed(), vehs[1].car);
				REMOVE_BLIP(vehs[1].vblip);
				LOCK_CAR_DOORS(vehs[1].car, 2);
				MISSION_COMPLETE("", 10000);
			}
		}
	}
}