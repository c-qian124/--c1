#ifndef BSTree_H
#define BSTree_H
typedef int DataType;

//������������㶨��
struct BinSearTreeNode
{
	DataType data;
	struct BinSearTreeNode *leftchild;
	struct BinSearTreeNode *rightchild;
};
//�������������Ͷ���
typedef struct BinSearTreeNode *BSTreeNode;
typedef struct BinSearTreeNode *BinSearTree;

//�������ܣ� ��������������
//��������� ��
//����ֵ��  ����������
BinSearTree create();

//�������ܣ� �����������������
//��������� ����������
//����ֵ��  ��
void Inorder(BinSearTree ptree);

//�������ܣ� ��������������
//�������bt�� �����������ĸ� 
//�������key�� Ҫ������Ԫ��
//����ֵ�� �ɹ�����NULL��ʧ�ܷ���Ԫ�ز���ĸ����λ��
BSTreeNode BSTSearch(BinSearTree bt, DataType key);

//�������ܣ� �ڶ����������в���Ԫ��key
//�������bt�� �����������ĸ� 
//�������key�� Ҫ�����Ԫ��
//����ֵ�� �ɹ����뷵��1�����򷵻�0
int BSTInsert(BinSearTree bt, DataType key);

//�������ܣ� ɾ�����������е�Ԫ��key
//�������bt�� �����������ĸ� 
//�������key�� Ҫɾ����Ԫ��
//����ֵ�� �ɹ�ɾ������1�����򷵻�0
int BSTDelete1(BinSearTree *bt, DataType key);

//�������ܣ� ɾ�����������е�Ԫ��key
//�������bt�� �����������ĸ� 
//�������key�� Ҫɾ����Ԫ��
//����ֵ�� �ɹ�ɾ������1�����򷵻�0
int BSTDelete2(BinSearTree *bt, DataType key);

//�������ܣ� ���ٶ���������
//�������bt�� �����������ĸ� 
//����ֵ�� ��
void BST_Destory(BinSearTree *bt);

#endif
