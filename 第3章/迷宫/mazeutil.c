#include <stdlib.h>
#include <stdio.h>
#include "mazeutil.h"

// ��ʼ���Թ�,����ռ䣬�������е���Ϊ0
Maze* InitMaze(int size)
{
	int i;
	Maze* maze = (Maze*)malloc(sizeof(Maze));
	maze->size = size;//�Թ���С 
	//���Թ�����ռ� 
	maze->data = (int**)malloc(sizeof(int*) * maze->size);
	for (i=0;i<maze->size;i++)
	{
		maze->data[i] = (int*)malloc(sizeof(int) * maze->size);
	}
	return maze;
}
//�����Թ��ṹ��0��������ߵ�·��1����ǽ
void ReadMaze(Maze* maze)
{
	int i,j;
	printf("���þ������ʽ�����Թ��Ľṹ:\n");
	//�����Թ��Ľṹ 
	for (i=0;i<maze->size;i++)
	{
		for(j=0;j<maze->size;j++)
			scanf_s("%d", &maze->data[i][j]);
	}
}
//���Թ��Ľṹ��ʾ����
void WriteMaze(Maze* maze)
{
	int i,j;
	printf("�Թ��ṹ����:\n");
	//����Թ��Ľṹ 
	for (i=0;i<maze->size;i++)
	{
		for(j=0;j<maze->size;j++)
			printf("%5d", maze->data[i][j]);
		printf("\n");
	}
}