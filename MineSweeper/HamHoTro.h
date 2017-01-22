#ifndef _HAMHOTRO_H
#define _HAMHOTRO_H
#include <Windows.h>
void gotoxy(short x, short y);
void SetBGColor(WORD color);
void SetColor(WORD color);
void clrscr();
void resizeConsole(int width, int height);
#endif