#pragma once

#include "framework.h"
//Windows.h�� �����ϱ� ���� ����

#define MAX_LOADSTRING 100

//�������α׷� ������ ����ϴ� Ŭ�����̴�.
class CAPIEngine
{
public:
	CAPIEngine();
	virtual ~CAPIEngine();//����Ҹ��� ����

	//���� ������, ������Կ����ڴ� �۵����� �ʵ��� ���ڴ�.
	// ( ���⼭ ���� delete������ �ش� ����� �۵����� �ʵ��� ���ڴٴ� �ǹ��̴�.)
	// 
	//private:�������� �̷�����
	//CAPIEngine(const CAPIEngine& t) {};
	CAPIEngine(const CAPIEngine& t) = delete;
	CAPIEngine operator=(const CAPIEngine& t) = delete;
	

public:
	void Create(HINSTANCE hInstance, int nCmdShow);
	MSG Run();


	virtual void OnCreate();
	virtual void OnDestroy();
	virtual void OnUpdate();


	//�� �׸��� �Լ�
	//tX, tY: ���� �߽�
	//tRadius: ���� ������
	//float�� Ÿ���� ������ ������ --> 2���� �������� ���Ӽ��踦 ����
	void DrawCircle(float tX, float tY, float tRadius);



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
	//������ �ڵ��� ��������� ����
	HWND mhWnd;
	//DC�ڵ��� ��������� ����
	HDC mhDC;

};

