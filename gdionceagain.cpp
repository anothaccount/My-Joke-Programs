#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <time.h>

int main()
{
	HDC hdc = GetDC(0);
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	int why = 1;
	while(true)
	{
		//StretchBlt(hdc, 0, 0, sw, sh/2, hdc, 0, 0, sw, sh, SRCCOPY); //why++;
		//StretchBlt(hdc, 0, sh/2, sw, sh/2, hdc, 0, 0, sw, sh, SRCCOPY); //why++;
		//BitBlt(hdc, 0, 0, y, x, hdc, 0, 0, PATINVERT);
		//BitBlt(hdc, 10, 0, y, x, hdc, 0, 0, SRCCOPY);
		//BitBlt(hdc, 0, 0, sw, sh, hdc, 0, 0, SRCPAINT);
		//StretchBlt(hdc, why, why, sw, sh, hdc, 0, 0, sw, sh, SRCCOPY); why++;//why++;
		//StretchBlt(hdc, sw/4+why/2, sh/4+why/2, sw/2-why, sh/2-why, hdc, 0, 0, sw, sh, SRCCOPY); why++;why++;
		//StretchBlt(hdc, 0, 0, sw/4, sh/4, hdc, 0, 0, sw, sh, SRCCOPY); //why++;
		//StretchBlt(hdc, 0, sh/2, sw/4, sh/4, hdc, 0, 0, sw, sh, SRCCOPY); //why++;
		//StretchBlt(hdc, sw/2, 0, sw/4, sh/4, hdc, 0, 0, sw, sh, SRCCOPY); //why++;
		//StretchBlt(hdc, sw/2, sh/2, sw/4, sh/4, hdc, 0, 0, sw, sh, SRCCOPY); //why++;
		//StretchBlt(hdc, why, why, sw/2, sh/2, hdc, 0, 0, sw, sh, SRCCOPY); //why++;
		//StretchBlt(hdc, why, sh/2+0-why, sw/2, sh/2, hdc, 0, 0, sw, sh, SRCCOPY); //why++;
		//StretchBlt(hdc, sw/2+0-why, why, sw/2, sh/2, hdc, 0, 0, sw, sh, SRCCOPY); //why++;
		//StretchBlt(hdc, sw/2+0-why, sh/2+0-why, sw/2, sh/2, hdc, 0, 0, sw, sh, SRCCOPY); why++;
		//StretchBlt(hdc, 0-why, 0-why, sw+why, sh+why, hdc, 0, 0, sw, sh, SRCCOPY); why++;
		//StretchBlt(hdc, 0-why, 0-why, sw, sh, hdc, 0, 0, sw, sh, NOTSRCERASE); why++;
		//PatBlt(hdc,rand()%20+1,rand()%20+1,y,x,PATPAINT);
		//Sleep(100);
		//BitBlt(hdc, 10, 0, y, x, hdc, 0, 0, SRCPAINT);
		//SetStretchBltMode(hdc,COLORONCOLOR);
		//SetStretchBltMode(hdc,HALFTONE);		
		//StretchBlt(hdc, 0, 0, rand()%sw-25, sh, hdc, 0, 0, sw, sh, SRCCOPY);
		BitBlt(hdc, why, why, sw, sh, hdc, 0, 0, NOTSRCERASE); why++;
		//Ellipse(hdc,rand()%10-15,sh,rand()%10-15,sw);
		//Sleep(500);
	}
}
