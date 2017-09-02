
// definitions for primary / secondary challenges
#define primary_unlock when ( ( ( stat_p_masada || stat_p_m16 || stat_p_tavor || stat_p_fn2000 || stat_p_m4 )
#define primary_unlock_1 when ( ( ( stat_p_scar || stat_p_ak47 || stat_p_fal || stat_p_famas )
#define primary_unlock_2 when ( ( ( stat_p_mp5k || stat_p_uzi || stat_p_kriss || stat_p_ump45 || stat_p_p90 )
#define primary_unlock_3 when ( ( ( stat_p_m240 || stat_p_sa80 || stat_p_rpd || stat_p_aug )
#define primary_unlock_4 when ( ( ( stat_p_cheytac || stat_p_m21 || stat_p_barrett || stat_p_wa2000 )

#define secondary_unlock when ( ( ( stat_s_glock || stat_s_tmp || stat_s_beretta393 || stat_s_pp2000  )
#define secondary_unlock_1 when ( ( ( stat_s_striker || stat_s_aa12 || stat_s_ranger || stat_s_m1014 || stat_s_model1887 || stat_s_spas12 )
#define secondary_unlock_2 when ( ( ( stat_s_usp || stat_s_coltanaconda || stat_s_deserteagle || stat_s_beretta )
#define secondary_unlock_3 when ( ( ( stat_s_at4 || stat_s_rpg || stat_s_javelin || stat_s_stinger || stat_s_m79 )

// primary challenge stats

#define stat_p_masada 		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "masada" , 0 ) ) )
#define stat_p_m16 			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "m16" , 0 ) ) )
#define stat_p_tavor 		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "tavor" , 0 ) ) )
#define stat_p_fn2000 		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "fn2000" , 0 ) ) )
#define stat_p_m4   		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "m4" , 0 ) ) )
#define stat_p_scar 		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "scar" , 0 ) ) )
#define stat_p_ak47 		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "ak47" , 0 ) ) )
#define stat_p_fal			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "fal" , 0 ) ) )
#define stat_p_famas  		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "famas" , 0 ) ) ) )
#define stat_p_mp5k			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "mp5k" , 0 ) ) )
#define stat_p_uzi 			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "uzi" , 0 ) ) )
#define stat_p_kriss 		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "kriss" , 0 ) ) ) 
#define stat_p_ump45		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "ump45" , 0 ) ) )
#define stat_p_p90			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "p90" , 0 ) ) ) )
#define stat_p_m240			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "m240" , 0 ) ) )
#define stat_p_sa80			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "sa80" , 0 ) ) )
#define stat_p_rpd			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "rpd" , 0 ) ) )
#define stat_p_aug			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "aug" , 0 ) ) )
#define stat_p_mg4			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "mg4" , 0 ) ) ) )
#define stat_p_cheytac		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "cheytac" , 0 ) ) )
#define stat_p_m21			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "m21" , 0 ) ) )
#define stat_p_barrett		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "barrett" , 0 ) ) )
#define stat_p_wa2000		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "wa2000" , 0 ) ) )

// secondary challenge stats

#define stat_s_glock 		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "glock" , 0 ) ) )
#define stat_s_tmp			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "tmp" , 0 ) ) )
#define stat_s_beretta393	getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "beretta393" , 0 ) ) )
#define stat_s_pp2000		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "pp2000" , 0 ) ) )
#define stat_s_striker		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "striker" , 0 ) ) )
#define stat_s_aa12			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "aa12" , 0 ) ) )
#define stat_s_ranger		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "ranger" , 0 ) ) )
#define stat_s_m1014		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "m1014" , 0 ) ) )
#define stat_s_model1887	getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "model1887" , 0 ) ) )
#define stat_s_spas12		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "spas12" , 0 ) ) )
#define stat_s_usp			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "usp" , 0 ) ) )
#define stat_s_coltanaconda	getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "coltanaconda" , 0 ) ) )
#define stat_s_deserteagle	getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "deserteagle" , 0 ) ) )
#define stat_s_beretta		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "beretta" , 0 ) ) )
#define stat_s_at4			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "at4" , 0 ) ) )
#define stat_s_rpg			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "rpg" , 0 ) ) )
#define stat_s_javelin		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "javelin" , 0 ) ) )
#define stat_s_stinger		getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "stinger" , 0 ) ) )
#define stat_s_m79			getplayerdata( "challengeTierNew" , int( tablelookup( "mp/challengeTable.csv" , 6 , "m79" , 0 ) ) )

// playercard icon stats

// playercard emblem stats

/////////////////
// weapon info //
/////////////////

// assault
#define REF_M4              "m4"
#define REF_FAMAS           "famas"
#define REF_SCAR            "scar"
#define REF_TAVOR           "tavor"
#define REF_FAL             "fal"
#define REF_M16             "m16"
#define REF_MASADA          "masada"
#define REF_FN2000          "fn2000"
#define REF_AK47            "ak47"

#define WEAPON_M4           tablelookup( "mp/statsTable.csv" , 4 , REF_M4 , 3 )
#define WEAPON_FAMAS        tablelookup( "mp/statsTable.csv" , 4 , REF_FAMAS , 3 )
#define WEAPON_SCAR         tablelookup( "mp/statsTable.csv" , 4 , REF_SCAR , 3 )
#define WEAPON_TAVOR        tablelookup( "mp/statsTable.csv" , 4 , REF_TAVOR , 3 )
#define WEAPON_FAL          tablelookup( "mp/statsTable.csv" , 4 , REF_FAL , 3 )
#define WEAPON_M16          tablelookup( "mp/statsTable.csv" , 4 , REF_M16 , 3 )
#define WEAPON_MASADA       tablelookup( "mp/statsTable.csv" , 4 , REF_MASADA , 3 )
#define WEAPON_FN2000       tablelookup( "mp/statsTable.csv" , 4 , REF_FN2000 , 3 )
#define WEAPON_AK47         tablelookup( "mp/statsTable.csv" , 4 , REF_AK47 , 3 )

// smg
#define REF_MP5K            "mp5k"
#define REF_UMP45           "ump45"
#define REF_KRISS           "kriss"
#define REF_P90             "p90"
#define REF_TAVOR           "uzi"

#define WEAPON_MP5K         tablelookup( "mp/statsTable.csv" , 4 , REF_MP5K , 3 )
#define WEAPON_UMP45        tablelookup( "mp/statsTable.csv" , 4 , REF_UMP45 , 3 )
#define WEAPON_KRISS        tablelookup( "mp/statsTable.csv" , 4 , REF_KRISS , 3 )
#define WEAPON_P90          tablelookup( "mp/statsTable.csv" , 4 , REF_P90 , 3 )
#define WEAPON_TAVOR        tablelookup( "mp/statsTable.csv" , 4 , REF_TAVOR , 3 )

// lmg

#define REF_SA80            "sa80"
#define REF_RPD             "rpd"
#define REF_MG4             "mg4"
#define REF_AUG             "aug"
#define REF_M240            "m240"

#define WEAPON_SA80         tablelookup( "mp/statsTable.csv" , 4 , REF_SA80 , 3 )
#define WEAPON_RPD          tablelookup( "mp/statsTable.csv" , 4 , REF_RPD , 3 )
#define WEAPON_MG4          tablelookup( "mp/statsTable.csv" , 4 , REF_MG4 , 3 )
#define WEAPON_AUG          tablelookup( "mp/statsTable.csv" , 4 , REF_AUG , 3 )
#define WEAPON_M240         tablelookup( "mp/statsTable.csv" , 4 , REF_M240 , 3 )

// sniper

#define REF_CHEYTAC         "cheytac"
#define REF_BARRETT         "barrett"
#define REF_WA2000          "wa2000"
#define REF_M21             "m21"

#define WEAPON_CHEYTAC      tablelookup( "mp/statsTable.csv" , 4 , WEAPON_CHEYTAC , 3 )
#define WEAPON_BARRETT      tablelookup( "mp/statsTable.csv" , 4 , WEAPON_BARRETT , 3 )
#define WEAPON_WA2000       tablelookup( "mp/statsTable.csv" , 4 , WEAPON_WA2000 , 3 )
#define WEAPON_M21          tablelookup( "mp/statsTable.csv" , 4 , WEAPON_M21 , 3 )

// machine pistol

#define REF_PP2000          "pp2000"
#define REF_GLOCK           "glock"
#define REF_BARETTA393      "baretta393"
#define REF_TMP             "tmp"

#define WEAPON_PP2000       tablelookup( "mp/statsTable.csv" , 4 , REF_PP2000 , 3 )
#define WEAPON_GLOCK        tablelookup( "mp/statsTable.csv" , 4 , REF_GLOCK , 3 )
#define WEAPON_BARETTA393   tablelookup( "mp/statsTable.csv" , 4 , REF_BARETTA393 , 3 )
#define WEAPON_TMP          tablelookup( "mp/statsTable.csv" , 4 , REF_TMP , 3 )

// shotgun

#define REF_SPAS12          "spas12"
#define REF_AA12            "aa12"
#define REF_STRIKER         "striker"
#define REF_RANGER          "ranger"
#define REF_M1014           "m1014"
#define REF_MODEL1887       "model1887"

#define WEAPON_SPAS12       tablelookup( "mp/statsTable.csv" , 4 , REF_SPAS12 , 3 )
#define WEAPON_AA12         tablelookup( "mp/statsTable.csv" , 4 , REF_AA12 , 3 )
#define WEAPON_STRIKER      tablelookup( "mp/statsTable.csv" , 4 , REF_STRIKER , 3 )
#define WEAPON_RANGER       tablelookup( "mp/statsTable.csv" , 4 , REF_RANGER , 3 )
#define WEAPON_M1014        tablelookup( "mp/statsTable.csv" , 4 , REF_M1014 , 3 )
#define WEAPON_MODEL1887    tablelookup( "mp/statsTable.csv" , 4 , REF_MODEL1887 , 3 )

// pistol

#define REF_USP             "usp"
#define REF_COLTANACONDA    "coltanaconda"
#define REF_BERETTA         "beretta"
#define REF_DESERTEAGLE     "deserteagle"

#define WEAPON_USP          tablelookup( "mp/statsTable.csv" , 4 , REF_USP , 3 )
#define WEAPON_COLTANACONDA tablelookup( "mp/statsTable.csv" , 4 , REF_COLTANACONDA , 3 )
#define WEAPON_BARETTA      tablelookup( "mp/statsTable.csv" , 4 , REF_BARETTA , 3 )
#define WEAPON_DESERTEAGLE  tablelookup( "mp/statsTable.csv" , 4 , REF_DESERTEAGLE , 3 )

// rocket launchers

#define REF_AT4             "at4"
#define REF_M79             "m79"
#define REF_STINGER         "stinger"
#define REF_JAVELIN         "javelin"
#define REF_RPG             "rpg"

#define WEAPON_AT4          tablelookup( "mp/statsTable.csv" , 4 , REF_AT4 , 3 )
#define WEAPON_M79          tablelookup( "mp/statsTable.csv" , 4 , REF_M79 , 3 )
#define WEAPON_STINGER      tablelookup( "mp/statsTable.csv" , 4 , REF_STINGER , 3 )
#define WEAPON_JAVELIN      tablelookup( "mp/statsTable.csv" , 4 , REF_JAVELIN , 3 )
#define WEAPON_RPG          tablelookup( "mp/statsTable.csv" , 4 , REF_RPG , 3 )

// extra grenades

#define REF_FLASH			"flash_grenade"
#define REF_CONCUSSION		"concussion_grenade"
#define REF_SMOKE			"smoke_grenade"

#define STAT_FLASH          tablelookup( "mp/statstable.csv", 4, REF_FLASH, 3 )
#define STAT_CONCUSSION     tablelookup( "mp/statstable.csv", 4, REF_CONCUSSION, 3 )
#define STAT_SMOKE          tablelookup( "mp/statstable.csv", 4, REF_SMOKE, 3 )
