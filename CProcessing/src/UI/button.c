#include "cprocessing.h"
#include "Button.h"

/* WHY CANT I OVERLOAD FUNCTIONS */
Button CreateButton(float x, float y, float width, float height)
{
    Button newButton;

    newButton.buttonState = 0;
  
    newButton.x = x;
    newButton.y = y;

    newButton.width = width;
    newButton.height = height;

    return newButton;
}

Button CreateButtonImage(float x, float y, float width, float height, CP_Image buttonUp)
{
    Button newButton = CreateButton(x, y, width, height);

    newButton.imageUp = buttonUp;

    return newButton;
}

Button CreateButtonImage2(float x, float y, float width, float height, CP_Image buttonUp, CP_Image buttonDown)
{
    Button newButton = CreateButtonImage(x, y, width, height, buttonUp);
    newButton.imageDown = buttonDown;

    return newButton;
}

Button ButtonUpdate(Button button)
{



#if 0
    if (CP_Input_MouseClicked())
    {
        float mouseX = CP_Input_GetMouseX();
        float mouseY = CP_Input_GetMouseY();

        if (mouseX >= button.buttonLeft &&
            mouseX <= button.buttonRight &&
            mouseY >= button.buttonTop &&
            mouseY <= button.buttonBottom)
        {

            button.buttonState = !button.buttonState;
        }
    }
#endif
    //DrawCall
    //if (!button.buttonState) CP_Image_Draw(button.imageUp, button.buttonX, button.buttonY, button.buttonHalfSize * 2, button.buttonHalfSize * 2, 255);
    //else CP_Image_Draw(button.imageDown, button.buttonX - button.buttonHalfSize, button.buttonY - button.buttonHalfSize, button.buttonHalfSize * 2, button.buttonHalfSize * 2, 255);
    //CP_Graphics_DrawRect(button.buttonX - button.buttonHalfSize, button.buttonY - button.buttonHalfSize, button.buttonHalfSize * 2, button.buttonHalfSize * 2);

    return button;
}


