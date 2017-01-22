#ifndef _CAPDO_H
#define _CAPDO_H
#include "Struct.h"
void De(Level &L);
void ChuThichDe(int min);
void PathDe(FILE *&f1, FILE *&f2);
void PathTimeDe(FILE *&f);
void TrungBinh(Level &L);
void ChuThichTrungBinh(int min);
void PathTB(FILE *&f1, FILE *&f2);
void PathTimeTB(FILE *&f);
void Kho(Level &L);
void ChuThichKho(int min);
void PathKho(FILE *&f1, FILE *&f2);
void PathTimeKho(FILE *&f);
#endif
