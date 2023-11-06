#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
struct Node
{
	DataType data;
	struct Node * next;
};
typedef struct Node Node;

//��������:    �������������� Josephus ����Ľ�   
// �������:    n Ϊ������, k Ϊ���, s Ϊ��ʼλ�� 
// ����ֵ:      answer Ϊ����Ĵ�              
int josephus(int n, int s, int k )
{
	Node *current, *prev, *head;
	head = (Node *)malloc(sizeof(Node));
	int answer;
	prev = head;
	for (int i = 1; i <= n; i++)               //β�巨����ѭ������  
	{
		current = (Node *)malloc(sizeof(Node));
		current->data = i;
		prev->next = current;
		prev = current;
	}
	prev->next = head->next;          //�����һ���ڵ�� next ָ��ָ��ͷ������ѭ������
	current = head->next;
	for (int i = 1; i < s; i++)
	{
		prev = prev->next;
		current = current->next;       //current ָ���ƶ� s - 1 �Σ�ָ����ʼ�ڵ�
	}

	while (current->next != current)          //ѭ��ֱ������ֻʣһ��Ԫ�� 
	{
		for (int i = 1; i < k; i++)
		{
			prev = prev->next;
			current = current->next;          //current ָ���ƶ� k - 1 �Σ�ָ��Ҫɾ���Ľڵ�
		}
		prev->next = current->next;
		printf("��ǰ���е������%d��\n", current->data);
		free(current);                        //ɾ���ýڵ�
		current = prev->next;
	}
	answer = current->data;
	printf("��ǰ���е������%d��\n", current->data);
	return answer;
}


void main( )
{
	int n, k, s, answer;       //n Ϊ������,  s Ϊ��ʼλ��, k Ϊ���,
	//�� s ���˴�1��ʼ����,���� k ���˳���,��һ�����ٴ�1��ʼ����
	printf("������������n����ʼλ��s�����k\n");
	scanf_s("%d,%d,%d", &n,&s,&k);
	answer = josephus(n, s, k);
	printf("�����е��ǵ�%d����\n", answer);
}