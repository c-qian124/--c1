#ifndef LINKSTACK_H_
#define LINKSTACK_H_

#include "node.h"
#define FALSE 0
#define TRUE 1


typedef struct Node  *top,*LinkStack;

LinkStack SetNullStack_Link();
int IsNullStack_link(LinkStack top);
void Push_link(LinkStack top, DataType x);
void Pop_link(LinkStack top);
DataType Pop_seq_return(LinkStack top);
DataType Top_link(LinkStack top);
#endif