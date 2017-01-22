#include <iostream>
#include "HamHoTro.h"
using namespace std;

char vuongTraiTren = 218;
char vuongTraiDuoi = 192;
char vuongPhaiTren = 191;
char vuongPhaiDuoi = 217;
char noiNgangTren = 194;
char noiNgangDuoi = 193;
char noiDocTrai = 195;
char noiDocPhai = 180;
char noiGiua = 197;
char ngang = 196;
char doc = 179;

void VeDongTren(int cot){
	cout << vuongTraiTren;
	for (int i = 1; i < cot; i++)
		cout << ngang << ngang << noiNgangTren;
	cout << ngang << ngang << vuongPhaiTren;
}

void VeDongGiua(int cot){
	cout << endl;
	cout << doc;
	for (int i = 0; i < cot; i++)
		cout << "  " << doc;
	cout << endl;
	cout << noiDocTrai;
	for (int i = 1; i < cot; i++)
		cout << ngang << ngang << noiGiua;
	cout << ngang << ngang << noiDocPhai;
}

void VeDongDuoi(int cot){
	cout << endl;
	cout << doc;
	for (int i = 0; i < cot; i++)
		cout << "  " << doc;
	cout << endl;
	cout << vuongTraiDuoi;
	for (int i = 1; i < cot; i++)
		cout << ngang << ngang << noiNgangDuoi;
	cout << ngang << ngang << vuongPhaiDuoi;
}

void VeBanCo(int dong, int cot){
	SetBGColor(1);
	clrscr();
	SetBGColor(7);
	SetColor(1);
	VeDongTren(cot);
	for (int i = 1; i < dong; i++)
		VeDongGiua(cot);
	VeDongDuoi(cot);
}


