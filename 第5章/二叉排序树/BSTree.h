#ifndef BSTree_H
#define BSTree_H
typedef int DataType;

//二叉排序树结点定义
struct BinSearTreeNode
{
	DataType data;
	struct BinSearTreeNode *leftchild;
	struct BinSearTreeNode *rightchild;
};
//二叉排序树类型定义
typedef struct BinSearTreeNode *BSTreeNode;
typedef struct BinSearTreeNode *BinSearTree;

//函数功能： 创建二叉排序树
//输入参数： 无
//返回值：  二叉排序树
BinSearTree create();

//函数功能： 中序遍历二叉排序树
//输入参数： 二叉排序树
//返回值：  无
void Inorder(BinSearTree ptree);

//函数功能： 检索二叉排序树
//输入参数bt： 二叉排序树的根 
//输入参数key： 要检索的元素
//返回值： 成功返回NULL，失败返回元素插入的父结点位置
BSTreeNode BSTSearch(BinSearTree bt, DataType key);

//函数功能： 在二叉排序树中插入元素key
//输入参数bt： 二叉排序树的根 
//输入参数key： 要插入的元素
//返回值： 成功插入返回1，否则返回0
int BSTInsert(BinSearTree bt, DataType key);

//函数功能： 删除二叉排序中的元素key
//输入参数bt： 二叉排序树的根 
//输入参数key： 要删除的元素
//返回值： 成功删除返回1，否则返回0
int BSTDelete1(BinSearTree *bt, DataType key);

//函数功能： 删除二叉排序中的元素key
//输入参数bt： 二叉排序树的根 
//输入参数key： 要删除的元素
//返回值： 成功删除返回1，否则返回0
int BSTDelete2(BinSearTree *bt, DataType key);

//函数功能： 销毁二叉排序树
//输入参数bt： 二叉排序树的根 
//返回值： 无
void BST_Destory(BinSearTree *bt);

#endif
