#define rect_x
#define rect_y
#define rect_w
#define rect_h

#define CHOICE_ACCOLADE( itemIndex, accoladesIndex ) \
		itemDef \
		{ \
			rect -226.286 60 64 64 2 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			textscale 0.55 \
			visible when ( ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) && getplayerdata( "awards" , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) ) > 0 ) \
			exp material ( tablelookup( "mp/awardTable.csv" , 1 , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) , 2 ) ) \
		}	