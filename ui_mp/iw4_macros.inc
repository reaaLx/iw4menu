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
				
		#define CHECK_FOR_UPDATE_ACTION \
			exec checkforupdate \
			open auconfirm

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
				open "createserver";
		
		#define SETUP_ACTION_START \
			exec selectStringTableEntryInDvar mp/didyouknow.csv 0 didyouknow; \
			exec xpartygo;
			
		#define SETUP_ACTION_STARTDEV \
			if (dvarstring(ui_mapname) == "mp_afghan") \
			{ \
				exec "devmap mp_afghan"; \
			} \
			if (dvarstring(ui_mapname) == "mp_boneyard") \
			{ \
				exec "devmap mp_boneyard"; \
			} \
			if (dvarstring(ui_mapname) == "mp_brecourt") \
			{ \
				exec "devmap mp_brecourt"; \
			} \
			if (dvarstring(ui_mapname) == "mp_checkpoint") \
			{ \
				exec "devmap mp_checkpoint"; \
			} \
			if (dvarstring(ui_mapname) == "mp_derail") \
			{ \
				exec "devmap mp_derail"; \
			} \
			if (dvarstring(ui_mapname) == "mp_estate") \
			{ \
				exec "devmap mp_estate"; \
			} \
			if (dvarstring(ui_mapname) == "mp_favela") \
			{ \
				exec "devmap mp_favela"; \
			} \
			if (dvarstring(ui_mapname) == "mp_highrise") \
			{ \
				exec "devmap mp_highrise"; \
			} \
			if (dvarstring(ui_mapname) == "mp_invasion") \
			{ \
				exec "devmap mp_invasion"; \
			} \
			if (dvarstring(ui_mapname) == "mp_nightshift") \
			{ \
				exec "devmap mp_nightshift"; \
			} \
			if (dvarstring(ui_mapname) == "mp_quarry") \
			{ \
				exec "devmap mp_quarry"; \
			} \
			if (dvarstring(ui_mapname) == "mp_rundown") \
			{ \
				exec "devmap mp_rundown"; \
			} \
			if (dvarstring(ui_mapname) == "mp_rust") \
			{ \
				exec "devmap mp_rust"; \
			} \
			if (dvarstring(ui_mapname) == "mp_subbase") \
			{ \
				exec "devmap mp_subbase"; \
			} \
			if (dvarstring(ui_mapname) == "mp_terminal") \
			{ \
				exec "devmap mp_terminal"; \
			} \
			if (dvarstring(ui_mapname) == "mp_underpass") \
			{ \
				exec "devmap mp_underpass"; \
			} \
			if (dvarstring(ui_mapname) == "af_caves") \
			{ \
				exec "devmap af_caves"; \
			} \
			if (dvarstring(ui_mapname) == "af_chase") \
			{ \
				exec "devmap af_chase"; \
			} \
			if (dvarstring(ui_mapname) == "airport") \
			{ \
				exec "devmap airport"; \
			} \
			if (dvarstring(ui_mapname) == "arcadia") \
			{ \
				exec "devmap arcadia"; \
			} \
			if (dvarstring(ui_mapname) == "boneyard") \
			{ \
				exec "devmap boneyard"; \
			} \
			if (dvarstring(ui_mapname) == "cliffhanger") \
			{ \
				exec "devmap cliffhanger"; \
			} \
			if (dvarstring(ui_mapname) == "co_hunted") \
			{ \
				exec "devmap co_hunted"; \
			} \
			if (dvarstring(ui_mapname) == "contingency") \
			{ \
				exec "devmap contingency"; \
			} \
			if (dvarstring(ui_mapname) == "dc_whitehouse") \
			{ \
				exec "devmap dc_whitehouse"; \
			} \
			if (dvarstring(ui_mapname) == "dcburning") \
			{ \
				exec "devmap dcburning"; \
			} \
			if (dvarstring(ui_mapname) == "dcemp") \
			{ \
				exec "devmap dcemp"; \
			} \
			if (dvarstring(ui_mapname) == "ending") \
			{ \
				exec "devmap ending"; \
			} \
			if (dvarstring(ui_mapname) == "estate") \
			{ \
				exec "devmap estate"; \
			} \
			if (dvarstring(ui_mapname) == "favela") \
			{ \
				exec "devmap favela"; \
			} \
			if (dvarstring(ui_mapname) == "favela_escape") \
			{ \
				exec "devmap favela_escape"; \
			} \
			if (dvarstring(ui_mapname) == "gulag") \
			{ \
				exec "devmap gulag"; \
			} \
			if (dvarstring(ui_mapname) == "invasion") \
			{ \
				exec "devmap invasion"; \
			} \
			if (dvarstring(ui_mapname) == "iw4_credits") \
			{ \
				exec "devmap iw4_credits"; \
			} \
			if (dvarstring(ui_mapname) == "oilrig") \
			{ \
				exec "devmap oilrig"; \
			} \
			if (dvarstring(ui_mapname) == "so_bridge") \
			{ \
				exec "devmap so_bridge"; \
			} \
			if (dvarstring(ui_mapname) == "so_ghillies") \
			{ \
				exec "devmap so_ghillies"; \
			} \
			if (dvarstring(ui_mapname) == "trainer") \
			{ \
				exec "devmap trainer"; \
			} \
			if (dvarstring(ui_mapname) == "mp_abandon") \
			{ \
				exec "devmap mp_abandon"; \
			} \
			if (dvarstring(ui_mapname) == "mp_bloc") \
			{ \
				exec "devmap mp_bloc"; \
			} \
			if (dvarstring(ui_mapname) == "mp_bog_sh") \
			{ \
				exec "devmap mp_bog_sh"; \
			} \
			if (dvarstring(ui_mapname) == "mp_cargoship") \
			{ \
				exec "devmap mp_cargoship"; \
			} \
			if (dvarstring(ui_mapname) == "mp_compact") \
			{ \
				exec "devmap mp_compact"; \
			} \
			if (dvarstring(ui_mapname) == "mp_complex") \
			{ \
				exec "devmap mp_complex"; \
			} \
			if (dvarstring(ui_mapname) == "mp_crash") \
			{ \
				exec "devmap mp_crash"; \
			} \
			if (dvarstring(ui_mapname) == "mp_cross_fire") \
			{ \
				exec "devmap mp_cross_fire"; \
			} \
			if (dvarstring(ui_mapname) == "mp_fuel2") \
			{ \
				exec "devmap mp_fuel2"; \
			} \
			if (dvarstring(ui_mapname) == "mp_killhouse") \
			{ \
				exec "devmap mp_killhouse"; \
			} \
			if (dvarstring(ui_mapname) == "mp_nuked") \
			{ \
				exec "devmap mp_nuked"; \
			} \
			if (dvarstring(ui_mapname) == "mp_overgrown") \
			{ \
				exec "devmap mp_overgrown"; \
			} \
			if (dvarstring(ui_mapname) == "mp_storm") \
			{ \
				exec "devmap mp_storm"; \
			} \
			if (dvarstring(ui_mapname) == "mp_strike") \
			{ \
				exec "devmap mp_strike"; \
			} \
			if (dvarstring(ui_mapname) == "mp_trailerpark") \
			{ \
				exec "devmap mp_trailerpark"; \
			} \
			if (dvarstring(ui_mapname) == "mp_vacant") \
			{ \
				exec "devmap mp_vacant"; \
			}
		
		#define SETUP_ACTION_RULES \
			if (dvarstring(ui_gametype) == "arena") \
			{ \
				open "settings_quick_arena"; \
			} \
			if (dvarstring(ui_gametype) == "war") \
			{ \
				open "settings_quick_war"; \
			} \
			if (dvarstring(ui_gametype) == "sd") \
			{ \
				open "settings_quick_sd"; \
			} \
			if (dvarstring(ui_gametype) == "sab") \
			{ \
				open "settings_quick_sab"; \
			} \
			if (dvarstring(ui_gametype) == "dm") \
			{ \
				open "settings_quick_dm"; \
			} \
			if (dvarstring(ui_gametype) == "dom") \
			{ \
				open "settings_quick_dom"; \
			} \
			if (dvarstring(ui_gametype) == "ctf") \
			{ \
				open "settings_quick_ctf"; \
			} \
			if (dvarstring(ui_gametype) == "koth") \
			{ \
				open "settings_quick_koth"; \
			} \
			if (dvarstring(ui_gametype) == "oneflag") \
			{ \
				open "settings_quick_oneflag"; \
			} \
			if (dvarstring(ui_gametype) == "dd") \
			{ \
				open "settings_quick_dd"; \
			} \
			if (dvarstring(ui_gametype) == "vip") \
			{ \
				open "settings_quick_vip"; \
			} \
			if (dvarstring(ui_gametype) == "gtnw") \
			{ \
				open "settings_quick_gtnw"; \
			}
			
		#define SETUP_ACTION_BACK \
			exec "xstopparty"; \
			if (inprivateparty() && !privatepartyhost() && privatepartyhostinlobby()) \
			{ \
				exec "xstopprivateparty"; \
				exec "xstartprivateparty"; \
			} \
			setdvar xblive_privatematch 0; \
			close self;