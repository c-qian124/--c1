#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"
#include "BinTreeStack.h"
/*AB@D@@CE@@@*/
void main()
{    
	BinTreeNode *bt;
	printf("������������������У�");
	bt = CreateBinTree_Recursion();
	printf("�ö������������������Ϊ��");
	PreOrder_NRecursion1(bt);
	printf("\n�ö������������������Ϊ��");
	InOrder_NRecursion(bt);
	printf("\n�ö������ĺ����������Ϊ��");
	PostOrder_NRecursion(bt);
	printf("\n");
}