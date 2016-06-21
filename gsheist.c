// GTA V Online Mission for IV
// Mission: Gruppe Sechs heists
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
	CLEAR_ZONE(-1294.52, 1270.78, 21.7427, 300.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	SET_PARKED_CAR_DENSITY_MULTIPLIER(0.0);
	SET_CAR_DENSITY_MULTIPLIER(0.1);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);
	INIT_SETTINGS(-1294.52, 1270.78, 21.7427, 308.0);
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
			PRINT_MAIN_LOGO(0.37, 0.05, "Gruppe Sechs Heists");
			PRINT_DESC(0.21, 0.11, "A homeless drug addict friend that lives near  Westdyke Hospital told me that Gruppe Sechs ");
			PRINT_DESC(0.21, 0.13, "will load tons of cash today into a security car. Of course, there will be a bunch of security ");
			PRINT_DESC(0.21, 0.15, "men to protect the greens. Steal the car and deliver it to my place (you'll be rewarded!)");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			MANAGE_PLAYER();
			POLICE(0, 0);
			MANAGE_VEHICLES(1);
			MANAGE_ACTORS(15);
			MANAGE_UNIQUE_VEHICLE_STATUS(1);
			SWITCH_POLICE_HELIS(FALSE);
			SET_PED_NON_CREATION_AREA(-1245.94, 1292.7, 20.6938, -1236.48, 1296.6,  21.7911);
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, -1293.65, 1279.79, 21.6688, 227.0, 25000, 0);
			SPAWN_VEHICLE(1, MODEL_STOCKADE, BLIP_COLOR_CYAN, -1245.94, 1292.7, 20.6938, 182.0, 30000, 0);
			SPAWN_ACTOR(0,   MODEL_M_M_ARMOURED, WEAPON_MP5, BLIP_COLOR_RED, 100, 100, 100, 10, -1236.48, 1296.6,  21.7911, 182.0, 0);
			SPAWN_ACTOR(1,   MODEL_M_M_ARMOURED, WEAPON_M4,  BLIP_COLOR_RED, 100, 100, 100, 10, -1234.44, 1291.81, 20.6937, 182.0, 0);
			SPAWN_ACTOR(2,   MODEL_M_M_ARMOURED, WEAPON_MP5, BLIP_COLOR_RED, 100, 100, 100, 10, -1238.7,  1286.51, 20.6932, 182.0, 0);
			SPAWN_ACTOR(3,   MODEL_M_M_ARMOURED, WEAPON_M4,  BLIP_COLOR_RED, 100, 100, 100, 10, -1242.61, 1289.4,  20.7169, 182.0, 0);
			SPAWN_ACTOR(4,   MODEL_M_M_ARMOURED, WEAPON_MP5, BLIP_COLOR_RED, 100, 100, 100, 10, -1247.32, 1284.47, 20.6932, 182.0, 0);
			SPAWN_ACTOR(5,   MODEL_M_M_ARMOURED, WEAPON_M4,  BLIP_COLOR_RED, 100, 100, 100, 10, -1250.28, 1290.92, 20.6932, 182.0, 0);
			SPAWN_ACTOR(6,   MODEL_M_M_ARMOURED, WEAPON_MP5, BLIP_COLOR_RED, 100, 100, 100, 10, -1256.65, 1293.55, 20.6946, 182.0, 0);
			SPAWN_ACTOR(7,   MODEL_M_M_ARMOURED, WEAPON_M4,  BLIP_COLOR_RED, 100, 100, 100, 10, -1251.81, 1296.36, 21.7804, 182.0, 0);
			SPAWN_ACTOR(8,   MODEL_M_M_ARMOURED, WEAPON_MP5, BLIP_COLOR_RED, 100, 100, 100, 10, -1249.05, 1297.15, 21.8163, 272.0, 0);
			SPAWN_ACTOR(9,   MODEL_M_M_ARMOURED, WEAPON_M4,  BLIP_COLOR_RED, 100, 100, 100, 10, -1243.3,  1296.98, 21.8003, 272.0, 0);
			SPAWN_ACTOR(10,  MODEL_M_M_ARMOURED, WEAPON_M4,  BLIP_COLOR_RED, 100, 100, 100, 10, -1234.61, 1295.81, 20.6944, 0.0,   0);
			SPAWN_ACTOR(11,  MODEL_M_M_ARMOURED, WEAPON_M4,  BLIP_COLOR_RED, 100, 100, 100, 10, -1229.62, 1296.35,  20.695, 0.0,   0);
			SPAWN_ACTOR(12,  MODEL_M_M_ARMOURED, WEAPON_M4,  BLIP_COLOR_RED, 100, 100, 100, 10, -1232.21, 1283.25, 20.9877, 0.0,   0);
			SPAWN_ACTOR(13,  MODEL_M_M_ARMOURED, WEAPON_M4,  BLIP_COLOR_RED, 100, 100, 100, 10, -1236.97, 1282.17, 21.2238, 0.0,   0);
			SPAWN_ACTOR(14,  MODEL_M_M_ARMOURED, WEAPON_M4,  BLIP_COLOR_RED, 100, 100, 100, 10, -1226.58, 1284.55, 20.6932, 0.0,   0);
			SPAWN_ACTOR(15,  MODEL_M_M_ARMOURED, WEAPON_M4,  BLIP_COLOR_RED, 100, 100, 100, 10, -1228,    1296.81, 22.1373, 0.0,   0);	
			FORCE_PED_PINNED_DOWN(peds[0].actor, TRUE, 999999);
			FORCE_PED_PINNED_DOWN(peds[1].actor, TRUE, 999999);
			FORCE_PED_PINNED_DOWN(peds[2].actor, TRUE, 999999);
			FORCE_PED_PINNED_DOWN(peds[3].actor, TRUE, 999999);
			PLAY_CHECKPOINT_SOUND();			
			objrc++;
		}
		
		if(objrc == 2)
		{
			PRINT_TXT("Clear out the ~R~guards~s~");
			
			if(peds[0].retc == 2 || peds[1].retc == 2 || peds[2].retc == 2 || peds[3].retc == 2 || peds[4].retc == 2 || peds[5].retc == 2 || peds[6].retc == 2 || peds[7].retc == 2 || peds[8].retc == 2 || peds[9].retc == 2 || peds[10].retc == 2 || peds[11].retc == 2 || peds[12].retc == 2 || peds[13].retc == 2 || peds[14].retc == 2 || peds[15].retc == 2)
			{
				PLAY_SOUND_FROM_POSITION(-1, "SHOP_ALARMS_RANDOM", -1236.48, 1296.6, 21.7911);
			}
			
			if(peds[0].retc == 2 && peds[1].retc == 2 && peds[2].retc == 2 && peds[3].retc == 2 && peds[4].retc == 2 && peds[5].retc == 2 && peds[6].retc == 2 && peds[7].retc == 2 && peds[8].retc == 2 && peds[9].retc == 2 && peds[10].retc == 2 && peds[11].retc == 2 && peds[12].retc == 2 && peds[13].retc == 2 && peds[14].retc == 2 && peds[15].retc == 2)
			{
				objrc++;
			}
		}

		if(objrc == 3)
		{
			PRINT_TXT("Steal the ~b~car~s~");
			
			if(DOES_VEHICLE_EXIST(vehs[1].car))
			{
				if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car))
				{
					SPAWN_VEHICLE(2, MODEL_HUNTLEY, NOBLIP, -1235.66, 1354.2,  21.96,   182.0, 100, 1);
					SPAWN_ACTOR_INSIDE_CAR(0, 2, 10, MODEL_M_M_ARMOURED, WEAPON_MP5,  BLIP_COLOR_RED, 100, 100, 100, 100, 0);
					SPAWN_ACTOR_INSIDE_CAR(1, 2, 0,  MODEL_M_M_ARMOURED, WEAPON_MP5,  NOBLIP, 100, 100, 100, 100, 0);
					SPAWN_ACTOR_INSIDE_CAR(2, 2, 1,  MODEL_M_M_ARMOURED, WEAPON_MP5,  NOBLIP, 100, 100, 100, 100, 0);
					SPAWN_ACTOR_INSIDE_CAR(3, 2, 2,  MODEL_M_M_ARMOURED, WEAPON_MP5,  NOBLIP, 100, 100, 100, 100, 0);
					SPAWN_VEHICLE(3, MODEL_HUNTLEY, NOBLIP, -1282.38, 1240.38, 21.6742, 300.0, 100, 1);
					SPAWN_ACTOR_INSIDE_CAR(4, 3, 10, MODEL_M_M_ARMOURED, WEAPON_MP5,  BLIP_COLOR_RED, 100, 100, 100, 100, 0);
					SPAWN_ACTOR_INSIDE_CAR(5, 3, 0,  MODEL_M_M_ARMOURED, WEAPON_MP5,  NOBLIP, 100, 100, 100, 100, 0);
					SPAWN_ACTOR_INSIDE_CAR(6, 3, 1,  MODEL_M_M_ARMOURED, WEAPON_MP5,  NOBLIP, 100, 100, 100, 100, 0);
					SPAWN_ACTOR_INSIDE_CAR(7, 3, 2,  MODEL_M_M_ARMOURED, WEAPON_MP5,  NOBLIP, 100, 100, 100, 100, 0);
					GO_AFTER_PLAYER_WITH_VEHICLE(0, 2);
					GO_AFTER_PLAYER_WITH_VEHICLE(4, 3);
					SPAWN_VEHICLE(4, MODEL_HUNTLEY, NOBLIP, -1376.98, 762.276, 19.5954, 89.0, 100, 1);
					SPAWN_VEHICLE(5, MODEL_HUNTLEY, NOBLIP, -1381.75, 762.232, 19.6874, 89.0, 100, 1);
					SPAWN_VEHICLE(6, MODEL_HUNTLEY, NOBLIP, -1387.19, 762.249, 19.6874, 89.0, 100, 1);
					SPAWN_VEHICLE(7, MODEL_HUNTLEY, NOBLIP, -1392.77, 762.291, 19.6824, 89.0, 100, 1);
					SPAWN_ACTOR(8,   MODEL_M_M_ARMOURED, WEAPON_RLAUNCHER, NOBLIP, 20, 100, 100, 50, -1369.74, 766.073, 19.5578, 45.0, 0);
					SPAWN_ACTOR(9,   MODEL_M_M_ARMOURED, WEAPON_MP5, NOBLIP, 50, 100, 100, 50, -1381.68, 767.844, 19.6891, 45.0, 0);
					SPAWN_ACTOR(10,   MODEL_M_M_ARMOURED, WEAPON_MP5, NOBLIP, 50, 100, 100, 50, -1383.28, 768.225, 19.6874, 45.0, 0);
					SPAWN_ACTOR(11,   MODEL_M_M_ARMOURED, WEAPON_MP5, NOBLIP, 50, 100, 100, 50, -1388.61, 768.262, 19.6874, 45.0, 0);
					SPAWN_ACTOR(12,   MODEL_M_M_ARMOURED, WEAPON_MP5, NOBLIP, 50, 100, 100, 50, -1394.53, 767.992, 19.6481, 45.0, 0);
					SPAWN_ACTOR(13,   MODEL_M_M_ARMOURED, WEAPON_MP5, NOBLIP, 50, 100, 100, 50, -1399.7,  768.776, 19.4433, 45.0, 0);
					SPAWN_ACTOR(14,   MODEL_M_M_ARMOURED, WEAPON_MP5, NOBLIP, 50, 100, 100, 50, -1404.18, 769.475, 19.4291, 45.0, 0);
					FORCE_PED_PINNED_DOWN(peds[8].actor, TRUE, 999999);
					for(i=8;i<=14;i++) REMOVE_BLIP(peds[i].pblip);
					PLAY_CHECKPOINT_SOUND();
					objrc++;
				}
			}
		}
		
		if(objrc == 4)
		{
			GOTO_LOCATION_WITH_VEHICLE(1, 0, -1669.66, -15.9458, 7.62874, "Deliver the ~b~car~S~ to the ~Y~rendezvous~S~", "Steal the ~b~car~S~");	
		}
		
		if(objrc == 5)
		{
			MISSION_COMPLETE("", 40000);
		}
	}
}