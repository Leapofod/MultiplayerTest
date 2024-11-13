#include "gameutils.h"

#include "raylib.h"

void DrawTextCentered(const char *text, int posX, int posY, int fontSize, Color color)
{
    int tw = MeasureText(text, fontSize);
    DrawText(text, posX - tw / 2, posY, fontSize, color);
}
