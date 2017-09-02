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

		#define PREPROC_CAC_CLOSEALL \
				close "popup_cac_weapon_primary"; \
				close "popup_primary_attachments"; \
				close "popup_secondary_attachments"  \
				close "popup_cac_weapon_secondary"; \
				close "popup_cac_handgun_secondary"; \
				close "popup_cac_machinePistols_secondary"; \
				close "popup_cac_assault_primary"; \
				close "popup_cac_SMG_primary"; \
				close "popup_cac_LMG_primary"; \
				close "popup_cac_sniper_primary"; \
				close "popup_cac_shotgun_primary"; \
				close "popup_cac_assault_secondary"; \
				close "popup_cac_SMG_secondary"; \
				close "popup_cac_sniper_secondary"; \
				close "popup_cac_shotgun_secondary"; \
				close "popup_cac_template"; \
				close "popup_cac_primary_camo"; \
				close "popup_cac_secondary_camo"; \
				close "popup_cac_bling"; \
				close "popup_cac_perk2"; \
				close "popup_cac_rocket_secondary"; \
				close "popup_primary_attachments_bling"; \
				close "popup_secondary_attachments_bling"; \
				close "popup_cac_other_primary"; \

		// CREATE A CLASS POPUP -- 15 CLASSES /* will need to revise this. (cac_popup.menu) */
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
				getPlayerData("customClasses",localVarInt("classIndex"),"weaponSetups",0,"weapon") \

		#define LOCAL_WEAPON_NAME( statNum ) \
				"@"+tablelookup("mp/attachmentTable.csv",statNum,tablelookup("mp/statsTable.csv",statNum,DEF_1,11),3) \

		#define LOCAL_WEAPON( itemIndex, statNum ) \
				CHOICE_BUTTON_FOCUS( itemIndex, LOCAL_WEAPON_NAME ( statNum ), LOCAL_WPN_ACTION1( statNum ), onFocusArg, leaveFocusArg ) \

// CREATE A CLASS WEAPONS PRIMARY - SECONDARY - EQUIPMENT - EXTRA - PERK 1/2/3 - DEATHSTREAK

		// riot shield

		#define LOCAL_RIOT_ACTION( weaponStat ) \
				if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) != weaponStat ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "camo" , "none" ); \
				} \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "weapon" , weaponStat ); \
				setPlayerData( "weaponNew" , weaponStat , "false" ); \
				LOCAL_CACSETVARSTRINGS \
				LOCAL_CAC_WEAPON_ATTACHMENT_TYPE( REF_IS_PRIMARY_ATTACHMENT, weaponStat ) \

		#define LOCAL_RIOT_FOCUS( weaponStat ) \
				setLocalVarString "ui_info_name" ( "@" + tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 3 ) ); \
				setLocalVarString "ui_info_desc" ( "@" + tablelookup( "mp/statstable.csv" , 4 , weaponStat , 7 ) ); \
				setLocalVarString "ui_info_icon" ( tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 6 ) )

		#define LOCAL_RIOT_ITEM( itemIndex, textArg, weaponStat ) \
				CHOICE_BUTTON_FOCUS( itemIndex, textArg, LOCAL_RIOT_ACTION( weaponStat ), LOCAL_RIOT_FOCUS( weaponStat ), ; )

// extra
		#define LOCAL_EXTRA_ACTION( weaponStat ) \
				play "mouse_click"; \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "specialGrenade" , weaponStat ); \
				LOCAL_CACSETVARSTRINGS \
				close "popup_cac_extra"; \

		#define LOCAL_EXTRA_SHOW( weaponStat ) \
				setLocalVarString "ui_info_name" ("@"+tablelookup("mp/statsTable.csv",4,weaponStat,3)); \
				setLocalVarString "ui_info_desc" ("@"+tablelookup("mp/statstable.csv",4,weaponStat,7)); \
				setLocalVarString "ui_info_icon" (tablelookup("mp/statsTable.csv",4,weaponStat,6)); \

		#define LOCAL_EXTRA_ITEM( itemIndex, weaponStat ) \
				CHOICE_BUTTON_FOCUS( itemIndex, locstring("@MPUI_N_XN","@"+tablelookup("mp/statsTable.csv",4,weaponStat,3),int(tablelookup("mp/statsTable.csv",4,weaponStat,5))), LOCAL_EXTRA_ACTION( weaponStat ), LOCAL_EXTRA_SHOW( weaponStat ), ; ) \
				CHOICE_NEWICON_VIS( itemIndex, when ( weaponclassnew( weaponStat ) ) )
// equipment
		#define LOCAL_EQUIPMENT_ACTION( weaponStat ) \
				play "mouse_click"; \
				setPlayerData( "perkNew" , weaponStat , "false" ); \
				if ( weaponStat != "specialty_bling" ) \
				{ \
					close self; \
				} \
				if ( 0 == 1 && weaponStat != "specialty_bling" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
				} \
				if ( 0 == 1 && weaponStat == "specialty_onemanarmy" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "onemanarmy" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
					LOCAL_CACSETVARSTRINGS \
				} \
				if ( 0 == 1 && weaponStat != "specialty_onemanarmy" && getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) == "onemanarmy" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "glock" ); \
					LOCAL_CACSETVARSTRINGS \
				} \
				if ( 0 == 4 ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 4 , weaponStat ); \
				} \
				if ( 0 != 4 ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , weaponStat ); \
				} \
				LOCAL_CACSETVARSTRINGS \
				close "popup_cac_equipment"; \

		#define LOCAL_EQUIPMENT_FOCUS( weaponStat ) \
				setLocalVarString "ui_selected_ref" ( weaponStat ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , weaponStat , 8 ) ); \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ); \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				LOCAL_CH_STATE \

		#define LOCAL_EQUIPMENT_NOFOCUS( weaponStat ) \
				setPlayerData( "perkNew" , weaponStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , weaponStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \

		#define LOCAL_EQUIPMENT_ITEM( itemIndex, weaponStat ) \
				CHOICE_BUTTON_FOCUS_VIS_EX( itemIndex, "@"+tablelookup("mp/perkTable.csv",1,weaponStat,2), LOCAL_EQUIPMENT_ACTION( weaponStat ), LOCAL_EQUIPMENT_FOCUS( weaponStat ), LOCAL_EQUIPMENT_NOFOCUS( weaponStat ), when ( isitemunlocked( weaponStat ) ), disabled when ( !isitemunlocked( weaponStat ) ) ) \
				CHOICE_NEWICON_VIS( itemIndex, when((getplayerdata("perkNew",weaponStat)||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,weaponStat,8))))) \
				CHOICE_LOCKEDICON_VIS( itemIndex,  when ( !isitemunlocked( weaponStat ) ) ) \

	// perks 1
		#define LOCAL_PERK1_ACTION( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \
				LOCAL_IS_PERK_STAT( REF_PERK1, perkStat ) \
				LOCAL_CACSETVARSTRINGS \

		#define LOCAL_PERK1_FOCUS( perkStat ) \
				setLocalVarString "ui_selected_ref" ( perkStat ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 4 ) ); \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				LOCAL_CH_STATE \	

		#define LOCAL_PERK1_NOFOCUS( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \

		#define LOCAL_PERK1_ITEM( itemIndex, perkStat ) \
				CHOICE_BUTTON_FOCUS_EX( itemIndex, "@"+tablelookup("mp/perkTable.csv",1,perkStat,int(2+(isitemunlocked(tablelookup("mp/perkTable.csv",1,perkStat,8))*(9-2)))), LOCAL_PERK1_ACTION( perkStat ), LOCAL_PERK1_FOCUS( perkStat ), LOCAL_PERK1_NOFOCUS( perkStat ), disabled when ( !isitemunlocked( perkStat ) ) ) \
				CHOICE_NEWICON_VIS( itemIndex, when ((getplayerdata("perkNew",perkStat)||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,perkStat,8))))) \
				CHOICE_LOCKEDICON_VIS( itemIndex, when ( !isitemunlocked( weaponStat ) ) ) \	

// perks 2
		#define LOCAL_PERK2_ACTION( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \
				LOCAL_IS_PERK_STAT( REF_PERK2, perkStat ) \
				LOCAL_CACSETVARSTRINGS \

		#define LOCAL_PERK2_FOCUS( perkStat ) \
				setLocalVarString "ui_selected_ref" ( perkStat ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 4 ) ); \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				LOCAL_CH_STATE \

		#define LOCAL_PERK2_NOFOCUS( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \

		#define LOCAL_PERK2_ITEM( itemIndex, perkStat ) \
				CHOICE_BUTTON_FOCUS_EX( itemIndex, "@"+tablelookup("mp/perkTable.csv",1,perkStat,int(2+(isitemunlocked(tablelookup("mp/perkTable.csv",1,perkStat,8))*(9-2)))), LOCAL_PERK2_ACTION( perkStat ), LOCAL_PERK2_FOCUS( perkStat ), LOCAL_PERK2_NOFOCUS( perkStat ), disabled when ( !isitemunlocked( perkStat ) ) ) \
				CHOICE_NEWICON_VIS( itemIndex, when ((getplayerdata("perkNew",perkStat)||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,perkStat,8))))) \
				CHOICE_LOCKEDICON_VIS( itemIndex, when ( !isitemunlocked( weaponStat ) ) ) \	

		// perks 3
		#define LOCAL_PERK3_ACTION( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \
				LOCAL_IS_PERK_STAT( REF_PERK3, perkStat ) \
				LOCAL_CACSETVARSTRINGS \

		#define LOCAL_PERK3_FOCUS( perkStat ) \
				setLocalVarString "ui_selected_ref" ( perkStat ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 4 ) ); \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				LOCAL_CH_STATE \

		#define LOCAL_PERK3_NOFOCUS( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \

		#define LOCAL_PERK3_ITEM( itemIndex, perkStat ) \
				CHOICE_BUTTON_FOCUS_EX( itemIndex, "@"+tablelookup("mp/perkTable.csv",1,perkStat,int(2+(isitemunlocked(tablelookup("mp/perkTable.csv",1,perkStat,8))*(9-2)))), LOCAL_PERK3_ACTION( perkStat ), LOCAL_PERK3_FOCUS( perkStat ), LOCAL_PERK3_NOFOCUS( perkStat ), disabled when ( !isitemunlocked( perkStat ) ) ) \
				CHOICE_NEWICON_VIS( itemIndex, when ((getplayerdata("perkNew",perkStat)||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,perkStat,8))))) \
				CHOICE_LOCKEDICON_VIS( itemIndex, when ( !isitemunlocked( weaponStat ) ) ) \	

	// PRIMARY WEAPONS
		#define LOCAL_WEAPON_ACTION( weaponStat ) \
				UI_TABDEPTH2( ;, "@" + tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 3 ) ) \
				if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) != weaponStat ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "camo" , "none" ); \
				} \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "weapon" , weaponStat ); \
				setPlayerData( "weaponNew" , weaponStat , "false" ); \
				LOCAL_CACSETVARSTRINGS \
				LOCAL_CAC_WEAPON_ATTACHMENT_TYPE( REF_IS_PRIMARY_ATTACHMENT, weaponStat ) \

		#define LOCAL_WEAPON_ITEM( itemIndex, weaponStat ) \
				CHOICE_BUTTON_FOCUS_VIS_EX( itemIndex, "@"+tablelookup("mp/statsTable.csv",4,weaponStat,3), LOCAL_WEAPON_ACTION( weaponStat ), setLocalVarString "ui_selected_ref" ( weaponStat );, setPlayerData( "weaponNew" , weaponStat , "false" );, when ( isitemunlocked( weaponStat ) ), disabled when ( !isitemunlocked( weaponStat ) ) ) \
				CHOICE_CAPTION_VIS( itemIndex, "@"+tablelookup("mp/statsTable.csv",4,weaponStat,3), when ( ( isitemunlocked( weaponStat ) == 0 ) ) ) \
				CHOICE_NEWICON_VIS( itemIndex, when((getplayerdata("weaponNew",weaponStat)||getplayerdataanybooltrue("camoNew",weaponStat)||getplayerdataanybooltrue("attachmentNew",weaponStat)))) \
				CHOICE_LOCKEDICON_VIS( itemIndex, when ( ( isitemunlocked( weaponStat ) == 0 ) ) ) \

		#define LOCAL_WEAPON2_ACTION( weaponStat ) \
				UI_TABDEPTH2( ;, "@" + tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 3 ) ) \
				if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) != weaponStat ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "camo" , "none" ); \
				} \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , weaponStat ); \
				setPlayerData( "weaponNew" , weaponStat , "false" ); \
				LOCAL_CACSETVARSTRINGS \
				LOCAL_CAC_WEAPON_ATTACHMENT_TYPE( REF_IS_SECONDARY_ATTACHMENT, weaponStat ) \

		#define LOCAL_WEAPON2_ITEM( itemIndex, weaponStat ) \
				CHOICE_BUTTON_FOCUS_VIS( itemIndex, "@"+tablelookup("mp/statsTable.csv",4,weaponStat,3), LOCAL_WEAPON2_ACTION( weaponStat ), setLocalVarString "ui_selected_ref" ( weaponStat );, setPlayerData( "weaponNew" , weaponStat , "false" );, when ( isitemunlocked( weaponStat ) ) ) \

// CAMOS
		#define LOCAL_CAMO_ACTION( camoStat ) \
				UI_TABDEPTH2( ;, "@" + tablelookup( "mp/camoTable.csv" , 1 , camoStat , 2 ) ) \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setPlayerData( "camoNew" , "localVarString" ( "tempName" ) , camoStat , "false" ); \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "camo" , camoStat ); \
				LOCAL_CACSETVARSTRINGS \
				PREPROC_CAC_CLOSEALL \

		#define LOCAL_CAMO_FOCUS( camoStat ) \
				setLocalVarString "ui_selected_ref" ( camoStat ); \
				setLocalVarString "ui_weapon_ref" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setLocalVarString "ui_unlock_ref" ( localvarstring( "ui_weapon_ref" ) + " " + camoStat ); \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_unlock_ref" ) , 3 ) ); \
				setLocalVarInt "ui_challenge_state" ( 1 ); \
				LOCAL_CH_REF( "ch_expert_" ) \

		#define LOCAL_CAMO_NOFOCUS( camoStat ) \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setPlayerData( "camoNew" , "localVarString" ( "tempName" ) , camoStat , "false" ); \

		#define LOCAL_WEAPON_CAMO( itemIndex, camoStat ) \
				CHOICE_BUTTON_FOCUS( itemIndex, "@"+tablelookup("mp/camoTable.csv",1,camoStat,2), LOCAL_CAMO_ACTION( camoStat ), LOCAL_CAMO_FOCUS( camoStat ), LOCAL_CAMO_NOFOCUS( camoStat ) ) \

// ATTACHMENTS
		#define LOCAL_ATTACHMENT_NAME( attachmentStat ) \
				"@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat),3) \

		#define LOCAL_ATTACHMENT_ACTION( attachmentStat ) \
				UI_TABDEPTH2( ;, "@" + tablelookup( "mp/attachmentTable.csv" , 4 , tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) , 11 ) , 3 ) ) \
				LOCAL_CACATTACHMENT_WEAPONTYPE( REF_IS_PRIMARY_ATTACHMENT ) \
				setLocalVarString "tempName"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon")); \
				setPlayerData("attachmentNew","localVarString"("tempName"),"localVarString"("ui_selected_ref"),"false");; \
				if(menuisopen("popup_primary_attachments_bling")||menuisopen("popup_secondary_attachments_bling")) \
				{ \
					setLocalVarString "tempName"(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)); \
					if((localvarstring("ui_attachment1")==tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)||localvarstring("ui_attachment2")==tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat))) \
					{ \
						setLocalVarInt "tempInt"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",1)==tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)); \
						setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment","localVarInt"("tempInt"),"none"); \
					} \
					else \
					{ \
						setLocalVarInt "tempInt"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",0)!="none"); \
						setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment","localVarInt"("tempInt"),"localVarString"("tempName")); \
					} \
					setLocalVarString "ui_attachment1"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",0)); \
					setLocalVarString "ui_attachment2"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",1)); \
					setLocalVarInt "ui_numAttachments"(0); \
					if(localvarstring("ui_attachment1")!="none") \
					{ \
						setLocalVarInt "ui_numAttachments"(localvarint("ui_numAttachments")+1); \
					} \
					if(localvarstring("ui_attachment2")!="none") \
					{ \
						setLocalVarInt "ui_numAttachments"(localvarint("ui_numAttachments")+1); \
					} \
					LOCAL_CACSETVARSTRINGS \
				} \
				else \
				{ \
					if(getplayerdata("customClasses",localvarint("classIndex"),"perks",1)=="specialty_bling") \
					{ \
						setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment",1,"none");; \
					} \
					if(getplayerdata("customClasses",localvarint("classIndex"),"perks",1)=="specialty_bling"&&getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",1)==tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)) \
					{ \
						setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment",1,"none");; \
					} \
					setLocalVarString "tempName"(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)); \
					setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment",0,"localVarString"("tempName")); \
					if(0==0) \
					{ \
						open "popup_cac_primary_camo"; \
					} \
					else \
					{ \
						PREPROC_CAC_CLOSEALL \
					} \
					LOCAL_CACSETVARSTRINGS \
				} \

		#define LOCAL_ATTACHMENT_FOCUS( attachmentStat ) \
				setLocalVarString "ui_selected_ref"(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)); \
				setLocalVarString "ui_weapon_ref"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon")); \
				setLocalVarString "ui_unlock_ref"(localvarstring("ui_weapon_ref")+""+tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)); \
				setLocalVarString "ui_challenge_ref"(tablelookup("mp/unlockTable.csv",0,localvarstring("ui_unlock_ref"),3)); \
				setLocalVarInt "ui_challenge_state"(1); \
				LOCAL_CH_REF( "ch_marksman_" ) \

		#define LOCAL_ATTACHMENT_NOFOCUS \
				setLocalVarString "tempName"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon")); \
				if(localvarstring("ui_selected_ref")!="") \
				{ \
					setPlayerData("attachmentNew","localVarString"("tempName"),"localVarString"("ui_selected_ref"),"false");; \
				} \

		#define LOCAL_ATTACHMENT_ITEM( itemIndex, attachmentStat ) \
				CHOICE_BUTTON_FOCUS_VIS_EX( itemIndex, LOCAL_ATTACHMENT_NAME( attachmentStat ), LOCAL_ATTACHMENT_ACTION( attachmentStat ), LOCAL_ATTACHMENT_FOCUS( attachmentStat ), LOCAL_ATTACHMENT_NOFOCUS, \
				when(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)!=""), \
				disabled when(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)!="" \
				&&(!isitemunlocked(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon")+"" \
				+(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat))) \
				||((((getplayerdata("customClasses",localvarint("classIndex"),"perks",1)=="specialty_bling")&&menuisopen("popup_primary_attachments_bling"))||((getplayerdata("customClasses",localvarint("classIndex"),"perks",1)=="specialty_bling" \
				&&isitemunlocked("specialty_secondarybling"))&&menuisopen("popup_secondary_attachments_bling"))) \
				&&tablelookup("mp/attachmentCombos.csv",0,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",0),tablegetrownum("mp/attachmentCombos.csv",0,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)))=="no"))) ) \

		#define LOCAL_ATTACHMENT_BLING_NAME( attachmentStat ) \
				"@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,localvarstring("loadoutPrimary"),attachmentStat),3)

		#define LOCAL_ATTACHMENT_BLING_ACTION( attachmentStat ) \
				UI_TABDEPTH2( ;, "@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,localvarstring("loadoutPrimary"),attachmentStat),3)) \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setPlayerData( "attachmentNew" , "localVarString" ( "tempName" ) , "localVarString" ( "ui_selected_ref" ) , "false" ); \
				if ( menuisopen( "popup_primary_attachments_bling" ) || menuisopen( "popup_secondary_attachments_bling" ) ) \
				{ \
					setLocalVarString "tempName" ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) ); \
					if ( ( localvarstring( "ui_attachment1" ) == tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) || localvarstring( "ui_attachment2" ) == tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) ) ) \
					{ \
						setLocalVarInt "tempInt" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) == tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) ); \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , "localVarInt" ( "tempInt" ) , "none" ); \
					} \
					else \
					{ \
						setLocalVarInt "tempInt" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) != "none" ); \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , "localVarInt" ( "tempInt" ) , "localVarString" ( "tempName" ) ); \
					} \
					setLocalVarString "ui_attachment1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
					setLocalVarString "ui_attachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
					setLocalVarInt "ui_numAttachments" ( 0 ); \
					if ( localvarstring( "ui_attachment1" ) != "none" ) \
					{ \
						setLocalVarInt "ui_numAttachments" ( localvarint( "ui_numAttachments" ) + 1 ); \
					} \
					if ( localvarstring( "ui_attachment2" ) != "none" ) \
					{ \
						setLocalVarInt "ui_numAttachments" ( localvarint( "ui_numAttachments" ) + 1 ); \
					} \
					LOCAL_CACSETVARSTRINGS \
					if ( ( localvarstring( "ui_attachment1" ) == tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) || localvarstring( "ui_attachment2" ) == tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) ) ) \
					{ \
						setItemColor self backcolor 0 0 0 "0.35"; \
					} \
					else \
					{ \
						setItemColor self backcolor 0 0 0 1; \
					} \
					if ( localvarint( "ui_numAttachments" ) == 2 ) \
					{ \
						if ( 0 == 0 ) \
						{ \
							UI_TABDEPTH2( ;, "@" + tablelookup( "mp/perkTable.csv" , 1 , "specialty_bling" , 2 ) ) \
							open "popup_cac_primary_camo"; \
						} \
						else \
						{ \
							PREPROC_CAC_CLOSEALL \
						} \
						LOCAL_CACSETVARSTRINGS \
					} \
				} \
				else \
				{ \
					if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) == "specialty_bling" ) \
					{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
					} \
					if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) == "specialty_bling" && getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) == tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) ) \
					{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
					} \
					setLocalVarString "tempName" ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 , "localVarString" ( "tempName" ) ); \
					if ( 0 == 0 ) \
					{ \
						open "popup_cac_primary_camo"; \
					} \
					else \
					{ \
						PREPROC_CAC_CLOSEALL \
					} \
					LOCAL_CACSETVARSTRINGS \
				} \

		#define LOCAL_ATTACHMENT_BLING_FOCUS( attachmentStat ) \
				setLocalVarString "ui_attachment_hint" ( "" ); \
				setLocalVarString "ui_selected_ref" ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) ); \
				setLocalVarString "ui_weapon_ref" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setLocalVarString "ui_unlock_ref" ( localvarstring( "ui_weapon_ref" ) + " " + tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) ); \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_unlock_ref" ) , 3 ) ); \
				setLocalVarInt "ui_challenge_state" ( 1 ); \
				LOCAL_CH_REF( "ch_marksman_" ) \
				if ( ( localvarstring( "ui_attachment1" ) == tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) || localvarstring( "ui_attachment2" ) == tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) ) ) \
				{ \
					setItemColor self backcolor 0 0 0 "0.35"; \
				} \
				else \
				{ \
					if ( !( tablelookup( "mp/attachmentCombos.csv" , 0 , tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) , tablegetrownum( "mp/attachmentCombos.csv" , 0 , localvarstring( "ui_attachment1" ) ) ) != "no" ) ) \
					{ \
						setLocalVarString "ui_attachment_hint" ( localvarstring( "ui_attachment1" ) ); \
					} \
					if ( !( tablelookup( "mp/attachmentCombos.csv" , 0 , tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) , tablegetrownum( "mp/attachmentCombos.csv" , 0 , localvarstring( "ui_attachment2" ) ) ) != "no" ) ) \
					{ \
						setLocalVarString "ui_attachment_hint" ( localvarstring( "ui_attachment2" ) ); \
					} \
				} \

		#define LOCAL_ATTACHMENT_BLING_NOFOCUS \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				if ( localvarstring( "ui_selected_ref" ) != "" ) \
				{ \
					setPlayerData( "attachmentNew" , "localVarString" ( "tempName" ) , "localVarString" ( "ui_selected_ref" ) , "false" ); \
				} \

		#define LOCAL_ATTACHMENT_BLING_ITEM( itemIndex, attachmentStat ) \
				CHOICE_BUTTON_FOCUS_VIS_EX( itemIndex, LOCAL_ATTACHMENT_BLING_NAME( attachmentStat ), LOCAL_ATTACHMENT_BLING_ACTION( attachmentStat ), LOCAL_ATTACHMENT_BLING_FOCUS( attachmentStat ), LOCAL_ATTACHMENT_BLING_NOFOCUS, \
				when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) != "" ), \
				disabled when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) != "" \
				&& ( !isitemunlocked( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) + " " + ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) ) ) \
				|| ( !( localvarstring( "ui_attachment1" ) == tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) || localvarstring( "ui_attachment2" ) == tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) ) \
				&& ( ( !( tablelookup( "mp/attachmentCombos.csv" , 0 , tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) , tablegetrownum( "mp/attachmentCombos.csv" , 0 , localvarstring( "ui_attachment1" ) ) ) != "no" ) \
				|| !( tablelookup( "mp/attachmentCombos.csv" , 0 , tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) , tablegetrownum( "mp/attachmentCombos.csv" , 0 , localvarstring( "ui_attachment2" ) ) ) != "no" ) \
				|| localvarint( "ui_numAttachments" ) == 2 ) ) ) ) ) ) \
				PREPROC_SHADER_DRAW( CHOICE_RECT( itemIndex ), ORIGIN_NONE, "popup_button_selected_bar_bling", 0.8 0.6 0.1 1 \
				visible when ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) \
				== tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) \
				== tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , attachmentStat ) ) ) \

// SECONDARY ATTACHMENTS
// ATTACHMENTS
		#define LOCAL_ATTACHMENT2_NAME( attachmentStat ) \
				"@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"weapon"),attachmentStat),3) \

		#define LOCAL_ATTACHMENT2_ACTION( attachmentStat ) \
				LOCAL_CACATTACHMENT_WEAPONTYPE( REF_IS_SECONDARY_ATTACHMENT ) \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
				setPlayerData( "attachmentNew" , "localVarString" ( "tempName" ) , "localVarString" ( "ui_selected_ref" ) , "false" ) ;; \
				if ( menuisopen( "popup_primary_attachments_bling" ) || menuisopen( "popup_secondary_attachments_bling" ) ) \
				{ \
					setLocalVarString "tempName" ( tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , attachmentStat ) ); \
					if ( ( localvarstring( "ui_attachment1" ) == tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , attachmentStat ) || localvarstring( "ui_attachment2" ) == tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , attachmentStat ) ) ) \
					{ \
						setLocalVarInt "tempInt" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) == tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , attachmentStat ) ); \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , "localVarInt" ( "tempInt" ) , "none" ); \
					} \
					else \
					{ \
						setLocalVarInt "tempInt" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) != "none" ); \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , "localVarInt" ( "tempInt" ) , "localVarString" ( "tempName" ) ); \
					} \
					setLocalVarString "ui_attachment1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
					setLocalVarString "ui_attachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
					setLocalVarInt "ui_numAttachments" ( 0 ); \
					if ( localvarstring( "ui_attachment1" ) != "none" ) \
					{ \
						setLocalVarInt "ui_numAttachments" ( localvarint( "ui_numAttachments" ) + 1 ); \
					} \
					if ( localvarstring( "ui_attachment2" ) != "none" ) \
					{ \
						setLocalVarInt "ui_numAttachments" ( localvarint( "ui_numAttachments" ) + 1 ); \
					} \
					LOCAL_CACSETVARSTRINGS \
				} \
				else \
				{ \
					if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) == "specialty_bling" ) \
					{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
					} \
					if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) == "specialty_bling" && getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) == tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , attachmentStat ) ) \
					{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
					} \
					setLocalVarString "tempName" ( tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , attachmentStat ) ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 , "localVarString" ( "tempName" ) ); \
					if ( 1 == 0 ) \
					{ \
						open "popup_cac_primary_camo"; \
					} \
					else \
					{ \
						PREPROC_CAC_CLOSEALL \
					} \
					LOCAL_CACSETVARSTRINGS \
				} \

		#define LOCAL_ATTACHMENT2_FOCUS( attachmentStat ) \
				setLocalVarString "ui_selected_ref" ( tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , attachmentStat ) ); \
				setLocalVarString "ui_weapon_ref" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
				setLocalVarString "ui_unlock_ref" ( localvarstring( "ui_weapon_ref" ) + " " + tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , attachmentStat ) ); \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_unlock_ref" ) , 3 ) ); \
				setLocalVarInt "ui_challenge_state" ( 1 ); \
				LOCAL_CH_REF( "ch_marksman_" ) \

		#define LOCAL_ATTACHMENT2_NOFOCUS \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
				if ( localvarstring( "ui_selected_ref" ) != "" ) \
				{ \
					setPlayerData( "attachmentNew" , "localVarString" ( "tempName" ) , "localVarString" ( "ui_selected_ref" ) , "false" ) ;; \
				} \

		#define LOCAL_ATTACHMENT2_ITEM( itemIndex, attachmentStat ) \
				CHOICE_BUTTON_FOCUS_VIS( itemIndex, LOCAL_ATTACHMENT2_NAME( attachmentStat ), LOCAL_ATTACHMENT2_ACTION( attachmentStat ), LOCAL_ATTACHMENT2_FOCUS( attachmentStat ), LOCAL_ATTACHMENT2_NOFOCUS, when (tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"weapon"),attachmentStat)!=""))\

		#define LOCAL_DEATHSTREAK_ACTION( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				LOCAL_IS_PERK_STAT( REF_DEATHSTREAK, perkStat ) \
				LOCAL_CACSETVARSTRINGS \

		#define LOCAL_DEATHSTREAK_FOCUS( perkStat ) \
				setLocalVarString "ui_selected_ref" ( perkStat ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ); \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				LOCAL_CH_STATE \

		#define LOCAL_DEATHSTREAK_NOFOCUS( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \

		#define LOCAL_DEATHSTREAK_ITEM( itemIndex, perkStat ) \
				CHOICE_BUTTON_FOCUS_EX( itemIndex,"@"+tablelookup("mp/perkTable.csv",1,perkStat,2), LOCAL_DEATHSTREAK_ACTION( perkStat ), LOCAL_DEATHSTREAK_FOCUS( perkStat ), LOCAL_DEATHSTREAK_NOFOCUS( perkStat ), disabled when ( !isitemunlocked( perkStat ) ) ) \
				CHOICE_NEWICON_VIS( itemIndex, when ( ( getplayerdata( "perkNew" , perkStat ) || getplayerdata( "perkNew" , tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ) ) )) \
				CHOICE_LOCKEDICON_VIS( itemIndex, when ( !isitemunlocked( perkStat ) ) ) \
