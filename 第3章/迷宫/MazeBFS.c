#include <stdlib.h>
#include <stdio.h>
#include "mazeutil.h"
#include "LinkQueue.h" //包含链队列头文件

//迷宫广度遍历算法
int MazeBFS(int entryX, int entryY, int exitX, int exitY, Maze* maze)
{
	int direction[8][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 },
	{ 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };
	//用于两个队列，分别保存等待扩展的点（x，y）值
	LinkQueue linkQueueX = NULL;
	LinkQueue linkQueueY = NULL;
	int posX, posY;//临时变量，存放点坐标（x，y）
	int preposX, preposY;
	int **preposMarkX;//记录迷宫行走过程中的前序点x值
	int **preposMarkY;//记录迷宫行走过程中的前序点y值
	int **mark;//标记二维数组，标记哪些点走过，不再重复走
	int i, j, mov;
	//给存放前驱x值的数组分配空间 
	preposMarkX = (int**)malloc(sizeof(int*)* maze->size);
	for (i = 0; i<maze->size; i++)
	{
		preposMarkX[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	//给存放前驱y值的数组分配空间 
	preposMarkY = (int**)malloc(sizeof(int*)* maze->size);
	for (i = 0; i<maze->size; i++)
	{
		preposMarkY[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	//给做标记的二维数组分配空间，并赋初值 
	mark = (int**)malloc(sizeof(int*)* maze->size);
	for (i = 0; i<maze->size; i++)
	{
		mark[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	for (i = 0; i<maze->size; i++)// 给所有元素设置初值
	{
		for (j = 0; j<maze->size; j++)
		{
			preposMarkX[i][j] = -1;
			preposMarkY[i][j] = -1;
			mark[i][j] = 0;
		}
	}
	linkQueueX = SetNullQueue_Link(); //创建空队列
	linkQueueY = SetNullQueue_Link();//创建空队列
	EnQueue_link(linkQueueX, entryX);//迷宫入口点入队
	EnQueue_link(linkQueueY, entryY);//迷宫入口点入队
	mark[entryX][entryY] = 1;  //入口点设置标志位
	//如果队列不为空且还没有找到迷宫出口点
	while (!IsNullQueue_Link(linkQueueX))
	{
		preposX = FrontQueue_link(linkQueueX); //取队头
		DeQueue_link(linkQueueX);  //出队
		preposY = FrontQueue_link(linkQueueY); //取队头
		DeQueue_link(linkQueueY);  //出队
		printf("出队元素是：%d %d\t", preposX, preposY);
		//将与当前点相邻接且满足一定条件的点放入队列
		for (mov = 0; mov<8; mov++)
		{
			posX = preposX + direction[mov][0];
			posY = preposY + direction[mov][1];
			if (posX == exitX && posY == exitY)//到达出口点
			{
				preposMarkX[posX][posY] = preposX;
				preposMarkY[posX][posY] = preposY;
				printf("\n广度搜索迷宫路径如下：\n%d %d\t", posX, posY);
				//将路径逆序输出
				while (!(posX == entryX && posY == entryY))
				{
					//继续往前寻找前驱
					preposX = preposMarkX[posX][posY];
					preposY = preposMarkY[posX][posY];
					posX = preposX;
					posY = preposY;
					printf("%d %d\t", posX, posY);
				}
				return 1;
			}//end 64
			//如果能走，且没有被扩展过
			if (maze->data[posX][posY] == 0 && mark[posX][posY] == 0)
			{
				EnQueue_link(linkQueueX, posX); //入队扩展
				EnQueue_link(linkQueueY, posY);
				printf("入队元素是：%d %d\t", posX, posY);
				mark[posX][posY] = 1; //做标记
				preposMarkX[posX][posY] = preposX; //记录前驱
				preposMarkY[posX][posY] = preposY;
			} //end 82
		}//end 60
	}//end 53
	return 0;
}