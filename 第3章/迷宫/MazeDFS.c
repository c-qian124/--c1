#include <stdlib.h>
#include <stdio.h>
#include "mazeutil.h"
#include "linkstack.h" //������ջͷ�ļ�

//�Թ���ȱ����㷨
int MazeDFS(int entryX, int entryY, int exitX, int exitY, Maze* maze)
{
	int direction[8][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 },
	{ 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };
	//��������ջ���ֱ𱣴�·���е㣨x��y��ֵ
	LinkStack linkStackX = NULL;
	LinkStack linkStackY = NULL;
	int posX, posY;//��ʱ��������ŵ����꣨x��y��
	int preposX, preposY;
	int **mark; //��Ƕ�ά���飬�����Щ���߹��������ظ���
	int i, j;//ѭ������
	int mov;//�ƶ��ķ���
	// ������ǵĶ�ά�������ռ䣬������ֵ 
	mark = (int**)malloc(sizeof(int*)* maze->size);
	for (i = 0; i<maze->size; i++)
		mark[i] = (int*)malloc(sizeof(int)* maze->size);
	//������Ԫ�����ó�ֵ 
	for (i = 0; i<maze->size; i++)
	{
		for (j = 0; j<maze->size; j++)
			mark[i][j] = 0;
	}
	linkStackX = SetNullStack_Link(); //��ʼ��ջ
	linkStackY = SetNullStack_Link(); //��ʼ��ջ
	mark[entryX][entryY] = 1; //��ڵ����ñ�־λ
	Push_link(linkStackX, entryX); //��ڵ���ջ
	Push_link(linkStackY, entryY); //��ڵ���ջ
	//���ջ��Ϊ���һ�û���ҵ��Թ����ڵ�
	while (!IsNullStack_link(linkStackX))
	{
		preposX = Top_link(linkStackX);
		preposY = Top_link(linkStackY);
		Pop_link(linkStackX);
		Pop_link(linkStackY);
		//printf("��ջԪ����%d %d\t", preposX, preposY);	//���ջ��Ԫ��
		mov = 0;
		while (mov < 8)
		{
			posX = preposX + direction[mov][0];
			posY = preposY + direction[mov][1];
			if (posX == exitX && posY == exitY)//�����յ�
			{
				Push_link(linkStackX, preposX); //���ڵ���ջ
				Push_link(linkStackY, preposY); //���ڵ���ջ
				printf("\n��������Թ�·�����£�\n");
				printf("%d %d\t", exitX, exitY); //��ӡ��ڵ�
				while (!IsNullStack_link(linkStackX))//��·���������
				{
					posX = Top_link(linkStackX); //ȡջ��Ԫ��
					posY = Top_link(linkStackY);//ȡջ��Ԫ��
					Pop_link(linkStackX); //��ջ
					Pop_link(linkStackY); //��ջ
					printf("%d %d\t", posX, posY);	//���ջ��Ԫ��
				}//end 52
				return 1;
			}//end 46
			//����·������ͨ
			if (maze->data[posX][posY] == 0 && mark[posX][posY] == 0)
			{
				mark[posX][posY] = 1;
				Push_link(linkStackX, preposX);//��ջ
				Push_link(linkStackY, preposY);//��ջ
				//printf("��ջԪ����%d %d\t", preposX, preposY);	//���ջ��Ԫ��
				preposX = posX;
				preposY = posY;
				mov = 0;//�Ѿ���ǰ���ˣ���˷������´�0�ŷ���ʼ����
			}//end 63
			else
				mov++;  //������������
		}//end 42
	} //end 35
	return 0;
}