#include <Windows.h>
#include "resource1.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam);

//엔트리 포인트
//APIENTRY 지정자는 윈도우 표준 호출 규약인 __stdcall을 사용한다는 의미

//함수 호출 방법 (호출 규약)
//__stdcall		: 매개변수의 개수가 고정된 함수	/ 크기 작다 / callee (피호출자) stack 정리
//__cdecl		: 매개변수의 개수가 가변적인 함수 / 크기 작다 / caller (호출자) stack 정리


HINSTANCE g_hInst; 
//매개변수
//hInstace		:프로그램 인스턴스 핸들
//hPrevInstance :이전에 실행시킨 같은 프로그램 인스턴스 핸들 (사용 x)
//lpszCmdParam	:명령행으로 입력된 프로그램 인수 (사용 x)
//nCmdShow		:프로그램이 실행 될 형태 (사용 x)

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	g_hInst = hInstance;
	
	HWND			hWnd;			//윈도우 핸들러
	MSG				Msg;			//윈도우 메세지
	WNDCLASS		WndClass;		//윈도우 구조체

									// 1. 윈도우 클래스 설정/초기화
	WndClass.style = CS_HREDRAW | CS_VREDRAW;				//윈도우 스타일 정의 -- 가로|세로 로 늘어날떄 재정의
	WndClass.cbClsExtra = 0;									//특수한 목적으로 사용될 예약 영역
	WndClass.cbWndExtra = 0;									//특수한 목적으로 사용될 예약 영역
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//윈도우 배경 색상
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);			//마우스 커서 지정
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);		//아이콘 지정 
	WndClass.hInstance = hInstance;							//윈도우 크래스를 등록하는 프로그램의 번호
	WndClass.lpfnWndProc = WndProc;								//프로시저 설정 (메세지 처리)
	WndClass.lpszClassName = TEXT("WndClass");						//윈도우 클래스 이름
	WndClass.lpszMenuName = NULL;									//프로그램이 사용할 메뉴 설정

																	// 2. 윈도우 클래스 등록
	RegisterClass(&WndClass);		//윈도우 클래스의 주소값을 전달 (사용하기 위해)

									// 3. 윈도우 창 생성
	hWnd = CreateWindow(
		WndClass.lpszClassName,		//클래스 이름
		TEXT("윈도우 타이틀"),		//타이틀 이름
		WS_SYSMENU,					//윈도우 창 스타일  WS_SYSMENU - 닫기버튼 있음 WS_OVERLAPPED - 닫기버튼 없음
		CW_USEDEFAULT,				//시작 x 좌표
		CW_USEDEFAULT,				//시작 y 좌표
		800,						//윈도우 창 너비
		640,						//윈도우 창 높이
		NULL,						//부모 윈도우 핸들 지정
		NULL,						//윈도우 메뉴 핸들 지정
		hInstance,					//윈도우 식별자 지정
		NULL);						//여러개의 윈도우를 만들 때 파라미터를 전달 (사용x)

									// 4. 윈도우 창 활성화/표시
									//SW_HIDE		/윈도우 숨기기
									//SW_MINIMIZE	/윈도우를 최소화 시키고, 활성화 하지 않습니다
									//SW_RESTORE	/윈도우 활성화
									//SW_SHOW		/윈도우를 활성화, 화면에 표시
									//SW_SHOWNORMAL	/윈도우를 활성화, 화면에 표시
	ShowWindow(hWnd, SW_SHOW);

	// 5. 메세지 루프/처리
	//GetMessage()		- 메세지 큐에서 메세지를 읽어드린 후 WM_QUIT이라면 FALSE를 반환, 아니라면 TRUE를 반환 
	//메세지가 있을 때까지 대기
	//PeekMessage()		- 받을 메세지가 있다면 TRUE를 반환 / 아니라면 FALSE를 반환 (게임개발에 적당)
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);		//키보드 입력 메세지를 프로그램에서 사용할 수 있도록 가공
		DispatchMessage(&Msg);		//메세지 큐에서 꺼낸 메세지를 프로시저에 전달
	}

	return (int)Msg.wParam;
}

//콜백함수 매개변수
//hwnd						-메세지를 받을 윈도우 핸들러
//msg						-어떤 종류의 메세지인지 확인할 수 있는 값
//wParam					-메세지의 부가 정보(메세지에 따라 다름)
//IParam					-메세지의 부가 정보(메세지에 따라 다름)
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam)
{
	static int posX, posY, oldX, oldY;
	static bool bDraw = false;
	HDC hdc;
	PAINTSTRUCT ps;

	static HBITMAP myBitmap;

	switch (msg)
	{

	case WM_CREATE:
		myBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_LABI));
		return 0;

	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &ps);
		//메모리 DC 생성
		HDC memDC = CreateCompatibleDC(hdc);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, myBitmap);
		BITMAP bit;
		int bWidth, bHeight;
		GetObject(myBitmap, sizeof(BITMAP), &bit);

		bWidth = bit.bmWidth;
		bHeight = bit.bmHeight;

		BitBlt(hdc, 10, 10, bWidth, bHeight, memDC, 0, 0, SRCCOPY);
		SelectObject(memDC, oldBitmap);
		DeleteDC(memDC);

		EndPaint(hwnd, &ps);
		return 0;
	}
	case WM_LBUTTONDOWN:		//누를 때 동작
		posX = LOWORD(IParam);
		posY = HIWORD(IParam);
		oldX = posX;
		oldY = posY;
		bDraw = true;
		return 0;

	case WM_MOUSEMOVE: 
		if (bDraw)
		{
			hdc = GetDC(hwnd);

			//그리기 모드 설정
			SetROP2(hdc, R2_NOT);		//원래 그림을 반전시켜서 그리기 때문에 겹치면 지워짐
			MoveToEx(hdc, posX, posY, NULL);
			LineTo(hdc, oldX, oldY);
			oldX = LOWORD(IParam);
			oldY = LOWORD(IParam);
			MoveToEx(hdc, posX, posY, NULL);
			LineTo(hdc, oldX, oldY);
			ReleaseDC(hwnd, hdc); 
		}
		return 0;

	case WM_LBUTTONUP:			//땔 때 동작
		bDraw = false;
		hdc = GetDC(hwnd);
		MoveToEx(hdc, posX, posY, NULL);
		LineTo(hdc, oldX, oldY);
		ReleaseDC(hwnd, hdc);
		return 0;

		//윈도우를 종료하려고 한다면
	case WM_DESTROY:
		//WM_QUIT 메세지를 발송
		DeleteObject(myBitmap);
		PostQuitMessage(0);
		return 0;
	}

	//그 외의 메세지는 윈도우에서 알아서 처리하도록 설정
	return DefWindowProc(hwnd, msg, wParam, IParam);
}

