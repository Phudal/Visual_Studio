//#include <stdio.h>
//#include <mmsystem.h>
//#include <Windows.h>
//#include <stdlib.h>
//#include <conio.h>
//#pragma comment(lib,"winmm.lib")
//
//#define SPEED 25						//SPEED���� �����ų� ���߾ ��Ʈ�� �������� �ӵ��� ������ �� �ֽ��ϴ�.
//
//void line();
//void noteADown();			//��Ʈ A�� �����̴� �Լ��Դϴ�
//void noteBDown();			//��Ʈ B�� �����̴� �Լ��Դϴ�
//void noteCDown();			//��Ʈ C�� �����̴� �Լ��Դϴ�
//void noteDDown();			//��Ʈ D�� �����̴� �Լ��Դϴ�
//void noteABDown();			//��Ʈ AB�� �����̴� �Լ��Դϴ�
//void noteCDDown();			//��Ʈ CD�� �����̴� �Լ��Դϴ�
//void gotoxy(int x, int y);
//void test();
//
//int x = 0, y = 0;
//char input;
//int main(void) 
//{
//	//PlaySound(TEXT("��� ���� ��.wav"), NULL, SND_ASYNC);
//	while (1) {
//		test();
//	}
//	return 0;
//}
//void line()
//{
//	for (int i = 0; i < 25; i++)
//	{
//		printf("|                    |                    |                    |                    |\n");//wall line
//	}
//	printf("-------------------------------------------------------------------------------------\n"); //bottom line
//}
//void noteADown()
//{
//	char barA[89] = "|--------------------|                    |                    |                    |";
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%s\n", barA);
//		Sleep(SPEED);
//		system("cls");
//		gotoxy(x, y + i);
//	}
//}
//void noteBDown()
//{
//	char barB[89] = "|                    |--------------------|                    |                    |";
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%s\n", barB);
//		Sleep(SPEED);
//		system("cls");
//		gotoxy(x, y + i);
//	}
//}
//void noteCDown()
//{
//	char barC[89] = "|                    |                    |--------------------|                    |";
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%s\n", barC);
//		Sleep(SPEED);
//		system("cls");
//		gotoxy(x, y + i);
//	}
//	//int i = 0, j = 0, count = 0;
//	//char barC[89] = "|                    |                    |--------------------|                    |";
//	/*for (i = 0; i < 25; i++)
//	{
//		if (count != i)
//		{
//			for (j = 0; j < i; j++)
//				printf("|                    |                    |                    |                    |\n");
//		}
//		if (count == i)
//			printf("%s\n", barC);
//		if (count != i)
//		{
//			for (j = i; j < 25; j++);
//				printf("|                    |                    |                    |                    |\n");
//		}
//*/
//		/*printf("%s\n", barC);
//		Sleep(SPEED);
//		system("cls");
//		gotoxy(x, y + i);*/
//		/*system("cls");
//		Sleep(SPEED);
//	}*/
//}
//void noteDDown()
//{
//	char barD[89] ="|                    |                    |                    |--------------------|";
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%s\n", barD);
//		Sleep(SPEED);
//		system("cls");
//		gotoxy(x, y + i);
//	}
//}
//void noteABDown()
//{
//	char barAB[89] = "|--------------------|--------------------|                    |                    |";
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%s\n", barAB);
//		Sleep(SPEED);
//		system("cls");
//		gotoxy(x, y + i);
//	}
//}
//void noteCDDown()
//{
//	char barCD[89] = "|                    |                    |--------------------|--------------------|";
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%s\n", barCD);
//		Sleep(SPEED);
//		system("cls");
//		gotoxy(x, y + i);
//	}
//}
//void gotoxy(int x, int y) 
//{
//	COORD Pos;
//	Pos.X = x;
//	Pos.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
//}
//void test()
//{
//	line();				//������ ���� ����
//	noteADown();
//	noteBDown();
//	noteCDown();		//�׽�Ʈ�� ��Ʈ - ���� ���� ��������
//	noteDDown();		//�׽�Ʈ�� ��Ʈ - ��Ʈ�� ��������
//	noteABDown();
//	noteCDDown();
//}
////#include<stdio.h> 
////#include<windows.h>
////#include<mmsystem.h>
////#pragma comment(lib,"winmm.lib")
////
////int main(void) {
////	PlaySound(TEXT("��� ���� ��.wav"), NULL, SND_ASYNC);
////	printf("test");
////	while (1) {
////		Sleep(1000);
////	}
////	printf("aftertest");
////	return 0;
////}
