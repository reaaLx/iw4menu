#define CAC_THING_1 \
if(!(tablelookup("mp/attachmentTable.csv",4,GPD_WS,0,"attachment",0),12)!=""||tablelookup("mp/attachmentTable.csv",4,GPD_WS,1,"attachment",0),12)!="")&&(GPD_SHORT,"perks",0)=="specialty_null_gl"||GPD_SHORT,"perks",0)=="specialty_null_grip"||GPD_SHORT,"perks",0)=="specialty_null_shotgun")||GPD_SHORT,"perks",0)=="specialty_null_heartbeat") \
{ \
	setPlayerData("customClasses",LOCALVARINT,"perks",0,"specialty_null"); \
}

#define CAC_THING_2 \
setLocalVarString "loadoutPrimary" 					(GPD_WS,0,"weapon")); \
setLocalVarString "loadoutPrimaryAttachment" 		(GPD_WS,0,"attachment",0)); \
setLocalVarString "loadoutPrimaryAttachment2" 		(GPD_WS,0,"attachment",1));

#define CAC_THING_2_1 \
if ( localVarString( "loadoutPrimaryAttachment2" ) == "" ) \
{ \
	setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
}

#define CAC_THING_3 \
setLocalVarString "loadoutPrimaryCamo" 				(GPD_WS,0,"camo")); \
setLocalVarString "loadoutSecondaryCamo" 			(GPD_WS,1,"camo")); \
setLocalVarString "loadoutSecondary" 				(GPD_WS,1,"weapon")); \
setLocalVarString "loadoutSecondaryAttachment" 		(GPD_WS,1,"attachment",0)); \
setLocalVarString "loadoutSecondaryAttachment2" 	(GPD_WS,1,"attachment",1));

#define CAC_THING_3_1 \
if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
{ \
	setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
}

#define CAC_THING_4 \
setLocalVarString "loadoutSecondaryCamo" 			(GPD_WS,1,"camo")); \
setLocalVarString "loadoutEquipment" 				(GPD_SHORT,"perks",0)); \
setLocalVarString "loadoutPerk1" 					(GPD_SHORT,"perks",1)); \
setLocalVarString "loadoutPerk2" 					(GPD_SHORT,"perks",2)); \
setLocalVarString "loadoutPerk3" 					(GPD_SHORT,"perks",3)); \
setLocalVarString "loadoutStreak1" 					(GPD_SHORTER("killstreaks",0)); \
setLocalVarString "loadoutStreak2" 					(GPD_SHORTER("killstreaks",1)); \
setLocalVarString "loadoutStreak3" 					(GPD_SHORTER("killstreaks",2)); \
setLocalVarString "loadoutDeathStreak" 				(GPD_SHORT,"perks",4)); \
setLocalVarString "loadoutOffhandSecondary" 		(GPD_SHORT,"specialGrenade")); \
setLocalVarString "loadoutClassName" 				(GPD_SHORT,"name"));

#define LOCALVARINT \
localvarint( "classIndex" )

#define GPD_WS \
getplayerdata("customClasses",LOCALVARINT,"weaponSetups"

#define GPD_SHORT \
getplayerdata("customClasses",LOCALVARINT

#define GPD_SHORTER \
getplayerdata

#define CAC_THING_FOCUS \
CAC_THING_1 	\
CAC_THING_2 	\
CAC_THING_2_1 	\
CAC_THING_3 	\
CAC_THING_3_1 	\
CAC_THING_4

#define CAC_STATNUM( statNum ) \
setPlayerData( "customClasses" , statNum , "inUse" , "true" ); \
setLocalVarInt "classIndex" ( statNum ); \
open "menu_cac_assault"; \

#define CAC_STATNUM_HI( statNum ) \
CAC_THING_FOCUS \
setLocalVarInt "classIndex" ( statNum ); \

#define CAC_STATNUM_NAME( statNum ) \
getplayerdata( "customClasses" , statNum , "name" ) \

#define WHEN \
when ( getplayerdata( "prestige" ) \