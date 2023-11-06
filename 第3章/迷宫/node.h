#ifndef LIST_H_
#define LIST_H_

//栈和队列的结点定义
typedef int DataType;
struct Node{
	DataType	  data;
	struct Node*  next;
};
typedef struct Node  *PNode;

#endif