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
		BT->leftchild = CreateBinTree_Recursion(); /* 构造左子树 */
		BT->rightchild = CreateBinTree_Recursion(); /* 构造右子树 */
	}
	return BT;
}
//第一种迭代算法，非教材的改进算法
void PreOrder_NRecursion1(BinTree bt)//先根遍历非递归实现
{
	LinkStack lstack; //定义链栈
	lstack = SetNullStack_Link(); //初始化栈
	BinTreeNode *p;
	Push_link(lstack, bt); //根结点入栈
	while (!IsNullStack_link(lstack))
	{
		p = Top_link(lstack);
		Pop_link(lstack);
		printf("%c", p->data);          //访问结点
		if (p->rightchild)
			Push_link(lstack, p->rightchild);//右子树不空，进栈
		if (p->leftchild)
			Push_link(lstack, p->leftchild);//左子树不空，进栈
	}
}

//第二种迭代算法，非教材的改进算法,相对于第一种迭代，减少了进栈的结点
void PreOrder_NRecursion2(BinTree bt)
{
	LinkStack lstack; //定义链栈
	BinTreeNode *p = bt;
	lstack = SetNullStack_Link(); //初始化栈
	if (bt == NULL) return;
	Push_link(lstack, bt);
	while (!IsNullStack_link(lstack))
	{
		p = Top_link(lstack);
		Pop_link(lstack);
		while (p)
		{
			printf("%c", p->data); //访问结点
			if (p->rightchild)    //右孩子是空，不用进栈
				Push_link(lstack, p->rightchild);
			p = p->leftchild;
		}
	} 
}

//非教材的改进算法
void InOrder_NRecursion(BinTree bt)//中根遍历非递归实现
{
	LinkStack lstack; //定义链栈
	lstack = SetNullStack_Link(); //初始化栈
	BinTree p;
	p = bt;
	if (p == NULL) return;
	Push_link(lstack, bt); //根结点入栈
	p = p->leftchild; //进入左子树
	while (p||!IsNullStack_link(lstack))
	{
		while (p != NULL)
		{
			Push_link(lstack, p);
			p = p->leftchild;
		}
		p = Top_link(lstack);
		Pop_link(lstack);
		printf("%c", p->data);  //访问结点
		p = p->rightchild;//右子树非空，扫描右子树
	} 
}

//后根遍历非递归实现，进栈出栈各一次
void PostOrder_NRecursion(BinTree bt)
{
	BinTree p = bt;
	LinkStack lstack; //定义链栈
	if (bt == NULL) return;
	lstack = SetNullStack_Link(); //初始化栈
	while (p != NULL || !IsNullStack_link(lstack))
	{
		while (p != NULL)
		{
			Push_link(lstack, p);
			p = p->leftchild ? p->leftchild : p->rightchild;
		}
		p = Top_link(lstack);
		Pop_link(lstack);
		printf("%c", p->data);  //访问结点
		if (!IsNullStack_link(lstack) && (Top_link(lstack)->leftchild == p))
			p = (Top_link(lstack))->rightchild;  //从左子树退回，进入右子树
		else p = NULL;           //从右子树退回，则退回上一层
	}
}