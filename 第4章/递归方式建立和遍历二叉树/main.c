#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"
void main()
{
	BinTree bt = NULL;
	printf("输入二叉树的先序序列：\n");
	bt = CreateBinTree_Recursion();
	printf("二叉树的链式存储结构建立完成！\n");
	printf("该二叉树的先序遍历序列为：\n");
	PreOrder_Recursion(bt);
	printf("\n");
	printf("该二叉树的中序遍历为：\n");
	InOrder_Recursion(bt);
	printf("\n");
	printf("该二叉树的后序遍历为：\n");
	PostOrder_Recursion(bt);
	printf("\n");
	DestroyBinTree(bt);
}
