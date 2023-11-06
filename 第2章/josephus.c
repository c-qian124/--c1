#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
struct Node
{
	DataType data;
	struct Node * next;
};
typedef struct Node Node;

//函数功能:    给出具体条件下 Josephus 问题的解   
// 输入参数:    n 为总人数, k 为间隔, s 为起始位置 
// 返回值:      answer 为问题的答案              
int josephus(int n, int s, int k )
{
	Node *current, *prev, *head;
	head = (Node *)malloc(sizeof(Node));
	int answer;
	prev = head;
	for (int i = 1; i <= n; i++)               //尾插法建立循环链表  
	{
		current = (Node *)malloc(sizeof(Node));
		current->data = i;
		prev->next = current;
		prev = current;
	}
	prev->next = head->next;          //让最后一个节点的 next 指针指向开头，构成循环链表
	current = head->next;
	for (int i = 1; i < s; i++)
	{
		prev = prev->next;
		current = current->next;       //current 指针移动 s - 1 次，指向起始节点
	}

	while (current->next != current)          //循环直至链表只剩一个元素 
	{
		for (int i = 1; i < k; i++)
		{
			prev = prev->next;
			current = current->next;          //current 指针移动 k - 1 次，指向要删除的节点
		}
		prev->next = current->next;
		printf("当前出列的序号是%d：\n", current->data);
		free(current);                        //删除该节点
		current = prev->next;
	}
	answer = current->data;
	printf("当前出列的序号是%d：\n", current->data);
	return answer;
}


void main( )
{
	int n, k, s, answer;       //n 为总人数,  s 为起始位置, k 为间隔,
	//第 s 个人从1开始报数,报到 k 的人出列,下一个人再从1开始报数
	printf("请输入总人数n，起始位置s，间隔k\n");
	scanf_s("%d,%d,%d", &n,&s,&k);
	answer = josephus(n, s, k);
	printf("最后出列的是第%d个人\n", answer);
}