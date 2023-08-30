// WinAPIEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

/*
   이번 스텝에서는


   i) DrawCircle 함수를 만들자.
       <-- 게임 엔징의 주요기능으로 취급

   ii) CUnit클래스를 추가

   iii) CUnit객체의 외관은 일단 원 으로 취급하여 표현하자

   iv) UpdateMethod 개념을 살펴보자.



*/



#include "framework.h"
#include "WinAPIEngine.h"

#include "CAPIEngine.h"
#include "CUnit.h"

class CRyuEngine :public CAPIEngine
{
    CUnit* mpUnit = nullptr;



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

        mpUnit = new CUnit;
    }

    virtual void OnDestroy() override
    {
        if (nullptr != mpUnit)
        {
            delete mpUnit;
            mpUnit = nullptr;
        }
        //todo
        OutputDebugString(L"CRyuEngine::OnDestroy\n");

        CAPIEngine::OnDestroy();

    }

    virtual void OnUpdate() override
    {
        CAPIEngine::OnUpdate();


        //키입력 처리를 하는 window api함수
        if (GetAsyncKeyState('A') & 0x8000)
        {
            mpUnit->mX = mpUnit->mX - 0.01f;
        }
        

        //todo
        //OutputDebugString(L"=======CRyuEngine::OnUpdate\n");

        //mpUnit의 외관을 원으로 표현하자
        //this->DrawCircle(200.0f, 100.0f, 50.0f);
        //this->DrawCircle(mpUnit->mX, mpUnit->mY, mpUnit->mRadius);
        mpUnit->Render(this); //this는 CRyuEngine* 이고 이는 부모클래스인 CAPIEngine*을 표현할 수 있다
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



