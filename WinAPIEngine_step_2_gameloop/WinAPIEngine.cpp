// WinAPIEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

/*
   이번 스텝에서는
   '메시지 루프 message loop'를
   게임프로그램의 핵심개념인
   '게임루프 game loop'까지 고려한 구조로 변경한다.

   결과적으로
     -윈도우 데스크탑 응용 프로그램 구조
     -게임 프로그램 구조
    이 두가지 경우를 모두 고려한 구조로 만들겠다 라는 것이다.


*/



#include "framework.h"
#include "WinAPIEngine.h"

#include "CAPIEngine.h"

class CRyuEngine :public CAPIEngine
{
public:
    CRyuEngine() {};
    virtual ~CRyuEngine() {};//가상소멸자 적용

    //복사함수는 막았다.
    CRyuEngine(const CRyuEngine& t) = delete;
    CRyuEngine operator=(const CRyuEngine& t) = delete;

public:
    virtual void OnCreate() override
    {
        CAPIEngine::OnCreate();


        //todo
        OutputDebugString(L"CRyuEngine::OnCreate\n");
    }

    virtual void OnDestroy() override
    {
        //todo
        OutputDebugString(L"CRyuEngine::OnDestroy\n");

        CAPIEngine::OnDestroy();

    }

    virtual void OnUpdate() override
    {
        CAPIEngine::OnUpdate();

        //todo
        //OutputDebugString(L"=======CRyuEngine::OnUpdate\n");
    }



};





int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

  
    //CAPIEngine tEngine;
    CRyuEngine tEngine;
    tEngine.Create(hInstance, nCmdShow);


    //CAPIEngine tEngineB = tEngine;   //복사 생성자 작동 안됨 확인
    //CAPIEngine tEngineC;
    //tEngineC = tEngine;        //복사대입연산자 작동 안됨 확인


    MSG tMsg = { 0 };


   tMsg = tEngine.Run();

   return (int)tMsg.wParam;
}



