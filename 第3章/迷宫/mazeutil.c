#include <stdlib.h>
#include <stdio.h>
#include "mazeutil.h"

// 初始化迷宫,分配空间，并将所有点置为0
Maze* InitMaze(int size)
{
	int i;
	Maze* maze = (Maze*)malloc(sizeof(Maze));
	maze->size = size;//迷宫大小 
	//给迷宫分配空间 
	maze->data = (int**)malloc(sizeof(int*) * maze->size);
	for (i=0;i<maze->size;i++)
	{
		maze->data[i] = (int*)malloc(sizeof(int) * maze->size);
	}
	return maze;
}
//读入迷宫结构，0代表可以走的路，1代表墙
void ReadMaze(Maze* maze)
{
	int i,j;
	printf("请用矩阵的形式输入迷宫的结构:\n");
	//读入迷宫的结构 
	for (i=0;i<maze->size;i++)
	{
		for(j=0;j<maze->size;j++)
			scanf_s("%d", &maze->data[i][j]);
	}
}
//将迷宫的结构显示出来
void WriteMaze(Maze* maze)
{
	int i,j;
	printf("迷宫结构如下:\n");
	//输出迷宫的结构 
	for (i=0;i<maze->size;i++)
	{
		for(j=0;j<maze->size;j++)
			printf("%5d", maze->data[i][j]);
		printf("\n");
	}
}