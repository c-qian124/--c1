#ifndef MAZE_H_
#define MAZE_H_

// �Թ��Ľṹ
typedef struct	MAZE_STRU
{
	int size;   // �Թ���С 
	int **data; //��ά���鱣���Թ��ṹ 
}Maze;

// �������ܣ���ʼ���Թ�������ռ䣬�������е���Ϊ0
// �������size��    �Թ���С
// ����ֵ�� ���ڽӾ����ʾ��ͼ
Maze* InitMaze(int size);

// �������ܣ������Թ��ṹ��0��������ߵ�·��1����ǽ
// �������maze��    ��ά�����ͼ
// ����ֵ�� ��
void ReadMaze(Maze* maze);

// �������ܣ����Թ��Ľṹ��ʾ����
// �������maze��  �Թ�
// ����ֵ�� ��
void WriteMaze(Maze* maze);

// �������ܣ�  �����������·��
// �������maze��   �Թ��ṹ
// �������entryX    �Թ���ڵ��x����
// �������entryY    �Թ���ڵ��y����
// �������exitX    �Թ����ڵ��x����
// �������exitY    �Թ����ڵ��y����
// ����ֵ��  û��·������0�� ��·������1
int MazeBFS(int entryX, int entryY, int exitX, int exitY, Maze* maze);

// �������ܣ�  ��ȶ���������·��
// �������maze��   �Թ��ṹ
// �������entryX    �Թ���ڵ��x����
// �������entryY    �Թ���ڵ��y����
// �������exitX    �Թ����ڵ��x����
// �������exitY    �Թ����ڵ��y����
// ����ֵ��  û��·������0�� ��·������1
int MazeDFS(int entryX, int entryY, int exitX, int exitY, Maze* maze);

#endif