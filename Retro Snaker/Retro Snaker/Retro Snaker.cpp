#include "Function.h"
#include <cstdio>
#include <conio.h>   //_getch()����  _kbhit()����
#include <iostream>
#include <Windows.h>  //Sleep()����
using namespace std;



int main(void)
{
	
	int keyboard0, keyboard; //��¼������Ϣ
	while (1) 
	{
		//��game��food��length��ʼ��
		length = 0;  
		game = 1;
		food = 1;
		score = 0;

		//ClearEverything();
		system("cls");  //���ϴ�̰���ߵ���������Ϣȫ��ɾ����
		printf("����ո����Ϸ��ʼ");
		while (1) //�ж���Ϸ�Ƿ�ʼ
		{
			//�������һ�λ�����������֣�Ӧ�ðѵ�һ�ε�������Keyboard0��ȡ���������ķ������Keyboard��ȡ
			keyboard0 = _getch();
			if (keyboard0 == 0x20)
			{
				system("cls");
				break;
			}		
		}
		printf("��ǰ����: %d\n", score);
		GenerateStartPosition(); //�����ߵĳ�ʼλ��
		GenerateFood(); //����ʳ��
		DrawBackground(); //��������

		while (1) // �����߳�ʼ�ƶ�����
		{
			keyboard0 = _getch();
			if (keyboard0 == 224)
			{
				keyboard = _getch();
				snake[0][2] = keyboard;  //�����Ժ��������Ū��������
				break;
			}	
		}

		while (1) //��Ϸ��ʼ
		{

			while (!_kbhit())
			{//�˴�˳����н���
				system("cls");
				printf("��ǰ����: %d\n", score);
				MoveSnake(keyboard);  //�ƶ�
				if (game == 0) //��Ϸ��������
				{
					system("cls");
					printf("game over\n���յ÷�Ϊ: %d", score);
					Sleep(2000);
					while (!_kbhit());
					break;
				}
				if (score == SNAKELONG)   //ʤ������ 
				{
					system("cls");
					printf("you win\n���������������һ����Ϸ\n");
					Sleep(2000);
					while (!_kbhit());//���������������һ����Ϸ
					break;
				}
				if (food == 0)   //�ж��߳���ʳ��
				{
					GenerateFood(); //����ʳ��
					food = 1;
					++score;
				}
				DrawBackground();  //��������
				Sleep(400);
			}
			if (game == 0 || score == SNAKELONG)
				break;
			keyboard0 = _getch();	
			if (keyboard0 == 224)
			{
				keyboard = _getch();
				switch (keyboard)  //��ֹ��ԭ�ص�ͷ
				{
				case 72:
					if (snake[0][2] == 80)
						keyboard = 80;
					break;
				case 80:
					if (snake[0][2] == 72)
						keyboard = 72;
					break;
				case 75:
					if (snake[0][2] == 77)
						keyboard = 77;
					break;
				case 77:
					if (snake[0][2] == 75)
						keyboard = 75;
					break;
				}
			}	
			else
				continue;
			
		}	
	}
	system("pause");
	return 0;
}