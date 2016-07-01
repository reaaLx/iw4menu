#ifndef STAT_ENABLE
#define STAT_ENABLE	1
#endif

#ifndef CHOICE_POPMENU_SIZE_Y
#define CHOICE_POPMENU_SIZE_Y 124 
#endif

#define CAC_DVAR 			"ui_popup_cac_weapon_ CAC_TYPE_IS _tabDepth"
#define CAC_TYPE_IS			primary

#define CAC_TAB_TITLE1		localVarString( "ui_tab1Name" )
#define CAC_TAB_TITLE2		localVarString( "ui_tab2Name" )
#define CAC_TAB_TITLE3		localVarString( "ui_tab3Name" )
#define CAC_TAB_TITLE4		localVarString( "ui_tab4Name" )
#define CAC_TAB_TITLE5		localVarString( "ui_tab5Name" )

#define LOCAL_CLOSE_WPN \
		close "popup_cac_weapon_primary"; \
		close "popup_primary_attachments";  \
		close "popup_secondary_attachments";  \
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
		close "popup_cac_LMG_secondary"; \
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
		close "popup_cac_other_primary";

#define LOCAL_WEAPON_CLASS2( itemIndex, textArg, actionArg, onFocusArg, leaveFocusArg ) \
		itemDef \
		{ \
			rect CHOICE_RECT( itemIndex ) \
			forecolor 1 1 1 1  \
			style 1 \
			background "popup_button_selection_bar_short" \
			group "mw2_popup_button" \
			type 1 \
			textAlign 4 \
			textAlignX 68 \
			textScale 0.375 \
			textFont 3 \
			exp text( textArg ); \
			visible 1 \
			onFocus \
			{ \
				onFocusArg \
				play "mouse_over"; \
				setItemColor self backcolor 0 0 0 1; \
				setLocalVarBool "ui_popupAButton" ( 1 ); \
			} \
			leaveFocus \
			{ \
				leaveFocusArg \
				setItemColor self backcolor 1 1 1 0; \
				setLocalVarBool "ui_popupAButton" ( 0 ); \
			} \
			action \
			{ \
				actionArg \
				play "mouse_click"; \
				if ( localvarint( "ui_tabDepth" ) == 0 ) \
				{ \
					setLocalVarString "ui_tab1Name" ( textArg ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 1 ) \
				{ \
					setLocalVarString "ui_tab2Name" ( textArg ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 2 ) \
				{ \
					setLocalVarString "ui_tab3Name" ( textArg ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 3 ) \
				{ \
					setLocalVarString "ui_tab4Name" ( textArg ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 4 ) \
				{ \
					setLocalVarString "ui_tab5Name" ( textArg ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 5 ) \
				{ \
					setLocalVarString "ui_tab6Name" ( textArg ); \
				} \
			} \
		}
#define LOCAL_WEAPON_ITEM( itemIndex, textArg, weaponName, weaponRef ) \
		itemDef \
		{ \
			name weaponName \
			rect CHOICE_RECT( itemIndex ) \
			visible 1 \
			group "mw2_popup_button" \
			style 1 \
			forecolor 1 1 1 1 \
			disablecolor 0.6 0.55 0.55 1 \
			background "popup_button_selection_bar_short" \
			type 1 \
			textfont 3 \
			textalign 4 \
			textalignx 68 \
			textscale 0.375 \
			text textArg \
			onFocus \
			{ \
				play "mouse_over"; \
				setItemColor self backcolor 0 0 0 1; \
				setLocalVarBool "ui_popupAButton" ( 1 ); \
				setLocalVarString "ui_selected_ref" ( weaponRef ); \
				setLocalVarString "ui_info_name" ( "@" + tablelookup( "mp/statsTable.csv" , 4 , weaponRef , 3 ) ); \
				setLocalVarString "ui_info_desc" ( "@" + tablelookup( "mp/statstable.csv" , 4 , weaponRef , 7 ) ); \
				setLocalVarString "ui_info_icon" ( tablelookup( "mp/statsTable.csv" , 4 , weaponRef , 6 ) ); \
			} \
			leaveFocus \
			{ \
				setItemColor self backcolor 1 1 1 0; \
				setLocalVarBool "ui_popupAButton" ( 0 ); \
			} \
			action \
			{ \
				play "mouse_click"; \
				if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) != weaponRef ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "camo" , "none" ); \
				} \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "weapon" , weaponRef ); \
				setPlayerData( "weaponNew" , weaponRef , "false" ); \
				if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
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
				if ( 0 == 0 ) \
				{ \
					if ( ( tablelookup( "mp/statsTable.csv" , 4 , weaponRef , 11 ) != "" ) ) \
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
					if ( ( tablelookup( "mp/statsTable.csv" , 4 , weaponRef , 11 ) != "" ) ) \
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
						LOCAL_CLOSE_WPN \
					} \
				} \
			} \
		}
		
#define POPMENU_CAC_TAB( textArg ) \
		itemDef \
		{ \
			rect -64 0 854 CHOICE_POPMENU_SIZE_Y 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 0.5 0.5 0.5 1 \
			background "white" \
			textscale 0.55 \
		} \
		itemDef \
		{ \
			rect -64 0 1708 480 1 1 \
			decoration \
			visible 0 \
			style 3 \
			forecolor 1 1 1 0.75 \
			background "mw2_popup_bg_fogstencil" \
			textscale 0.55 \
			exp rect x ( 0 - ( ( float( milliseconds( ) % 60000 ) / 60000 ) * ( 854 ) ) ) \
		} \
		itemDef \
		{ \
			rect -64 0 -1708 -480 1 1 \
			decoration \
			visible 0 \
			style 3 \
			forecolor 0.85 0.85 0.85 1 \
			background "mw2_popup_bg_fogscroll" \
			textscale 0.55 \
			exp rect x ( 0 - ( ( float( milliseconds( ) % 60000 ) / 60000 ) * ( 854 ) ) ) \
		} \
		itemDef \
		{ \
			rect -64 0 854 0 1 1 \
			decoration \
			visible 0 \
			style 3 \
			forecolor 1 1 1 1 \
			background "mockup_popup_bg_stencilfill" \
			textscale 0.55 \
			exp rect h ( ( 24 + 5 * 20 ) ) \
		} \
		itemDef \
		{ \
			rect -64 0 -1708 -480 1 1 \
			decoration \
			visible 0 \
			style 3 \
			forecolor 1 1 1 0.75 \
			background "mw2_popup_bg_fogstencil" \
			textscale 0.55 \
			exp rect x ( ( - 854 ) + ( ( float( milliseconds( ) % 50000 ) / 50000 ) * ( 854 ) ) ) \
		} \
		itemDef \
		{ \
			rect -64 0 -1708 -480 1 1 \
			decoration \
			visible 0 \
			style 3 \
			forecolor 0.85 0.85 0.85 1 \
			background "mw2_popup_bg_fogscroll" \
			textscale 0.55 \
			exp rect x ( ( - 854 ) + ( ( float( milliseconds( ) % 50000 ) / 50000 ) * ( 854 ) ) ) \
		} \
		itemDef \
		{ \
			rect -64 0 854 CHOICE_POPMENU_SIZE_Y 1 1 \
			decoration \
			visible 0 \
			style 3 \
			forecolor 1 1 1 0 \
			background "small_box_lightfx" \
			textscale 0.55 \
			exp rect h ( ( 24 + 5 * 20 ) ) \
		} \
		itemDef \
		{ \
			rect 790 0 32 32 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "drop_shadow_br" \
			textscale 0.55 \
			exp rect y ( CHOICE_POPMENU_SIZE_Y ) \
			visible when ( !localvarint( "ui_centerPopup" ) ) \
		} \
		itemDef \
		{ \
			rect -64 0 854 32 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "drop_shadow_b" \
			textscale 0.55 \
			exp rect y ( CHOICE_POPMENU_SIZE_Y ) \
			visible when ( !localvarint( "ui_centerPopup" ) ) \
		} \
		itemDef \
		{ \
			rect -96 0 32 32 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "drop_shadow_bl" \
			textscale 0.55 \
			exp rect y ( CHOICE_POPMENU_SIZE_Y ) \
			visible when ( !localvarint( "ui_centerPopup" ) ) \
		} \
		itemDef \
		{ \
			rect -64 0 280 CHOICE_POPMENU_SIZE_Y 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 1 1 1 0 \
			background "gradient_fadein" \
			textscale 0.55 \
		} \
		itemDef \
		{ \
			rect -56 0 200 CHOICE_POPMENU_SIZE_Y 2 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 0.5 \
			background "small_box_lightfx" \
			textscale 0.55 \
			exp rect y ( 1 ) /*fixes not going with the define ie. CHOICE_POPMENU_SIZE_Y*/ \
		} \
		itemDef \
		{ \
			rect -64 0 280 20 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 0.25 0.25 0.25 1 \
			background "white" \
			textscale 0.55 \
			exp rect y ( - 20 - ( ( localvarint( "ui_tabDepth" ) - 1 ) * 20 ) ) \
			visible when ( localvarint( "ui_tabDepth" ) > ( 1 - 1 ) ) \
		} \
		itemDef \
		{ \
			rect -64 0 280 20 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 0 0 0 1 \
			background "gradient_fadein" \
			textfont 9 \
			textalign 4 \
			textalignx 68 \
			textscale 0.375 \
			exp rect y ( - 20 - ( ( localvarint( "ui_tabDepth" ) - 1 ) * 20 ) ) \
			exp forecolor r ( 1 - ( ( localvarint( "ui_tabDepth" ) > 1 ) * 0.35 ) ) \
			exp forecolor g ( 1 - ( ( localvarint( "ui_tabDepth" ) > 1 ) * 0.35 ) ) \
			exp forecolor b ( 1 - ( ( localvarint( "ui_tabDepth" ) > 1 ) * 0.35 ) ) \
			visible when ( localvarint( "ui_tabDepth" ) > ( 1 - 1 ) ) \
			exp text ( CAC_TAB_TITLE1 ) \
		} \
		itemDef \
		{ \
			rect -64 0 280 20 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 0.25 0.25 0.25 1 \
			background "white" \
			textscale 0.55 \
			exp rect y ( - 20 - ( ( localvarint( "ui_tabDepth" ) - 2 ) * 20 ) ) \
			visible when ( localvarint( "ui_tabDepth" ) > ( 2 - 1 ) ) \
		} \
		itemDef \
		{ \
			rect -64 0 280 20 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 0 0 0 1 \
			background "gradient_fadein" \
			textfont 9 \
			textalign 4 \
			textalignx 68 \
			textscale 0.375 \
			exp rect y ( - 20 - ( ( localvarint( "ui_tabDepth" ) - 2 ) * 20 ) ) \
			exp forecolor r ( 1 - ( ( localvarint( "ui_tabDepth" ) > 2 ) * 0.35 ) ) \
			exp forecolor g ( 1 - ( ( localvarint( "ui_tabDepth" ) > 2 ) * 0.35 ) ) \
			exp forecolor b ( 1 - ( ( localvarint( "ui_tabDepth" ) > 2 ) * 0.35 ) ) \
			visible when ( localvarint( "ui_tabDepth" ) > ( 2 - 1 ) ) \
			exp text ( CAC_TAB_TITLE2 ) \
		} \
		itemDef \
		{ \
			rect -64 0 280 20 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 0.25 0.25 0.25 1 \
			background "white" \
			textscale 0.55 \
			exp rect y ( - 20 - ( ( localvarint( "ui_tabDepth" ) - 3 ) * 20 ) ) \
			visible when ( localvarint( "ui_tabDepth" ) > ( 3 - 1 ) ) \
		} \
		itemDef \
		{ \
			rect -64 0 280 20 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 0 0 0 1 \
			background "gradient_fadein" \
			textfont 9 \
			textalign 4 \
			textalignx 68 \
			textscale 0.375 \
			exp rect y ( - 20 - ( ( localvarint( "ui_tabDepth" ) - 3 ) * 20 ) ) \
			exp forecolor r ( 1 - ( ( localvarint( "ui_tabDepth" ) > 3 ) * 0.35 ) ) \
			exp forecolor g ( 1 - ( ( localvarint( "ui_tabDepth" ) > 3 ) * 0.35 ) ) \
			exp forecolor b ( 1 - ( ( localvarint( "ui_tabDepth" ) > 3 ) * 0.35 ) ) \
			visible when ( localvarint( "ui_tabDepth" ) > ( 3 - 1 ) ) \
			exp text ( CAC_TAB_TITLE3 ) \
		} \
		itemDef \
		{ \
			rect -64 0 280 20 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 0.25 0.25 0.25 1 \
			background "white" \
			textscale 0.55 \
			exp rect y ( - 20 - ( ( localvarint( "ui_tabDepth" ) - 4 ) * 20 ) ) \
			visible when ( localvarint( "ui_tabDepth" ) > ( 4 - 1 ) ) \
		} \
		itemDef \
		{ \
			rect -64 0 280 20 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 0 0 0 1 \
			background "gradient_fadein" \
			textfont 9 \
			textalign 4 \
			textalignx 68 \
			textscale 0.375 \
			exp rect y ( - 20 - ( ( localvarint( "ui_tabDepth" ) - 4 ) * 20 ) ) \
			exp forecolor r ( 1 - ( ( localvarint( "ui_tabDepth" ) > 4 ) * 0.35 ) ) \
			exp forecolor g ( 1 - ( ( localvarint( "ui_tabDepth" ) > 4 ) * 0.35 ) ) \
			exp forecolor b ( 1 - ( ( localvarint( "ui_tabDepth" ) > 4 ) * 0.35 ) ) \
			visible when ( localvarint( "ui_tabDepth" ) > ( 4 - 1 ) ) \
			exp text ( CAC_TAB_TITLE4 ) \
		} \
		itemDef \
		{ \
			rect -64 0 280 20 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 0.25 0.25 0.25 1 \
			background "white" \
			textscale 0.55 \
			exp rect y ( - 20 - ( ( localvarint( "ui_tabDepth" ) - 5 ) * 20 ) ) \
			visible when ( localvarint( "ui_tabDepth" ) > ( 5 - 1 ) ) \
		} \
		itemDef \
		{ \
			rect -64 0 280 20 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 0 0 0 1 \
			background "gradient_fadein" \
			textfont 9 \
			textalign 4 \
			textalignx 68 \
			textscale 0.375 \
			exp rect y ( - 20 - ( ( localvarint( "ui_tabDepth" ) - 5 ) * 20 ) ) \
			exp forecolor r ( 1 - ( ( localvarint( "ui_tabDepth" ) > 5 ) * 0.35 ) ) \
			exp forecolor g ( 1 - ( ( localvarint( "ui_tabDepth" ) > 5 ) * 0.35 ) ) \
			exp forecolor b ( 1 - ( ( localvarint( "ui_tabDepth" ) > 5 ) * 0.35 ) ) \
			visible when ( localvarint( "ui_tabDepth" ) > ( 5 - 1 ) ) \
			exp text ( CAC_TAB_TITLE5 ) \
		}
/*
#define LOCAL_WEAPON_STAT_SHOW \
		itemDef \
		{ \
			rect -56 0 200 184 2 1 \
			decoration \
			autowrapped \
			visible 1 \
			forecolor 1 1 1 0.65 \
			textfont 3 \
			textalign 4 \
			textalignx 4 \
			textaligny 104 \
			textscale 0.375 \
			visible when ( !isitemunlocked( localvarstring( "ui_selected_ref" ) ) ) \
			exp text ( "@" + tablelookup( "mp/rankTable.csv" , 0 , tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_selected_ref" ) , 2 ) , 17 ) ) \
		} \
		itemDef \
		{ \
			rect -56 0 200 184 2 1 \
			decoration \
			autowrapped \
			visible 1 \
			forecolor 1 1 1 0.65 \
			textfont 3 \
			textalign 4 \
			textalignx 4 \
			textaligny 144 \
			textscale 0.375 \
			text "@PLATFORM_VIEW_CHALLENGES" \
			visible when ( isitemunlocked( localvarstring( "ui_selected_ref" ) ) && ( tablelookup( "mp/challengeTable.csv" , 6 , localvarstring( "ui_selected_ref" ) , 4 ) ) != "" ) \
		} \
		itemDef \
		{ \
			rect -128 22 120 4 3 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 0.65 \
			backcolor 0 0 0 1 \
			background "gradient_fadein" \
			textfont 3 \
			textalign 6 \
			textaligny -20 \
			textscale 0.375 \
			text "@MPUI_ACCURACY" \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 22 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 22 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.75 1 0.7 0.85 \
			background "white" \
			textscale 0.55 \
			exp rect w ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 22 ) / 100 ) * 120 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 22 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 22 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.85 0.85 0.85 1 \
			background "gradient_fadein" \
			textscale 0.55 \
			exp rect w ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 22 ) / 100 ) * 120 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 22 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 22 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 0.25 0.65 \
			background "white" \
			textscale 0.55 \
			exp rect x ( - 64 + ( 0 - 120 * ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 22 ) / 100 ) ) + ( ( 0 - 120 * ( 0 / 100 ) ) * ( 0 < 0 ) ) ) \
			exp rect w ( min( 120 * ( 0 / 100 ) , ( 1 - ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 22 ) / 100 ) ) * 120 ) ) \
			exp forecolor r ( ( 0 < 0 ) * 0.45 + 0.25 ) \
			exp forecolor g ( ( 0 > 0 ) * 0.45 + 0.25 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 22 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 48 120 4 3 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 0.65 \
			backcolor 0 0 0 1 \
			background "gradient_fadein" \
			textfont 3 \
			textalign 6 \
			textaligny -20 \
			textscale 0.375 \
			text "@MPUI_DAMAGE" \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 23 ) && 1  \
		} \
		itemDef \
		{ \
			rect -128 48 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.75 1 0.7 0.85 \
			background "white" \
			textscale 0.55 \
			exp rect w ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 23 ) / 100 ) * 120 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 23 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 48 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.85 0.85 0.85 1 \
			background "gradient_fadein" \
			textscale 0.55 \
			exp rect w ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 23 ) / 100 ) * 120 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 23 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 48 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 0.25 0.65 \
			background "white" \
			textscale 0.55 \
			exp rect x ( - 64 + ( 0 - 120 * ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 23 ) / 100 ) ) + ( ( 0 - 120 * ( 0 / 100 ) ) * ( 0 < 0 ) ) ) \
			exp rect w ( min( 120 * ( 0 / 100 ) , ( 1 - ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 23 ) / 100 ) ) * 120 ) ) \
			exp forecolor r ( ( 0 < 0 ) * 0.45 + 0.25 ) \
			exp forecolor g ( ( 0 > 0 ) * 0.45 + 0.25 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 23 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 74 120 4 3 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 0.65 \
			backcolor 0 0 0 1 \
			background "gradient_fadein" \
			textfont 3 \
			textalign 6 \
			textaligny -20 \
			textscale 0.375 \
			text "@MPUI_RANGE" \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 24 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 74 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.75 1 0.7 0.85 \
			background "white" \
			textscale 0.55 \
			exp rect w ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 24 ) / 100 ) * 120 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 24 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 74 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.85 0.85 0.85 1 \
			background "gradient_fadein" \
			textscale 0.55 \
			exp rect w ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 24 ) / 100 ) * 120 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 24 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 74 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 0.25 0.65 \
			background "white" \
			textscale 0.55 \
			exp rect x ( - 64 + ( 0 - 120 * ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 24 ) / 100 ) ) + ( ( 0 - 120 * ( 0 / 100 ) ) * ( 0 < 0 ) ) ) \
			exp rect w ( min( 120 * ( 0 / 100 ) , ( 1 - ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 24 ) / 100 ) ) * 120 ) ) \
			exp forecolor r ( ( 0 < 0 ) * 0.45 + 0.25 ) \
			exp forecolor g ( ( 0 > 0 ) * 0.45 + 0.25 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 24 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 100 120 4 3 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 0.65 \
			backcolor 0 0 0 1 \
			background "gradient_fadein" \
			textfont 3 \
			textalign 6 \
			textaligny -20 \
			textscale 0.375 \
			text "@MPUI_FIRE_RATE" \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 25 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 100 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.75 1 0.7 0.85 \
			background "white" \
			textscale 0.55 \
			exp rect w ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 25 ) / 100 ) * 120 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 25 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 100 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.85 0.85 0.85 1 \
			background "gradient_fadein" \
			textscale 0.55 \
			exp rect w ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 25 ) / 100 ) * 120 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 25 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 100 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 0.25 0.65 \
			background "white" \
			textscale 0.55 \
			exp rect x ( - 64 + ( 0 - 120 * ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 25 ) / 100 ) ) + ( ( 0 - 120 * ( 0 / 100 ) ) * ( 0 < 0 ) ) ) \
			exp rect w ( min( 120 * ( 0 / 100 ) , ( 1 - ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 25 ) / 100 ) ) * 120 ) ) \
			exp forecolor r ( ( 0 < 0 ) * 0.45 + 0.25 ) \
			exp forecolor g ( ( 0 > 0 ) * 0.45 + 0.25 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 25 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 126 120 4 3 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 0.65 \
			backcolor 0 0 0 1 \
			background "gradient_fadein" \
			textfont 3 \
			textalign 6 \
			textaligny -20 \
			textscale 0.375 \
			text "@MPUI_MOBILITY" \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 26 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 126 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.75 1 0.7 0.85 \
			background "white" \
			textscale 0.55 \
			exp rect w ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 26 ) / 100 ) * 120 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 26 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 126 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.85 0.85 0.85 1 \
			background "gradient_fadein" \
			textscale 0.55 \
			exp rect w ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 26 ) / 100 ) * 120 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 26 ) && 1 ) \
		} \
		itemDef \
		{ \
			rect -128 126 120 2 3 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 0.25 0.65 \
			background "white" \
			textscale 0.55 \
			exp rect x ( - 64 + ( 0 - 120 * ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 26 ) / 100 ) ) + ( ( 0 - 120 * ( 0 / 100 ) ) * ( 0 < 0 ) ) ) \
			exp rect w ( min( 120 * ( 0 / 100 ) , ( 1 - ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 26 ) / 100 ) ) * 120 ) ) \
			exp forecolor r ( ( 0 < 0 ) * 0.45 + 0.25 ) \
			exp forecolor g ( ( 0 > 0 ) * 0.45 + 0.25 ) \
			visible when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 26 ) && 1 ) \
		}	
*/		