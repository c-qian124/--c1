#include<stdio.h>
#include<stdlib.h>
#include "LinkList.h" //注意包含该头文件
void main()
{
	LinkList head = NULL;
	PNode p = NULL;
	head = SetNullList_Link();
	printf("判断链表是否为空，1为空，0为非空： ");
	printf("%d\n", IsNull_Link(head));
	CreateList_Head(head);
	//CreateList_Tail(head);
	printf("头插法建立完成后的链表：");
	//printf("尾插法建立完成后的链表：");
	print(head);
	p = Locate_Link(head, 5);
	printf("\n元素5在内存中的位置：");
	printf("%p", p);
	InsertPost_link(head, p, 99);
	printf("\n在5后面插入99后的链表：");
	print(head);
	DelNode_Link(head, 99);
	printf("\n删除99后的链表：");
	print(head);
	printf("\n");
	DestoryList_Link(head);
}
