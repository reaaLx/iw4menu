#include "ui/menudefinition.h"

// Size define for the hud compass
// These are used for both the dynamic & non-dynamic compass drawing
// If these are changed, the cgame should be recompiled
#define COMPASS_SIZE		109
#define MINIMAP_X			11.5
#define MINIMAP_Y			5 
#define MINIMAP_W			89.5
#define	MINIMAP_H			89.5

#define COMPASS_SIZE_MP		0
#define MINIMAP_X_MP		0
#define MINIMAP_Y_MP		12
#define MINIMAP_W_MP		100
#define	MINIMAP_H_MP		100

#define FULLSCREEN			0 0 640 480
#define FULLSCREEN_WIDE		-107 0 854 480

#define ORIGIN_TITLE		48 40
#define ORIGIN_TITLE_SS		104 120

#define FONTSCALE_SS		0.3333
#define FONTSCALE_SMALL		0.375
#define FONTSCALE_NORMAL	0.4583
#define FONTSCALE_BOLD		0.4583
#define FONTSCALE_BIG		0.55
#define FONTSCALE_EXTRABIG	1.0


// new settings
#define TEXTSIZE_SMALL		FONTSCALE_SMALL
#define TEXTSIZE_SMALL_SS	( FONTSCALE_SMALL * 2 ) // 0.75
#define TEXTSIZE_DEFAULT	FONTSCALE_NORMAL
#define TEXTSIZE_DEFAULT_SS	( FONTSCALE_NORMAL * 2 ) // 0.9166
#define TEXTSIZE_TITLE		FONTSCALE_BIG
#define TEXTSIZE_TITLE_SS	1
// end new settings

#define TEXTSIZE_BOLD		TEXTSIZE_DEFAULT
#define TEXTSIZE_BIG		TEXTSIZE_TITLE

#define COLOR_TITLE			1 1 1 1
#define COLOR_FOCUSED		1 1 1 1
#define COLOR_UNFOCUSED		0.4823 0.4823 0.4823 1
#define COLOR_DISABLED		0.35 0.35 0.35 1
#define COLOR_SAFEAREA		0 0 1 1

#define	COLOR_USMC			0.6 0.64 0.69
#define COLOR_ARAB			0.65 0.57 0.41
#define COLOR_USSR			0.52 0.28 0.28
#define COLOR_SAS			0 0 0

#define DEFAULT_MP_CFG		"default_mp.cfg"
#define SPLITSCREEN_MP_CFG	"default_splitscreen.cfg"
#define SYSTEMLINK_MP_CFG	"default_systemlink.cfg"
#define XBOXLIVE_MP_CFG		"default_xboxlive.cfg"

#define MAX_RANK			int(tableLookup( "mp/rankTable.csv", 0, "maxrank", 1 ) )
#define MAX_PRESTIGE		int(tableLookup( "mp/rankIconTable.csv", 0, "maxprestige", 1 ) )

#define PRESTIGE_AVAIL 		( stat( 2326 ) < MAX_PRESTIGE && stat( 2301 ) == int( tableLookup( "mp/rankTable.csv", 0 , MAX_RANK, 7 ) ) )
#define PRESTIGE_NEXT 		( stat( 2326 ) < MAX_PRESTIGE && stat( 252 ) == MAX_RANK )
#define PRESTIGE_FINISH 	( stat( 2326 ) == MAX_PRESTIGE )

#define CAN_RANK_UP			( stat( 252 ) < MAX_RANK || stat( 2326 ) < MAX_PRESTIGE )

