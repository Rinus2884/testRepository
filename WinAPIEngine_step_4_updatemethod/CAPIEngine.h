#pragma once

#include "framework.h"
//Windows.h를 포함하기 위해 포함

#define MAX_LOADSTRING 100

//게임프로그램 구조를 담당하는 클래스이다.
class CAPIEngine
{
public:
	CAPIEngine();
	virtual ~CAPIEngine();//가상소멸자 적용

	//복사 생성자, 복사대입연산자는 작동하지 않도록 막겠다.
	// ( 여기서 쓰인 delete예약어는 해당 기능을 작동하지 않도록 막겠다는 의미이다.)
	// 
	//private:예전에는 이렇게함
	//CAPIEngine(const CAPIEngine& t) {};
	CAPIEngine(const CAPIEngine& t) = delete;
	CAPIEngine operator=(const CAPIEngine& t) = delete;
	

public:
	void Create(HINSTANCE hInstance, int nCmdShow);
	MSG Run();


	virtual void OnCreate();
	virtual void OnDestroy();
	virtual void OnUpdate();


	//원 그리기 함수
	//tX, tY: 원의 중심
	//tRadius: 원의 반지름
	//float로 타입을 결정한 이유는 --> 2차원 연속적인 게임세계를 가정
	void DrawCircle(float tX, float tY, float tRadius);



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
	//윈도우 핸들을 멤버변수로 선언
	HWND mhWnd;
	//DC핸들을 멤버변수로 선언
	HDC mhDC;

};

