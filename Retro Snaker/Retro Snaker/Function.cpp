#include "Function.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
/*
��٣�
1.������  
2.���߳�ʼλ��  
3.���߶�����  
4.�������ʳ��  
5.���߳Զ����Ժ��ܱ䳤  
6.����
7.�����������
8.�û�����
*/

int length = 0;  //��¼�ߵĳ���
const int SNAKELONG = 40;
int food = 1;  //�ж�ʳ���ǲ��Ǳ�����
int game = 1;   //�ж��Ƿ���Ϸ����
int score = 0;
int background[20][23] =
{
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

int snake[SNAKELONG][3] = { 0 };

//������
void DrawBackground()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			switch (background[i][j])
			{
			case 0:
				printf("  "); //�հײ���
				break;
			case 1:
				printf("��"); //�߽�
				break;
			case 2:
				printf("��"); //ʳ��
				break;
			case 3:
				printf("��"); //��ͷ
				break;
			case 4:
				printf("��"); //����
				break;
			}
		}
		printf("\n");
	}
}

//���ߵ�λ�ü�¼�ڱ���������
void PutSnakeInBackground()
{
	background[snake[0][0]][snake[0][1]] = 3;
	for (int i = 1; i <= length; i++)
		background[snake[i][0]][snake[i][1]] = 4;
}

//�����߳�ʼλ��
void GenerateStartPosition()
{
	time_t t;
	srand(time(&t));
	snake[0][0] = rand() % 18 + 1;
	snake[0][1] = rand() % 21 + 1;
	PutSnakeInBackground();
}


//�ߵ��ƶ�
void MoveSnake(const int &keyboard)
{

	int tempx = snake[length][0], tempy = snake[length][1];
	switch (keyboard) //�ж����Ƿ�die�Լ��Ƿ���˶���
	{
	case 72: //�ϵ�ʱ����λ�������1�� �����겻��
		if (background[snake[0][0] - 1][snake[0][1]] == 2)
		{
			++length;
			food = 0;
		}
		else if (background[snake[0][0] - 1][snake[0][1]] == 4 || background[snake[0][0] - 1][snake[0][1]] == 1)
		{
			game = 0;
			break;
		}
		break;
	case 80: //�µ�ʱ����λ�������1�� �����겻��
		if (background[snake[0][0] + 1][snake[0][1]] == 2)
		{
			++length;
			food = 0;
		}
		else if (background[snake[0][0] + 1][snake[0][1]] == 4 || background[snake[0][0] + 1][snake[0][1]] == 1)
		{
			game = 0;
			break;
		}
		break;
	case 75: //���ʱ����λ�������1�������겻��
		if (background[snake[0][0]][snake[0][1] - 1] == 2)
		{
			++length;
			food = 0;
		}
		else if (background[snake[0][0]][snake[0][1] - 1] == 4 || background[snake[0][0]][snake[0][1] - 1] == 1)
		{
			game = 0;
			break;
		}
		break;
	case 77: //�ҵ�ʱ����λ�������1�� �����겻��
		if (background[snake[0][0]][snake[0][1] + 1] == 2)
		{
			++length;
			food = 0;
		}
		else if (background[snake[0][0]][snake[0][1] + 1] == 4 || background[snake[0][0]][snake[0][1] + 1] == 1)
		{
			game = 0;
			break;
		}
		break;
	}

	for (int i = length; i > 0; i--)
	{
		snake[i][0] = snake[i - 1][0];
		snake[i][1] = snake[i - 1][1];
		snake[i][2] = snake[i - 1][2];
	}

	switch (keyboard)
	{
	case 72: //�ϵ�ʱ����λ�������1�� �����겻��
		snake[0][0] -= 1;
		break;
	case 80: //�µ�ʱ����λ�������1�� �����겻��
		snake[0][0] += 1;
		break;
	case 75: //���ʱ����λ�������1�������겻��
		snake[0][1] -= 1;
		break;
	case 77: //�ҵ�ʱ����λ�������1�� �����겻��
		snake[0][1] += 1;
		break;
	}
	snake[0][2] = keyboard;

	background[tempx][tempy] = 0; //���ƶ��������Ǹ������������
	PutSnakeInBackground(); //�Ѹ��µ���Ϣд��snake������
}

//�������ʳ��
void GenerateFood()
{
	time_t t;
	srand(time(&t));
	while (1)
	{
		int FoodCoordinateX = rand() % 18 + 1,
			FoodCoordinateY = rand() % 21 + 1;
		if (background[FoodCoordinateX][FoodCoordinateY] == 0)
		{
			background[FoodCoordinateX][FoodCoordinateY] = 2;
			break;
		}
	}
}

//�����������
void ClearEverything()
{

	for (int i = 0; i < 23; i++)
	{
		background[0][i] = 1;
		background[19][i] = 1;
		if (i < 20)
		{
			background[i][0] = 1;
			background[i][22] = 1;
		}
	}
	for (int i = 1; i < 19; i++)
		for (int j = 1; j < 22; j++)
			background[i][j] = 0;
	length = 0;
}