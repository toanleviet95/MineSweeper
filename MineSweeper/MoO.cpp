#include <iostream>
#include "HamHoTro.h";
using namespace std;
#define max 200

// MỞ Ô ĐÁNH SỐ (ĐƯỢC TÔ MÀU KHÁC NHAU)
void MoOso(int a[][max], int i, int j, bool b[][max])
{ 
	        if (a[i][j] == 0){
		        gotoxy(j * 3 + 1, i * 2 + 1);
		        SetBGColor(15);
		        cout << "  ";
	        }
	        else if (a[i][j] == 1)
			{
				gotoxy(j * 3 + 1, i * 2 + 1);
				SetBGColor(7);
				SetColor(1);
				cout << '1';
			}
			else if (a[i][j] == 2)
			{
				gotoxy(j * 3 + 1, i * 2 + 1);
				SetBGColor(7);
				SetColor(2);
				cout << '2';
			}
			else if (a[i][j] == 3)
			{
				gotoxy(j * 3 + 1, i * 2 + 1);
				SetBGColor(7);
				SetColor(4);
				cout << '3';
			}
			else if (a[i][j] == 4)
			{
				gotoxy(j * 3 + 1, i * 2 + 1);
				SetBGColor(7);
				SetColor(0);
				cout << '4';
			}
			else if (a[i][j] == 5)
			{
				gotoxy(j * 3 + 1, i * 2 + 1);
				SetBGColor(7);
				SetColor(5);
				cout << '5';
			}
			else if (a[i][j] == 6)
			{
				gotoxy(j * 3 + 1, i * 2 + 1);
				SetBGColor(7);
				SetColor(6);
				cout << '6';
			}
			else if (a[i][j] == 7)
			{
				gotoxy(j * 3 + 1, i * 2 + 1);
				SetBGColor(7);
				SetColor(3);
				cout << '7';
			}
			else if (a[i][j] == 8)
			{
				gotoxy(j * 3 + 1, i * 2 + 1);
				SetBGColor(7);
				SetColor(18);
				cout << '8';
			}
	        b[i][j] = true; 
}
// MỞ Ô KHÔNG CÓ BOM
void MoOkhong(int a[][max], int i, int j, int dong, int cot, bool b[][max])
{
	bool khong;
	MoOso(a, i, j, b);
	for (int k = -1; k<2; k++)
	for (int m = -1; m<2; m++)
	{
		if (i+k>=0&&i+k<=dong&&j+m>=0&&j+m<=cot&&a[i + k][j + m] == 0)
		{
			khong = b[i + k][j + m];
			MoOso(a, i + k, j + m, b);
			b[i + k][j + m] = khong;
		}
		else
		{
			MoOso(a, i + k, j + m, b);
		}
	}
}

// XỬ LÍ XUNG QUANH SAU KHI CHỌN PHẢI Ô KHÔNG CÓ BOM
void XuLyXungQuanh(int a[][max], int i, int j, int dong, int cot, bool b[][max])
{
	int dem = 1;
	//Nếu gặp ô số hay ô mìn thì thôi
	//Nếu là ô số 0 thì mở tất cả ra 
	if (dem == 0)
	{
		dem = 1;
		return;
	}
	dem = 0;
	for (int k = -1; k <= 1; k++)
	for (int m = -1; m <= 1; m++)
	if (a[i + k][j + m] == 0)
	{
		if (b[i + k][j + m] == false)
		{
			MoOkhong(a, i + k, j + m, dong, cot, b);
			dem++;
			XuLyXungQuanh(a, i + k, j + m, dong, cot, b);
		}
		if (a[i + k][j + m] > 0)
		{
			MoOso(a, i, j, b);
			XuLyXungQuanh(a, i + k, j + m, dong, cot, b);
		}
	}

}

// Ô CHƯA MỞ 
int ChuaMo(bool b[][max], int dong, int cot)
{
	int dem = 0;
	for (int i = 0; i<dong; i++)
	for (int j = 0; j<cot; j++)
	{
		if (!b[i][j])
		{
			dem++;
		}
	}
	return dem;
}

// XUẤT MÌN
void XuatMin(int a[][max], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	for (int j = 0; j < cot; j++)
	{
		if (a[i][j] == -1)
		{
			gotoxy(j * 3 + 1, i * 2 + 1);
			SetBGColor(14);
			SetColor(4);
			printf("%c", 15);
		}
	}
}