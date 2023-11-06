#include<stdio.h>
#include<stdlib.h>
#include"BSTree.h"

//40 10 5 2 -1 -1 8 -1 9 -1 -1 -1 55 45 -1 48 47 -1 -1 5 -1 -1 60 -1 70 -1 -1
void main()
{
	BinSearTree bt; int n;
	printf("输入二叉树排序树的先序序列：\n");
	bt = create();
	printf("输入要查找的元素,存在返回1，不存在返回0，插入：");
	scanf("%d",&n);
	printf("%d\n", BSTSearch(bt, n));
	printf("输入要插入的元素，成功插入存在返回1，否则返回0：");
	scanf("%d", &n);
	printf("%d\n", BSTInsert(bt, n));
	printf("二叉树排序树的中序遍历序列：\n");
	Inorder(bt);
	printf("\n第一种删除方法，输入要删除的元素,成功返回1，不成功返回0：");
	scanf("%d", &n);
	printf("%d\n",BSTDelete1(&bt, n));
	printf("二叉树排序树的中序遍历序列：\n");
	Inorder(bt);
	printf("\n第二种删除方法，输入要删除的元素,成功返回1，不成功返回0：");
	scanf("%d", &n);
	printf("%x\n", BSTDelete2(&bt, n));
	printf("二叉树排序树的中序遍历序列：\n");
	Inorder(bt);
}