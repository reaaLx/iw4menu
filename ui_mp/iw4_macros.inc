			#define LOCAL_CLOSE_ALL \
					close "pc_options_actions"; \
					close "pc_options_advanced_video"; \
					close "pc_options_audio"; \
					close "pc_options_controls"; \
					close "pc_options_look"; \
					close "pc_options_movement"; \
					close "pc_options_video"; \
					close "pc_options_voice"; \
					close "options_graphics"; \
					close "options_graphics_texture"; \
					close "options_graphics_defaults"; \
					close "options_control_defaults"; \
					close "options_voice"; \
					close "options_multi"; \
					close "controls_multi"; \
					close "main_options"; \
					close "main_controls";

		#define MENU_OPTION_IS_OPEN \
				if(!menuisopen("pc_options_advanced_video")&&!menuisopen("pc_options_video")&&!menuisopen("pc_options_Audio")&&!menuisopen("pc_options_controls")&&!menuisopen("pc_options_voice")) \
				{ \
					if(localvarbool("ui_showApply")||localvarbool("ui_showAudioApply")) \
					{ \
						open "all_restart_popmenu"; \
					} \
				}
		
		#define DO_THE_SERVER_EXEC \
				exec "xrequirelivesignin"; \
				setdvar "systemlink" 0; \
				setdvar "splitscreen" 0; \
				setdvar "onlinegame" 1; \
				exec "exec default_xboxlive.cfg"; \
				exec "party_maxplayers 18"; \
				exec "xblive_privatematch 0"; \
				exec "xblive_rankedmatch 0"; \
				exec "xstartprivateparty"; \
				setdvar ui_mptype 0; \
				exec "xcheckezpatch"; \
				exec "exec default_xboxlive.cfg" \
				exec "exec xblive_rankedmatch 0"; \
				exec "ui_enumeratesaved"; \
				exec "xblive_privatematch 1"; \
				exec "xstartprivatematch"; \
				open "menu_xboxlive_privatelobby";
		
		#define SETUP_ACTION_START \
				exec "selectStringTableEntryInDvar mp/didyouknow.csv 0 didyouknow"; \
				exec "xpartygo";
			
		#define SETUP_LEAVE_CALL \
				if((dvarbool("onlinegame")&&!dvarbool("xblive_privatematch"))==0&&((dvarbool("sv_running"))==0)&&(inprivateparty()&&!privatepartyhost()&&privatepartyhostinlobby())) \
				{ \
					open "popup_leavegameandparty"; \
				} \
				if((dvarbool("onlinegame")&&!dvarbool("xblive_privatematch"))==0&&((dvarbool("sv_running"))==0)&&(!inprivateparty()||privatepartyhost()||!privatepartyhostinlobby())) \
				{ \
					open "popup_leavegame"; \
				} \
				if((dvarbool("onlinegame")&&!dvarbool("xblive_privatematch"))&&(dvarbool("sv_running"))) \
				{ \
					open "popup_endgame_ranked"; \
				} \
				if((dvarbool("onlinegame")&&!dvarbool("xblive_privatematch"))&&(dvarbool("sv_running"))==0&&(inprivateparty()&&!privatepartyhost()&&privatepartyhostinlobby())) \
				{ \
					open "popup_leavegameandparty_ranked"; \
				} \
				if((dvarbool("onlinegame")&&!dvarbool("xblive_privatematch"))&&(dvarbool("sv_running"))==0&&(!inprivateparty()||privatepartyhost()||!privatepartyhostinlobby())) \
				{ \
					open "popup_leavegame_ranked"; \
				} \
/*
		#define SETUP_CAC_FOCUS_UNLOCK \
				if(isitemunlocked("cac")) \
				{ \
					setLocalVarString "ui_hint_text" ( "@MPUI_DESC_CREATE_A_CLASS" ); \
				} \
				else \
				{ \
					if(tablelookup("mp/unlockTable.csv",0,"cac",2)==9999) \
					{ \
						setLocalVarString "ui_hint_text" ( "@PERKS_UNLOCKED_AT_NONE" ); \
					} \
					else \
					{ \
						if(tablelookup("mp/unlockTable.csv",0,"cac",3)!="") \
						{ \
							setLocalVarString "ui_hint_text" ( "@PERKS_UNLOCKED_BY_CHALLENGE" ); \
						} \
						else \
						{ \
							setLocalVarString "ui_hint_text" ("@"+tablelookup("mp/rankTable.csv",0,tablelookup("mp/unlockTable.csv",0,"cac",2),17)); \
						} \
					} \
				}
*/
		#define SETUP_ACTION_BACK \
				exec "xstopparty"; \
				if(inprivateparty()&&!privatepartyhost()&&privatepartyhostinlobby()) \
				{ \
					exec "xstopprivateparty"; \
					exec "xstartprivateparty"; \
				} \
				setdvar xblive_privatematch 0; \
				close self;

		// this works pretty well here ;)
		#define SETUP_SETTING_HARDCORE \
				if(dvarInt("g_hardcore")!=0) \
				{ \
					exec "exec hardcore_settings.cfg"; \
				} \
				if(dvarInt("g_hardcore")!=1) \
				{ \
					exec "exec hardcore_disable.cfg"; \
				}

#define PRESTIGE_VIS when(!(getplayerdata("prestige")==int(tablelookup("mp/rankIconTable.csv",0,"maxprestige",1)))
#define PRESTIGE_DIS when(!(getplayerdata("prestige")<int(tablelookup("mp/rankIconTable.csv",0,"maxprestige",1))&&getplayerdata("experience")>=int(tablelookup("mp/rankTable.csv",0,int(tablelookup("mp/rankTable.csv",0,"maxrank",1)),7)))&&!(getplayerdata("prestige")==int(tablelookup("mp/rankIconTable.csv",0,"maxprestige",1))))
			
#define CLEAR_UI_HINT exec "set ui_hint_text @NULL_EMPTY";

#define NEWUNLOCKS when(((getplayerdataanybooltrue("weaponNew")||getplayerdataanybooltrue("camoNew")||getplayerdataanybooltrue("attachmentNew"))||getplayerdataanybooltrue("perkNew")||((getplayerdata("perkNew","frag_grenade_mp")||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,"frag_grenade_mp",8)))||(getplayerdata("perkNew","semtex_mp")||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,"semtex_mp",8)))||(getplayerdata("perkNew","c4_mp")||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,"c4_mp",8)))||(getplayerdata("perkNew","claymore_mp")||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,"claymore_mp",8)))||(getplayerdata("perkNew","throwingknife_mp")||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,"throwingknife_mp",8)))||(getplayerdata("perkNew","specialty_tacticalinsertion")||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,"specialty_tacticalinsertion",8)))||(getplayerdata("perkNew","specialty_blastshield")||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,"specialty_blastshield",8)))||weaponclassnew("weapon_grenade")||weaponclassnew("weapon_equipment"))||getplayerdata("featureNew","cac")))
#define NEWUNLOCKS_PLAYERCARD when((getplayerdata("featureNew","cas")||getplayerdata("featureNew","token_1")||getplayerdata("featureNew","token_2")||getplayerdata("featureNew","token_3")||getplayerdata("featureNew","token_4")||getplayerdata("featureNew","token_5")||getplayerdata("featureNew","token_6")||getplayerdata("featureNew","token_7")||getplayerdata("featureNew","token_8")||getplayerdata("featureNew","token_9")||getplayerdata("featureNew","token_10")||getplayerdata("featureNew","token_11")||getplayerdata("featureNew","token_12"))||getplayerdata("featureNew","clantag")||(getplayerdataanybooltrue("iconNew")||getplayerdata("featureNew","playercard_icon"))||(getplayerdataanybooltrue("titleNew")||getplayerdata("featureNew","playercard_title")))
#define NEWUNLOCKS_CHALLENGES when(((getplayerdataanybooltrue("challengeTierNew")||getplayerdata("featureNew","challenges"))||getplayerdata("featureNew","challenges")||((getplayerdata("prestige")<int(tablelookup("mp/rankIconTable.csv",0,"maxprestige",1))&&getplayerdata("experience")>=int(tablelookup("mp/rankTable.csv",0,int(tablelookup("mp/rankTable.csv",0,"maxrank",1)),7)))&&getplayerdata("featureNew","prestige"))))

#define MAY_CHOOSE_CLASS (dvarInt("scr_oldschool")!=1)

#define TEAM_IS_SPECTATOR (localVarString("ui_team")=="spectator"))

#define TEAM_IS_AXIS ((localvarstring("ui_team")=="opfor"))
#define TEAM_IS_ALLIES ((localvarstring("ui_team")=="marines"))
#define TEAM_IS_AXIS_ALLIES (!(localvarstring("ui_team")=="marines")||(localvarstring("ui_team")=="opfor"))||!(1)))

#define TEAM_IS_NONE (localVarString("ui_team")==""))

#define ALLIES_DISABLED (localVarString("ui_team")=="marines")||(localVarString("ui_team")=="opfor"))||!(1))

// string list defined for buttons.
// 12/14 languages listed

// graphic settings stuff
#define ASPECT_RATIO_STRLIST { "@MENU_AUTO" 0 "@MENU_STANDARD_4_3" 1 "@MENU_WIDE_16_10" 2 "@MENU_WIDE_16_9" 3 }
#define AA_STRLIST { "@MENU_OFF" 1 "@MENU_2X" 2 "@MENU_4X" 4 }
#define DLIGHT_STRLIST { "@MENU_OFF" 0 "@MENU_LOW" 2 "@MENU_NORMAL" "4" }
#define ZFEATHER_STRLIST { "@MENU_NO" 0 "@MENU_YES" 1 }
#define MDL_DETAIL_STRLIST { "@MENU_NORMAL" 1 "@MENU_LOW" 2 }
#define WTR_DETAIL_STRLIST { "@MENU_NORMAL" 1 "@MENU_LOW" 0 }

// graphic textures stuff
#define TEXTURE_MM_STRLIST { "@MENU_AUTOMATIC" Unchanged "@MENU_BILINEAR" Force Bilinear "@MENU_TRILINEAR" Force Trilinear }
#define TEXTURE_QUALITY_STRLIST { "@MENU_AUTOMATIC" 0 "@MENU_MANUAL" 1 }
#define TEXTURE_RESOLUTION_STRLIST { "@MENU_LOW" 3 "@MENU_NORMAL" 2 "@MENU_HIGH" 1 "@MENU_EXTRA" 0 }

// sound stuff
#define SOUND_EQ_STRLIST { "@MENU_OFF" 0 "@MENU_ON" 1 }
#define SOUND_QUALITY_STRLIST { "@MENU_11KHZ" 11 "@MENU_22KHZ" 22 "@MENU_44KHZ" 44 }
#define SOUND_CONFIG_STRLIST { "@MENU_WINDOWS_DEFAULT"; "Windows Default"; "@MENU_MONO"; "Mono"; "@MENU_STEREO"; "Stereo"; "@MENU_FOUR_SPEAKERS"; "4 Speakers"; "@MENU_FIVE_ONE_SPEAKERS"; "5.1 Speakers"; }

// game options stuff
#define ENABLE_CONSOLE_STRLIST { "@MENU_YES" 0 "@MENU_NO" 1 }
#define LANG_STRLIST { "@MENU_ENGLISH" 0 "@MENU_FRENCH" 1 "@MENU_GERMAN" 2 "@MENU_ITALIAN" 3 "@MENU_SPANISH" 4 "@MENU_BRITISH" 5 "@MENU_RUSSIAN" 6 "@MENU_POLISH" 7 "@MENU_KOREAN" 8 "@MENU_TAIWANESE" 9 "@MENU_JAPANESE" 10 "@MENU_CHINESE" 11 "@MENU_THAI" 12 }

// Voice
#define VOICE_STRLIST { "@MENU_NO" 1 "@MENU_YES" 0 }
			