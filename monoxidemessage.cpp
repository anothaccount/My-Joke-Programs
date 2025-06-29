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
#pragma comment(lib, "winmm.lib")
#pragma comment(lib,"Msimg32.lib")
#define _USE_MATH_DEFINES 1
#include <cmath>
#define NOTSRCINVERT (DWORD)0x999999
#define M_PI   3.14159265358979323846264338327950288
//#define PI   3.14159265358979323846264338327950288
//typedef NTSTATUS(NTAPI* NRHEdef)(NTSTATUS, ULONG, ULONG, PULONG, ULONG, PULONG); 
//typedef NTSTATUS(NTAPI* RAPdef)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);

int main(){
	MessageBoxW(NULL, L"test", L"lmao", MB_OK | MB_ICONERROR);
	HWND wnd = GetForegroundWindow();
	HDC hdc = GetDC(0);
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	for (int i = 0; i < 50; ++i) {
	Arc(hdc,rand()%sw,rand()%sh,rand()%sw,rand()%sh,rand()%sw,rand()%sh,rand()%sw,rand()%sh); 
    Beep(rand()%5000, 100);
    BitBlt(hdc,0,-1,sw,sh,hdc,0,0,SRCCOPY);
    }
	Sleep(300);
}
