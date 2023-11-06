#include<stdio.h>
#include<stdlib.h>
#include"BSTree.h"

//��������������
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

//�����������������
void Inorder(BinSearTree ptree) 
{
	if (ptree == NULL)
		return;
	Inorder(ptree->leftchild);
	printf("%d ", ptree->data);
	Inorder(ptree->rightchild);
}

//��������������
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

//�����㷨
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

//��һ��ɾ���㷨
int BSTDelete1(BinSearTree *bt, DataType key)
{
	//parent��¼p�ĸ���㣬maxpl��¼p���������еĹؼ��������
	BSTreeNode parent, p, maxpl;
	p = *bt;
	parent = NULL;
	while (p != NULL) //���ұ�ɾ���Ľ��
	{
		if (p->data == key) break; //������ҵ��ˣ�����ѭ��
		parent = p;
		if (p->data > key)
			p = p->leftchild;
		else
			p = p->rightchild;
	}//end 82
	if (p == NULL) {
		printf(" not exist��\n");
		return 0;
	}
	if (p->leftchild == NULL)   //ֻ�������������
	{
		if (parent == NULL)     //ɾ�����Ǹ���㣬������Ҫ�ر�ע��
			*bt = p->rightchild;
		else if (parent->leftchild == p)
			parent->leftchild = p->rightchild;
		//p�Ǹ����parent�����ӣ����޸ĸ�������ָ��
		else
			parent->rightchild = p->rightchild;
		//p�Ƿֽ��parent���Һ��ӣ����޸ĸ�������ָ��
	}//end 95
	if (p->leftchild != NULL) //����������������
	{
		maxpl = p->leftchild;
		while (maxpl->rightchild != NULL) //��λ�������е������maxpl
			maxpl = maxpl->rightchild;
		maxpl->rightchild = p->rightchild;
		if (parent == NULL)    //ɾ�����Ǹ���㣬������Ҫ�ر�ע��
			*bt = p->leftchild;
		else if (parent->leftchild == p) 
			//p�Ǹ����parent�����ӣ����޸ĸ�������ָ��
			parent->leftchild = p->leftchild;
		else
			parent->rightchild = p->leftchild; 
		//p�Ƿֽ��parent���Һ��ӣ����޸ĸ�������ָ��
	}//end 106
	free(p); //�ͷŽ��p
	return 1;
}
//�ڶ���ɾ���㷨
int BSTDelete2(BinSearTree *bt, DataType key){
	BSTreeNode parent, p, maxpl;
	p = *bt;
	parent = NULL;
	while (p != NULL) //���ұ�ɾ���Ľ��
	{
		if (p->data == key) break; //������ҵ��ˣ�����ѭ��
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
	if (p->leftchild == NULL) //ֻ�������������
	{
		if (parent == NULL)
			*bt = p->rightchild;
		else if (parent->leftchild == p)
			parent->leftchild = p->rightchild;
		else
			parent->rightchild = p->rightchild;
	}//end 142
	if (p->leftchild != NULL)//����������������
	{
		BSTreeNode parentp; //parentp��¼maxpl�ĸ����
		parentp = p;
		maxpl = p->leftchild;
		while (maxpl->rightchild != NULL) //��λp���������е������maxpl
		{
			parentp = maxpl;
			maxpl = maxpl->rightchild;
		}
		p->data = maxpl->data; //�޸�p��������Ϊmaxpl��������
		if (parentp == p)      //���maxpl�ĸ������p����
			p->leftchild = maxpl->leftchild; //�޸�p������ָ��
		else
			parentp->rightchild = maxpl->leftchild; //�޸ĸ�������ָ��
		p = maxpl;  //����pָ��Ϊmaxpl����Ա�ɾ��
	}//end 151
	free(p);
	return 1;
}

//������չ
//void BST_Destory(BinSearTree *bt){}
//int BSTS_ASL(BinSearTree *bt){}
//int BSTS_Recur(BinSearTree *bt, DataType key){}