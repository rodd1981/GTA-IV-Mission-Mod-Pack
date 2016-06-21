// GTA V Online Mission for IV
// Mission: Rooftop Rumble
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   5
int i;

void main(void)
{
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	CLEAR_ZONE(310.001, 1184.58, 14.7722, 200.0);
	INIT_SETTINGS(-310.001, 1184.58, 14.7722, 180.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	SET_PARKED_CAR_DENSITY_MULTIPLIER(0.5);
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
			PRINT_MAIN_LOGO(0.42, 0.05, "Death Penalty");
			PRINT_DESC(0.17, 0.11, "A kingpin from LC has found out that Riley was cheating on him for several months. Now,  she's ");
			PRINT_DESC(0.17, 0.13, "sentenced to death penalty and is about to be killed pretty soon! This cannot happen my friend!");
			PRINT_DESC(0.17, 0.15, "Riley is a famous porn star and our company's revenue went to billions since she started working");	
			PRINT_DESC(0.17, 0.17, "with us! Take out all the mobsters on your way and bring back my sweet Riley!");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			POLICE(0, 0);
			MANAGE_PLAYER();
			GET_CHAR_COORDINATES(GetPlayerPed(), &px, &py, &pz);
			MANAGE_ACTORS(15);
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel,  BLIP_COLOR_WHITE, -309.289, 1178.17, 14.6767, 90.0, 25000, 0);
			SPAWN_ACTOR(0,   MODEL_IG_GRACIE, WEAPON_UNARMED,  BLIP_COLOR_CYAN,  0, 100,  50,  0, -236.962, 1089.72, 6.17311, 70.0, 1);
			SET_CHAR_NEVER_TARGETTED(peds[0].actor, TRUE);
			SPAWN_ACTOR(1,   MODEL_M_Y_GMAF_HI_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -237.755, 1095.35, 6.03428, 250.0, 0);
			SPAWN_ACTOR(2,   MODEL_M_Y_GMAF_HI_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -239.506, 1095.34, 6.12573, 250.0, 0);
			SPAWN_ACTOR(3,   MODEL_M_Y_GMAF_LO_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -241.298, 1095.38, 6.22434, 250.0, 0);
			SPAWN_ACTOR(4,   MODEL_M_Y_GMAF_LO_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -242.418, 1094.35, 6.28225, 250.0, 0);
			SPAWN_ACTOR(5,   MODEL_M_Y_GMAF_HI_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -243.37,  1092.84, 6.32927, 250.0, 0);
			SPAWN_ACTOR(6,   MODEL_M_Y_GMAF_HI_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -244.034, 1090.44, 6.50516, 250.0, 0);
			SPAWN_ACTOR(7,   MODEL_M_Y_GMAF_LO_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -244.214, 1088,    6.73398, 250.0, 0);
			SPAWN_ACTOR(8,   MODEL_M_Y_GMAF_LO_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -243.883, 1086.47, 6.56978, 250.0, 0);
			SPAWN_ACTOR(9,   MODEL_M_Y_GMAF_HI_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -232.903, 1092.67, 5.52235, 250.0, 0);
			SPAWN_ACTOR(10,  MODEL_M_Y_GMAF_HI_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -244.536, 1084.99, 6.44042, 250.0, 0);
			SPAWN_ACTOR(11,  MODEL_M_Y_GMAF_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 10, -240.914, 1082.5,   6.3339, 250.0, 0);
			TASK_AIM_GUN_AT_CHAR(peds[1].actor, peds[0].actor,  999999);
			TASK_AIM_GUN_AT_CHAR(peds[2].actor, peds[0].actor,  999999);
			TASK_AIM_GUN_AT_CHAR(peds[3].actor, peds[0].actor,  999999);
			TASK_AIM_GUN_AT_CHAR(peds[4].actor, peds[0].actor,  999999);
			TASK_AIM_GUN_AT_CHAR(peds[5].actor, peds[0].actor,  999999);
			TASK_AIM_GUN_AT_CHAR(peds[6].actor, peds[0].actor,  999999);
			TASK_AIM_GUN_AT_CHAR(peds[7].actor, peds[0].actor,  999999);
			TASK_AIM_GUN_AT_CHAR(peds[8].actor, peds[0].actor,  999999);
			TASK_AIM_GUN_AT_CHAR(peds[9].actor, peds[0].actor,  999999);
			TASK_HANDS_UP(peds[0].actor, 999999);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
		
		if(objrc == 2)
		{
			PRINT_TXT("Rescue ~b~Riley~s~");

			if(peds[0].retc == 2)
			{
				MISSION_FAILED("Riley was killed!");
			}
			
			if(DOES_CHAR_EXIST(peds[0].actor))
			{
				for(i=1;i<=11;i++)
				{
					if(DOES_CHAR_EXIST(peds[i].actor))
					{
						if(IS_PED_IN_COMBAT(peds[i].actor))
						{
							PANIC_SCREAM(peds[0].actor);
							TASK_COWER(peds[0].actor);
						}
					}
				}
			}
			
			if(peds[1].retc == 2 && peds[2].retc == 2 && peds[3].retc == 2 && peds[4].retc == 2 && peds[5].retc == 2 && peds[6].retc == 2 && peds[7].retc == 2 && peds[8].retc == 2 && peds[9].retc == 2 && peds[10].retc == 2 && peds[11].retc == 2)
			{
				SET_VICTIM_GROUP_FOR_PED(peds[0].actor);
				SET_CHAR_ONLY_DAMAGED_BY_PLAYER(peds[0].actor, TRUE);
				TASK_ENTER_CAR_AS_PASSENGER(peds[0].actor, vehs[0].car, -1, 0);
				objrc++;
			}	
		}
		
		if(objrc == 3)
		{
			SET_MISSION_CHECKPOINT(0, -1267.6,  1453.47, 20.6959, 2.0, "Take ~b~Riley~s~ back to her ~Y~house~S~");
			
			if(peds[0].retc == 2)
			{
				MISSION_FAILED("Riley was killed!");
			}
			
			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -456.865, 1202.6,  13.7573, 90.00000000, 90.00000000, 90.00000000, 0) && !DOES_VEHICLE_EXIST(vehs[1].car) && vehs[1].retc != 2)
			{
				SPAWN_VEHICLE(1, MODEL_HUNTLEY, NOBLIP, -456.865, 1202.6,  13.7573, 182.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(12, 1, 10, MODEL_M_Y_GMAF_HI_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(13, 1, 0,  MODEL_M_Y_GMAF_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(12, 1);
			}
			
			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -450.355, 1134.69, 11.957, 90.00000000, 90.00000000, 90.00000000, 0) && !DOES_VEHICLE_EXIST(vehs[2].car) && vehs[2].retc != 2)
			{
				SPAWN_VEHICLE(2, MODEL_HUNTLEY, NOBLIP, -450.355, 1134.69, 11.957,  359.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(14, 2, 10, MODEL_M_Y_GMAF_HI_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(15, 2, 0,  MODEL_M_Y_GMAF_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(14, 2);
			}			
		}
		
		if(objrc == 4)
		{
			if(peds[0].retc == 2)
			{
				MISSION_FAILED("Riley was killed!");
			}
			
			if(IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
			{
				GET_CAR_CHAR_IS_USING(GetPlayerPed(), &randomveh);
				STOP_CAR_BREAKING(randomveh, 1);
				TASK_LEAVE_ANY_CAR(GetPlayerPed());
			}
			
			if(IS_CHAR_IN_ANY_CAR(peds[0].actor))
			{
				TASK_LEAVE_ANY_CAR(peds[0].actor);
			}
			
			TASK_LEAVE_GROUP(peds[0].actor);
			SAY_AMBIENT_SPEECH(peds[0].actor, "THANKS", 1, 0, 0);
			TASK_WANDER_STANDARD(peds[0].actor);
			REMOVE_BLIP(peds[0].pblip);
			objrc++;
		}
		
		if(objrc == 5)
		{
			MISSION_COMPLETE("", 20000);
		}
	}
}