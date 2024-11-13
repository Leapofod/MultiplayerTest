#include "raylib.h"
#include "screens.h"

static struct
{
    const char*     text;
    const Rectangle bounds;
} buttons[] = {
    {.text   = "JOIN",
     .bounds = (Rectangle){350, 140, 100, 40}},
    {.text   = "HOST",
     .bounds = (Rectangle){350, 210, 100, 40}},
    {.text   = "EXIT",
     .bounds = (Rectangle){350, 280, 100, 40}}};

static int buttonsCount        = 3;
static int selectedButtonOld   = -1;
static int selectedButton      = -1;
static int selectedButtonPress = 0;

static Color buttonNormalBg     = {204, 219, 238, 255};
static Color buttonSelectBg     = {229, 237, 248, 255};
static Color buttonPressdBg     = {178, 199, 226, 255};
static Color buttonNormalBorder = {45, 98, 161, 255};
static Color buttonSelectBorder = {84, 141, 212, 255};
static Color buttonPressdBorder = {32, 84, 147, 255};

void MenuMainUpdate()
{
    selectedButtonOld   = selectedButton;
    selectedButton      = -1;
    selectedButtonPress = 0;

    for (int i = 0; i < buttonsCount; ++i)
    {
        if (CheckCollisionPointRec(GetMousePosition(), buttons[i].bounds))
        {
            selectedButton = i;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                selectedButtonPress = 1;
            break;
        }
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && selectedButton == selectedButtonOld)
    {
        switch (selectedButton)
        {
            case 0:
                nextMenu = MENU_JOIN;
                break;
            case 1:
                nextMenu = MENU_HOST;
                break;
            case 2:
                winShouldClose = 1;
                break;
            default: break;
        }
    }
}

void MenuMainDraw()
{
    for (int i = 0; i < buttonsCount; ++i)
    {
        const int fontSize = 20;

        int px = buttons[i].bounds.x;
        int py = buttons[i].bounds.y;
        int wi = buttons[i].bounds.width;
        int he = buttons[i].bounds.height;
        int tw = MeasureText(buttons[i].text, fontSize);

        DrawRectangleRec(buttons[i].bounds,
                         selectedButton == i ? selectedButtonPress ? buttonPressdBg : buttonSelectBg
                                             : buttonNormalBg);
        DrawRectangleLinesEx(buttons[i].bounds, 2,
                             selectedButton == i ? selectedButtonPress ? buttonPressdBorder : buttonSelectBorder
                                                 : buttonNormalBorder);
        DrawText(buttons[i].text,
                 px + (wi / 2) - (tw / 2),
                 py + (he / 2) - (fontSize / 2),
                 fontSize, DARKBLUE);
    }
}
