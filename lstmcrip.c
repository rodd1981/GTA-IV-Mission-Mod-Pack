// GTA V Online Mission for IV
// Mission: Lost MC RIP
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
	CLEAR_ZONE(414.907, 28.0238, 8.79453, 200.0);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);
	INIT_SETTINGS(420.828, 28.8978, 8.78683, 100.0);
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
			PRINT_MAIN_LOGO(0.43, 0.05, "Lost MC RIP");
			PRINT_DESC(0.35, 0.11, "Recreation of GTA V Online mission \"Lost MC RIP\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			POLICE(0, 0);
			MANAGE_PLAYER();
			MANAGE_ACTORS(14);
			ALTER_WANTED_LEVEL(GetPlayerIndex(), 0);	
		}
	
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			CLEAR_ZONE(480.671, 330.929, 8.57156, 50.0);
			SPAWN_VEHICLE(0, vehmodel,  BLIP_COLOR_WHITE, 414.907, 28.0238, 8.79453, 10.0, 25000, 0);
			SPAWN_VEHICLE(1, MODEL_HELLFURY, NOBLIP,  480.671, 330.929, 8.57156, 287.0, vhealth, 1);
			SPAWN_VEHICLE(2, MODEL_HELLFURY, NOBLIP,  500.989, 331.218, 8.57157, 287.0, vhealth, 1);
			SPAWN_VEHICLE(3, MODEL_HELLFURY, NOBLIP,  462.637, 342.84,  8.57144, 287.0, vhealth, 1);
			SPAWN_VEHICLE(4, MODEL_HELLFURY, NOBLIP,  456.194, 328.523, 8.57156, 287.0, vhealth, 1);
			SPAWN_VEHICLE(5, MODEL_ROMERO,   NOBLIP,  469.083, 341.918, 8.57143,   0.0, vhealth, 1);
			SPAWN_ACTOR(0,   MODEL_M_M_GBIK_LO_03, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 477.765, 330.598, 8.57155, 0.0, 0);
			SPAWN_ACTOR(1,   MODEL_M_Y_GBIK_HI_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 487.11,  332.822, 8.58402, 0.0, 0);
			SPAWN_ACTOR(2,   MODEL_M_Y_GBIK_HI_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 462.72,  329.053, 8.57155, 0.0, 0);
			SPAWN_ACTOR(3,   MODEL_M_Y_GBIK_LO_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 455.702, 331.683, 8.57326, 0.0, 0);
			SPAWN_ACTOR(4,   MODEL_M_Y_GBIK_LO_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 453.886, 342.619, 8.57142, 0.0, 0);
			SPAWN_ACTOR(5,   MODEL_M_M_GBIK_LO_03, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 455.879, 353.054, 8.57143, 0.0, 0);
			SPAWN_ACTOR(6,   MODEL_M_Y_GBIK_HI_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 461.334, 354.282, 8.55088, 0.0, 0);
			SPAWN_ACTOR(7,   MODEL_M_Y_GBIK_HI_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 452.701, 350.135, 8.57144, 0.0, 0);
			SPAWN_ACTOR(8,   MODEL_M_Y_GBIK_LO_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 475.867, 352.833, 8.57144, 0.0, 0);
			SPAWN_ACTOR(9,   MODEL_M_Y_GBIK_LO_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 485.464, 355.757, 8.57232, 0.0, 0);
			SPAWN_ACTOR(10,  MODEL_M_M_GBIK_LO_03, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 494.51,  355.139, 8.57158, 0.0, 0);
			SPAWN_ACTOR(11,  MODEL_M_Y_GBIK_HI_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 501.969, 343.139, 8.57158, 0.0, 0);
			SPAWN_ACTOR(12,  MODEL_M_Y_GBIK_HI_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 510.718, 339.741, 8.57158, 0.0, 0);
			SPAWN_ACTOR(13,  MODEL_M_Y_GBIK_LO_01, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 513.053, 328.065, 8.57157, 0.0, 0);
			SPAWN_ACTOR(14,  MODEL_M_Y_GBIK_LO_02, WEAPON_M4,  BLIP_COLOR_RED, accuracy, ehealth, armour, 0, 505.737, 314.082, 8.57796, 0.0, 0);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
		
		if(objrc == 2)
		{
			PRINT_TXT("Take out the ~R~Lost~S~");
			
			if(peds[0].retc == 2 && peds[1].retc == 2 && peds[2].retc == 2 && peds[3].retc == 2 && peds[4].retc == 2 && peds[5].retc == 2 && peds[6].retc == 2 && peds[7].retc == 2 && peds[8].retc == 2 && peds[9].retc == 2 && peds[10].retc == 2 && peds[11].retc == 2 && peds[12].retc == 2 && peds[13].retc == 2 && peds[14].retc == 2)
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