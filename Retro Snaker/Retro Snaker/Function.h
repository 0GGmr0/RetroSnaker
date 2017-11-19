#ifndef FUNCTION_H
#define FUNCTION_H

extern const int SNAKELONG;
extern int background[][23];
extern int food; 
extern int game;
extern int length;
extern int score;
//�洢�ߵ���Ϣ [][0]Ϊ��ǰ�ĺ����꣬ [][1]Ϊ��ǰ�������꣬  [][2]Ϊ��ǰǰ���ķ���
extern int snake[][3];


//���ɱ���
void  DrawBackground();

//��������ߵĳ�ʼλ��
void GenerateStartPosition();

//���ߵ�λ�ü�¼�ڱ���������
void PutSnakeInBackground();

//�ߵ��ƶ�
void MoveSnake(const int &keyboard);

//�������ʳ��
void GenerateFood();

//�����������ʼ��
void ClearEverything();

#endif