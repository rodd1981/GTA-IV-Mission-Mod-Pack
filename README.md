# GTA IV Mission Mod Pack (Source Code - for DEVS only!)

Source code for the GTA IV Mission Mod Pack V2.0 (it also comes with an API library coded by myself - very useful for those wanting to create new missions).

# Special thanks

- Alex Blade - SCOCL (This mod wouldn't exist without this great tool).
- Cosy       - Thanks for sharing the source code of your mini-menu.
- Skorpro    - Thanks for sharing the source code of your ASI SCO Loader.
- OhManMyBad - Thanks for sharing the source code of your GTA V Teleportation. 

# Requirements

- SCOCL (to compile missions - Download: http://www.dev-c.com/gtaiv/scocl/)
- GTA IV 1.0.7.0

# Installation

- Create a new directory and extract all files.
- Use SCOONE (to compile a single C source file) or SCOALL (to compile all C source files)
- Make sure you have SCOCL set on your PATH environment variable before compiling the sources

# Usage

- Compile new missions: scoone <mission.c>
- Compile all missions: scoall
- Source files should be sitting on the root directory
- SCO version will be written in PC directory

# API functions

Check source codes to understand how to use these functions properly

- GTAV_TELEPORT(float destx, float desty) - Teleports to destination X, Y
- APPLY_SELECTED_OPTIONS(int lvl, int wth, int time) - Apply selected options (level, weather and time)
- LOCK_TIME_OF_DAY(void) - Self explanatory
- CHECK_WANTED_LEVEL() - Returns 1 if player is wanted or 0 if player is not wanted
- PRINT_TXT(char *string) - Print objective on screen
- DRAW_WINDOW_FOR_DESC(float x, float y, float width, float heigh, int alpha) - Draw window for mission description
- PLAY_CHECKPOINT_SOUND() - Plays a checkpoint completed sound
- PRINT_MAIN_LOGO(float x, float y, char *string) - Print main mission logo on menu
- PRINT_DESC(float x, float y, char *string) - Print mission description
- MISSION_COMPLETE(char *string, int money) - Use this function when the last objective is complete
- MISSION_FAILED(char *string) - Use this function when mission fails
- PRINT_LIVES() - Print lifes left for player
- PRINT_TIMER(uint timer) - Will be implemented soon
- POLICE(int police, int maxwanted) - Enable/disable police and sets max stars wanted (0 = NO POLICE / 1 - POLICE ON / MAXSTARS [0-6])
- INIT_SETTINGS(float x, float y, float z, float h) - Initial XYZH world coordinates for player
- SET_MISSION_CHECKPOINT(uint num, float x, float y, float z, float radius, char *string) - Add a checkpoint objective for player
- SPAWN_ACTOR(uint pednum, uint model, uint wep, uint blipnum, int accuracy, int health, int armour, float sense, float x, float y, float z, float h, int role) - Spawn an actor (role = 0 --> Enemy / role = 1 --> Friend)
- SPAWN_ACTOR_INSIDE_CAR(uint pednum, uint vehnum, uint seat, uint model, uint wep, uint blipnum, uint accuracy, uint health, uint armour, float sense, uint role) - Spawns an actor inside car
- SPAWN_VEHICLE(uint num, uint model, uint blipnum, float x, float y, float z, float h, uint health, uint tyre) - Spawns a vehicle on map
- DEBUG_MISSION() - Use this function to debug code issues inside the objectives
- MANAGE_ACTORS(uint num) - Use this function to manage all actors blips & deaths (num = amount of actors)
- CLEAR_ZONE(float x, float y, float z, float radius) - Clear area of cars, chars & objs
- MANAGE_PLAYER() - Manage player deaths & lives amount
- MANAGE_VEHICLES(uint num) - Manage vehicle blips & deaths
- MANAGE_UNIQUE_VEHICLE_STATUS(uint num) - Use this function to manage if a single vehicle was destroyed (if so it will fail the mission)
- MANAGE_UNIQUE_ACTOR_STATUS(uint num) - Use this function to manage if a single char was killed (if so it will fail the mission)
- GOTO_LOCATION_WITH_VEHICLE(uint vehnum, uint blipnum, float x, float y, float z, char *string, char *string2) - Add blip/objective to go with a specific vehicle to a location
- GO_AFTER_PLAYER_WITH_VEHICLE(uint e_num, uint v_num) - Will order the spawned enemy inside car to hunt the player
- DRIVE_TO_LOCATION_WITH_VEHICLE(uint e_num, uint v_num, float x, float y, float z, float speed) - Will order the driver to go with vehicle to a specific location on map
- MANAGE_PICKUP(int num) - Will manage if a specific pickup obj has been collected
- SPAWN_ENEMY_CAR_IN_AREA(uint modelveh, float x, float y, float z, uint vnum, uint enum1, uint enum2, uint modelped) - Will spawn enemy inside car in a specific area with roads/highways.

# License

As of November 1, 2015 Chat API is licensed under the GPLv3+: http://www.gnu.org/licenses/gpl-3.0.html.

# Legal

- If you make money off of it, please consider donating

# Misc

- Pull requests and improvements are always welcome
- Let me know if you port this to ScriptHook (I am in the hope that someone does that - preferrably aiming for a Mission Creator, similar to GTA V's).
