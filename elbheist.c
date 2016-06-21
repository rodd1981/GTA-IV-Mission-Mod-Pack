// GTA V Online Mission for IV
// Mission: El Burro Heists
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   3
int i;

void main(void)
{
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	CLEAR_ZONE(-112.563, 1616.14, 20.19, 200.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	CLEAR_ZONE(-1164.27, 672.434, 11.2206, 200.0);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);
	INIT_SETTINGS(-1474.77, 1118.16, 23.0135, 271.0);
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
			PRINT_MAIN_LOGO(0.43, 0.05, "El Burro Heists");
			PRINT_DESC(0.35, 0.11, "Recreation of GTA V Online mission \"El Burro Heists\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			POLICE(0, 0);
			MANAGE_PLAYER();
			MANAGE_ACTORS(19);
			MANAGE_UNIQUE_VEHICLE_STATUS(1);
		}
		
		if(objrc == 1)
		{	
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel,  BLIP_COLOR_WHITE, -1468.08, 1118.99, 22.9749, 180.0, 25000, 0);
			SPAWN_VEHICLE(1, MODEL_SABREGT, BLIP_COLOR_CYAN, -112.563, 1616.14, 20.19, 44.0, 2000, 0);	
			CHANGE_CAR_COLOUR(vehs[1].car, 89, 89);			
			SPAWN_ACTOR(0,  MODEL_M_Y_GLAT_LO_01, WEAPON_DEAGLE,      BLIP_COLOR_RED,  accuracy, ehealth, armour, 10, -110.991, 1618.43, 20.0056,  44.0, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_GLAT_HI_01, WEAPON_DEAGLE,      BLIP_COLOR_RED,  accuracy, ehealth, armour, 10, -112.16,  1620.28, 19.9447, 209.0, 0);
			SPAWN_ACTOR(3,  MODEL_M_Y_GLAT_HI_02, WEAPON_MP5,         BLIP_COLOR_RED,  accuracy, ehealth, armour, 10, -124.208, 1638.71, 19.7692, 209.0, 0);
			SPAWN_ACTOR(4,  MODEL_M_Y_GLAT_LO_01, WEAPON_M4,          BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -136.187, 1642.96, 20.5699, 209.0, 0);
			SPAWN_ACTOR(5,  MODEL_M_Y_GLAT_LO_02, WEAPON_M4,          BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -127.286, 1634.55,  20.146, 209.0, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_GLAT_HI_01, WEAPON_DEAGLE,      BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -111.977, 1639.25, 18.9476, 209.0, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_GLAT_HI_02, WEAPON_M4,          BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -108.742, 1649.75, 18.5945, 209.0, 0);
			SPAWN_ACTOR(8,  MODEL_M_Y_GLAT_LO_01, WEAPON_MP5,         BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -102.999, 1651.78, 18.5576, 209.0, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_GLAT_LO_02, WEAPON_MP5,         BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -109.709, 1660.58, 18.6001, 209.0, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_GLAT_HI_01, WEAPON_M4,          BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -104.808, 1664.24, 18.6018, 209.0, 0);
			SPAWN_ACTOR(11, MODEL_M_Y_GLAT_HI_02, WEAPON_MP5,         BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -96.0378, 1655.48, 18.5293, 209.0, 0);
			SPAWN_ACTOR(12, MODEL_M_Y_GLAT_HI_01, WEAPON_MP5,         BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -87.382,  1648.54, 18.2102, 209.0, 0);
			SPAWN_ACTOR(13, MODEL_M_Y_GLAT_HI_02, WEAPON_M4,          BLIP_COLOR_RED,  accuracy, ehealth, armour, 0, -79.6563, 1652.74, 18.6692, 209.0, 0);
			TASK_CHAT_WITH_CHAR(peds[0].actor, peds[2].actor, 1, 1);
			TASK_CHAT_WITH_CHAR(peds[2].actor, peds[0].actor, 0, 1);
			PLAY_CHECKPOINT_SOUND();
			objrc++;			
		}
		
		if(objrc == 2)
		{
			GOTO_LOCATION_WITH_VEHICLE(1, 0, -1477.68, 1125.49, 20.0449, "Deliver the ~b~car~S~ to the ~Y~dealership~S~", "Repo the ~b~Sabre GT~S~");	

			if(DOES_VEHICLE_EXIST(vehs[1].car))
			{
				if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car))
				{
					if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -245.837, 1714.64, 14.6782, 80.00000000, 80.00000000, 80.0000000, 0) && !DOES_VEHICLE_EXIST(vehs[2].car) && vehs[2].retc != 2)
					{
						SPAWN_VEHICLE(2, MODEL_LANDSTALKER, NOBLIP, -245.837, 1714.64, 14.6782, 255.0, vhealth, 1);
						SPAWN_ACTOR_INSIDE_CAR(14, 2, 10, MODEL_M_Y_GAFR_HI_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
						SPAWN_ACTOR_INSIDE_CAR(15, 2, 0,  MODEL_M_Y_GAFR_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
						GO_AFTER_PLAYER_WITH_VEHICLE(14, 2);
					}
					
					if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -872.364, 1163.52, 18.0094, 130.00000000, 130.00000000, 130.00000000, 0) && !DOES_VEHICLE_EXIST(vehs[3].car) && vehs[3].retc != 2)
					{
						SPAWN_VEHICLE(3, MODEL_LANDSTALKER, NOBLIP, -872.364, 1163.52, 18.0094, 270.0, vhealth, 1);
						SPAWN_ACTOR_INSIDE_CAR(16, 3, 10, MODEL_M_Y_GAFR_HI_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
						SPAWN_ACTOR_INSIDE_CAR(17, 3, 0,  MODEL_M_Y_GAFR_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
						GO_AFTER_PLAYER_WITH_VEHICLE(16, 3);
					}
					
					if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -1412.22, 1255.99, 23.9687, 80.00000000, 80.00000000, 80.0000000, 0) && !DOES_VEHICLE_EXIST(vehs[4].car) && vehs[4].retc != 2)
					{
						SPAWN_VEHICLE(4, MODEL_LANDSTALKER, NOBLIP, -1412.22, 1255.99, 23.9687, 221.0, vhealth, 1);
						SPAWN_ACTOR_INSIDE_CAR(18, 4, 10, MODEL_M_Y_GAFR_HI_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
						SPAWN_ACTOR_INSIDE_CAR(19, 4, 0,  MODEL_M_Y_GAFR_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
						GO_AFTER_PLAYER_WITH_VEHICLE(18, 4);
					}	
				}
			}
		}
		
		if(objrc == 3)
		{
			MISSION_COMPLETE("", 10000);
		}
	}
}