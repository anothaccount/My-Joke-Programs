#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <time.h>

int main()
{
	HDC hdc = GetDC(0);
	int x = GetSystemMetrics(0);
	int y = GetSystemMetrics(0);
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	while(true)
	{
		//BitBlt(hdc, 0, 0, y, x, hdc, 0, 0, PATINVERT);
		BitBlt(hdc, 10, 0, y, x, hdc, 0, 0, SRCCOPY);
		BitBlt(hdc, -10, 0, y, x, hdc, 0, 0, SRCPAINT);
		Sleep(300);
		//BitBlt(hdc, 10, 0, y, x, hdc, 0, 0, SRCPAINT);
		//SetStretchBltMode(hdc,COLORONCOLOR);
		//SetStretchBltMode(hdc,HALFTONE);		
		StretchBlt(hdc, 0, 0, rand()%sw+25, sh, hdc, 0, 0, sw, sh, SRCCOPY);
		StretchBlt(hdc, 0, 0, rand()%sw-25, sh, hdc, 0, 0, sw, sh, SRCCOPY);
		BitBlt(hdc,rand()%10+1,rand()%10+1,y,x,hdc,0,0,SRCINVERT);
		//Ellipse(hdc,rand()%10-15,sh,rand()%10-15,sw);
		//Sleep(500);
	}
}

