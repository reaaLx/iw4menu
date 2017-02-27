
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