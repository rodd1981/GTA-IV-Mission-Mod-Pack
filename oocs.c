// GTA V Online Mission for IV
// Mission: Out of court settlement
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   4
int drvstyle = 0;

void main(void)
{
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	CLEAR_ZONE(-318.825, 1602.5,  20.2807, 200.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	INIT_SETTINGS(-318.825, 1602.5,  20.2807, 177.0);
	SET_PARKED_CAR_DENSITY_MULTIPLIER(0.0);
	SET_CAR_DENSITY_MULTIPLIER(0.1);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);
	
	while (TRUE)
    {
		WAIT(0);
		GET_CHAR_COORDINATES(GetPlayerPed(), &px, &py, &pz);
		GET_CHAR_HEADING(GetPlayerPed(), &ph);
		
		if(objrc == 0) 
		{
			DRAW_MENU();
			PRINT_MAIN_LOGO(0.36, 0.05, "Out of court Settlement");
			PRINT_DESC(0.33, 0.11, "Recreation of GTA V Online mission \"Out of court settlement\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}	
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			POLICE(1, 3);
			MANAGE_PLAYER();
			MANAGE_ACTORS(1);
			MANAGE_VEHICLES(1);
			MANAGE_UNIQUE_VEHICLE_STATUS(1);
			LOCK_TIME_OF_DAY();
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, -314.868, 1595.63, 20.3283, 177.0, 25000, 0);
			CLEAR_ZONE(139.366,  1170.61, 14.7591, 200.0);
			SPAWN_VEHICLE(1, MODEL_BANSHEE, NOBLIP, 139.366,  1170.61, 14.7591, 89.00, 2000, 0);
			SPAWN_ACTOR_INSIDE_CAR(0, 1, 10, MODEL_M_M_BUSINESS_03,  WEAPON_PISTOL,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 0);
			peds[0].objhash = document;
			SET_CHAR_WILL_DO_DRIVEBYS(peds[0].actor, FALSE);
			DRIVE_TO_LOCATION_WITH_VEHICLE(0, 1, -928.247, 1329.25, 24.481, 10.0);
			PLAY_CHECKPOINT_SOUND();
			objrc++;			
		}
		
		if(objrc == 2)
		{
			MANAGE_PICKUP(0);
			
			if(peds[0].retc == 1)
			{
				PRINT_TXT("Take out the ~r~lawyer~s~");
			}
			
			if(peds[0].retc == 2)
			{
				PRINT_TXT("Get the ~b~evidence~s~");
			}
			
			if(peds[0].objretc == 2 && peds[0].retc == 2)
			{
				ALTER_WANTED_LEVEL(GetPlayerIndex(), 3);
				APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
				objrc++;
				PLAY_CHECKPOINT_SOUND();
			}
			
			if(DOES_VEHICLE_EXIST(vehs[1].car))
			{
				if(HAS_CAR_BEEN_DAMAGED_BY_CHAR(vehs[1].car, GetPlayerPed()) && drvstyle == 0 || IS_CAR_TOUCHING_CAR(vehs[0].car, vehs[1].car) && drvstyle == 0 || IS_CHAR_TOUCHING_VEHICLE(GetPlayerPed(), vehs[1].car) && drvstyle == 0)
				{
					if(DOES_CHAR_EXIST(peds[0].actor))
					{
						if(level == 0)
						{				
							SET_CHAR_WILL_DO_DRIVEBYS(peds[0].actor, FALSE);
							DRIVE_TO_LOCATION_WITH_VEHICLE(0, 1, -928.247, 1329.25, 24.481, 25.0);
							drvstyle = 1;
						}
						
						else if(level == 1 || level == 2)
						{
							SET_CHAR_WILL_DO_DRIVEBYS(peds[0].actor, FALSE);
							DRIVE_TO_LOCATION_WITH_VEHICLE(0, 1, -928.247, 1329.25, 24.481, 35.0);
							drvstyle = 1;
						}
					}
				}
			}
			
			if(DOES_CHAR_EXIST(peds[0].actor))
			{
				if(LOCATE_CHAR_ANY_MEANS_3D(peds[0].actor, -928.247, 1329.25, 24.481, 5.0, 5.0, 5.0, 0))
				{
					if(IS_CHAR_IN_ANY_CAR(peds[0].actor))
					{
						STOP_CAR_BREAKING(vehs[1].car, 1);
						TASK_LEAVE_ANY_CAR(peds[0].actor);
						TASK_USE_MOBILE_PHONE(peds[0].actor, TRUE);
						MISSION_FAILED("~S~Target arrived~S~");
					}
				}
			}
		}
		
		if(objrc == 3)
		{
			if(CHECK_WANTED_LEVEL() == 1)
			{
				PRINT_TXT("Lose the cops");
			}
			
			else if(CHECK_WANTED_LEVEL() == 0)
			{
				SET_MISSION_CHECKPOINT(0, -1216, 1641.51, 31.2611, 9.0, "Deliver the ~b~evidence~s~ to ~Y~Madrazo's house~S~");
			}
		}
		
		if(objrc == 4)
		{
			MISSION_COMPLETE("", 15000);
		}
	}
}