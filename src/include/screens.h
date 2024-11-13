#ifndef SCREENS_INCLUDE_H
#define SCREENS_INCLUDE_H

typedef enum
{
    MENU_NONE,
    MENU_MAIN,
    MENU_HOST,
    MENU_JOIN
} GameMenu;

void MenuMainUpdate();
void MenuMainDraw();

void MenuJoinUpdate();
void MenuJoinDraw();

void MenuHostUpdate();
void MenuHostDraw();

void MenuNoneUpdate();
void MenuNoneDraw();

extern int winShouldClose;
extern GameMenu nextMenu;

#endif
