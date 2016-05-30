CHOICE_BUTTON_VIS( 1, "@MENU_VIDEO", LOCAL_CLOSE_ALL open "pc_options_video", when( ( !dvarInt( "sv_running" ) || dvarInt( "ui_allow_graphic_change" ) ) && dvarInt( "arcademode" ) == 0 ); )
CHOICE_DBUTTON_VIS( 1, "@MENU_VIDEO", when( ( dvarInt( "sv_running" ) && dvarInt("ui_allow_graphic_change") == 0 ) || dvarBool( "arcademode" ) ); )

CHOICE_BUTTON_VIS( 2, "@MENU_AUDIO", LOCAL_CLOSE_ALL  open "pc_options_audio", when( ( !dvarInt( "sv_running" ) || dvarInt( "ui_allow_graphic_change" ) ) && dvarInt( "arcademode" ) == 0 ); )
CHOICE_DBUTTON_VIS( 2, "@MENU_AUDIO", when( ( dvarInt( "sv_running" ) && dvarInt("ui_allow_graphic_change") == 0 ) || dvarBool( "arcademode" ) ); )

CHOICE_BUTTON( 3, "@MENU_CONTROLS", LOCAL_CLOSE_ALL open "pc_options_controls" )

CHOICE_BUTTON_VIS( 4, "@MENU_VOICECHAT", LOCAL_CLOSE_ALL open "pc_options_voice", when( dvarInt( "ui_multiplayer" ) ) )
CHOICE_DBUTTON_VIS( 4, "@MENU_VOICECHAT", when( !dvarInt( "ui_multiplayer" ) ); )

CHOICE_SEPARATOR( CHOICE_SEP_1 )

CHOICE_BUTTON_VIS( 5, "@MENU_RESET_SYSTEM_DEFAULTS", LOCAL_CLOSE_ALL open "options_graphics_defaults", when( ( !dvarInt( "sv_running" ) || dvarInt( "ui_allow_graphic_change" ) ) && dvarInt( "arcademode" ) == 0 ); )
CHOICE_DBUTTON_VIS( 5, "@MENU_RESET_SYSTEM_DEFAULTS", when( ( dvarInt( "sv_running" ) && dvarInt("ui_allow_graphic_change") == 0 ) || dvarBool( "arcademode" ) ); )
