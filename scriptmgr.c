

// Script Manager
// Created by Cosy

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
#define KEY_DELETE 211
#define KEY_DOWN_ARROW 208
#define KEY_LEFT_ARROW 203
#define KEY_RIGHT_ARROW 205

#define MYFONT 7
#define TEXT_W 0.236f
#define TEXT_H 0.32f
#define TEXT_LEFT 0.40f // change this for Menu position x
#define TEXT_TOP 0.20f // change this for Menu position y
#define TEXT_RIGHT TEXT_LEFT+0.15f
#define TEXT_INDENT 0.005f
#define TEXT_WIDTH 0.172f
#define TEXT_LINE_SPACING 0.0225f
#define DISPLAY_LINE_START TEXT_TOP + ( TEXT_LINE_SPACING * 1.25f )
#define WINDOW_LEFT TEXT_LEFT - TEXT_INDENT
#define WINDOW_TOP TEXT_TOP - TEXT_INDENT
//#define WINDOW_WIDTH TEXT_WIDTH + ( TEXT_INDENT * 2 )
#define WINDOW_WIDTH 0.25f
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
	MENU_CUSTOM,
	MENU_QUIT
};

enum
{
	TYPE_SUBMENU,
	TYPE_TOGGLE,
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

//uint r = 30, g = 144, b = 255; // A nice LCD blue 8^)
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
window_height = 0.2f,
window_height_centre = 0.0f;

char *page_title = 0;

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

void PRINT_DESC(float x, float y, char *string)
{
	SET_UP_DRAW(2, 0.28, 0.28, 255, 255, 255, 240);
	DRAW_TEXT("STRING",  x, y, string);
}

void PRINT_MAIN_LOGO(char *string, float x, float y)
{
	SET_UP_DRAW(2, 0.48, 0.78, 255, 255, 255, 240);
	DRAW_TEXT("STRING",  x, y, string);
}

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
				UNPAUSE_GAME();
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

void MenuSetup(void)
{
	if ( ( isMenu = !isMenu ) )
	{
		STOP_MOBILE_PHONE_RINGING();
		DESTROY_MOBILE_PHONE();
		TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME( isNetGame?"mpcellphone":"spcellphone" );
		DISABLE_FRONTEND_RADIO();
		if ( !IS_FONT_LOADED( MYFONT ) ) LOAD_TEXT_FONT( MYFONT );
	}
	else
	{
		ENABLE_FRONTEND_RADIO();
		if ( !isNetGame ) LoadScript("spcellphone");
		else if ( isNetPhoneEnabled ) LoadScript("mpcellphone");
	}
	
	DISPLAY_AREA_NAME(FALSE);
	DISPLAY_CASH(FALSE);
	DISPLAY_FRONTEND_MAP_BLIPS(FALSE);
	DISPLAY_HUD(FALSE);
	DISPLAY_RADAR(FALSE);
	PAUSE_GAME();
	DRAW_FRONTEND_HELPER_TEXT("SELECT", "PAD_DPAD_UPDOWN", 0);
	DRAW_FRONTEND_HELPER_TEXT("QUIT", "INPUT_F_CANCEL", 0);
	DRAW_FRONTEND_HELPER_TEXT("CONFIRM", "INPUT_F_ACCEPT", 0);
}

void CreatePage( const char *desc, int page )
{
	item[num_items].desc = desc;
	item[num_items].script = "na";
	item[num_items].value = page;
	item[num_items].type = TYPE_SUBMENU;

	++num_items;
}

void CreateItem( const char *desc, const char *script )
{
	item[num_items].desc = desc;
	item[num_items].script = script;
	item[num_items].value = GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(script);
	item[num_items].type = TYPE_TOGGLE;

	++num_items;
}

void DrawPage(void)
{
	int i;
	display_line = DISPLAY_LINE_START;
	DRAW_RECT(0.5000, 0.5000, 1.0000, 1.0000, 0, 0, 0, 90);
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

		if ( item[i].type == TYPE_TOGGLE) // toggle displayer
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

		display_line += TEXT_LINE_SPACING;
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
		else if ( item[selection].type == TYPE_TOGGLE )
		{
			item[selection].value = LoadScript(item[selection].script);
			PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_READY");
		}
	}

	else if (IS_BUTTON_JUST_PRESSED(0, BUTTON_O) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_BACKSPACE))
	{
		selection_mem[page] = selection;
		page = prev_page;
		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_READY");
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
		CreatePage( "GTA V Online Missions", MENU_GTAO );
		CreatePage( "Custom Missions", MENU_CUSTOM );
		CreatePage( "Exit menu", MENU_QUIT );
	
		prev_page = MENU_MAIN; // previous page for when going back
		page_title = "GTA IV Mission Mod Pack"; // Title header for this page
	}


	else if ( page == MENU_GTAO )
	{
		CreateItem("A boat in the bay (Trevor)", "abitb");
		CreateItem("All in the Game (Simeon)","aitg");
		CreateItem("Blow Up (Simeon)","blowup");
		CreateItem("Blow Up II (Simeon)", "blowup2");
		CreateItem("Blow Up III (Simeon)", "blowup3");
		CreateItem("Crystal Clear Out 2 (Trevor)","ccout2");
		CreateItem("El Burro Heists (Simeon)","elbheist");
		CreateItem("Gentry Does It (Simeon)","gentrydi");
		CreateItem("Lost MC Rip (Lamar)", "lstmcrip");
		CreateItem("It Takes A Thief (Simeon)", "itat");
		CreateItem("Out of Court Settlement (Martin)", "oocs");
		CreateItem("Potshot (Trevor)", "potshot");
		CreateItem("Rockford Roll (Simeon)", "rockroll");
		CreateItem("Rooftop Rumble (Martin)", "rooftop");
		CreateItem("Show me the Monet (Martin)", "smtmonet");
		CreateItem("The Parking Garage (Lester)", "prkgarag");
		
		prev_page = MENU_MAIN;
		page_title = "GTA V Online Missions";
	}


	else if ( page == MENU_CUSTOM )
	{
		CreateItem("Saints and Devils","sntsdvls");
		CreateItem("Death Penalty","dethpnty");
		CreateItem("Gruppe Sechs Heists","gsheist");
		CreateItem("Deal Breaker 2","dealbrk2");

		prev_page = MENU_MAIN;
		page_title = "Custom Missions";
	}
	
	else if ( page == MENU_QUIT )
	{
		UNPAUSE_GAME();
		DISPLAY_AREA_NAME(TRUE);
		DISPLAY_CASH(TRUE);
		DISPLAY_FRONTEND_MAP_BLIPS(TRUE);
		DISPLAY_HUD(TRUE);
		DISPLAY_RADAR(TRUE);
		TERMINATE_THIS_SCRIPT();
	}
	
	window_height = ( ( num_items + 1 ) * TEXT_LINE_SPACING ) + ( WINDOW_HEIGHT_CUT + ( TEXT_LINE_SPACING / 4 ) );
	window_height_centre = ( TEXT_TOP - TEXT_INDENT ) + window_height / 2;
}


void main(void)
{
	while ( ++num_items < MAX_PAGES ) selection_mem[num_items] = 0;
	while ( !IS_PLAYER_SCRIPT_CONTROL_ON(GetPlayerIndex()) ) WAIT(1000);
	//TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("modmanager");
		
	while ( TRUE )
	{
		WAIT(0);
		SET_SLEEP_MODE_ACTIVE(TRUE);
		PRINT_MAIN_LOGO("GTA IV Mission Mod Pack v2.0", 0.30, 0.05);
		PRINT_DESC(0.28, 0.11, "Created by rodd1981 (c) www.facebook.com/gtamodz");
		MenuSetup();
		
		if (page != page_check ) 
		{
			SetupPage();
		}
		
		DrawPage();
		Nav();
		
		/*
		if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_F11))
		{
			TERMINATE_THIS_SCRIPT();
		}
		*/
	}
}
