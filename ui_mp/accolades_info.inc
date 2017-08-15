#undef CHOICE_HORIZONTAL_ALIGN
#define CHOICE_HORIZONTAL_ALIGN 	2

#undef CHOICE_VERTICAL_ALIGN
#define CHOICE_VERTICAL_ALIGN 		1

#define CHOICE_ACCOLADE( itemIndex, accoladesName, accoladesIndex ) \
		itemDef \
		{ \
			name accoladesName \
			rect ( -234.952 + 75 * CHOICE_COL( itemIndex ) ) ( 51.3 + 75 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 81.3 81.3 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			background "highlight_selected" \
			type 1 \
			textscale 0.55 \
			exp forecolor g ( 0.45 + ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) ) \
			exp forecolor b ( 0.45 + ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) ) \
			exp forecolor a ( ( getfocuseditemname( ) == accoladesName ) * ( ( sin( milliseconds( ) / 150 ) * 0.5 + 0.5 ) * 0.5 + 0.5 ) ) \
			visible when ( ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) ) \
			onFocus \
			{ \
				setLocalVarInt "ui_highlightIndex" ( accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) ); \
				play "mouse_over"; \
			} \
			action \
			{ \
				play "mouse_click"; \
			} \
		} \
		itemDef \
		{ \
			rect ( -226.286 + 75 * CHOICE_COL( itemIndex ) ) ( 60 + 75 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 64 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			background "award_locked" \
			textscale 0.55 \
			visible when ( ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) && getplayerdata( "awards" , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) ) == 0 ) \
		} \
		itemDef \
		{ \
			rect ( -226.286 + 75 * CHOICE_COL( itemIndex ) ) ( 60 + 75 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 64 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			textscale 0.55 \
			visible when ( ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) && getplayerdata( "awards" , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) ) > 0 ) \
			exp material ( tablelookup( "mp/awardTable.csv" , 1 , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) , 2 ) ) \
		} \
		itemDef \
		{ \
			rect ( -226.286 + 75 * CHOICE_COL( itemIndex ) ) ( 60 + 75 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 64 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			forecolor 1 1 1 1 \
			textfont 3 \
			textalign 14 \
			textstyle 8 \
			textscale 0.375 \
			visible when ( ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) && getplayerdata( "awards" , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) ) > 0 ) \
			exp text ( locstring( "@MPUI_X_N" , getplayerdata( "awards" , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) ) ) ) \
		}