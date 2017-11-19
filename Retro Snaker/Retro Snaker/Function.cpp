#include "Function.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
/*
大纲：
1.画背景  
2.画蛇初始位置  
3.让蛇动起来  
4.生成随机食物  
5.让蛇吃东西以后能变长  
6.计数
7.设计死亡条件
8.用户界面
*/

int length = 0;  //记录蛇的长度
const int SNAKELONG = 40;
int food = 1;  //判断食物是不是被吃了
int game = 1;   //判断是否游戏结束
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

//画背景
void DrawBackground()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			switch (background[i][j])
			{
			case 0:
				printf("  "); //空白部分
				break;
			case 1:
				printf("■"); //边界
				break;
			case 2:
				printf("⊕"); //食物
				break;
			case 3:
				printf("○"); //蛇头
				break;
			case 4:
				printf("●"); //蛇身
				break;
			}
		}
		printf("\n");
	}
}

//把蛇的位置记录在背景数组中
void PutSnakeInBackground()
{
	background[snake[0][0]][snake[0][1]] = 3;
	for (int i = 1; i <= length; i++)
		background[snake[i][0]][snake[i][1]] = 4;
}

//生成蛇初始位置
void GenerateStartPosition()
{
	time_t t;
	srand(time(&t));
	snake[0][0] = rand() % 18 + 1;
	snake[0][1] = rand() % 21 + 1;
	PutSnakeInBackground();
}


//蛇的移动
void MoveSnake(const int &keyboard)
{

	int tempx = snake[length][0], tempy = snake[length][1];
	switch (keyboard) //判断蛇是否die以及是否吃了东西
	{
	case 72: //上的时候首位纵坐标减1， 横坐标不变
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
	case 80: //下的时候首位纵坐标加1， 横坐标不变
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
	case 75: //左的时候首位横坐标减1，纵坐标不变
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
	case 77: //右的时候首位横坐标加1， 纵坐标不变
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
	case 72: //上的时候首位纵坐标减1， 横坐标不变
		snake[0][0] -= 1;
		break;
	case 80: //下的时候首位纵坐标加1， 横坐标不变
		snake[0][0] += 1;
		break;
	case 75: //左的时候首位横坐标减1，纵坐标不变
		snake[0][1] -= 1;
		break;
	case 77: //右的时候首位横坐标加1， 纵坐标不变
		snake[0][1] += 1;
		break;
	}
	snake[0][2] = keyboard;

	background[tempx][tempy] = 0; //把移动后多余的那个方块给消除掉
	PutSnakeInBackground(); //把更新的信息写入snake数组中
}

//生成随机食物
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

//清空两个数组
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