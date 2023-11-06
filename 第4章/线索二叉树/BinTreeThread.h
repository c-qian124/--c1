#ifndef _BinTreeThread_H
#define _BinTreeThread_H

typedef char DataType;
typedef struct BTreeNode
{
	DataType data;
	struct BTreeNode *leftchild;
	struct BTreeNode *rightchild;
	int ltag;
	int rtag;
}BinTreeNode;
typedef BinTreeNode *BinTree;

//�������ܣ� �ݹ齨��������
//��������� ��
//����ֵ��   �������ĸ�
BinTree CreateBinTree();

//�������ܣ� �Զ�����bt�����������
//��������� �������ĸ�
//����ֵ��   ��
void Create_InorderThread(BinTree bt);

//�������ܣ� ���������������������
//��������� �����������ĸ�
//����ֵ��   ��
void Inorder_ThreadBinTree(BinTree bt);

#endif
