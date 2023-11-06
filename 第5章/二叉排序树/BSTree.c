#include<stdio.h>
#include<stdlib.h>
#include"BSTree.h"

//创建二叉排序树
BinSearTree create() 
{
	BinSearTree bt;
	DataType key;
	scanf_s("%d", &key);
	if (key == -1)
		bt = NULL;
	else {
		bt = (BinSearTree)malloc(sizeof(struct BinSearTreeNode));
		bt->data = key;
		bt->leftchild = create();
		bt->rightchild = create();
	}
	return bt;
}

//中序遍历二叉排序树
void Inorder(BinSearTree ptree) 
{
	if (ptree == NULL)
		return;
	Inorder(ptree->leftchild);
	printf("%d ", ptree->data);
	Inorder(ptree->rightchild);
}

//检索二叉排序树
BSTreeNode BSTSearch(BinSearTree bt, DataType key)
{
	BSTreeNode p, parent;
	p = bt; parent = p;
	while (p)
	{
		parent = p;
		if (p->data == key) {
			printf("exist this key\n");
			return NULL;
		}
		if (p->data > key)
			p = p->leftchild;
		else
			p = p->rightchild;
	}//end 35
	return parent;
}

//插入算法
int BSTInsert(BinSearTree bt, DataType key)
{
	BSTreeNode p, temp;
	temp = BSTSearch(bt, key);
	if (temp == NULL) {
		printf("exist this key\n");
		return 0;
	}
	p = (BSTreeNode*)malloc(sizeof(struct BinSearTreeNode));
	if (p == NULL) {
		printf("Alloc Failure!\n");
		return 0;
	}
	p->data = key;
	p->leftchild = p->rightchild = NULL;
	if (key < temp->data)
		temp->leftchild = p;
	else
		temp->rightchild = p;
	return 1;
}

//第一种删除算法
int BSTDelete1(BinSearTree *bt, DataType key)
{
	//parent记录p的父结点，maxpl记录p的左子树中的关键码最大结点
	BSTreeNode parent, p, maxpl;
	p = *bt;
	parent = NULL;
	while (p != NULL) //查找被删除的结点
	{
		if (p->data == key) break; //如果查找到了，跳出循环
		parent = p;
		if (p->data > key)
			p = p->leftchild;
		else
			p = p->rightchild;
	}//end 82
	if (p == NULL) {
		printf(" not exist！\n");
		return 0;
	}
	if (p->leftchild == NULL)   //只有右子树的情况
	{
		if (parent == NULL)     //删除的是根结点，这里需要特别注意
			*bt = p->rightchild;
		else if (parent->leftchild == p)
			parent->leftchild = p->rightchild;
		//p是父结点parent的左孩子，则修改父结点的左指针
		else
			parent->rightchild = p->rightchild;
		//p是分结点parent的右孩子，则修改父结点的右指针
	}//end 95
	if (p->leftchild != NULL) //有左子树和右子树
	{
		maxpl = p->leftchild;
		while (maxpl->rightchild != NULL) //定位左子树中的最大结点maxpl
			maxpl = maxpl->rightchild;
		maxpl->rightchild = p->rightchild;
		if (parent == NULL)    //删除的是根结点，这里需要特别注意
			*bt = p->leftchild;
		else if (parent->leftchild == p) 
			//p是父结点parent的左孩子，则修改父结点的左指针
			parent->leftchild = p->leftchild;
		else
			parent->rightchild = p->leftchild; 
		//p是分结点parent的右孩子，则修改父结点的右指针
	}//end 106
	free(p); //释放结点p
	return 1;
}
//第二种删除算法
int BSTDelete2(BinSearTree *bt, DataType key){
	BSTreeNode parent, p, maxpl;
	p = *bt;
	parent = NULL;
	while (p != NULL) //查找被删除的结点
	{
		if (p->data == key) break; //如果查找到了，跳出循环
		parent = p;
		if (p->data > key)
			p = p->leftchild;
		else
			p = p->rightchild;
	}//end 129
	if (p == NULL)
	{
		printf(" not exist\n"); return 0;
	}
	if (p->leftchild == NULL) //只有左子树的情况
	{
		if (parent == NULL)
			*bt = p->rightchild;
		else if (parent->leftchild == p)
			parent->leftchild = p->rightchild;
		else
			parent->rightchild = p->rightchild;
	}//end 142
	if (p->leftchild != NULL)//有左子树和右子树
	{
		BSTreeNode parentp; //parentp记录maxpl的父结点
		parentp = p;
		maxpl = p->leftchild;
		while (maxpl->rightchild != NULL) //定位p的左子树中的最大结点maxpl
		{
			parentp = maxpl;
			maxpl = maxpl->rightchild;
		}
		p->data = maxpl->data; //修改p的数据域为maxpl的数据域
		if (parentp == p)      //如果maxpl的父结点是p自身
			p->leftchild = maxpl->leftchild; //修改p结点的左指针
		else
			parentp->rightchild = maxpl->leftchild; //修改父结点的右指针
		p = maxpl;  //更新p指针为maxpl结点以便删除
	}//end 151
	free(p);
	return 1;
}

//延伸扩展
//void BST_Destory(BinSearTree *bt){}
//int BSTS_ASL(BinSearTree *bt){}
//int BSTS_Recur(BinSearTree *bt, DataType key){}