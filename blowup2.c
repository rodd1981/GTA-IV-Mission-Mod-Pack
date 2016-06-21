// GTA V Online Mission for IV
// Mission: Blow Up 2
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   7

void main(void)
{
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	CLEAR_ZONE(-346.642, 244.674, 14.7565, 200.0);
	SET_PARKED_CAR_DENSITY_MULTIPLIER(0.0);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);
	INIT_SETTINGS(-346.642, 244.674, 14.7565, 90.0);
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
			PRINT_MAIN_LOGO(0.43, 0.05, "Blow Up 2");
			PRINT_DESC(0.35, 0.11, "Recreation of GTA V Online mission \"Blow up 2\"");
			//PRINT_DESC(0.20, 0.13, "Test1");
			//PRINT_DESC(0.20, 0.15, "Test2");
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			POLICE(1, 3);
			MANAGE_PLAYER();
			MANAGE_VEHICLES(8);
			MANAGE_UNIQUE_VEHICLE_STATUS(2); // Used to check if vehicle gets destroyed (if so, mission will finish as failed)
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			CLEAR_ZONE(-603.353, 272.82, 4.66682, 40.0);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, -353.286, 237.295, 14.673,  0.7, 25000, 0);
			SPAWN_VEHICLE(1,    MODEL_COQUETTE, NOBLIP,  -595.251, 264.305, 4.66682, 0.0,   vhealth, 1);
			SPAWN_VEHICLE(2,     MODEL_BANSHEE, NOBLIP,  -588.593, 263.887, 4.66682, 0.0,   vhealth, 0); // Objective - Deliver this vehicle
			CHANGE_CAR_COLOUR(vehs[2].car, 135, 135);
			SPAWN_VEHICLE(3,    MODEL_INFERNUS, NOBLIP,  -585.645, 264.17,  4.66682, 0.0,   vhealth, 1);
			SPAWN_VEHICLE(4,       MODEL_REBLA, NOBLIP,  -582.498, 264.088, 4.66682, 0.0,   vhealth, 1);
			SPAWN_VEHICLE(5, MODEL_LANDSTALKER, NOBLIP,  -594.292, 281.632, 4.66682, 180.0, vhealth, 1);
			SPAWN_VEHICLE(6,       MODEL_PRIMO, NOBLIP,  -590.92,  281.835, 4.66682, 180.0, vhealth, 1);
			SPAWN_VEHICLE(7,       MODEL_SABRE, NOBLIP,  -587.792, 282.322, 4.66682, 180.0, vhealth, 1);
			SPAWN_VEHICLE(8,      MODEL_PMP600, NOBLIP,  -584.526, 282.144, 4.66682, 180.0, vhealth, 1);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
		
		if(objrc == 2)
		{
			SET_MISSION_CHECKPOINT(0, -603.353, 272.82, 2.66682, 5.0, "Go to the ~Y~parking lot~S~");
		}
		
		if(objrc == 3)
		{
			ADD_CAR_BLIP(1, BLIP_COLOR_RED);
			ADD_CAR_BLIP(2, BLIP_COLOR_CYAN);
			ADD_CAR_BLIP(3, BLIP_COLOR_RED);
			ADD_CAR_BLIP(4, BLIP_COLOR_RED);
			ADD_CAR_BLIP(5, BLIP_COLOR_RED);
			ADD_CAR_BLIP(6, BLIP_COLOR_RED);
			ADD_CAR_BLIP(7, BLIP_COLOR_RED);
			ADD_CAR_BLIP(8, BLIP_COLOR_RED);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
		
		if(objrc == 4)
		{
			PRINT_TXT("Destroy the ~R~cars~S~. Remember and keep the ~b~Banshee~S~ away from the carnage!");
			
			if(vehs[1].retc == 2 && vehs[3].retc == 2 && vehs[4].retc == 2 && vehs[5].retc == 2 && vehs[6].retc == 2 && vehs[7].retc == 2 && vehs[8].retc == 2)
			{
				ALTER_WANTED_LEVEL(GetPlayerIndex(), 3);
				PLAY_CHECKPOINT_SOUND();
				objrc++;
			}
		}
		
		if(objrc == 5)
		{
			APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
			objrc++;
		}
		
		if(objrc == 6)
		{
			if(CHECK_WANTED_LEVEL() == 1)
			{
				PRINT_TXT("Lose the cops");
			}
			
			if(CHECK_WANTED_LEVEL() == 0)
			{
				GOTO_LOCATION_WITH_VEHICLE(2, 9, -1477.68, 1125.49, 20.0449, "Deliver the ~b~Banshee~S~ to the ~Y~dealership~S~", "Get in the ~b~Banshee~S~");	
			}
		}
		
		if(objrc == 7)
		{			
			if(CHECK_WANTED_LEVEL() == 1)
			{
				PRINT_TXT("Lose the cops");
			}
			
			if(CHECK_WANTED_LEVEL() == 0)
			{
				MISSION_COMPLETE("", 10000);
			}
		}
	}
}