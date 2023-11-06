#ifndef BINTREE_H
#define BINTREE_H

typedef char DataType;
typedef struct BTreeNode
{
	DataType data;
	struct BTreeNode *leftchild;
	struct BTreeNode *rightchild;
}BinTreeNode;
typedef BinTreeNode *BinTree;

//�������ܣ� �ݹ齨��������
//��������� ��
//����ֵ��   �������ĸ�
BinTree CreateBinTree_Recursion();

//�������ܣ� �ݹ��������
//��������� �������ĸ�
//����ֵ��   ��
void PreOrder_Recursion(BinTree bt);

//�������ܣ� �ݹ��������
//��������� �������ĸ�
//����ֵ��   ��
void InOrder_Recursion(BinTree bt);

//�������ܣ� �ݹ�������
//��������� �������ĸ�
//����ֵ��   ��
void PostOrder_Recursion(BinTree bt);

//�������ܣ� ���ٶ�����
//��������� �������ĸ�
//����ֵ��   ��
void DestroyBinTree(BinTree bt);

#endif
