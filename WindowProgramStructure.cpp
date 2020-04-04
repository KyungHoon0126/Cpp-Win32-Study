#include <Windows.h>
#include <TCHAR.h>

// �޽��� ó�� �Լ�
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

// ���� �κ�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	// hInstance : ���α׷��� Ŀ���� �ο��ϴ� ID
	// hPrevInstance : ������ �ο����� ��, ������ ��� X
	// szCmdLine : char *, ���ڿ��� �Ѿ�´ٴ� ��.
	// iCmdShow : ���������� �����찡 ȭ�鿡 ��µ� �� ���� ����.


	HWND hwnd;
	MSG msg;


	// �� ������ Ŭ���� ���� ��
	WNDCLASSEX wndClass; // ������ Ŭ���� Ÿ���� WNDCLASSEX�� ������ ����� �� �ʵ忡 �� �ο�.
	wndClass.cbSize = sizeof(wndClass); // WNDCLASSEX ����ü ũ��, sizeof(WNDCLASSEX) �̷��Ե� ��� ����.
	wndClass.style = CS_HREDRAW || CS_VREDRAW; // ������ �������, ������ ũ�� ����� �ٽ� �׸��� ������ ������.
	wndClass.lpfnWndProc = WndProc; // �޽��� ó���� ���� �Լ� ���.
	wndClass.cbClsExtra = 0; // Ŭ���� ���� �޸�
	wndClass.cbWndExtra = 0; // ������ ���� �޸�
	wndClass.hInstance = hInstance; // WinMain() �Լ��� ù ��° �Ű������� �Ѿ�� �������α׷��� �ν��Ͻ��� ��, ������ �ν��Ͻ� -> HANDLE(�ڵ�)
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // ������ ����
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // Ŀ�� ����

	// wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ������ ���� ����.
	wndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(126, 64, 255));

	wndClass.lpszMenuName = NULL; // �޴� �̸�
	wndClass.lpszClassName = _T("ClassNameEx"); // ������ Ŭ���� �̸�, _T() : ������Ʈ���� ����ϴ� ���������� ��Ƽ����Ʈ�� �����ڵ�� ������� ó���ϱ����� ���.
	wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION); // ���� ������ ����


	// �� ������ Ŭ���� ��� ��
	RegisterClassEx(&wndClass); // ������ ���� ������ Ŭ������ RegisterClassEx() �Լ��� �̿��� Ŀ�ο� ����Ѵ�.


	// �� ������ ���� ��
	hwnd = CreateWindow(			// ������ �ڵ� �� ��ȯ
		_T("ClassNameEx"),			// ������ Ŭ���� �̸�, �����ڵ� ��ȯ�� ���� ��ũ�� _T() ��� 
		_T("Window Title Name"),	// ������ Ÿ��Ʋ �̸�
		WS_OVERLAPPEDWINDOW,		// ������ ��Ÿ��
		CW_USEDEFAULT,				// ��ġ x ��ǥ
		CW_USEDEFAULT,				// ��ġ y ��ǥ
		CW_USEDEFAULT,				// ������ ���� ũ��
		CW_USEDEFAULT,				// ������ ���� ũ��
		NULL,						// �θ� ������ �ڵ�
		NULL,						// �޴� �ڵ�
		hInstance,					// ���� ���α׷� �ν��Ͻ� 
		NULL						// ���� ������ ����
	);


	// �� ������ ȭ�� ��� ��
	ShowWindow(hwnd, iCmdShow); // hwnd : ��Ÿ�� ������ �ڵ� ��, iCmdShow : �����츦 ȭ�鿡 ��Ÿ���� ���.
	UpdateWindow(hwnd); // ������ ȭ�� �⺻ ���


	// �� �޽��� ó�� ��
	// GetMessage() �Լ��� �޽��� ť���� �޽����� ������, ���� �޽����� msg ������ �����Ѵ�.
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// TranslateMessage() �Լ��� ���� �� �� �޽����� �ϳ��� ������ �� �̿�
		TranslateMessage(&msg);

		// �޽����� ó���ϴ� �Լ��� �޽����� ������.
		DispatchMessage(&msg);
	}
}


// �޽��� ó�� �κ�
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// hwnd : ������ �������� �ڵ� ��
	// iMsg : �޽��� ��ȣ

	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	} // ó���� �޽����� case ���� ����, �������� Ŀ���� ó���ϵ��� DefWindowProc() �Լ��� ó��.

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}