#include<stdio.h>
#include<stdlib.h>
#include "LinkList.h" //ע�������ͷ�ļ�
void main()
{
	LinkList head = NULL;
	PNode p = NULL;
	head = SetNullList_Link();
	printf("�ж������Ƿ�Ϊ�գ�1Ϊ�գ�0Ϊ�ǿգ� ");
	printf("%d\n", IsNull_Link(head));
	CreateList_Head(head);
	//CreateList_Tail(head);
	printf("ͷ�巨������ɺ������");
	//printf("β�巨������ɺ������");
	print(head);
	p = Locate_Link(head, 5);
	printf("\nԪ��5���ڴ��е�λ�ã�");
	printf("%p", p);
	InsertPost_link(head, p, 99);
	printf("\n��5�������99�������");
	print(head);
	DelNode_Link(head, 99);
	printf("\nɾ��99�������");
	print(head);
	printf("\n");
	DestoryList_Link(head);
}
