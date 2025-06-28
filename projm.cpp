#include <windows.h>
#include <math.h>
#include <cmath>
#include <iostream>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib,"Msimg32.lib")
#include "stuffs.h"

int red, green, blue;
bool ifcolorblue = false, ifblue = false;
COLORREF Hue(int length) { //Credits to Void_/GetMBR
	if (red != length) {
		red < length; red++;
		if (ifblue == true) {
			return RGB(red, 0, length);
		}
		else {
			return RGB(red, 0, 0);
		}
	}
	else {
		if (green != length) {
			green < length; green++;
			return RGB(length, green, 0);
		}
		else {
			if (blue != length) {
				blue < length; blue++;
				return RGB(0, length, blue);
			}
			else {
				red = 0; green = 0; blue = 0;
				ifblue = true;
			}
		}
	}
}


void p1() //Stretch zoom effect
{	
    while (1) {
        HDC hdc = GetDC(0);
        int x = SM_CXSCREEN;
        int y = SM_CYSCREEN;
        int w = GetSystemMetrics(0);
        int h = GetSystemMetrics(1);
        //BitBlt(hdc, rand() % 666, rand() % 666, w, h, hdc, rand() % 666, rand() % 666, NOTSRCERASE);
        //Sleep(10);
        StretchBlt(hdc,-5,0,w+10,h,hdc,0,0,w,h,SRCCOPY);
        StretchBlt(hdc,0,-5,w,h+10,hdc,0,0,w,h,SRCCOPY);
        //Sleep(10);
        ReleaseDC(0, hdc);
    }
}
void p2() //Cube from flv.exe
{
	HDC dc = GetDC(NULL);
	HDC dcCopy = CreateCompatibleDC(dc);
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);

	/*
		   Setup the Tesseract's size
		By your screen's width and height
	*/

	float size = (w + h) / 10;

	int cx = size;
	int cy = size;

	int xdv = 10;
	int ydv = 10;

	float angleX = 0.01;
	float angleY = 0.01;
	float angleZ = 0.01;

	int d = 60;

	VERTEX vtx[] =
	{
		//BOTTOM HYPER CUBE
		{size, 0, 0},
		{size, size, 0},
		{0, size, 0},
		{0, 0, 0},

		//TOP HYPER CUBE
		{size, 0, size},
		{size, size, size},
		{0, size, size},
		{0, 0, size},

		//BOTTOM INSIDE HYPER CUBE
		{size - d,  d,      d},
		{size - d,  size - d,  d},
		{d,      size - d,  d},
		{d,      d,      d},

		//TOP INSIDE HYPER CUBE
		{size - d,  d,      size - d},
		{size - d,  size - d,  size - d},
		{d,      size - d,  size - d},
		{d,      d,      size - d}
	};

	//32 EDGES
	EDGE edges[] =
	{
		//BOTTOM HYPER CUBE FACE (0, 1, 2, 3)
		{0, 1},
		{1, 2},
		{2, 3},
		{3, 0},

		//BOTTOM-TOP HYPER CUBE FACE
		{0, 4},
		{1, 5},
		{2, 6},
		{3, 7},

		//TOP HYPER CUBE FACE (4, 5, 6, 7)
		{4, 5},
		{5, 6},
		{6, 7},
		{7, 4},

		//BOTTOM INSIDE HYPER CUBE FACE (8, 9, 10, 11)
		{8,   9},
		{9,  10},
		{10, 11},
		{11,  8},

		//BOTTOM-TOP INSIDE HYPER CUBE FACE
		{8,  12},
		{9,  13},
		{10, 14},
		{11, 15},

		//TOP INSIDE HYPER CUBE FACE (12, 13, 14, 15)
		{12, 13},
		{13, 14},
		{14, 15},
		{15, 12},

		//HYPER CUBE AND INSIDE CONNECTION BOTTOM
		{0,  8},
		{1,  9},
		{2, 10},
		{3, 11},

		//HYPER CUBE AND INSIDE CONNECTION TOP
		{4, 12},
		{5, 13},
		{6, 14},
		{7, 15}
	};


	int index = rand() % 4;

	//Calculate the number of vertex and edges
	int totvtx = sizeof(vtx) / sizeof(vtx[0]);
	int totedg = sizeof(edges) / sizeof(edges[0]);

	while (true)
	{
		dc = GetDC(NULL);

		//Rotate Axis
		for (int i = 0; i < totvtx; i++)
		{
			_3D::RotateX(&vtx[i], angleX);
			_3D::RotateY(&vtx[i], angleY);
			_3D::RotateZ(&vtx[i], angleZ);
		}

		//Draw the edge
		for (int i = 0; i < totedg; i++)
		{
			_3D::DrawEdge(dc,
				vtx[edges[i].vtx0].x + cx, vtx[edges[i].vtx0].y + cy,
				vtx[edges[i].vtx1].x + cx, vtx[edges[i].vtx1].y + cy, 20);
		}

		Sleep(40);


		//Moves the tesseract around
		cx += xdv;
		cy += ydv;

		//Right and left collisions
		if (cx > w - (size / 2) || cx < -(size / 2))
		{
			xdv *= -1;
			index = rand() % 4;
		}

		//Top and bottom collisions
		if (cy > h - (size / 2) || cy < -(size / 2))
		{
			ydv *= -1;
			index = rand() % 4;
		}
		ReleaseDC(0, dc);
	}

	return 0x00;
}
int main(){
	//p1();
	p2();
}
