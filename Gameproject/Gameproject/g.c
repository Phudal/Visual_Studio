#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include <mmsystem.h>
#include <conio.h>
#include <wchar.h>
#pragma warning (disable:4996)
#pragma comment(lib,"winmm.lib")

#define SPEED 18			//357/20
#define BPM 357				//60/168 = 0.357
#define Height 15
#define Width 30


/*        좌표 관련                                                     */
int Target_x = 35;
int Target_y = 15;
int x = 0, y = 0;						//커서 축
/*        입력 관련                                                     */
int input;
char map_file[100];						//파일에 있는 맵 정보 저장
char converted_map_file[100];

/*        모양 관련                                                     */
char note = '0';
char Target_shape[] = { 0xA2, 0xC2 };

void scan_file();						//파일 스캔함수
void gotoxy(int x, int y);				//커서 이동함수
void CursorView();						//커서 숨김함수

void up_note();
void down_note();
void left_note();
void right_note();
void crash(int a, int b);

void intro();							//인트로 함수
void converting_map_file();				//맵 파일을 읽어서 재생

int main(void)
{	
	CursorView();
	intro();
	scan_file();
	PlaySound(TEXT("wings_of_piano.wav"), NULL, SND_ASYNC);			//음악재생함수
	converting_map_file();
	return 0;
}


void scan_file()
{
	FILE *bt;
	bt = fopen("wpp.txt", "r");
	fscanf(bt, "%s", map_file);
	//printf("%s", map_file);					//디버깅용 프린터
	fclose(bt);
}
void gotoxy(int tx, int ty)
{
	COORD Pos;
	Pos.X = tx;
	Pos.Y = ty;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void CursorView()
{
	CONSOLE_CURSOR_INFO Curinfo;
	Curinfo.dwSize = 1;
	Curinfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Curinfo);
}
void target_moving(int tx, int ty)
{
	Target_x = Target_x + tx;
	Target_y = Target_y + ty;
}
void up_note()
{
	for (int i = 0; i < Height; i++)
	{
		gotoxy(Target_x, Target_y + i - Height);
		printf("%c%c",0xA1,0xE8 );
		crash(Target_y + i - Height, Target_y - 1);
		gotoxy(Target_x, Target_y);
		printf("%s",Target_shape);
		Sleep(SPEED);
		system("cls");
	}
}
void down_note()
{
	for (int i = Height; i > 0; i--)
	{
		gotoxy(Target_x, Target_y + i);
		printf("%c%c", 0xA1, 0xE9);
		crash(Target_y + i, Target_y + 1);
		gotoxy(Target_x, Target_y);
		printf("%s", Target_shape);
		Sleep(SPEED);
		system("cls");
	}
}
void left_note()
{
	for (int i = 0; i < Width; i++)
	{
		gotoxy(Target_x + i - Width, Target_y);
		printf("%c%c",0xA1, 0xE7);
		crash(Target_x + i - Width, Target_x - 1);
		gotoxy(Target_x, Target_y);
		printf("%s", Target_shape);
		Sleep(SPEED / 6);
		system("cls");
	}
}
void right_note()
{
	for (int i = Width; i > 0; i--)
	{
		gotoxy(Target_x + i, Target_y);
		printf("%c%c", 0xA1, 0xE6);
		crash(Target_x + i, Target_x + 1);
		gotoxy(Target_x, Target_y);
		printf("%s", Target_shape);
		Sleep(SPEED / 6);
		system("cls");
	}
}
void intro() 
{
	gotoxy(15, 15);
	printf("→START");
	gotoxy(15, 16);
	printf("  END");
	do {
		input = getch();
		if (input == 0 || input == 0xe0)
			input = getch();

		switch (input)
		{
		case 72:
			gotoxy(15, 15);
			printf("→START");
			gotoxy(15, 16);
			printf("  END");
			input = getch();
			if (input == 0 || input == 0xe0)
				input = getch();
			break;
		case 80:
			gotoxy(15, 15);
			printf("  START");
			gotoxy(15, 16);
			printf("→END");
			input = getch();
			if (input == 0 || input == 0xe0)
				input = getch();
			if (input == 77)
				exit(1);
		}
	} while (input != 77);
	gotoxy(15, 20);
	printf("게임을 시작합니다!");
	Sleep(1000);
	system("cls");
}
void crash(int a, int b)
{
	if (a == b)
	{
		system("cls");
		gotoxy(50, 5);
		printf("Good!");
	}
}
void converting_map_file()
{
	for (int i = 0; i < strlen(map_file); i++)
	{
		switch (map_file[i])
		{
		case 'w':											//w를 up노트로 정의
			up_note();
			break;
		case 's':											//s를 down노트로 정의
			down_note();
			break;
		case 'a':											//a를 left노트로 정의
			left_note();									
			break;
		case 'd':											//d를 right노트로 정의	
			right_note();
			break;
		case 'c':											//c를 한 박자 쉼으로 정의
			gotoxy(Target_x, Target_y);
			printf("%s", Target_shape);
			Sleep(BPM);
			break;
		case 'j':											//타킷을 왼쪽으로 1칸 옮김
			Target_x = Target_x - 1;
			break;
		case 'k':											//타킷을 아랫쪽으로 1칸 옮김
			Target_y = Target_y + 1;						
			break;
		case 'l':											//타킷을 오른쪽으로 1칸 옮김
			Target_x = Target_x + 1;
			break;
		case 'i':											//타깃을 위쪽으로 1칸 옮김
			Target_y = Target_y - 1;
			break;
		}
	}
}