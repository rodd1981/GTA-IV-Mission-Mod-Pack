// GTA V Online Mission for IV
// Mission: Potshot
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
	CLEAR_ZONE(-993.127, 1602.71, 23.7039, 200.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);
	INIT_SETTINGS(-1001.27, 1606.37, 23.9702, 218.0);
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
			PRINT_MAIN_LOGO(0.44, 0.05, "Potshot");
			PRINT_DESC(0.36, 0.11, "Recreation of GTA V Online mission \"Potshot\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			MANAGE_PLAYER();
			MANAGE_ACTORS(13);
			POLICE(0, 0);
			MANAGE_UNIQUE_VEHICLE_STATUS(1);
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			CLEAR_ZONE(-1698.47, -251.951, 2.75527, 80.0);
			SPAWN_VEHICLE(1, MODEL_BOXVILLE, BLIP_COLOR_CYAN, -975.19, 1845.89, 22.4331, 146.0, 20000, 0);
			CHANGE_CAR_COLOUR(vehs[1].car, 56, 56);
			OPEN_CAR_DOOR(vehs[1].car, 2);
			OPEN_CAR_DOOR(vehs[1].car, 3);
			SET_CAR_ONLY_DAMAGED_BY_PLAYER(vehs[1].car, TRUE);	
			SPAWN_VEHICLE(0, vehmodel,  BLIP_COLOR_WHITE, -993.127, 1602.71, 23.7039, 218.0, 25000, 0);			
			SPAWN_ACTOR(0,  MODEL_M_Y_GLAT_LO_01, WEAPON_M4,      NOBLIP,  accuracy, ehealth, armour, 20, -964.5,   1801.97,  22.568, 218.0, 0);
			SPAWN_ACTOR(1,  MODEL_M_Y_GLAT_LO_02, WEAPON_M4,      NOBLIP,  accuracy, ehealth, armour, 20, -973.685, 1795.45, 21.5553, 218.0, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_GLAT_HI_01, WEAPON_MP5,     NOBLIP,  accuracy, ehealth, armour, 30, -970.632, 1812.19, 25.5898, 218.0, 0);
			SPAWN_ACTOR(3,  MODEL_M_Y_GLAT_HI_02, WEAPON_MP5,     NOBLIP,  accuracy, ehealth, armour, 30, -970.056, 1823.3,  25.9393, 218.0, 0);
			SPAWN_ACTOR(4,  MODEL_M_Y_GLAT_LO_01, WEAPON_M4,      NOBLIP,  accuracy, ehealth, armour, 30, -960.154, 1820.17, 24.4381, 218.0, 0);
			SPAWN_ACTOR(5,  MODEL_M_Y_GLAT_LO_02, WEAPON_M4,      NOBLIP,  accuracy, ehealth, armour, 30, -956.683, 1832.14, 24.0773, 218.0, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_GLAT_HI_01, WEAPON_MP5,     NOBLIP,  accuracy, ehealth, armour, 30, -964.955, 1839.44, 23.4045, 218.0, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_GLAT_HI_02, WEAPON_MP5,     NOBLIP,  accuracy, ehealth, armour, 30, -997.653, 1843.78, 23.1654, 218.0, 0);
			SPAWN_ACTOR(8,  MODEL_M_Y_GLAT_LO_01, WEAPON_M4,      NOBLIP,  accuracy, ehealth, armour, 30, -994.89,  1855.23, 22.3237, 218.0, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_GLAT_LO_02, WEAPON_M4,      NOBLIP,  accuracy, ehealth, armour, 30, -985.224, 1852.71, 22.3286, 218.0, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_GLAT_HI_01, WEAPON_MP5,     NOBLIP,  accuracy, ehealth, armour, 30, -974.953, 1861.38, 22.3548, 218.0, 0);
			SPAWN_ACTOR(11, MODEL_M_Y_GLAT_HI_02, WEAPON_MP5,     NOBLIP,  accuracy, ehealth, armour, 30, -963.932, 1853.13, 22.7367, 218.0, 0);
			SPAWN_ACTOR(12, MODEL_M_Y_GLAT_HI_01, WEAPON_M4,      NOBLIP,  accuracy, ehealth, armour, 30, -951.958, 1844.28, 23.3605, 218.0, 0);
			SPAWN_ACTOR(13, MODEL_M_Y_GLAT_HI_02, WEAPON_MP5,     NOBLIP,  accuracy, ehealth, armour, 30, -982.619, 1848.14, 22.3487, 218.0, 0);
			PLAY_CHECKPOINT_SOUND();
			objrc++;					
		}
		
		if(objrc == 2)
		{	
			if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car) || !IS_CHAR_IN_CAR(GetPlayerPed(), vehs[1].car))
			{
				GOTO_LOCATION_WITH_VEHICLE(1, 0, -1669.66, -15.9458, 7.62874, "Deliver the ~b~van~S~ to ~Y~Trevor's trailer~S~", "Steal the ~b~van~S~");	
			}
		}
			
		if(objrc == 3)
		{
			MISSION_COMPLETE("", 15000);
		}
	}
}