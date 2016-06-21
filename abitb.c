// GTA V Online Mission for IV
// Mission: A boat in the bay
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   4
int i;
float zg;
Object boxcrate1, boxcrate2;

void main(void)
{
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	CLEAR_ZONE(1515.05, 976.519, 13.9896, 300.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	SET_PARKED_CAR_DENSITY_MULTIPLIER(0.0);
	SET_CAR_DENSITY_MULTIPLIER(0.1);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);
	INIT_SETTINGS(1515.05, 976.519, 13.9896, 358.0);
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
			PRINT_MAIN_LOGO(0.41, 0.05, "A boat in the bay");
			PRINT_DESC(0.34, 0.11, "Recreation of GTA V Online mission \"A boat in the bay\"");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			MANAGE_PLAYER();
			POLICE(0, 0);
			MANAGE_VEHICLES(1);
			MANAGE_ACTORS(20);
			MANAGE_UNIQUE_VEHICLE_STATUS(1);
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE,    1514.7,    981.11,  13.9245,  270.0, 25000, 0);
			SPAWN_VEHICLE(1, MODEL_JETMAX, BLIP_COLOR_CYAN, 1596.59,  1123.46, -0.538461, 355.0,  2000, 0);
			SPAWN_ACTOR(0, MODEL_M_Y_GLAT_LO_01,  WEAPON_MP5, BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1607.19,  1109.9,  1.23748, 180.0, 0);
			SPAWN_ACTOR(1, MODEL_M_Y_GLAT_LO_02,  WEAPON_M4,  BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1612.53,  1108.5,  1.17813, 180.0, 0);
			SPAWN_ACTOR(2, MODEL_M_Y_GLAT_HI_01,  WEAPON_MP5, BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1609.52,  1101.57, 2.44235, 180.0, 0);
			SPAWN_ACTOR(3, MODEL_M_Y_GLAT_HI_02,  WEAPON_M4,  BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1601.24,  1100.91, 2.78421, 180.0, 0);
			SPAWN_ACTOR(4, MODEL_M_Y_GLAT_LO_01,  WEAPON_MP5, BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1590.71,  1106.25, 3.11711, 180.0, 0);
			SPAWN_ACTOR(5, MODEL_M_Y_GLAT_LO_02,  WEAPON_M4,  BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1592.66,  1114.2,  1.38435, 180.0, 0);
			SPAWN_ACTOR(6, MODEL_M_Y_GLAT_HI_01,  WEAPON_MP5, BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1584.97,  1110.88, 1.30062, 180.0, 0);
			SPAWN_ACTOR(7, MODEL_M_Y_GLAT_HI_02,  WEAPON_M4,  BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1605.5,   1092.29, 3.61118, 180.0, 0);
			SPAWN_ACTOR(8, MODEL_M_Y_GLAT_LO_01,  WEAPON_MP5, BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1611.26,  1104.88, 1.68505, 180.0, 0);
			SPAWN_ACTOR(9, MODEL_M_Y_GLAT_LO_02,  WEAPON_M4,  BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1617.13,  1108.1,  1.13466, 180.0, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_GLAT_HI_01, WEAPON_MP5, BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1616.69,  1100.48, 2.27609, 180.0, 0);
			SPAWN_ACTOR(11, MODEL_M_Y_GLAT_HI_02, WEAPON_M4,  BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1574.26,  1094.53, 1.56449, 180.0, 0);
			SPAWN_ACTOR(12, MODEL_M_Y_GLAT_HI_02, WEAPON_M4,  BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, 1608.32,  1104.61, 1.9201 , 180.0, 0);
			GET_GROUND_Z_FOR_3D_COORD(1614.23,  1103.03, 1.92772, &zg);
			CREATE_OBJECT(MODEL_CJ_IND_CRATE_2, 1614.23,  1103.03, zg, &boxcrate1, 1);
			GET_GROUND_Z_FOR_3D_COORD(1606.9,   1090.62, 3.83613, &zg);
			CREATE_OBJECT(MODEL_CJ_IND_CRATE_2, 1606.9,   1090.62, 3.83613, &boxcrate2, 1);
			PLAY_CHECKPOINT_SOUND();
			objrc++;			
		}
		
		if(objrc == 2)
		{
			PRINT_TXT("Steal the ~b~boat~S~");
			
			if(DOES_VEHICLE_EXIST(vehs[1].car))
			{
				if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car))
				{	
					PLAY_CHECKPOINT_SOUND();
					objrc++;
				}
			}
		}
		
		if(objrc == 3)
		{
			if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car) || !IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car))
			{
				GOTO_LOCATION_WITH_VEHICLE(1, 0, -1141.72, 1888.54, 0.284137, "Deliver the ~b~boat~S~ to the ~Y~rendezvous~S~", "Steal the ~b~boat~S~");	
			}
			
			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 752.115, 1149.62, -1.12384, 130.00000000, 130.00000000, 130.00000000, 0) && !DOES_VEHICLE_EXIST(vehs[2].car) && vehs[2].retc != 2)
			{
				SPAWN_VEHICLE(2, MODEL_JETMAX, NOBLIP, 752.115, 1149.62, -1.12384, 300.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(13, 2, 10, MODEL_M_Y_GLAT_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(14, 2, 0,  MODEL_M_Y_GLAT_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(13, 2);
			}
			
			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 747.74,  1164.84, -0.957116, 130.00000000, 130.00000000, 130.00000000, 0) && !DOES_VEHICLE_EXIST(vehs[3].car) && vehs[3].retc != 2)
			{
				SPAWN_VEHICLE(3, MODEL_JETMAX, NOBLIP, 747.74,  1164.84, -0.957116, 300.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(15, 3, 10, MODEL_M_Y_GLAT_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(16, 3, 0,  MODEL_M_Y_GLAT_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(15, 3);
			}
			
			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 81.1985, 1593.88, -0.795539, 80.00000000, 80.00000000, 80.0000000, 0) && !DOES_VEHICLE_EXIST(vehs[4].car) && vehs[4].retc != 2)
			{
				SPAWN_VEHICLE(4, MODEL_JETMAX, NOBLIP, 81.1985, 1593.88, -0.795539, 180.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(17, 4, 10, MODEL_M_Y_GLAT_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(18, 4, 0,  MODEL_M_Y_GLAT_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(17, 4);
			}		

			if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 99.7643, 1611.66, -0.587167, 80.00000000, 80.00000000, 80.0000000, 0) && !DOES_VEHICLE_EXIST(vehs[5].car) && vehs[5].retc != 2)
			{
				SPAWN_VEHICLE(5, MODEL_JETMAX, NOBLIP, 99.7643, 1611.66, -0.587167, 180.0, vhealth, 1);
				SPAWN_ACTOR_INSIDE_CAR(19, 5, 10, MODEL_M_Y_GLAT_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				SPAWN_ACTOR_INSIDE_CAR(20, 5, 0,  MODEL_M_Y_GLAT_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
				GO_AFTER_PLAYER_WITH_VEHICLE(19, 5);
			}	
		}
		
		if(objrc == objend)
		{
			MISSION_COMPLETE("", 15000);
		}
	}
}