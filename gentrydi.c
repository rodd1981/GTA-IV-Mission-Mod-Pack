// GTA V Online Mission for IV
// Mission: Gentry does it
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   4

int i;
int alarmrc[] = {0, 0};

void main(void)
{
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	CLEAR_ZONE(-1468.08, 1118.99, 22.9749, 100.0);
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
			PRINT_MAIN_LOGO(0.43, 0.05, "Gentry does it");
			PRINT_DESC(0.35, 0.11, "Recreation of GTA V Online mission \"Gentry does it\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			MANAGE_PLAYER();
			POLICE(1, 4);
			MANAGE_VEHICLES(2);
			MANAGE_UNIQUE_VEHICLE_STATUS(1);
			MANAGE_UNIQUE_VEHICLE_STATUS(2);
			MANAGE_ACTORS(1);
			CLEAR_AREA_OF_OBJECTS(-1489.64, 1426.23, 13.0549, 200.0);
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, -1468.08, 1118.99, 22.9749, 180.0, 25000, 0);
			SPAWN_VEHICLE(3, vehmodel, NOBLIP, -1472.13, 1123.65, 22.9585, 271.0, 30000, 0);
			SPAWN_VEHICLE(1, MODEL_COMET, BLIP_COLOR_CYAN, -1489.64, 1426.23, 13.0549, 178.0, 1000, 1);
			SPAWN_VEHICLE(2, MODEL_PRES,  BLIP_COLOR_CYAN, -1474.18, 1396.22, 13.0553, 90.0,  1000, 1);
			SPAWN_ACTOR(0,  MODEL_M_M_FATCOP_01,   WEAPON_MICRO_UZI, NOBLIP,  accuracy, ehealth, armour, 0, -1495.3, 1404.57,  13.1751,  0.0, 0);
			SPAWN_ACTOR(1,  MODEL_M_Y_COP_TRAFFIC, WEAPON_MICRO_UZI, NOBLIP,  accuracy, ehealth, armour, 0, -1478.55, 1399.55, 13.1751,  0.0, 0);
			SET_VEH_ALARM(vehs[1].car, TRUE);
			SET_VEH_ALARM(vehs[2].car, TRUE);
			FORCE_PED_PINNED_DOWN(peds[0].actor, TRUE, 9000);
			FORCE_PED_PINNED_DOWN(peds[1].actor, TRUE, 9000);
			PLAY_CHECKPOINT_SOUND();
			objrc++;			
		}
		
		if(objrc == 2 || objrc == 3)
		{
			if(CHECK_WANTED_LEVEL() == 1)
			{
				PRINT_TXT("Lose the cops");
			}
			
			if(DOES_VEHICLE_EXIST(vehs[1].car))
			{
				if(IS_CHAR_SITTING_IN_CAR(GetPlayerPed(), vehs[1].car))
				{
					if(alarmrc[0] == 0)
					{
						TRIGGER_VEH_ALARM(vehs[1].car);
						alarmrc[0] = 1;
					}
					
					for(i=0;i<=1;i++)
					{
						if(DOES_CHAR_EXIST(peds[i].actor))
						{
							if(peds[i].sense != 100)
							{
								ALTER_WANTED_LEVEL(GetPlayerIndex(), 2);
								SET_SENSE_RANGE(peds[i].actor, 100);
							}
						}
					}
				}
			}
			
			if(DOES_VEHICLE_EXIST(vehs[2].car))
			{
				if(IS_CHAR_SITTING_IN_CAR(GetPlayerPed(), vehs[2].car))
				{
					if(alarmrc[1] == 0)
					{
						TRIGGER_VEH_ALARM(vehs[2].car);
						alarmrc[1] = 1;
					}
					
					for(i=0;i<=1;i++)
					{
						if(DOES_CHAR_EXIST(peds[i].actor))
						{
							if(peds[i].sense != 100)
							{
								ALTER_WANTED_LEVEL(GetPlayerIndex(), 2);
								SET_SENSE_RANGE(peds[i].actor, 100);
							}
						}
					}
				}
			}
				
			if((!IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car) && CHECK_WANTED_LEVEL() == 0 || !IS_CHAR_IN_CAR(GetPlayerPed(), vehs[2].car)) && CHECK_WANTED_LEVEL() == 0)
			{
					PRINT_TXT("Steal the ~b~cars~s~");
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