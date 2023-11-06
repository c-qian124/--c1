#include <stdio.h>
#include <stdlib.h>
#include "PolyAdd.h"
//将结点插入到链表的适当位置，这是一个指数升序排列的链表
void insertList(PNode head, PNode pnode)
{
	PNode pPre = head;
	while (pPre->next != NULL)
	{
		if (pPre->next->exp>pnode->exp)
		{
			pnode->next = pPre->next;
			pPre->next = pnode;
			break;
		}
		pPre = pPre->next;
	}
	if (pPre->next == NULL)//待插入结点的指数最大，直接插入结点到最后
	{
		pPre->next = pnode;
	}
}
void CreateList(PNode head)
{
	int exp;//指数
	float coef;//系数
	PNode pTemp = NULL;
	head->next = NULL;//分配好空间，指针域赋值为空
	//读入多项式
	printf("请输入要放入链表1中的数据，顺序为系数，指数，若多项式结束，则以0，0结尾：\n");
	//读入数据，以0，0结尾，把数据插入链表中
	scanf_s("%f,%d", &coef, &exp);
	while (coef != 0 || exp != 0)
	{
		pTemp = (PNode)malloc(sizeof(struct tagNode));
		pTemp->coef = coef;
		pTemp->exp = exp;
		pTemp->next = NULL;
		insertList(head, pTemp);
		scanf_s("%f,%d", &coef, &exp);
	}
}
void printLinkedList(PNode head)//输出链表
{
	PNode temp = head->next;//链表的第一个节点
	while (temp != NULL)
	{
		printf("%0.0f ", temp->coef);
		printf("%d,", temp->exp);
		temp = temp->next;
	}
	printf("\n");
}
void Add_Poly(PNode pa, PNode pb)//两个多项式相加
{
	PNode p = pa->next;/*链表1，和多项式结果放在在链表1*/
	PNode q = pb->next;/*链表2*/
	PNode pre = pa;
	PNode u;/*临时变量*/
	float x;
	while (p != NULL && q != NULL)/*当两个链表都不为空*/
	{
		if (p->exp<q->exp)
		{/*比较链表1跟链表2当前节点的指数大小，链表1也是存放结果的地方*/
			pre = p; p = p->next;/*p指向要比较的下一个结点。pre指向的是结果链表的最后一个结点*/
		}
		else if (p->exp == q->exp)
		{/*假如链表1和链表2的指数相等，就要系数相加*/
			x = p->coef + q->coef;
			if (x != 0)/*相加后的系数不为0，有必要保留一个结点就可以了*/
			{
				p->coef = x; pre = p;
			}
			else
			{/*相加后系数是0，不需要保留任何一个结点，在这里删除链表1的结点，下面删除链表2的结点*/
				pre->next = p->next;/*保持链表1的连续性*/
				free(p);
			}
			p = pre->next;/*p指向要比较的下一个结点*/
			/*下面的代码是进行链表2结点的删除工作，因为指数相等，仅仅需要保留一个结点就可以了*/
			/*而结果直接保存在链表1中，所以，删除链表2的结点*/
			u = q;
			q = q->next;
			free(u);
		}
		else/*如果链表2的当前节点指数小，那么要把链表2的当前节点加入到结果链表中（即是链表1）*/
		{/*相当于把结点插入到链表1中，用u作为临时变量，保存链表2的下一个当前节点的位置*/
			u = q->next;
			q->next = p;
			pre->next = q;
			pre = q;
			q = u;
		}
	}
	if (q)/*如果链表2比链表1长，那么需要把链表2多余的部分加入结果链表中*/
		/*链表1比链表2长，则什么都不用做*/
		pre->next = q;
	free(pb);
}