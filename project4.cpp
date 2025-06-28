#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <cmath>

const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);

void rgbquad() {
    HDC hdc, memdc;
    HBITMAP hdib;

    BITMAPINFO bInfo = {0};
    bInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bInfo.bmiHeader.biBitCount = 32;
    bInfo.bmiHeader.biPlanes = 1;
    bInfo.bmiHeader.biWidth = HDCX;
    bInfo.bmiHeader.biHeight = HDCY;
    bInfo.bmiHeader.biCompression = BI_RGB;
    bInfo.bmiHeader.biSizeImage = 0;

    RGBQUAD *pixel = {0};

    while (1) {
        hdc = GetDC(0); memdc = CreateCompatibleDC(hdc);
        hdib = CreateDIBSection(hdc, &bInfo, NULL, (void**)&pixel, 0, 0);
        SelectObject(memdc, hdib);

        BitBlt(memdc, 0, 0, HDCX, HDCY, hdc, 0, 0, SRCCOPY);

        for (int i = 0; i < HDCX * HDCY; i++) {
            pixel[i].rgbRed -= 1;
            pixel[i].rgbBlue += 1;
        }

        BitBlt(hdc, 0, 0, HDCX, HDCY, memdc, 0, 0, SRCCOPY);

        ReleaseDC(0, hdc); DeleteDC(memdc); DeleteObject(hdib);
    }
}
void lines() {
    HDC hdc;
    HPEN pen;
    COLORREF color;
    POINT bPoints[4];
    bPoints[0] = {HDCX/2, HDCY/2};

    while (1) {
        hdc = GetDC(0);

        bPoints[1] = {rand()%HDCX, rand()%HDCY};
        bPoints[2] = {rand()%HDCX, rand()%HDCY};
        bPoints[3] = {rand()%HDCX, rand()%HDCY};

        color = RGB(rand()%256, rand()%256, rand()%256);
        pen = CreatePen(PS_SOLID, 7, color);
        SelectObject(hdc, pen);

        PolyBezier(hdc, bPoints, 4);

        ReleaseDC(0, hdc); DeleteObject(pen);
    }
}
void stretch(){
	HDC hdc;
	while (1){
        hdc = GetDC(0);		
		StretchBlt(hdc,0,0,HDCX+5,HDCY+5,hdc,0,0,HDCX,HDCY,SRCCOPY);
	}
}
void all(){
	HDC hdc, memdc;
    HPEN pen;
    COLORREF color;
    POINT bPoints[4];
    bPoints[0] = {HDCX/2, HDCY/2};	
    HBITMAP hdib;

    BITMAPINFO bInfo = {0};
    bInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bInfo.bmiHeader.biBitCount = 32;
    bInfo.bmiHeader.biPlanes = 1;
    bInfo.bmiHeader.biWidth = HDCX;
    bInfo.bmiHeader.biHeight = HDCY;
    bInfo.bmiHeader.biCompression = BI_RGB;
    bInfo.bmiHeader.biSizeImage = 0;

    RGBQUAD *pixel = {0};
	while (1){
		hdc = GetDC(0);	memdc = CreateCompatibleDC(hdc);
		StretchBlt(hdc,0,0,HDCX+5,HDCY+5,hdc,0,0,HDCX,HDCY,SRCCOPY);
		bPoints[1] = {rand()%HDCX, rand()%HDCY};
        bPoints[2] = {rand()%HDCX, rand()%HDCY};
        bPoints[3] = {rand()%HDCX, rand()%HDCY};

        color = RGB(rand()%256, rand()%256, rand()%256);
        pen = CreatePen(PS_SOLID, 7, color);
        SelectObject(hdc, pen);

        PolyBezier(hdc, bPoints, 4);

        ReleaseDC(0, hdc); DeleteObject(pen);
        hdib = CreateDIBSection(hdc, &bInfo, NULL, (void**)&pixel, 0, 0);
        SelectObject(memdc, hdib);

        BitBlt(memdc, 0, 0, HDCX, HDCY, hdc, 0, 0, SRCCOPY);

        for (int i = 0; i < HDCX * HDCY; i++) {
            pixel[i].rgbRed -= 1;
            pixel[i].rgbBlue += 1;
        }

        BitBlt(hdc, 0, 0, HDCX, HDCY, memdc, 0, 0, SRCCOPY);
	}
}

int main() {
    //rgbquad();
    //lines();
    //stretch();
	all();
}
