//д��������,�Զ��е����л����������в���
//Ҫ������һ��������ӣ�Ȼ����������е�����
#include<stdio.h>
#include<stdlib.h>
#include "LinkQueue.h"
void main()
{
	LinkQueue lqueue = SetNullQueue_Link(); //�����ն���
	int data;
	printf("��������ӵ�Ԫ�أ���0������");
	scanf_s("%d,", &data);
	while (data)
	{
		EnQueue_link(lqueue, data); //����
		scanf_s("%d,", &data);
	}
	printf("����Ԫ�ص�˳���ǣ�");
	while (!IsNullQueue_Link(lqueue))
	{
		printf("%d ", FrontQueue_link(lqueue)); //�����ͷԪ��
		DeQueue_link(lqueue);   //����
	}
	printf("\n");
}