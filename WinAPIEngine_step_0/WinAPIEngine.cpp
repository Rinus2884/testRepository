// WinAPIEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

/*
    크게 두가지에 초점을 맞춘다.

    i) 주요 window api를 사용해본다
    ii) 주요한 게임 프로그램 구조들을 만들어본다.


    윈도우 데스크탑 응용프로그램을 만들고 구동시키는 코드를
    클래스화해보자.

    i) CAPIEngine




*/



#include "framework.h"
#include "WinAPIEngine.h"

#include "CAPIEngine.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

  
    CAPIEngine tEngine;
    tEngine.Create(hInstance, nCmdShow);

    MSG tMsg = { 0 };


   tMsg = tEngine.Run();

   return (int)tMsg.wParam;
}



