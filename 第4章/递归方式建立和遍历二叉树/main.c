#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"
void main()
{
	BinTree bt = NULL;
	printf("������������������У�\n");
	bt = CreateBinTree_Recursion();
	printf("����������ʽ�洢�ṹ������ɣ�\n");
	printf("�ö������������������Ϊ��\n");
	PreOrder_Recursion(bt);
	printf("\n");
	printf("�ö��������������Ϊ��\n");
	InOrder_Recursion(bt);
	printf("\n");
	printf("�ö������ĺ������Ϊ��\n");
	PostOrder_Recursion(bt);
	printf("\n");
	DestroyBinTree(bt);
}
