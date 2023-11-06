#ifndef LINKLQUEUE_H
#define LINKLQUEUE_H
typedef int DataType;
struct Node
{
	DataType data;   //������
	struct Node	*next;
};
typedef struct Node *PNode;
struct Queue
{	PNode		f;
	PNode		r;
};
typedef struct Queue *LinkQueue;

//�������ܣ�������������
//��������� ��
//����ֵ��    �յ�������
LinkQueue SetNullQueue_Link();

//�������ܣ��ж�һ���������Ƿ�Ϊ��
//�������lqueue�� ����ָ��
//����ֵ��    �ն��з���1�����򷵻�0
int IsNullQueue_Link(LinkQueue lqueue);

//�������ܣ�����
//�������lqueue�� ����ָ��
//�������x�� ����Ԫ��
//����ֵ��    ��
void EnQueue_link(LinkQueue lqueue, DataType x);

//�������ܣ�����
//�������lqueue�� ����ָ��
//����ֵ��    ��
void DeQueue_link(LinkQueue lqueue);

//�������ܣ����ͷԪ�ص�ֵ
//�������lqueue�� ����ָ��
//����ֵ��    ��
DataType  FrontQueue_link(LinkQueue lqueue);

#endif