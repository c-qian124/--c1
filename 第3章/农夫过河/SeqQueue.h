#ifndef SEQQUEUE_H
#define SEQQUEUE_H

typedef int DataType;

 struct Queue
 {
	 int Max;  //ѭ�����е��������
	 int f;   //��ͷ
	 int r;   //��β
	 DataType *elem; //����Ԫ����ʼλ��
 };
typedef struct Queue *SeqQueue;

//�������ܣ�������ѭ������
//��������� ��
//����ֵ��    �յ�ѭ������
SeqQueue SetNullQueue_seq(int m);

//�������ܣ��ж�һ��ѭ�������Ƿ�Ϊ��
//�������squeue�� ѭ������ָ��
//����ֵ��    �ն��з���1�����򷵻�0
int IsNullQueue_seq(SeqQueue squeue);

//�������ܣ�����
//�������squeue�� ѭ������ָ��
//�������x�� ����Ԫ��
//����ֵ��    ��
void EnQueue_seq(SeqQueue squeue, DataType x);

//�������ܣ�����
//�������squeue�� ѭ������ָ��
//����ֵ��    ��
void DeQueue_seq(SeqQueue squeue);

//�������ܣ����ͷԪ�ص�ֵ
//�������squeue�� ѭ������ָ��
//����ֵ��    ��
DataType FrontQueue_seq(SeqQueue squeue);

#endif