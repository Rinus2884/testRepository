
/*
	Window API Programming

	윈도우 프로그래밍은 다음 두가지 에 초점을 맞추겠다.

	i) '주요한 window api' 들을 사용해본다.
	ii) 게임 프로그램에 필요한 '주요 프로그램 구조'들을 작성해본다.



	-----------------------------------------
	API Appilication Programming Interface
	<-- 프로그램을 작성하는 데 필요한 구조체, 함수모음집

	window api는 C언어를 기반으로 만들어졌다.



*/

#include <Windows.h>


//step_0
//<----------------- '윈도우 데스크탑 응용프로그램'의 시작점(진입점)은 WinMain함수의 정의이다.

/*
hInstance:윈도우 응용프로그램의 식별자로서의 핸들, <---같은 윈도우 종류라면 모두 같다. ex)크롬이라면 다른거라도 다 같다
hPrevInstance: 이 윈도우가 만들어진 원래 윈도우의 핸들
lpCmdLine: 응용프로그램 실행시 전달해줄 문자열( 커맨드라인 인자 )
nCmdShow: 윈도우를 보일지 말지 여부

<--운영체제가 넘겨준다

*/


//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//	return 0;
//}



/*

 
    h: Handle 이라는 의미의 접두사

	이 개념이 존재하는 이유는 
	윈도우 운영체제부터는 이전에 도스dos와는 달리 
	'멀티 태스킹multi tasking'을 제공하기 때문이다.
	즉, 운영체제가 컴퓨터의 모든 자원을 관리하고
	응용프로그램은 운영체제에게서 이런 자원에 대한 간접적인 제어권을 얻는 구조이다.

	운영체제 시스템이 관리하는 자원에 직접 접근하여 참조할 수 없으므로
	자원resource의 실제 참조는 운영체제 시스템 '커널 kernal모드 수준'에서 하고
	응용프로그램 코드는 이 커널이 허용하는 제어권인 handle을 가지고 커널에게 제어를 요청하며
	'유저 user모드 수준'에서 동작한다 
	라고 보면 된다.

	<-- 즉, '핸들handle' 이란 임의의 자원의 식별자(제어권)이다.
	





 
	LPWSTR: 

		LP: long pointer: 윈도우 초창기에 2byte짜리 포인터 변수는 short pointer, 4byte짜리 포인터 변수는 long pointer로 다룬 잔재이다.
		W: wide <-- 유니코드(멀티바이트) 문자집합을 나타낸다. 유니코드: 2바이트짜리 문자 전세계 문자 표기를 위해 한글은 10000자로 표기, 2^16 =65000개
		STR: string 문자열


	<-- 유니코드 C스타일 문자열 상수

	접두사 붙이는것 헝가리안 표기법


*/


//step_1
//<----------------- 윈도우 클래스 window class

/*
	윈도우 클래스 window class<--이 클래스는 객체를 만드는 클래스 개념이 아니다.
	<-- 윈도우들에서 공통된 데이터집합을 관리하기위해 만들어진 개념이다.(크롬에서 새창표시, 종료 등 과 같은게 같게나옴)


	이를테면, 형태는 같고, 데이터만 다른 윈도우들의 경우
	이러한 윈도우 클래스 정보를 공유함으로써 보다 메모리 관점에서 효율적으로 동작 가능하다.
	이러한 이유로 처음에 만들어진 개념이다.

	그리고 이러한 윈도우 클래스 정보는
	윈도우 운영체제에 등록되어
	운영체제가 관리하게 된다.

*/



//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//
//	//윈도우 클래스 변수를 만들고, 설정하고, 등록한다.
//	WNDCLASSEXW wcex;
//
//	wcex.cbSize = sizeof(WNDCLASSEX);//윈도우 클래스 정보 크기
//
//	wcex.style = CS_HREDRAW | CS_VREDRAW;//윈도우 가로세로 크기가 변경되면 다시 갱신옵션
//	wcex.lpfnWndProc = nullptr;		//lpfn: long pointer function 함수포인터
//	wcex.cbClsExtra = 0;		//윈도우 클래스를 위해 여분으로 준비된 메모리 크기
//	wcex.cbWndExtra = 0;		//윈도우를 위해 여분으로 준비된 메모리 크기
//	wcex.hInstance = hInstance; //같은 종류의 윈도우면 같다.
//	wcex.hIcon = LoadIcon(hInstance, nullptr);
//	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wcex.lpszMenuName = nullptr;
//	wcex.lpszClassName = L"szWindowClass"; //윈도우 클래스 정보의 식별자
//	wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr);
//
//
//	//lpsz: long pointer string zero C스타일 문자열
//	// 유니코드 C스타일 문자열 상수를 표기할 때는 앞에 L을 붙여준다.
//
//	//운영체제에 윈도우 클래스 정보를 등록
//	RegisterClassExW(&wcex);
//
//	return 0;
//}


//step_2
//<------------------- 윈도우 생성
//					( 코드가 아직 완전하지 않으므로 이 스텝에서는 실행 에러를 발생시킬 것이다.)
//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//
//	//윈도우 클래스 변수를 만들고, 설정하고, 등록한다.
//	WNDCLASSEXW wcex;
//
//	wcex.cbSize = sizeof(WNDCLASSEX);//윈도우 클래스 정보 크기
//
//	wcex.style = CS_HREDRAW | CS_VREDRAW;//윈도우 가로세로 크기가 변경되면 다시 갱신옵션
//	wcex.lpfnWndProc = nullptr;		//lpfn: long pointer function 함수포인터
//	wcex.cbClsExtra = 0;		//윈도우 클래스를 위해 여분으로 준비된 메모리 크기
//	wcex.cbWndExtra = 0;		//윈도우를 위해 여분으로 준비된 메모리 크기
//	wcex.hInstance = hInstance; //같은 종류의 윈도우면 같다.
//	wcex.hIcon = LoadIcon(hInstance, nullptr);
//	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wcex.lpszMenuName = nullptr;
//	wcex.lpszClassName = L"szWindowClass"; //윈도우 클래스 정보의 식별자
//	wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr);
//
//
//	//lpsz: long pointer string zero C스타일 문자열
//	// 유니코드 C스타일 문자열 상수를 표기할 때는 앞에 L을 붙여준다.
//
//	//운영체제에 윈도우 클래스 정보를 등록
//	RegisterClassExW(&wcex);
//
//
//
//
//
//	
//	//윈도우 생성 window api 함수
//	//CreateWindowW 는 window handle을 리턴한다.
//	//눈에 보이는 윈도우가 생성된다.
//	HWND hWnd = CreateWindowW(L"szWindowClass", L"szWindow", WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//	//HWND 
//	//윈도우 핸들 CreateWindowW
//	//윈도우 응용프로그램의 식별자
//	//hWnd는 윈도우 마다 모두 다르다( 반면에 hInstance는 윈도우 종류가 같다면 같다 )
//
//	//WS_OVERLAPPEDWINDOW는 여러 윈도우 스타일을 미리 조합해둔 스타일이다.
//
//	//CW_ CreateWindow
//	
//	//WS_ WindowStyle
//
//	//윈도우 보이기 api
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);//윈도우 갱신 api
//
//
//
//
//
//
//	return 0;
//}



//step_3
//<------------------------- 메시지, 메시지루프, 윈도우 프로시저
// 

//운영체제가 호출한다.
//윈도우 프로시저 함수: 메시지 처리를 담당할 함수
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		//WM_ Window Message
	case WM_PAINT:		//윈도우 그리기에 관한 메시지 처리
	{
		PAINTSTRUCT ps;
		//BeginPaint, EndPaint 짝은 WM_PAINT메시지 처리부에서만 사용가능하다.
		HDC hdc = BeginPaint(hWnd, &ps);
		//device context 를 얻는 api함수이다.
		// graphic device context 그리기에 관련된 장치가 추상화된 개념(장치, 장치의 설정값, 장치의 상태값)
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		EndPaint(hWnd, &ps);//device context를 다시 돌려주는 api함수이다.


		//<--자원은 획득하여 사용이 끝났으면 반드시 반환한다는 개념
	}
	break;
	case WM_DESTROY:	//윈도우 종료 에 관한 메시지 처리
		PostQuitMessage(0);//프로그램 종료 api함수
		/*
		    Send~		대기(동기)함수
			Post~		비대기(비동기)함수

			동기sync: 코드의 진행시기와 실제 프로그램의 진행시기가 일치하는 것
			비동기 async: 코드의 진행시기와 실제 프로그램의 진행시기가 일치하지 않는 것
		*/
		break;
	default:		//<-- 기본은 이것으로 처리한다. 
					//즉, 위에 사용자 정의된 case에 해당하지 않는
					//윈도우 메시지들을 여기에서 처리된다.
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{

	//윈도우 클래스 변수를 만들고, 설정하고, 등록한다.
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);//윈도우 클래스 정보 크기

	wcex.style = CS_HREDRAW | CS_VREDRAW;//윈도우 가로세로 크기가 변경되면 다시 갱신옵션
	//wcex.lpfnWndProc = nullptr;		//lpfn: long pointer function 함수포인터
	wcex.lpfnWndProc = WndProc;			//윈도우 메시지들을 처리할 윈도우 프로시저를 등록한다
	wcex.cbClsExtra = 0;		//윈도우 클래스를 위해 여분으로 준비된 메모리 크기
	wcex.cbWndExtra = 0;		//윈도우를 위해 여분으로 준비된 메모리 크기
	wcex.hInstance = hInstance; //같은 종류의 윈도우면 같다.
	wcex.hIcon = LoadIcon(hInstance, nullptr);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"szWindowClass"; //윈도우 클래스 정보의 식별자
	wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr);


	//lpsz: long pointer string zero C스타일 문자열
	// 유니코드 C스타일 문자열 상수를 표기할 때는 앞에 L을 붙여준다.

	//운영체제에 윈도우 클래스 정보를 등록
	RegisterClassExW(&wcex);



	//윈도우 생성 window api 함수
	//CreateWindowW 는 window handle을 리턴한다.
	//눈에 보이는 윈도우가 생성된다.
	HWND hWnd = CreateWindowW(L"szWindowClass", L"Window", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	//<--현재 여기서 에러가 나는 이유는 WM_CREATE메시지를 처리할 윈도우 프로시저가 설정되지 않았기 때문이다.


	//HWND 
	//윈도우 핸들 CreateWindowW
	//윈도우 응용프로그램의 식별자
	//hWnd는 윈도우 마다 모두 다르다( 반면에 hInstance는 윈도우 종류가 같다면 같다 )

	//WS_OVERLAPPEDWINDOW는 여러 윈도우 스타일을 미리 조합해둔 스타일이다.

	//CW_ CreateWindow

	//WS_ WindowStyle

	//윈도우 보이기 api
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);//윈도우 갱신 api


	//엑셀러레이터 를 로드
	HACCEL hAccelTable = LoadAccelerators(hInstance, nullptr);

	MSG msg;

	// 기본 '메시지 루프'입니다:
	//
	// GetMessage 는 
	// 대기함수blocked( 동기함수 sync)
	//<-- 메시지큐에 메시지가 없으면 이 함수의 호출지점에서 실행의 흐름이 멈춘다
	while (GetMessage(&msg, nullptr, 0, 0))//<--메시지큐에서 메시지를 하나 얻는다(꺼내온다)
	{
		//먼저 단축키 해석과 실행을 우선한다
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);//<--메시지를 해석한다
			DispatchMessage(&msg);//<--'메시지를 처리할 함수'에게 메시지를 던져준다.
		}
	}

	/*
		도스dos 와는 달리											CUI >>> GUI
		window운영체제는 멀티태스킹을 지원한다.
		<--이를 지원하기 위해 만들어진 것이 메시지 이다.

		그리고 이러한 메시지를 기반으로 프로그램이 동작하는 것을 
		'메시지 드리븐 message driven'이다.
		'윈도우는 메시지 드리븐 방식으로 동작'한다.



		여러 응용프로그램이 동시?에 실행되는 형식이
		바로 멀티 태스킹인데
		이러한 실행을 지원하기 위해
		각각의 윈도우 '응용프로그램의 식별자, 해야할 일, 관련 데이터' 등을 기록하여
		'메시지message'를 만들고
		이러한 메시지를 '메시지큐message queue'에 집어넣고
		차례차례 '꺼내어' '해석'하고
		윈도우의 '알맞은  일을 처리하도록' 만들어져 있다.

	*/















	return 0;
}





