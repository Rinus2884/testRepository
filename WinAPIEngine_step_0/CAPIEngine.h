#pragma once

#include "framework.h"
//Windows.h를 포함하기 위해 포함

#define MAX_LOADSTRING 100

class CAPIEngine
{
public:
	void Create(HINSTANCE hInstance, int nCmdShow);
	MSG Run();

private:
	ATOM                MyRegisterClass(HINSTANCE hInstance);
	BOOL                InitInstance(HINSTANCE, int);
	//표기법상 이것은 멤버함수이지만
	//static예약어를 적용하여 전역함수의 성격을 띄게 만들었다.
	static LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
	static INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);





public:
	static HINSTANCE hInst; //<--static함수에서 다루어지므로 이것도 static을 적용하였다.                              
	WCHAR szTitle[MAX_LOADSTRING];                 
	WCHAR szWindowClass[MAX_LOADSTRING];

};

