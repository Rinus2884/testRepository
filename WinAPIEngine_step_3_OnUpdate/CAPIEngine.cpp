#include "CAPIEngine.h"

#include "Resource.h"

//static�����̹Ƿ� ������������ �ʱ�ȭ
HINSTANCE CAPIEngine::hInst = nullptr;





CAPIEngine::CAPIEngine()
{
    //�޸� �ʱ�ȭ
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
//    //�������α׷� �����ζ�� �����Ѵ�
//    OnCreate();
//
//
//
//    HACCEL hAccelTable = LoadAccelerators(hInst, MAKEINTRESOURCE(IDC_WINAPIENGINE));
//
//    MSG msg;//�޽��� ������ �� ��Ÿ���� ����
//
//    //�ϴ� �̰��� ���ӷ������ ����
//    // �⺻ �޽��� �����Դϴ�:
//    /*
//        �޽��� ť���� �޽����� ��´�
//          ������������ ó���� �켱���� �Ѵ�
//          �޽����� �ؼ��Ѵ�
//          �޽����� ���������ν����� ó���� �� �ֵ��� ����ġ���ش�.
//    */
//    while (GetMessage(&msg, nullptr, 0, 0))//�޽��� ť�� �޽����� ������ ����Ѵ�.
//    {
//        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//        {
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//        }
//    }
//
//
//    //�������α׷� �����ζ�� �����Ѵ�
//    OnDestroy();
//
//    return msg;
//}

MSG CAPIEngine::Run()
{
    //dc�� ��´�
    // GetDC ~ ReleaseDC�� ��𼭳� ȣ�Ⱑ���� dc���� window api�Լ��̴�.
    //      <-- BeginPaint ~ EndPaint�ʹ� �ٸ���.
    mhDC = GetDC(mhWnd);

    //�������α׷� �����ζ�� �����Ѵ�
    OnCreate();

    //���� ���α׷������� ������ ������������ ����� ���� �ʿ����.
    //HACCEL hAccelTable = LoadAccelerators(hInst, MAKEINTRESOURCE(IDC_WINAPIENGINE));

    MSG msg = { 0 };//�޽��� ������ �� ��Ÿ���� ����

    
    //���� ���α׷��� ���� ���踦 �׻� �����ϴ� ������ �ʿ��ϴ�.
    //�׷��� GetMessage �Լ��� ��⵿���� ������ Ư¡�� �����Ƿ� �̿� �������� �ʴ�.
    //�޽��� ť���� �޽����� �������� ��⵿���� Ư¡�� ������ �ʴ� window api �Լ��� �ִ�.
    //PeekMessage�� �װ��̴�.
    //�׷��Ƿ� �̰��� ����Ͽ� ������ ��������.


    //���ӷ������� ����� �޽����� ������ �ۼ��Ͽ���. <--- game loop pattern�� �����
    while (WM_QUIT != msg.message)
    {
        //�޽��� ť�� �޽����� ��� ������� �ʴ´�
        // �޽����� �ִٸ� �޽����� �������� true�� �����Ѵ�
        //          <--�޽����� ���� ������ �Ŀ��� ť���� �޽����� �����Ѵ�(PM_REMOVE)
        // �޽����� ���ٸ� ��� false�� �����Ѵ�
        if (PeekMessage(&msg, nullptr, 0 ,0, PM_REMOVE))//<---window program
        {
            //�� �������� ����, ó���ؾ��� ������ �޽����� �ִٴ� ���̴�.
            //--������ ����ũž �������α׷� ������ ���� ó���� �ϴ� ����--
            //if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            //
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            //}
        }
        else//<---game program
        {
            //�� �������� ����, ó���ؾ��� ������ �޽����� ���ٴ� ���̴�.
            //������ �������α׷� ���忡�� ���� �� �̰��� Idle Time ���� �ð� �����̴�.
            //--���� ���α׷� ������ ���� ó���� �ϴ� ����--
            OnUpdate();


        }


    }


    //�������α׷� �����ζ�� �����Ѵ�
    OnDestroy();


    //dc�� �����Ѵ�
    ReleaseDC(mhWnd, mhDC);

    return msg;
}



void CAPIEngine::OnCreate()
{
    WCHAR szTemp[256] = { 0 };
    wsprintf(szTemp, L"CAPIEngine::OnCreate\n"); //wsprintf �����ڵ�� ���ڿ� ���
    OutputDebugString(szTemp);//��� a: �ƽ�Ű�ڵ� w:�����ڵ�
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
    
    //BeginPaint~EndPaint¦�� WM_PAINT�޽��� ó���ο����� ��ȿ�ϴ�.
    //�׷��Ƿ� ���⼭�� ���Ұ��̴�.

    //���ڿ� ��� window api �Լ�
    TextOut(mhDC, 0, 0, L"I am a boy.", 11);
    TextOut(mhDC, 0, 25, L"�ȳ��ϼ���.������Դϴ�.", 13);
    TextOut(mhDC, 0, 50, TEXT("�ȳ��ϼ���.������Դϴ�."), 13);

    //�簢�� ��� window api �Լ�
    Rectangle(mhDC, 200, 200, 200 + 100, 200 + 50);

    //Ÿ�� ��� window api �Լ�
    Ellipse(mhDC, 400, 100, 400 + 100, 100 + 70);

    //���� �׸���
    MoveToEx(mhDC, 350, 200, NULL);  //<-- ù��° ������ ��ġ�� ����ش�.
    LineTo(mhDC, 450, 300);
    LineTo(mhDC, 600, 300);

    MoveToEx(mhDC, 550, 200, NULL);
    LineTo(mhDC, 600, 300);

    //�����غ��� �����̴µ� �װ� window�� ������ �ֱ� �����̴�. window���� ����� ����
    //���ӿ� �����ϴٺ��� �׷���.
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
    hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    //��������� �����ѵ�
    mhWnd = hWnd;

    //������� ����, ���� ���̴� �����찡 ������� ���̴�.
    //�̷��� ������� �������� ũ�⸦ ��������.

    //window api���� �����ϴ� �簢���� ����ü
    RECT tRect = {0,0,800,600};

    //�� �Լ��� Ÿ��Ʋ��, �޴� ���� ����Ͽ� ������ ũ�⸦ ��Ÿ���� �簢������ ũ�⸦ �ٽ� �������ش�.
    AdjustWindowRect(&tRect, WS_OVERLAPPEDWINDOW, FALSE);//FALSE: �޴��� ������� �ʴ´�

    //�������� ��ġ�� �����ϴ� �Լ�
    //������ ũ�⸦ �����Ѵ�.

    //HWND_TOPMOST: ��� â�� �ֻ���â���� ����.
    SetWindowPos(hWnd, HWND_TOPMOST, 100, 100,
        tRect.right-tRect.left, tRect.bottom-tRect.top,//�ʺ�,����
        SWP_NOMOVE|SWP_NOZORDER);//SWP SetWindowPos�� �ǹ��� ���λ�
    //SWP_NOMOVE ���� ��ġ���� �̵� ���� <-- ���� ��ġ�� ����
    //SWP_NOZORDER �����ִ� ��� ������ ������ ���� ������ ������� �ʰڴ�




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
        // �޴� ������ ���� �м��մϴ�:
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
    case WM_PAINT://<--WM-PAINT������ �޽��� ó���ο��� ���� ��µ��� ���Ͽ���.
        //<-- ��, �������������α׷��� ���ۿ� ���� �����Ͽ���.
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);        //dc�� ��´�( dc: �׸��� ��ġ�� �߻�ȭ�� �����̴� )
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...

        ////���ڿ� ��� window api �Լ�
        //TextOut(hdc, 0, 0, L"I am a boy.", 11);
        //TextOut(hdc, 0, 25, L"�ȳ��ϼ���.������Դϴ�.", 13);
        //TextOut(hdc, 0, 50, TEXT("�ȳ��ϼ���.������Դϴ�."), 13);

        ////�簢�� ��� window api �Լ�
        //Rectangle(hdc, 200, 200, 200 + 100, 200 + 50);

        ////Ÿ�� ��� window api �Լ�
        //Ellipse(hdc, 400, 100, 400 + 100, 100 + 70);

        ////���� �׸���
        //MoveToEx(hdc, 350, 200, NULL);  //<-- ù��° ������ ��ġ�� ����ش�.
        //LineTo(hdc, 450, 300);
        //LineTo(hdc, 600, 300);

        //MoveToEx(hdc, 550, 200, NULL);
        //LineTo(hdc, 600, 300);





        EndPaint(hWnd, &ps);            //dc�� ��ȯ�Ѵ�
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