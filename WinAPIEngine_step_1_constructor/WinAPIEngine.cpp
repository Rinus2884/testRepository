// WinAPIEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

/*
   CAPIEngine을 상속받아
   나만의 게임 클래스를 만드는 형태로 구성하자.

   <-- CAPIEngine 클래스: '게임 프로그램의 주요한 구조와 기능'을 담는 클래스
   <-- CRyuEngine 클래스: 게임 로직(logic, 게임플레이 관련 코드) 을 담는 클래스


   i) 상속관계를 만들고 소멸자는 적절하게 작동하게 하기 위해서
   가상소멸자로 만들었다.

   ii) 게임프로그램 구조의 가장 핵심 개념인 게임루프를 고려하여
   자식클래스에서 게임 플레이 관련 코드를 작성할 수 있는 위치인
   OnCreate, OnDestroy, OnUpdate 함수를 가상함수로 만들어 재정의하였다.


   <--- OnUpdate는 아직 게임루프 구조가 마련되지 않아 미테스트


   iii) 만약을 위해 
        복사생성자, 
        복사대입연산자는 
        막아두었다.


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



