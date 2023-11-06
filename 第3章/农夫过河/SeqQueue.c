#include <stdio.h>
#include <stdlib.h>
#include "SeqQueue.h"
SeqQueue SetNullQueue_seq(int m) //�����ն���
{
	SeqQueue squeue;
	squeue = (SeqQueue)malloc(sizeof(struct Queue));
	if (squeue == NULL)
	{
		printf("Alloc failure\n");
		return NULL;
	}
	squeue->elem = (int*)malloc(sizeof(DataType)*m);
	if (squeue->elem != NULL)
		{
			squeue->Max = m;
			squeue->f = 0;  
			squeue->r = 0;
			return squeue;
		}
}
int IsNullQueue_seq(SeqQueue squeue) //�ж϶����Ƿ�Ϊ��
{
	return (squeue->f == squeue->r);
}

void EnQueue_seq(SeqQueue squeue, DataType x)  //���
{
	if ((squeue->r + 1) % squeue->Max == squeue->f)//�Ƿ���
		printf("It is FULL Queue!");
	else{
		squeue->elem[squeue->r] = x;
		squeue->r = (squeue->r + 1) % (squeue->Max);
	}
}

void DeQueue_seq(SeqQueue squeue)  //����
{
	//if(paqu->f == paqu->r)//�Ƿ��
		//printf("empty queue");
	if (IsNullQueue_seq(squeue))
		printf("It is empty queue!\n");
	else
		squeue->f = (squeue->f + 1) % (squeue->Max);
}

DataType FrontQueue_seq(SeqQueue squeue) //���ͷԪ��
{
	if (squeue->f == squeue->r)
	{
		printf("It is empty queue!\n");
	}
	else
	{
		return(squeue->elem[squeue->f]);
	}
}