#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <ctime>
//#include <gdiplus.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib,"Msimg32.lib")
#define _USE_MATH_DEFINES 1
#include <cmath>
#define NOTSRCINVERT (DWORD)0x999999
#define M_PI   3.14159265358979323846264338327950288
//#define PI   3.14159265358979323846264338327950288
//typedef NTSTATUS(NTAPI* NRHEdef)(NTSTATUS, ULONG, ULONG, PULONG, ULONG, PULONG); 
//typedef NTSTATUS(NTAPI* RAPdef)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
typedef struct
{
	FLOAT h;
	FLOAT s;
	FLOAT l;
} HSL;

COLORREF RndRGB() {
	int clr = rand() % 5;
	if (clr == 0) return RGB(255, 0, 0); if (clr == 1) return RGB(0, 255, 0); if (clr == 2) return RGB(0, 0, 255); if (clr == 3) return RGB(255, 0, 255); if (clr == 4) return RGB(255, 255, 0);
}

LPCWSTR  generateRandomUnicodeString(int len)
{
	wchar_t* ustr = new wchar_t[len + 1];      // +1 for '\0'

	for (int i = 0; i < len; i++) {
		ustr[i] = (rand() % 256) + 1024;
	}
	ustr[len] = L'\0';
	return ustr;
} 
int stage = 0;
int r = 0, g = 0, b = 0;
COLORREF Hue(int shift) {
    switch (stage) {
        case 0:
            r = 255;
            b = 0;
            g < 255 ? g += shift : stage++;
            break;
        case 1:
            g = 255;
            b = 0;
            r > 0 ? r -= shift : stage++;
            break;
        case 2:
            g = 255;
            r = 0;
            b < 255 ? b += shift : stage++;
            break;
        case 3:
            b = 255;
            r = 0;
            g > 0 ? g -= shift : stage++;
            break;
        case 4:
            b = 255;
            g = 0;
            r < 255 ? r += shift : stage++;
            break;
        case 5:
            r = 255;
            g = 0;
            b > 0 ? b -= shift : stage = 0;
            break;
    }

    return RGB(r, g, b);
}
DWORD WINAPI cur(LPVOID lpParam) {
	POINT cursor;
	while (1) {
		HDC hdc = GetDC(HWND_DESKTOP);
		int sw = GetSystemMetrics(0);
		int sh = GetSystemMetrics(1);
		GetCursorPos(&cursor);
		DrawIcon(hdc,cursor.x,cursor.y,LoadIcon(NULL, MAKEINTRESOURCE((32512 + rand() % (32518 - 32512 + 1)))));
		ReleaseDC(0, hdc);
		//Sleep(10);
	}
	//return(1);
}
DWORD WINAPI shader1(LPVOID lpParam) {
		HDC hdc = GetDC(0);
		POINT cursor;
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	int inc31 = sw - sh%sw - sh;
	int why = 0;
	int why2 = 0;
	srand(time(0));
	while(true)
	{
		RECT rect;
        GetWindowRect(GetDesktopWindow(), &rect);
        POINT pt1[10];
        HPEN hPen = CreatePen(PS_SOLID, 10, RGB(rand()%255,rand()%255,rand()%255));
		HPEN hOldPen = SelectPen(hdc, hPen);
		HBRUSH hBrush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		HBRUSH hOldBrush = SelectBrush(hdc, hBrush);
		HBRUSH brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		SelectObject(hdc, brush);
		BitBlt(hdc,0,0,sw,sh,hdc,5,0,0x00090245);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-5,0,0x00090245);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc, 0, 0, sw, sh, hdc, 10-rand()%20, 10-rand()%20, 0x00010289);
		pt1[0].x = rect.left + 50-rand()%100;
        pt1[0].y = rect.top  + 50-rand()%100;
        pt1[1].x = rect.right+ 50-rand()%100;
        pt1[1].y = rect.top + 50-rand()%100;
        pt1[2].x = rect.left + 50-rand()%100;
        pt1[2].y = rect.bottom+ 50-rand()%100;
        PlgBlt(hdc, pt1, hdc, rect.left, rect.top, rect.right, rect.bottom, 0, 0, 0);
        brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
        BitBlt(hdc, 0, 0, sw, sh, hdc, 5, 0, 0x002606C8);
        brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc, 0, 0, sw, sh, hdc, -5, 0, 0x002606C8);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc, 0, 0, sw, sh, hdc, 0, 5, 0x002606C8);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc, 0, 0, sw, sh, hdc, 0, -5, 0x002606C8);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		StretchBlt(hdc,2-rand()%4,2-rand()%4,sw,sh,hdc,0,0,sw,sh,0x006858A6);
		DrawIcon(hdc,rand()%sw,rand()%sh,LoadCursor(NULL,IDC_ARROW));
		RoundRect(hdc,rand()%sw,rand()%sh,rand()%sw,rand()%sh,rand()%sw,rand()%sh);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		StretchBlt(hdc,5-rand()%10,5-rand()%10,sw,sh,hdc,0,0,sw,sh,0x00D307A4);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		StretchBlt(hdc, 0-sw/4, 0-sh/4, sw*1.5, sh*1.5, hdc, 0, 0,sw,sh, 0x002606C8);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		StretchBlt(hdc,rand()%sw,0,rand()%sw,sh,hdc,0,0,sw,sh,0x006A01E9);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		StretchBlt(hdc,0,rand()%sh,sw,rand()%sh,hdc,0,0,sw,sh,0x00720648);
		StretchBlt(hdc,rand()%sw,0,rand()%sw,sh,hdc,0,0,sw,sh,SRCCOPY);
		StretchBlt(hdc,0,rand()%sh,sw,rand()%sh,hdc,0,0,sw,sh,NOTSRCCOPY);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		Pie(hdc, rand()%sw,rand()%sh,rand()%sw,rand()%sh,rand()%sw,rand()%sh,rand()%sw,rand()%sh);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		StretchBlt(hdc,0+5-rand()%10,0+5-rand()%10,sw/2,sh/2,hdc,0,0,sw,sh,0x00090245);
		brush = CreateSolidBrush(RndRGB());
		StretchBlt(hdc,sw/2+5-rand()%10,0+5-rand()%10,sw/2,sh/2,hdc,0,0,sw,sh,0x00271868);
		brush = CreateSolidBrush(RndRGB());
		StretchBlt(hdc,0+5-rand()%10,sh/2+5-rand()%10,sw/2,sh/2,hdc,0,0,sw,sh,0x00140869);
		brush = CreateSolidBrush(RndRGB());
		StretchBlt(hdc,sw/2+5-rand()%10,sh/2+5-rand()%10,sw/2,sh/2,hdc,0,0,sw,sh,0x00120868);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc, 0, 0, sw, sh, hdc, 50-rand()%100, 50-rand()%100, 0x001302C8);
		pt1[0].x = rect.left;
        pt1[0].y = rect.top - 50;
        pt1[1].x = rect.right;
        pt1[1].y = rect.top + 50;
        pt1[2].x = rect.left;
        pt1[2].y = rect.bottom - 50;
        PlgBlt(hdc, pt1, hdc, rect.left, rect.top, rect.right, rect.bottom, 0, 0, 0);
        brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
        BitBlt(hdc, 0, 0, sw, sh, hdc, 50-rand()%100, 50-rand()%100, 0x001302C8);
        pt1[0].x = rect.left;
        pt1[0].y = rect.top + 50;
        pt1[1].x = rect.right;
        pt1[1].y = rect.top - 50;
        pt1[2].x = rect.left;
        pt1[2].y = rect.bottom + 50;
        PlgBlt(hdc, pt1, hdc, rect.left, rect.top, rect.right, rect.bottom, 0, 0, 0);
        DrawIcon(hdc, rand()%sw, rand()%sh, LoadIcon(NULL, MAKEINTRESOURCE((32512 + rand() % (32518 - 32512 + 1)))));
        brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
        BitBlt(hdc,0,0,sw,sh,hdc,50,0,0x006858A6);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-50,0,0x006718A8);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,0,50,0x00690145);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,0,-50,0x006A01E9);
		DrawIconEx(hdc, rand()%sw, rand()%sh, LoadCursor(NULL, IDC_NO),rand()%sw,rand()%sh,0,0,DI_NORMAL);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		StretchBlt(hdc,50/2,0,sw-50,sh,hdc,0,0,sw,sh,SRCCOPY);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		StretchBlt(hdc,0,50/2,sw,sh-50,hdc,0,0,sw,sh,SRCCOPY);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-sw/4+why,0,0x00100C85);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,sw-sw/4+why,0,0x00100C85);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-sw/4+why,0,0x001100A6);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,sw-sw/4+why,0,0x001100A6);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-sw/4+why,0,0x00120868);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,sw-sw/4+why,0,0x00120868);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-sw/4+why,0,0x001302C8);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,sw-sw/4+why,0,0x001302C8);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-sw/4+why,0,0x00140869);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,sw-sw/4+why,0,0x00140869);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-sw/4+why,0,0x001502C9);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,sw-sw/4+why,0,0x001502C9);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-sw/4+why,0,0x00165CCA);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,sw-sw/4+why,0,0x00165CCA);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-sw/4+why,0,0x00171D54);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,sw-sw/4+why,0,0x00171D54);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-sw/4+why,0,0x00180D59);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,sw-sw/4+why,0,0x00180D59);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-sw/4+why,0,0x00191CC8);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,sw-sw/4+why,0,0x00191CC8);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,10,0,0x002606C8);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-10,0,0x00480368);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,0,10,0x002606C8);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,0,-10,0x00480368);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		Rectangle(hdc,rand()%sw,rand()%sh,rand()%sw,rand()%sh);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		StretchBlt(hdc,0,0,rand()%sw,rand()%sh,hdc,0,0,sw,sh,SRCINVERT);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,5-rand()%10,5-rand()%10,0x004C0CC8);
		//Rectangle(hdc,rand()%sw,rand()%sh,rand()%sw,rand()%sh);
		StretchBlt(hdc, 0, 0, sw, sh/2, hdc, 0, 0, sw, sh, NOTSRCCOPY);
		StretchBlt(hdc, 0, sh/2, sw, sh/2, hdc, 0, 0, sw, sh, SRCCOPY);
		StretchBlt(hdc, 0, 0, sw/2, sh, hdc, 0, 0, sw, sh, NOTSRCCOPY);
		StretchBlt(hdc, sw/2, 0, sw/2, sh, hdc, 0, 0, sw, sh, SRCCOPY);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		POINT vertices[] = { {rand()%sw, rand()%sh}, {rand()%sw, rand()%sh}, {rand()%sw, rand()%sh} };
		Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));
		PolyBezier(hdc, vertices, sizeof(vertices) * sizeof(vertices[0]));
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,50-rand()%100,50-rand()%100,0x007D0C69);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,50-rand()%100,50-rand()%100,0x0047076A);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,50-rand()%100,50-rand()%100,0x009217A9);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,50,0,SRCAND);
		brush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		BitBlt(hdc,0,0,sw,sh,hdc,-50,0,SRCAND);
		GetCursorPos(&cursor);
		DrawIconEx(hdc,cursor.x-150,cursor.y-150,LoadIcon(NULL, MAKEINTRESOURCE((32512 + rand() % (32518 - 32512 + 1)))),300,300,0,0,DI_NORMAL);
		DrawIconEx(hdc,cursor.x-150+300,cursor.y-150,LoadIcon(NULL, MAKEINTRESOURCE((32512 + rand() % (32518 - 32512 + 1)))),300,300,0,0,DI_NORMAL);
		DrawIconEx(hdc,cursor.x-150-300,cursor.y-150,LoadIcon(NULL, MAKEINTRESOURCE((32512 + rand() % (32518 - 32512 + 1)))),300,300,0,0,DI_NORMAL);
		DrawIconEx(hdc,cursor.x-150,cursor.y-150+300,LoadIcon(NULL, MAKEINTRESOURCE((32512 + rand() % (32518 - 32512 + 1)))),300,300,0,0,DI_NORMAL);
		DrawIconEx(hdc,cursor.x-150,cursor.y-150-300,LoadIcon(NULL, MAKEINTRESOURCE((32512 + rand() % (32518 - 32512 + 1)))),300,300,0,0,DI_NORMAL);
		BitBlt(hdc, 0, 0, sw, sh, hdc, 40-rand()%80, 40-rand()%80, SRCPAINT);
		BitBlt(hdc, 0, 0, sw, sh, hdc, 40-rand()%80, 40-rand()%80, SRCAND);
		PatBlt(hdc, rand()%sw, rand()%sh, rand()%sw, rand()%sh, PATINVERT);
		BitBlt(hdc, 0, 0, sw, sh, hdc, -10, 0, 0x005408A9);
        BitBlt(hdc, 0, 0, sw, sh, hdc, sw-10, 0, 0x005408A9);
        BitBlt(hdc, 0, 0, sw, sh, hdc, 0, -10, 0x005408A9);
        BitBlt(hdc, 0, 0, sw, sh, hdc, 0, sh-10, 0x005408A9);
        StretchBlt(hdc, 2-rand()%4, 2-rand()%4, sw, sh, hdc, 0, 0,sw,sh, 0x00891B08);
		DrawIconEx(hdc,rand()%sw,rand()%sh,LoadIcon(NULL, IDI_WARNING),500,500,0,NULL,DI_NORMAL);
		DrawIconEx(hdc,rand()%sw,rand()%sh,LoadCursor(NULL, IDC_ARROW),500,500,0,NULL,DI_NORMAL);
		RoundRect(hdc,rand()%sw,rand()%sh,rand()%sw,rand()%sh,rand()%sw,rand()%sh);
		StretchBlt(hdc, 2-rand()%4, 2-rand()%4, sw, sh, hdc, 0, 0,sw,sh, 0x008E1D7C);
		StretchBlt(hdc, sw/4, 0, sw, sh, hdc, 0, 0,sw,sh, 0x009217A9);
		StretchBlt(hdc, -sw/4, 0, sw, sh, hdc, 0, 0,sw,sh, 0x009217A9);
		BitBlt(hdc, 0, -1, sw, sh, hdc, 0, 0, SRCAND);
		BitBlt(hdc, 0, 1, sw, sh, hdc, 0, 0, SRCAND);
		BitBlt(hdc, -30, 0, sw, sh, hdc, 0, 0, SRCCOPY);//credit to pankoza for the train effect
        BitBlt(hdc, sw - 30, 0, sw, sh, hdc, 0, 0, SRCCOPY);
        StretchBlt(hdc, 25/2, 25/2, sw-25, sh-25, hdc, 0, 0, sw, sh, SRCCOPY);
        BitBlt(hdc, 10, 0, sw, sh, hdc, 0, 0, SRCCOPY);
		BitBlt(hdc, -10, 0, sw, sh, hdc, 0, 0, SRCPAINT);
		StretchBlt(hdc, 0, 0, rand()%sw+25, sh, hdc, 0, 0, sw, sh, SRCCOPY);
		StretchBlt(hdc, 0, 0, rand()%sw-25, sh, hdc, 0, 0, sw, sh, SRCCOPY);
		BitBlt(hdc,rand()%10+1,rand()%10+1,sw,sh,hdc,0,0,SRCINVERT);
		DrawIconEx(hdc,rand()%sw,rand()%sh,LoadIcon(NULL, IDI_WINLOGO),200,200,0,NULL,DI_NORMAL);
		DrawIconEx(hdc,rand()%sw,rand()%sh,LoadIcon(NULL, IDI_WARNING),200,200,0,NULL,DI_NORMAL);
		BitBlt(hdc, rand()%500, rand()%500, rand()%sw, rand()%sh, hdc, 0, 0, PATINVERT);
		StretchBlt(hdc,4,0,sw,sh,hdc,0,0,sw,sh,SRCCOPY);
		StretchBlt(hdc,-5,0,sw,sh,hdc,0,0,sw,sh,SRCCOPY);
		BitBlt(hdc, rand()%500, rand()%500, rand()%sw, rand()%sh, hdc, 0, 0, PATINVERT);
		BitBlt(hdc, rand() % 666, rand() % 666, sw, sh, hdc, rand() % 666, rand() % 666, NOTSRCERASE);
		StretchBlt(hdc,-10/2,-10/2,sw+10,sh+10,hdc,0,0,sw,sh,SRCCOPY);
		BitBlt(hdc,5/2-rand()%5,5/2-rand()%5,sw,sh,hdc,0,0,SRCCOPY);
		BitBlt(hdc,rand()%sw,rand()%sh,rand()%sw,rand()%sh,hdc,0,0,SRCCOPY);
		StretchBlt(hdc,0,0,sw-rand()%sw,sh,hdc,0,0,sw,sh,SRCCOPY);
		StretchBlt(hdc,0,0,sw,sh-rand()%sh,hdc,0,0,sw,sh,SRCCOPY);
		StretchBlt(hdc,0,0,sw+rand()%sw,sh,hdc,0,0,sw,sh,SRCCOPY);
		StretchBlt(hdc,0,0,sw,sh+rand()%sh,hdc,0,0,sw,sh,SRCCOPY);
		PatBlt(hdc, 0, rand()%sh, sw, rand()%sh, PATINVERT);
		StretchBlt(hdc,0,0,sw-why,sh,hdc,0,0,sw,sh,SRCCOPY);
		StretchBlt(hdc,0,0,sw,sh-why,hdc,0,0,sw,sh,SRCCOPY);
		StretchBlt(hdc,why,0,sw-why,sh,hdc,0,0,sw,sh,SRCCOPY);
		StretchBlt(hdc,0,why,sw,sh-why,hdc,0,0,sw,sh,SRCCOPY);
		BitBlt(hdc,why,why,sw-why,sh-why,hdc,0,0,SRCINVERT);
		BitBlt(hdc,why,why,sw-why,sh-why,hdc,0,0,NOTSRCERASE);
		BitBlt(hdc,0,0,sw,sh,hdc,(sw/2)+why,0,NOTSRCCOPY);
		BitBlt(hdc,0,0,sw,sh,hdc,0,(sh/2)+why,NOTSRCERASE);
		BitBlt(hdc,0,0,sw,sh,hdc,(0-sw/2)+why,0,NOTSRCCOPY);
		BitBlt(hdc,0,0,sw,sh,hdc,0,(0-sh/2)+why,NOTSRCERASE);
		BitBlt(hdc,0,0,sw,sh,hdc,sw/2,0,SRCINVERT);
		BitBlt(hdc,0,0,sw,sh,hdc,0-sw/2,0,SRCINVERT);
		BitBlt(hdc,0,0,sw,sh,hdc,0,sh/2,SRCINVERT);
		BitBlt(hdc,0,0,sw,sh,hdc,0,0-sh/2,SRCINVERT);
		DrawIconEx(hdc,rand()%sw,rand()%sh,LoadIcon(NULL, MAKEINTRESOURCE((32512 + rand() % (32518 - 32512 + 1)))),500,500,0, NULL, DI_NORMAL);
		BitBlt(hdc, (rand() % 51)-25, (rand() % 51)-25, sw, sh, hdc, 0, 0, SRCAND);
		BitBlt(hdc, (rand() % 51)-25, (rand() % 51)-25, sw, sh, hdc, 0, 0, NOTSRCERASE);
		StretchBlt(hdc,rand()%sw/2,rand()%sh/2,rand()%sw,rand()%sh,hdc,0,0,sw,sh,SRCCOPY);
		DrawIconEx(hdc, rand()%sw, rand()%sh, LoadCursor(NULL, IDC_ARROW),200,200,0, NULL, DI_NORMAL);
		//Sleep(1);
		BitBlt(hdc,0,sh/8,sw,sh,hdc,0,0,SRCINVERT);
		BitBlt(hdc,0,0-sh/8,sw,sh,hdc,0,0,SRCINVERT);
		BitBlt(hdc,-2,0,sw,sh,hdc,0,0,SRCCOPY);
		BitBlt(hdc,sw-2,0,sw,sh,hdc,0,0,SRCCOPY);
		StretchBlt(hdc,0,sh/4,sw,sh/2,hdc,0,0,sw,sh,NOTSRCCOPY);
		inc31--;inc31--;inc31--;
        pt1[0].x = rect.left - inc31;
        pt1[0].y = rect.top - inc31;
        pt1[1].x = rect.right - inc31;
        pt1[1].y = rect.top + inc31;
        pt1[2].x = rect.left + inc31;
        pt1[2].y = rect.bottom - inc31;
        PlgBlt(hdc, pt1, hdc, rect.left, rect.top, rect.right, rect.bottom, 0, 0, 0);
        POINT pt2[10];
        //int inc31 = rand() % w - rand() % h % rand() % w - rand() % h;
        //inc31--;inc31--;inc31--;
        pt2[0].x = rect.left + inc31;
        pt2[0].y = rect.top + inc31;
        pt2[1].x = rect.right + inc31;
        pt2[1].y = rect.top - inc31;
        pt2[2].x = rect.left - inc31;
        pt2[2].y = rect.bottom + inc31;
        PlgBlt(hdc, pt2, hdc, rect.left, rect.top, rect.right, rect.bottom, 0, 0, 0);
        DrawIconEx(hdc, rand()%sw, rand()%sh, LoadCursor(NULL, IDC_WAIT),100,100,0, NULL, DI_NORMAL);
		//Sleep(1);
		BitBlt(hdc,0-why,0,sw,sh,hdc,0,0,SRCCOPY);
		BitBlt(hdc,sw-why,0,sw,sh,hdc,0,0,SRCCOPY);why++;
		BitBlt(hdc, 0, 0, sw, sh, hdc, (0-sw/1.5)+why, 0, 0x1900ac010e);
        BitBlt(hdc, 0, 0, sw, sh, hdc, (sw - 0-sw/1.5)+why, 0, 0x1900ac010e);
        BitBlt(hdc, 0, 0, sw, sh, hdc, 0, (0-sh/1.5)+why2, 0x1900ac010e);
        BitBlt(hdc, 0, 0, sw, sh, hdc, 0, (sh - 0-sh/1.5)+why2, 0x1900ac010e);
		DeleteObject(brush);why++;why++;why2--;
	}
}
VOID WINAPI sound1() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 11025, 11025, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[11025 * 60] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t*t*(t>>7&t>>9&t>>2));

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
int CALLBACK WinMain(
	HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine, int       nCmdShow
)
{
	MessageBoxW(NULL, L"survive for 1 minute", L"exe.exe", MB_OK | MB_ICONINFORMATION);
	HANDLE thread69 = CreateThread(0, 0, cur, 0, 0, 0);
	HANDLE thread420 = CreateThread(0, 0, shader1, 0, 0, 0);
	sound1();//sound1
	Sleep(60000);
}
