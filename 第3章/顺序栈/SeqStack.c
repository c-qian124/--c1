#include <stdlib.h>
#include <stdio.h>
#include "SeqStack.h"
SeqStack SetNullStack_Seq(int m)  //������˳��ջ
{
	SeqStack sstack = (SeqStack)malloc(sizeof(struct SeqStack));
	if (sstack != NULL){
		sstack->elem = (int*)malloc(sizeof(int)*m);
		if (sstack->elem != NULL){
			sstack->MAX = m;
			sstack->top = -1;
			return(sstack);
		}
		else {
			free(sstack);
			return NULL;
		}
	}
	else{
		printf("out of space");
		return NULL;
	}
}

int IsNullStack_seq(SeqStack sstack) //�ж�һ��ջ�Ƿ�Ϊ��
{
	return(sstack->top == -1);
}
void Push_seq(SeqStack sstack, int x)  //��ջ
{
	if (sstack->top >= (sstack->MAX - 1))  //���ջ�Ƿ���
		printf("overflow! \n");
	else{
		sstack->top++; //�����������޸�ջ������
		sstack->elem[sstack->top] = x;//��Ԫ��x�ŵ�ջ��������λ����
	}
}
void Pop_seq(SeqStack sstack)//��ջ
{
	if (IsNullStack_seq(sstack)) //�ж�ջ�Ƿ�Ϊ��
		printf("Underflow!\n");
	else
		sstack->top = sstack->top - 1;//ջ����1
}
DataType Top_seq(SeqStack sstack)//��ջ��Ԫ�ص�ֵ
{
	if (IsNullStack_seq(sstack))//�ж�sstack��ָ��ջ�Ƿ�Ϊ��ջ
	{
		printf("it is empty");
		return 0;
	}
	else
		return sstack->elem[sstack->top];
}