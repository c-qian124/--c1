#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef int DataType;
struct Node{
	DataType	  data;
	struct Node*  next;
};
typedef struct Node  *PNode;
typedef struct Node  *LinkStack;

//函数功能：创建空链栈
//输入参数： 无
//返回值：    空的链栈
LinkStack SetNullStack_Link();       

//函数功能：判断一个链栈是否为空
//输入参数top： 链栈栈顶指针
//返回值：    空栈返回1，否则返回0
int IsNullStack_link(LinkStack top); 

//函数功能：进栈
//输入参数top： 链栈栈顶指针
//输入参数x： 进栈元素
//返回值：    无
void Push_link(LinkStack top, DataType x); 

//函数功能：出栈
//输入参数top： 链栈栈顶指针
//返回值：    无
void Pop_link(LinkStack top);      // 删除栈顶元素

//函数功能：求栈顶元素的值
//输入参数top： 链栈栈顶指针
//返回值：    无
DataType Top_link(LinkStack top); // 求栈顶元素的值

#endif