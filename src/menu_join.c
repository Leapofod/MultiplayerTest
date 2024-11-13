#include "gameutils.h"
#include "raylib.h"
#include "screens.h"
#include "stdio.h"
#include "string.h"

static char addrBuffer[64];
static int  maxAddrLen = 63;

void MenuJoinDraw()
{
    DrawTextCentered("JOIN A GAME", 400, 100, 30, BLACK);

    char buffer[96];
    sprintf(buffer, "ADDRESS: %s", addrBuffer);
    if (strlen(addrBuffer) < maxAddrLen)
        strcat(buffer, "|");

    DrawText(buffer, 200, 160, 20, BLACK);
    DrawLineEx((Vector2){200, 185}, (Vector2){600, 185}, 2, LIGHTGRAY);
}

void MenuJoinUpdate() {}
