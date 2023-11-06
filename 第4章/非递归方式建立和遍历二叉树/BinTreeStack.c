#include <stdio.h>
#include <stdlib.h>
#include "BinTreeStack.h"
#include "LinkStack.h"
BinTree CreateBinTree_Recursion()
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
		BT->leftchild = CreateBinTree_Recursion(); /* ���������� */
		BT->rightchild = CreateBinTree_Recursion(); /* ���������� */
	}
	return BT;
}
//��һ�ֵ����㷨���ǽ̲ĵĸĽ��㷨
void PreOrder_NRecursion1(BinTree bt)//�ȸ������ǵݹ�ʵ��
{
	LinkStack lstack; //������ջ
	lstack = SetNullStack_Link(); //��ʼ��ջ
	BinTreeNode *p;
	Push_link(lstack, bt); //�������ջ
	while (!IsNullStack_link(lstack))
	{
		p = Top_link(lstack);
		Pop_link(lstack);
		printf("%c", p->data);          //���ʽ��
		if (p->rightchild)
			Push_link(lstack, p->rightchild);//���������գ���ջ
		if (p->leftchild)
			Push_link(lstack, p->leftchild);//���������գ���ջ
	}
}

//�ڶ��ֵ����㷨���ǽ̲ĵĸĽ��㷨,����ڵ�һ�ֵ����������˽�ջ�Ľ��
void PreOrder_NRecursion2(BinTree bt)
{
	LinkStack lstack; //������ջ
	BinTreeNode *p = bt;
	lstack = SetNullStack_Link(); //��ʼ��ջ
	if (bt == NULL) return;
	Push_link(lstack, bt);
	while (!IsNullStack_link(lstack))
	{
		p = Top_link(lstack);
		Pop_link(lstack);
		while (p)
		{
			printf("%c", p->data); //���ʽ��
			if (p->rightchild)    //�Һ����ǿգ����ý�ջ
				Push_link(lstack, p->rightchild);
			p = p->leftchild;
		}
	} 
}

//�ǽ̲ĵĸĽ��㷨
void InOrder_NRecursion(BinTree bt)//�и������ǵݹ�ʵ��
{
	LinkStack lstack; //������ջ
	lstack = SetNullStack_Link(); //��ʼ��ջ
	BinTree p;
	p = bt;
	if (p == NULL) return;
	Push_link(lstack, bt); //�������ջ
	p = p->leftchild; //����������
	while (p||!IsNullStack_link(lstack))
	{
		while (p != NULL)
		{
			Push_link(lstack, p);
			p = p->leftchild;
		}
		p = Top_link(lstack);
		Pop_link(lstack);
		printf("%c", p->data);  //���ʽ��
		p = p->rightchild;//�������ǿգ�ɨ��������
	} 
}

//��������ǵݹ�ʵ�֣���ջ��ջ��һ��
void PostOrder_NRecursion(BinTree bt)
{
	BinTree p = bt;
	LinkStack lstack; //������ջ
	if (bt == NULL) return;
	lstack = SetNullStack_Link(); //��ʼ��ջ
	while (p != NULL || !IsNullStack_link(lstack))
	{
		while (p != NULL)
		{
			Push_link(lstack, p);
			p = p->leftchild ? p->leftchild : p->rightchild;
		}
		p = Top_link(lstack);
		Pop_link(lstack);
		printf("%c", p->data);  //���ʽ��
		if (!IsNullStack_link(lstack) && (Top_link(lstack)->leftchild == p))
			p = (Top_link(lstack))->rightchild;  //���������˻أ�����������
		else p = NULL;           //���������˻أ����˻���һ��
	}
}