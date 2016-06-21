// GTA V Online Mission for IV
// Mission: Deal Breaker II
// Created by rodd1981 (rod.assis@gmail.com)
// http://gtaforums.com/topic/776716-gta-iv-mission-mod-pack-v10/
// Source Code from: https://github.com/rodd1981/GTA-IV-Mission-Mod-Pack

#include "lib/functions.c"
#include "lib/missmenu.c"
#define objstart 0
#define objend   33
Pickup meth;
float zg;

void main(void)
{
	int i;
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("scriptmgr");
	CLEAR_ZONE(-1401.54, 1460.03, 25.228, 200.0);
	INIT_SETTINGS(-1401.54, 1460.03, 25.228, 181.0);
	ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(1);

	while (TRUE)
    {
		WAIT(0);
		GET_CHAR_COORDINATES(GetPlayerPed(), &px, &py, &pz);
		GET_CHAR_HEADING(GetPlayerPed(), &ph);
		
		if(objrc == 0)
		{
			DRAW_MENU();
			PRINT_MAIN_LOGO(0.36, 0.05, "Deal Breaker 2");
			PRINT_DESC(0.17, 0.11, "Kenny Petrovic wants your help again! Break several gang deals around the city, steal the meths and");
			PRINT_DESC(0.17, 0.13, "bring it back to Petrovic!");		
		}
		
		if(objrc > objstart && objrc != objend)
		{
			PRINT_LIVES();
			POLICE(0, 0);
			MANAGE_PLAYER();
			MANAGE_ACTORS(25);
			MANAGE_VEHICLES(8);
		}
		
		if(objrc == 1)
		{
			UNLOCK_FRONTEND_DISPLAYS();
			APPLY_SELECTED_OPTIONS(level, weather, time);
			SPAWN_VEHICLE(0, vehmodel, BLIP_COLOR_WHITE, -1402.31, 1448.91, 25.2095, 260.0, 25000, 0);
			SPAWN_ACTOR(0,  MODEL_M_Y_GALB_LO_01, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -235.245, 736.191, 7.17629, 359.00, 0);
			SPAWN_ACTOR(1,  MODEL_M_Y_GALB_LO_02, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -242.534, 751.594, 7.17629, 180.00, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_GALB_LO_03, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -224.212, 733.745, 7.17629, 359.00, 0);
			SPAWN_ACTOR(3,  MODEL_M_M_GJAM_HI_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -252.282, 734.633, 7.17629, 359.00, 0);
			SPAWN_ACTOR(4,  MODEL_M_Y_GJAM_LO_01, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -240.564, 757.853, 7.17629, 359.00, 0);
			SPAWN_ACTOR(5,  MODEL_M_M_GJAM_HI_02, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -213.845, 770.489, 7.17656, 180.00, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_GALB_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -247.049, 743.071, 7.17629, 180.00, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_GALB_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -237.965, 736.233, 7.17629, 359.00, 0);
			SPAWN_ACTOR(8,  MODEL_M_M_GJAM_HI_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -232.166, 750.679, 7.1763,  180.00, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_GJAM_LO_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -223.334, 743.824, 7.1763,  180.00, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_GALB_LO_02, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -217.599, 732.528, 7.17629, 359.00, 0);
			SPAWN_ACTOR(11, MODEL_M_Y_GALB_LO_03, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -232.218, 736.181, 7.17629, 359.00, 0);
			SPAWN_ACTOR(12, MODEL_M_Y_GJAM_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -220.533, 744.745, 7.17629, 359.00, 0);
			SPAWN_ACTOR(13, MODEL_M_M_GJAM_HI_02, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -216.215, 749.206, 7.17656, 359.00, 0);
			SPAWN_ACTOR(14, MODEL_M_Y_GALB_LO_01, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -222.783, 757.124, 7.17629, 359.00, 0);
			SPAWN_ACTOR(15, MODEL_M_Y_GALB_LO_02, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -232.206, 738.876, 7.17629, 180.00, 0);
			SPAWN_ACTOR(16, MODEL_M_Y_GALB_LO_03, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -252.451, 742.294, 7.17629, 359.00, 0);
			SPAWN_ACTOR(17, MODEL_M_M_GJAM_HI_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -250.118, 754.883, 7.1763,  359.00, 0);
			SPAWN_ACTOR(18, MODEL_M_Y_GJAM_LO_01, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -248.534, 763.041, 7.17629, 359.00, 0);
			SPAWN_ACTOR(19, MODEL_M_M_GJAM_HI_02, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -235.108, 738.577, 7.16745, 180.00, 0);
			SPAWN_ACTOR(20, MODEL_M_Y_GALB_LO_01, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -257.487, 770.534, 7.17656, 180.00, 0);
			SPAWN_ACTOR(21, MODEL_M_Y_GALB_LO_02, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -251.491, 770.231, 7.17656, 180.00, 0);
			SPAWN_ACTOR(22, MODEL_M_M_GJAM_HI_01, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -218.769, 769.511, 7.17656, 180.00, 0);
			SPAWN_ACTOR(23, MODEL_M_Y_GJAM_LO_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -238.347, 738.48,  7.17629, 180.00, 0);
			if(level == 2) SPAWN_ACTOR(24, MODEL_M_Y_GALB_LO_01, WEAPON_RLAUNCHER, NOBLIP, accuracy, ehealth, armour, 10, -235.431, 767.386, 11.0087, 180.00, 0);
			PLAY_CHECKPOINT_SOUND();
			objrc++;
		}
		
		if(objrc == 2)
		{
			SET_MISSION_CHECKPOINT_BIG_RADIUS(0, -235.245, 736.191, 5.17629, 5.0, "Go to ~Y~the 1st deal~S~");
		}
		
		if(objrc == 3)
		{
			GET_GROUND_Z_FOR_3D_COORD(-235.245, 736.191, 7.17629, &zg);
			CREATE_PICKUP(drugbag, 22, -235.245, 736.191, zg, &meth, 1);
			objrc++;
		}
		
		if(objrc == 4)
		{
			PRINT_TXT("Steal the ~b~meth~s~");
			
			if(HAS_PICKUP_BEEN_COLLECTED(meth))
			{
				PLAY_CHECKPOINT_SOUND();
				objrc++;
			}
		}
		
		if(objrc == 5)
		{
			SPAWN_ACTOR(0,  MODEL_M_Y_GBIK_HI_01, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -585.10,  461.91,  21.49,   2.75,   0);
			SPAWN_ACTOR(1,  MODEL_M_M_GBIK_LO_03, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -585.616, 468.715, 21.488,  182.41, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_GBIK_HI_02, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -595.481, 464.74,  21.638,  265.92, 0);
			SPAWN_ACTOR(3,  MODEL_M_Y_GMAF_HI_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -597.163, 455.501, 21.488,  331.00, 0);
			SPAWN_ACTOR(4,  MODEL_M_Y_GMAF_HI_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -605.358, 471.974, 21.6383, 232.00, 0);
			SPAWN_ACTOR(5,  MODEL_M_Y_GMAF_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -588.16,  480.281, 21.638,  232.00, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_GBIK_HI_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -589.336, 469.316, 21.488,  182.41, 0);
			SPAWN_ACTOR(7,  MODEL_M_M_GBIK_LO_03, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -587.28,  462.54,  21.49,   329.31, 0);
			SPAWN_ACTOR(8,  MODEL_M_Y_GMAF_HI_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -581.9,   470.367, 21.488,  182.41, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_GMAF_HI_02, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -594.351, 472.798, 21.488,  228.75, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_GBIK_HI_02, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -594.962, 467.802, 21.488,  264.23, 0);
			SPAWN_ACTOR(11, MODEL_M_M_GBIK_LO_03, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -582.63,  462.93,  21.49,   37.72, 0);
			SPAWN_ACTOR(12, MODEL_M_Y_GMAF_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -581.293, 464.782, 21.638,  260.44, 0);
			SPAWN_ACTOR(13, MODEL_M_Y_GBIK_HI_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -581.293, 464.782, 21.638,  260.44, 0);
			SPAWN_ACTOR(14, MODEL_M_M_GBIK_LO_03, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -601.837, 459.914, 21.488,  331.00, 0);
			SPAWN_ACTOR(15, MODEL_M_Y_GBIK_HI_02, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -582.96,  464.90,  21.64,   184.16, 0);
			SPAWN_ACTOR(16, MODEL_M_Y_GMAF_HI_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -593.067, 455.576, 21.488,  331.00, 0);
			SPAWN_ACTOR(17, MODEL_M_Y_GMAF_HI_02, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -585.751, 454.634, 21.488,  11.00,  0);
			SPAWN_ACTOR(18, MODEL_M_Y_GMAF_LO_01, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -580.629, 455.126, 21.488,  11.00,  0);
			SPAWN_ACTOR(19, MODEL_M_Y_GBIK_HI_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -586.00,  452.58,  21.488,  11.00,  0);
			SPAWN_ACTOR(20, MODEL_M_M_GBIK_LO_03, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -585.10,  464.94,  21.64,   182.41, 0);
			SPAWN_ACTOR(21, MODEL_M_Y_GMAF_HI_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -601.034, 475.955, 21.488,  232.00, 0);
			SPAWN_ACTOR(22, MODEL_M_Y_GMAF_HI_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -598.267, 484.205, 21.4879, 232.00, 0);
			SPAWN_ACTOR(23, MODEL_M_Y_GBIK_HI_02, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -587.10,  465.06,  21.64,   175.62, 0);
			if(level == 2) SPAWN_ACTOR(24, MODEL_M_M_GBIK_LO_03, WEAPON_RLAUNCHER, NOBLIP, accuracy, ehealth, armour, 10, -585.918, 475.123, 25.358,  211.00, 0);
			objrc++;
		}
		
		if(objrc == 6)
		{
			SET_MISSION_CHECKPOINT_BIG_RADIUS(0, -585.10,  461.91,  19.49, 5.0, "Go to ~Y~the 2nd deal~S~");
		}
		
		if(objrc == 7)
		{
			GET_GROUND_Z_FOR_3D_COORD(-585.10,  461.91,  21.49, &zg);
			CREATE_PICKUP(drugbag, 22, -585.10,  461.91, zg, &meth, 1);
			objrc++;
		}
		
		if(objrc == 8)
		{
			PRINT_TXT("Steal the ~b~meth~s~");
			
			if(HAS_PICKUP_BEEN_COLLECTED(meth))
			{
				PLAY_CHECKPOINT_SOUND();
				objrc++;
			}
		}
		
		if(objrc == 9)
		{
			SPAWN_ACTOR(0,  MODEL_M_Y_GIRI_LO_01, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -726.821, -192.367, 4.93627, 302.76, 0);
			SPAWN_ACTOR(1,  MODEL_M_Y_GIRI_LO_02, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -722.687, -189.388, 4.94912, 302.12, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_GIRI_LO_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -712.929, -188.191, 4.86609, 310.00, 0);
			SPAWN_ACTOR(3,  MODEL_M_Y_GKOR_LO_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -709.971, -207.208, 4.94753, 177.85, 0);
			SPAWN_ACTOR(4,  MODEL_M_Y_GKOR_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -712.317, -218.202, 4.94551, 177.85, 0);
			SPAWN_ACTOR(5,  MODEL_M_Y_GKOR_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -717.206, -168.593, 5.68585,  77.00, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_GIRI_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -723.622, -187.741, 4.94933, 302.12, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_GIRI_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -727.465, -187.865, 4.94823, 302.76, 0);
			SPAWN_ACTOR(8,  MODEL_M_Y_GKOR_LO_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -721.696, -191.248, 4.94889, 277.00, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_GKOR_LO_02, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -722.454, -195.992, 4.90525, 277.00, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_GIRI_LO_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -714.29,  -193.346, 4.86726, 310.00, 0);
			SPAWN_ACTOR(11, MODEL_M_Y_GIRI_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -725.881, -184.396, 4.94878, 302.76, 0);
			SPAWN_ACTOR(12, MODEL_M_Y_GKOR_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -717.974, -182.595, 5.01987, 310.00, 0);
			SPAWN_ACTOR(13, MODEL_M_Y_GIRI_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -708.091, -186.611, 4.86561, 310.00, 0);
			SPAWN_ACTOR(14, MODEL_M_Y_GIRI_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -700.023, -195.147, 4.86393, 310.00, 0);
			SPAWN_ACTOR(15, MODEL_M_Y_GIRI_LO_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -721.486, -188.825, 4.94839, 128.12, 0);
			SPAWN_ACTOR(16, MODEL_M_Y_GKOR_LO_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -703.412, -208.528, 4.94611, 177.85, 0);
			SPAWN_ACTOR(17, MODEL_M_Y_GKOR_LO_02, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -708.123, -212.965, 4.94753, 177.85, 0);
			SPAWN_ACTOR(18, MODEL_M_Y_GKOR_LO_01, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -720.592, -190.016, 4.94932, 128.12, 0);
			SPAWN_ACTOR(19, MODEL_M_Y_GIRI_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -718.476, -210.586, 4.9453,  177.85, 0);
			SPAWN_ACTOR(20, MODEL_M_Y_GIRI_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -736.037, -180.667, 4.94756, 77.00, 0);
			SPAWN_ACTOR(21, MODEL_M_Y_GKOR_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -733.707, -174.073, 4.94756, 77.00, 0);
			SPAWN_ACTOR(22, MODEL_M_Y_GKOR_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -725.296, -168.395, 4.94402, 77.00, 0);
			SPAWN_ACTOR(23, MODEL_M_Y_GIRI_LO_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -722.278, -186.68,  4.9494,  128.12, 0);
			if(level == 2) SPAWN_ACTOR(24, MODEL_M_Y_GIRI_LO_02, WEAPON_RLAUNCHER, NOBLIP, accuracy, ehealth, armour, 10, -697.079, -184.312, 4.86222, 77.00, 0);
			objrc++;
		}
		
		if(objrc == 10)
		{
			SET_MISSION_CHECKPOINT_BIG_RADIUS(0, -726.821, -192.367, 2.93627, 5.0, "Go to ~Y~the 3rd deal~S~");
		}
		
		if(objrc == 11)
		{
			GET_GROUND_Z_FOR_3D_COORD(-726.821, -192.367, 4.93627, &zg);
			CREATE_PICKUP(drugbag, 22, -726.821, -192.367, zg, &meth, 1);
			objrc++;
		}
		
		if(objrc == 12)
		{
			PRINT_TXT("Steal the ~b~meth~s~");
			
			if(HAS_PICKUP_BEEN_COLLECTED(meth))
			{
				PLAY_CHECKPOINT_SOUND();
				objrc++;
			}
		}
		
		if(objrc == 13)
		{
			SPAWN_ACTOR(0,  MODEL_M_Y_GBIK_LO_01, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -1605.81, -39.3239,   10.0497,  359.00, 0);
			SPAWN_ACTOR(1,  MODEL_M_Y_GBIK_LO_02, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -1603.89, -39.3499,   10.0499,  359.00, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_GBIK_LO_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -1601.48, -39.3962,   10.0502,  359.00, 0);
			SPAWN_ACTOR(3,  MODEL_M_Y_GALB_LO_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -1601.42, -37.2957,   10.0502,  180.00, 0);
			SPAWN_ACTOR(4,  MODEL_M_Y_GALB_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -1603.08, -37.3806,   10.09,    180.00, 0);
			SPAWN_ACTOR(5,  MODEL_M_Y_GALB_LO_03, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -1604.93, -37.5005,   10.0561,  180.00, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_GBIK_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -1611.44, -41.8721,   10.0488,  359.00, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_GBIK_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -1594.35, -33.885,    10.0511,  359.00, 0);
			SPAWN_ACTOR(8,  MODEL_M_Y_GALB_LO_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -1592.93, -43.6399,   10.0514,  359.00, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_GALB_LO_02, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -1609.85, -50.853,    10.0492,  359.00, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_GBIK_LO_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -1614,    -30.9863,   10.0484,  180.00, 0);
			SPAWN_ACTOR(11, MODEL_M_Y_GBIK_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -1608.96, -24.7118,   10.0492,  180.00, 0);
			SPAWN_ACTOR(12, MODEL_M_Y_GALB_LO_03, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -1601.97, -24.604,    10.0501,  180.00, 0);
			SPAWN_ACTOR(13, MODEL_M_Y_GBIK_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -1593.8,  -19.4928,   10.0514,  180.00, 0);
			SPAWN_ACTOR(14, MODEL_M_Y_GBIK_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -1588.01, -26.9841,   10.0524,  180.00, 0);
			SPAWN_ACTOR(15, MODEL_M_Y_GBIK_LO_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -1584.21, -19.0972,   10.0526,  180.00, 0);
			SPAWN_ACTOR(16, MODEL_M_Y_GALB_LO_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -1574.74, -23.7162,   10.054,   180.00, 0);
			SPAWN_ACTOR(17, MODEL_M_Y_GALB_LO_02, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -1568.23, -32.5272,   10.0549,  180.00, 0);
			SPAWN_ACTOR(18, MODEL_M_Y_GALB_LO_03, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -1591.44, -6.50326,   10.0516,  180.00, 0);
			SPAWN_ACTOR(19, MODEL_M_Y_GBIK_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -1602.41, -0.278483,  10.0499,  180.00, 0);
			SPAWN_ACTOR(20, MODEL_M_Y_GBIK_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -1612.35, 4.01353,    10.0484,  359.00, 0);
			SPAWN_ACTOR(21, MODEL_M_Y_GALB_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -1608.11, 11.9725,    10.0489,  359.00, 0);
			SPAWN_ACTOR(22, MODEL_M_Y_GALB_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -1596.12, 19.5136,    10.0506,  359.00, 0);
			SPAWN_ACTOR(23, MODEL_M_Y_GBIK_LO_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -1605.06, 24.3298,    10.0707,  359.00, 0);
			if(level == 2) SPAWN_ACTOR(24, MODEL_M_Y_GBIK_LO_02, WEAPON_RLAUNCHER, NOBLIP, accuracy, ehealth, armour, 10, -1579.97, 2.92759,    30.7406,  359.00, 0);
			objrc++;
		}
		
		if(objrc == 14)
		{
			SET_MISSION_CHECKPOINT_BIG_RADIUS(0, -1605.81, -39.3239, 8.0497, 5.0, "Go to ~Y~the 4th deal~S~");
		}
		
		if(objrc == 15)
		{
			GET_GROUND_Z_FOR_3D_COORD(-1605.81, -39.3239, 10.0497, &zg);
			CREATE_PICKUP(drugbag, 22, -1605.81, -39.3239, zg, &meth, 1);
			objrc++;
		}
		
		if(objrc == 16)
		{
			PRINT_TXT("Steal the ~b~meth~s~");
			
			if(HAS_PICKUP_BEEN_COLLECTED(meth))
			{
				PLAY_CHECKPOINT_SOUND();
				objrc++;
			}
		}
		
		if(objrc == 17)
		{
			SPAWN_ACTOR(0,  MODEL_M_Y_GLAT_LO_01, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -1026.42, 239.098, 8.75836, 359.00, 0);
			SPAWN_ACTOR(1,  MODEL_M_Y_GLAT_LO_02, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -1024.91, 239.05,  8.75836, 359.00, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_GLAT_HI_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -1022.83, 239.05,  8.75836, 359.00, 0);
			SPAWN_ACTOR(3,  MODEL_M_Y_GMAF_HI_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -1022.87, 241.592, 8.75836, 180.00, 0);
			SPAWN_ACTOR(4,  MODEL_M_Y_GMAF_HI_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -1024.61, 241.615, 8.75836, 180.00, 0);
			SPAWN_ACTOR(5,  MODEL_M_Y_GMAF_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -1026.82, 241.152, 8.75799, 180.00, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_GLAT_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -1024.56, 246.646, 8.75835, 180.00, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_GLAT_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -1020.79, 253.233, 8.75836, 180.00, 0);
			SPAWN_ACTOR(8,  MODEL_M_Y_GMAF_HI_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -1028.36, 252.831, 8.75836, 180.00, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_GMAF_HI_02, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -1034.2,  253.813, 8.75799, 180.00, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_GLAT_HI_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -1024.83, 231.802, 8.75836, 180.00, 0);
			SPAWN_ACTOR(11, MODEL_M_Y_GLAT_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -1032.39, 230.211, 8.75799, 180.00, 0);
			SPAWN_ACTOR(12, MODEL_M_Y_GMAF_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -1015.45, 229.895, 8.75836, 180.00, 0);
			SPAWN_ACTOR(13, MODEL_M_Y_GLAT_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -1038.2,  233.745, 8.75799, 180.00, 0);
			SPAWN_ACTOR(14, MODEL_M_Y_GLAT_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -1049.6,  230.384, 8.75799, 180.00, 0);
			SPAWN_ACTOR(15, MODEL_M_Y_GLAT_HI_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -1016.71, 254.104, 8.75837, 180.00, 0);
			SPAWN_ACTOR(16, MODEL_M_Y_GMAF_HI_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, -1010.28, 254.446, 8.75837, 180.00, 0);
			SPAWN_ACTOR(17, MODEL_M_Y_GMAF_HI_02, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, -1001.4,  252.531, 8.75837, 180.00, 0);
			SPAWN_ACTOR(18, MODEL_M_Y_GMAF_LO_01, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -996.709, 247.585, 8.75837, 180.00, 0);
			SPAWN_ACTOR(19, MODEL_M_Y_GLAT_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, -991.845, 230.686, 8.75836, 180.00, 0);
			SPAWN_ACTOR(20, MODEL_M_Y_GLAT_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, -982.474, 230.467, 8.75797,  90.00, 0);
			SPAWN_ACTOR(21, MODEL_M_Y_GMAF_HI_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, -965.072, 231.437, 8.75797,  90.00, 0);
			SPAWN_ACTOR(22, MODEL_M_Y_GMAF_HI_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, -966.42,  253.908, 8.75802,  90.00, 0);
			SPAWN_ACTOR(23, MODEL_M_Y_GLAT_HI_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, -984.898, 253.961, 8.75801,  90.00, 0);
			if(level == 2) SPAWN_ACTOR(24, MODEL_M_Y_GLAT_LO_02, WEAPON_RLAUNCHER, NOBLIP, accuracy, ehealth, armour, 10, -963.694, 241.67,  25.0016,  90.00, 0);
			objrc++;
		}
		
		if(objrc == 18)
		{
			SET_MISSION_CHECKPOINT_BIG_RADIUS(0, -1026.42, 239.098, 6.75836, 5.0, "Go to ~Y~the 5th deal~S~");
		}
		
		if(objrc == 19)
		{
			GET_GROUND_Z_FOR_3D_COORD(-1026.42, 239.098, 8.75836, &zg);
			CREATE_PICKUP(drugbag, 22, -1026.42, 239.098, zg, &meth, 1);
			objrc++;
		}
		
		if(objrc == 20)
		{
			PRINT_TXT("Steal the ~b~meth~s~");
			
			if(HAS_PICKUP_BEEN_COLLECTED(meth))
			{
				PLAY_CHECKPOINT_SOUND();
				objrc++;
			}
		}
		
		if(objrc == 21)
		{
			SPAWN_ACTOR(0,  MODEL_M_Y_GAFR_LO_01, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, 470.339, 332.218, 8.57155, 180.00, 0);
			SPAWN_ACTOR(1,  MODEL_M_Y_GAFR_LO_02, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, 468.969, 332.238, 8.57151, 180.00, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_GAFR_HI_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, 466.84,  332.293, 8.57155, 180.00, 0);
			SPAWN_ACTOR(3,  MODEL_M_M_GJAM_HI_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, 467.133, 328.205, 8.57155, 359.00, 0);
			SPAWN_ACTOR(4,  MODEL_M_Y_GJAM_LO_01, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, 469.193, 328.156, 8.57155, 359.00, 0);
			SPAWN_ACTOR(5,  MODEL_M_M_GJAM_HI_02, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, 471.072, 328.18,  8.57155, 359.00, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_GAFR_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, 466.771, 321.422, 8.57155, 359.00, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_GAFR_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, 473.602, 319.462, 8.57155, 359.00, 0);
			SPAWN_ACTOR(8,  MODEL_M_M_GJAM_HI_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, 468.425, 311.733, 8.57155, 359.00, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_GJAM_LO_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, 458.953, 316.606, 8.57155, 359.00, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_GAFR_HI_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, 468.575, 344.248, 8.57144, 180.00, 0);
			SPAWN_ACTOR(11, MODEL_M_Y_GAFR_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, 479.251, 342.322, 8.57144, 180.00, 0);
			SPAWN_ACTOR(12, MODEL_M_M_GJAM_HI_02, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, 480.965, 335.772, 10.0304, 180.00, 0);
			SPAWN_ACTOR(13, MODEL_M_Y_GAFR_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, 495.243, 341.136, 8.57158, 180.00, 0);
			SPAWN_ACTOR(14, MODEL_M_Y_GAFR_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, 506.574, 345.234, 8.59222, 180.00, 0);
			SPAWN_ACTOR(15, MODEL_M_Y_GAFR_HI_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, 460.611, 340.199, 8.57144, 180.00, 0);
			SPAWN_ACTOR(16, MODEL_M_M_GJAM_HI_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, 452.719, 342.284, 8.57144, 180.00, 0);
			SPAWN_ACTOR(17, MODEL_M_Y_GJAM_LO_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, 443.75,  341.124, 8.57144, 180.00, 0);
			SPAWN_ACTOR(18, MODEL_M_M_GJAM_HI_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, 435.542, 335.936, 10.0302, 180.00, 0);
			SPAWN_ACTOR(19, MODEL_M_Y_GAFR_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, 422.471, 341.264, 8.57158, 180.00, 0);
			SPAWN_ACTOR(20, MODEL_M_Y_GAFR_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, 468.511, 358.706, 8.57144, 180.00, 0);
			SPAWN_ACTOR(21, MODEL_M_M_GJAM_HI_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, 459.734, 366.102, 8.70539, 180.00, 0);
			SPAWN_ACTOR(22, MODEL_M_Y_GJAM_LO_01, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, 475.917, 366.031, 8.70538, 180.00, 0);
			SPAWN_ACTOR(23, MODEL_M_Y_GAFR_HI_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, 468.356, 381.514, 8.70538, 180.00, 0);
			if(level == 2) SPAWN_ACTOR(24, MODEL_M_Y_GAFR_LO_02, WEAPON_RLAUNCHER, NOBLIP, accuracy, ehealth, armour, 10, 468.652, 395.647, 48.6704, 180.00, 0);
			objrc++;
		}
		
		if(objrc == 22)
		{
			SET_MISSION_CHECKPOINT_BIG_RADIUS(0, 470.339, 332.218, 6.57155, 5.0, "Go to ~Y~the 6th deal~S~");
		}
		
		if(objrc == 23)
		{
			GET_GROUND_Z_FOR_3D_COORD(470.339, 332.218, 8.57155, &zg);
			CREATE_PICKUP(drugbag, 22, 470.339, 332.218, zg, &meth, 1);
			objrc++;
		}
		
		if(objrc == 24)
		{
			PRINT_TXT("Steal the ~b~meth~s~");
			
			if(HAS_PICKUP_BEEN_COLLECTED(meth))
			{
				PLAY_CHECKPOINT_SOUND();
				objrc++;
			}
		}
		
		if(objrc == 25)
		{
			SPAWN_ACTOR(0,  MODEL_M_Y_GIRI_LO_01, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, 692.816, 1912.53, 27.1642, 255.00, 0);
			SPAWN_ACTOR(1,  MODEL_M_Y_GIRI_LO_02, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, 701.171, 1913.14, 27.1642, 255.00, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_GIRI_LO_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, 706.195, 1918.42, 27.1642, 255.00, 0);
			SPAWN_ACTOR(3,  MODEL_M_Y_GMAF_HI_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, 706.195, 1918.42, 27.1642,  70.00, 0);
			SPAWN_ACTOR(4,  MODEL_M_Y_GMAF_HI_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, 709.813, 1917.24, 27.1642,  70.00, 0);
			SPAWN_ACTOR(5,  MODEL_M_Y_GMAF_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, 710.637, 1919.51, 27.1642,  70.00, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_GIRI_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, 711.459, 1921.72, 27.1642, 255.00, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_GIRI_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, 707.326, 1929.26, 27.1642, 255.00, 0);
			SPAWN_ACTOR(8,  MODEL_M_Y_GMAF_HI_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, 702.434, 1935.3,  27.1642, 255.00, 0);
			SPAWN_ACTOR(9,  MODEL_M_Y_GMAF_HI_02, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, 699.399, 1923.51, 27.1642, 255.00, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_GIRI_LO_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, 709.929, 1907.43, 27.1642,  70.00, 0);
			SPAWN_ACTOR(11, MODEL_M_Y_GIRI_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, 718.798, 1902.65, 27.1642,  70.00, 0);
			SPAWN_ACTOR(12, MODEL_M_Y_GMAF_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, 707.947, 1896.64, 27.1642,  70.00, 0);
			SPAWN_ACTOR(13, MODEL_M_Y_GIRI_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, 727.068, 1911.98, 27.1642,  70.00, 0);
			SPAWN_ACTOR(14, MODEL_M_Y_GIRI_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, 727.299, 1920.31, 27.1642,  70.00, 0);
			SPAWN_ACTOR(15, MODEL_M_Y_GIRI_LO_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, 706.363, 1945.57, 27.1642, 255.00, 0);
			SPAWN_ACTOR(16, MODEL_M_Y_GMAF_HI_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, 694.128, 1943.84, 27.1642, 255.00, 0);
			SPAWN_ACTOR(17, MODEL_M_Y_GMAF_HI_02, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, 687.483, 1933.25, 27.1642, 255.00, 0);
			SPAWN_ACTOR(18, MODEL_M_Y_GMAF_LO_01, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, 683.067, 1916.09, 27.1642, 255.00, 0);
			SPAWN_ACTOR(19, MODEL_M_Y_GIRI_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, 688.096, 1895.07, 27.1642, 255.00, 0);
			SPAWN_ACTOR(20, MODEL_M_Y_GIRI_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, 669.98,  1901.47, 27.1642, 255.00, 0);
			SPAWN_ACTOR(21, MODEL_M_Y_GMAF_HI_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, 668.519, 1916.59, 28.0052, 255.00, 0);
			SPAWN_ACTOR(22, MODEL_M_Y_GMAF_HI_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, 673.965, 1932.08, 27.9638, 255.00, 0);
			SPAWN_ACTOR(23, MODEL_M_Y_GIRI_LO_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, 680.766, 1948.66, 28.016,  255.00, 0);
			if(level == 2) SPAWN_ACTOR(24, MODEL_M_Y_GIRI_LO_02, WEAPON_RLAUNCHER, NOBLIP, accuracy, ehealth, armour, 10, 718.887, 1874.52, 34.3049,  18.00, 0);
			objrc++;
		}
		
		if(objrc == 26)
		{
			SET_MISSION_CHECKPOINT_BIG_RADIUS(0, 692.816, 1912.53, 25.1642, 5.0, "Go to ~Y~the 7th deal~S~");
		}
		
		if(objrc == 27)
		{
			GET_GROUND_Z_FOR_3D_COORD(692.816, 1912.53, 27.1642, &zg);
			CREATE_PICKUP(drugbag, 22, 692.816, 1912.53, zg, &meth, 1);
			objrc++;
		}
		
		if(objrc == 28)
		{
			PRINT_TXT("Steal the ~b~meth~s~");
			
			if(HAS_PICKUP_BEEN_COLLECTED(meth))
			{
				PLAY_CHECKPOINT_SOUND();
				objrc++;
			}
		}
		
		if(objrc == 29)
		{
			SPAWN_ACTOR(0,  MODEL_M_Y_GKOR_LO_01, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, 1487.28, 751.065, 28.4037, 359.00, 0);
			SPAWN_ACTOR(1,  MODEL_M_Y_GKOR_LO_02, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, 1488.66, 751.011, 28.4106, 359.00, 0);
			SPAWN_ACTOR(2,  MODEL_M_Y_GKOR_LO_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, 1490.93, 750.973, 28.4037, 359.00, 0);
			SPAWN_ACTOR(3,  MODEL_M_Y_GBIK_HI_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, 1490.94, 753.326, 28.4037, 180.00, 0);
			SPAWN_ACTOR(4,  MODEL_M_M_GBIK_LO_03, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, 1488.92, 753.313, 28.4076, 180.00, 0);
			SPAWN_ACTOR(5,  MODEL_M_Y_GBIK_HI_02, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, 1486.17, 753.452, 28.4037, 180.00, 0);
			SPAWN_ACTOR(6,  MODEL_M_Y_GKOR_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, 1493.27, 758.205, 28.4037, 180.00, 0);
			SPAWN_ACTOR(7,  MODEL_M_Y_GKOR_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, 1489.03, 761.547, 28.4045, 180.00, 0);
			SPAWN_ACTOR(8,  MODEL_M_Y_GBIK_HI_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, 1483.9,  759.287, 28.4037, 180.00, 0);
			SPAWN_ACTOR(9,  MODEL_M_M_GBIK_LO_03, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, 1488.61, 764.774, 28.4344, 180.00, 0);
			SPAWN_ACTOR(10, MODEL_M_Y_GKOR_LO_01, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, 1497.26, 748.259, 28.4037, 359.00, 0);
			SPAWN_ACTOR(11, MODEL_M_Y_GKOR_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, 1497.14, 759.533, 28.4037, 359.00, 0);
			SPAWN_ACTOR(12, MODEL_M_Y_GBIK_HI_02, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, 1495.43, 741.569, 28.4037, 359.00, 0);
			SPAWN_ACTOR(13, MODEL_M_Y_GKOR_LO_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, 1488.66, 737.241, 28.4037, 359.00, 0);
			SPAWN_ACTOR(14, MODEL_M_Y_GKOR_LO_02, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, 1483.8,  744.13,  28.4037, 359.00, 0);
			SPAWN_ACTOR(15, MODEL_M_Y_GKOR_LO_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, 1488.69, 746.333, 28.4141, 359.00, 0);
			SPAWN_ACTOR(16, MODEL_M_Y_GBIK_HI_01, WEAPON_BARETTA,   NOBLIP, accuracy, ehealth, armour, 10, 1492.05, 749.16,  28.4037, 359.00, 0);
			SPAWN_ACTOR(17, MODEL_M_M_GBIK_LO_03, WEAPON_MICRO_UZI, NOBLIP, accuracy, ehealth, armour, 10, 1481.61, 742.04,  28.4037, 359.00, 0);
			SPAWN_ACTOR(18, MODEL_M_Y_GBIK_HI_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, 1476.84, 749.063, 28.4037, 359.00, 0);
			SPAWN_ACTOR(19, MODEL_M_Y_GKOR_LO_01, WEAPON_AK47,      NOBLIP, accuracy, ehealth, armour, 10, 1475.2,  757.616, 28.4037, 359.00, 0);
			SPAWN_ACTOR(20, MODEL_M_Y_GKOR_LO_02, WEAPON_MP5,       NOBLIP, accuracy, ehealth, armour, 10, 1482.56, 777.11,  28.4004, 180.00, 0);
			SPAWN_ACTOR(21, MODEL_M_Y_GBIK_HI_01, WEAPON_M4,        NOBLIP, accuracy, ehealth, armour, 10, 1489.46, 778.663, 28.3633, 180.00, 0);
			SPAWN_ACTOR(22, MODEL_M_M_GBIK_LO_03, WEAPON_DEAGLE,    NOBLIP, accuracy, ehealth, armour, 10, 1497.74, 775.124, 28.4147, 180.00, 0);
			SPAWN_ACTOR(23, MODEL_M_Y_GKOR_LO_01, WEAPON_SHOTGUN,   NOBLIP, accuracy, ehealth, armour, 10, 1489.56, 728.868, 29.215,  180.00, 0);
			if(level == 2) SPAWN_ACTOR(24, MODEL_M_Y_GKOR_LO_02, WEAPON_RLAUNCHER, NOBLIP, accuracy, ehealth, armour, 10, 1477.97, 711.531, 41.6328, 359.00, 0);
			objrc++;
		}
		
		if(objrc == 30)
		{
			SET_MISSION_CHECKPOINT_BIG_RADIUS(0, 1487.28, 751.065, 26.4037, 5.0, "Go to ~Y~the 8th deal~S~");
		}
		
		if(objrc == 31)
		{
			GET_GROUND_Z_FOR_3D_COORD(1487.28, 751.065, 28.4037, &zg);
			CREATE_PICKUP(drugbag, 22, 1487.28, 751.065, zg, &meth, 1);
			objrc++;
		}
		
		if(objrc == 32)
		{
			PRINT_TXT("Steal the ~b~meth~s~");
			
			if(HAS_PICKUP_BEEN_COLLECTED(meth))
			{
				PLAY_CHECKPOINT_SOUND();
				objrc++;
			}
		}
		
		if(objrc == 33)
		{
			SET_MISSION_CHECKPOINT(0, -1401.54, 1460.03, 23.228, 5.0, "Deliver the meth on the ~Y~drop off~S~");
		}
		
		if(objrc == 34)
		{
			MISSION_COMPLETE("", 100000);
		}
	}
}