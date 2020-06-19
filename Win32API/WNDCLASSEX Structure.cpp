#include <windows.h>

// 윈도우 클래스 : 윈도우의 속성 값을 저장해 등록하는 구조체, 12개의 필드로 구성

typedef struct _WNDCLASSEX {
	UINT		cbSize;			// 구조체 크기
	UINT		style;			// 출력 형태
	WNDPROC		lpfnWndProc;		// 프로시저 함수
	int		cbClsExtra;		// 클래스 여분 메모리
	int		cbWndExtra;		// 윈도우 여분 메모리
	HANDLE		hInstance;		// 윈도우 인스턴스
	HICON		hIcon;			// 아이콘
	HCURSOR		hCursor;		// 커서
	HBRUSH		hbrBackground;		// 배경 색
	LPCTSTR		lpszMenuName;		// 메뉴 이름
	LPCTSTR		lpszClassName;		// 클래스 이름
	HICON		hIconSm;		// 작은 아이콘
} WNDCLASSEX;
