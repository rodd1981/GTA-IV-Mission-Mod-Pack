// Script Manager
// Created by Cosy
// Code adaptations done by rodd1981

#include <natives.h>
#include <common.h>
#include <strings.h>

#define BUTTON_SELECT 13
#define BUTTON_START 12
#define BUTTON_S 14
#define BUTTON_T 15
#define BUTTON_X 16
#define BUTTON_O 17
#define BUTTON_DPAD_UP 8
#define BUTTON_DPAD_DOWN 9
#define BUTTON_DPAD_LEFT 10
#define BUTTON_DPAD_RIGHT 11
#define BUTTON_L2 5
#define BUTTON_R2 7
#define BUTTON_L1 4
#define BUTTON_R1 6
#define BUTTON_STICK_LEFT 18
#define BUTTON_STICK_RIGHT 19

#define KEY_UP_ARROW 200
#define KEY_DOWN_ARROW 208
#define KEY_LEFT_ARROW 203
#define KEY_RIGHT_ARROW 205
#define KEY_DELETE 211

#define MYFONT 7
#define TEXT_W 0.24f
#define TEXT_H 0.32f
#define TEXT_LEFT 0.42f // change this for Menu position x
#define TEXT_TOP 0.23f // change this for Menu position y
#define TEXT_RIGHT TEXT_LEFT+0.10f
#define TEXT_INDENT 0.002f
#define TEXT_WIDTH 0.172f
#define TEXT_LINE_SPACING 0.0225f
#define DISPLAY_LINE_START TEXT_TOP + ( TEXT_LINE_SPACING * 1.25f )
#define WINDOW_LEFT TEXT_LEFT - TEXT_INDENT
#define WINDOW_TOP TEXT_TOP - TEXT_INDENT
//#define WINDOW_WIDTH TEXT_WIDTH + ( TEXT_INDENT * 2 )
#define WINDOW_WIDTH 0.222f
#define WINDOW_HEIGHT_CUT TEXT_INDENT * 2
#define WINDOW_X_CENTRE ( TEXT_LEFT - TEXT_INDENT ) + ( TEXT_WIDTH + ( TEXT_INDENT * 2 ) ) / 2
#define FALSE 0
#define TRUE 1

#define MAX_ITEMS 20 // Maximum items per page
#define MAX_PAGES 4 // the amount of pages we have in enumerator ePage

enum ePage
{
	MENU_MAIN,
	MENU_GTAO,
	MENU_CUSTOM
};

enum
{
	TYPE_SUBMENU,
	TYPE_TOGGLE,
	TYPE_START,
	TYPE_ADJUST_WEATHER,
	TYPE_ADJUST_TIME,
	TYPE_ADJUST_CARS,
	TYPE_ADJUST_LEVEL
};

int selection = 0,
num_items = 0,
page = MENU_MAIN,
page_check = -1,
prev_page = MENU_MAIN,
selection_mem[MAX_PAGES];

bool isNetGame = FALSE,
isMenu = FALSE,
isNetPhoneEnabled = FALSE;

uint r = 255, g = 255, b = 255; // A nice LCD blue 8^)

struct data
{
	char *desc,
	*script;
	uint value, 
	type;
};
struct data item[MAX_ITEMS];

float display_line = TEXT_TOP,
window_height = 0.0f,
window_height_centre = 0.0f;

char *page_title = 0;
char *info_title = 0;

bool LoadScript( const char *script )
{
	if ( !IS_STRING_NULL(script) )
	{
		if ( DOES_SCRIPT_EXIST(script) )
		{
			if ( GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(script) > 0 )
			{
				TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(script);
			}
			else
			{
				TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(script);
				REQUEST_SCRIPT(script);
				while ( !HAS_SCRIPT_LOADED(script) ) WAIT(100);
				START_NEW_SCRIPT(script, 1024);
				MARK_SCRIPT_AS_NO_LONGER_NEEDED(script);
				return TRUE;
			}
		}
	}
	return FALSE;
}

void LOCK_FRONTEND_DISPLAYS(void)
{
	PAUSE_GAME();
	DRAW_RECT(0.5000, 0.5000, 1.0000, 1.0000, 28, 63, 112, 90);
	SET_PLAYER_CONTROL(GET_PLAYER_ID(), FALSE);
	SET_CINEMATIC_BUTTON_ENABLED(FALSE);
	BLOCK_PED_WEAPON_SWITCHING(GetPlayerPed(), TRUE);
	DISPLAY_AREA_NAME(FALSE);
	DISPLAY_CASH(FALSE);
	DISPLAY_FRONTEND_MAP_BLIPS(FALSE);
	DISPLAY_HUD(FALSE);
	DISPLAY_RADAR(FALSE);
	SET_CHAR_VISIBLE(GetPlayerPed(), FALSE);
	DRAW_FRONTEND_HELPER_TEXT("SELECT", "PAD_DPAD_UPDOWN", 0);
	DRAW_FRONTEND_HELPER_TEXT("QUIT", "INPUT_F_CANCEL", 0);
	DRAW_FRONTEND_HELPER_TEXT("CONFIRM", "INPUT_F_ACCEPT", 0);
}

void UNLOCK_FRONTEND_DISPLAYS(void)
{
	UNPAUSE_GAME();
	SET_PLAYER_CONTROL(GET_PLAYER_ID(), TRUE);
	SET_CINEMATIC_BUTTON_ENABLED(TRUE);
	BLOCK_PED_WEAPON_SWITCHING(GetPlayerPed(), FALSE);
	DISPLAY_AREA_NAME(TRUE);
	DISPLAY_CASH(TRUE);
	DISPLAY_FRONTEND_MAP_BLIPS(TRUE);
	DISPLAY_HUD(TRUE);
	DISPLAY_RADAR(TRUE);
	SET_CHAR_VISIBLE(GetPlayerPed(), TRUE);
}

void CreatePage( const char *desc, int page )
{
	item[num_items].desc = desc;
	item[num_items].script = "na";
	item[num_items].value = page;
	item[num_items].type = TYPE_SUBMENU;

	++num_items;
}


void CREATE_ITEM(const char *desc, int type)
{
	item[num_items].desc = desc;
	item[num_items].value = 0;
	item[num_items].type = type;

	++num_items;
}

void DISPLAY_OPTION(int i)
{
	if ( item[i].type == TYPE_ADJUST_WEATHER ) // value displayer
	{
		if(item[i].value == 0)
		{
			DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_RIGHT, display_line, "STRING", "< Clear >");
			weather = 0;
		}
			
		else if(item[i].value == 1)
		{
			DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_RIGHT, display_line, "STRING", "< Raining >");
			weather = 1;
		}
		
		else if(item[i].value > 1)
		{
			item[i].value = 0;
			weather = 0;
		}
		
		else if(item[i].value < 0 || item[i].value == -1)
		{
			item[i].value = 1;
			weather = 2;
		}
	}
	
	if ( item[i].type == TYPE_ADJUST_TIME ) // value displayer
	{
		if(item[i].value == 0)
		{
			DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_RIGHT, display_line, "STRING", "< Morning >");
			time = 0;
		}
			
		else if(item[i].value == 1)
		{
			DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_RIGHT, display_line, "STRING", "< Noon >");
			time = 1;
		}
		
		else if(item[i].value == 2)
		{
			DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_RIGHT, display_line, "STRING", "< Evening >");
			time = 2;
		}
		
		else if(item[i].value > 2)
		{
			item[i].value = 0;
			time = 0;
		}
		
		else if(item[i].value < 0 || item[i].value == -1)
		{
			item[i].value = 2;
			time = 2;
		}
	}
	
	if ( item[i].type == TYPE_ADJUST_LEVEL ) // value displayer
	{
		if(item[i].value == 0)
		{
			DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_RIGHT, display_line, "STRING", "< Easy >");
			level = 0;
		}
		
		else if(item[i].value == 1)
		{
			DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_RIGHT, display_line, "STRING", "< Normal >");
			level = 1;
		}
		
		else if(item[i].value == 2)
		{
			DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_RIGHT, display_line, "STRING", "< Hard >");
			level = 2;
		}
		
		else if(item[i].value > 2)
		{
			item[i].value = 0;
			level = 0;
		}
		
		else if(item[i].value < 0 || item[i].value == -1)
		{
			item[i].value = 2;
			level = 2;
		}
	}
	
	if ( item[i].type == TYPE_ADJUST_CARS ) // value displayer
	{
		if(item[i].value == 0)
		{
			DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_RIGHT, display_line, "STRING", "< 2-Seat Car >");
			vehmodel = MODEL_COMET;
		}
		
		else if(item[i].value == 1)
		{
			DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_RIGHT, display_line, "STRING", "< 4-Seat Car >");
			vehmodel = MODEL_PMP600;
		}
		
		else if(item[i].value == 2)
		{
			DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_RIGHT, display_line, "STRING", "< Stockade >");
			vehmodel = MODEL_NSTOCKADE;
		}
		
		else if(item[i].value > 2)
		{
			item[i].value = 0;
			level = 0;
		}
		
		else if(item[i].value < 0 || item[i].value == -1)
		{
			item[i].value = 2;
			level = 2;
		}
	}
}

void DrawPage(void)
{
	int i;
	display_line = DISPLAY_LINE_START;
	DRAW_RECT(0.5000, 0.5000, 1.0000, 1.0000, 0, 0, 0, 80);
	DRAW_RECT(WINDOW_X_CENTRE, window_height_centre, WINDOW_WIDTH+0.004f, window_height+0.006f, r, g, b, 255);
	DRAW_RECT(WINDOW_X_CENTRE, window_height_centre, WINDOW_WIDTH, window_height, 0, 0, 0, 255);
		
	SET_TEXT_SCALE(TEXT_W, TEXT_H);
	SET_TEXT_COLOUR(r, g, b, 255);
	SET_TEXT_DROPSHADOW(FALSE, 0, 0, 0, 255);
	SET_TEXT_WRAP(WINDOW_LEFT, WINDOW_LEFT+WINDOW_WIDTH);
	SET_TEXT_CENTRE(TRUE);
	DISPLAY_TEXT_WITH_LITERAL_STRING(WINDOW_X_CENTRE, TEXT_TOP, "STRING", page_title );

	for ( i = 0; i < num_items; ++i )
	{
		SET_TEXT_SCALE(TEXT_W, TEXT_H);
		SET_TEXT_DROPSHADOW(FALSE, 0, 0, 0, 255);
		
		if ( selection == i )
		{
			SET_TEXT_COLOUR(0, 0, 0, 255);
			DRAW_RECT(WINDOW_X_CENTRE, display_line+(TEXT_LINE_SPACING/2), WINDOW_WIDTH, TEXT_LINE_SPACING, r, g, b, 255);
		}
		else SET_TEXT_COLOUR(r, g, b, 255);
		DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_LEFT, display_line, "STRING", item[i].desc );

		if ( item[i].type == TYPE_START || item[i].type == TYPE_TOGGLE ) // toggle displayer
		{
			SET_TEXT_SCALE(TEXT_W, TEXT_H);
			SET_TEXT_DROPSHADOW(FALSE, 0, 0, 0, 255);
			if ( item[i].value )
			{
				if ( selection == i )
				{
					SET_TEXT_COLOUR(0, 0, 0, 255);
				}
				else 
				{
					SET_TEXT_COLOUR(r, g, b, 255);
					//DISPLAY_TEXT_WITH_LITERAL_STRING(TEXT_RIGHT, display_line, "STRING", "On");
				}
			}
		}
		
		if ( item[i].type == TYPE_ADJUST_LEVEL || item[i].type == TYPE_ADJUST_WEATHER || item[i].type == TYPE_ADJUST_TIME || item[i].type == TYPE_ADJUST_CARS) // value displayer
		{
			SET_TEXT_SCALE(TEXT_W, TEXT_H);
			SET_TEXT_DROPSHADOW(FALSE, 0, 0, 0, 255);
			
			if ( selection == i ) 
			{
				SET_TEXT_COLOUR(0, 0, 0, 255);
				DISPLAY_OPTION(i);
			}
			else 
			{
				SET_TEXT_COLOUR(r, g, b, 255);
				DISPLAY_OPTION(i);
			}

			display_line += TEXT_LINE_SPACING;
		}
	}
}


void Nav(void)
{
	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_UP) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_UP_ARROW))
	{
		if ( --selection < 0 ) selection = num_items - 1;
		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
	}

	else if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_DOWN) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_DOWN_ARROW))
	{
		if ( ++selection > num_items - 1 ) selection = 0;
		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
	}

	else if (IS_BUTTON_JUST_PRESSED(0, BUTTON_X) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_ENTER))
	{
		if ( item[selection].type == TYPE_SUBMENU )
		{
			selection_mem[page] = selection;
			page = item[selection].value;
			PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_READY");
		}
		else if ( item[selection].type == TYPE_START )
		{
			PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_READY");
			objrc++;
		}
	}

	else if (IS_BUTTON_JUST_PRESSED(0, BUTTON_O) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_BACKSPACE))
	{
		selection_mem[page] = selection;
		page = prev_page;
		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_READY");
	}
	
	else if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_LEFT) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_LEFT_ARROW) )
	{
		if ( item[selection].type == TYPE_ADJUST_LEVEL || item[selection].type == TYPE_ADJUST_WEATHER || item[selection].type == TYPE_ADJUST_TIME || item[selection].type == TYPE_ADJUST_CARS) 
		{
			PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
			item[selection].value -= 1;
		}
	}
		
	else if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_RIGHT) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_RIGHT_ARROW) )
	{
		if ( item[selection].type == TYPE_ADJUST_LEVEL || item[selection].type == TYPE_ADJUST_WEATHER || item[selection].type == TYPE_ADJUST_TIME || item[selection].type == TYPE_ADJUST_CARS)
		{
			PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
			item[selection].value += 1;
		}
	}
}

void SetupPage(void)
{
	num_items = 0;
	page_check = page;
	selection = selection_mem[page];

	// Check Main Menu below for examples of inserting items.
	// These two lines underneath give more help on the values required.

	// CreatePage( "Page description", <MENU enum> );
	// CreateItem( "Script description", "script filename" );

	if ( page == MENU_MAIN )
	{
		CREATE_ITEM("Difficulty",    TYPE_ADJUST_LEVEL);
		CREATE_ITEM("Weather",     TYPE_ADJUST_WEATHER);
		CREATE_ITEM("Time of day",    TYPE_ADJUST_TIME);
		CREATE_ITEM("Car",            TYPE_ADJUST_CARS);
		CREATE_ITEM("Start Mission",        TYPE_START);
	
		prev_page = MENU_MAIN; // previous page for when going back
		page_title = "Mission Menu"; // Title header for this page
	}
	
	window_height = ( ( num_items + 1 ) * TEXT_LINE_SPACING ) + ( WINDOW_HEIGHT_CUT + ( TEXT_LINE_SPACING / 4 ) );
	window_height_centre = ( TEXT_TOP - TEXT_INDENT ) + window_height / 2;
}

void DRAW_MENU(void)
{
	if (!IS_FONT_LOADED(MYFONT))
	{
		LOAD_TEXT_FONT(MYFONT);
	}
	
	LOCK_FRONTEND_DISPLAYS();
	
	if(page != page_check) 
	{
		SetupPage();
	}
	
	DrawPage();
	Nav();
}