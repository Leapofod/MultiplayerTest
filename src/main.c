#include <stdio.h>

#define ENET_IMPLEMENTATION
#include "enet.h"
#undef ENET_IMPLEMENTATION

#include "raylib.h"

int main()
{
    if (enet_initialize() < 0)
    {
        fprintf(stderr, "Error initializing enet");
        return 1;
    }

    InitWindow(600, 400, "Multiplayer Test");
    SetExitKey(KEY_NULL);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello!", 200, 150, 20, BLACK);
        EndDrawing();
    }
}
