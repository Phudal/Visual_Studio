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


/*        ��ǥ ����                                                     */
int Target_x = 35;
int Target_y = 15;
int x = 0, y = 0;						//Ŀ�� ��
/*        �Է� ����                                                     */
int input;
char map_file[100];						//���Ͽ� �ִ� �� ���� ����
char converted_map_file[100];

/*        ��� ����                                                     */
char note = '0';
char Target_shape[] = { 0xA2, 0xC2 };

void scan_file();						//���� ��ĵ�Լ�
void gotoxy(int x, int y);				//Ŀ�� �̵��Լ�
void CursorView();						//Ŀ�� �����Լ�

void up_note();
void down_note();
void left_note();
void right_note();
void crash(int a, int b);

void intro();							//��Ʈ�� �Լ�
void converting_map_file();				//�� ������ �о ���

int main(void)
{	
	CursorView();
	intro();
	scan_file();
	PlaySound(TEXT("wings_of_piano.wav"), NULL, SND_ASYNC);			//��������Լ�
	converting_map_file();
	return 0;
}


void scan_file()
{
	FILE *bt;
	bt = fopen("wpp.txt", "r");
	fscanf(bt, "%s", map_file);
	//printf("%s", map_file);					//������ ������
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
	printf("��START");
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
			printf("��START");
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
			printf("��END");
			input = getch();
			if (input == 0 || input == 0xe0)
				input = getch();
			if (input == 77)
				exit(1);
		}
	} while (input != 77);
	gotoxy(15, 20);
	printf("������ �����մϴ�!");
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
		case 'w':											//w�� up��Ʈ�� ����
			up_note();
			break;
		case 's':											//s�� down��Ʈ�� ����
			down_note();
			break;
		case 'a':											//a�� left��Ʈ�� ����
			left_note();									
			break;
		case 'd':											//d�� right��Ʈ�� ����	
			right_note();
			break;
		case 'c':											//c�� �� ���� ������ ����
			gotoxy(Target_x, Target_y);
			printf("%s", Target_shape);
			Sleep(BPM);
			break;
		case 'j':											//ŸŶ�� �������� 1ĭ �ű�
			Target_x = Target_x - 1;
			break;
		case 'k':											//ŸŶ�� �Ʒ������� 1ĭ �ű�
			Target_y = Target_y + 1;						
			break;
		case 'l':											//ŸŶ�� ���������� 1ĭ �ű�
			Target_x = Target_x + 1;
			break;
		case 'i':											//Ÿ���� �������� 1ĭ �ű�
			Target_y = Target_y - 1;
			break;
		}
	}
}