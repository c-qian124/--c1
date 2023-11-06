#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef int DataType;
struct Node{
	DataType	  data;
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
void Push_link(LinkStack top, DataType x); 

//�������ܣ���ջ
//�������top�� ��ջջ��ָ��
//����ֵ��    ��
void Pop_link(LinkStack top);      // ɾ��ջ��Ԫ��

//�������ܣ���ջ��Ԫ�ص�ֵ
//�������top�� ��ջջ��ָ��
//����ֵ��    ��
DataType Top_link(LinkStack top); // ��ջ��Ԫ�ص�ֵ

#endif