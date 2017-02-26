#define TEXTBUTTON_COLOR			0.9 0.9 0.92 0.75

#define OPTIONS_HEADING_JOIN_COLOR	0.9 0.9 0.95 0.175

#define		FILTER_Y_SPACING	20
#define		FILTER_WIDTH		254
#define		X_FILTER			-58
#define		X_FILTERB			(X_FILTER+FILTER_WIDTH)
#define		Y_FILTER			-30
#define 	ORIGIN_FILTER1		X_FILTER Y_FILTER
#define 	ORIGIN_FILTER2		X_FILTER (Y_FILTER+FILTER_Y_SPACING)
#define 	ORIGIN_FILTER3		X_FILTER (Y_FILTER+(FILTER_Y_SPACING*2))
#define 	ORIGIN_FILTER4		8 (Y_FILTER+(FILTER_Y_SPACING*2))

#define 	ORIGIN_FILTER1B		X_FILTERB Y_FILTER
#define 	ORIGIN_FILTER2B		X_FILTERB (Y_FILTER+FILTER_Y_SPACING)
#define 	ORIGIN_FILTER3B		X_FILTERB (Y_FILTER+(FILTER_Y_SPACING*2))
#define 	ORIGIN_FILTER4B		X_FILTERB (Y_FILTER+(FILTER_Y_SPACING*3))

#define 	TAB_NAME_Y			68

#define		TAB_BG_COLOR		OPTIONS_HEADING_JOIN_COLOR
#define		TAB_BORDER_COLOR	0.1 0.1 0.12 0.5

#define		CUSTOM_BUTTON_TEXT_SIZE	0.33

#undef CHOICE_HORIZONTAL_ALIGN 
#define CHOICE_HORIZONTAL_ALIGN HORIZONTAL_ALIGN_CENTER 

#undef CHOICE_VERTICAL_ALIGN
#define CHOICE_VERTICAL_ALIGN VERTICAL_ALIGN_TOP

// custom button highlights
CHOICE_HIGHLIGHT_CUSTOM_2( (X_FILTER-10), Y_FILTER, (FILTER_WIDTH-20), (FILTER_Y_SPACING-2), when( localVarString( ui_choicegroup ) == CHOICE_GROUP && localVarInt( "ui_highlight" ) == 1 ); )
CHOICE_HIGHLIGHT_CUSTOM_2( (X_FILTER-10), (Y_FILTER+FILTER_Y_SPACING), (FILTER_WIDTH-20), (FILTER_Y_SPACING-2), when( localVarString( "ui_choicegroup" ) == CHOICE_GROUP && localVarInt( "ui_highlight" ) == 2 ); )
CHOICE_HIGHLIGHT_CUSTOM_2( (X_FILTER-10), (Y_FILTER+(FILTER_Y_SPACING*2)), (FILTER_WIDTH-20), (FILTER_Y_SPACING-2), when( localVarString( "ui_choicegroup" ) == CHOICE_GROUP && localVarInt( "ui_highlight" ) == 3 ); )
CHOICE_HIGHLIGHT_CUSTOM_2( (X_FILTERB-10), Y_FILTER, (FILTER_WIDTH-20), (FILTER_Y_SPACING-2), when( localVarString( "ui_choicegroup" ) == CHOICE_GROUP && localVarInt( ui_highlight ) == 4 ); )
CHOICE_HIGHLIGHT_CUSTOM_2( (X_FILTERB-10), (Y_FILTER+FILTER_Y_SPACING), (FILTER_WIDTH-20), (FILTER_Y_SPACING-2), when( localVarString( "ui_choicegroup" ) == CHOICE_GROUP && localVarInt( "ui_highlight" ) == 5 ); )
CHOICE_HIGHLIGHT_CUSTOM_2( (X_FILTERB-10), (Y_FILTER+(FILTER_Y_SPACING*2)), (FILTER_WIDTH-20), (FILTER_Y_SPACING-2), when( localVarString( "ui_choicegroup" ) == CHOICE_GROUP && localVarInt( "ui_highlight" ) == 6 ); )

itemDef	
{
	name "sourcefield"
	style WINDOW_STYLE_FILLED
	textFont	UI_FONT_NORMAL
	ownerdraw UI_NETSOURCE
	rect ORIGIN_FILTER1 170 15 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
	textStyle 3
	textAlign ITEM_ALIGN_LEFT
	textAlignX 0
	textAlignY 16
	textStyle 3
	textScale CUSTOM_BUTTON_TEXT_SIZE
	foreColor 1 1 1 1
	backColor 0 0 0 0
	visible 1
	onFocus
	{ 
		setLocalVarInt ui_highlight ( 1 ); 
		setLocalVarString ui_choicegroup ( CHOICE_GROUP );
	}
	leaveFocus
	{ 
		setLocalVarInt ui_highlight ( 0 ); 
		setLocalVarString ui_choicegroup ( "@NULL_EMPTY" );
	}
	action
	{
		play "mouse_click";
	}
	mouseEnter
	{
		show "message_source";
		play "mouse_over";
	}
	mouseExit
	{ 
		hide "message_source";
	}
}
itemDef	
{
	name "gametypefield"
	style WINDOW_STYLE_FILLED
	textStyle 3
	text "@MENU_GAME_TYPE"
	ownerdraw UI_JOINGAMETYPE
	textFont	UI_FONT_NORMAL
	rect ORIGIN_FILTER2 170 15 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
	textAlign ITEM_ALIGN_LEFT
	textAlignX 0
	textAlignY 16
	textScale CUSTOM_BUTTON_TEXT_SIZE
	foreColor 1 1 1 1
	border 0
	borderColor 0 0 0 0
	backColor 0 0 0 0
	visible 1
	onFocus
	{ 
		setLocalVarInt "ui_highlight" ( 2 ); 
		setLocalVarString "ui_choicegroup" ( CHOICE_GROUP );
	}
	leaveFocus
	{ 
		setLocalVarInt "ui_highlight" ( 0 ); 
		setLocalVarString "ui_choicegroup" ( "@NULL_EMPTY" );
	}
	action 
	{ 
		play "mouse_click"; 
	}
	mouseEnter
	{ 
		show "message_typefilter"; 
		play "mouse_over";
	}
	mouseExit
	{ 
		hide "message_typefilter";
	}
}
itemDef 
{
	name "filterServers"
	text "@MENU_FILTER_SERVERS"
	type ITEM_TYPE_BUTTON
	textFont UI_FONT_NORMAL
	textScale CUSTOM_BUTTON_TEXT_SIZE
	textStyle ITEM_TEXTSTYLE_SHADOWED
	style WINDOW_STYLE_FILLED
	rect ORIGIN_FILTER3 130 15 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
	textAlign ITEM_ALIGN_LEFT
	textAlignX 0
	textAlignY 16
	foreColor .9 .9 .95 1
	visible 1
	onFocus
	{ 
		setLocalVarInt "ui_highlight" ( 3 ); 
		setLocalVarString "ui_choicegroup" ( CHOICE_GROUP );
	}
	leaveFocus
	{ 
		setLocalVarInt "ui_highlight" ( 0 ); 
		setLocalVarString "ui_choicegroup" ( "@NULL_EMPTY" );
	}
	action 
	{
		play "mouse_click";
		open "filter_popmenu";
	}
	mouseEnter 
	{ 
		show "message_filterServers"; 
		play "mouse_over"; 
	}
	mouseExit 
	{ 
		hide "message_filterServers"; 
	}
}
itemDef	
{
	name "refreshdate"
	ownerdraw UI_SERVERREFRESHDATE
	textStyle ITEM_TEXTSTYLE_SHADOWED
	textFont UI_FONT_NORMAL
	textScale 0.25
	rect ORIGIN_FILTER4 265 18
	textAlign ITEM_ALIGN_LEFT
	textAlignX 0
	textAlignY 16
	foreColor 1 1 1 1
	visible 1
	decoration
}
itemDef 
{
	name "refreshSource"
	text "@MENU_REFRESH_LIST"
	type ITEM_TYPE_BUTTON
	textScale CUSTOM_BUTTON_TEXT_SIZE
	textStyle ITEM_TEXTSTYLE_SHADOWED
	style WINDOW_STYLE_FILLED
	rect ORIGIN_FILTER1B 130 15 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
	textAlign ITEM_ALIGN_LEFT
	textAlignX 0
	textAlignY 16
	textFont UI_FONT_NORMAL
	foreColor .9 .9 .95 1
	visible 1
	onFocus
	{ 
		setLocalVarInt "ui_highlight" ( 4 ); 
		setLocalVarString "ui_choicegroup" ( CHOICE_GROUP );
	}
	leaveFocus
	{ 
		setLocalVarInt "ui_highlight" ( 0 ); 
		setLocalVarString "ui_choicegroup" ( "@NULL_EMPTY" );
	}
	mouseEnter 
	{ 
		show "message_refreshSource"; 
		play "mouse_over"; 
	}
	mouseExit
	{ 
		hide "message_refreshSource"; 
	}
	action
	{
		play "mouse_click"; 
		uiScript "RefreshServers";
	}
}
itemDef 
{
	name "refreshFilter"
	text "@MENU_QUICK_REFRESH"
	textScale CUSTOM_BUTTON_TEXT_SIZE
	textStyle ITEM_TEXTSTYLE_SHADOWED
	style WINDOW_STYLE_FILLED
	textFont UI_FONT_NORMAL
	type ITEM_TYPE_BUTTON
  	rect ORIGIN_FILTER2B 130 15  CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
	textAlign ITEM_ALIGN_LEFT
	textAlignX 0
	textAlignY 16
	foreColor .9 .9 .95 1
	visible 1
	onFocus
	{
		setLocalVarInt "ui_highlight" ( 5 ); 
		setLocalVarString "ui_choicegroup" ( CHOICE_GROUP );
	}
	leaveFocus
	{
		setLocalVarInt "ui_highlight" ( 0 ); 
		setLocalVarString "ui_choicegroup" ( "@NULL_EMPTY" );
	}
	mouseEnter
	{
		show "message_refreshFilter"; 
		play "mouse_over"; 
	}
	mouseExit 
	{
		hide "message_refreshFilter"; 
	}
	action
	{
		play "mouse_click"; 
		uiScript "RefreshFilter";
	}
}
itemDef 
{
	text "@MENU_NEW_FAVORITE"
	type ITEM_TYPE_BUTTON
	textFont UI_FONT_NORMAL
	textScale CUSTOM_BUTTON_TEXT_SIZE
	textStyle ITEM_TEXTSTYLE_SHADOWED
	style WINDOW_STYLE_FILLED
	rect ORIGIN_FILTER3B 130 15 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
	textAlign ITEM_ALIGN_LEFT
	textAlignX 0
	textAlignY 16
	foreColor CHOICE_TEXTCOLOR_DISABLED
	visible when( dvarInt( "ui_netSource" ) != 2 )
	decoration
}
itemDef 
{
	name "createFavorite"
	text "@MENU_NEW_FAVORITE"
	type ITEM_TYPE_BUTTON
	textFont UI_FONT_NORMAL
	textScale CUSTOM_BUTTON_TEXT_SIZE
	textStyle ITEM_TEXTSTYLE_SHADOWED
	style WINDOW_STYLE_FILLED
	rect ORIGIN_FILTER3B 130 15  CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
	textAlign ITEM_ALIGN_LEFT
	textAlignX 0
	textAlignY 16
	foreColor .9 .9 .95 1
	visible 1
	// Only show when view favorite servers list
	dvarTest "ui_netSource"
	showDvar { "2" }
	onFocus
	{
		setLocalVarInt "ui_highlight" ( 6 ); 
		setLocalVarString "ui_choicegroup" ( CHOICE_GROUP );
	}
	leaveFocus
	{
		setLocalVarInt "ui_highlight" ( 0 ); 
		setLocalVarString "ui_choicegroup" ( "@NULL_EMPTY" );
	}
	mouseEnter
	{
	show "message_createFavorite";
	play "mouse_over";
	}
	mouseExit
	{
		hide "message_createFavorite";
	}
	action
	{
		play "mouse_click";
		open "createfavorite_popmenu";
	}
}

#define WIDTH_PASSWORD		20 
#define WIDTH_HARDWARE		20 
#define WIDTH_SERVER		208
#define WIDTH_MAP			70
#define WIDTH_PLAYER		50
#define WIDTH_TYPE			102
#define WIDTH_VOICE			80 
#define WIDTH_PURE			20 
#define WIDTH_MOD			20 
#define WIDTH_PB			20
#define WIDTH_PING			50 

#define TAB_HEIGHT			16
#define TAB_LABEL_OFFSET \
		textAlignX 4 	 \
		textAlignY (14)

#define TABLE_X				4
#define TABLE_Y				64

#define PASSWORD_X			(4) 			
#define HARDWARE_X			(26)
#define SERVER_X			(48)
#define MAP_X				(258) 	
#define PLAYER_X			(330) 	
#define TYPE_X				(382) 	
#define VOICE_X				(486) 	
#define PURE_X				(568) 	
#define MOD_X				(590) 	
#define PB_X				(612) 
#define PING_X				(568) 	

#define TABLE_HEIGHT		330
#define TABLE_WIDTH			(638)

// table bg color
itemDef	
{
	name "window"
	group "grpSystembutton"
	rect TABLE_X TABLE_Y TABLE_WIDTH TABLE_HEIGHT
	style WINDOW_STYLE_FILLED
	foreColor 1 1 1 1
	backColor 0 0 0 .3
	visible 1
	decoration
}

#define ORIGIN_PASSWORD   	PASSWORD_X	TABLE_Y
#define ORIGIN_HARDWARE    	HARDWARE_X	TABLE_Y
#define ORIGIN_SERVER 	   	SERVER_X	TABLE_Y
#define ORIGIN_MAP 		   	MAP_X		TABLE_Y
#define ORIGIN_PLAYER 	   	PLAYER_X	TABLE_Y
#define ORIGIN_TYPE 	   	TYPE_X		TABLE_Y
#define ORIGIN_VOICE 	   	VOICE_X		TABLE_Y
#define ORIGIN_PURE 	   	PURE_X		TABLE_Y
#define ORIGIN_MOD 		   	MOD_X		TABLE_Y
#define ORIGIN_PB			PB_X		TABLE_Y
#define ORIGIN_PING 	   	PING_X		TABLE_Y

#define RECT_PASSWORD		ORIGIN_PASSWORD 	WIDTH_PASSWORD 		TABLE_HEIGHT
#define RECT_HARDWARE		ORIGIN_HARDWARE 	WIDTH_HARDWARE 		TABLE_HEIGHT
#define RECT_SERVER			ORIGIN_SERVER 		WIDTH_SERVER 		TABLE_HEIGHT
#define RECT_MAP			ORIGIN_MAP 			WIDTH_MAP 			TABLE_HEIGHT
#define RECT_PLAYER			ORIGIN_PLAYER 		WIDTH_PLAYER 		TABLE_HEIGHT
#define RECT_TYPE			ORIGIN_TYPE 		WIDTH_TYPE 			TABLE_HEIGHT
#define RECT_VOICE			ORIGIN_VOICE 		WIDTH_VOICE 		TABLE_HEIGHT
#define RECT_PURE			ORIGIN_PURE 		WIDTH_PURE 			TABLE_HEIGHT
#define RECT_MOD			ORIGIN_MOD 			WIDTH_MOD 			TABLE_HEIGHT
#define RECT_PB				ORIGIN_PB			WIDTH_PB			TABLE_HEIGHT
#define RECT_PING			ORIGIN_PING 		WIDTH_PING 			TABLE_HEIGHT

//	SERVER LIST COLUMN OUTLINES	=====================================================================
#define PREPROC_COLUMN_BOX( pname, prect ) PREPROC_COLUMN_BOX_RAW( pname, prect, 0 0 0 0 )
#define PREPROC_COLUMN_BOX_RAW( pname, prect, pcolor ) \
		itemDef	\
		{ \
			name pname \
			group grpColumn \
			rect prect 0 0 \
			origin -2 -2 \
			style WINDOW_STYLE_FILLED \
			border 1 \
			backColor pcolor \
			borderColor TAB_BORDER_COLOR \
			visible 1 \
			decoration \
		}
	
PREPROC_COLUMN_BOX( passwordColumn, ORIGIN_PASSWORD 	(WIDTH_PASSWORD+2) 		TABLE_HEIGHT)
PREPROC_COLUMN_BOX( hardwareColumn, ORIGIN_HARDWARE 	(WIDTH_HARDWARE+2) 		TABLE_HEIGHT)
PREPROC_COLUMN_BOX( serverColumn,  	ORIGIN_SERVER 		(WIDTH_SERVER+2) 		TABLE_HEIGHT)
PREPROC_COLUMN_BOX( mapColumn,  	ORIGIN_MAP 			(WIDTH_MAP+2) 			TABLE_HEIGHT)
PREPROC_COLUMN_BOX( playerColumn,  	ORIGIN_PLAYER 		(WIDTH_PLAYER+2) 		TABLE_HEIGHT)
PREPROC_COLUMN_BOX( typeColumn,  	ORIGIN_TYPE 		(WIDTH_TYPE+2) 			TABLE_HEIGHT)
PREPROC_COLUMN_BOX( voiceColumn,  	ORIGIN_VOICE 		(WIDTH_VOICE+2) 		TABLE_HEIGHT)
PREPROC_COLUMN_BOX( pureColumn,  	ORIGIN_PURE 		(WIDTH_PURE+2) 			TABLE_HEIGHT)
PREPROC_COLUMN_BOX( modColumn,  	ORIGIN_MOD 			(WIDTH_MOD+2) 			TABLE_HEIGHT)
PREPROC_COLUMN_BOX( pbColumn,  		ORIGIN_PB 			(WIDTH_PB+2) 			TABLE_HEIGHT)
PREPROC_COLUMN_BOX_RAW( pingColumn, ORIGIN_PING 		(WIDTH_PING+2)			TABLE_HEIGHT, 0 0 0.4 .15)
		

// SERVER LIST TEXT ===========================================================
itemDef
{
	name "serverlist"
	rect TABLE_X TABLE_Y (TABLE_WIDTH - 8 ) (TABLE_HEIGHT - 17 )
	origin 0 16
	type ITEM_TYPE_LISTBOX
	style WINDOW_STYLE_FILLED
	elementwidth 120
	elementheight 16
	textFont UI_FONT_NORMAL
	textAlign 1
	textAlignY 0
	textScale 0.25
	elementtype LISTBOX_TEXT
	feeder FEEDER_SERVERS
	foreColor 1 1 1 1
	backColor 0 0 0 0
	outlinecolor OPTIONS_HEADING_JOIN_COLOR
	visible 1
	//		numcols	xpos			xwidth			textlen
	columns	11		PASSWORD_X		16				20
					HARDWARE_X		16				10
					SERVER_X		WIDTH_SERVER	22
					MAP_X			WIDTH_MAP		25
					PLAYER_X		WIDTH_PLAYER	10
					TYPE_X			WIDTH_TYPE		22
					VOICE_X			16				14
					PURE_X			16				10
					MOD_X			16				20
					PB_X			WIDTH_PB		20
					PING_X			WIDTH_PING		20
	doubleClick { uiScript "JoinServer"; }
	execKeyInt 13 { uiScript "JoinServer"; }
}

#undef	TABLE_HEIGHT
#define TABLE_HEIGHT TAB_HEIGHT

		// PASSWORD ==============================================================
		itemDef
		{
			name "password"
			group grpTabs
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_FILLED
			rect RECT_PASSWORD
			foreColor 1 1 1 1
			backColor OPTIONS_HEADING_JOIN_COLOR
			visible 1
			action
			{
				play "mouse_click" ;
				uiScript ServerSort 0 ;
				setItemColor grpTabs backColor TAB_BG_COLOR ;
				setItemColor password backColor .1 .2 .37 1 ;
				setItemColor grpColumn backColor 0 0 0 0 ;
				setItemColor passwordColumn backColor 0 0 0.4 .15
			}
			mouseEnter { show message_sort ; setItemColor passwordColumn borderColor 1 1 1 1 ; play "mouse_over" }
			mouseExit { hide message_sort ; setItemColor passwordColumn borderColor TAB_BORDER_COLOR }
		}
		itemDef
		{
			name "passwordicon"
			style WINDOW_STYLE_SHADER
			rect ORIGIN_PASSWORD 16 16
			origin 3 0
			background "hud_server_locked"
			visible 1
			decoration
		}

		// HARDWARE ==============================================================
		itemDef
		{
			name hardware
			group grpTabs
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_FILLED
			rect RECT_HARDWARE
			foreColor 1 1 1 1
			backColor OPTIONS_HEADING_JOIN_COLOR
			visible 1
			action
			{
				play "mouse_click" ;
				uiScript ServerSort 1 ;
				setItemColor grpTabs backColor TAB_BG_COLOR ;
				setItemColor hardware backColor .1 .2 .37 1 ;
				setItemColor grpColumn backColor 0 0 0 0 ;
				setItemColor hardwareColumn backColor 0 0 0.4 .15
			}
			mouseEnter { show message_sort ; setItemColor hardwareColumn borderColor 1 1 1 1 ; play "mouse_over" }
			mouseExit { hide message_sort ; setItemColor hardwareColumn borderColor TAB_BORDER_COLOR }
		}
		itemDef
		{
			name hardwareicon
			style WINDOW_STYLE_SHADER
			rect ORIGIN_HARDWARE 16 16
			origin 3 0
			background "server_hardware_header"
			visible 1
			decoration
		}
		
		// SERVER ================================================================
		itemDef
		{
			name "server"
			group grpTabs
			text "@MENU_SERVER NAME"
			TAB_LABEL_OFFSET
			type ITEM_TYPE_BUTTON
			textScale 0.25
			textFont	UI_FONT_NORMAL
			style WINDOW_STYLE_FILLED
			rect RECT_SERVER
			textAlign ITEM_ALIGN_LEFT
			foreColor 1 1 1 1
			backColor OPTIONS_HEADING_JOIN_COLOR
			visible 1
			action
			{
				play "mouse_click" ;
				uiScript ServerSort 2 ;
				setItemColor grpTabs backColor TAB_BG_COLOR ;
				setItemColor server backColor .1 .2 .37 1 ;
				setItemColor grpColumn backColor 0 0 0 0 ;
				setItemColor serverColumn backColor 0 0 0.4 .15
			}
			mouseEnter { show message_sort ; setItemColor serverColumn borderColor 1 1 1 1 ; play "mouse_over" }
			mouseExit { hide message_sort ; setItemColor serverColumn borderColor TAB_BORDER_COLOR }
		}

		// MAP ===================================================================
		itemDef
		{
			name "map"
			group grpTabs
			type ITEM_TYPE_BUTTON
			text "@MENU_MAP_NAME"
			TAB_LABEL_OFFSET
			textScale 0.25
			textFont	UI_FONT_NORMAL
			style WINDOW_STYLE_FILLED
			rect RECT_MAP
			textAlign ITEM_ALIGN_LEFT
			backColor OPTIONS_HEADING_JOIN_COLOR
			foreColor 1 1 1 1
			visible 1
			action
			{
				play "mouse_click" ;
				uiScript ServerSort 3 ;
				setItemColor grpTabs backColor TAB_BG_COLOR ;
				setItemColor map backColor .1 .2 .37 1 ;
				setItemColor grpColumn backColor 0 0 0 0 ;
				setItemColor mapColumn backColor 0 0 .4 .15
			}
			mouseEnter { show message_sort ; setItemColor mapColumn borderColor 1 1 1 1 ; play "mouse_over"}
			mouseExit { hide message_sort ; setItemColor mapColumn borderColor TAB_BORDER_COLOR }
		}

		// PLAYERS ===============================================================
		itemDef
		{
			name "players"
			group grpTabs
			text "@MENU_NUMPLAYERS"
			TAB_LABEL_OFFSET
			type ITEM_TYPE_BUTTON
			textScale 0.25
			style WINDOW_STYLE_FILLED
			textFont	UI_FONT_NORMAL
			rect RECT_PLAYER
			textAlign ITEM_ALIGN_LEFT
			foreColor 1 1 1 1
			backColor OPTIONS_HEADING_JOIN_COLOR
			visible 1
			action
			{
				play "mouse_click" ;
				uiScript ServerSort 4 ;
				setItemColor grpTabs backColor TAB_BG_COLOR ;
				setItemColor Players backColor .1 .2 .37 1 ;
				setItemColor grpColumn backColor 0 0 0 0 ;
				setItemColor playerColumn backColor 0 0 .4 .15
			}
			mouseEnter { show message_sort ; setItemColor playerColumn borderColor 1 1 1 1 ; play "mouse_over"}
			mouseExit { hide message_sort ; setItemColor playerColumn borderColor TAB_BORDER_COLOR }
		}

		// TYPE ==================================================================
		itemDef
		{
			name "type"
			group grpTabs
			text "@MENU_TYPE1"
			TAB_LABEL_OFFSET
			textFont UI_FONT_NORMAL
			textScale 0.25
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_FILLED
			rect RECT_TYPE
			textAlign ITEM_ALIGN_LEFT
			backColor OPTIONS_HEADING_JOIN_COLOR
			foreColor 1 1 1 1
			visible 1
			action
			{
				play "mouse_click" ;
				uiScript ServerSort 5 ;
				setItemColor grpTabs backColor TAB_BG_COLOR ;
				setItemColor Type backColor .1 .2 .37 1 ;
				setItemColor grpColumn backColor 0 0 0 0 ;
				setItemColor typeColumn backColor 0 0 .4 .15
			}
			mouseEnter { show message_sort ; setItemColor typeColumn borderColor 1 1 1 1 ; play "mouse_over"}
			mouseExit { hide message_sort ; setItemColor typeColumn borderColor TAB_BORDER_COLOR }
		}

		// MOD ===================================================================
		itemDef
		{
			name "Mod"
			group grpTabs
			text "@MENU_TYPE1"
			TAB_LABEL_OFFSET
			textFont UI_FONT_NORMAL
			textScale 0.25
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_FILLED
			rect RECT_VOICE
			textAlign ITEM_ALIGN_LEFT
			backColor OPTIONS_HEADING_JOIN_COLOR
			foreColor 1 1 1 1
			visible 1
			action
			{
				play "mouse_click";
				uiScript ServerSort 6;
				setItemColor grpTabs backColor TAB_BG_COLOR;
				setItemColor Voice backColor .1 .2 .37 1 ;
				setItemColor grpColumn backColor 0 0 0 0 ;
				setItemColor voiceColumn backColor 0 0 .4 .15
			}
			mouseEnter { show message_sort ; setItemColor voiceColumn borderColor 1 1 1 1 ; play "mouse_over"}
			mouseExit { hide message_sort ; setItemColor voiceColumn borderColor TAB_BORDER_COLOR }
		}

		// PING ==================================================================
		itemDef
		{
			name "Ping"
			group grpTabs
			text "@MENU_PING"
			TAB_LABEL_OFFSET
			type ITEM_TYPE_BUTTON
			textScale 0.25
			textFont	UI_FONT_NORMAL
			style WINDOW_STYLE_FILLED
			rect RECT_PING
			textAlign ITEM_ALIGN_LEFT
			backColor .1 .2 .37 1 // Start highlighted
			foreColor 1 1 1 1
			visible 1
			action
			{
				play "mouse_click" ;
				uiScript ServerSort 7;
				setItemColor grpTabs backColor TAB_BG_COLOR ;
				setItemColor Ping backColor .1 .2 .37 1 ;
				setItemColor grpColumn backColor 0 0 0 0 ;
				setItemColor pingColumn backColor 0 0 .4 .15
			}
			mouseEnter { show message_sort ; setItemColor pingColumn borderColor 1 1 1 1 ; play "mouse_over"}
			mouseExit { hide message_sort ; setItemColor pingColumn borderColor TAB_BORDER_COLOR }
		}

#undef TABLE_HEIGHT
#define TABLE_HEIGHT	360

// 	BUTTONS	===============================================================

itemDef 
{
    name "serverinfo"
    text "@MENU_SERVER_INFO"
	type ITEM_TYPE_BUTTON
	textFont UI_FONT_NORMAL
    textScale TEXTSIZE_SMALL
	style WINDOW_STYLE_FILLED
	border 1
	borderColor 0.1 0.1 0.1 0.25
    rect 70 -26 92 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
	textAlign ITEM_ALIGN_CENTER
    textAlignX 9 // center
    textAlignY 18
	backColor TAB_BG_COLOR
    foreColor TEXTBUTTON_COLOR
    visible 0
    action 
	{ 
		play "mouse_click";
		open "serverinfo_popmenu";
	}
	mouseEnter
	{ 
		setItemColor serverinfo backColor 0.1 0.2 0.37 1; 
		show "message_serverinfo"; 
		play "mouse_over";
	}
    mouseExit 
	{ 
		setItemColor serverinfo backColor TAB_BG_COLOR
		hide "message_serverinfo"; 
	}
}
itemDef 
{
    name "findPlayer"
    text "@MENU_FIND_FRIEND"
	type ITEM_TYPE_BUTTON
	textFont UI_FONT_NORMAL
    textScale TEXTSIZE_SMALL
	style WINDOW_STYLE_FILLED
	border 1
	borderColor 0.1 0.1 0.1 0.25
    rect 160 -26 92 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
	textAlign ITEM_ALIGN_CENTER
    textAlignX 0 // center
    textAlignY 18
	backColor TAB_BG_COLOR
    foreColor TEXTBUTTON_COLOR
    visible 0
    action 
	{ 
		play "mouse_click";
		open "findplayer_popmenu";
	}
	mouseEnter { show "message_findplayer"; setItemColor findplayer backColor 0.1 0.2 0.37 1; play "mouse_over"; }
    mouseExit { hide "message_findplayer"; setItemColor findplayer backColor TAB_BG_COLOR }
}
itemDef 
{
	name "addFavorite"
	text "@MENU_ADD_TO_FAVORITES"
	type ITEM_TYPE_BUTTON
	textScale TEXTSIZE_SMALL
	style WINDOW_STYLE_FILLED
	textStyle ITEM_TEXTSTYLE_SHADOWED
	ownerdrawFlag UI_SHOW_NOTFAVORITESERVERS
	rect -176 -26 92 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
	textFont UI_FONT_NORMAL
	textAlign ITEM_ALIGN_CENTER
	textAlignY 18
	foreColor TEXTBUTTON_COLOR
	visible when( dvarInt( "ui_netSource" ) != 2 )
	action 
	{
		play "mouse_click" ;
		uiScript "addFavorite";
		open "fav_message_popmenu";
	}
	mouseEnter { show "message_addFavorite"; play "mouse_over"; }
	mouseExit  { hide "message_addFavorite"; }
}
itemDef 
{
	name "delFavorite"
	text "@MENU_DEL_FAVORITE"
	type ITEM_TYPE_BUTTON
	textScale TEXTSIZE_SMALL
	style WINDOW_STYLE_FILLED
	textStyle ITEM_TEXTSTYLE_SHADOWED
	textFont UI_FONT_NORMAL
	ownerdrawFlag UI_SHOW_FAVORITESERVERS
	rect -176 -26 92 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
	textAlign ITEM_ALIGN_CENTER
	textAlignY 18
	foreColor TEXTBUTTON_COLOR
	visible when( dvarInt( "ui_netSource" ) == 2 )
	action 
	{
		play "mouse_click";
		open "del_fav_popmenu";
	}
	mouseEnter { show "message_delFavorite"; play "mouse_over"; }
	mouseExit  { hide "message_delFavorite"; }
}
itemDef 
{
	name "passwordEnter"
	text "@MENU_PASSWORD"
	type ITEM_TYPE_BUTTON
	textScale TEXTSIZE_SMALL
	style WINDOW_STYLE_FILLED
	textStyle ITEM_TEXTSTYLE_SHADOWED
	textFont UI_FONT_NORMAL
	rect -46 -26 80 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
	textAlign ITEM_ALIGN_CENTER
	textAlignY 18
	foreColor TEXTBUTTON_COLOR
	visible 1
	action 
	{
		play "mouse_click";
		open "password_popmenu";
	}
	mouseEnter { show "message_password"; play "mouse_over"; }
	mouseExit  { hide "message_password"; }
}
itemDef 
{
	name "serverinfo"
	text "@MENU_SERVER_INFO"
	type ITEM_TYPE_BUTTON
	textScale TEXTSIZE_SMALL
	style WINDOW_STYLE_FILLED
	textStyle ITEM_TEXTSTYLE_SHADOWED
	textFont UI_FONT_NORMAL
	rect 50 -26 92 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM // 390 420 100 14
	textAlign ITEM_ALIGN_CENTER
	textAlignY 18
	foreColor TEXTBUTTON_COLOR
	visible 1
	action
	{
		play "mouse_click";
		open "serverinfo_popmenu";
	}
	mouseEnter { show "message_password"; play "mouse_over"; }
	mouseExit  { hide "message_password"; }
}
itemDef 
{
	name "accept"
	text "@MENU_JOIN_SERVER"
	type 1
	textFont UI_FONT_NORMAL
	style WINDOW_STYLE_FILLED
	textStyle ITEM_TEXTSTYLE_SHADOWED
	rect 160 -26 92 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM // 510 420 90 14
	textAlign ITEM_ALIGN_CENTER
	textScale TEXTSIZE_SMALL
	textAlignY 18
	foreColor TEXTBUTTON_COLOR
	visible 1
	action 
	{ 
		play "mouse_click"; 
		uiScript "JoinServer"; 
	}
	mouseEnter { play "mouse_over"; }
}
itemDef 
{
	name			"back"
	text			"@MENU_BACK"
	type			1
	style			WINDOW_STYLE_FILLED
	foreColor		TEXTBUTTON_COLOR
	textStyle		ITEM_TEXTSTYLE_SHADOWED
	rect			-250 -26 40 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
	textFont		UI_FONT_NORMAL
	textAlign		ITEM_ALIGN_LEFT
	textScale		TEXTSIZE_SMALL
	textAlignY		18
	visible			1
	mouseEnter		{ play "mouse_over"; }
	action 
	{
		play "mouse_click";
		close "self";
	}	
}    
