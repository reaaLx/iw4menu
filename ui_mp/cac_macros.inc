	#define UI_TABDEPTH( actionArg, textArg ) \
			setLocalVarInt "ui_tabDepth" ( 0 ); \
			if ( localvarint( "ui_tabDepth" ) == 0 ) \
			{ setLocalVarString "ui_tab1Name" ( textArg ); } \
			if ( localvarint( "ui_tabDepth" ) == 1 ) \
			{ setLocalVarString "ui_tab2Name" ( textArg ); } \
			if ( localvarint( "ui_tabDepth" ) == 2 ) \
			{ setLocalVarString "ui_tab3Name" ( textArg ); } \
			if ( localvarint( "ui_tabDepth" ) == 3 ) \
			{ setLocalVarString "ui_tab4Name" ( textArg ); } \
			if ( localvarint( "ui_tabDepth" ) == 4 ) \
			{ setLocalVarString "ui_tab5Name" ( textArg ); } \
			if ( localvarint( "ui_tabDepth" ) == 5 ) \
			{ setLocalVarString "ui_tab6Name" ( textArg ); } \
			actionArg \
	
	#define UI_TABDEPTH2( actionArg, textArg ) \
			if ( localvarint( "ui_tabDepth" ) == 0 ) \
			{ setLocalVarString "ui_tab1Name" ( textArg ); } \
			if ( localvarint( "ui_tabDepth" ) == 1 ) \
			{ setLocalVarString "ui_tab2Name" ( textArg ); } \
			if ( localvarint( "ui_tabDepth" ) == 2 ) \
			{ setLocalVarString "ui_tab3Name" ( textArg ); } \
			if ( localvarint( "ui_tabDepth" ) == 3 ) \
			{ setLocalVarString "ui_tab4Name" ( textArg ); } \
			if ( localvarint( "ui_tabDepth" ) == 4 ) \
			{ setLocalVarString "ui_tab5Name" ( textArg ); } \
			if ( localvarint( "ui_tabDepth" ) == 5 ) \
			{ setLocalVarString "ui_tab6Name" ( textArg ); } \
			actionArg \

#define LOCAL_CH_REF( chType ) \
		if ( ( localvarstring( "ui_challenge_ref" ) == chType + localvarstring( "ui_weapon_ref" ) + "_2" ) ) \
		{ \
			setLocalVarString "ui_challenge_ref" ( chType + localvarstring( "ui_weapon_ref" ) ); \
			setLocalVarInt "ui_challenge_state" ( 2 ); \
		} \
		if ( ( localvarstring( "ui_challenge_ref" ) == chType + localvarstring( "ui_weapon_ref" ) + "_3" ) ) \
		{ \
			setLocalVarString "ui_challenge_ref" ( chType + localvarstring( "ui_weapon_ref" ) ); \
			setLocalVarInt "ui_challenge_state" ( 3 ); \
		} \
		if ( ( localvarstring( "ui_challenge_ref" ) == chType + localvarstring( "ui_weapon_ref" ) + "_4" ) ) \
		{ \
			setLocalVarString "ui_challenge_ref" ( chType + localvarstring( "ui_weapon_ref" ) ); \
			setLocalVarInt "ui_challenge_state" ( 4 ); \
		} \
		if ( ( localvarstring( "ui_challenge_ref" ) == chType + localvarstring( "ui_weapon_ref" ) + "_5" ) ) \
		{ \
			setLocalVarString "ui_challenge_ref" ( chType + localvarstring( "ui_weapon_ref" ) ); \
			setLocalVarInt "ui_challenge_state" ( 5 ); \
		} \
		if ( ( localvarstring( "ui_challenge_ref" ) == chType + localvarstring( "ui_weapon_ref" ) + "_6" ) ) \
		{ \
			setLocalVarString "ui_challenge_ref" ( chType + localvarstring( "ui_weapon_ref" ) ); \
			setLocalVarInt "ui_challenge_state" ( 6 ); \
		} \
		if ( ( localvarstring( "ui_challenge_ref" ) == chType + localvarstring( "ui_weapon_ref" ) + "_7" ) ) \
		{ \
			setLocalVarString "ui_challenge_ref" ( chType + localvarstring( "ui_weapon_ref" ) ); \
			setLocalVarInt "ui_challenge_state" ( 7 ); \
		} \
		if ( ( localvarstring( "ui_challenge_ref" ) == chType + localvarstring( "ui_weapon_ref" ) + "_8" ) ) \
		{ \
			setLocalVarString "ui_challenge_ref" ( chType + localvarstring( "ui_weapon_ref" ) ); \
			setLocalVarInt "ui_challenge_state" ( 8 ); \
		} \

#define LOCAL_CH_STATE \
		if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_2" ) \
		{ \
			setLocalVarInt "ui_challenge_state" ( 2 ); \
		} \
		if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_3" ) \
		{ \
			setLocalVarInt "ui_challenge_state" ( 3 ); \
		} \
		if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_4" ) \
		{ \
			setLocalVarInt "ui_challenge_state" ( 4 ); \
		} \
		setLocalVarString "ui_challengeName" ( "@" + tablelookup( "mp/allChallengesTable.csv" , 0 , localvarstring( "ui_challenge_ref" ) , 1 ) ); \

#define REF_PERK1 			1
#define REF_PERK2 			2
#define REF_PERK3 			3
#define REF_DEATHSTREAK 	4

#define LOCAL_IS_PERK_STAT( refPerk, perkStat ) \
		if ( perkStat != "specialty_bling" ) \
		{ \
			close "self"; \
		} \
		if ( refPerk == 1 && perkStat != "specialty_bling" ) \
		{ \
			setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
			setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
		} \
		if ( refPerk == 1 && perkStat == "specialty_onemanarmy" ) \
		{ \
			setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "onemanarmy" ); \
			setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 , "none" ); \
			setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
			LOCAL_CACSETVARSTRINGS \
		} \
		if ( refPerk == 1 && perkStat != "specialty_onemanarmy" && getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) == "onemanarmy" ) \
		{ \
			setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "glock" ); \
			LOCAL_CACSETVARSTRINGS \
		} \
		if ( refPerk == 4 ) \
		{ \
			setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 4 , perkStat ); \
		} \
		if ( refPerk != 4 ) \
		{ \
			setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , refPerk , perkStat ); \
		} \

#define REF_IS_PRIMARY_ATTACHMENT 		0
#define REF_IS_SECONDARY_ATTACHMENT 	1

#define LOCAL_CAC_WEAPON_ATTACHMENT_TYPE( REF_TYPE, weaponStat ) \
		if ( REF_TYPE == 0 ) \
		{ \
			if ( ( tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 11 ) != "" ) ) \
			{ \
				if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) == "specialty_bling" ) \
				{ \
					open "popup_primary_attachments_bling"; \
				} \
				else \
				{ \
					open "popup_primary_attachments"; \
				} \
			} \
			else \
			{ \
				open "popup_cac_primary_camo"; \
			} \
		} \
		else \
		{ \
			if ( ( tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 11 ) != "" ) ) \
			{ \
				if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) == "specialty_bling" && isitemunlocked( "specialty_secondarybling" ) ) \
				{ \
					open "popup_secondary_attachments_bling"; \
				} \
				else \
				{ \
					open "popup_secondary_attachments"; \
				} \
			} \
			else \
			{ \
				PREPROC_CAC_CLOSEALL \
			} \
		} \	

#define LOCAL_CACATTACHMENT_WEAPONTYPE( REF_IS_WEAPONTYPE ) \
		if(localvarint("ui_tabDepth")==0) \
		{ setLocalVarString "ui_tab1Name"("@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",REF_IS_WEAPONTYPE,"weapon"),attachmentStat),3)); } \
		if(localvarint("ui_tabDepth")==1) \
		{ setLocalVarString "ui_tab2Name"("@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",REF_IS_WEAPONTYPE,"weapon"),attachmentStat),3)); } \
		if(localvarint("ui_tabDepth")==2) \
		{ setLocalVarString "ui_tab3Name"("@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",REF_IS_WEAPONTYPE,"weapon"),attachmentStat),3)); } \
		if(localvarint("ui_tabDepth")==3) \
		{ setLocalVarString "ui_tab4Name"("@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",REF_IS_WEAPONTYPE,"weapon"),attachmentStat),3)); } \
		if(localvarint("ui_tabDepth")==4) \
		{ setLocalVarString "ui_tab5Name"("@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",REF_IS_WEAPONTYPE,"weapon"),attachmentStat),3)); } \
		if(localvarint("ui_tabDepth")==5) \
		{ setLocalVarString "ui_tab6Name"("@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",REF_IS_WEAPONTYPE,"weapon"),attachmentStat),3)); } \

#define LOCAL_CACSETVARSTRINGS \
		if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) \
		!= "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) \
		&& ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) \
		== "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) \
		== "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) \
		== "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) \
		== "specialty_null_heartbeat" ) \
		{ \
			setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
		} \
		setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
		setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
		setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
		if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
		{ \
			setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
		} \
		setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
		setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
		setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
		setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
		setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
		if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
		{ \
			setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
		} \
		setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
		setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
		setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
		setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
		setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
		setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
		setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
		setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
		setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
		setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
		setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \

	
// because why not
#define CAC_LOCALVARSTRINGS( itemIndex ) \
		setLocalVarString "loadoutPrimary" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutPrimary" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutPrimaryAttachment" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutPrimaryAttachment" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutPrimaryAttachment2" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutPrimaryAttachment2" , itemIndex + 1 ) ); \
		if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
		{ \
			setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
		} \
		setLocalVarString "loadoutPrimaryCamo" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutPrimaryCamo" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutSecondary" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutSecondary" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutSecondaryAttachment" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutSecondaryAttachment" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutSecondaryAttachment2" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutSecondaryAttachment2" , itemIndex + 1 ) ); \
		if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
		{ \
			setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
		} \
		setLocalVarString "loadoutSecondaryCamo" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutSecondaryCamo" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutEquipment" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutEquipment" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutPerk1" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutPerk1" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutPerk2" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutPerk2" ,itemIndex + 1 ) ); \
		setLocalVarString "loadoutPerk3" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutPerk3" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutStreak1" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutStreak1" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutStreak2" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutStreak2" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutStreak3" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutStreak3" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutDeathStreak" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutDeathStreak" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutOffhandSecondary" ( tablelookup( "mp/classTable.csv" , 0 , "loadoutOffhand" , itemIndex + 1 ) ); \
		setLocalVarString "loadoutClassName" ( "@" + ( tablelookup( "mp/classTable.csv" , 0 , "loadoutName" , itemIndex + 1 ) ) ); \

		#define CAC_LOCALVARSTRINGS2 \
		setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
		setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
		setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
		if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
		{ \
			setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
		} \
		setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
		setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
		setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
		setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
		if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
		{ \
			setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
		} \
		setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
		setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
		setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
		setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
		setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
		setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
		setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
		setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
		setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
		setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
		setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
		
// scriptmenus/changeclass.menu

#define CHOICE_CAC_DEFAULT( itemIndex, textArg, actionArg, visArg ) \
		CHOICE_BUTTON_FOCUS_VIS( itemIndex, textArg, actionArg, CAC_LOCALVARSTRINGS( itemIndex ), leaveFocusArg, visArg )
	
#define CHOICE_CAC_CUSTOM( itemIndex, classNum, actionArg ) \
		CHOICE_BUTTON_FOCUS_VIS( itemIndex, getplayerdata( "customClasses" , classNum , "name" ), actionArg, setLocalVarInt "classIndex" ( classNum ); CAC_LOCALVARSTRINGS2, leaveFocusArg, when ( getplayerdata( "customClasses" , classNum , "inUse" ) ) )
