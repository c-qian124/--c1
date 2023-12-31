#ifndef POLYADD_H
#define POLYADD_H

struct tagNode
{
	float coef;               //系数
	int exp;                 // 指数
	struct tagNode *next;   //指针域
};
typedef struct tagNode Node;
typedef struct tagNode*  PNode;

//函数功能：将结点插入到链表的适当位置，按照指数升序排列
//输入参数head： 链表头结点
//输入参数 pnode： 待插入的结点
//返回值：  无
void insertList(PNode head, PNode pnode);

//函数功能：调用insertLis()，创建多项式链表
//输入参数head： 链表头结点
//返回值：  无
void CreateList(PNode head);

//函数功能：两个多项式相加
//输入参数pa： 多项式1
//输入参数pb： 多项式2
//返回值：  无
void Add_Poly(PNode pa, PNode pb);

//函数功能：输出多项式链表
//输入参数head： 链表头结点
//返回值：  无
void printLinkedList(PNode head);

#endif