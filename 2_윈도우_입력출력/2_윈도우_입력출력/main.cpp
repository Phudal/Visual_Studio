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
	HDC				hdc;
	PAINTSTRUCT		ps;
	
	static int xPos, yPos;	//���ڿ� ��ġ
	static TCHAR str[256];	//���ڿ� �Է¹�
	int len;				//���ڿ� ����

	switch (msg)
	{
	case WM_CREATE:
		xPos = 100;
		yPos = 100;
		return 0;
	case WM_LBUTTONDOWN:	//���콺 ���� ��ư�� ��������
		// �޼��� �ڽ� ���
		MessageBox(hwnd, TEXT("�޼��� �ڽ� ����"), TEXT("�޼��� �ڽ� ����"), MB_ICONWARNING | MB_OK);
		return 0;

	case WM_PAINT:			//ȭ�鿡 �׸�, ���ڸ� �����
		hdc = BeginPaint(hwnd, &ps);
		Ellipse(hdc, 100, 100, 700, 540);			//�� �׸���
		Rectangle(hdc, 400, 400, 500, 500);			//�簢�� �׸���
		MoveToEx(hdc, 300, 300, NULL);				//��ǥ �̵�
		LineTo(hdc, 400, 400);						//�� ��ǥ�κ��� Ư�� ��ǥ�� �̵��ϸ鼭 �� �׸���
		
		MoveToEx(hdc, 100, 100, NULL);
		SetTextAlign(hdc, TA_UPDATECP);			
		TextOut(hdc, 100, 100, TEXT("Hello World"), 11);		//���ڿ��� ���, ���ڿ� ���̰� 11
		TextOut(hdc, 500, 500, TEXT("Test Text"), 9);
		

		RECT rect;
		rect.left = 250;
		rect.top = 250;
		rect.right = 650;
		rect.bottom = 650;
		
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
		DrawText(hdc, TEXT("���ڿ��׽�Ʈ"), 6, &rect, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);		//DT_SINGLELINE + DT_VCENTER = �������

		SetTextAlign(hdc, TA_NOUPDATECP);
		TextOut(hdc, xPos, yPos, str, lstrlen(str));

		EndPaint(hwnd, &ps);
		return 0;

	case WM_CHAR:								//���ڿ��� �Է¹�����,	 ����Ű ���� �Է¹��� �� ����
		len = lstrlen(str);
		str[len] = (TCHAR)wParam;
		str[len + 1] = 0;
		InvalidateRect(hwnd, NULL, TRUE);		//��ȿȭ ������ �ٸ� ���������� �ϰ������ ���
		return 0;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_UP:
			yPos -= 10;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case VK_DOWN:
			yPos += 10;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case VK_LEFT:
			xPos -= 10;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case VK_RIGHT:
			xPos += 10;
			InvalidateRect(hwnd, NULL, TRUE);
			break; 
		}
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

