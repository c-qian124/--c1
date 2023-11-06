#ifndef LINKLIST_H
#define LINKLIST_H

typedef int DataType; //���嵥�������������Ϊ����
struct Node{
	DataType	  data;  //������
	struct Node*  next;  //ָ����
};
typedef struct Node  *PNode;      //����ָ��ṹ���PNode����
typedef struct Node  *LinkList;   //������������

//�������ܣ� ��������ͷ���Ŀ�����
//������� �� ��
//����ֵ�� ������
LinkList SetNullList_Link();

//�������ܣ� �ж������Ƿ�Ϊ��
//������� �� ����
//����ֵ�� �շ���1�����򷵻�0
int IsNull_Link(LinkList llist); 

//�������ܣ� ͷ�巨����������
//������� �� ����ͷ���
//����ֵ�� ��
void CreateList_Head(struct Node *head); 

//�������ܣ� β�巨����������
//������� �� ����ͷ���
//����ֵ�� ��
void CreateList_Tail(struct Node* head); 

//�������ܣ� ��llist�����еĽ��p֮�����һ��ֵΪx�Ľ��
//������� llist �� ����
//�������p�� ����λ��
//�������x�� �������Ԫ��
//����ֵ�� �ɹ�����1�����򷵻�0
int InsertPost_link(LinkList llist, PNode p, DataType x);

//�������ܣ� ɾ����һ�������������ȵ�ֵ�Ľ��
//������� llist �� ����
//�������data�� ��ɾ����Ԫ��
//����ֵ�� ��
void DelNode_Link(struct Node *head, int data);

//�������ܣ���llist�����в���ֵΪx�Ľ��
//������� llist �� ����
//�������x�� ���ҵ�Ԫ��
//����ֵ�� ���ڴ��е�λ��
PNode Locate_Link(LinkList llist, DataType x);

//�������ܣ����������
//������� head �� ����ͷ���
//����ֵ�� ��
void print(LinkList head);

//�������ܣ��ͷŵ�����
//������� head �� ����ͷ���
//����ֵ�� ��
void DestoryList_Link(LinkList head);//�ͷŵ�����

#endif