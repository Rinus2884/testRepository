#include "CAPIEngine.h"

#include "Resource.h"

//static변수이므로 전역공간에서 초기화
HINSTANCE CAPIEngine::hInst = nullptr;





CAPIEngine::CAPIEngine()
{
    //메모리 초기화
    memset(szTitle, 0, MAX_LOADSTRING * sizeof(WCHAR));
    memset(szWindowClass, 0, MAX_LOADSTRING * sizeof(WCHAR));
}
CAPIEngine::~CAPIEngine()
{

}






void CAPIEngine::Create(HINSTANCE hInstance, int nCmdShow)
{
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPIENGINE, szWindowClass, MAX_LOADSTRING);

    MyRegisterClass(hInstance);
    InitInstance(hInstance, nCmdShow);
}
//MSG CAPIEngine::Run()
//{
//    //게임프로그램 생성부라고 가정한다
//    OnCreate();
//
//
//
//    HACCEL hAccelTable = LoadAccelerators(hInst, MAKEINTRESOURCE(IDC_WINAPIENGINE));
//
//    MSG msg;//메시지 데이터 를 나타내는 변수
//
//    //일단 이것을 게임루프라고 가정
//    // 기본 메시지 루프입니다:
//    /*
//        메시지 큐에서 메시지를 얻는다
//          엑셀러레이터 처리를 우선으로 한다
//          메시지를 해석한다
//          메시지를 윈도우프로시저가 처리할 수 있도록 디스패치해준다.
//    */
//    while (GetMessage(&msg, nullptr, 0, 0))//메시지 큐에 메시지가 없으면 대기한다.
//    {
//        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//        {
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//        }
//    }
//
//
//    //게임프로그램 해제부라고 가정한다
//    OnDestroy();
//
//    return msg;
//}

MSG CAPIEngine::Run()
{
    //dc를 얻는다
    // GetDC ~ ReleaseDC는 어디서나 호출가능한 dc관련 window api함수이다.
    //      <-- BeginPaint ~ EndPaint와는 다르다.
    mhDC = GetDC(mhWnd);

    //게임프로그램 생성부라고 가정한다
    OnCreate();

    //게임 프로그램에서는 윈도우 엑셀러레이터 기능이 굳이 필요없다.
    //HACCEL hAccelTable = LoadAccelerators(hInst, MAKEINTRESOURCE(IDC_WINAPIENGINE));

    MSG msg = { 0 };//메시지 데이터 를 나타내는 변수

    
    //게임 프로그램은 게임 세계를 항상 갱신하는 구조가 필요하다.
    //그런데 GetMessage 함수는 대기동작을 가지는 특징이 있으므로 이에 적합하지 않다.
    //메시지 큐에서 메시지를 가져오며 대기동작의 특징을 가지지 않는 window api 함수가 있다.
    //PeekMessage가 그것이다.
    //그러므로 이것을 사용하여 구조를 변경하자.


    //게임루프까지 고려한 메시지를 루프를 작성하였다. <--- game loop pattern이 적용됨
    while (WM_QUIT != msg.message)
    {
        //메시지 큐에 메시지가 없어도 대기하지 않는다
        // 메시지가 있다면 메시지를 가져오고 true를 리턴한다
        //          <--메시지의 값을 가져온 후에는 큐에서 메시지를 삭제한다(PM_REMOVE)
        // 메시지가 없다면 즉시 false를 리턴한다
        if (PeekMessage(&msg, nullptr, 0 ,0, PM_REMOVE))//<---window program
        {
            //이 문단으로 오면, 처리해야할 윈도우 메시지가 있다는 것이다.
            //--윈도우 데스크탑 응용프로그램 구조에 대한 처리를 하는 구간--
            //if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            //
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            //}
        }
        else//<---game program
        {
            //이 문단으로 오면, 처리해야할 윈도우 메시지가 없다는 것이다.
            //윈도우 응용프로그램 입장에서 봤을 때 이곳은 Idle Time 유휴 시간 구역이다.
            //--게임 프로그램 구조에 대한 처리를 하는 구간--
            OnUpdate();


        }


    }


    //게임프로그램 해제부라고 가정한다
    OnDestroy();


    //dc를 해제한다
    ReleaseDC(mhWnd, mhDC);

    return msg;
}



void CAPIEngine::OnCreate()
{
    WCHAR szTemp[256] = { 0 };
    wsprintf(szTemp, L"CAPIEngine::OnCreate\n"); //wsprintf 유니코드용 문자열 출력
    OutputDebugString(szTemp);//출력 a: 아스키코드 w:유니코드
}
void CAPIEngine::OnDestroy()
{
    WCHAR szTemp[256] = { 0 };
    wsprintf(szTemp, L"CAPIEngine::OnDestroy\n"); 
    OutputDebugString(szTemp);
}
void CAPIEngine::OnUpdate()
{
    //OutputDebugString(L"CAPIEngine::OnUpdate\n");
    
    //BeginPaint~EndPaint짝은 WM_PAINT메시지 처리부에서만 유효하다.
    //그러므로 여기서는 사용불가이다.

    //문자열 출력 window api 함수
    TextOut(mhDC, 0, 0, L"I am a boy.", 11);
    TextOut(mhDC, 0, 25, L"안녕하세요.여상민입니다.", 13);
    TextOut(mhDC, 0, 50, TEXT("안녕하세요.여상민입니다."), 13);

    //사각형 출력 window api 함수
    Rectangle(mhDC, 200, 200, 200 + 100, 200 + 50);

    //타원 출력 window api 함수
    Ellipse(mhDC, 400, 100, 400 + 100, 100 + 70);

    //선분 그리기
    MoveToEx(mhDC, 350, 200, NULL);  //<-- 첫번째 정점의 위치를 잡아준다.
    LineTo(mhDC, 450, 300);
    LineTo(mhDC, 600, 300);

    MoveToEx(mhDC, 550, 200, NULL);
    LineTo(mhDC, 600, 300);

    //실행해보면 깜빡이는데 그건 window에 맞춰져 있기 때문이다. window에서 사용할 것을
    //게임에 적용하다보니 그렇다.
}







ATOM CAPIEngine::MyRegisterClass(HINSTANCE  hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPIENGINE));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPIENGINE);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}
BOOL CAPIEngine::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    //멤버변수에 기억시켜둠
    mhWnd = hWnd;

    //여기까지 오면, 눈에 보이는 윈도우가 만들어진 것이다.
    //이렇게 만들어진 윈도우의 크기를 조정하자.

    //window api에서 제공하는 사각영역 구조체
    RECT tRect = {0,0,800,600};

    //이 함수는 타이틀바, 메뉴 등을 고려하여 윈도우 크기를 나타내는 사각영역의 크기를 다시 조정해준다.
    AdjustWindowRect(&tRect, WS_OVERLAPPEDWINDOW, FALSE);//FALSE: 메뉴는 고려하지 않는다

    //윈도우의 위치를 지정하는 함수
    //윈도우 크기를 조정한다.

    //HWND_TOPMOST: 모든 창에 최상위창으로 띄운다.
    SetWindowPos(hWnd, HWND_TOPMOST, 100, 100,
        tRect.right-tRect.left, tRect.bottom-tRect.top,//너비,높이
        SWP_NOMOVE|SWP_NOZORDER);//SWP SetWindowPos의 의미의 접두사
    //SWP_NOMOVE 현재 위치에서 이동 안함 <-- 원래 위치를 유지
    //SWP_NOZORDER 겹쳐있는 경우 윈도우 순서에 대한 정보를 고려하지 않겠다




    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}
LRESULT CALLBACK CAPIEngine::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT://<--WM-PAINT윈도우 메시지 처리부에서 다음 출력들을 행하였다.
        //<-- 즉, 윈도우응용프로그램의 동작에 따라 구현하였다.
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);        //dc를 얻는다( dc: 그리기 장치가 추상화된 개념이다 )
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

        ////문자열 출력 window api 함수
        //TextOut(hdc, 0, 0, L"I am a boy.", 11);
        //TextOut(hdc, 0, 25, L"안녕하세요.여상민입니다.", 13);
        //TextOut(hdc, 0, 50, TEXT("안녕하세요.여상민입니다."), 13);

        ////사각형 출력 window api 함수
        //Rectangle(hdc, 200, 200, 200 + 100, 200 + 50);

        ////타원 출력 window api 함수
        //Ellipse(hdc, 400, 100, 400 + 100, 100 + 70);

        ////선분 그리기
        //MoveToEx(hdc, 350, 200, NULL);  //<-- 첫번째 정점의 위치를 잡아준다.
        //LineTo(hdc, 450, 300);
        //LineTo(hdc, 600, 300);

        //MoveToEx(hdc, 550, 200, NULL);
        //LineTo(hdc, 600, 300);





        EndPaint(hWnd, &ps);            //dc를 반환한다
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
INT_PTR CALLBACK CAPIEngine::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}