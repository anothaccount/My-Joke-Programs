#include <windows.h>
#include <iostream>

int main() {
	HDC hdc;
    POINT curPos;
    HICON icon = LoadCursor(NULL, IDC_ARROW);
    int w = GetSystemMetrics(SM_CXICON), h = GetSystemMetrics(SM_CYICON);
    
    while (1) {
        hdc = GetDC(0);

        GetCursorPos(&curPos);
        DrawIcon(hdc, curPos.x+20, curPos.y, icon);
        DrawIcon(hdc, curPos.x-20, curPos.y, icon);
        DrawIcon(hdc, curPos.x, curPos.y+20, icon);
        DrawIcon(hdc, curPos.x, curPos.y-20, icon);

        ReleaseDC(0, hdc);
    }
}
