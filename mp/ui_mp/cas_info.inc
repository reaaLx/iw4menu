#define CHECK_BOX_COUNT 20

#define CAS_BUTTON( itemIndex, ksName, ksIndex) \
		itemDef \
		{ \
			rect 0 74 220 20 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.8 0.6 0.1 1 \
			background "ks_button_selected_bar" \
			textscale 0.55 \
			visible when ( ( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) && 0 ) \
		} \
		itemDef \
		{ \
			rect CHOICE_RECT( itemIndex ) \
			visible 1 \
			group "mw2_popup_button" \
			style 1 \
			forecolor 1 1 1 1 \
			disablecolor 0.6 0.55 0.55 1 \
			background "ks_button_selection_bar" \
			type 1 \
			textfont 3 \
			textalign 6 \
			textalignx -32 \
			textscale 0.375 \
			visible when ( 1 ) \
			disabled when ( ( !( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) && !localvarint( "ui_numTokens" ) ) || ( ( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) && ( ( !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) && ( int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak1Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak2Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak3Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) ) ) || ( localvarint( "ui_numStreaks" ) == 3 && !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) ) ) ) ) \
			exp text ( "@" + tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 2 ) ) \
			action \
			{ \
				play "mouse_click"; \
				if ( ( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) ) \
				{ \
					if ( localvarstring( "ui_streak1Name" ) == ksName ) \
					{ \
						setLocalVarString "ui_streak1Name" ( "none" ); \
					} \
					if ( localvarstring( "ui_streak2Name" ) == ksName ) \
					{ \
						setLocalVarString "ui_streak2Name" ( "none" ); \
					} \
					if ( localvarstring( "ui_streak3Name" ) == ksName ) \
					{ \
						setLocalVarString "ui_streak3Name" ( "none" ); \
					} \
					setLocalVarInt "ui_numStreaks" ( localvarint( "ui_numStreaks" ) - 1 ); \
					play "mouse_click"; \
					setItemColor self backcolor 0 0 0 1; \
				} \
				else \
				{ \
					if ( ( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) && localvarint( "ui_numStreaks" ) < 3 && !( !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) && ( int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak1Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak2Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak3Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) ) ) ) \
					{ \
						if ( localvarstring( "ui_streak1Name" ) == "none" ) \
						{ \
							setLocalVarString "ui_streak1Name" ( ksName ); \
						} \
						if ( localvarstring( "ui_streak2Name" ) == "none" && localvarstring( "ui_streak1Name" ) != ksName ) \
						{ \
							setLocalVarString "ui_streak2Name" ( ksName ); \
						} \
						if ( localvarstring( "ui_streak3Name" ) == "none" && localvarstring( "ui_streak1Name" ) != ksName && localvarstring( "ui_streak2Name" ) != ksName ) \
						{ \
							setLocalVarString "ui_streak3Name" ( ksName ); \
						} \
						setLocalVarInt "ui_numStreaks" ( localvarint( "ui_numStreaks" ) + 1 ); \
						play "mouse_click"; \
						setItemColor self backcolor 0 0 0 1; \
					} \
					else \
					{ \
						if ( !( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) ) \
						{ \
							open "popup_unlockconfirm"; \
						} \
					} \
				} \
				if ( localvarstring( "ui_streak1Name" ) == "none" || ( int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak2Name" ) , 4 ) ) < int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak1Name" ) , 4 ) ) && localvarstring( "ui_streak2Name" ) != "none" ) ) \
				{ \
					setLocalVarString "ui_tempStreak" ( localvarstring( "ui_streak1Name" ) ); \
					setLocalVarString "ui_streak1Name" ( localvarstring( "ui_streak2Name" ) ); \
					setLocalVarString "ui_streak2Name" ( localvarstring( "ui_tempStreak" ) ); \
				} \
				if ( localvarstring( "ui_streak2Name" ) == "none" || ( int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak3Name" ) , 4 ) ) < int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak2Name" ) , 4 ) ) && localvarstring( "ui_streak3Name" ) != "none" ) ) \
				{ \
					setLocalVarString "ui_tempStreak" ( localvarstring( "ui_streak2Name" ) ); \
					setLocalVarString "ui_streak2Name" ( localvarstring( "ui_streak3Name" ) ); \
					setLocalVarString "ui_streak3Name" ( localvarstring( "ui_tempStreak" ) ); \
				} \
				if ( localvarstring( "ui_streak1Name" ) == "none" || ( int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak2Name" ) , 4 ) ) < int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak1Name" ) , 4 ) ) && localvarstring( "ui_streak2Name" ) != "none" ) ) \
				{ \
					setLocalVarString "ui_tempStreak" ( localvarstring( "ui_streak1Name" ) ); \
					setLocalVarString "ui_streak1Name" ( localvarstring( "ui_streak2Name" ) ); \
					setLocalVarString "ui_streak2Name" ( localvarstring( "ui_tempStreak" ) ); \
				} \
			} \
			onFocus \
			{ \
				play "mouse_over"; \
				if ( dvarstring( "gameMode" ) != "mp" ) \
				{ \
					setItemColor "mw2_popup_button" backcolor 0 0 0 0; \
				} \
				setItemColor self backcolor 0 0 0 1; \
				setLocalVarBool "ui_popupAButton" ( 1 ); \
				setLocalVarString "ui_selected_ref" ( ksName ); \
				setLocalVarString "ui_cas_hint" ( "" ); \
				setLocalVarBool "ui_buttonFocused" ( 1 ); \
				if ( ( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) ) \
				{ \
					setItemColor self backcolor 0 0 0 1; \
				} \
				if ( localvarint( "ui_numStreaks" ) == 3 && !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) ) \
				{ \
					setLocalVarString "ui_cas_hint" ( "@MPUI_3_KILLSTREAKS_SELECTED" ); \
				} \
				setLocalVarString "ui_conflicting_ref" ( "" ); \
				if ( !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) && ( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) && ( int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak1Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_selected_ref" ) , 4 ) ) ) ) \
				{ \
					setLocalVarString "ui_conflicting_ref" ( localvarstring( "ui_streak1Name" ) ); \
				} \
				if ( !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) && ( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) && ( int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak2Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_selected_ref" ) , 4 ) ) ) ) \
				{ \
					setLocalVarString "ui_conflicting_ref" ( localvarstring( "ui_streak2Name" ) ); \
				} \
				if ( !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) && ( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) && ( int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak3Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_selected_ref" ) , 4 ) ) ) ) \
				{ \
					setLocalVarString "ui_conflicting_ref" ( localvarstring( "ui_streak3Name" ) ); \
				} \
				if ( localvarint( "ui_numStreaks" ) == 3 ) \
				{ \
					setLocalVarString "ui_conflicting_ref" ( "" ); \
				} \
				if ( ( !( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) && !localvarint( "ui_numTokens" ) ) || ( ( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) && ( ( !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) && ( int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak1Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak2Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak3Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) ) ) || ( localvarint( "ui_numStreaks" ) == 3 && !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) ) ) ) ) \
				{ \
					setLocalVarBool "ui_popupAButton" ( 0 ); \
				} \
			} \
			leaveFocus \
			{ \
				setItemColor self backcolor 1 1 1 0; \
				setLocalVarBool "ui_popupAButton" ( 0 ); \
				setLocalVarBool "ui_buttonFocused" ( 0 ); \
			} \
		} \
		itemDef \
		{ \
			rect CHOICE_RECT( itemIndex ) \
			decoration \
			visible 1 \
			group "mw2_popup_button" \
			style 1 \
			forecolor 1 1 1 1 \
			disablecolor 0.6 0.55 0.55 1 \
			background "menu_button_selection_bar" \
			type 1 \
			textfont 3 \
			textalign 4 \
			textalignx 24 \
			textscale 0.375 \
			visible when ( ( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) ) \
			disabled when ( ( !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) && ( int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak1Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak2Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak3Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) ) ) || ( localvarint( "ui_numStreaks" ) == 3 && !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) ) ) \
			exp text ( locstring( "@MPUI_N_KILLS" , int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) ) ) \
			action \
			{ \
				play "mouse_click"; \
			} \
			onFocus \
			{ \
				play "mouse_over"; \
				if ( dvarstring( "gameMode" ) != "mp" ) \
				{ \
					setItemColor "mw2_popup_button" backcolor 0 0 0 0; \
				} \
				setItemColor self backcolor 0 0 0 1; \
				setLocalVarBool "ui_popupAButton" ( 1 ); \
				if ( ( !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) && ( int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak1Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak2Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak3Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) ) ) || ( localvarint( "ui_numStreaks" ) == 3 && !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) ) ) \
				{ \
					setLocalVarBool "ui_popupAButton" ( 0 ); \
				} \
			} \
			leaveFocus \
			{ \
				setItemColor self backcolor 1 1 1 0; \
				setLocalVarBool "ui_popupAButton" ( 0 ); \
			} \
		} \
		itemDef \
		{ \
			rect 0 74 220 20 1 1 \
			decoration \
			visible 1 \
			group "mw2_popup_button" \
			style 1 \
			forecolor 0.6 0.55 0.55 1 \
			disablecolor 0.6 0.55 0.55 1 \
			background "menu_button_selection_bar" \
			type 1 \
			textfont 3 \
			textalign 4 \
			textalignx 24 \
			textscale 0.375 \
			visible when ( !( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) ) \
			exp text ( locstring( "@MPUI_N_KILLS" , int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) ) ) \
			action \
			{ \
				play "mouse_click"; \
			} \
			onFocus \
			{ \
				play "mouse_over"; \
				if ( dvarstring( "gameMode" ) != "mp" ) \
				{ \
					setItemColor "mw2_popup_button" backcolor 0 0 0 0; \
				} \
				setItemColor self backcolor 0 0 0 1; \
				setLocalVarBool "ui_popupAButton" ( 1 ); \
			} \
			leaveFocus \
			{ \
				setItemColor self backcolor 1 1 1 0; \
				setLocalVarBool "ui_popupAButton" ( 0 ); \
			} \
		}
#define CAS_CHECK_BOX( itemIndex, ksName, ksIndex ) \
		itemDef \
		{ \
			rect 0 (74 + (itemIndex * CHECK_BOX_COUNT ) ) 20 20 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.6 0.55 0.55 0.5 \
			background "ks_button_check_bg" \
			textscale 0.55 \
			visible when ( !( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) ) \
		} \
		itemDef \
		{ \
			rect 0 (74 + (itemIndex * CHECK_BOX_COUNT ) ) 20 20 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 0.25 \
			background "ks_button_check_locked" \
			textscale 0.55 \
			visible when ( !( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) && !localvarint( "ui_numTokens" ) ) \
		} \
		itemDef \
		{ \
			rect 0 (74 + (itemIndex * CHECK_BOX_COUNT ) ) 20 20 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.55 0.93 0.56 1 \
			background "ks_button_check_locked" \
			textscale 0.55 \
			exp forecolor a ( ( ( ( sin( milliseconds( ) / 150 ) * 0.5 + 0.5 ) * 0.75 + 0.25 ) * ( localvarint( "ui_numTokens" ) > 0 ) ) ) \
			visible when ( !( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) && localvarint( "ui_numTokens" ) ) \
		} \
		itemDef \
		{ \
			rect 0 (74 + (itemIndex * CHECK_BOX_COUNT ) ) 20 20 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "ks_button_check_bg" \
			textscale 0.55 \
			visible when ( !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) && ( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) ) \
		} \
		itemDef \
		{ \
			rect 0 (74 + (itemIndex * CHECK_BOX_COUNT ) ) 20 20 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "ks_button_check_bg" \
			textscale 0.55 \
			visible when ( ( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) ) \
		} \
		itemDef \
		{ \
			rect 0 (74 + (itemIndex * CHECK_BOX_COUNT ) ) 20 20 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			background "ks_button_check_fg" \
			textscale 0.55 \
			visible when ( ( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) ) \
		} \
		itemDef \
		{ \
			rect 0 (74 + (itemIndex * CHECK_BOX_COUNT ) ) 20 20 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 0.65 \
			background "ks_button_check_x" \
			textscale 0.55 \
			visible when ( ( !( localvarstring( "ui_streak1Name" ) == ksName || localvarstring( "ui_streak2Name" ) == ksName || localvarstring( "ui_streak3Name" ) == ksName ) && ( int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak1Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak2Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , ksIndex , localvarstring( "ui_streak3Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , ksIndex , ksName , 4 ) ) ) ) && ( isitemunlocked( ksName ) && getplayerdata( "killstreakUnlocked" , ksName ) ) && ( localvarint( "ui_numStreaks" ) != 3 ) ) \
		}