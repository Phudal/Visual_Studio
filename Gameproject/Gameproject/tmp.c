//#include <stdio.h>
//#include <time.h>
//#include <Windows.h>
//#include <stdlib.h>
//#include <mmsystem.h>
//#include <conio.h>
//#pragma comment(lib,"winmm.lib")
//
//#define SPEED 10															//���� �ٲپ� �ӵ� ���� ����
//#define Height 35															//���� ����
//int x = 0, y = 0;
//
//void gotoxy(int x, int y);													//Ŀ�� �̵� �Լ�
//void testnotedown();
//void noteAdown();
//void noteBdown();
//void noteCdown();
//void noteDdown();
//void CursorView();															//Ŀ�� ���� �Լ�
//void touch();
//void showscore();
//int main(void)
//{
//	CursorView();
//	PlaySound(TEXT("��� ���� ��.wav"), NULL, SND_ASYNC);					//���� ���
//	while (1)
//	{
//		//testnotedown();														//�׽�Ʈ�� ��Ʈ
//		noteAdown();
//		noteBdown();
//		noteCdown();
//		noteDdown();
//	}
//	return 0;
//}
//
//void gotoxy(int x, int y)
//{
//	COORD Pos;
//	Pos.X = x;
//	Pos.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
//}
//void testnotedown()
//{
//	char barA[] = "--------------    ";
//	char bg[] = "===============";
//	for (int i = 0; i < Height; i++)
//	{
//		printf("%s\n", barA);
//		gotoxy(0, Height);
//		printf("%s\n", bg);
//		//touch();
//		Sleep(SPEED);
//		system("cls");
//		gotoxy(x, y + i);
//		if (i == Height - 1)
//			touch();
//	}
//}
//void CursorView()
//{
//	CONSOLE_CURSOR_INFO Curinfo;
//	Curinfo.dwSize = 1;
//	Curinfo.bVisible = 0;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Curinfo);
//}
//void touch()
//{
//	char key = 0;
//	key = _getch();
//	switch (key)
//	{
//	case 'f':
//		printf("  ����          \n");
//		showscore();
//		break;
//	case 'g':
//		printf("         ����      \n");
//		showscore();
//		break;
//	case 'h':
//		printf("                ����    \n");
//		showscore();
//		break;
//	case 'j':
//		printf("                       ����  \n");
//		showscore();
//		break;
//	default:
//		break;
//	}
//	key = 0;
//}
//void showscore()
//{
//	gotoxy(20, 20);
//	printf("correct!");
//}
//void noteAdown()
//{
//	char barA[] = "   ----                                 ";
//	char bg[] = "==========================================";
//	for (int i = 0; i < Height; i++)
//	{
//		printf("%s\n", barA);
//		gotoxy(0, Height);
//		printf("%s\n", bg);
//		Sleep(SPEED);
//		system("cls");
//		gotoxy(x, y + i);
//		if (i == Height - 1)
//			touch();
//	}
//}
//void noteBdown()
//{
//	char barB[] = "          ----                          ";
//	char bg[] = "==========================================";
//	for (int i = 0; i < Height; i++)
//	{
//		printf("%s\n", barB);
//		gotoxy(0, Height);
//		printf("%s\n", bg);
//		Sleep(SPEED);
//		system("cls");
//		gotoxy(x, y + i);
//		if (i == Height - 1)
//			touch();
//	}
//}
//void noteCdown()
//{
//	char barC[] = "                 ----                   ";
//	char bg[] = "==========================================";
//	for (int i = 0; i < Height; i++)
//	{
//		printf("%s\n", barC);
//		gotoxy(0, Height);
//		printf("%s\n", bg);
//		Sleep(SPEED);
//		system("cls");
//		gotoxy(x, y + i);
//		if (i == Height - 1)
//			touch();
//	}
//}
//void noteDdown()
//{
//	char barD[] = "                        ----           ";
//	char bg[] = "=========================================";
//	for (int i = 0; i < Height; i++)
//	{
//		printf("%s\n", barD);
//		gotoxy(0, Height);
//		printf("%s\n", bg);
//		Sleep(SPEED);
//		system("cls");
//		gotoxy(x, y + i);
//		if (i == Height - 1)
//			touch();
//	}
//}