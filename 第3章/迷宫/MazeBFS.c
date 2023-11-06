#include <stdlib.h>
#include <stdio.h>
#include "mazeutil.h"
#include "LinkQueue.h" //����������ͷ�ļ�

//�Թ���ȱ����㷨
int MazeBFS(int entryX, int entryY, int exitX, int exitY, Maze* maze)
{
	int direction[8][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 },
	{ 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };
	//�����������У��ֱ𱣴�ȴ���չ�ĵ㣨x��y��ֵ
	LinkQueue linkQueueX = NULL;
	LinkQueue linkQueueY = NULL;
	int posX, posY;//��ʱ��������ŵ����꣨x��y��
	int preposX, preposY;
	int **preposMarkX;//��¼�Թ����߹����е�ǰ���xֵ
	int **preposMarkY;//��¼�Թ����߹����е�ǰ���yֵ
	int **mark;//��Ƕ�ά���飬�����Щ���߹��������ظ���
	int i, j, mov;
	//�����ǰ��xֵ���������ռ� 
	preposMarkX = (int**)malloc(sizeof(int*)* maze->size);
	for (i = 0; i<maze->size; i++)
	{
		preposMarkX[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	//�����ǰ��yֵ���������ռ� 
	preposMarkY = (int**)malloc(sizeof(int*)* maze->size);
	for (i = 0; i<maze->size; i++)
	{
		preposMarkY[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	//������ǵĶ�ά�������ռ䣬������ֵ 
	mark = (int**)malloc(sizeof(int*)* maze->size);
	for (i = 0; i<maze->size; i++)
	{
		mark[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	for (i = 0; i<maze->size; i++)// ������Ԫ�����ó�ֵ
	{
		for (j = 0; j<maze->size; j++)
		{
			preposMarkX[i][j] = -1;
			preposMarkY[i][j] = -1;
			mark[i][j] = 0;
		}
	}
	linkQueueX = SetNullQueue_Link(); //�����ն���
	linkQueueY = SetNullQueue_Link();//�����ն���
	EnQueue_link(linkQueueX, entryX);//�Թ���ڵ����
	EnQueue_link(linkQueueY, entryY);//�Թ���ڵ����
	mark[entryX][entryY] = 1;  //��ڵ����ñ�־λ
	//������в�Ϊ���һ�û���ҵ��Թ����ڵ�
	while (!IsNullQueue_Link(linkQueueX))
	{
		preposX = FrontQueue_link(linkQueueX); //ȡ��ͷ
		DeQueue_link(linkQueueX);  //����
		preposY = FrontQueue_link(linkQueueY); //ȡ��ͷ
		DeQueue_link(linkQueueY);  //����
		printf("����Ԫ���ǣ�%d %d\t", preposX, preposY);
		//���뵱ǰ�����ڽ�������һ�������ĵ�������
		for (mov = 0; mov<8; mov++)
		{
			posX = preposX + direction[mov][0];
			posY = preposY + direction[mov][1];
			if (posX == exitX && posY == exitY)//������ڵ�
			{
				preposMarkX[posX][posY] = preposX;
				preposMarkY[posX][posY] = preposY;
				printf("\n��������Թ�·�����£�\n%d %d\t", posX, posY);
				//��·���������
				while (!(posX == entryX && posY == entryY))
				{
					//������ǰѰ��ǰ��
					preposX = preposMarkX[posX][posY];
					preposY = preposMarkY[posX][posY];
					posX = preposX;
					posY = preposY;
					printf("%d %d\t", posX, posY);
				}
				return 1;
			}//end 64
			//������ߣ���û�б���չ��
			if (maze->data[posX][posY] == 0 && mark[posX][posY] == 0)
			{
				EnQueue_link(linkQueueX, posX); //�����չ
				EnQueue_link(linkQueueY, posY);
				printf("���Ԫ���ǣ�%d %d\t", posX, posY);
				mark[posX][posY] = 1; //�����
				preposMarkX[posX][posY] = preposX; //��¼ǰ��
				preposMarkY[posX][posY] = preposY;
			} //end 82
		}//end 60
	}//end 53
	return 0;
}