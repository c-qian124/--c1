#ifndef SEQSTACK_H
#define SEQSTACK_H

typedef int DataType;
struct SeqStack
{
	int MAX;         //�������
	int top;         //ջ��ָ��
	DataType *elem;  //���Ԫ�ص���ʼָ��
};
typedef struct SeqStack *SeqStack;

//�������ܣ�������˳��ջ
//�������m�� ˳��ջ���������
//����ֵ��    �յ�˳��ջ
SeqStack SetNullStack_Seq(int m);

//�������ܣ��ж�һ��ջ�Ƿ�Ϊ��
//�������sstack�� ˳��ջ
//����ֵ��    ��ջ����1�����򷵻�0
int IsNullStack_seq(SeqStack sstack);

//�������ܣ���ջ
//�������sstack�� ˳��ջ
//�������x�� ��ջԪ��
//����ֵ��    ��
void Push_seq(SeqStack sstack, int x);

//�������ܣ���ջ
//�������sstack�� ˳��ջ
//����ֵ��    ��
void Pop_seq(SeqStack sstack);

//�������ܣ���ջ��Ԫ�ص�ֵ
//�������sstack�� ˳��ջ
//����ֵ��    ��
DataType Top_seq(SeqStack sstack);

#endif