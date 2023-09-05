#include <Windows.h>
#include <iostream>
#include "beacon.h"


DECLSPEC_IMPORT INT WINAPI WINUSER$MessageBoxA(HWND hWnd, LPCSTR lpTest, LPCSTR lpCaption, UINT uType);

void go() {
	WINUSER$MessageBoxA(NULL, "Hello From BOF-land!", "Meterpreter Says...", MB_OK);
}