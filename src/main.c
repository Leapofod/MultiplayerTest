#include "network.h"
#include "raylib.h"
#include "screens.h"

/* Global Variables */
GameMenu nextMenu       = MENU_MAIN;
int      winShouldClose = 0;

/* Local Variables */
static GameMenu currMenu = MENU_NONE;

static void UpdateCurrentMenu();
static void DrawCurrentMenu();
static void SwitchNextMenu();

int main()
{
    InitNetwork();
    InitWindow(800, 450, "Multiplayer Test");
    SetExitKey(KEY_NULL);

    while (!winShouldClose)
    {
        if (currMenu != nextMenu)
            SwitchNextMenu();

        UpdateCurrentMenu();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCurrentMenu();
        EndDrawing();

        winShouldClose |= WindowShouldClose();
    }

    CloseWindow();
    CloseNetwork();
}

static void UpdateCurrentMenu()
{
    switch (nextMenu)
    {
        case MENU_NONE:
            MenuNoneUpdate();
            break;
        case MENU_MAIN:
            MenuMainUpdate();
            break;
        case MENU_JOIN:
            MenuJoinUpdate();
            break;
        case MENU_HOST:
            MenuHostUpdate();
            break;
    }
}

static void DrawCurrentMenu()
{
    switch (nextMenu)
    {
        case MENU_NONE:
            MenuNoneDraw();
            break;
        case MENU_MAIN:
            MenuMainDraw();
            break;
        case MENU_JOIN:
            MenuJoinDraw();
            break;
        case MENU_HOST:
            MenuHostDraw();
            break;
    }
}

static void SwitchNextMenu()
{
    // Something something unload current things
    currMenu = nextMenu;
}
