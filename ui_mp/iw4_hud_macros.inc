#define HUD_IS_ACTIVE					( ui_active() )
#define HUD_IS_HARDCORE					( dvarbool( "g_hardcore" ) )
#define HUD_HIDE_FLASHED				( flashbanged() )
#define HUD_HIDE_WEAPONS				( ( weaponname( ) == "killstreak_ac130_mp" ) || ( weaponname( ) == "killstreak_helicopter_minigun_mp" ) || ( weaponname( ) == "killstreak_predator_missile_mp" ) || ( ( weaponname( ) == "ac130_105mm_mp" ) || ( weaponname( ) == "ac130_40mm_mp" ) || ( weaponname( ) == "ac130_25mm_mp" ) ) || ( adsjavelin( ) ) || ( weaponname( ) == "heli_remote_mp" ) || missilecam( ) ) 
#define HUD_HIDE_ENDGAME				( dvarint( "scr_gameended" ) )

#define HUD_HIDE_EMP					isempjammed()
#define HUD_HIDE_SELECTINGLOCATION		selecting_location()
#define HUD_HIDE_INKILLCAM				inkillcam()

// team related stuff
#define HUD_HIDE_WHEN_SPECTATING		( team( "name" ) != "TEAM_SPECTATOR" )
#define HUD_HIDE_WHEN_FREE				( team( "name" ) ) == "TEAM_FREE" )

#define PLAYER_IS_UNKNOWN1 				( player( "score" ) ) == ( scoreatrank( 1 ) ) ) * ( scoreatrank( 2 ) 
#define PLAYER_IS_UNKNOWN2				( player( "score" ) ) != ( scoreatrank( 1 ) ) ) * ( scoreatrank( 1 )

#define HUD_TEXT_SWITCH					( ( ( milliseconds( ) % 30000 ) > 4000 && ( milliseconds( ) % 30000 ) < 30000 ) )