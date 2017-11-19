#ifndef FUNCTION_H
#define FUNCTION_H

extern const int SNAKELONG;
extern int background[][23];
extern int food; 
extern int game;
extern int length;
extern int score;
//存储蛇的信息 [][0]为当前的横坐标， [][1]为当前的列坐标，  [][2]为当前前进的方向
extern int snake[][3];


//生成背景
void  DrawBackground();

//随机生成蛇的初始位置
void GenerateStartPosition();

//把蛇的位置记录在背景数组中
void PutSnakeInBackground();

//蛇的移动
void MoveSnake(const int &keyboard);

//生成随机食物
void GenerateFood();

//将两个数组初始化
void ClearEverything();

#endif