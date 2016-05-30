// map display ================================================

		itemDef
		{
			name "fullmap_border"
			rect -260 135 240 240 3 1
			border 1
			bordersize 0.666667
			decoration
			visible 1
			forecolor 1 1 1 1
			bordercolor 1 1 1 0.35
			textscale 0.55
			visible when ( ( !isempjammed( ) ) )
		}
		itemDef
		{
			rect -260 135 240 240 3 1
			style 3
			decoration
			visible 1
			forecolor 0.89 0.98 0.95 0.05
			background "minimap_scanlines"
			textscale 0.55
			visible when ( ( !isempjammed( ) ) )
		}
		itemDef
		{
			name "fullmap_map"
			rect -260 135 240 240 3 1
			ownerdraw 181
			decoration
			visible 1
			forecolor 1 1 1 1
			background "compass_map_default"
			type 8
			textscale 0.55
			visible when ( ( !isempjammed( ) ) )
		}
		itemDef
		{
			name "fullmap_friendlies"
			rect -260 135 240 240 3 1
			ownerdraw 185
			decoration
			visible 1
			forecolor 1 1 1 1
			type 8
			textscale 0.55
			exp forecolor a ( 1 - radarjamintensity( ) )
			visible when ( ( !isempjammed( ) ) )
		}
		itemDef
		{
			name "fullmap_enemies"
			rect -260 135 240 240 3 1
			ownerdraw 188
			decoration
			visible 1
			forecolor 1 1 1 1
			type 8
			textscale 0.55
			exp forecolor a ( 1 - radarjamintensity( ) )
			visible when ( ( !isempjammed( ) ) )
		}
		itemDef
		{
			name "fullmap_objectives"
			rect -260 135 240 240 3 1
			ownerdraw 182
			decoration
			visible 1
			forecolor 1 1 1 1
			background "objective_line"
			type 8
			textscale 0.55
			visible when ( ( !isempjammed( ) ) )
		}
		itemDef
		{
			name "fullmap_sentries"
			rect -260 135 240 240 3 1
			ownerdraw 189
			decoration
			visible 1
			forecolor 1 1 1 1
			type 8
			textscale 0.55
			exp forecolor a ( 1 - radarjamintensity( ) )
			visible when ( ( !isempjammed( ) ) )
		}
		itemDef
		{
			name "fullmap_player"
			rect -260 135 240 240 3 1
			ownerdraw 183
			decoration
			visible 1
			forecolor 1 1 1 1
			background "compassping_player"
			type 8
			textscale 0.55
			exp forecolor a ( 1 - radarjamintensity( ) )
			visible when ( ( !isempjammed( ) ) )
		}
		itemDef
		{
			rect -260 135 240 240 3 1
			style 3
			decoration
			visible 1
			forecolor 0.64 0.74 0.71 1
			background "white"
			textscale 0.55
			exp forecolor a ( radarjamintensity( ) )
			visible when ( radarisjammed( ) && ( !isempjammed( ) ) )
		}
		itemDef
		{
			rect -260 135 240 240 3 1
			style 3
			decoration
			visible 1
			forecolor 0.89 0.98 0.95 1
			background "ac130_overlay_grain"
			textscale 0.55
			exp forecolor a ( radarjamintensity( ) )
			visible when ( radarisjammed( ) && ( !isempjammed( ) ) )
		}
		itemDef
		{
			rect -260 135 240 240 3 1
			style 3
			decoration
			visible 1
			forecolor 1 1 1 1
			background "stencil_base"
			textscale 0.55
			visible when ( ( !isempjammed( ) ) )
		}
		itemDef
		{
			rect -260 135 240 240 3 1
			style 3
			decoration
			visible 1
			forecolor 1 1 1 1
			background "scanlines_stencil"
			textscale 0.55
			exp rect y ( ( 135 - 240 ) + ( ( 240 * 2 ) * ( 1 - ( ( milliseconds( ) % 4000 ) / 4000 ) ) ) )
			visible when ( ( !isempjammed( ) ) )
		}
		itemDef
		{
			rect -260 135 240 240 3 1
			style 3
			decoration
			visible 1
			forecolor 0.89 0.98 0.95 1
			background "stencil_fill"
			textscale 0.55
			visible when ( ( !isempjammed( ) ) )
		}
		itemDef
		{
			rect -260 115 -136 20 3 1
			style 1
			decoration
			visible 1
			forecolor 1 1 1 1
			backcolor 0 0 0 0.35
			background "gradient_fadein"
			textfont 9
			textalign 4
			textalignx 4
			textscale 0.375
			visible when ( ( !isempjammed( ) ) )
			exp text ( getmapname( ) )
		}