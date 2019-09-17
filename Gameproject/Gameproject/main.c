//#include <stdio.h>
//#include <mmsystem.h>
//#include <Windows.h>
//#include <stdlib.h>
//#include <conio.h>
//#pragma comment(lib,"winmm.lib")
//
//#define SPEED 25						//SPEED값을 오르거나 낮추어서 노트가 떨어지는 속도를 조절할 수 있습니다.
//
//void line();
//void noteADown();			//노트 A를 움직이는 함수입니다
//void noteBDown();			//노트 B를 움직이는 함수입니다
//void noteCDown();			//노트 C를 움직이는 함수입니다
//void noteDDown();			//노트 D를 움직이는 함수입니다
//void noteABDown();			//노트 AB를 움직이는 함수입니다
//void noteCDDown();			//노트 CD를 움직이는 함수입니다
//void gotoxy(int x, int y);
//void test();
//
//int x = 0, y = 0;
//char input;
//int main(void) 
//{
//	//PlaySound(TEXT("어느 여름 날.wav"), NULL, SND_ASYNC);
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
//	line();				//시험삼아 만든 라인
//	noteADown();
//	noteBDown();
//	noteCDown();		//테스트용 노트 - 배경과 같이 떨어지게
//	noteDDown();		//테스트용 노트 - 노트만 떨어지게
//	noteABDown();
//	noteCDDown();
//}
////#include<stdio.h> 
////#include<windows.h>
////#include<mmsystem.h>
////#pragma comment(lib,"winmm.lib")
////
////int main(void) {
////	PlaySound(TEXT("어느 여름 날.wav"), NULL, SND_ASYNC);
////	printf("test");
////	while (1) {
////		Sleep(1000);
////	}
////	printf("aftertest");
////	return 0;
////}
