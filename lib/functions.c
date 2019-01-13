// GTA IV Native functions API (to use together with SCOCL)
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

// vars
Camera cam;
Vehicle veh;
Ped driver;
Vector3 wayp;
float x, y, z, PLx, PLy, dist;
float vehx, vehy, vehz, vehh;

// Groups
Group victimgrp;

// Return code vars, life counter and env vars

uint objrc = 0,
timerrc = 0,
missionrc = 0,
tlives,
tlivesrc = 0;

uint ehealth, 
vhealth,
armour, 
accuracy, 
vehmodel,
srate;
float fdamage;
int tod;

int level, weather, time, car;

// Object hash code list
uint drugbag  = 1557431624;
uint cokepkg  = 744256525;
uint document = 2012013641;
uint box2     = 3475812154;
uint laptop   = 3489541879;
uint cashpile = 1778551148;

// Player coords vars (used to calculate distance between player & blip) and pickup coords vars,  
float px, py, pz, ph, PKx, PKy, PKz, GZ, distblip, distance;
Vehicle randomveh;

// Actors vars definition
typedef struct _PEDS
{
	Ped actor;
	int retc;
	Blip pblip;
	uint objhash;
	Pickup object;
	int objretc;
	float sense;
	int seat;
} PEDS;
PEDS peds[30];

// Vehicle vars definition
typedef struct _VEHS
{
	Vehicle car;
	int retc;
	Blip vblip;
	Blip checkpoint;
} VEHS;
VEHS vehs[20];


void GTAV_TELEPORT(float destx, float desty){
    // defaults
    int fade;
    float topdown;
    float topdown_start = 5.0;
    float topdown_end = 1000.0;
    float position_step;
    float position = 0.0;
    float position_end = 1.0;
	
	DISPLAY_AREA_NAME(FALSE);
	DISPLAY_CASH(FALSE);
	DISPLAY_FRONTEND_MAP_BLIPS(FALSE);
	DISPLAY_HUD(FALSE);
	DISPLAY_RADAR(FALSE);
    
    // create cam
    CREATE_CAM(14, &cam);
    SET_CAM_ACTIVE(cam, true);
    SET_CAM_PROPAGATE(cam, true);
    ACTIVATE_SCRIPTED_CAMS(true, true);
    ATTACH_CAM_TO_PED(cam, GetPlayerPed());
    SET_CAM_ATTACH_OFFSET(cam, 0.0, 0.0, topdown_start);
    POINT_CAM_AT_PED(cam, GetPlayerPed());
    topdown = topdown_start;
    
    // disable movement
    SET_PLAYER_CONTROL(GET_PLAYER_ID(), false);
    
    // flash
    fade = 255;
    while(fade > 25){
        DRAW_RECT(0.5, 0.5, 1.0, 1.0, 255, 255, 255, fade);
        fade -= 25;
        WAIT(0);
    }
    
    // zoom out
    while(topdown <= topdown_end){
        UNATTACH_CAM(cam);
        ATTACH_CAM_TO_PED(cam, GetPlayerPed());
        SET_CAM_ATTACH_OFFSET(cam, 0.0, 0.0, topdown);
        POINT_CAM_AT_PED(cam, GetPlayerPed());
        topdown += 15.0;
        WAIT(0);
    }
    UNATTACH_CAM(cam);
    ATTACH_CAM_TO_PED(cam, GetPlayerPed());
    SET_CAM_ATTACH_OFFSET(cam, 0.0, 0.0, topdown_end);
    POINT_CAM_AT_PED(cam, GetPlayerPed());
    
    // slide cam to waypoint
    GET_CHAR_COORDINATES(GetPlayerPed(), &x, &y, &z);
    GET_DISTANCE_BETWEEN_COORDS_2D(x, y, destx, desty, &dist);
    if(dist < 250) position_step = 0.5;
    else if(dist < 750) position_step = 0.05;
    else position_step = 0.01;
    while(position <= position_end){
        PLx = x + position * (destx - x);
        PLy = y + position * (desty - y);
        UNATTACH_CAM(cam);
        SET_CAM_POS(cam, PLx, PLy, topdown);
        POINT_CAM_AT_COORD(cam, PLx, PLy, 0.0);
        position += position_step;
        WAIT(0);
    }
    
    // teleport to waypoint
    if(IS_CHAR_IN_ANY_CAR(GetPlayerPed())){
        GET_CAR_CHAR_IS_USING(GetPlayerPed(), &veh);
        SET_CAR_COORDINATES(veh, destx, desty, 50.0);
    }
    else SET_CHAR_COORDINATES(GetPlayerPed(), destx, desty, 50.0);
    WAIT(10);
    GET_CHAR_COORDINATES(GetPlayerPed(), &x, &y, &z);
	LOAD_SCENE(x, y, z);
	WAIT(10);
	GET_GROUND_Z_FOR_3D_COORD(x, y, z, &z);
    if(IS_CHAR_IN_ANY_CAR(GetPlayerPed())){
        GET_CAR_CHAR_IS_USING(GetPlayerPed(), &veh);
        SET_CAR_COORDINATES(veh, x, y, z);
    }
    else SET_CHAR_COORDINATES(GetPlayerPed(), x, y, z);
    
    // zoom in
    while(topdown >= topdown_start){
        UNATTACH_CAM(cam);
        ATTACH_CAM_TO_PED(cam, GetPlayerPed());
        SET_CAM_ATTACH_OFFSET(cam, 0.0, 0.0, topdown);
        POINT_CAM_AT_PED(cam, GetPlayerPed());
        topdown -= 15.0;
        WAIT(0);
    }
    UNATTACH_CAM(cam);
    ATTACH_CAM_TO_PED(cam, GetPlayerPed());
    SET_CAM_ATTACH_OFFSET(cam, 0.0, 0.0, topdown_start);
    POINT_CAM_AT_PED(cam, GetPlayerPed());
    
    // flash
    fade = 255;
    while(fade > 25){
        DRAW_RECT(0.5, 0.5, 1.0, 1.0, 255, 255, 255, fade);
        fade -= 25;
        WAIT(0);
    }
    
    // enable movement
    SET_PLAYER_CONTROL(GET_PLAYER_ID(), true);
    
    // delete cam
    SET_CAM_ACTIVE(cam, false);
    SET_CAM_PROPAGATE(cam, false);
    ACTIVATE_SCRIPTED_CAMS(false, false);
    if(DOES_CAM_EXIST(cam)) DESTROY_CAM(cam);
    SET_CAM_BEHIND_PED(GetPlayerPed());
    
    // finished
}

void APPLY_SELECTED_OPTIONS(int lvl, int wth, int time)
{
	if(lvl == 0)
	{
		tlives   = 2;
		ehealth  = 70;
		vhealth  = 100;
		armour   = 0;
		accuracy = 40;
		srate    = 40;
		fdamage  = 0.5;
	}
	
	if(lvl == 1)
	{
		tlives   = 2;
		ehealth  = 85;
		vhealth  = 125;
		armour   = 25;
		accuracy = 65;
		srate    = 65;
		fdamage  = 1.5;
	}
	
	if(lvl == 2)
	{
		tlives   = 1;
		ehealth  = 100;
		vhealth  = 150;
		armour   = 100;
		accuracy = 100;
		srate    = 100;
		fdamage  = 3.5;
	}
	
	if(wth == 0)
	{
		FORCE_WEATHER_NOW(WEATHER_EXTRA_SUNNY);
	}
	
	if(wth == 1)
	{
		FORCE_WEATHER_NOW(WEATHER_RAINING);
	}
	
	if(time == 0)
	{
		SET_TIME_OF_DAY(9, 00);
		tod = 0;
	}
	
	if(time == 1)
	{
		SET_TIME_OF_DAY(13, 00);
		tod = 1;
	}
	
	if(time == 2)
	{
		SET_TIME_OF_DAY(22, 00);
		tod = 2;
	}
}

void LOCK_TIME_OF_DAY(void)
{
	if(tod == 0)
	{
		SET_TIME_OF_DAY(9, 00);
	}
	
	if(tod == 1)
	{
		SET_TIME_OF_DAY(13, 00);
	}
	
	if(tod == 2)
	{
		SET_TIME_OF_DAY(22, 00);
	}
}

int CHECK_WANTED_LEVEL()
{
	if(IS_WANTED_LEVEL_GREATER(GetPlayerIndex(), 0))
	{
		return 1;
	}
	else if(!IS_WANTED_LEVEL_GREATER(GetPlayerIndex(), 0))
	{
		return 0;
	}
}

void DESTROY_ACTORS(void)
{
	int i;
	
	for(i=0;i<=30;i++)
	{
		if(DOES_CHAR_EXIST(peds[i].actor))
		{
			EXPLODE_CHAR_HEAD(peds[i].actor);
			TASK_DIE(peds[i].actor);
			REMOVE_BLIP(peds[i].pblip);
			MARK_CHAR_AS_NO_LONGER_NEEDED(&peds[i].actor);
			peds[i].retc = 2;
		}
	}
}

void PRINT_TXT(char *string)
{
	if(missionrc == 0)
	{
		PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", string, 100, 1);
	}
}

void DRAW_WINDOW_FOR_DESC(float x, float y, float width, float heigh, int alpha)
{
	HIDE_HELP_TEXT_THIS_FRAME();
	DRAW_CURVED_WINDOW(x, y, width, heigh, alpha);
}

void PRINT_TXT2(char *string)
{
	PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", string, 100, 1);
}

void PLAY_CHECKPOINT_SOUND()
{
	PLAY_AUDIO_EVENT("FRONTEND_GAME_PICKUP_CHECKPOINT_LAP");
	PLAY_AUDIO_EVENT("FRONTEND_GAME_PICKUP_CHECKPOINT_LAP");
}

void SET_UP_DRAW(int type, float width, float height, uint r, uint g, uint b, uint a)
{
        SET_TEXT_FONT(0);
        SET_TEXT_BACKGROUND(0);
        SET_TEXT_DROPSHADOW(0, 0, 0, 0, 255);
        SET_TEXT_EDGE(0, 0, 0, 0, 255);
        if (type == 1)
        {
                SET_TEXT_BACKGROUND(1);
        }
        else if (type == 2)
        {
                SET_TEXT_DROPSHADOW(1, 0, 0, 0, 255);
        }
        else if (type == 3)
        {
                SET_TEXT_EDGE(1, 0, 0, 0, 255);
        }
        SET_TEXT_COLOUR(r, g, b, a);
        SET_TEXT_SCALE(width, height);
        SET_TEXT_PROPORTIONAL(1);
        SET_TEXT_JUSTIFY(0);
        SET_TEXT_CENTRE(0);
        SET_TEXT_RIGHT_JUSTIFY(0);
}

float DRAW_TEXT(char *gxtName, float x, float y, char *val)
{
        float result;
        result = GET_STRING_WIDTH_WITH_STRING(gxtName, val);
        DISPLAY_TEXT_WITH_LITERAL_STRING(x, y, gxtName, val);
}

void DRAW_NUMBER(char *gxtName, float x, float y, uint val)
{
		DISPLAY_TEXT_WITH_NUMBER(x, y, gxtName, val);
}

void PRINT_MAIN_LOGO(float x, float y, char *string)
{
	SET_UP_DRAW(2, 0.48, 0.78, 255, 255, 255, 240);
	DRAW_TEXT("STRING",  x, y, string);
}

void PRINT_DESC(float x, float y, char *string)
{
	SET_UP_DRAW(2, 0.236, 0.32, 255, 255, 255, 240);
	DRAW_TEXT("STRING",  x, y, string);
}

void SET_VICTIM_GROUP_FOR_PED(uint ptype)
{
	CREATE_GROUP(0, &victimgrp, true);
	GET_PLAYER_GROUP(GetPlayerIndex(), &victimgrp);
	SET_GROUP_MEMBER(victimgrp, ptype);
	SET_CHAR_NEVER_LEAVES_GROUP(ptype, true);
	SET_GROUP_LEADER(victimgrp, GetPlayerPed());
	SET_GROUP_SEPARATION_RANGE(victimgrp, 9999.9);
	SET_GROUP_FORMATION(victimgrp, 3);
	SET_GROUP_FORMATION_SPACING(victimgrp, 4.0);
}

/*
void CREATE_BOXES_INSIDE_CAR(uint num)
{
	REQUEST_MODEL(MODEL_CJ_JOJO_BOX1);

    while(!HAS_MODEL_LOADED(MODEL_CJ_JOJO_BOX1))
    {
        WAIT(0);
    }
	
    CREATE_OBJECT_NO_OFFSET(MODEL_CJ_JOJO_BOX1,  0.18000000, -0.20000000, 0.30000000 - 0.50000000, &box[0], 1);
    ATTACH_OBJECT_TO_CAR(box[0], vehs[num].car, 0, 0.18000000, -0.20000000, 0.30000000, 0.00000000, 0.00000000, 0.00000000);
    CREATE_OBJECT_NO_OFFSET(MODEL_CJ_JOJO_BOX1,  0.05000000, -0.50000000, 0.30000000 - 0.50000000, &box[1], 1);
    ATTACH_OBJECT_TO_CAR(box[1], vehs[num].car, 0, 0.05000000, -0.50000000, 0.30000000, 0.00000000, 0.00000000, 0.00000000);
	CREATE_OBJECT_NO_OFFSET(MODEL_CJ_JOJO_BOX1,  -0.10000000, -1.40000000, 0.30000000 - 0.50000000, &box[2], 1);
    ATTACH_OBJECT_TO_CAR(box[2], vehs[num].car, 0, -0.10000000, -1.40000000, 0.30000000, -1.00000000, 0.00000000, 1.60000000);
	MARK_MODEL_AS_NO_LONGER_NEEDED(MODEL_CJ_JOJO_BOX1);
}
*/

void MISSION_COMPLETE(char *string, int money)
{
	int i;
	
	DRAW_RECT(0.5000, 0.5000, 1.0000, 1.0000, 0, 0, 0, 150);
	SET_PLAYER_CONTROL(GET_PLAYER_ID(), FALSE);
	//DESTROY_ACTORS();
	
	if(TIMERB() != 0 && timerrc == 0)
	{
		SETTIMERB(0);
		PLAY_CHECKPOINT_SOUND();
		timerrc = 1;
	}
	
	if(TIMERB() >= 0 && TIMERB() <= 3000  && timerrc == 1)
	{
		SET_UP_DRAW(2, 0.78, 0.78, 255, 255, 255, 180);
		DRAW_TEXT("STRING",  0.16, 0.35, "MISSION");
		SET_UP_DRAW(2, 2.90, 4.20, 255, 255, 255, 200);
		DRAW_TEXT("STRING",  0.15, 0.40, "PASSED");
	}
	
	else if(TIMERB() > 3000  && timerrc == 1)
	{
		for(i=0;i<=money;i+=500)
		{	
			WAIT(1);
			DRAW_RECT(0.5000, 0.5000, 1.0000, 1.0000, 0, 0, 0, 150);
			SET_UP_DRAW(2, 1.95, 2.00, 255, 255, 255, 150);
			DRAW_TEXT("STRING",  0.34, 0.35, "$");
			SET_UP_DRAW(2, 1.55, 2.00, 255, 255, 255, 150);
			DRAW_NUMBER("NUMBER", 0.42, 0.35, i);
			SET_PLAYER_CONTROL(GET_PLAYER_ID(), FALSE);
		}
		
		if(IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
		{
			GET_CAR_CHAR_IS_USING(GetPlayerPed(), &randomveh);
			STOP_CAR_BREAKING(randomveh, 1);
			TASK_LEAVE_CAR(GetPlayerPed(), randomveh);
			LOCK_CAR_DOORS(randomveh, 2);
		}
		
		SET_SLEEP_MODE_ACTIVE(0);
		ALTER_WANTED_LEVEL(GetPlayerIndex(), 0);
		APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
		TRIGGER_MISSION_COMPLETE_AUDIO(51);
		ADD_SCORE(GetPlayerIndex(), money);
		SET_PLAYER_CONTROL(GET_PLAYER_ID(), TRUE);
		TERMINATE_THIS_SCRIPT();
	}
}

void MISSION_FAILED(char *string)
{
	missionrc = 1;
	DRAW_RECT(0.5000, 0.5000, 1.0000, 1.0000, 0, 0, 0, 150);
	//DESTROY_ACTORS();
	
	if(TIMERB() != 0 && timerrc == 0)
	{
		SETTIMERB(0);
		PLAY_CHECKPOINT_SOUND();
		timerrc = 1;
	}

	if(TIMERB() > 0 && TIMERB() < 3000 && timerrc == 1)
	{
		SET_UP_DRAW(2, 0.78, 0.78, 255, 255, 255, 200);
		DRAW_TEXT("STRING",  0.16, 0.35, "MISSION");
		SET_UP_DRAW(2, 2.90, 4.20, 255, 255, 255, 250);
		DRAW_TEXT("STRING",  0.15, 0.40, "FAILED");
		PRINT_TXT2(string);
	}
		
	if(TIMERB() > 3000 && timerrc == 1)
	{
		SET_SLEEP_MODE_ACTIVE(0);
		
		if(IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
		{
			GET_CAR_CHAR_IS_USING(GetPlayerPed(), &randomveh);
			STOP_CAR_BREAKING(randomveh, 1);
			TASK_LEAVE_CAR(GetPlayerPed(), randomveh);
			LOCK_CAR_DOORS(randomveh, 2);
		}
		
		ALTER_WANTED_LEVEL(GetPlayerIndex(), 0);
		APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
		TERMINATE_THIS_SCRIPT();
	}	
}

void PRINT_LIVES()
{
	HIDE_HELP_TEXT_THIS_FRAME();
	
	if(tlives > 0)
	{
		DRAW_WINDOW_FOR_DESC(0.80, 0.75, 0.16, 0.05, 175);
		SET_UP_DRAW(2, 0.28, 0.31, 255, 255, 255, 200);
		DRAW_TEXT("STRING",  0.82, 0.76, "TEAM LIVES: ");
		SET_UP_DRAW(2, 0.28, 0.31, 255, 255, 255, 200);
		DRAW_NUMBER("NUMBER", 0.93, 0.76, tlives);
	}
	
	if(tlives == 0)
	{
		DRAW_WINDOW_FOR_DESC(0.80, 0.75, 0.16, 0.05, 175); 
		SET_UP_DRAW(2, 0.28, 0.31, 255, 42, 31, 200);
		DRAW_TEXT("STRING",  0.82, 0.76, "TEAM LIVES: ");
		SET_UP_DRAW(2, 0.28, 0.31, 255, 42, 31, 200);
		DRAW_NUMBER("NUMBER", 0.93, 0.76, tlives);
	}
}

void PRINT_TIMER(uint timer)
{
	DRAW_WINDOW_FOR_DESC(0.03, 0.65, 0.16, 0.6, 175);
	SET_UP_DRAW(2, 0.28, 0.31, 255, 255, 255, 150);
	DRAW_TEXT("STRING",  0.04, 0.65, "TIME: ");
	SET_UP_DRAW(2, 0.28, 0.31, 255, 255, 255, 150);
	//DRAW_NUMBER("NUMBER", 0.13, 0.65, timer);	
}

void POLICE(int police, int maxwanted)
{
	
	if(police == 0)
	{
		ALTER_WANTED_LEVEL(GetPlayerIndex(), 0);
		APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
		SET_CHAR_WANTED_BY_POLICE(GetPlayerPed(), FALSE);
		SET_POLICE_IGNORE_PLAYER(GetPlayerIndex(), TRUE);
		SET_WANTED_MULTIPLIER(0.00000000);
		SET_MAX_WANTED_LEVEL(0);
		SET_CREATE_RANDOM_COPS(0);
		SWITCH_POLICE_HELIS(0);
	}
	
	if(police == 1)
	{
		SET_POLICE_IGNORE_PLAYER(GetPlayerIndex(), FALSE);
		SET_MAX_WANTED_LEVEL(maxwanted);
		SET_CREATE_RANDOM_COPS(1);
		SWITCH_POLICE_HELIS(1);
	}
}

void INIT_SETTINGS(float x, float y, float z, float h)
{
	if(IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
	{
		GET_CAR_CHAR_IS_USING(GetPlayerPed(), &randomveh);
		REMOVE_CHAR_FROM_CAR_MAINTAIN_POSITION(GetPlayerPed(), randomveh);
	}
	
	ALLOW_EMERGENCY_SERVICES(TRUE);
	ALTER_WANTED_LEVEL(GetPlayerIndex(), 0);
	APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
	GIVE_WEAPON_TO_CHAR(GetPlayerPed(), WEAPON_BASEBALLBAT, 0, 0);
	GIVE_WEAPON_TO_CHAR(GetPlayerPed(), WEAPON_GRENADE, 25, 0);
	GIVE_WEAPON_TO_CHAR(GetPlayerPed(), WEAPON_SNIPERRIFLE, 40, 0);
	GIVE_WEAPON_TO_CHAR(GetPlayerPed(), WEAPON_RLAUNCHER, 4, 0);
	GIVE_WEAPON_TO_CHAR(GetPlayerPed(), WEAPON_MP5, 2000, 0);
	GIVE_WEAPON_TO_CHAR(GetPlayerPed(), WEAPON_DEAGLE, AMMO_MAX, 0);
	GIVE_WEAPON_TO_CHAR(GetPlayerPed(), WEAPON_M4, 1500, 1);
	
	SET_CHAR_WILL_FLY_THROUGH_WINDSCREEN(GetPlayerPed(), FALSE);
	SET_SLEEP_MODE_ACTIVE(1);
	CHANGE_PICKUP_BLIP_PRIORITY(1);
    CHANGE_PICKUP_BLIP_COLOUR(3);
    CHANGE_PICKUP_BLIP_DISPLAY(4);
	SET_MISSION_FLAG(1);
	SET_CAR_DENSITY_MULTIPLIER(1.0);
	SET_PED_DENSITY_MULTIPLIER(1.0);
	SET_RANDOM_CAR_DENSITY_MULTIPLIER(1.0);
	SET_PARKED_CAR_DENSITY_MULTIPLIER(1.0);
	SET_INT_STAT(STAT_ISLANDS_UNLOCKED, 3);
	OVERRIDE_NEXT_RESTART(x, y, z-2.0, h);
	GTAV_TELEPORT(x, y);
	SET_CHAR_HEADING(GetPlayerPed(), h);
}

void SPAWN_PICKUP(uint pickuptype, Pickup pickupname, uint model, float x, float y, float z)
{
	CREATE_PICKUP(pickuptype, 22, x, y, z, &pickupname, 1);
}

void SPAWN_CHECKPOINT(uint blipnum, float x, float y, float z)
{
	uint num;
	GENERATE_RANDOM_INT_IN_RANGE(blipnum, blipnum, &num);	
	
	if(!DOES_BLIP_EXIST(vehs[num].checkpoint))
	{
		ADD_BLIP_FOR_COORD(x, y, z, &vehs[num].checkpoint);
		CHANGE_BLIP_ALPHA(vehs[num].checkpoint, 255);
		CHANGE_BLIP_COLOUR(vehs[num].checkpoint, 14);
		CHANGE_BLIP_PRIORITY(vehs[num].checkpoint, 1);
		SET_ROUTE(vehs[num].checkpoint, 1);
	}
}

void ADD_CAR_BLIP(int num, uint blipnum)
{
	ADD_BLIP_FOR_CAR(vehs[num].car, &vehs[num].vblip);
	CHANGE_BLIP_COLOUR(vehs[num].vblip, blipnum);
}

void SET_MISSION_CHECKPOINT(uint num, float x, float y, float z, float radius, char *string)
{
	GET_DISTANCE_BETWEEN_COORDS_3D(x, y, z, px, py, pz, &distblip);
	
	if(!DOES_BLIP_EXIST(vehs[num].checkpoint) && CHECK_WANTED_LEVEL() == 0)
	{
		ADD_BLIP_FOR_COORD(x, y, z, &vehs[num].checkpoint);
		CHANGE_BLIP_ALPHA(vehs[num].checkpoint, 255);
		CHANGE_BLIP_COLOUR(vehs[num].checkpoint, 14);
		CHANGE_BLIP_PRIORITY(vehs[num].checkpoint, 1);
		SET_ROUTE(vehs[num].checkpoint, 1);
	}

	if(DOES_BLIP_EXIST(vehs[num].checkpoint) && CHECK_WANTED_LEVEL() == 0)
	{
		DRAW_CHECKPOINT_WITH_ALPHA(x, y, z, radius, 255, 225, 31, 240);
		PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", string, 100, 1);
		PRINT_TXT(string);
	}
	
	if(DOES_BLIP_EXIST(vehs[num].checkpoint) && distblip <= radius+5.0 && CHECK_WANTED_LEVEL() == 0)
	{
		SET_ROUTE(vehs[num].checkpoint, 0);
		REMOVE_BLIP(vehs[num].checkpoint);	
		PLAY_CHECKPOINT_SOUND();
		objrc++;
	}
	
	if(CHECK_WANTED_LEVEL() == 1)
	{
		if(DOES_BLIP_EXIST(vehs[num].checkpoint))
		{
			SET_ROUTE(vehs[num].checkpoint, 0);
			REMOVE_BLIP(vehs[num].checkpoint);	
		}
	}
}

void SET_MISSION_CHECKPOINT_BIG_RADIUS(uint num, float x, float y, float z, float radius, char *string)
{
	GET_DISTANCE_BETWEEN_COORDS_3D(x, y, z, px, py, pz, &distblip);
	
	if(!DOES_BLIP_EXIST(vehs[num].checkpoint) && CHECK_WANTED_LEVEL() == 0)
	{
		ADD_BLIP_FOR_COORD(x, y, z, &vehs[num].checkpoint);
		CHANGE_BLIP_ALPHA(vehs[num].checkpoint, 255);
		CHANGE_BLIP_COLOUR(vehs[num].checkpoint, 14);
		CHANGE_BLIP_PRIORITY(vehs[num].checkpoint, 1);
		SET_ROUTE(vehs[num].checkpoint, 1);
	}

	if(DOES_BLIP_EXIST(vehs[num].checkpoint) && CHECK_WANTED_LEVEL() == 0)
	{
		DRAW_CHECKPOINT_WITH_ALPHA(x, y, z, radius, 255, 225, 31, 240);
		PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", string, 100, 1);
		PRINT_TXT(string);
	}
	
	if(DOES_BLIP_EXIST(vehs[num].checkpoint) && distblip <= radius+95.0 && CHECK_WANTED_LEVEL() == 0)
	{
		SET_ROUTE(vehs[num].checkpoint, 0);
		REMOVE_BLIP(vehs[num].checkpoint);	
		PLAY_CHECKPOINT_SOUND();
		objrc++;
	}
	
	if(CHECK_WANTED_LEVEL() == 1)
	{
		if(DOES_BLIP_EXIST(vehs[num].checkpoint))
		{
			SET_ROUTE(vehs[num].checkpoint, 0);
			REMOVE_BLIP(vehs[num].checkpoint);	
		}
	}
}

void SET_MISSION_CHECKPOINT_CUSTOM(uint num, float x, float y, float z, float radius, char *string)
{
	GET_DISTANCE_BETWEEN_COORDS_3D(x, y, z, px, py, pz, &distblip);
	
	if(!DOES_BLIP_EXIST(vehs[num].checkpoint))
	{
		ADD_BLIP_FOR_COORD(x, y, z, &vehs[num].checkpoint);
		CHANGE_BLIP_ALPHA(vehs[num].checkpoint, 255);
		CHANGE_BLIP_COLOUR(vehs[num].checkpoint, 14);
		CHANGE_BLIP_PRIORITY(vehs[num].checkpoint, 1);
		SET_ROUTE(vehs[num].checkpoint, 1);
	}

	if(DOES_BLIP_EXIST(vehs[num].checkpoint))
	{
		DRAW_CHECKPOINT_WITH_ALPHA(x, y, z, radius, 255, 225, 31, 240);
		PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", string, 100, 1);
	}
	
	if(DOES_BLIP_EXIST(vehs[num].checkpoint) && distblip <= radius+5.0)
	{
		SET_ROUTE(vehs[num].checkpoint, 0);
		REMOVE_BLIP(vehs[num].checkpoint);	
	}
}

void SET_MISSION_CHECKPOINT_NO_TEXT(uint blipnum, float x, float y, float z, float radius)
{
	uint num;
	GENERATE_RANDOM_INT_IN_RANGE(blipnum, blipnum, &num);
	
	GET_DISTANCE_BETWEEN_COORDS_3D(x, y, z, px, py, pz, &distblip);

	if(DOES_BLIP_EXIST(vehs[num].checkpoint))
	{
		DRAW_CHECKPOINT_WITH_ALPHA(x, y, z, radius, 255, 225, 31, 240);
	}
	
	if(DOES_BLIP_EXIST(vehs[num].checkpoint) && distblip <= radius+2.0)
	{
		if(IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
		{
			GET_CAR_CHAR_IS_USING(GetPlayerPed(), &randomveh);
			STOP_CAR_BREAKING(randomveh, 1);
			TASK_LEAVE_CAR(GetPlayerPed(), randomveh);
			LOCK_CAR_DOORS(randomveh, 2);
		}
		
		SET_ROUTE(vehs[num].checkpoint, 0);
		REMOVE_BLIP(vehs[num].checkpoint);	
		PLAY_CHECKPOINT_SOUND();
		objrc++;
	}
}

void ADD_ACTOR_BLIP(uint num, ColourIndex colour)
{
	if(!DOES_BLIP_EXIST(peds[num].pblip))
	{
		if(DOES_CHAR_EXIST(peds[num].actor))
		{
			ADD_BLIP_FOR_CHAR(peds[num].actor, &peds[num].pblip);
			SET_BLIP_AS_FRIENDLY(peds[num].pblip, FALSE);
			CHANGE_BLIP_NAME_FROM_ASCII(peds[num].pblip, "Enemy");
			CHANGE_BLIP_ALPHA(peds[num].pblip, 255);
			CHANGE_BLIP_COLOUR(peds[num].pblip, colour);
		}
	}
}

void SPAWN_ACTOR(uint pednum, uint model, uint wep, uint blipnum, int accuracy, int health, int armour, float sense, float x, float y, float z, float h, int role)
{
	uint num, cash;
	GENERATE_RANDOM_INT_IN_RANGE(pednum, pednum, &num);
	peds[num].sense = sense;
	
	if(!DOES_CHAR_EXIST(peds[num].actor))
	{
		REQUEST_MODEL(model);
		while (!HAS_MODEL_LOADED(model)) WAIT(0);
		CREATE_CHAR(16, model, x, y, z, &peds[num].actor, true);
		SET_CHAR_HEADING(peds[num].actor, h);
		
		if(role == 0)
		{
			SET_CHAR_AS_ENEMY(peds[num].actor, TRUE);
			SET_CHAR_RELATIONSHIP_GROUP(peds[num].actor, 24);
			SET_CHAR_RELATIONSHIP(peds[num].actor, 5, 0);
		}
		
		if(role == 1)
		{
			SET_CHAR_AS_ENEMY(peds[num].actor, FALSE);
		}
		
		SET_CHAR_WANTED_BY_POLICE(peds[num].actor, FALSE);
		SET_CHAR_ACCURACY(peds[num].actor, accuracy);
		ADD_ARMOUR_TO_CHAR(peds[num].actor, armour);
		BLOCK_COWERING_IN_COVER(peds[num].actor, true);
		SET_SENSE_RANGE(peds[num].actor, sense);
		SET_CHAR_WANTED_BY_POLICE(peds[num].actor, FALSE);
		SET_PED_DONT_DO_EVASIVE_DIVES(peds[num].actor, TRUE);
		SET_CHAR_WILL_USE_CARS_IN_COMBAT(peds[num].actor, FALSE);
		SET_CHAR_RANDOM_COMPONENT_VARIATION(peds[num].actor);
		SET_CHAR_ONLY_DAMAGED_BY_PLAYER(peds[num].actor, FALSE);
		SET_CHAR_WILL_MOVE_WHEN_INJURED(peds[num].actor, TRUE);
		SET_CHAR_WILL_USE_COVER(peds[num].actor, TRUE);
		SET_CHAR_KEEP_TASK(peds[num].actor, TRUE);
		SET_PED_DIES_WHEN_INJURED(peds[num].actor, TRUE);
		SET_PED_GENERATES_DEAD_BODY_EVENTS(peds[num].actor, TRUE);
		GENERATE_RANDOM_INT_IN_RANGE(10, 100, &cash);
		UPDATE_WEAPON_OF_PED(peds[num].actor, wep);
		SET_CHAR_ACCURACY(peds[num].actor, accuracy);
		SET_CHAR_SHOOT_RATE(peds[num].actor, srate);
		SET_CHAR_FIRE_DAMAGE_MULTIPLIER(peds[num].actor, fdamage);
		SET_CHAR_CURRENT_WEAPON_VISIBLE(peds[num].actor, TRUE);
		MARK_MODEL_AS_NO_LONGER_NEEDED(model);
		TASK_STAND_STILL(peds[num].actor, 100);
		
		if(blipnum != 15)
		{
			ADD_BLIP_FOR_CHAR(peds[num].actor, &peds[num].pblip);
			
			if(role == 0)
			{
				SET_BLIP_AS_FRIENDLY(peds[num].pblip, FALSE);
				CHANGE_BLIP_NAME_FROM_ASCII(peds[num].pblip, "Enemy");
			}
			
			CHANGE_BLIP_COLOUR(peds[num].pblip, blipnum);
			CHANGE_BLIP_ALPHA(peds[num].pblip, 255);
		}
		
		peds[num].retc = 1;
	}
}

void SPAWN_ACTOR_INSIDE_CAR(uint pednum, uint vehnum, uint seat, uint model, uint wep, uint blipnum, uint accuracy, uint health, uint armour, float sense, uint role)
{
	uint num1, num2, cash;
	GENERATE_RANDOM_INT_IN_RANGE(pednum, pednum, &num1);
	GENERATE_RANDOM_INT_IN_RANGE(vehnum, vehnum, &num2);
	peds[num1].sense = sense;
	peds[num1].seat  = seat;
	
	REQUEST_MODEL(model);
	while (!HAS_MODEL_LOADED(model)) WAIT(0);
	
	if(seat == 10) // Driver
	{
		CREATE_CHAR_INSIDE_CAR(vehs[num2].car, 16, model, &peds[num1].actor);
	}
	
	if(seat >= 0 && seat <= 2) // Passenger
	{
		if(IS_CAR_PASSENGER_SEAT_FREE(vehs[num2].car, seat))
		{
			CREATE_CHAR_AS_PASSENGER(vehs[num2].car, 16, model, seat, &peds[num1].actor);
		}
	}
	
	if(role == 0)
	{
		//SET_CHAR_AS_ENEMY(peds[num1].actor, TRUE);
		SET_CHAR_RELATIONSHIP_GROUP(peds[num1].actor, 24);
		SET_CHAR_RELATIONSHIP(peds[num1].actor, 5, 0);
	}
	
	SET_CHAR_WANTED_BY_POLICE(peds[num1].actor, FALSE);
	SET_CHAR_ACCURACY(peds[num1].actor, accuracy);
	ADD_ARMOUR_TO_CHAR(peds[num1].actor, armour);
	BLOCK_COWERING_IN_COVER(peds[num1].actor, true);
	SET_SENSE_RANGE(peds[num1].actor, sense);
	SET_CHAR_WANTED_BY_POLICE(peds[num1].actor, FALSE);
	SET_PED_DONT_DO_EVASIVE_DIVES(peds[num1].actor, TRUE);
	//SET_CHAR_WILL_USE_CARS_IN_COMBAT(peds[num1].actor, TRUE);
	SET_CHAR_WILL_LEAVE_CAR_IN_COMBAT(peds[num1].actor, FALSE);
	SET_CHAR_WILL_DO_DRIVEBYS(peds[num1].actor, TRUE);
	SET_CHAR_RANDOM_COMPONENT_VARIATION(peds[num1].actor);
	SET_CHAR_ONLY_DAMAGED_BY_PLAYER(peds[num1].actor, FALSE);
	SET_CHAR_WILL_MOVE_WHEN_INJURED(peds[num1].actor, TRUE);
	SET_CHAR_WILL_USE_COVER(peds[num1].actor, TRUE);
	SET_CHAR_KEEP_TASK(peds[num1].actor, TRUE);
	SET_PED_DIES_WHEN_INJURED(peds[num1].actor, TRUE);
	SET_PED_GENERATES_DEAD_BODY_EVENTS(peds[num1].actor, TRUE);
	GENERATE_RANDOM_INT_IN_RANGE(10, 200, &cash);
	UPDATE_WEAPON_OF_PED(peds[num1].actor, wep);
	SET_CHAR_ACCURACY(peds[num1].actor, accuracy);
	SET_CHAR_SHOOT_RATE(peds[num1].actor, 100);
	SET_CHAR_FIRE_DAMAGE_MULTIPLIER(peds[num1].actor, 3.0);
	MARK_MODEL_AS_NO_LONGER_NEEDED(model);
	
	if(blipnum != 15)
	{
		ADD_BLIP_FOR_CHAR(peds[num1].actor, &peds[num1].pblip);
			
		if(role == 0)
		{
			SET_BLIP_AS_FRIENDLY(peds[num1].pblip, FALSE);
			CHANGE_BLIP_NAME_FROM_ASCII(peds[num1].pblip, "Enemy");
		}
			
		CHANGE_BLIP_COLOUR(peds[num1].pblip, blipnum);
		CHANGE_BLIP_ALPHA(peds[num1].pblip, 255);
	}
	
	peds[num1].retc = 1;
}	

void SPAWN_VEHICLE(uint num, uint model, uint blipnum, float x, float y, float z, float h, uint health, uint tyre)
{
	REQUEST_MODEL(model);
	while (!HAS_MODEL_LOADED(model)) WAIT(0); 
	CREATE_CAR(model, x, y, z, &vehs[num].car, true);
	SET_CAN_BURST_CAR_TYRES(vehs[num].car, tyre);
	SET_CAR_HEADING(vehs[num].car, h);
	SET_CAR_HEALTH(vehs[num].car, health);
	
	if(blipnum != 15 && num != 0)
	{
		ADD_BLIP_FOR_CAR(vehs[num].car, &vehs[num].vblip);
		CHANGE_BLIP_COLOUR(vehs[num].vblip, blipnum);
	}
	
	if(num == 0)
	{
		if(level == 0 || level == 1)
		{
			SET_CAR_CAN_BE_DAMAGED(vehs[num].car, FALSE);
		}
		
		else if(level == 2)
		{
			SET_CAR_CAN_BE_DAMAGED(vehs[num].car, TRUE);
		}
		
		ADD_BLIP_FOR_CAR(vehs[num].car, &vehs[num].vblip);
		CHANGE_BLIP_ALPHA(vehs[num].vblip, 255);
		CHANGE_BLIP_COLOUR(vehs[num].vblip, 0);
		CHANGE_BLIP_SPRITE(vehs[num].vblip, BLIP_TAXI_RANK);
		CHANGE_BLIP_NAME_FROM_ASCII(vehs[num].vblip, "Your car");
	}
	
	MARK_MODEL_AS_NO_LONGER_NEEDED(model);	
	vehs[num].retc = 1;
}

void DEBUG_MISSION()
{
	if(IS_PLAYER_PRESSING_HORN(GetPlayerIndex()))
	{
		objrc++;
		WAIT(1000);
	}
}

void MANAGE_ACTORS(uint num)
{
	int i, j; 
	
	for(i=0;i<=num;i++)
	{
		if(DOES_CHAR_EXIST(peds[i].actor))
		{
			if(peds[i].retc == 1)
			{
				if(IS_CHAR_DEAD(peds[i].actor))
				{
					if(peds[i].objhash != 0)
					{		
						GET_DEAD_CHAR_PICKUP_COORDS(peds[i].actor, &PKx, &PKy, &PKz);
						CREATE_PICKUP(peds[i].objhash, 22, PKx, PKy, PKz, &peds[i].object, 1);
						peds[i].objretc = 1;
					}
					
					EXPLODE_CHAR_HEAD(peds[i].actor);
					TASK_DIE(peds[i].actor);
					REMOVE_BLIP(peds[i].pblip);
					MARK_CHAR_AS_NO_LONGER_NEEDED(&peds[i].actor);
					peds[i].retc = 2;
				}
				
				if(!IS_CHAR_DEAD(peds[i].actor))
				{
					if(IS_PED_IN_COMBAT(peds[i].actor) || IS_CHAR_TOUCHING_CHAR(GetPlayerPed(), peds[i].actor) || HAS_CHAR_BEEN_DAMAGED_BY_CHAR(peds[i].actor, GetPlayerPed(), 0) || IS_PLAYER_TARGETTING_CHAR(GetPlayerIndex(), peds[i].actor) || HAS_CHAR_BEEN_DAMAGED_BY_CHAR(peds[i].actor, GetPlayerPed(), 0) || IS_PLAYER_FREE_AIMING_AT_CHAR(GetPlayerIndex(), peds[i].actor))
					{
						for(j=0;j<=num;j++)
						{
							if(DOES_CHAR_EXIST(peds[j].actor))
							{
								if(peds[j].sense != 100 && peds[j].seat != 10)
								{
									if(!DOES_BLIP_EXIST(peds[j].pblip))
									{
										ADD_ACTOR_BLIP(j, BLIP_COLOR_RED);
									}
									
									peds[j].sense = 100;
									SET_SENSE_RANGE(peds[j].actor, peds[j].sense);
								}
							}
						}
					}
				}
			}
		}
	}
}

void CLEAR_ZONE(float x, float y, float z, float radius)
{
	CLEAR_AREA_OF_CARS(x, y, z, radius);
	CLEAR_AREA_OF_CHARS(x, y, z, radius);
	CLEAR_AREA_OF_OBJECTS(x, y, z, radius);
}

void MANAGE_PLAYER()
{
	if(IS_PLAYER_DEAD(GetPlayerIndex()) && tlivesrc == 0)
	{
		tlivesrc = 1;
		GET_NEXT_CLOSEST_CAR_NODE_WITH_HEADING(px, py, pz, &vehx, &vehy, &vehz, &vehh);
		//OVERRIDE_NEXT_RESTART(px, py, pz, ph);
		OVERRIDE_NEXT_RESTART(vehx, vehy, vehz, vehh);
	}
	
	if(IS_PLAYER_PLAYING(GetPlayerIndex()) && tlivesrc == 1)
	{
		tlives--;
		GET_NEXT_CLOSEST_CAR_NODE_WITH_HEADING(px, py, pz, &vehx, &vehy, &vehz, &vehh);
		//OVERRIDE_NEXT_RESTART(px, py, pz, ph);
		OVERRIDE_NEXT_RESTART(vehx, vehy, vehz, vehh);
		tlivesrc=0;
	}
	
	if(tlives == -1)
	{
		MISSION_FAILED("~R~Out of lives!~S~");
	}
}


void MANAGE_VEHICLES(uint num)
{
	int i;
	
	for(i=0;i<=num;i++)
	{
		if(vehs[i].retc != 2)
		{
			if(DOES_VEHICLE_EXIST(vehs[i].car))
			{
				if(IS_CAR_DEAD(vehs[i].car) || IS_CAR_ON_FIRE(vehs[i].car))
				{
					if(DOES_BLIP_EXIST(vehs[i].vblip))
					{
						REMOVE_BLIP(vehs[i].vblip);
					}
					
					vehs[i].retc = 2;
					MARK_CAR_AS_NO_LONGER_NEEDED(&vehs[i].car);
				}
			}
		}
	}
}

void MANAGE_UNIQUE_VEHICLE_STATUS(uint num)
{
	if(vehs[num].retc == 2)
	{
		objrc=999;
		MISSION_FAILED("~R~Vehicle destroyed!~S~");
	}
}

void MANAGE_UNIQUE_ACTOR_STATUS(uint num)
{
	if(peds[num].retc == 2)
	{
		objrc=999;
		MISSION_FAILED("~R~Friendly killed!~S~");
	}
}

void GOTO_LOCATION_WITH_VEHICLE(uint vehnum, uint blipnum, float x, float y, float z, char *string, char *string2)
{
	if(DOES_VEHICLE_EXIST(vehs[vehnum].car))
	{
		if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[vehnum].car))
		{
			PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", string, 100, 1);
			
			if(!DOES_BLIP_EXIST(vehs[blipnum].checkpoint))
			{
				SPAWN_CHECKPOINT(blipnum, x, y, z);
			}
			
			SET_MISSION_CHECKPOINT_NO_TEXT(blipnum, x, y, z, 4.0);
		}
		
		else if(!IS_CHAR_IN_CAR(GetPlayerPed(), vehs[vehnum].car))
		{
			if(DOES_BLIP_EXIST(vehs[blipnum].checkpoint))
			{
				REMOVE_BLIP(vehs[blipnum].checkpoint);
			}
			
			PRINT_TXT(string2);
		}
		
		if(IS_CAR_ON_FIRE(vehs[vehnum].car) || IS_CAR_DEAD(vehs[vehnum].car))
		{
			MISSION_FAILED("~R~The vehicle has been destroyed~S~");
		}	
	}
}

void GOTO_LOCATION_WITH_VEHICLE_NOTEXT(uint vehnum, uint blipnum, float x, float y, float z)
{
	if(DOES_VEHICLE_EXIST(vehs[vehnum].car))
	{
		if(IS_CHAR_IN_CAR(GetPlayerPed(), vehs[vehnum].car))
		{
			
			if(!DOES_BLIP_EXIST(vehs[blipnum].checkpoint))
			{
				SPAWN_CHECKPOINT(blipnum, x, y, z);
			}
			
			SET_MISSION_CHECKPOINT_NO_TEXT(blipnum, x, y, z, 4.0);
		}
		
		else if(!IS_CHAR_IN_CAR(GetPlayerPed(), vehs[vehnum].car))
		{
			if(DOES_BLIP_EXIST(vehs[blipnum].checkpoint))
			{
				REMOVE_BLIP(vehs[blipnum].checkpoint);
			}
		}
		
		if(IS_CAR_ON_FIRE(vehs[vehnum].car) || IS_CAR_DEAD(vehs[vehnum].car))
		{
			MISSION_FAILED("~R~The vehicle has been destroyed~S~");
		}	
	}
}


void GO_AFTER_PLAYER_WITH_VEHICLE(uint e_num, uint v_num)
{	
	if(DOES_CHAR_EXIST(peds[e_num].actor))
	{
		if(DOES_VEHICLE_EXIST(vehs[v_num].car))
		{
			if(IS_CHAR_SITTING_IN_CAR(peds[e_num].actor, vehs[v_num].car))
			{
				TASK_CAR_MISSION_PED_TARGET(peds[e_num].actor, vehs[v_num].car, GetPlayerPed(), 2, 30.0, 2, 0, 10);
			}
		}
	}
}

void DRIVE_TO_LOCATION_WITH_VEHICLE(uint e_num, uint v_num, float x, float y, float z, float speed)
{	
	if(DOES_CHAR_EXIST(peds[e_num].actor))
	{
		if(DOES_VEHICLE_EXIST(vehs[v_num].car))
		{
			if(IS_CHAR_SITTING_IN_CAR(peds[e_num].actor, vehs[v_num].car))
			{
				TASK_CAR_MISSION_COORS_TARGET(peds[e_num].actor, vehs[v_num].car, x, y, z, 4, speed, 2, 0, 10);
			}
		}
	}
}

void MANAGE_PICKUP(int num)
{
	if(HAS_PICKUP_BEEN_COLLECTED(peds[num].object))
	{
		peds[num].objretc = 2;
	}
}

void SPAWN_ENEMY_CAR_IN_AREA(uint modelveh, float x, float y, float z, uint vnum, uint enum1, uint enum2, uint modelped)
{
	if(LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), x, y, z, 130.00000000, 130.00000000, 130.00000000, 0) && !DOES_VEHICLE_EXIST(vehs[vnum].car) && vehs[vnum].retc != 2)
	{
		GET_NEXT_CLOSEST_CAR_NODE_WITH_HEADING(x, y, z, &vehx, &vehy, &vehz, &vehh);
		SPAWN_VEHICLE(vnum, modelveh, NOBLIP, vehx, vehy, vehz, vehh, vhealth, 1);
		SPAWN_ACTOR_INSIDE_CAR(enum1, vnum, 10, modelped, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
		SPAWN_ACTOR_INSIDE_CAR(enum2, vnum, 0,  modelped, WEAPON_MP5, BLIP_COLOR_RED, accuracy, ehealth, armour, 100, 0);
		GO_AFTER_PLAYER_WITH_VEHICLE(enum1, vnum);
	}
}