//rect -427 -102 854 204 2 2
//rect xxxx	yyyy www hhh HORIZONTAL_ALIGN VERTICAL_ALIGN

// these applies to the popmenu base
// do not touch the "white" & "xpbar_stencilbase" itemdefs

#ifndef CHOICE_X_START
#define CHOICE_X_START 				-150
#endif

#ifndef CHOICE_Y_START
#define CHOICE_Y_START 				-100
#endif

#ifndef CHOICE_X_SIZE
#define CHOICE_X_SIZE 				300
#endif

#ifndef CHOICE_Y_SIZE
#define CHOICE_Y_SIZE				84
#endif

#ifndef HIGHLIGHT_SHADER 
#define HIGHLIGHT_SHADER 			"popup_button_selection_bar"
#endif

// these apply to the choice_button

#ifndef CHOICE_TEXTALIGN 
#define CHOICE_TEXTALIGN 			ITEM_ALIGN_TOP_RIGHT
#endif

#ifndef CHOICE_TEXTALIGN_X 
#define CHOICE_TEXTALIGN_X 			-24
#endif

#ifndef CHOICE_BUTTON_Y_START
#define	CHOICE_BUTTON_Y_START 		-40
#endif

#ifndef CHOICE_HORIZONTAL_ALIGN
#define CHOICE_HORIZONTAL_ALIGN		HORIZONTAL_ALIGN_CENTER
#endif

#ifndef CHOICE_VERTICAL_ALIGN
#define CHOICE_VERTICAL_ALIGN		VERTICAL_ALIGN_CENTER
#endif

// these apply to the choice_subtitle

#ifndef CHOICE_POPUP_SUBTITLE_TEXTALIGN
#define CHOICE_POPUP_SUBTITLE_TEXTALIGN ITEM_ALIGN_TOP_CENTER
#endif

#define CHOICE_POPMENU_CENTER( itemNum ) \
		itemDef \
		{ \
			rect CHOICE_X_START CHOICE_Y_START CHOICE_X_SIZE CHOICE_Y_SIZE CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			backcolor 0.5 0.5 0.5 1 \
			background "white" \
			textscale 0.55 \
			exp rect h( 24 + itemNum * 20 ) \
		} \
		itemDef \
		{ \
			rect CHOICE_X_START CHOICE_Y_START 1708 480 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 0.75 \
			background "mw2_popup_bg_fogstencil" \
			textscale 0.55 \
			exp rect x ( 0 - ( ( float( milliseconds() % 60000 ) / 60000 ) * ( 854 ) ) ) \
		} \
		itemDef \
		{ \
			rect CHOICE_X_START CHOICE_Y_START -1708 -480 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.85 0.85 0.85 1 \
			background "mw2_popup_bg_fogscroll" \
			textscale 0.55 \
			exp rect x ( 0 - ( ( float( milliseconds() % 60000 ) / 60000 ) * ( 854 ) ) ) \
		} \
		itemDef \
		{ \
			rect CHOICE_X_START CHOICE_Y_START 300 0 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			background "mockup_popup_bg_stencilfill" \
			textscale 0.55 \
			exp rect h ( ( 24 + itemNum * 20 ) ) \
		} \
		itemDef \
		{ \
			rect CHOICE_X_START CHOICE_Y_START -1708 -480 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 0.75 \
			background "mw2_popup_bg_fogstencil" \
			textscale 0.55 \
			exp rect x ( ( - 854 ) + ( ( float( milliseconds() % 50000 ) / 50000 ) * ( 854 ) ) ) \
		} \
		itemDef \
		{ \
			rect CHOICE_X_START CHOICE_Y_START -1708 -480 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0.85 0.85 0.85 1 \
			background "mw2_popup_bg_fogscroll" \
			textscale 0.55 \
			exp rect x ( ( - 854 ) + ( ( float( milliseconds() % 50000 ) / 50000 ) * ( 854 ) ) ) \
		} \
		itemDef \
		{ \
			rect CHOICE_X_START CHOICE_Y_START 300 0 1 1 \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 0 \
			background "small_box_lightfx" \
			textscale 0.55 \
			exp rect h ( ( 24 + itemNum * 20 ) ) \
		}
#define CHOICE_POPMENU_TITLE( textArg ) \
		itemDef \
		{ \
			rect -150 -102 300 24 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 1 \
			forecolor 1 1 1 1 \
			background "gradient_fadein" \
			textfont 9 \
			textalign 5 \
			textscale 0.375 \
			text textArg \
		}
#define CHOICE_POPMENU_SUBTITLE( textArg ) \
		itemDef \
		{ \
			rect -146 -78 292 20 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			autowrapped \
			visible 1 \
			style 1 \
			forecolor 1 1 1 0.65 \
			textfont 3 \
			textalign CHOICE_POPUP_SUBTITLE_TEXTALIGN \
			textscale 0.375 \
			visible when ( 1 ) \
			exp text ( textArg ) \
		}		
#define CHOICE_BUTTON( itemNum, textArg, actionArg ) \
		itemDef \
		{ \
			rect -146 (CHOICE_BUTTON_Y_START + ( itemNum * 20 ) ) 292 20 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			visible 1 \
			style 1 \
			foreColor 1 1 1 1 \
			background HIGHLIGHT_SHADER \
			group "mw2_popup_button" \
			type 1 \
			textFont 3 \
			textAlign CHOICE_TEXTALIGN \
			textAlignX CHOICE_TEXTALIGN_X \
			textScale 0.375 \
			text textArg \
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
			action \
			{ \
				play "mouse_click"; \
				actionArg \
			} \
		}
/*
		itemDef \
		{ \
			rect -491 -166 64 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "drop_shadow_tl" \
			textscale 0.55 \
			visible when ( 1 ) \
			exp rect h ( ( 8 + itemNum * 20 ) ) \
		} \
		itemDef \
		{ \
			rect -491 -166 300 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "drop_shadow_t" \
			textscale 0.55 \
			visible when ( 1 ) \
			exp rect h ( ( 8 + itemNum * 20 ) ) \
		} \
		itemDef \
		{ \
			rect -491 -166 64 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "drop_shadow_tr" \
			textscale 0.55 \
			visible when ( 1 ) \
			exp rect h ( ( 8 + itemNum * 20 ) ) \
		} \
		itemDef \
		{ \
			rect 150 -84 64 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "drop_shadow_br" \
			textscale 0.55 \
			exp rect y ( ( CHOICE_Y_START - 0 ) + ( ( 24 + itemNum * 20 ) ) ) \
			visible when ( 1 ) \
		} \
		itemDef \
		{ \
			rect -150 -84 300 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "drop_shadow_b" \
			textscale 0.55 \
			exp rect y ( ( CHOICE_Y_START - 0 ) + ( ( 24 + itemNum * 20 ) ) ) \
			visible when ( 1 ) \
		} \
		itemDef \
		{ \
			rect -214 -84 64 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "drop_shadow_bl" \
			textscale 0.55 \
			exp rect y ( ( CHOICE_Y_START - 0 ) + ( ( 24 + itemNum * 20 ) ) ) \
			visible when ( 1 ) \
		} \
		itemDef \
		{ \
			rect -491 -102 64 204 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "drop_shadow_l" \
			textscale 0.55 \
			exp rect h ( ( 24 + itemNum * 20 ) ) \
			visible when ( 1 ) \
		} \
		itemDef \
		{ \
			rect 150 -84 64 0 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 0 0 0 1 \
			background "drop_shadow_r" \
			textscale 0.55 \
			exp rect h ( ( 8 + itemNum * 20 ) ) \
			visible when ( shadow_visArg ) \
		}
*/		