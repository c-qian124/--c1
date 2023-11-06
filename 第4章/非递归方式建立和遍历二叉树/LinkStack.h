#ifndef LinkStack_H
#define LinkStack_H

#include "BinTreeStack.h"
typedef BinTree DataTypeStack;
struct Node{
	DataTypeStack  data;
	struct Node*  next;
};
typedef struct Node  *PNode;
typedef struct Node  *LinkStack;

//�������ܣ���������ջ
//��������� ��
//����ֵ��    �յ���ջ
LinkStack SetNullStack_Link(); 

//�������ܣ��ж�һ����ջ�Ƿ�Ϊ��
//�������top�� ��ջջ��ָ��
//����ֵ��    ��ջ����1�����򷵻�0
int IsNullStack_link(LinkStack top);

//�������ܣ���ջ
//�������top�� ��ջջ��ָ��
//�������x�� ��ջԪ��
//����ֵ��    ��
void Push_link(LinkStack top, DataTypeStack x);

//�������ܣ���ջ
//�������top�� ��ջջ��ָ��
//����ֵ��    ��
void Pop_link(LinkStack top);

//�������ܣ���ջ��Ԫ�ص�ֵ
//�������top�� ��ջջ��ָ��
//����ֵ��    ��
DataTypeStack Top_link(LinkStack top);

#endif
