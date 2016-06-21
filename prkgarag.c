// GTA V Online Mission for IV
// Mission: The Parking Garage
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   6
Pickup document2;
float zg;

void main(void)
{
	int i;
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	CLEAR_ZONE(2237.89, 184.489, 5.85721, 200.0);
	INIT_SETTINGS(2237.89, 184.489, 5.85721, 0.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	CLEAR_ZONE(2225.7,  345.369, 17.2112, 200.0);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);

	while (TRUE)
    {
		WAIT(0);
		GET_CHAR_COORDINATES(GetPlayerPed(), &px, &py, &pz);
		GET_CHAR_HEADING(GetPlayerPed(), &ph);
		
		if(objrc == 0)
		{
			DRAW_MENU();
			PRINT_MAIN_LOGO(0.39, 0.05, "The Parking Garage");
			PRINT_DESC(0.34, 0.11, "Recreation of GTA V Online mission \"The Parking Garage\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			POLICE(0, 0);
			MANAGE_PLAYER();
			MANAGE_ACTORS(21);
			MANAGE_VEHICLES(8);
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, 2236.36, 191.781, 5.96358, 270.0, 25000, 0);
			SPAWN_VEHICLE(1, MODEL_PMP600, NOBLIP,  2225.7,  345.369, 17.2112, 0.0,   vhealth, 1);
			SPAWN_VEHICLE(2, MODEL_PMP600, NOBLIP,  2235.81, 344.851, 17.2112, 0.0,   vhealth, 1);
			SPAWN_VEHICLE(3, MODEL_PMP600, NOBLIP,  2237.24, 362.006, 17.2112, 180.0, vhealth, 1);
			SPAWN_VEHICLE(4, MODEL_PMP600, NOBLIP,  2226.02, 361.978, 17.2112, 180.0, vhealth, 1);
			
			for(i=1;i<=4;i++)
			{
				OPEN_CAR_DOOR(vehs[i].car, 0);
				OPEN_CAR_DOOR(vehs[i].car, 1);
				OPEN_CAR_DOOR(vehs[i].car, 2);
				OPEN_CAR_DOOR(vehs[i].car, 3);
			}
			
			SPAWN_ACTOR(0,  MODEL_M_Y_GLAT_LO_01, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 10, 2241.71, 349.074, 17.2112, 180.0, 0);
			SPAWN_ACTOR(1,  MODEL_M_Y_GLAT_LO_02, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 10, 2236.66, 352.623, 17.2112, 180.0, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_GLAT_HI_01, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 10, 2234.38, 351.852, 17.2112, 180.0, 0);
			SPAWN_ACTOR(3,  MODEL_M_Y_GLAT_HI_02, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 10, 2220.1,  355.928, 17.2112, 180.0, 0);
			SPAWN_ACTOR(4,  MODEL_M_Y_GLAT_LO_01, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 10, 2218.18, 350.432, 17.2112, 180.0, 0);
			SPAWN_ACTOR(5,  MODEL_M_Y_GLAT_LO_02, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 10, 2224.79, 349.411, 17.2112, 180.0, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_GLAT_HI_01, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 10, 2221.69, 367.831, 17.2112, 180.0, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_GLAT_HI_02, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 10, 2228.39, 374.876, 17.2111, 180.0, 0);
			SPAWN_ACTOR(8,  MODEL_M_Y_GLAT_LO_01, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 10, 2246.78, 372.589, 17.3392, 180.0, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_GLAT_LO_02, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 10, 2247.09, 360.237, 17.3619, 180.0, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_GLAT_HI_01, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 10, 2234.74, 335.179, 17.2112,   0.0, 0);
			SPAWN_ACTOR(11, MODEL_M_Y_GLAT_HI_02, WEAPON_M4,  NOBLIP, accuracy, ehealth, armour, 10, 2230.77, 335.418, 17.2112,   0.0, 0);
			SPAWN_ACTOR(12, MODEL_M_Y_GLAT_LO_02, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 10, 2228.00, 344.176, 17.2112, 180.0, 0);
			SPAWN_ACTOR(13, MODEL_M_Y_GLAT_HI_01, WEAPON_MP5, NOBLIP, accuracy, ehealth, armour, 10, 2240.39, 344.829, 17.2112, 180.0, 0);
			TASK_CHAT_WITH_CHAR(peds[10].actor, peds[13].actor, 1, 1);
			TASK_CHAT_WITH_CHAR(peds[11].actor, peds[12].actor, 0, 1);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
		
		if(objrc == 2)
		{
			SET_MISSION_CHECKPOINT(0, 2265.86, 310.3, 3.93312, 4.0, "Go to the ~Y~parking lot~S~");
		}
		
		if(objrc == 3)
		{
			GET_GROUND_Z_FOR_3D_COORD(2247.02, 364.361, 17.3601, &zg);
			CREATE_PICKUP(drugbag, 22, 2247.02, 364.361, zg, &document2, 1);
			objrc++;
		}
		
		if(objrc == 4)
		{
			PRINT_TXT("Get the ~b~document~s~");
			
			if(HAS_PICKUP_BEEN_COLLECTED(document2))
			{
				PLAY_CHECKPOINT_SOUND();
				objrc++;
			}
		}
		
		if(objrc == 5)
		{
			SET_MISSION_CHECKPOINT(0, 747.599, -119.14, 3.67973, 4.0, "Deliver the ~b~document~s~ to ~Y~Lester's warehourse~S~");
			SPAWN_ENEMY_CAR_IN_AREA(MODEL_HUNTLEY, 1847.66, 259.651, 5.34315, 5, 14, 15, MODEL_M_Y_GAFR_HI_01);
			SPAWN_ENEMY_CAR_IN_AREA(MODEL_HUNTLEY, 1854.45, 276.598, 5.134,   6, 16, 17, MODEL_M_Y_GAFR_HI_01);
			SPAWN_ENEMY_CAR_IN_AREA(MODEL_HUNTLEY, 1370.08, 295.171, 24.829,  7, 18, 19, MODEL_M_Y_GAFR_HI_01);
			SPAWN_ENEMY_CAR_IN_AREA(MODEL_HUNTLEY, 1357.89, 281.534, 25.8018, 8, 20, 21, MODEL_M_Y_GAFR_HI_01);			
		}
		
		if(objrc == 6)
		{
			MISSION_COMPLETE("", 20000);
		}
	}
}