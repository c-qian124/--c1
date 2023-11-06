#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"
#include "BinTreeThread.h"
//AB@D@@CE@@@
void main()
{    
   	BinTreeNode *bt;
	printf("输入二叉树的先序序列建立二叉树：\n");
	bt = CreateBinTree();
	printf("建立中序穿线树");
	Create_InorderThread(bt);
	printf("\n中序线索化二叉树：\n");
	Inorder_ThreadBinTree(bt);
}