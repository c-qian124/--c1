#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"
//构建二叉树；特别注意这里的返回值
BinTree CreateBinTree_Recursion()
{
	char ch;
	BinTree bt;
	scanf_s("%c", &ch);
	if (ch == '@')
		bt = NULL;
	else
	{
		bt = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		bt->data = ch;
		bt->leftchild = CreateBinTree_Recursion();
		bt->rightchild = CreateBinTree_Recursion();
	}
	return bt;
}
void PreOrder_Recursion(BinTree bt)  //递归先序遍历
{
	if (bt == NULL) return;
	printf("%c", bt->data);
	PreOrder_Recursion(bt->leftchild);
	PreOrder_Recursion(bt->rightchild);
}
void InOrder_Recursion(BinTree bt)  //递归中序遍历
{
	if (bt == NULL) return;
	InOrder_Recursion(bt->leftchild);
	printf("%c", bt->data);
	InOrder_Recursion(bt->rightchild);
}
void PostOrder_Recursion(BinTree bt)  //递归后序遍历
{
	if (bt == NULL) return;
	PostOrder_Recursion(bt->leftchild);
	PostOrder_Recursion(bt->rightchild);
	printf("%c", bt->data);
}
void DestroyBinTree(BinTree bt)  //销毁二叉树
{
	if (bt != NULL)
	{
		DestroyBinTree(bt->leftchild);
		DestroyBinTree(bt->rightchild);
		free(bt);
	}
}
