// rect -234.952 51.3333 81.3333 81.3333 2 1
// rect -234.952 127.333 81.3333 81.3333 2 1

#undef CHOICE_X_START
#define CHOICE_X_START				-75.3333

#undef CHOICE_X_SPACING
#define CHOICE_X_SPACING			81

#undef CHOICE_SIZE_X
#define CHOICE_SIZE_X				41.3333


#undef CHOICE_Y_START
#define CHOICE_Y_START				81.3333

#undef CHOICE_Y_SPACING
#define CHOICE_Y_SPACING			61

#undef CHOICE_SIZE_Y
#define CHOICE_SIZE_Y				51.3333


#undef CHOICE_Y_COUNT
#define CHOICE_Y_COUNT				10

#undef CHOICE_ROW
#define CHOICE_ROW( itemIndex )			( ( itemIndex - 0 ) % CHOICE_Y_COUNT )

#undef CHOICE_COL
#define CHOICE_COL( itemIndex )			( ( itemIndex - 0 - ( ( itemIndex - 0 ) % CHOICE_Y_COUNT ) ) / CHOICE_Y_COUNT )

#undef CHOICE_X
#define CHOICE_X( itemIndex ) 			( CHOICE_X_START + CHOICE_X_SPACING * CHOICE_COL( itemIndex ) )

#undef CHOICE_Y
#define CHOICE_Y( itemIndex ) 			( CHOICE_Y_START + CHOICE_Y_SPACING * CHOICE_ROW( itemIndex ) )

#undef CHOICE_ORIGIN
#define CHOICE_ORIGIN( itemIndex )		CHOICE_X( itemIndex ) CHOICE_Y( itemIndex )

#undef CHOICE_RECT
#define CHOICE_RECT( itemIndex )		CHOICE_ORIGIN( itemIndex ) CHOICE_SIZE_X CHOICE_SIZE_Y CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN

#define CHOICE_ACCOLADES( nameArg, itemIndex, accoladesIndex ) \
		itemDef \
		{ \
			name nameArg \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + 30 ) CHOICE_SIZE_Y CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			background "highlight_selected" \
			group "mw2_button" \
			type 1 \
			textscale 0.55 \
			exp forecolor g ( 0.45 + ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) ) \
			exp forecolor b ( 0.45 + ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) ) \
			exp forecolor a ( ( getfocuseditemname( ) == "highlightImage0_0" ) * ( ( sin( milliseconds( ) / 150 ) * 0.5 + 0.5 ) * 0.5 + 0.5 ) ) \
			visible when ( ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) ) \
			onFocus \
			{ \
				setLocalVarInt "ui_highlightIndex" ( accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) ); \
				setLocalVarBool "ui_highlightButton" ( 1 ); \
				setItemColor self backcolor 1 1 1 1; \
				play "mouse_over"; \
			} \
			leaveFocus \
			{ \
				setLocalVarInt "ui_highlightIndex" ( accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) ) \
				setLocalVarBool "ui_highlightButton" ( 0 ); \
				setItemColor self backcolor 0 0 0 0; \
			} \
			action \
			{ \
				play "mouse_click"; \
			} \
		} \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + 30 ) CHOICE_SIZE_Y CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			background "award_locked" \
			textscale 0.55 \
			visible when ( ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) && getplayerdata( "awards" , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) ) == 0 )  \
		} \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + 30 ) CHOICE_SIZE_Y CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
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
			rect CHOICE_ORIGIN( itemIndex ) ( CHOICE_SIZE_X + 30 ) CHOICE_SIZE_Y CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			forecolor 1 1 1 1 \
			textfont 3 \
			textalign 14 \
			textscale 0.375 \
			visible when ( ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) && getplayerdata( "awards" , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) ) > 0 ) \
			exp text ( locstring( "@MPUI_X_N" , getplayerdata( "awards" , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) ) ) ) \
		}