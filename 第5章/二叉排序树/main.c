#include<stdio.h>
#include<stdlib.h>
#include"BSTree.h"

//40 10 5 2 -1 -1 8 -1 9 -1 -1 -1 55 45 -1 48 47 -1 -1 5 -1 -1 60 -1 70 -1 -1
void main()
{
	BinSearTree bt; int n;
	printf("������������������������У�\n");
	bt = create();
	printf("����Ҫ���ҵ�Ԫ��,���ڷ���1�������ڷ���0�����룺");
	scanf("%d",&n);
	printf("%d\n", BSTSearch(bt, n));
	printf("����Ҫ�����Ԫ�أ��ɹ�������ڷ���1�����򷵻�0��");
	scanf("%d", &n);
	printf("%d\n", BSTInsert(bt, n));
	printf("������������������������У�\n");
	Inorder(bt);
	printf("\n��һ��ɾ������������Ҫɾ����Ԫ��,�ɹ�����1�����ɹ�����0��");
	scanf("%d", &n);
	printf("%d\n",BSTDelete1(&bt, n));
	printf("������������������������У�\n");
	Inorder(bt);
	printf("\n�ڶ���ɾ������������Ҫɾ����Ԫ��,�ɹ�����1�����ɹ�����0��");
	scanf("%d", &n);
	printf("%x\n", BSTDelete2(&bt, n));
	printf("������������������������У�\n");
	Inorder(bt);
}