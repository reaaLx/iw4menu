//iw4 stock
CHOICE_BUTTON( 0, "@MENU_VIDEO", LOCAL_CLOSE_ALL open "pc_options_video" )
CHOICE_BUTTON( 1, "@MENU_AUDIO", LOCAL_CLOSE_ALL  open "pc_options_audio" )
CHOICE_BUTTON( 2, "@MENU_CONTROLS", LOCAL_CLOSE_ALL open "pc_options_controls" )

CHOICE_BUTTON_EX( 3, "@MENU_VOICE", LOCAL_CLOSE_ALL open "pc_options_voice", disabled when ( dvarstring( "gameMode" ) == "sp" || dvarstring( "gameMode" ) == "so" ) )

CHOICE_SEPARATOR( CHOICE_SEP_1 )

CHOICE_BUTTON_EX( 4, "@MENU_RESET_SYSTEM_DEFAULTS", LOCAL_CLOSE_ALL open "options_graphics_defaults";, disabled when ( ( ( dvarstring( "gameMode" ) == "so" && ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) || inlobby() ) ) || ( dvarstring( "gameMode" ) == "mp" && ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) || inlobby() ) ) ) ) )
