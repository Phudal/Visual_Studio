#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam);

//��Ʈ�� ����Ʈ
//APIENTRY �����ڴ� ������ ǥ�� ȣ�� �Ծ��� __stdcall�� ����Ѵٴ� �ǹ�

//�Լ� ȣ�� ��� (ȣ�� �Ծ�)
//__stdcall		: �Ű������� ������ ������ �Լ�	/ ũ�� �۴� / callee (��ȣ����) stack ����
//__cdecl		: �Ű������� ������ �������� �Լ� / ũ�� �۴� / caller (ȣ����) stack ����

//�Ű�����
//hInstace		:���α׷� �ν��Ͻ� �ڵ�
//hPrevInstance :������ �����Ų ���� ���α׷� �ν��Ͻ� �ڵ� (��� x)
//lpszCmdParam	:��������� �Էµ� ���α׷� �μ� (��� x)
//nCmdShow		:���α׷��� ���� �� ���� (��� x)

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	HWND			hWnd;			//������ �ڵ鷯
	MSG				Msg;			//������ �޼���
	WNDCLASS		WndClass;		//������ ����ü

									// 1. ������ Ŭ���� ����/�ʱ�ȭ
	WndClass.style = CS_HREDRAW | CS_VREDRAW;				//������ ��Ÿ�� ���� -- ����|���� �� �þ�� ������
	WndClass.cbClsExtra = 0;									//Ư���� �������� ���� ���� ����
	WndClass.cbWndExtra = 0;									//Ư���� �������� ���� ���� ����
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//������ ��� ����
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);			//���콺 Ŀ�� ����
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);		//������ ���� 
	WndClass.hInstance = hInstance;							//������ ũ������ ����ϴ� ���α׷��� ��ȣ
	WndClass.lpfnWndProc = WndProc;								//���ν��� ���� (�޼��� ó��)
	WndClass.lpszClassName = TEXT("WndClass");						//������ Ŭ���� �̸�
	WndClass.lpszMenuName = NULL;									//���α׷��� ����� �޴� ����

																	// 2. ������ Ŭ���� ���
	RegisterClass(&WndClass);		//������ Ŭ������ �ּҰ��� ���� (����ϱ� ����)

									// 3. ������ â ����
	hWnd = CreateWindow(
		WndClass.lpszClassName,		//Ŭ���� �̸�
		TEXT("������ Ÿ��Ʋ"),		//Ÿ��Ʋ �̸�
		WS_SYSMENU,					//������ â ��Ÿ��  WS_SYSMENU - �ݱ��ư ���� WS_OVERLAPPED - �ݱ��ư ����
		CW_USEDEFAULT,				//���� x ��ǥ
		CW_USEDEFAULT,				//���� y ��ǥ
		800,						//������ â �ʺ�
		640,						//������ â ����
		NULL,						//�θ� ������ �ڵ� ����
		NULL,						//������ �޴� �ڵ� ����
		hInstance,					//������ �ĺ��� ����
		NULL);						//�������� �����츦 ���� �� �Ķ���͸� ���� (���x)

									// 4. ������ â Ȱ��ȭ/ǥ��
									//SW_HIDE		/������ �����
									//SW_MINIMIZE	/�����츦 �ּ�ȭ ��Ű��, Ȱ��ȭ ���� �ʽ��ϴ�
									//SW_RESTORE	/������ Ȱ��ȭ
									//SW_SHOW		/�����츦 Ȱ��ȭ, ȭ�鿡 ǥ��
									//SW_SHOWNORMAL	/�����츦 Ȱ��ȭ, ȭ�鿡 ǥ��
	ShowWindow(hWnd, SW_SHOW);

	// 5. �޼��� ����/ó��
	//GetMessage()		- �޼��� ť���� �޼����� �о�帰 �� WM_QUIT�̶�� FALSE�� ��ȯ, �ƴ϶�� TRUE�� ��ȯ 
	//�޼����� ���� ������ ���
	//PeekMessage()		- ���� �޼����� �ִٸ� TRUE�� ��ȯ / �ƴ϶�� FALSE�� ��ȯ (���Ӱ��߿� ����)
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);		//Ű���� �Է� �޼����� ���α׷����� ����� �� �ֵ��� ����
		DispatchMessage(&Msg);		//�޼��� ť���� ���� �޼����� ���ν����� ����
	}

	return (int)Msg.wParam;
}

//�ݹ��Լ� �Ű�����
//hwnd						-�޼����� ���� ������ �ڵ鷯
//msg						-� ������ �޼������� Ȯ���� �� �ִ� ��
//wParam					-�޼����� �ΰ� ����(�޼����� ���� �ٸ�)
//IParam					-�޼����� �ΰ� ����(�޼����� ���� �ٸ�)
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	int i;
	HBRUSH MyBrush, OldBrush;
	HPEN MyPen, OldPen;
	switch (msg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (int i = 0; i < 300; i += 5)
		{
			MoveToEx(hdc, 0, i, NULL);
			LineTo(hdc, 600, i);
		}

		//���� ��, �ʷ� �귯���� �簢��				�귯���� �����̶�� ����, ���� �⺻���� ����, �귯���� �⺻���� �Ͼ�
		MyBrush = CreateSolidBrush(RGB(0, 255, 0));
		OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);
		MyPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
		OldPen = (HPEN)SelectObject(hdc, MyPen);
		
		Rectangle(hdc, 20, 20, 150, 150);

		//���� ��, ��(null)�귯��
		SelectObject(hdc, GetStockObject(NULL_BRUSH));
		Ellipse(hdc, 220, 20, 350, 150);

		//null��, �ʷ� �귯��
		SelectObject(hdc, GetStockObject(NULL_PEN));
		SelectObject(hdc, MyBrush);
		Rectangle(hdc, 420, 20, 550, 150);

		//���� �ļ�, �ٵ��� �Ķ� �귯��
		DeleteObject(MyPen);
		DeleteObject(SelectObject(hdc, OldBrush));

		MyPen = CreatePen(PS_DASH, 1, RGB(0, 0, 0));
		MyBrush = CreateHatchBrush(HS_CROSS, RGB(0, 0, 255));
		SelectObject(hdc, MyPen);
		SelectObject(hdc, MyBrush);
		Ellipse(hdc, 20, 170, 150, 300);

		//(220,170,350,300)��ǥ�� PS_DASHDOT �Ķ���, HS_DIAGCROSS �ʷ� �귯�� ��
		DeleteObject(SelectObject(hdc,OldPen));
		DeleteObject(SelectObject(hdc, OldBrush));

		MyPen = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 255));
		MyBrush = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 255, 0));
		SelectObject(hdc, MyPen);
		SelectObject(hdc, MyBrush);
		Ellipse(hdc, 220, 170, 350, 300);

		//(420,170,550,300)��ǥ�� PS_SOLID �ʷ� ��, HS_FDIAGONAL ���� �귯�� �簢��
		DeleteObject(SelectObject(hdc, OldPen));
		DeleteObject(SelectObject(hdc, OldBrush));

		MyPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		MyBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(255, 0, 0));
		SelectObject(hdc, MyPen);
		SelectObject(hdc, MyBrush);
		Rectangle(hdc, 420, 170, 550, 300);

		//DeleteObject(MyPen);
		//DeleteObject(MyBrush);
		DeleteObject(SelectObject(hdc, OldBrush));		//MyBrush ����, SelectObject�� OldBrush�� �����ϸ� (�ٷ� ���� �귯��)MyBrush�� ��ȯ
		//SelctObject(hdc, OldBrush));
		//DeleteObject(MyBrush);
		//�� ���� �� �ٷ� ����
		
		DeleteObject(SelectObject(hdc, OldPen));		//MyPen ����

		EndPaint(hwnd, &ps);
		return 0;


		//�����츦 �����Ϸ��� �Ѵٸ�
	case WM_DESTROY:
		//WM_QUIT �޼����� �߼�
		PostQuitMessage(0);
		return 0;
	}

	//�� ���� �޼����� �����쿡�� �˾Ƽ� ó���ϵ��� ����
	return DefWindowProc(hwnd, msg, wParam, IParam);
}

