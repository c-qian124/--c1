//д��������,��ջ�����л����㷨���в���
//Ҫ������һ�����У�ͨ��ջʵ�����з�ת
#include <stdlib.h>
#include <stdio.h>
#include "LinkStack.h"
void main()
{
	LinkStack p = SetNullStack_Link(5); //����һ����ջ
	int data;
	printf("�������ջ��Ԫ�أ���0������");
	scanf_s("%d,", &data);
	while (data)
	{
		Push_link(p, data);      //��ջ
		scanf_s("%d,", &data);
	}
	printf("��ջԪ�ص�˳���ǣ�");
	while (!IsNullStack_link(p))      //�Ƿ��ջ
	{
		printf("%d ", Top_link(p)); //ȡջ��Ԫ��
		Pop_link(p);                //��ջ
	}
	printf("\n");
}