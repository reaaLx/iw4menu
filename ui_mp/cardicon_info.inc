#undef CHOICE_HORIZONTAL_ALIGN
#define CHOICE_HORIZONTAL_ALIGN 	2

#undef CHOICE_VERTICAL_ALIGN
#define CHOICE_VERTICAL_ALIGN 		1

#define LOCAL_CARDICON( itemIndex, iconName , iconStat ) \
		itemDef \
		{ \
			name iconName \
			rect ( -224 + 55 * CHOICE_COL( itemIndex ) ) ( 68.67 + 49 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 74.67 74.67 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			background "highlight_selected" \
			type 1 \
			textscale 0.55 \
			exp forecolor g ( 0.45 + ( isitemunlocked( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) && ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) ) ) \
			exp forecolor b ( 0.45 + ( isitemunlocked( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) && ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) ) ) \
			exp forecolor a ( ( getfocuseditemname( ) == iconName ) * ( ( sin( milliseconds( ) / 100 ) * 0.5 + 0.5 ) * 0.5 + 0.5 ) ) \
			visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) ) \
			onFocus \
			{ \
				play "mouse_over"; \
				setLocalVarString "ui_tempVar" ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ); \
				if ( localvarstring( "ui_tempVar" ) != "" ) \
				{ \
					setPlayerData( "iconNew" , "localVarString" ( "ui_tempVar" ) , "false" ); \
				} \
			} \
			action \
			{ \
				if ( isitemunlocked( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) ) \
				{ \
					play "mouse_click"; \
					setLocalVarString "ui_tempVar" ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ); \
					setPlayerData( "cardIcon" , "localVarString" ( "ui_tempVar" ) ); \
				} \
			} \
		} \
		PREPROC_SHADER_DRAW_EXP( ( -208 + 55 * CHOICE_COL( itemIndex ) ) ( 84.67 + 49 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 42.67 42.67 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN, \
		tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 1 ), WINDOW_STYLE_SHADER, CHOICE_TEXTCOLOR \
		visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) && isitemunlocked( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) ) ) \
		PREPROC_SHADER_DRAW_EXP( ( -224 + 55 * CHOICE_COL( itemIndex ) ) ( 68.67 + 49 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 74.67 74.67 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN, \
		"highlight_selected", WINDOW_STYLE_SHADER, CHOICE_TEXTCOLOR \
		exp forecolor a ( getplayerdata( "iconNew" , tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) * ( ( sin( milliseconds( ) / 100 ) * 0.5 + 0.5 ) * 0.25 + 0.75 ) * 0.65 ) \
		visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) ) ) \
		PREPROC_SHADER_DRAW_EXP( ( -208 + 55 * CHOICE_COL( itemIndex ) ) ( 114.67 + 49 * CHOICE_COL ( itemIndex ) + CHOICE_SEP_TOTAL_SPACING ( itemIndex ) ) 40 20 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN, "specialty_new_bg", WINDOW_STYLE_SHADER, CHOICE_TEXTCOLOR \
		exp forecolor a ( getplayerdata( "iconNew" , tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) ) \
		visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) ) ) \
		PREPROC_SHADER_DRAW_EXP( ( -208 + 55 * CHOICE_COL( itemIndex ) ) ( 84.67 + 49 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 42.67 42.67 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN, "cardicon_locked", WINDOW_STYLE_SHADER, CHOICE_TEXTCOLOR \
		visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) && !isitemunlocked( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) ) ) \
