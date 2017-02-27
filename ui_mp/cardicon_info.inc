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
		itemDef \
		{ \
			rect ( -208 + 55 * CHOICE_COL( itemIndex ) ) ( 84.67 + 49 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 42.67 42.67 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			textscale 0.55 \
			visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) && isitemunlocked( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) ) \
			exp material ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 1 ) ) \
		} \
		itemDef \
		{ \
			rect ( -224 + 55 * CHOICE_COL( itemIndex ) ) ( 68.67 + 49 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 74.67 74.67 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.25 1 0.45 1 \
			background "highlight_selected" \
			textscale 0.55 \
			exp forecolor a ( getplayerdata( "iconNew" , tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) * ( ( sin( milliseconds( ) / 100 ) * 0.5 + 0.5 ) * 0.25 + 0.75 ) * 0.65 ) \
			visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) ) \
		} \
		itemDef \
		{ \
			rect ( -208 + 55 * CHOICE_COL( itemIndex ) ) ( 114.67 + 49 * CHOICE_COL ( itemIndex ) + CHOICE_SEP_TOTAL_SPACING ( itemIndex ) ) 40 20 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			background "specialty_new_bg" \
			textscale 0.55 \
			exp forecolor a ( getplayerdata( "iconNew" , tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) ) \
			visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) ) \
		} \
		itemDef \
		{ \
			rect ( -208 + 55 * CHOICE_COL( itemIndex ) ) ( 84.67 + 49 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 42.67 42.67 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			background "cardicon_locked" \
			textscale 0.55 \
			visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) && !isitemunlocked( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) ) \
		}		