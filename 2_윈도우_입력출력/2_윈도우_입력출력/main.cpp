#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam);

//엔트리 포인트
//APIENTRY 지정자는 윈도우 표준 호출 규약인 __stdcall을 사용한다는 의미

//함수 호출 방법 (호출 규약)
//__stdcall		: 매개변수의 개수가 고정된 함수	/ 크기 작다 / callee (피호출자) stack 정리
//__cdecl		: 매개변수의 개수가 가변적인 함수 / 크기 작다 / caller (호출자) stack 정리

//매개변수
//hInstace		:프로그램 인스턴스 핸들
//hPrevInstance :이전에 실행시킨 같은 프로그램 인스턴스 핸들 (사용 x)
//lpszCmdParam	:명령행으로 입력된 프로그램 인수 (사용 x)
//nCmdShow		:프로그램이 실행 될 형태 (사용 x)

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
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
	HDC				hdc;
	PAINTSTRUCT		ps;
	
	static int xPos, yPos;	//문자열 위치
	static TCHAR str[256];	//문자열 입력바
	int len;				//문자열 길이

	switch (msg)
	{
	case WM_CREATE:
		xPos = 100;
		yPos = 100;
		return 0;
	case WM_LBUTTONDOWN:	//마우스 왼쪽 버튼이 눌렸을때
		// 메세지 박스 출력
		MessageBox(hwnd, TEXT("메세지 박스 내용"), TEXT("메세지 박스 제목"), MB_ICONWARNING | MB_OK);
		return 0;

	case WM_PAINT:			//화면에 그림, 문자를 띄워줌
		hdc = BeginPaint(hwnd, &ps);
		Ellipse(hdc, 100, 100, 700, 540);			//원 그리기
		Rectangle(hdc, 400, 400, 500, 500);			//사각형 그리기
		MoveToEx(hdc, 300, 300, NULL);				//좌표 이동
		LineTo(hdc, 400, 400);						//현 좌표로부터 특정 좌표로 이동하면서 선 그리기
		
		MoveToEx(hdc, 100, 100, NULL);
		SetTextAlign(hdc, TA_UPDATECP);			
		TextOut(hdc, 100, 100, TEXT("Hello World"), 11);		//문자열을 출력, 문자열 길이가 11
		TextOut(hdc, 500, 500, TEXT("Test Text"), 9);
		

		RECT rect;
		rect.left = 250;
		rect.top = 250;
		rect.right = 650;
		rect.bottom = 650;
		
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
		DrawText(hdc, TEXT("문자열테스트"), 6, &rect, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);		//DT_SINGLELINE + DT_VCENTER = 가운데정렬

		SetTextAlign(hdc, TA_NOUPDATECP);
		TextOut(hdc, xPos, yPos, str, lstrlen(str));

		EndPaint(hwnd, &ps);
		return 0;

	case WM_CHAR:								//문자열을 입력받을때,	 방향키 등은 입력받을 수 없음
		len = lstrlen(str);
		str[len] = (TCHAR)wParam;
		str[len + 1] = 0;
		InvalidateRect(hwnd, NULL, TRUE);		//무효화 현상을 다른 지역에서도 하고싶을때 사용
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

		//윈도우를 종료하려고 한다면
	case WM_DESTROY:
		//WM_QUIT 메세지를 발송
		PostQuitMessage(0);
		return 0;
	}

	//그 외의 메세지는 윈도우에서 알아서 처리하도록 설정
	return DefWindowProc(hwnd, msg, wParam, IParam);
}

