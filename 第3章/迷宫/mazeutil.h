#ifndef MAZE_H_
#define MAZE_H_

// 迷宫的结构
typedef struct	MAZE_STRU
{
	int size;   // 迷宫大小 
	int **data; //二维数组保存迷宫结构 
}Maze;

// 函数功能：初始化迷宫，分配空间，并将所有点置为0
// 输入参数size：    迷宫大小
// 返回值： 用邻接矩阵表示的图
Maze* InitMaze(int size);

// 函数功能：读入迷宫结构，0代表可以走的路，1代表墙
// 输入参数maze：    二维数组的图
// 返回值： 无
void ReadMaze(Maze* maze);

// 函数功能：将迷宫的结构显示出来
// 输入参数maze：  迷宫
// 返回值： 无
void WriteMaze(Maze* maze);

// 函数功能：  广度优先搜索路径
// 输入参数maze：   迷宫结构
// 输入参数entryX    迷宫入口点的x坐标
// 输入参数entryY    迷宫入口点的y坐标
// 输入参数exitX    迷宫出口点的x坐标
// 输入参数exitY    迷宫出口点的y坐标
// 返回值：  没有路径返回0， 有路径返回1
int MazeBFS(int entryX, int entryY, int exitX, int exitY, Maze* maze);

// 函数功能：  深度度优先搜索路径
// 输入参数maze：   迷宫结构
// 输入参数entryX    迷宫入口点的x坐标
// 输入参数entryY    迷宫入口点的y坐标
// 输入参数exitX    迷宫出口点的x坐标
// 输入参数exitY    迷宫出口点的y坐标
// 返回值：  没有路径返回0， 有路径返回1
int MazeDFS(int entryX, int entryY, int exitX, int exitY, Maze* maze);

#endif