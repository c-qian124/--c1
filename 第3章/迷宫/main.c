#include <stdio.h>
#include "mazeutil.h"

void main()
{
	Maze *maze;
	int mazeSize; //�Թ���С
	int entryX,entryY,exitX,exitY;
	int find = 0;
	printf("�������Թ���С��");
	scanf_s("%d",&mazeSize);
	entryX = 0; entryY = 0;
	exitX = mazeSize - 1; exitY = exitX;
	maze = InitMaze(mazeSize);
	ReadMaze(maze);
	printf("������Թ��ṹ���£�\n");
	printf("�������Թ�����ڵ�x,y�����ڵ�x,y\n");
	scanf_s("%d%d%d%d", &entryX,&entryY,&exitX,&exitY);
	//�����������
	find = MazeBFS(entryX,entryY,exitX,exitY,maze);
	//�����������
	find = MazeDFS(entryX, entryY, exitX, exitY, maze);
	if (!find)
	{
		printf("�Ҳ���·����\n");
	}
}