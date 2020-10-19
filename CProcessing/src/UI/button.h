#ifndef _BUTTON_H_
#define _BUTTON_H_

typedef struct
{
	CP_Image	imageUp, 
				imageDown;

	const char* name,
				text;

		float	x,
				y,
				width,
				height;

			
	int buttonState;

}Button;

Button CreateButton(float x, float y, float width, float height);
Button CreateButtonImage(float x, float y, float width, float height, CP_Image buttonUp);
Button CreateButtonImage2(float x, float y, float width, float height, CP_Image buttonUp, CP_Image buttonDown);
Button ButtonUpdate(Button button);

#endif