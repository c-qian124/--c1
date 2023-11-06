#include <stdio.h>
#include "mazeutil.h"

void main()
{
	Maze *maze;
	int mazeSize; //迷宫大小
	int entryX,entryY,exitX,exitY;
	int find = 0;
	printf("请输入迷宫大小：");
	scanf_s("%d",&mazeSize);
	entryX = 0; entryY = 0;
	exitX = mazeSize - 1; exitY = exitX;
	maze = InitMaze(mazeSize);
	ReadMaze(maze);
	printf("输入的迷宫结构如下：\n");
	printf("请输入迷宫的入口点x,y，出口点x,y\n");
	scanf_s("%d%d%d%d", &entryX,&entryY,&exitX,&exitY);
	//广度优先搜索
	find = MazeBFS(entryX,entryY,exitX,exitY,maze);
	//深度优先搜索
	find = MazeDFS(entryX, entryY, exitX, exitY, maze);
	if (!find)
	{
		printf("找不到路径！\n");
	}
}