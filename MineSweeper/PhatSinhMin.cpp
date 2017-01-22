#include <stdlib.h>
#include <time.h>
#define max 200

// PHÁT SINH MÌN 
void PhatSinhMin(int a[][max], int dong, int cot, int min, bool b[][max])
{
	srand((unsigned)time(NULL));
	int i, j;
	for (i = 0; i < dong; i++)
	for (j = 0; j < cot; j++)
	{
		b[i][j] = false; 
		a[i][j] = 0; 
	}
	for (int l = 0; l < min; l++)
	{
		do{
			i = rand() % dong;
			j = rand() % cot;
		} while (a[i][j] == -1);
		a[i][j] = -1; 
	}
}

// TẠO BÃI MÌN
void TaoBaiMin(int a[][max], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	for (int j = 0; j < cot; j++)
	if (a[i][j] == 0) 
	{
		int dem = 0; 
		for (int k = i - 1; k <= i + 1; k++)
		for (int l = j - 1; l <= j + 1; l++)
		if (k >= 0 && k<dong&&l >= 0 && l<cot && a[k][l] == -1)
			dem++;
		a[i][j] = dem; 
	}
}