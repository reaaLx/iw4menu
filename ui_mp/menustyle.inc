#undef CHOICE_X_START
#define CHOICE_X_START -64

#undef CHOICE_Y_START
#define CHOICE_Y_START 28

#define MENU_BACKGROUND_FRAME_DROP_SHADOW(posX, posY, width, height, imageArg) \
		itemDef \
		{ \
			rect posX posY width height 4 1 \
			style 3 \
			foreColor 0 0 0 1 \
			background imageArg \
			textScale 0.55 \
			decoration \
			visible 1 \
		}
