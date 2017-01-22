#include <iostream>
#include <conio.h>
#include "HamHoTro.h"
#pragma comment(lib,"Winmm.lib")
using namespace std;

void NhacWIN() // Nhạc WIN
{
	PlaySound(TEXT("win.wav"), NULL, SND_FILENAME);
}

void NhacGAMEOVER() // Nhạc GAMEOVER
{
	PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME);
}

void explosion() // Tiếng mìn nổ
{
	PlaySound(TEXT("explosion.wav"), NULL, SND_FILENAME);
}

void coin() // Tiếng mở trúng ô không mìn
{
	PlaySound(TEXT("coin.wav"), NULL, SND_FILENAME);
}

void ChuWIN() // Vẽ chữ YOU WIN bằng ASCII
{
	printf("\n\n\n\n\n\n\n\n");
	printf("                         W W W   W W W     W W W     W W W   W W W\n");
	printf("                           W       W     W       W     W       W\n");
	printf("                             W   W       W       W     W       W\n");
	printf("                               W         W       W     W       W\n");
	printf("                               W         W       W     W       W\n");
	printf("                               W         W       W     W       W\n");
	printf("                             W W W         W W W         W W W\n");
	printf("\n\n\n");
	printf("                         W W W   W W W   W W W W W   W W W   W W W\n");
	printf("                           W       W         W         W W     W\n");
	printf("                           W   W   W         W         W W     W\n");
	printf("                           W   W   W         W         W   W   W\n");
	printf("                           W   W   W         W         W   W   W\n");
	printf("                           W   W   W         W         W     W W\n");
	printf("                             W   W       W W W W W   W W W   W W");
}

void ChuGAMEOVER() // Vẽ chữ GAME OVER bằng ASCII
{
	printf("\n\n\n\n\n\n\n\n");
	printf("                    G G G G        G G       G G G    G G G   G G G G G\n");
	printf("                   G       G         G          G G   G G       G\n");
	printf("                   G               G   G        G G   G G       G\n");
	printf("                   G               G   G        G   G   G       G G G\n");
	printf("                   G     G G G     G G G        G       G       G\n");
	printf("                   G       G     G       G      G       G       G\n");
	printf("                     G G G     G G G   G G G  G G G   G G G   G G G G G\n");
	printf("\n\n\n");
	printf("                     G G G     G G G   G G G    G G G G G     G G G G\n");
	printf("                   G       G     G       G        G             G     G\n");
	printf("                   G       G     G       G        G             G     G\n");
	printf("                   G       G      G     G         G G G         G     G\n");
	printf("                   G       G       G   G          G             G G G\n");
	printf("                   G       G       G   G          G             G     G\n");
	printf("                     G G G          G G         G G G G G     G G G     G");
}

void GAMEOVER(){
	explosion();
	SetBGColor(0);
	SetColor(14);
	clrscr();
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { 92, 38 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	resizeConsole(800, 500);
	ChuGAMEOVER();
	NhacGAMEOVER();
}

void WIN(){
	SetBGColor(1);
	SetColor(14);
	clrscr();
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { 92, 38 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	resizeConsole(800, 500);
	ChuWIN();
	NhacWIN();
}



