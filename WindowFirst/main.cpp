
/*
	Window API Programming

	������ ���α׷����� ���� �ΰ��� �� ������ ���߰ڴ�.

	i) '�ֿ��� window api' ���� ����غ���.
	ii) ���� ���α׷��� �ʿ��� '�ֿ� ���α׷� ����'���� �ۼ��غ���.



	-----------------------------------------
	API Appilication Programming Interface
	<-- ���α׷��� �ۼ��ϴ� �� �ʿ��� ����ü, �Լ�������

	window api�� C�� ������� ���������.



*/

#include <Windows.h>


//step_0
//<----------------- '������ ����ũž �������α׷�'�� ������(������)�� WinMain�Լ��� �����̴�.

/*
hInstance:������ �������α׷��� �ĺ��ڷμ��� �ڵ�, <---���� ������ ������� ��� ����. ex)ũ���̶�� �ٸ��Ŷ� �� ����
hPrevInstance: �� �����찡 ������� ���� �������� �ڵ�
lpCmdLine: �������α׷� ����� �������� ���ڿ�( Ŀ�ǵ���� ���� )
nCmdShow: �����츦 ������ ���� ����

<--�ü���� �Ѱ��ش�

*/


//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//	return 0;
//}



/*

 
    h: Handle �̶�� �ǹ��� ���λ�

	�� ������ �����ϴ� ������ 
	������ �ü�����ʹ� ������ ����dos�ʹ� �޸� 
	'��Ƽ �½�ŷmulti tasking'�� �����ϱ� �����̴�.
	��, �ü���� ��ǻ���� ��� �ڿ��� �����ϰ�
	�������α׷��� �ü�����Լ� �̷� �ڿ��� ���� �������� ������� ��� �����̴�.

	�ü�� �ý����� �����ϴ� �ڿ��� ���� �����Ͽ� ������ �� �����Ƿ�
	�ڿ�resource�� ���� ������ �ü�� �ý��� 'Ŀ�� kernal��� ����'���� �ϰ�
	�������α׷� �ڵ�� �� Ŀ���� ����ϴ� ������� handle�� ������ Ŀ�ο��� ��� ��û�ϸ�
	'���� user��� ����'���� �����Ѵ� 
	��� ���� �ȴ�.

	<-- ��, '�ڵ�handle' �̶� ������ �ڿ��� �ĺ���(�����)�̴�.
	





 
	LPWSTR: 

		LP: long pointer: ������ ��â�⿡ 2byte¥�� ������ ������ short pointer, 4byte¥�� ������ ������ long pointer�� �ٷ� �����̴�.
		W: wide <-- �����ڵ�(��Ƽ����Ʈ) ���������� ��Ÿ����. �����ڵ�: 2����Ʈ¥�� ���� ������ ���� ǥ�⸦ ���� �ѱ��� 10000�ڷ� ǥ��, 2^16 =65000��
		STR: string ���ڿ�


	<-- �����ڵ� C��Ÿ�� ���ڿ� ���

	���λ� ���̴°� �밡���� ǥ���


*/


//step_1
//<----------------- ������ Ŭ���� window class

/*
	������ Ŭ���� window class<--�� Ŭ������ ��ü�� ����� Ŭ���� ������ �ƴϴ�.
	<-- ������鿡�� ����� ������������ �����ϱ����� ������� �����̴�.(ũ�ҿ��� ��âǥ��, ���� �� �� ������ ���Գ���)


	�̸��׸�, ���´� ����, �����͸� �ٸ� ��������� ���
	�̷��� ������ Ŭ���� ������ ���������ν� ���� �޸� �������� ȿ�������� ���� �����ϴ�.
	�̷��� ������ ó���� ������� �����̴�.

	�׸��� �̷��� ������ Ŭ���� ������
	������ �ü���� ��ϵǾ�
	�ü���� �����ϰ� �ȴ�.

*/



//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//
//	//������ Ŭ���� ������ �����, �����ϰ�, ����Ѵ�.
//	WNDCLASSEXW wcex;
//
//	wcex.cbSize = sizeof(WNDCLASSEX);//������ Ŭ���� ���� ũ��
//
//	wcex.style = CS_HREDRAW | CS_VREDRAW;//������ ���μ��� ũ�Ⱑ ����Ǹ� �ٽ� ���ſɼ�
//	wcex.lpfnWndProc = nullptr;		//lpfn: long pointer function �Լ�������
//	wcex.cbClsExtra = 0;		//������ Ŭ������ ���� �������� �غ�� �޸� ũ��
//	wcex.cbWndExtra = 0;		//�����츦 ���� �������� �غ�� �޸� ũ��
//	wcex.hInstance = hInstance; //���� ������ ������� ����.
//	wcex.hIcon = LoadIcon(hInstance, nullptr);
//	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wcex.lpszMenuName = nullptr;
//	wcex.lpszClassName = L"szWindowClass"; //������ Ŭ���� ������ �ĺ���
//	wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr);
//
//
//	//lpsz: long pointer string zero C��Ÿ�� ���ڿ�
//	// �����ڵ� C��Ÿ�� ���ڿ� ����� ǥ���� ���� �տ� L�� �ٿ��ش�.
//
//	//�ü���� ������ Ŭ���� ������ ���
//	RegisterClassExW(&wcex);
//
//	return 0;
//}


//step_2
//<------------------- ������ ����
//					( �ڵ尡 ���� �������� �����Ƿ� �� ���ܿ����� ���� ������ �߻���ų ���̴�.)
//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//
//	//������ Ŭ���� ������ �����, �����ϰ�, ����Ѵ�.
//	WNDCLASSEXW wcex;
//
//	wcex.cbSize = sizeof(WNDCLASSEX);//������ Ŭ���� ���� ũ��
//
//	wcex.style = CS_HREDRAW | CS_VREDRAW;//������ ���μ��� ũ�Ⱑ ����Ǹ� �ٽ� ���ſɼ�
//	wcex.lpfnWndProc = nullptr;		//lpfn: long pointer function �Լ�������
//	wcex.cbClsExtra = 0;		//������ Ŭ������ ���� �������� �غ�� �޸� ũ��
//	wcex.cbWndExtra = 0;		//�����츦 ���� �������� �غ�� �޸� ũ��
//	wcex.hInstance = hInstance; //���� ������ ������� ����.
//	wcex.hIcon = LoadIcon(hInstance, nullptr);
//	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wcex.lpszMenuName = nullptr;
//	wcex.lpszClassName = L"szWindowClass"; //������ Ŭ���� ������ �ĺ���
//	wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr);
//
//
//	//lpsz: long pointer string zero C��Ÿ�� ���ڿ�
//	// �����ڵ� C��Ÿ�� ���ڿ� ����� ǥ���� ���� �տ� L�� �ٿ��ش�.
//
//	//�ü���� ������ Ŭ���� ������ ���
//	RegisterClassExW(&wcex);
//
//
//
//
//
//	
//	//������ ���� window api �Լ�
//	//CreateWindowW �� window handle�� �����Ѵ�.
//	//���� ���̴� �����찡 �����ȴ�.
//	HWND hWnd = CreateWindowW(L"szWindowClass", L"szWindow", WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//	//HWND 
//	//������ �ڵ� CreateWindowW
//	//������ �������α׷��� �ĺ���
//	//hWnd�� ������ ���� ��� �ٸ���( �ݸ鿡 hInstance�� ������ ������ ���ٸ� ���� )
//
//	//WS_OVERLAPPEDWINDOW�� ���� ������ ��Ÿ���� �̸� �����ص� ��Ÿ���̴�.
//
//	//CW_ CreateWindow
//	
//	//WS_ WindowStyle
//
//	//������ ���̱� api
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);//������ ���� api
//
//
//
//
//
//
//	return 0;
//}



//step_3
//<------------------------- �޽���, �޽�������, ������ ���ν���
// 

//�ü���� ȣ���Ѵ�.
//������ ���ν��� �Լ�: �޽��� ó���� ����� �Լ�
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		//WM_ Window Message
	case WM_PAINT:		//������ �׸��⿡ ���� �޽��� ó��
	{
		PAINTSTRUCT ps;
		//BeginPaint, EndPaint ¦�� WM_PAINT�޽��� ó���ο����� ��밡���ϴ�.
		HDC hdc = BeginPaint(hWnd, &ps);
		//device context �� ��� api�Լ��̴�.
		// graphic device context �׸��⿡ ���õ� ��ġ�� �߻�ȭ�� ����(��ġ, ��ġ�� ������, ��ġ�� ���°�)
		// TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
		EndPaint(hWnd, &ps);//device context�� �ٽ� �����ִ� api�Լ��̴�.


		//<--�ڿ��� ȹ���Ͽ� ����� �������� �ݵ�� ��ȯ�Ѵٴ� ����
	}
	break;
	case WM_DESTROY:	//������ ���� �� ���� �޽��� ó��
		PostQuitMessage(0);//���α׷� ���� api�Լ�
		/*
		    Send~		���(����)�Լ�
			Post~		����(�񵿱�)�Լ�

			����sync: �ڵ��� ����ñ�� ���� ���α׷��� ����ñⰡ ��ġ�ϴ� ��
			�񵿱� async: �ڵ��� ����ñ�� ���� ���α׷��� ����ñⰡ ��ġ���� �ʴ� ��
		*/
		break;
	default:		//<-- �⺻�� �̰����� ó���Ѵ�. 
					//��, ���� ����� ���ǵ� case�� �ش����� �ʴ�
					//������ �޽������� ���⿡�� ó���ȴ�.
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{

	//������ Ŭ���� ������ �����, �����ϰ�, ����Ѵ�.
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);//������ Ŭ���� ���� ũ��

	wcex.style = CS_HREDRAW | CS_VREDRAW;//������ ���μ��� ũ�Ⱑ ����Ǹ� �ٽ� ���ſɼ�
	//wcex.lpfnWndProc = nullptr;		//lpfn: long pointer function �Լ�������
	wcex.lpfnWndProc = WndProc;			//������ �޽������� ó���� ������ ���ν����� ����Ѵ�
	wcex.cbClsExtra = 0;		//������ Ŭ������ ���� �������� �غ�� �޸� ũ��
	wcex.cbWndExtra = 0;		//�����츦 ���� �������� �غ�� �޸� ũ��
	wcex.hInstance = hInstance; //���� ������ ������� ����.
	wcex.hIcon = LoadIcon(hInstance, nullptr);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"szWindowClass"; //������ Ŭ���� ������ �ĺ���
	wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr);


	//lpsz: long pointer string zero C��Ÿ�� ���ڿ�
	// �����ڵ� C��Ÿ�� ���ڿ� ����� ǥ���� ���� �տ� L�� �ٿ��ش�.

	//�ü���� ������ Ŭ���� ������ ���
	RegisterClassExW(&wcex);



	//������ ���� window api �Լ�
	//CreateWindowW �� window handle�� �����Ѵ�.
	//���� ���̴� �����찡 �����ȴ�.
	HWND hWnd = CreateWindowW(L"szWindowClass", L"Window", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	//<--���� ���⼭ ������ ���� ������ WM_CREATE�޽����� ó���� ������ ���ν����� �������� �ʾұ� �����̴�.


	//HWND 
	//������ �ڵ� CreateWindowW
	//������ �������α׷��� �ĺ���
	//hWnd�� ������ ���� ��� �ٸ���( �ݸ鿡 hInstance�� ������ ������ ���ٸ� ���� )

	//WS_OVERLAPPEDWINDOW�� ���� ������ ��Ÿ���� �̸� �����ص� ��Ÿ���̴�.

	//CW_ CreateWindow

	//WS_ WindowStyle

	//������ ���̱� api
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);//������ ���� api


	//������������ �� �ε�
	HACCEL hAccelTable = LoadAccelerators(hInstance, nullptr);

	MSG msg;

	// �⺻ '�޽��� ����'�Դϴ�:
	//
	// GetMessage �� 
	// ����Լ�blocked( �����Լ� sync)
	//<-- �޽���ť�� �޽����� ������ �� �Լ��� ȣ���������� ������ �帧�� �����
	while (GetMessage(&msg, nullptr, 0, 0))//<--�޽���ť���� �޽����� �ϳ� ��´�(�����´�)
	{
		//���� ����Ű �ؼ��� ������ �켱�Ѵ�
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);//<--�޽����� �ؼ��Ѵ�
			DispatchMessage(&msg);//<--'�޽����� ó���� �Լ�'���� �޽����� �����ش�.
		}
	}

	/*
		����dos �ʹ� �޸�											CUI >>> GUI
		window�ü���� ��Ƽ�½�ŷ�� �����Ѵ�.
		<--�̸� �����ϱ� ���� ������� ���� �޽��� �̴�.

		�׸��� �̷��� �޽����� ������� ���α׷��� �����ϴ� ���� 
		'�޽��� �帮�� message driven'�̴�.
		'������� �޽��� �帮�� ������� ����'�Ѵ�.



		���� �������α׷��� ����?�� ����Ǵ� ������
		�ٷ� ��Ƽ �½�ŷ�ε�
		�̷��� ������ �����ϱ� ����
		������ ������ '�������α׷��� �ĺ���, �ؾ��� ��, ���� ������' ���� ����Ͽ�
		'�޽���message'�� �����
		�̷��� �޽����� '�޽���ťmessage queue'�� ����ְ�
		�������� '������' '�ؼ�'�ϰ�
		�������� '�˸���  ���� ó���ϵ���' ������� �ִ�.

	*/















	return 0;
}





