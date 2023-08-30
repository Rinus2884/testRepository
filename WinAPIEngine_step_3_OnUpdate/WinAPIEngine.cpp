// WinAPIEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

/*
   이번 스텝에서는
   
   i) 다음 window api함수들을 사용하여 
      적절한 '클라이언트client 영역'을 가진 윈도우로 조정한다.

       AdjustWindowRect
       SetWindowPos

    ii) 문자열, 도형(직선, 사각형, 원)등을 출력해본다
        윈도우 프로시저에 WM_PAINT메시지 처리부에서 해본다.
        <-- 윈도우 데스크탑 응용프로그램 처리방법


    iii) ii)항목의 내용을 OnUpdate에서 처리하도록 구조를 변경한다.
         <-- 게임 프로그램에서의 처리방법

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



