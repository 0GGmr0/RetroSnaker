#include "Function.h"
#include <cstdio>
#include <conio.h>   //_getch()函数  _kbhit()函数
#include <iostream>
#include <Windows.h>  //Sleep()函数
using namespace std;



int main(void)
{
	
	int keyboard0, keyboard; //记录按键信息
	while (1) 
	{
		//对game和food和length初始化
		length = 0;  
		game = 1;
		food = 1;
		score = 0;

		//ClearEverything();
		system("cls");  //将上次贪吃蛇的最后输出信息全部删除掉
		printf("输入空格后游戏开始");
		while (1) //判定游戏是否开始
		{
			//方向键按一次会出现两次数字，应该把第一次的数字用Keyboard0读取掉，真正的方向键用Keyboard读取
			keyboard0 = _getch();
			if (keyboard0 == 0x20)
			{
				system("cls");
				break;
			}		
		}
		printf("当前分数: %d\n", score);
		GenerateStartPosition(); //生成蛇的初始位置
		GenerateFood(); //生成食物
		DrawBackground(); //画出背景

		while (1) // 决定蛇初始移动方向
		{
			keyboard0 = _getch();
			if (keyboard0 == 224)
			{
				keyboard = _getch();
				snake[0][2] = keyboard;  //此行以后考虑下如何弄到函数中
				break;
			}	
		}

		while (1) //游戏开始
		{

			while (!_kbhit())
			{//此处顺序很有讲究
				system("cls");
				printf("当前分数: %d\n", score);
				MoveSnake(keyboard);  //移动
				if (game == 0) //游戏结束条件
				{
					system("cls");
					printf("game over\n最终得分为: %d", score);
					Sleep(2000);
					while (!_kbhit());
					break;
				}
				if (score == SNAKELONG)   //胜利条件 
				{
					system("cls");
					printf("you win\n按下任意键进入下一场游戏\n");
					Sleep(2000);
					while (!_kbhit());//输入任意键进入下一场游戏
					break;
				}
				if (food == 0)   //判定蛇吃了食物
				{
					GenerateFood(); //生成食物
					food = 1;
					++score;
				}
				DrawBackground();  //画出背景
				Sleep(400);
			}
			if (game == 0 || score == SNAKELONG)
				break;
			keyboard0 = _getch();	
			if (keyboard0 == 224)
			{
				keyboard = _getch();
				switch (keyboard)  //防止蛇原地掉头
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