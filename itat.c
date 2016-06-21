// GTA V Online Mission for IV
// Mission: It Takes a Thief
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   4
int drvstyle[2] = {0, 0, 0};

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
			PRINT_MAIN_LOGO(0.42, 0.05, "It takes a thief");
			PRINT_DESC(0.35, 0.11, "Recreation of GTA V Online mission \"It takes a thief\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			MANAGE_PLAYER();
			POLICE(1, 3);
			MANAGE_VEHICLES(2);
			MANAGE_UNIQUE_VEHICLE_STATUS(1);
			MANAGE_UNIQUE_VEHICLE_STATUS(2);
			CLEAR_AREA_OF_OBJECTS(-1477.68, 1125.49, 20.0449, 20.0);
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel,  BLIP_COLOR_WHITE, -1468.08, 1118.99,  22.9749, 180.0, 25000, 0);
			SPAWN_VEHICLE(3, MODEL_PCJ, NOBLIP, -1472.13, 1123.65, 22.9585, 271.0,  30000, 0);
			SPAWN_VEHICLE(1,       MODEL_COMET, BLIP_COLOR_CYAN, -1493.39, 491.032, 19.0811, 90.0,  3000, 0);
			SPAWN_VEHICLE(2,    MODEL_COQUETTE, BLIP_COLOR_CYAN, -876.674, 1173.87, 17.5401, 177.0, 3000, 0);
			SPAWN_ACTOR_INSIDE_CAR(0, 1, 10, MODEL_M_Y_GALB_LO_03,  WEAPON_MP5,  NOBLIP, accuracy, ehealth, armour, 0, 0);
			SPAWN_ACTOR_INSIDE_CAR(1, 2, 10, MODEL_M_M_BUSINESS_02, WEAPON_MP5,  NOBLIP, accuracy, ehealth, armour, 0, 0);
			SET_CHAR_WILL_DO_DRIVEBYS(peds[0].actor, FALSE);
			SET_CHAR_WILL_DO_DRIVEBYS(peds[1].actor, FALSE);
			TASK_CAR_DRIVE_WANDER(peds[0].actor, vehs[1].car, 15.0, 2);
			TASK_CAR_DRIVE_WANDER(peds[1].actor, vehs[2].car, 15.0, 2);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
		
		if(objrc == 2 || objrc == 3)
		{
			if(CHECK_WANTED_LEVEL() == 1)
			{
				PRINT_TXT("Lose the cops");
			}
			
			if(DOES_VEHICLE_EXIST(vehs[1].car) || DOES_VEHICLE_EXIST(vehs[2].car))
			{
				if(HAS_CAR_BEEN_DAMAGED_BY_CHAR(vehs[1].car, GetPlayerPed()) && drvstyle[1] == 0 || HAS_CHAR_BEEN_DAMAGED_BY_CHAR(peds[0].actor, GetPlayerPed(), 0) && drvstyle[1] == 0)
				{
					if(DOES_CHAR_EXIST(peds[0].actor))
					{
						if(level == 0)
						{
							TASK_CAR_DRIVE_WANDER(peds[0].actor, vehs[1].car, 25.0, 3);
							drvstyle[1] = 1;
						}
						
						else if(level == 1)
						{
							TASK_CAR_DRIVE_WANDER(peds[0].actor, vehs[1].car, 30.0, 3);
							drvstyle[1] = 1;
						}
						
						else if(level == 2)
						{
							TASK_CAR_DRIVE_WANDER(peds[0].actor, vehs[1].car, 40.0, 3);
							drvstyle[1] = 1;
						}
						
					}
				}
				
				if(HAS_CAR_BEEN_DAMAGED_BY_CHAR(vehs[2].car, GetPlayerPed()) && drvstyle[2] == 0 || HAS_CHAR_BEEN_DAMAGED_BY_CHAR(peds[1].actor, GetPlayerPed(), 0) && drvstyle[2] == 0)
				{
					if(DOES_CHAR_EXIST(peds[1].actor))
					{
						if(level == 0)
						{
							TASK_CAR_DRIVE_WANDER(peds[1].actor, vehs[2].car, 25.0, 3);
							drvstyle[2] = 1;
						}
						
						else if(level == 1)
						{
							TASK_CAR_DRIVE_WANDER(peds[1].actor, vehs[2].car, 30.0, 3);
							drvstyle[2] = 1;							
						}
						
						else if(level == 1)
						{						
							TASK_CAR_DRIVE_WANDER(peds[1].actor, vehs[2].car, 40.0, 3);
							drvstyle[2] = 1;
						}
					}
				}
				
				if((!IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car) && CHECK_WANTED_LEVEL() == 0 || !IS_CHAR_IN_CAR(GetPlayerPed(), vehs[2].car)) && CHECK_WANTED_LEVEL() == 0)
				{
					PRINT_TXT("Retrieve the ~b~cars~s~");
				}
			}
			
			if(DOES_VEHICLE_EXIST(vehs[1].car))
			{
				if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car) && CHECK_WANTED_LEVEL() == 0 && vehs[1].retc != 3)
				{
					SET_MISSION_CHECKPOINT_CUSTOM(0, -1477.68, 1125.49, 20.0449, 3.0, "Deliver the ~b~car~s~ to the ~Y~dealership~S~");

					if(LOCATE_CAR_3D(vehs[1].car, -1477.68, 1125.49, 20.0449, 3.0, 3.0, 3.0, 0))
					{
						STOP_CAR_BREAKING(vehs[1].car, 1);
						TASK_LEAVE_CAR(GetPlayerPed(), vehs[1].car);
						REMOVE_BLIP(vehs[1].vblip);
						LOCK_CAR_DOORS(vehs[1].car, TRUE);
						vehs[1].retc = 3;
						objrc++;
					}
				}
			}

			if(DOES_VEHICLE_EXIST(vehs[2].car))
			{
				if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[2].car) && CHECK_WANTED_LEVEL() == 0 && vehs[2].retc != 3)
				{
					SET_MISSION_CHECKPOINT_CUSTOM(0, -1477.68, 1125.49, 20.0449, 3.0, "Deliver the ~b~car~s~ to the ~Y~dealership~S~");
					
					if(LOCATE_CAR_3D(vehs[2].car, -1477.68, 1125.49, 20.0449, 3.0, 3.0, 3.0, 0))
					{
						REMOVE_BLIP(vehs[2].vblip);
						STOP_CAR_BREAKING(vehs[2].car, 1);
						TASK_LEAVE_CAR(GetPlayerPed(), vehs[2].car);
						LOCK_CAR_DOORS(vehs[2].car, TRUE);
						vehs[2].retc = 3;
						objrc++;
					}
				}	
			}
		} 
			
		if(objrc == 4) 
		{
			if(CHECK_WANTED_LEVEL() == 0)
			{
				MISSION_COMPLETE("", 10000);
			}
		}
	}
}