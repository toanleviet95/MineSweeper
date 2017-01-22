#ifndef _XULY_H
#define _XULY_H
#define max 200
void PhatSinhMin(int a[][max], int dong, int cot, int min, bool b[][max]);
void TaoBaiMin(int a[][max], int dong, int cot);
void VeBanCo(int dong, int cot);
int Keyboard(int a[][max], bool b[][max], int dong, int cot, int min, float time, int &i, int &j);
void MoOso(int a[][max], int i, int j, bool b[][max]);
void MoOkhong(int a[][max], int i, int j, int dong, int cot, bool b[][max]);
void XuatMin(int a[][max], int dong, int cot);
void XuLyXungQuanh(int a[][max], int i, int j, int dong, int cot, bool b[][max]);
int ChuaMo(bool b[][max], int dong, int cot);
void coin();
void GAMEOVER();
void WIN();
void BangTen(float time, FILE *&f1, FILE *&f2);
#endif