#include <stdio.h>
#include <stdlib.h>
#include "BinTreeThread.h"
#include "LinkStack.h"
BinTree CreateBinTree()
{
	char ch;
	BinTree BT;
	scanf_s("%c", &ch);
	if (ch == '@')
		BT = NULL;
	else
	{
		BT = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		BT->data = ch;
		BT->ltag = 0;
		BT->rtag = 0;
		BT->leftchild = CreateBinTree(); /* ���������� */
		BT->rightchild = CreateBinTree(); /* ���������� */
	}
	return BT;
}

void Create_InorderThread(BinTree bt)
{
	LinkStack st = SetNullStack_Link();
	BinTreeNode *p, *pr, *q;
	if (bt == NULL) return;
	p = bt;
	pr = NULL;
	do{
		while (p != NULL)
		{ 
			Push_link(st, p); 
			p = p->leftchild; 
		}
		p = Top_link(st);
		Pop_link(st);
		if (pr != NULL)
		{
			if (pr->rightchild == NULL)
			{ pr->rightchild = p; pr->rtag = 1; }
			if (p->leftchild == NULL)
			{ p->leftchild = p; p->ltag = 1; }
		}
		pr = p; 
		p = p->rightchild;
	} while (!IsNullStack_link(st) || p != NULL);
	p = bt; q = bt;
	while (p->leftchild != NULL) p = p->leftchild;
	p->ltag = 1;
	while (q->rightchild != NULL) q = q->rightchild;
	q->rtag = 1;
}

void Inorder_ThreadBinTree(BinTree bt)
{
	BinTreeNode  *p;
	if (bt == NULL) return;
	p = bt;
	/* ˳������һֱ�����ҵ�һ����� */
	while (p->leftchild != NULL && p->ltag == 0)
		p = p->leftchild;
	while (p != NULL)
	{
		printf("%c  ", p->data);
		printf("%d  ", p->ltag);
		printf("%d\n", p->rtag);
		if (p->rightchild != NULL &&p->rtag == 0)   /* ��������������ʱ */
		{
			p = p->rightchild;
			while (p->leftchild != NULL && p->ltag == 0)
				/* ˳��������������һֱ���� */
				p = p->leftchild;
		}
		else  p = p->rightchild;    /* ˳�������� */
	}//while 
}