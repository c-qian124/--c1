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

//函数功能： 递归建立二叉树
//输入参数： 无
//返回值：   二叉树的根
BinTree CreateBinTree_Recursion();

//函数功能： 非递归先序遍历方法1
//输入参数： 二叉树的根
//返回值：   无
void PreOrder_NRecursion1(BinTree bt);

//函数功能： 非递归先序遍历方法1
//输入参数： 二叉树的根
//返回值：   无
void PreOrder_NRecursion2(BinTree bt);

//函数功能： 非递归中序遍历
//输入参数： 二叉树的根
//返回值：   无
void InOrder_NRecursion(BinTree bt);

//函数功能： 非递归后序遍历
//输入参数： 二叉树的根
//返回值：   无
void PostOrder_NRecursion(BinTree bt);
#endif
