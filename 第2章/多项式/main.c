#include <stdio.h>
#include <stdlib.h>
#include "PolyAdd.h"

void main()
{
	PNode head1 = (PNode)malloc(sizeof(struct tagNode));//��ͷָ�����ռ�
	PNode head2 = (PNode)malloc(sizeof(struct tagNode));//��ͷָ�����ռ�
	CreateList(head1);
	CreateList(head2);
	printf("\n");
	Add_Poly(head1, head2);//����ʽ���
	printf("����ʽ��ӵĽ��Ϊ��\n");
	printLinkedList(head1);
	printf("\n");
}