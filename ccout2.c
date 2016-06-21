// GTA V Online Mission for IV
// Mission: Crystal Clear Out 2
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   3

void main(void)
{
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	CLEAR_ZONE(-853.735, 786.536, 4.46572, 200.0);
	INIT_SETTINGS(-845.426, 773.775, 4.46572, 90.0);
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
			PRINT_MAIN_LOGO(0.38, 0.05, "Crystal Clear Out 2");
			PRINT_DESC(0.35, 0.11, "Recreation of GTA V Online mission \"Crystal Clear Out 2\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			POLICE(0, 0);
			MANAGE_PLAYER();
			MANAGE_ACTORS(19);
			ALTER_WANTED_LEVEL(GetPlayerIndex(), 0);
		}
			
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			CLEAR_ZONE(-1028.73, 1417.01, 25.6895, 15.0);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, -853.735, 786.536, 4.46572, 90.0, 25000, 0);
			SPAWN_VEHICLE(1, MODEL_LANDSTALKER, NOBLIP,  -1061.9,  -570.603, 2.85199, 51.0, vhealth, 1);
			SPAWN_VEHICLE(2, MODEL_REBLA,       NOBLIP,  -1045.56, -587.348, 2.85195, 51.0, vhealth, 1);
			SPAWN_VEHICLE(3, MODEL_RUINER,      NOBLIP,  -1042.66, -570.529, 2.85199, 51.0, vhealth, 1);
			SPAWN_ACTOR(0,  MODEL_M_Y_GLAT_LO_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1046.89, -574.214, 2.85195, 0.0, 0);
			SPAWN_ACTOR(1,  MODEL_M_Y_GLAT_LO_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1048.99, -570.175, 2.85199, 0.0, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_GLAT_HI_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1045.54, -572.489, 2.85199, 0.0, 0);
			SPAWN_ACTOR(3,  MODEL_M_Y_GLAT_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1049.8,  -582.973, 2.85195, 0.0, 0);
			SPAWN_ACTOR(4,  MODEL_M_Y_GLAT_LO_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1059.32, -585.468, 2.85195, 0.0, 0);
			SPAWN_ACTOR(5,  MODEL_M_Y_GLAT_LO_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1036.74, -568.812, 2.85199, 0.0, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_GLAT_HI_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1034.93, -562.12,  2.85199, 0.0, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_GLAT_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour,  50,    -1065, -598.316, 3.88147, 0.0, 0);
			SPAWN_ACTOR(8,  MODEL_M_Y_GLAT_LO_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1080.26, -585.084, 2.85195, 0.0, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_GLAT_LO_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1033.73, -604.027, 2.99985, 0.0, 0);	
			SPAWN_VEHICLE(4, MODEL_LANDSTALKER, NOBLIP,  -1576.52, -261.846, 2.84248, 51.0, vhealth, 1);
			SPAWN_VEHICLE(5, MODEL_REBLA,       NOBLIP,  -1567.47, -253.508, 2.84421, 51.0, vhealth, 1);
			SPAWN_VEHICLE(6, MODEL_RUINER,      NOBLIP,  -1565.6,  -265.81,  2.84384, 51.0, vhealth, 1);
			SPAWN_ACTOR(10,  MODEL_M_Y_GLAT_LO_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1578.59, -256.587, 2.85484, 210.0, 0);
			SPAWN_ACTOR(11,  MODEL_M_Y_GLAT_LO_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1575.34, -256.749, 2.83832, 210.0, 0);
			SPAWN_ACTOR(12,  MODEL_M_Y_GLAT_HI_01, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1577.46, -259.32,  2.84035, 210.0, 0);
			SPAWN_ACTOR(13,  MODEL_M_Y_GLAT_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1572.57, -266.798, 2.84248, 210.0, 0);
			SPAWN_ACTOR(14,  MODEL_M_Y_GLAT_LO_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1577.95, -269.074, 2.84248, 210.0, 0);
			SPAWN_ACTOR(15,  MODEL_M_Y_GLAT_HI_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1562.31, -265.447, 2.8469,  210.0, 0);
			SPAWN_ACTOR(16,  MODEL_M_Y_GLAT_HI_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1555.47, -259.006, 2.84248, 210.0, 0);
			SPAWN_ACTOR(17,  MODEL_M_Y_GLAT_LO_02, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1547.82, -243.737, 2.84306, 210.0, 0);
			SPAWN_ACTOR(18,  MODEL_M_Y_GLAT_HI_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1539.28, -267.798, 2.84184, 210.0, 0);
			SPAWN_ACTOR(19,  MODEL_M_Y_GLAT_HI_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour,  50, -1548.88, -276.916, 2.88562, 210.0, 0);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
	
		if(objrc == 2)
		{
			PRINT_TXT("Take out the ~R~enemies~S~");
			
			if(peds[0].retc == 2 && peds[1].retc == 2 && peds[2].retc == 2 && peds[3].retc == 2 && peds[4].retc == 2 && peds[5].retc == 2 && peds[6].retc == 2 && peds[7].retc == 2 && peds[8].retc == 2 && peds[9].retc == 2 && peds[10].retc == 2 && peds[11].retc == 2 && peds[12].retc == 2 && peds[13].retc == 2 && peds[14].retc == 2 && peds[15].retc == 2 && peds[16].retc == 2 && peds[17].retc == 2 && peds[18].retc == 2 && peds[19].retc == 2)
			{
				objrc++;
			}	
		}
		
		if(objrc == 3)
		{
			MISSION_COMPLETE("", 13000);
		}
	}
}