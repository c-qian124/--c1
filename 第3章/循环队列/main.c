//д��������,�Զ��е����л����������в���
//Ҫ������һ��������ӣ�Ȼ����������е�����
#include<stdio.h>
#include<stdlib.h>
#include "SeqQueue.h"
void main()
{
		
	SeqQueue squeue = SetNullQueue_seq(5); //�����ն���
	int data;
	printf("��������ӵ�Ԫ�أ���0������");
	scanf_s("%d,", &data);
	while (data)
	{
		EnQueue_seq(squeue, data);      //����
		scanf_s("%d,", &data);
	}
	printf("����Ԫ�ص�˳���ǣ�");
	while (!IsNullQueue_seq(squeue))
	{
		printf("%d ", FrontQueue_seq(squeue)); //�����ͷԪ��
		DeQueue_seq(squeue);   //����
	}
	printf("\n");
}