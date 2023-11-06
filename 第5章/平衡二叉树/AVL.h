#ifndef AVL_H
#define AVL_H

typedef int Status;
typedef int DataType;
#define TRUE 1
#define FALSE 0
//ƽ���������������㶨��
struct AVLTreeNode
{
	DataType data;
	int bf;
	struct AVLTreeNode *leftchild; //����ָ��
	struct AVLTreeNode *rightchild; //�Һ���ָ��
};
//ƽ����������������Ͷ���
typedef struct AVLTreeNode *AVLNode;
typedef struct AVLTreeNode *AVLTree;
typedef AVLTree *PAVLTree;

//�������ܣ� ����AVL�������
//��������� AVL��
//����ֵ��  AVL�������
Status AVLDepth(AVLNode bt);

//�������ܣ� �������AVL��
//��������� AVL��
//����ֵ��  ��
void Inorder(AVLNode bt);

//�������ܣ� ����AVL��
//�������bt�� AVL��
//�������key�� Ҫ������Ԫ��
//����ֵ��  �ɹ�����1�����򷵻�0
Status searchAVL(AVLNode bt, DataType key);

//�������ܣ� ����AVL��
//��������� AVL��
//����ֵ��  ��
void destroyAVL(PAVLTree bt);

//�������ܣ� ����AVL��
//��������� AVL��
//����ֵ��  ��
void leftRotate(AVLNode *bt);

//�������ܣ� ����AVL��
//��������� AVL��
//����ֵ��  ��
void rightRotate(AVLNode *bt);

//�������ܣ� ��ƽ�⴦��AVL��
//��������� AVL��
//����ֵ��  ��
void leftBalance(AVLNode *bt);

//�������ܣ� ��ƽ�⴦��AVL��
//��������� AVL��
//����ֵ��  ��
void rightBalance(AVLNode *bt);

//�������ܣ� ��AVL���в���Ԫ��
//�������bt�� AVL��
//�������key�� Ҫ�����Ԫ��
//�������more�� �����Ƿ�����
//����ֵ��  ��
Status insertAVL(AVLNode *bt, DataType key, Status *more);

//�������ܣ� ��AVL����ɾ��Ԫ��
//�������bt�� AVL��
//�������key�� Ҫɾ����Ԫ��
//�������less�� �����Ƿ����
//����ֵ��  ��
Status deleteAVL(AVLNode *bt, DataType key, Status *less);


#endif