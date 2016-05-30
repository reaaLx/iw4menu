//---------------- icon ----------------
		itemDef
		{
			rect 10 58 128 128 1 1
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0.275
			textscale 0.55
			visible when ( localvarstring( "ui_team" ) == "marines" )
			exp material ( dvarstring( "g_TeamIcon_Allies" ) )
		}
		itemDef
		{
			rect 10 58 128 128 1 1
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0.275
			textscale 0.55
			visible when ( localvarstring( "ui_team" ) == "opfor" )
			exp material ( dvarstring( "g_TeamIcon_Axis" ) )
		}
		itemDef
		{
			rect 10 58 128 128 1 1
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0.275
			textscale 0.55
			visible when ( team( "name" ) == "TEAM_FREE" && localvarstring( "ui_team" ) == "marines" )
			exp material ( dvarstring( "g_TeamIcon_Allies" ) )
		}
		itemDef
		{
			rect 10 58 128 128 1 1
			style 3
			decoration
			visible 1
			forecolor 1 1 1 0.275
			textscale 0.55
			visible when ( team( "name" ) == "TEAM_FREE" && localvarstring( "ui_team" ) == "opfor" )
			exp material ( dvarstring( "g_TeamIcon_Axis" ) )
		}
//--------------- name -----------------
		itemDef
		{
			rect 10 196 128 128 1 1
			decoration
			visible 1
			forecolor 1 1 1 0.2
			textfont 6
			textscale 0.4583
			textstyle 6
			visible when ( team( "name" ) == "TEAM_ALLIES" )
			exp text ( "@" + dvarstring( "g_TeamName_Allies" ) )
		}
		itemDef
		{
			rect 10 196 128 128 1 1
			decoration
			visible 1
			forecolor 1 1 1 0.2
			textfont 6
			textscale 0.4583
			textstyle 6
			visible when ( team( "name" ) == "TEAM_FREE" && localvarstring( "ui_team" ) == "marines" )
			exp text ( "@" + dvarstring( "g_TeamName_Allies" ) )
		}
		itemDef
		{
			rect 10 196 128 128 1 1
			decoration
			visible 1
			forecolor 1 1 1 0.2
			textfont 6
			textscale 0.4583
			textstyle 6
			visible when ( team( "name" ) == "TEAM_AXIS" )
			exp text ( "@" + dvarstring( "g_TeamName_Axis" ) )
		}
		itemDef
		{
			rect 10 196 128 128 1 1
			decoration
			visible 1
			forecolor 1 1 1 0.2
			textfont 6
			textscale 0.4583
			textstyle 6
			visible when ( team( "name" ) == "TEAM_FREE" && localvarstring( "ui_team" ) == "opfor" )
			exp text ( "@" + dvarstring( "g_TeamName_Axis" ) )
		}