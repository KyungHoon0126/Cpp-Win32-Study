#include <windows.h>

// ������ Ŭ���� : �������� �Ӽ� ���� ������ ����ϴ� ����ü, 12���� �ʵ�� ����

typedef struct _WNDCLASSEX {
	UINT		cbSize;			// ����ü ũ��
	UINT		style;			// ��� ����
	WNDPROC		lpfnWndProc;	// ���ν��� �Լ�
	int		    cbClsExtra;		// Ŭ���� ���� �޸�
	int			cbWndExtra;		// ������ ���� �޸�
	HANDLE		hInstance;		// ������ �ν��Ͻ�
	HICON		hIcon;			// ������
	HCURSOR		hCursor;		// Ŀ��
	HBRUSH		hbrBackground;	// ��� ��
	LPCTSTR		lpszMenuName;	// �޴� �̸�
	LPCTSTR		lpszClassName;	// Ŭ���� �̸�
	HICON		hIconSm;		// ���� ������
} WNDCLASSEX;