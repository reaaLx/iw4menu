#define CHOICE_BUTTON_KILLSTREAK( itemIndex, streakName ) \
		PREPROC_SHADER_DRAW_EXP_VIS( CHOICE_RECT( itemIndex ), "ks_button_selected_bar", 3, 0.8 0.6 0.1 1,  \
		when ( ( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) && 0 ) ) \
		itemDef \
		{ \
			rect CHOICE_RECT( itemIndex ) \
			visible 1 \
			group "mw2_popup_button" \
			style 1 \
			foreColor 1 1 1 1 \
			disableColor 0.6 0.55 0.55 1 \
			background "ks_button_selection_bar" \
			type 1 \
			textFont 3 \
			textAlign 6 \
			textAlignX -32 \
			textScale 0.375 \
			disabled when ( ( !( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) \
			&& !localvarint( "ui_numTokens" ) ) || ( ( isitemunlocked( streakName ) \
			&& getplayerdata( "killstreakUnlocked" , streakName ) ) \
			&& ( ( !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) \
			&& ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak1Name" ) , 4 ) ) \
			== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak2Name" ) , 4 ) ) \
			== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak3Name" ) , 4 ) ) \
			== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) ) ) || ( localvarint( "ui_numStreaks" ) == 3 && !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) ) ) ) ) \
			exp text ( "@" + tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 2 ) ) \
			onFocus \
			{ \
				play "mouse_over"; \
				if ( dvarstring( "gameMode" ) != "mp" ) \
				{ \
					setItemColor "mw2_popup_button" backcolor 0 0 0 0; \
				} \
				setItemColor self backcolor 0 0 0 1; \
				setLocalVarBool "ui_popupAButton" ( 1 ); \
				setLocalVarString "ui_selected_ref" ( streakName ); \
				setLocalVarString "ui_cas_hint" ( "" ); \
				setLocalVarBool "ui_buttonFocused" ( 1 ); \
				if ( ( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) ) \
				{ \
					setItemColor self backcolor 0 0 0 1; \
				} \
				if ( localvarint( "ui_numStreaks" ) == 3 && !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) ) \
				{ \
					setLocalVarString "ui_cas_hint" ( "@MPUI_3_KILLSTREAKS_SELECTED" ); \
				} \
				setLocalVarString "ui_conflicting_ref" ( "" ); \
				if ( !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) \
				&& ( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) && ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak1Name" ) , 4 ) ) \
				== int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_selected_ref" ) , 4 ) ) ) ) \
				{ \
					setLocalVarString "ui_conflicting_ref" ( localvarstring( "ui_streak1Name" ) ); \
				} \
				if ( !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) && ( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) \
				&& ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak2Name" ) , 4 ) ) \
				== int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_selected_ref" ) , 4 ) ) ) ) \
				{ \
					setLocalVarString "ui_conflicting_ref" ( localvarstring( "ui_streak2Name" ) ); \
				} \
				if ( !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) && ( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) \
				&& ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak3Name" ) , 4 ) ) \
				== int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_selected_ref" ) , 4 ) ) ) ) \
				{ \
					setLocalVarString "ui_conflicting_ref" ( localvarstring( "ui_streak3Name" ) ); \
				} \
				if ( localvarint( "ui_numStreaks" ) == 3 ) \
				{ \
					setLocalVarString "ui_conflicting_ref" ( "" ); \
				} \
				if ( ( !( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) && !localvarint( "ui_numTokens" ) ) || ( ( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) && ( ( !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) \
				&& ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak1Name" ) , 4 ) ) \
				== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak2Name" ) , 4 ) ) \
				== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak3Name" ) , 4 ) ) \
				== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) ) ) || ( localvarint( "ui_numStreaks" ) == 3 \
				&& !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) ) ) ) ) \
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
			action \
			{ \
				play "mouse_click"; \
				if ( ( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) ) \
				{ \
					if ( localvarstring( "ui_streak1Name" ) == streakName ) \
					{ \
						setLocalVarString "ui_streak1Name" ( "none" ); \
					} \
					if ( localvarstring( "ui_streak2Name" ) == streakName ) \
					{ \
						setLocalVarString "ui_streak2Name" ( "none" ); \
					} \
					if ( localvarstring( "ui_streak3Name" ) == streakName ) \
					{ \
						setLocalVarString "ui_streak3Name" ( "none" ); \
					} \
					setLocalVarInt "ui_numStreaks" ( localvarint( "ui_numStreaks" ) - 1 ); \
					play "mouse_click"; \
					setItemColor self backcolor 0 0 0 1; \
				} \
				else \
				{ \
					if ( ( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) && localvarint( "ui_numStreaks" ) < 3 \
					&& !( !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) \
					&& ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak1Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) \
					|| int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak2Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) \
					|| int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak3Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) ) ) ) \
					{ \
						if ( localvarstring( "ui_streak1Name" ) == "none" ) \
						{ \
							setLocalVarString "ui_streak1Name" ( streakName ); \
						} \
						if ( localvarstring( "ui_streak2Name" ) == "none" && localvarstring( "ui_streak1Name" ) != streakName ) \
						{ \
							setLocalVarString "ui_streak2Name" ( streakName ); \
						} \
						if ( localvarstring( "ui_streak3Name" ) == "none" && localvarstring( "ui_streak1Name" ) != streakName && localvarstring( "ui_streak2Name" ) != streakName ) \
						{ \
							setLocalVarString "ui_streak3Name" ( streakName ); \
						} \
						setLocalVarInt "ui_numStreaks" ( localvarint( "ui_numStreaks" ) + 1 ); \
						play "mouse_click"; \
						setItemColor self backcolor 0 0 0 1; \
					} \
					else \
					{ \
						if ( !( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) ) \
						{ \
							open "popup_unlockconfirm"; \
						} \
					} \
				} \
				if ( localvarstring( "ui_streak1Name" ) == "none" || ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak2Name" ) , 4 ) ) \
				< int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak1Name" ) , 4 ) ) && localvarstring( "ui_streak2Name" ) != "none" ) ) \
				{ \
					setLocalVarString "ui_tempStreak" ( localvarstring( "ui_streak1Name" ) ); \
					setLocalVarString "ui_streak1Name" ( localvarstring( "ui_streak2Name" ) ); \
					setLocalVarString "ui_streak2Name" ( localvarstring( "ui_tempStreak" ) ); \
				} \
				if ( localvarstring( "ui_streak2Name" ) == "none" || ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak3Name" ) , 4 ) ) \
				< int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak2Name" ) , 4 ) ) && localvarstring( "ui_streak3Name" ) != "none" ) ) \
				{ \
					setLocalVarString "ui_tempStreak" ( localvarstring( "ui_streak2Name" ) ); \
					setLocalVarString "ui_streak2Name" ( localvarstring( "ui_streak3Name" ) ); \
					setLocalVarString "ui_streak3Name" ( localvarstring( "ui_tempStreak" ) ); \
				} \
				if ( localvarstring( "ui_streak1Name" ) == "none" || ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak2Name" ) , 4 ) ) \
				< int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak1Name" ) , 4 ) ) && localvarstring( "ui_streak2Name" ) != "none" ) ) \
				{ \
					setLocalVarString "ui_tempStreak" ( localvarstring( "ui_streak1Name" ) ); \
					setLocalVarString "ui_streak1Name" ( localvarstring( "ui_streak2Name" ) ); \
					setLocalVarString "ui_streak2Name" ( localvarstring( "ui_tempStreak" ) ); \
				} \
			} \
		} \
		itemDef \
		{ \
			rect CHOICE_RECT( itemIndex ) \
			decoration \
			visible 1 \
			group "mw2_popup_button" \
			style 1 \
			foreColor 1 1 1 1 \
			disableColor 0.6 0.55 0.55 1 \
			type 1 \
			textFont 3 \
			textAlign 4 \
			textAlignX 24 \
			textScale 0.375 \
			visible when ( ( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) ) \
			disabled when ( ( !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) \
			&& ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak1Name" ) , 4 ) ) \
			== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak2Name" ) , 4 ) ) \
			== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak3Name" ) , 4 ) ) \
			== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) ) ) || ( localvarint( "ui_numStreaks" ) == 3 \
			&& !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) ) ) \
			exp text ( locstring( "@MPUI_N_KILLS" , int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) ) ) \
			onFocus \
			{ \
				play "mouse_over"; \
				if ( dvarstring( "gameMode" ) != "mp" ) \
				{ \
					setItemColor "mw2_popup_button" backcolor 0 0 0 0; \
				} \
				setItemColor self backcolor 0 0 0 1; \
				setLocalVarBool "ui_popupAButton" ( 1 ); \
				if ( ( !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) \
				&& ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak1Name" ) , 4 ) ) \
				== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak2Name" ) , 4 ) ) \
				== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak3Name" ) , 4 ) ) \
				== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) ) ) || ( localvarint( "ui_numStreaks" ) == 3 \
				&& !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) ) ) \
				{ \
					setLocalVarBool "ui_popupAButton" ( 0 ); \
				} \
			} \
			leaveFocus \
			{ \
				setItemColor self backcolor 1 1 1 0; \
				setLocalVarBool "ui_popupAButton" ( 0 ); \
			} \
			action \
			{ \
				play "mouse_click"; \
			} \
		} \
		PREPROC_TEXT_DRAW_ADV_VIS( CHOICE_RECT( itemIndex ), ORIGIN_NONE, locstring( "@MPUI_N_KILLS" , int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) ), 0.375, 24, 0, 4, 3, 0.6 0.55 0.55 1, \
		when ( !( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) ) textstyle 0 ) \
		PREPROC_SHADER_DRAW_EXP_VIS( 0 (74 + ( itemIndex * 20 ) ) 20 20 1 1, "ks_button_check_bg", 3, 0.6 0.55 0.55 0.5, \
		when ( !( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) ) ) \
		PREPROC_SHADER_DRAW_EXP_VIS( 0 (74 + ( itemIndex * 20 ) ) 20 20 1 1, "ks_button_check_locked", 3, 1 1 1 0.25, \
		when ( !( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) && !localvarint( "ui_numTokens" ) ) ) \
		PREPROC_SHADER_DRAW_EXP_VIS( 0 (74 + ( itemIndex * 20 ) ) 20 20 1 1, "ks_button_check_locked", 3, 0.55 0.93 0.56 1, \
		when ( !( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) && localvarint( "ui_numTokens" ) ) \
		exp forecolor a ( ( ( ( sin( milliseconds( ) / 150 ) * 0.5 + 0.5 ) * 0.75 + 0.25 ) * ( localvarint( "ui_numTokens" ) > 0 ) ) ) ) \
		PREPROC_SHADER_DRAW_EXP_VIS( 0 (74 + ( itemIndex * 20 ) ) 20 20 1 1, "ks_button_check_bg", 3, 0 0 0 1, \
		when ( !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) \
		&& ( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) ) ) \
		PREPROC_SHADER_DRAW_EXP_VIS( 0 (74 + ( itemIndex * 20 ) ) 20 20 1 1, "ks_button_check_bg", 3, 0 0 0 1, \
		when ( ( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) ) ) \
		PREPROC_SHADER_DRAW_EXP_VIS( 0 (74 + ( itemIndex * 20 ) ) 20 20 1 1, "ks_button_check_fg", 3, 1 1 1 1, \
		when ( ( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) ) ) \
		PREPROC_SHADER_DRAW_EXP_VIS( 0 (74 + ( itemIndex * 20 ) ) 20 20 1 1, "ks_button_check_x", 3, 1 1 1 0.65, \
		when ( ( !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) \
		&& ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak1Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) \
		|| int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak2Name" ) , 4 ) ) \
		== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak3Name" ) , 4 ) ) \
		== int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) ) ) \
		&& ( isitemunlocked( streakName ) && getplayerdata( "killstreakUnlocked" , streakName ) ) && ( localvarint( "ui_numStreaks" ) != 3 ) ) )
