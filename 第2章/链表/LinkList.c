#include<stdio.h>
#include<stdlib.h>
#include "LinkList.h" //����ǰ�涨���ͷ�ļ�����˫���ţ������c��ķ�����ͬ
LinkList SetNullList_Link() //��������ͷ���Ŀ�����
{
	LinkList head = (LinkList)malloc(sizeof(struct Node));
	if (head != NULL) head->next = NULL;
	else printf("alloc failure");
	return head; //����ͷָ��
}
int IsNull_Link(LinkList llist) //�ж������Ƿ�Ϊ��
{
	return(llist->next == NULL);
}
void CreateList_Head(struct Node *head)//ͷ�巨����������
{
	PNode p = NULL;  int data;
	printf("�������������ݽ���������-1����\n");
	scanf_s("%d", &data);
	while (data != -1){ /*����ռ䣬��ֵ*/
		p = (struct Node*)malloc(sizeof(struct Node));
		p->data = data;  //��������ֵ
		p->next = head->next;   //next��ֵ
		head->next = p;
		scanf_s("%d", &data);
	}
}
void CreateList_Tail(struct Node* head)// β�巨����������
{
	PNode p = NULL; PNode q = head; int data;
	printf("�������������ݽ���������-1����\n");
	scanf_s("%d", &data);
	while (data != -1){   //����ռ䣬��ֵ
		p = (struct Node*)malloc(sizeof(struct Node));
		p->data = data;
		p->next = NULL;
		q->next = p;
		q = p;
		scanf_s("%d", &data);
	}
}
//��llist�����е�pλ��֮�����ֵΪx�Ľ��
int InsertPost_link(LinkList llist, PNode p, DataType x)
{
	PNode q;
	if (p == NULL) { printf("para failure!\n"); return 0; }
	q = (PNode)malloc(sizeof(struct Node));
	if (q == NULL){
		printf("out of space!\n"); return 0;
	}
	else {
		q->data = x;
		q->next = p->next;
		p->next = q;
		return 1;
	}
}
//ɾ����һ�������������ȵ�ֵ�Ľ��
void DelNode_Link(struct Node *head, int data)
{
	PNode p = head->next; PNode beforeP = head;
	while (p != NULL){
		if (p->data == data){
			beforeP->next = p->next;
			free(p);
			break;
		}
		else{
			beforeP = p;
			p = p->next;
		}
	}
}
//��llist�����в���ֵΪx�Ľ�㣬���������ڴ��е�λ��
PNode Locate_Link(LinkList llist, DataType x)
{
	PNode p;
	if (llist == NULL) return NULL;
	p = llist->next;
	while (p != NULL&&p->data != x) p = p->next;
	return p;
}
void print(LinkList head)    //���������
{
	PNode  p = head->next;
	while (p){
		printf("%d  ", p->data);
		p = p->next;
	}
}
void DestoryList_Link(LinkList head)//�ͷŵ�����
{
	PNode  pre = head; PNode p = pre->next;
	while (p){
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
