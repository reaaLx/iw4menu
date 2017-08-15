/*
BACKGROUND_SETTINGS is normal grey color
BACKGROUND_BLUR_INGAME is the darker color eg. advanced / bind menu
BACKGROUND_SETTINGS_ADVANCED is ingame.
*/

#ifdef BACKGROUND_SETTINGS
		itemDef
		{
			rect -427 -240 854 480 2 2
			decoration
			visible 1
			style 3
			forecolor 0 0 0 0.4
			background "white"
			textscale 0.55
			visible when ( ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) ) && ( dvarstring( "gameMode" ) == "mp" || ( dvarstring( "gameMode" ) == "so" && !dvarbool( "solo_play" ) ) ) )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			decoration
			visible 1
			style 3
			forecolor 1 1 1 1
			background "mw2_main_background"
			textscale 0.55
			visible when ( ! ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) ) )
		}
		itemDef
		{
			rect 0 0 1708 480 0 0
			decoration
			visible 1
			style 3
			forecolor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			textscale 0.55
			exp rect x ( ( 0 - 107 ) - ( ( float( milliseconds() % 60000 ) / 60000 ) * ( 854 ) ) )
			visible when ( ! ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) ) )
		}
		itemDef
		{
			rect 0 0 -1708 -480 0 0
			decoration
			visible 1
			style 3
			forecolor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			textscale 0.55
			exp rect x ( ( - 107 + 854 ) + ( ( float( milliseconds() % 50000 ) / 50000 ) * ( 854 ) ) )
			visible when ( ! ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) ) )
		}
		itemDef
		{
			rect -427 -240 854 480 2 2
			decoration
			visible 1
			style 3
			forecolor 1 1 1 1
			background "mw2_main_mp_image"
			textscale 0.55
			visible when ( dvarstring( "gameMode" ) == "mp" && ! ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) ) )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			decoration
			visible 1
			style 3
			forecolor 1 1 1 0
			background "mockup_bg_glow"
			textscale 0.55
			exp forecolor a ( ( ( sin( milliseconds() / 1500 ) + 1 ) * 0.25 ) + 0.25 )
			visible when ( ! ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) ) )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			decoration
			visible 1
			style 3
			forecolor 1 1 1 0
			background "mockup_bg_glow"
			textscale 0.55
			exp forecolor a ( ( ( sin( milliseconds() / 480 ) + 1 ) * 0.25 ) + 0.25 )
			visible when ( ! ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) ) )
		}
		itemDef
		{
			rect -64 0 280 480 1 0
			decoration
			visible 1
			style 3
			forecolor 1 1 1 0.1
			background "gradient_fadein_fadebottom"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			decoration
			visible 1
			style 3
			forecolor 0.25 0.25 0.25 0.75
			background "gradient_fadein"
			textscale 0.55
			visible when ( ! ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) ) )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			decoration
			visible 1
			style 3
			forecolor 0.25 0.25 0.25 0.75
			background "gradient_fadein"
			textscale 0.55
			visible when ( ! ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) ) )
		}
#endif
// INGAME BACKGROUND
#ifdef BACKGROUND_BLUR_INGAME
		itemDef
		{
			rect 0 0 640 480 4 4
			decoration
			visible 1
			style 3
			forecolor 0 0 0 0.4
			background "white"
			textscale 0.55
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			decoration
			visible 1
			style 3
			forecolor 1 1 1 0
			background "mockup_bg_glow"
			textscale 0.55
			exp forecolor a ( ( ( sin( milliseconds() / 1500 ) + 1 ) * 0.25 ) + 0.25 )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			decoration
			visible 1
			style 3
			forecolor 1 1 1 0
			background "mockup_bg_glow"
			textscale 0.55
			exp forecolor a ( ( ( sin( milliseconds() / 480 ) + 1 ) * 0.25 ) + 0.25 )
		}
		itemDef
		{
			rect -64 0 280 480 1 0
			decoration
			visible 1
			style 3
			forecolor 0 0 0 0.25
			background "gradient_fadein_fadebottom"
			textscale 0.55
		}
#endif
#ifdef BACKGROUND_SETTINGS_ADVANCED
		itemDef
		{
			rect 0 0 640 480 4 4
			decoration
			visible 1
			style 3
			forecolor 0 0 0 1
			background "black"
			textscale 0.55
			visible when ( 1 )
		}
		itemDef
		{
			rect 0 0 1708 480 0 0
			decoration
			visible 1
			style 3
			forecolor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			textscale 0.55
			exp rect x ( ( 0 - 107 ) - ( ( float( milliseconds() % 60000 ) / 60000 ) * ( 854 ) ) )
			visible when ( 1 )
		}
		itemDef
		{
			rect 0 0 -1708 -480 0 0
			decoration
			visible 1
			style 3
			forecolor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			textscale 0.55
			exp rect x ( ( - 107 + 854 ) + ( ( float( milliseconds() % 50000 ) / 50000 ) * ( 854 ) ) )
			visible when ( 1 )
		}
		itemDef
		{
			rect -427 -240 854 480 2 2
			decoration
			visible 1
			style 3
			forecolor 1 1 1 1
			background "mw2_main_mp_image"
			textscale 0.55
			visible when ( dvarstring( "gameMode" ) == "mp" )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			decoration
			visible 1
			style 3
			forecolor 1 1 1 0
			background "mockup_bg_glow"
			textscale 0.55
			exp forecolor a ( ( ( sin( milliseconds() / 1500 ) + 1 ) * 0.25 ) + 0.25 )
			visible when ( ! ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) ) )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			decoration
			visible 1
			style 3
			forecolor 1 1 1 0
			background "mockup_bg_glow"
			textscale 0.55
			exp forecolor a ( ( ( sin( milliseconds() / 480 ) + 1 ) * 0.25 ) + 0.25 )
			visible when ( ! ( dvarbool( "cl_ingame" ) || dvarbool( "sv_running" ) ) )
		}
#endif
