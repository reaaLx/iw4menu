#define LOCAL_MAP_ACTION( mapname ) \
		setdvar ui_mapname mapname; \
		close "settings_map"; \
		close "self"; \

#define LOCAL_MAP_FOCUS( name, desc, icon ) \
		setLocalVarString "ui_info_name" ( name  ); \
		setLocalVarString "ui_info_desc" ( desc ); \
		setLocalVarString "ui_info_icon" ( icon ); \

#define LOCAL_MAP_NAME( name ) \
				"@" + name \

#define LOCAL_MAP_BUTTON( itemIndex, mapname, name, desc, icon ) \
		CHOICE_BUTTON_FOCUS( itemIndex, LOCAL_MAP_NAME( name ), LOCAL_MAP_ACTION( mapname ), LOCAL_MAP_FOCUS( name, desc, icon ), ; )

#define LOCAL_XDLC_FOCUS \
		setLocalVarString "ui_info_name" ( PATCH_DLC_MAPS  ); \
		setLocalVarString "ui_info_desc" ( PATCH_DLC_MAPS_DESC ); \
		setLocalVarString "ui_info_icon" ( loadscreen_mp_bonusmaps ); \
		
#define LOCAL_XDLC_BUTTON( itemIndex ) \
		CHOICE_BUTTON_FOCUS( itemIndex, "@PATCH_DLC_MAPS", open "settings_bonus_map";, LOCAL_XDLC_FOCUS, ; )
