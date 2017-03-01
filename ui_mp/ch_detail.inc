#define PQ_DEF_0 \
tablelookupbyrow(localvarstring("ui_challengeTierTable")

#define PQ_DEF_1 \
(PQ_DEF_0,chIndex,1)=="tier_prestige")

#define PQ_DEF_2 \
tablelookup("mp/allChallengesTable.csv",0,PQ_DEF_0,chIndex,0)

#define PQ_DEF_3 \
int(max(getplayerdata("challengeState",PQ_DEF_0,chIndex,0)),1)

#define F_HEIGHT ((sin(milliseconds()/150)*0.5+0.5)*0.5+0.5)

#define LOCAL_CHD_BUTTON( itemIndex, chIndex ) \
		itemDef \
		{ \
			rect CHOICE_RECT( itemIndex ) \
			visible 1 \
			group "mw2_button" \
			style 1 \
			forecolor 1 1 1 1 \
			disablecolor 0.6 0.55 0.55 1 \
			background "popup_button_selection_bar_short" \
			type 1 \
			textfont 3 \
			textalign 6 \
			textalignx -76 \
			textscale 0.375 \
			glowColor 0 0 0 1 \
			exp glowcolor r (PQ_DEF_1*0.25*F_HEIGHT) \
			exp glowcolor g (PQ_DEF_1*0.75*F_HEIGHT) \
			exp glowcolor b (PQ_DEF_1*0.25*F_HEIGHT) \
			visible when (PQ_DEF_0,chIndex,0)!=""&&!(int(PQ_DEF_2,6+((PQ_DEF_3)-1)*2)))=="")&&!(PQ_DEF_1&&!isitemunlocked("tier_prestige"))) \
			disabled when (!isitemunlocked(PQ_DEF_0,chIndex,0))||!isitemunlocked(PQ_DEF_0,chIndex,1))) \
			exp text(locstring("@"+PQ_DEF_2,1))+locstring("@"+PQ_DEF_2,3)+"_"+PQ_DEF_3))) \
			action \
			{ \
				play "mouse_click"; \
			} \
			onFocus \
			{ \
				play "mouse_over"; \
				if(dvarstring("gameMode")!="mp") \
				{ \
					setItemColor "mw2_button" backcolor 0 0 0 0; \
				} \
				setItemColor self backcolor 0 0 0 1; \
				setLocalVarBool "ui_menuAButton"(1); \
				setLocalVarString "ui_selected_ref"(PQ_DEF_0,chIndex,0)); \
				setLocalVarString "ui_selected_unlock"(tablelookup("mp/unlockTable.csv",0,localvarstring("ui_selected_ref"),(4+int(max(getplayerdata("challengeState",localvarstring("ui_selected_ref")),1)))-1)); \
				setLocalVarString "ui_selected_unlockType"(""); \
				if(tablelookup("mp/camoTable.csv",1,localvarstring("ui_selected_unlock"),1)!="") \
				{ \
					setLocalVarString "ui_selected_unlockType"("camo"); \
				} \
				if(tablelookup("mp/attachmentTable.csv",4,localvarstring("ui_selected_unlock"),4)!="") \
				{ \
					setLocalVarString "ui_selected_unlockType"("attachment"); \
				} \
				if(localvarstring("ui_selected_unlock")=="title") \
				{ \
					setLocalVarString "ui_selected_unlockType"("title"); \
				} \
				if ( localvarstring("ui_selected_unlock")=="icon") \
				{ \
					setLocalVarString "ui_selected_unlockType"("icon"); \
				} \
			} \
			leaveFocus \
			{ \
				setItemColor self backcolor 0 0 0 "0.0"; \
				setLocalVarString "ui_hint_text" ("@NULL_EMPTY"); \
				setLocalVarBool "ui_menuAButton" (0); \
			} \
		} \
		itemDef \
		{ \
			rect CHOICE_RECT( itemIndex ) \
			visible 1 \
			group "mw2_button" \
			style 1 \
			forecolor 1 1 1 1 \
			disablecolor 0.6 0.55 0.55 1 \
			background "popup_button_selection_bar_short" \
			type 1 \
			textfont 3 \
			textalign 6 \
			textalignx -76 \
			textscale 0.375 \
			glowColor 0 0 0 1 \
			exp glowcolor r (PQ_DEF_1*0.25*F_HEIGHT) \
			exp glowcolor g (PQ_DEF_1*0.75*F_HEIGHT) \
			exp glowcolor b (PQ_DEF_1*0.25*F_HEIGHT) \
			visible when (tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0)!=""&&(int(tablelookup("mp/allChallengesTable.csv",0,tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0),6+((int(max(getplayerdata("challengeState",tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0)),1))-1)*2)))=="")&&!((tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,1)=="tier_prestige")&&!isitemunlocked("tier_prestige"))) \
			disabled when (!isitemunlocked(tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0))||!isitemunlocked(tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,1))) \
			exp text (locstring("@"+tablelookup("mp/allChallengesTable.csv",0,tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0),1))+locstring("@"+tablelookup("mp/allChallengesTable.csv",0,tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0),3)+"_"+(int(max(getplayerdata("challengeState",tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0)),1))-1))) \
			action \
			{ \
				play "mouse_click"; \
			} \
			onFocus \
			{ \
				play "mouse_over"; \
				if(dvarstring("gameMode")!="mp") \
				{ \
					setItemColor "mw2_button" backcolor 0 0 0 0; \
				} \
				setItemColor self backcolor 0 0 0 1; \
				setLocalVarBool "ui_menuAButton" (1); \
				setLocalVarString "ui_selected_ref"(tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0)); \
			} \
			leaveFocus \
			{ \
				setItemColor self backcolor 0 0 0 "0.0"; \
				setLocalVarString "ui_hint_text" ("@NULL_EMPTY"); \
				setLocalVarBool "ui_menuAButton" (0); \
			} \
		} \
		itemDef \
		{ \
			rect 216 (35+(itemIndex*20)+0) 40 10 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 0.55 \
			background "black" \
			textscale 0.55 \
			exp rect w (40) \
			exp rect x (216+(46*dvarbool("wideScreen"))) \
			visible when (tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0)!=""&&!(int(tablelookup("mp/allChallengesTable.csv",0,tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0),6+((int(max(getplayerdata("challengeState",tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0)),1))-1)*2)))=="")&&!((tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,1)=="tier_prestige")&&!isitemunlocked("tier_prestige"))) \
		} \
		itemDef \
		{ \
			rect 216 (35+(itemIndex*20)+2) 40 6 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.85 0.85 0.85 1 \
			background "gradient_fadein" \
			textscale 0.55 \
			exp rect w (((getplayerdata("challengeProgress",tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0))-0)/(int(tablelookup("mp/allChallengesTable.csv",0,tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0),6+((int(max(getplayerdata("challengeState",tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0)),1))-1)*2)))-0))*40) \
			exp rect x (216+(46*dvarbool("wideScreen"))) \
			visible when (tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0)!=""&&!((tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,1)=="tier_prestige")&&!isitemunlocked("tier_prestige"))) \
		} \
		itemDef \
		{ \
			rect 216 (35+(itemIndex*20)+2) 40 6 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 0.25 0.65 \
			background "white" \
			textscale 0.55 \
			exp rect w (((getplayerdata("challengeProgress",tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0))-0)/(int(tablelookup("mp/allChallengesTable.csv",0,tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0),6+((int(max(getplayerdata("challengeState",tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0)),1))-1)*2)))-0))*40) \
			exp rect x (216+(46*dvarbool("wideScreen"))) \
			visible when (tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0)!=""&&!((tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,1)=="tier_prestige")&&!isitemunlocked("tier_prestige"))) \
		} \
		itemDef \
		{ \
			rect 216 (35+(itemIndex*20)+0) 40 10 1 1 \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 0.65 \
			backcolor 0 0 0 0.55 \
			background "white" \
			textfont 10 \
			textalign 9 \
			textscale 0.275 \
			text "@MPUI_DONE_CAPS" \
			exp rect x (216+(46*dvarbool("wideScreen"))) \
			visible when (tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0)!=""&&(int(tablelookup("mp/allChallengesTable.csv",0,tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0),6+((int(max(getplayerdata("challengeState",tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,0)),1))-1)*2)))=="")&&!((tablelookupbyrow(localvarstring("ui_challengeTierTable"),chIndex,1)=="tier_prestige")&&!isitemunlocked("tier_prestige"))) \
		}