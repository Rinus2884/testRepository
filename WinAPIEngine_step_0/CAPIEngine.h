#pragma once

#include "framework.h"
//Windows.h�� �����ϱ� ���� ����

#define MAX_LOADSTRING 100

class CAPIEngine
{
public:
	void Create(HINSTANCE hInstance, int nCmdShow);
	MSG Run();

private:
	ATOM                MyRegisterClass(HINSTANCE hInstance);
	BOOL                InitInstance(HINSTANCE, int);
	//ǥ����� �̰��� ����Լ�������
	//static���� �����Ͽ� �����Լ��� ������ ��� �������.
	static LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
	static INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);





public:
	static HINSTANCE hInst; //<--static�Լ����� �ٷ�����Ƿ� �̰͵� static�� �����Ͽ���.                              
	WCHAR szTitle[MAX_LOADSTRING];                 
	WCHAR szWindowClass[MAX_LOADSTRING];

};

