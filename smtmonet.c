// GTA V Online Mission for IV
// Mission: Show me the Monet
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   3
int drvstyle = 0;

void main(void)
{
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	CLEAR_ZONE(-1214.81, 1644.22,  34.2615, 200.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	INIT_SETTINGS(-1214.81, 1644.22,  34.2615, 180.0);
	SET_PARKED_CAR_DENSITY_MULTIPLIER(0.0);
	SET_CAR_DENSITY_MULTIPLIER(0.1);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);
	
	while (TRUE)
    {
		WAIT(0);
		GET_CHAR_COORDINATES(GetPlayerPed(), &px, &py, &pz);
		GET_CHAR_HEADING(GetPlayerPed(), &ph);
		
		if (objrc == 0) 
		{
			DRAW_MENU();
			PRINT_MAIN_LOGO(0.38, 0.05, "Show me the monet");
			PRINT_DESC(0.33, 0.11, "Recreation of GTA V Online mission \"Show me the monet\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}	
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			POLICE(0, 0);
			MANAGE_PLAYER();
			MANAGE_ACTORS(16);
			MANAGE_VEHICLES(8);
			MANAGE_UNIQUE_VEHICLE_STATUS(1);
			LOCK_TIME_OF_DAY();
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, -1215.19, 1639.03, 34.2613, 270.0, 25000, 0);
			CLEAR_ZONE(-1374.26, 1293.41,  22.0688, 200.0);
			SPAWN_VEHICLE(1, MODEL_SPEEDO, BLIP_COLOR_CYAN, -1374.26, 1293.41,  22.0688, 129.57, 10000, 0);
			SPAWN_ACTOR_INSIDE_CAR(0, 1, 10, MODEL_M_M_GUNNUT_01,  WEAPON_MP5,  NOBLIP, accuracy, ehealth, armour, 0, 0);
			SPAWN_ACTOR_INSIDE_CAR(1, 1, 0,  MODEL_M_M_GUNNUT_01,  WEAPON_MP5,  NOBLIP, accuracy, ehealth, armour, 0, 0);
			SET_CHAR_RELATIONSHIP_GROUP(peds[0].actor, 25);
			SET_CHAR_WILL_DO_DRIVEBYS(peds[0].actor, FALSE);
			DRIVE_TO_LOCATION_WITH_VEHICLE(0, 1, -1812.17, -633.983, 2.8858, 15.0);
			PLAY_CHECKPOINT_SOUND();
			objrc++;			
		}
		
		if(objrc == 2)
		{
			GOTO_LOCATION_WITH_VEHICLE(1, 0, 353.595,  -218.003, 2.53322, "Deliver the ~b~van~S~ to the ~Y~Madrazo's lockup~S~", "Steal the ~b~van~S~");
			
			if(DOES_VEHICLE_EXIST(vehs[1].car))
			{
				if(HAS_CAR_BEEN_DAMAGED_BY_CHAR(vehs[1].car, GetPlayerPed()) && drvstyle == 0 || IS_CAR_TOUCHING_CAR(vehs[0].car, vehs[1].car) && drvstyle == 0 || IS_CHAR_TOUCHING_VEHICLE(GetPlayerPed(), vehs[1].car) && drvstyle == 0)
				{
					if(DOES_CHAR_EXIST(peds[0].actor))
					{
						if(level == 0)
						{				
							SET_CHAR_WILL_DO_DRIVEBYS(peds[0].actor, FALSE);
							SET_SENSE_RANGE(peds[1].actor, 100);
							DRIVE_TO_LOCATION_WITH_VEHICLE(0, 1, -1812.17, -633.983, 2.8858, 30.0);
							drvstyle = 1;
						}
						
						else if(level == 1 || level == 2)
						{
							SET_CHAR_WILL_DO_DRIVEBYS(peds[0].actor, FALSE);
							SET_SENSE_RANGE(peds[1].actor, 100);
							DRIVE_TO_LOCATION_WITH_VEHICLE(0, 1, -1812.17, -633.983, 2.8858, 40.0);
							drvstyle = 1;
						}
					}
				}
			}
		}
		
		if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car))
		{	
			SPAWN_ENEMY_CAR_IN_AREA(MODEL_PATRIOT, -982.786, 774.217,  4.25072, 2, 2, 3, MODEL_M_M_GUNNUT_01);
			SPAWN_ENEMY_CAR_IN_AREA(MODEL_PATRIOT, -982.786, 774.217,  4.25072, 3, 3, 4, MODEL_M_M_GUNNUT_01);
			SPAWN_ENEMY_CAR_IN_AREA(MODEL_PATRIOT, -176.43,  146.567,  14.8169, 4, 5, 6, MODEL_M_M_GUNNUT_01);
			SPAWN_ENEMY_CAR_IN_AREA(MODEL_PATRIOT, -176.43,  146.567,  14.8169, 5, 7, 8, MODEL_M_M_GUNNUT_01);
			SPAWN_ENEMY_CAR_IN_AREA(MODEL_PATRIOT, 58.2459, -310.795,  14.8176, 6, 9,10, MODEL_M_M_GUNNUT_01);	
			SPAWN_ENEMY_CAR_IN_AREA(MODEL_PATRIOT, 58.2459, -310.795,  14.8176, 7, 11,12,MODEL_M_M_GUNNUT_01);
		}
		
		
		if(DOES_CHAR_EXIST(peds[0].actor))
		{
			if(LOCATE_CHAR_ANY_MEANS_3D(peds[0].actor, -1812.17, -633.983, 2.8858, 5.0, 5.0, 5.0, 0))
			{
				if(IS_CHAR_IN_ANY_CAR(peds[0].actor))
				{
					STOP_CAR_BREAKING(vehs[1].car, 1);
					TASK_LEAVE_ANY_CAR(peds[0].actor);
					SET_CHAR_RELATIONSHIP_GROUP(peds[0].actor, 24);
					
					if(DOES_CHAR_EXIST(peds[1].actor) && IS_CHAR_IN_ANY_CAR(peds[1].actor))
					{
						TASK_LEAVE_ANY_CAR(peds[1].actor);
					}	
				}
			}
		}
		
		if(objrc == 3)
		{
			MISSION_COMPLETE("", 20000);
		}
	}
}