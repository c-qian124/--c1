#ifndef LIST_H_
#define LIST_H_

//ջ�Ͷ��еĽ�㶨��
typedef int DataType;
struct Node{
	DataType	  data;
	struct Node*  next;
};
typedef struct Node  *PNode;

#endif