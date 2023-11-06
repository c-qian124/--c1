#ifndef BinTreeStack_H
#define BinTreeStack_H
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

//�������ܣ� �ǵݹ������������1
//��������� �������ĸ�
//����ֵ��   ��
void PreOrder_NRecursion1(BinTree bt);

//�������ܣ� �ǵݹ������������1
//��������� �������ĸ�
//����ֵ��   ��
void PreOrder_NRecursion2(BinTree bt);

//�������ܣ� �ǵݹ��������
//��������� �������ĸ�
//����ֵ��   ��
void InOrder_NRecursion(BinTree bt);

//�������ܣ� �ǵݹ�������
//��������� �������ĸ�
//����ֵ��   ��
void PostOrder_NRecursion(BinTree bt);
#endif
