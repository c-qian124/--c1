#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"
#include "BinTreeStack.h"
/*AB@D@@CE@@@*/
void main()
{    
	BinTreeNode *bt;
	printf("输入二叉树的先序序列：");
	bt = CreateBinTree_Recursion();
	printf("该二叉树的先序遍历序列为：");
	PreOrder_NRecursion1(bt);
	printf("\n该二叉树的中序遍历序列为：");
	InOrder_NRecursion(bt);
	printf("\n该二叉树的后序遍历序列为：");
	PostOrder_NRecursion(bt);
	printf("\n");
}