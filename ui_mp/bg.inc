		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			foreColor 1 1 1 1
			background "mw2_main_background"
			decoration 
			textScale 0.55
			visible 1
		}
#ifdef BACKGROUND_SP
		itemDef
		{
			rect -107 0 854 480
			style 3
			foreColor 1 1 1 1
			background "mw2_main_sp_image"
			decoration 
			visible 1
		}
#endif
#ifdef BACKGROUND_SO
		itemDef
		{
			rect -107 0 854 480
			style 3
			foreColor 1 1 1 1
			background "mw2_main_co_image"
			decoration 
			visible 1
		}
#endif
#ifdef BACKGROUND_MP
		itemDef
		{
			rect -107 0 854 480 0 0
			style 3
			foreColor 1 1 1 1
			background "mw2_main_mp_image"
			decoration 
			visible 1
		}
#endif
		itemDef
		{
			rect 0 0 1708 480 0 0
			style 3
			foreColor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			decoration 
			textScale 0.55
			exp rect x ( ( 0 - 107 ) - ( ( float( milliseconds() % 60000 ) / 60000 ) * ( 854 ) ) )
			visible 1
		}
		itemDef
		{
			rect 0 0 -1708 -480 0 0
			style 3
			foreColor 1 1 1 0.5
			background "mw2_main_cloud_overlay"
			decoration 
			textScale 0.55
			exp rect x ( ( - 107 + 854 ) + ( ( float( milliseconds() % 50000 ) / 50000 ) * ( 854 ) ) )
			visible 1
		}

		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			foreColor 1 1 1 0
			background "mockup_bg_glow"
			decoration 
			textScale 0.55
			exp forecolor a ( ( ( sin ( milliseconds() / 1500 ) + 1 ) * 0.25 ) + 0.25 )
			visible 1
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			style 3
			foreColor 1 1 1 0
			background "mockup_bg_glow"
			decoration 
			textScale 0.55
			visible 1
			exp forecolor a ( ( ( sin ( milliseconds() / 480 ) + 1 ) * 0.25 ) + 0.25 )
		}
		itemDef
		{
			rect 0 0 640 480 4 4
			decoration
			visible 1
			style 3
			forecolor 1 1 1 0.2
			background "big_menu_lightfx"
			textscale 0.55
		}
#ifndef BACKGROUND_SIDEBAR
		itemDef
		{
			rect -64 0 280 480 1 0
			style 3
			foreColor 1 1 1 0.1
			background "gradient_fadein_fadebottom"
			decoration 
			textScale 0.55
			visible 1
		}
#endif