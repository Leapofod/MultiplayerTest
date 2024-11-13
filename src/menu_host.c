#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gameutils.h"
#include "raylib.h"
#include "screens.h"

static char      portBuffer[6];
static const int maxPortLen = 5;

void MenuHostDraw()
{
    DrawTextCentered("HOST A GAME", 400, 100, 30, BLACK);

    char buffer[32];
    sprintf(buffer, "PORT: %s", portBuffer);
    if (strlen(portBuffer) < maxPortLen)
        strcat(buffer, "|");

    DrawText(buffer, 300, 160, 20, BLACK);
    DrawLineEx((Vector2){300, 185}, (Vector2){500, 185}, 2, LIGHTGRAY);
}

void MenuHostUpdate()
{
    int key = GetCharPressed();
    while (strlen(portBuffer) < maxPortLen && key > 0)
    {
        if (isdigit(key) && ((char)key != '0' || strlen(portBuffer) > 0))
            portBuffer[strlen(portBuffer)] = (char)key;

        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE) && strlen(portBuffer) > 0)
        portBuffer[strlen(portBuffer) - 1] = '\0';

    else if (IsKeyPressed(KEY_ESCAPE))
    {
        nextMenu = MENU_MAIN;
        memset(portBuffer, 0, sizeof(portBuffer));
        return;
    }

    else if (IsKeyPressed(KEY_ENTER) && strlen(portBuffer) > 0)
    {
        // Host a game and join locally
        int port = atoi(portBuffer);
        nextMenu = MENU_NONE;
    }
}
