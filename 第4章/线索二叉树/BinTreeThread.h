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

//函数功能： 递归建立二叉树
//输入参数： 无
//返回值：   二叉树的根
BinTree CreateBinTree();

//函数功能： 对二叉树bt添加中序线索
//输入参数： 二叉树的根
//返回值：   无
void Create_InorderThread(BinTree bt);

//函数功能： 中序遍历中序线索二叉树
//输入参数： 线索二叉树的根
//返回值：   无
void Inorder_ThreadBinTree(BinTree bt);

#endif
