#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <time.h>

int main()
{
	HDC hdc = GetDC(0);
	int x = GetSystemMetrics(0);
	int y = GetSystemMetrics(1);
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	while(true)
	{
		//BitBlt(hdc, 0, 0, y, x, hdc, 0, 0, PATINVERT);
		//BitBlt(hdc, 10, 0, y, x, hdc, 0, 0, SRCCOPY);
		//BitBlt(hdc, -10, 0, y, x, hdc, 0, 0, SRCPAINT);
		StretchBlt(hdc, rand()%20+1, rand()%20+1, sw-rand()%20+1, sh-rand()%20+1, hdc, 0, 0, sw, sh, SRCCOPY);
		StretchBlt(hdc, rand()%100+1, rand()%100+1, rand()%2000+1, rand()%2000+1, hdc, 0, 0, sw, sh, SRCCOPY);
		PatBlt(hdc,rand()%20+1,rand()%20+1,y,x,PATPAINT);
		Sleep(100);
		//BitBlt(hdc, 10, 0, y, x, hdc, 0, 0, SRCPAINT);
		//SetStretchBltMode(hdc,COLORONCOLOR);
		//SetStretchBltMode(hdc,HALFTONE);		
		//StretchBlt(hdc, 0, 0, rand()%sw-25, sh, hdc, 0, 0, sw, sh, SRCCOPY);
		//BitBlt(hdc,rand()%10+1,rand()%10+1,y,x,hdc,0,0,SRCINVERT);
		//Ellipse(hdc,rand()%10-15,sh,rand()%10-15,sw);
		//Sleep(500);
	}
}

