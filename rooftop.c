// GTA V Online Mission for IV
// Mission: Rooftop Rumble
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   9

void main(void)
{
	int i, loc;
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	CLEAR_ZONE(-1028.73, 1417.01, 25.6895, 200.0);
	INIT_SETTINGS(-1186.5, 1375.04, 22.2372, 0.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	CLEAR_ZONE(-1187.55, 1380.63, 22.1364, 200.0);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);

	while (TRUE)
    {
		WAIT(0);
		GET_CHAR_COORDINATES(GetPlayerPed(), &px, &py, &pz);
		GET_CHAR_HEADING(GetPlayerPed(), &ph);
		
		if(objrc == 0)
		{
			DRAW_MENU();
			PRINT_MAIN_LOGO(0.41, 0.05, "Rooftop Rumble");
			PRINT_DESC(0.35, 0.11, "Recreation of GTA V Online mission \"Rooftop Rumble\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			POLICE(0, 0);
			MANAGE_PLAYER();
			MANAGE_ACTORS(21);
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, -1187.55, 1380.63, 22.1364, 270.0, 25000, 0);
			SPAWN_VEHICLE(1, MODEL_PMP600, NOBLIP,  -1028.73, 1417.01, 25.6895, 90.0,  vhealth, 1);
			SPAWN_VEHICLE(2, MODEL_PMP600, NOBLIP,  -1005.46, 1413.49, 25.6897, 359.0, vhealth, 1);
			SPAWN_VEHICLE(3, MODEL_PMP600, NOBLIP,  -1001.54, 1425.53, 25.6895, 180.0, vhealth, 1);
			SPAWN_VEHICLE(4, MODEL_PMP600, NOBLIP,  -1001.53, 1404.93, 25.6895, 359.0, vhealth, 1);
			SPAWN_ACTOR(0,  MODEL_M_M_BUSINESS_02, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 0, -1033.42, 1417.8,  25.4725, 90.0, 0);
			SPAWN_ACTOR(1,  MODEL_M_M_BUSINESS_03, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 0, -1009.69, 1423.15, 25.6895, 90.0, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_BUSINESS_01, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 0, -1008.05, 1420.8,  25.6895, 90.0, 0);
			SPAWN_ACTOR(3,  MODEL_M_Y_BUSINESS_02, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 0, -1009,    1417.83, 25.6895, 90.0, 0);
			SPAWN_ACTOR(4,  MODEL_M_M_BUSINESS_02, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 0, -1010.57, 1409.04, 25.6897, 90.0, 0);
			SPAWN_ACTOR(5,  MODEL_M_M_BUSINESS_03, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 0, -1009.44, 1404.61, 25.6895, 90.0, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_BUSINESS_01, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 0, -1000.76, 1411.69, 25.6897, 90.0, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_BUSINESS_02, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 0, -998.807, 1413.69, 25.6897, 90.0, 0);
			SPAWN_ACTOR(8,  MODEL_M_M_BUSINESS_03, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 0, -994.108, 1424.72, 25.6897, 90.0, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_BUSINESS_01, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 0, -991.946, 1422.94, 25.6897, 90.0, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_BUSINESS_02, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 0, -989.997, 1418.3,  25.6895, 90.0, 0);
			SPAWN_ACTOR(11, MODEL_F_Y_BUSINESS_01, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 0, -990.219, 1408.94, 25.6897, 90.0, 0);
			SPAWN_ACTOR(12, MODEL_M_M_BUSINESS_02, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 0, -1023.58, 1408.9,  25.6894, 90.0, 0);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
		
		if(objrc == 2)
		{
			SET_MISSION_CHECKPOINT(0, -1046.71, 1414.75, 21.2986, 9.0, "Go to the ~Y~parking lot~S~");
		}
		
		if(objrc == 3)
		{
			PRINT_TXT("Take out the ~R~Professionals~S~");
			
			if(peds[0].retc == 2 && peds[1].retc == 2 && peds[2].retc == 2 && peds[3].retc == 2 && peds[4].retc == 2 && peds[5].retc == 2 && peds[6].retc == 2 && peds[7].retc == 2 && peds[8].retc == 2 && peds[9].retc == 2 && peds[10].retc == 2 && peds[11].retc == 2 && peds[12].retc == 2)
			{
				objrc++;
			}	
		}
		
		if(objrc == 4)
		{
			PRINT_TXT("Take out the ~R~Professionals~S~");
			SPAWN_VEHICLE(5, MODEL_PMP600, NOBLIP,  -1114.76, 1443.61, 24.4437, 270.0, vhealth, 1);
			SPAWN_VEHICLE(6, MODEL_PMP600, NOBLIP,  -1049.09, 1340.22, 24.4041, 359.0, vhealth, 1);
			SPAWN_ACTOR_INSIDE_CAR(13, 5, 10, MODEL_M_M_BUSINESS_02, WEAPON_MP5,  BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
			SPAWN_ACTOR_INSIDE_CAR(14, 5, 0,  MODEL_M_M_BUSINESS_03, WEAPON_MP5,  BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
			SPAWN_ACTOR_INSIDE_CAR(15, 5, 1,  MODEL_M_Y_BUSINESS_01, WEAPON_MP5,  BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
			SPAWN_ACTOR_INSIDE_CAR(16, 5, 2,  MODEL_M_Y_BUSINESS_02, WEAPON_MP5,  BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
			SPAWN_ACTOR_INSIDE_CAR(17, 6, 10, MODEL_M_M_BUSINESS_02, WEAPON_MP5,  BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
			SPAWN_ACTOR_INSIDE_CAR(18, 6, 0,  MODEL_M_M_BUSINESS_03, WEAPON_MP5,  BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
			SPAWN_ACTOR_INSIDE_CAR(19, 6, 1,  MODEL_M_Y_BUSINESS_01, WEAPON_MP5,  BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
			SPAWN_ACTOR_INSIDE_CAR(20, 6, 2,  MODEL_M_Y_BUSINESS_02, WEAPON_MP5,  BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
			DRIVE_TO_LOCATION_WITH_VEHICLE(13, 5, -1046.71, 1414.75, 21.2986, 50.0);
			DRIVE_TO_LOCATION_WITH_VEHICLE(17, 6, -1046.71, 1414.75, 21.2986, 50.0);
			objrc++;
		}
		
		if(objrc == 5)
		{
			PRINT_TXT("Take out the ~R~Professionals~S~");
			
			for(i=13;i<=20;i++)
			{
				if(DOES_CHAR_EXIST(peds[i].actor))
				{
					if((LOCATE_CHAR_ANY_MEANS_3D(peds[i].actor, -1046.71, 1414.75, 21.2986, 10.0, 10.0, 10.0, 0)))
					{
						if(IS_CHAR_IN_ANY_CAR(peds[i].actor))
						{
							TASK_LEAVE_ANY_CAR(peds[i].actor);
						}
						
						if(!IS_PED_IN_COMBAT(peds[i].actor))
						{
							TASK_COMBAT(peds[i].actor, GetPlayerPed());
						}
					}
				}
			}

			if(peds[13].retc == 2 && peds[14].retc == 2 && peds[19].retc == 2 && peds[20].retc == 2)
			{
				objrc++;
			}
		}
			
		if(objrc == 6)
		{
			PRINT_TXT("Take out the ~R~Professionals~S~");
			
			GENERATE_RANDOM_INT_IN_RANGE(0, 2, &loc);
			
			if(loc == 0)
			{
				SPAWN_VEHICLE(7, MODEL_PMP600, NOBLIP, -1024.43, 1380.21, 24.4023, 270.0, vhealth, 1);
			}
			
			if(loc == 1)
			{
				SPAWN_VEHICLE(7, MODEL_PMP600, NOBLIP, -1055.74, 1358.32, 24.4236, 180.0, vhealth, 1);
			}
			
			if(loc == 2)
			{
				SPAWN_VEHICLE(7, MODEL_PMP600, NOBLIP, -1035.87, 1467.62, 24.426,  272.0, vhealth, 1);
			}
			
			SPAWN_ACTOR_INSIDE_CAR(21, 7, 10, MODEL_M_M_BUSINESS_03, WEAPON_MP5, BLIP_COLOR_CYAN, accuracy, ehealth, armour, 0, 0);
			SET_CHAR_WILL_DO_DRIVEBYS(peds[21].actor, FALSE);
			peds[21].objhash = document;
			
			if(level == 0 || level == 1)
			{
				DRIVE_TO_LOCATION_WITH_VEHICLE(21, 7, -1482.63, -41.492, 6.55484, 25.0);
			}
			
			if(level == 2)
			{
				DRIVE_TO_LOCATION_WITH_VEHICLE(21, 7, -1482.63, -41.492, 6.55484, 35.0);
			}
			
			SPAWN_VEHICLE(8, MODEL_PMP600, NOBLIP, -1488.84, -46.7436, 6.37691, 11.0, vhealth, 1);
			SPAWN_ACTOR(22,  MODEL_M_M_BUSINESS_03, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 90, -1488.93, -40.0033, 6.84433, 11.0, 0);
			SPAWN_ACTOR(23,  MODEL_M_Y_BUSINESS_01, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 90, -1494.2,  -44.9943, 6.86176, 11.0, 0);
			SPAWN_ACTOR(24,  MODEL_M_Y_BUSINESS_02, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 90, -1479.68, -47.4844, 6.32828, 11.0, 0);
			objrc++;
			PLAY_CHECKPOINT_SOUND();
		}
		
		if(objrc == 7)
		{
			MANAGE_PICKUP(21);
			
			if(DOES_CHAR_EXIST(peds[21].actor))
			{
				if(LOCATE_CHAR_ANY_MEANS_3D(peds[21].actor, -1482.63, -41.492, 6.55484, 5.0, 5.0, 5.0, 0))
				{
					if(IS_CHAR_IN_ANY_CAR(peds[21].actor))
					{
						STOP_CAR_BREAKING(vehs[7].car, 1);
						TASK_LEAVE_ANY_CAR(peds[21].actor);
					}
				}
			}
				
			if(peds[21].retc == 1)
			{
				PRINT_TXT("Steal the ~b~document~s~");		
			}
			
			if(peds[21].retc == 2)
			{
				PRINT_TXT("The ~b~document~s~ has been dropped. Steal it!");
			}
			
			if(peds[21].objretc == 2 && peds[21].retc == 2)
			{
				objrc++;
				PLAY_CHECKPOINT_SOUND();
			}
		}
	
		if(objrc == 8)
		{
			SET_MISSION_CHECKPOINT(0, -1216, 1641.51, 31.2611, 9.0, "Deliver the ~b~document~s~ to ~Y~Madrazo's house~S~");
		}
		
		if(objrc == 9)
		{
			MISSION_COMPLETE("", 20000);
		}
	}
}