#include <stdio.h>
#include <stdlib.h>
#include "PolyAdd.h"
//�������뵽������ʵ�λ�ã�����һ��ָ���������е�����
void insertList(PNode head, PNode pnode)
{
	PNode pPre = head;
	while (pPre->next != NULL)
	{
		if (pPre->next->exp>pnode->exp)
		{
			pnode->next = pPre->next;
			pPre->next = pnode;
			break;
		}
		pPre = pPre->next;
	}
	if (pPre->next == NULL)//���������ָ�����ֱ�Ӳ����㵽���
	{
		pPre->next = pnode;
	}
}
void CreateList(PNode head)
{
	int exp;//ָ��
	float coef;//ϵ��
	PNode pTemp = NULL;
	head->next = NULL;//����ÿռ䣬ָ����ֵΪ��
	//�������ʽ
	printf("������Ҫ��������1�е����ݣ�˳��Ϊϵ����ָ����������ʽ����������0��0��β��\n");
	//�������ݣ���0��0��β�������ݲ���������
	scanf_s("%f,%d", &coef, &exp);
	while (coef != 0 || exp != 0)
	{
		pTemp = (PNode)malloc(sizeof(struct tagNode));
		pTemp->coef = coef;
		pTemp->exp = exp;
		pTemp->next = NULL;
		insertList(head, pTemp);
		scanf_s("%f,%d", &coef, &exp);
	}
}
void printLinkedList(PNode head)//�������
{
	PNode temp = head->next;//����ĵ�һ���ڵ�
	while (temp != NULL)
	{
		printf("%0.0f ", temp->coef);
		printf("%d,", temp->exp);
		temp = temp->next;
	}
	printf("\n");
}
void Add_Poly(PNode pa, PNode pb)//��������ʽ���
{
	PNode p = pa->next;/*����1���Ͷ���ʽ�������������1*/
	PNode q = pb->next;/*����2*/
	PNode pre = pa;
	PNode u;/*��ʱ����*/
	float x;
	while (p != NULL && q != NULL)/*������������Ϊ��*/
	{
		if (p->exp<q->exp)
		{/*�Ƚ�����1������2��ǰ�ڵ��ָ����С������1Ҳ�Ǵ�Ž���ĵط�*/
			pre = p; p = p->next;/*pָ��Ҫ�Ƚϵ���һ����㡣preָ����ǽ����������һ�����*/
		}
		else if (p->exp == q->exp)
		{/*��������1������2��ָ����ȣ���Ҫϵ�����*/
			x = p->coef + q->coef;
			if (x != 0)/*��Ӻ��ϵ����Ϊ0���б�Ҫ����һ�����Ϳ�����*/
			{
				p->coef = x; pre = p;
			}
			else
			{/*��Ӻ�ϵ����0������Ҫ�����κ�һ����㣬������ɾ������1�Ľ�㣬����ɾ������2�Ľ��*/
				pre->next = p->next;/*��������1��������*/
				free(p);
			}
			p = pre->next;/*pָ��Ҫ�Ƚϵ���һ�����*/
			/*����Ĵ����ǽ�������2����ɾ����������Ϊָ����ȣ�������Ҫ����һ�����Ϳ�����*/
			/*�����ֱ�ӱ���������1�У����ԣ�ɾ������2�Ľ��*/
			u = q;
			q = q->next;
			free(u);
		}
		else/*�������2�ĵ�ǰ�ڵ�ָ��С����ôҪ������2�ĵ�ǰ�ڵ���뵽��������У���������1��*/
		{/*�൱�ڰѽ����뵽����1�У���u��Ϊ��ʱ��������������2����һ����ǰ�ڵ��λ��*/
			u = q->next;
			q->next = p;
			pre->next = q;
			pre = q;
			q = u;
		}
	}
	if (q)/*�������2������1������ô��Ҫ������2����Ĳ��ּ�����������*/
		/*����1������2������ʲô��������*/
		pre->next = q;
	free(pb);
}