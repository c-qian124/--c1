//д��������,��ջ�����л����㷨���в���
//Ҫ������һ�����У�ͨ��ջʵ�����з�ת
#include <stdlib.h>
#include <stdio.h>
#include "SeqStack.h"
void main()
{
	SeqStack p = SetNullStack_Seq(5); //����һ����ջ
	int data;
	printf("�������ջ��Ԫ�أ���0������");
	scanf_s("%d,", &data);
	while (data)
	{
		Push_seq(p, data);      //��ջ
		scanf_s("%d,", &data);
	}
	printf("��ջԪ�ص�˳���ǣ�");
	while (!IsNullStack_seq(p))      //�Ƿ��ջ
	{
		printf("%d ", Top_seq(p)); //ȡջ��Ԫ��
		Pop_seq(p);                //��ջ
	}
	printf("\n");
}