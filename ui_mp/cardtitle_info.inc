#undef CHOICE_HORIZONTAL_ALIGN
#define CHOICE_HORIZONTAL_ALIGN 	2

#undef CHOICE_VERTICAL_ALIGN
#define CHOICE_VERTICAL_ALIGN 		1

#define LOCAL_CARDTITLE( itemIndex, cardName, cardStat ) \
		itemDef \
		{ \
			name cardName \
			rect ( -302 + 190 * CHOICE_COL( itemIndex ) ) ( 71.3 + 30 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 224 53.3 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			background "highlight_selected" \
			type 1 \
			textscale 0.55 \
			exp forecolor g ( 0.45 + ( isitemunlocked( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) && ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) ) ) \
			exp forecolor b ( 0.45 + ( isitemunlocked( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) && ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) ) ) \
			exp forecolor a ( ( getfocuseditemname( ) == cardName ) * ( ( sin( milliseconds( ) / 100 ) * 0.5 + 0.5 ) * 0.5 + 0.5 ) ) \
			visible when ( ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) ) \
			onFocus \
			{ \
				play "mouse_over"; \
				setLocalVarString "ui_tempVar" ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ); \
				if ( localvarstring( "ui_tempVar" ) != "" ) \
				{ \
					setPlayerData( "titleNew" , "localVarString" ( "ui_tempVar" ) , "false" ); \
				} \
			} \
			action \
			{ \
				if ( isitemunlocked( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) ) \
				{ \
					play "mouse_click"; \
					setLocalVarString "ui_tempVar" ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ); \
					setPlayerData( "cardTitle" , "localVarString" ( "ui_tempVar" ) ); \
				} \
			} \
		} \
		itemDef \
		{ \
			rect ( -270 + 190 * CHOICE_COL( itemIndex ) ) ( 81.3 + 30 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 160 32 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 1 1 1 1 \
			textfont 3 \
			textalign 5 \
			textaligny 8 \
			textstyle 8 \
			textscale 0.375 \
			exp forecolor r ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 3 ) ) \
			exp forecolor g ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 4 ) ) \
			exp forecolor b ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 5 ) ) \
			exp forecolor a ( ( 1 * !( getfocuseditemname( ) == cardName ) ) + ( ( ( sin( milliseconds( ) / 100 ) * 0.5 + 0.5 ) * 0.25 + 0.75 ) * ( getfocuseditemname( ) == cardName ) ) ) \
			visible when ( ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) && isitemunlocked( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) ) \
			exp text ( "@" + tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 1 ) ) \
			exp material ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 2 ) ) \
		} \
		itemDef \
		{ \
			rect ( -302 + 190 * CHOICE_COL( itemIndex ) ) ( 71.3 + 30 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 224 53.3 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.25 1 0.45 1 \
			background "highlight_selected" \
			textscale 0.55 \
			exp forecolor a ( getplayerdata( "titleNew" , tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) * ( ( sin( milliseconds( ) / 100 ) * 0.5 + 0.5 ) * 0.5 + 0.5 ) * 0.65 ) \
			visible when ( ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) ) \
		} \
		itemDef \
		{ \
			rect ( -270 + 190 * CHOICE_COL( itemIndex ) ) ( 92 + 30 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 40 20 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			background "specialty_new_bg" \
			textscale 0.55 \
			exp forecolor a ( getplayerdata( "titleNew" , tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) ) \
			visible when ( ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) ) \
		} \
		itemDef \
		{ \
			rect ( -270 + 190 * CHOICE_COL( itemIndex ) ) ( 81.3 + 30 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 160 32 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 1 1 1 1 \
			background "cardtitle_locked" \
			textfont 3 \
			textalign 5 \
			textaligny 8 \
			textscale 0.375 \
			visible when ( ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) && !isitemunlocked( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) ) \
			exp text ( "" ) \
		}		