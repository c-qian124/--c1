#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"
#include "BinTreeThread.h"
//AB@D@@CE@@@
void main()
{    
   	BinTreeNode *bt;
	printf("������������������н�����������\n");
	bt = CreateBinTree();
	printf("������������");
	Create_InorderThread(bt);
	printf("\n������������������\n");
	Inorder_ThreadBinTree(bt);
}