#ifndef POLYADD_H
#define POLYADD_H

struct tagNode
{
	float coef;               //ϵ��
	int exp;                 // ָ��
	struct tagNode *next;   //ָ����
};
typedef struct tagNode Node;
typedef struct tagNode*  PNode;

//�������ܣ��������뵽������ʵ�λ�ã�����ָ����������
//�������head�� ����ͷ���
//������� pnode�� ������Ľ��
//����ֵ��  ��
void insertList(PNode head, PNode pnode);

//�������ܣ�����insertLis()����������ʽ����
//�������head�� ����ͷ���
//����ֵ��  ��
void CreateList(PNode head);

//�������ܣ���������ʽ���
//�������pa�� ����ʽ1
//�������pb�� ����ʽ2
//����ֵ��  ��
void Add_Poly(PNode pa, PNode pb);

//�������ܣ��������ʽ����
//�������head�� ����ͷ���
//����ֵ��  ��
void printLinkedList(PNode head);

#endif