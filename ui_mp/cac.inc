#define CAC_THING_1 \
if(!(tablelookup("mp/attachmentTable.csv",4,GPD_WS,0,"attachment",0),12)!=""|| \
tablelookup("mp/attachmentTable.csv",4,GPD_WS,1,"attachment",0),12)!="")&& \
(GPD_SHORT,"perks",0)=="specialty_null_gl"|| \
GPD_SHORT,"perks",0)=="specialty_null_grip"|| \
GPD_SHORT,"perks",0)=="specialty_null_shotgun")|| \
GPD_SHORT,"perks",0)=="specialty_null_heartbeat") \
{ \
	setPlayerData("customClasses",LOCALVARINT1,"perks",0,"specialty_null"); \
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

#define LOCALVARINT1 \
localVarInt( "classIndex" )

#define GPD_WS \
getPlayerData("customClasses",LOCALVARINT1,"weaponSetups"

#define GPD_SHORT \
getPlayerData("customClasses",LOCALVARINT1

#define GPD_SHORTER \
getPlayerData

#define CAC_THING_FOCUS \
CAC_THING_1 	\
CAC_THING_2 	\
CAC_THING_2_1 	\
CAC_THING_3 	\
CAC_THING_3_1 	\
CAC_THING_4

#define CAC_STATNUM( statNum ) \
setPlayerData("customClasses",statNum,"inUse","true"); \
setlocalVarInt "classIndex" (statNum); \
open "menu_cac_assault"; \

#define CAC_STATNUM_HI(statNum) \
CAC_THING_FOCUS \
setlocalVarInt "classIndex" (statNum); \

#define CAC_STATNUM_NAME( statNum ) \
getPlayerData("customClasses",statNum,"name") \

#define WHEN \
when ( getPlayerData( "prestige" ) \

#define LOCAL_WPN_ACTION1( statNum ) \

#define DEF_1 \
		getPlayerData("customClasses",localVarInt("classIndex"),"weaponSetups",0,"weapon")

#define LOCAL_WEAPON_NAME( statNum ) \
		"@"+tablelookup("mp/attachmentTable.csv",statNum,tablelookup("mp/statsTable.csv",statNum,DEF_1,11),3)

#define LOCAL_WEAPON( itemIndex, statNum ) \
		CHOICE_BUTTON_FOCUS( itemIndex, LOCAL_WEAPON_NAME ( statNum ), LOCAL_WPN_ACTION1( statNum ), onFocusArg, leaveFocusArg )
