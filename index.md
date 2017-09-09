
{
	menuDef
	{
		name [string]
		rect [float] [float] [float] [float] [int] [int]
		exp rect x ( [script expressions] )
		exp rect y ( [script expressions] )
		exp rect w ( [script expressions] )
		exp rect h ( [script expressions] )
		fullscreen [int]
		style [int]
		border [int]
		borderSize [float]
		focusColor [float] [float] [float] [float]
		foreColor [float] [float] [float] [float]
		backColor [float] [float] [float] [float]
		borderColor [float] [float] [float] [float]
		disableColor [float] [float] [float] [float]
		background [string]
		type [int]
		textScale [float]
		fadeClamp [float]
		fadeAmount [float]
		fadeCycle [float]
		blurWorld [int]
		soundLoop [string]
		visible [int]
		visible if ( [script expressions] )
		visible when ( [script expressions] )
		disabled [int]
		disabled if ( [script expressions] )
		disabled when ( [script expressions] )
		allowedBinding [string]
		// flag > clicking outside the menu rectangle area causes the menu to close.
		outOfBoundsClick
		// flag > Causes the menu to be drawn overtop of the calling menu. 
		// Only items in this menu can gain the focus, even though items in the underlying menu can be seen.
		popup
		execKey [int][string]
		{
			[script]
		}
		onOpen 
		{ 
			[script]
		}
		onClose 
		{ 
			[script]
		}
		onRequestClose
		{
			[script]
		}
		onESC
		{
			[script]
		}

		itemDef
		{
			rect [float] [float] [float] [float] [int] [int] 
			exp rect x ( [script expressions] )
			exp rect y ( [script expressions] )
			exp rect w ( [script expressions] )
			exp rect h ( [script expressions] )
			// flag > Presence of this keyword declares whether this item is a decoration item or not. 
			// Non-decoration items would be hotspots, buttons, sliders, etc. 
			// items that cause actions to happen. Decoration items would be menu border graphics, logos, animation boxes, etc.
			// anything without this keyword will make mouseover sound and other assorted things.
			decoration
			background [string]
			group [string]
			style [int]
			type [int]
			textFont [int]
			textAlign [int]
			textAlignX [int]
			textAlignY [int]
			textStyle [int]
			textScale [int]
			disableColor [float] [float] [float] [float]
			foreColor [float] [float] [float] [float]
			exp foreColor r ( [script expressions] )
			exp foreColor g ( [script expressions] )
			exp foreColor b ( [script expressions] )
			exp foreColor a ( [script expressions] )
			backColor [float] [float] [float] [float]
			exp backColor r ( [script expressions] )
			exp backColor g ( [script expressions] )
			exp backColor b ( [script expressions] )
			exp backColor a ( [script expressions] )
			glowColor [float] [float] [float] [float]
			exp glowColor r ( [script expressions] )
			exp glowColor g ( [script expressions] )
			exp glowColor b ( [script expressions] )
			exp glowColor a ( [script expressions] )
			disabled [int]
			disabled when ( [script expressions] )
			disabled if ( [script expressions] )
			visible [int]
			visible when ( [script expressions] )
			visible if ( [script expressions] )
			exp text ( [script expressions] ) 
			exp material ( [[script expressions] or "string" ) 

		}
	}	
}
