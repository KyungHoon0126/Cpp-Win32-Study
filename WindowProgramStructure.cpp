#include <Windows.h>
#include <TCHAR.h>

// 메시지 처리 함수
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

// 메인 부분
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	// hInstance : 프로그램에 커널이 부여하는 ID
	// hPrevInstance : 이전에 부여받은 값, 지금은 사용 X
	// szCmdLine : char *, 문자열이 넘어온다는 것.
	// iCmdShow : 정숫값으로 윈도우가 화면에 출력될 때 형태 정의.


	HWND hwnd;
	MSG msg;


	// ※ 윈도우 클래스 생성 ※
	WNDCLASSEX wndClass; // 윈도우 클래스 타입인 WNDCLASSEX의 변수를 만들고 각 필드에 값 부여.
	wndClass.cbSize = sizeof(wndClass); // WNDCLASSEX 구조체 크기, sizeof(WNDCLASSEX) 이렇게도 사용 가능.
	wndClass.style = CS_HREDRAW || CS_VREDRAW; // 윈도우 출력형태, 윈도우 크기 변경시 다시 그리는 형태의 윈도우.
	wndClass.lpfnWndProc = WndProc; // 메시지 처리에 사용될 함수 등록.
	wndClass.cbClsExtra = 0; // 클래스 여분 메모리
	wndClass.cbWndExtra = 0; // 윈도우 여분 메모리
	wndClass.hInstance = hInstance; // WinMain() 함수에 첫 번째 매개변수로 넘어온 응용프로그램의 인스턴스의 값, 윈도우 인스턴스 -> HANDLE(핸들)
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // 아이콘 지정
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // 커서 지정

	// wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // 윈도우 배경색 지정.
	wndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(126, 64, 255));

	wndClass.lpszMenuName = NULL; // 메뉴 이름
	wndClass.lpszClassName = _T("ClassNameEx"); // 윈도우 클래스 이름, _T() : 프로젝트에서 사용하는 문자집합이 멀티바이트든 유니코드든 상관없이 처리하기위해 사용.
	wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION); // 작은 아이콘 지정


	// ※ 윈도우 클래스 등록 ※
	RegisterClassEx(&wndClass); // 위에서 만든 윈도우 클래스는 RegisterClassEx() 함수를 이용해 커널에 등록한다.


	// ※ 윈도우 생성 ※
	hwnd = CreateWindow(			// 윈도우 핸들 값 반환
		_T("ClassNameEx"),			// 윈도우 클래스 이름, 유니코드 변환을 위한 매크로 _T() 사용 
		_T("Window Title Name"),	// 윈도우 타이틀 이름
		WS_OVERLAPPEDWINDOW,		// 윈도우 스타일
		CW_USEDEFAULT,				// 위치 x 좌표
		CW_USEDEFAULT,				// 위치 y 좌표
		CW_USEDEFAULT,				// 윈도우 가로 크기
		CW_USEDEFAULT,				// 윈도우 세로 크기
		NULL,						// 부모 윈도우 핸들
		NULL,						// 메뉴 핸들
		hInstance,					// 응용 프로그램 인스턴스 
		NULL						// 생성 윈도우 정보
	);


	// ※ 윈도우 화면 출력 ※
	ShowWindow(hwnd, iCmdShow); // hwnd : 나타낼 윈도우 핸들 값, iCmdShow : 윈도우를 화면에 나타내는 방법.
	UpdateWindow(hwnd); // 윈도우 화면 기본 출력


	// ※ 메시지 처리 ※
	// GetMessage() 함수가 메시지 큐에서 메시지를 꺼내고, 꺼낸 메시지는 msg 변수에 저장한다.
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// TranslateMessage() 함수로 변형 → 두 메시지를 하나로 변형할 때 이용
		TranslateMessage(&msg);

		// 메시지를 처리하는 함수에 메시지를 보낸다.
		DispatchMessage(&msg);
	}
}


// 메시지 처리 부분
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// hwnd : 생성된 윈도우의 핸들 값
	// iMsg : 메시지 번호

	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	} // 처리할 메시지만 case 문에 나열, 나머지는 커널이 처리하도록 DefWindowProc() 함수로 처리.

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}