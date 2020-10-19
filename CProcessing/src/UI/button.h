#ifndef _BUTTON_H_
#define _BUTTON_H_		//@todo What is this

typedef struct
{
	
	const char*		name,
					text;

		float		x,
					y,
					width,
					height;

		CP_Color	colorFont,
					colorDefault,
					colorHover;

		void		(*onClick)(void);	//Function Pointer
		
#if 0
	CP_Image	imageUp,
				imageDown;
#endif

}Button;

Button CreateButton(float x, float y, float width, float height); //QUESTIONABLE
#if 0
Button CreateButtonImage(float x, float y, float width, float height, CP_Image buttonUp);
Button CreateButtonImage2(float x, float y, float width, float height, CP_Image buttonUp, CP_Image buttonDown);
Button ButtonUpdate(Button button);
#endif

#endif