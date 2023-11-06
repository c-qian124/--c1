#include<stdio.h>
#include<stdlib.h>
#include"huffman.h"

int *GetFrequency() //������ѡ�ļ���Ĭ���ļ�������Ƶ������
{
	int i;
	int LEN = CHARLEN
	FILE *fp = NULL;
	int *freq = (int *)malloc(sizeof(int)*LEN);
	/*	----- ��ʼ��fre���� -----*/
	for (i = 0; i < LEN; i++)
		freq[i] = 0;
	fp = fopen(".\\file.txt", "r");
	if (fp == NULL)
	{
		printf("\n\t\t�Ҳ����ļ�\"\n");
		exit(0);
	}
	/*	----- ���ļ�������Ƶ���� ,������ֻ��Сд��ĸ-----*/
	for (char ch; 0 < fscanf_s(fp, "%c", &ch);)
	{
		printf("%c ", ch);
		if (ch >= 0x61) freq[ch - 0x61]++;
	}
	printf("\n");
	fclose(fp);
	return freq;
}
//	�����������
HuffTree CreateHuffTree(int n, int *w){
	HuffTree pht;
	int i, j, x1, x2, min1, min2;
	pht = (HuffTree)malloc(sizeof(struct HuffTreeNode));
	if (pht == NULL){
		printf("Out of space!!\n");
		return pht;
	}
	//Ϊ������������2*N-1���ռ�
	pht->ht = (HtNode)malloc(sizeof(struct HuffNode)*(2 * n - 1));

	if (pht->ht == NULL){
		printf("Out of space!!\n");
		return pht;
	}
	//��ʼ����������
	for (i = 0; i < 2 * n - 1; i++){
		pht->ht[i].leftchild = -1;	//��ʼ��Ҷ�������
		pht->ht[i].rightchild = -1;	//��ʼ��Ҷ����Һ���
		pht->ht[i].parent = -1;	//��ʼ��Ҷ���ĸ���
		if (i < n)
			pht->ht[i].weight = w[i];
		else
			pht->ht[i].weight = -1;
	}
	for (i = 0; i < n - 1; i++){
		min1 = MAX;			//m1����Сֵ
		min2 = MAX;			//m2�����Сֵ
		x1 = -1;			//��Сֵ�±�
		x2 = -1;			//��Сֵ�±�
		//�ҵ���Сֵ�±�x1���Ѽ�Сֵ��ֵ��m1
		for (j = 0; j < n + i; j++)
		if (pht->ht[j].weight < min1&&pht->ht[j].parent == -1){
			min2 = min1;
			x2 = x1;
			min1 = pht->ht[j].weight;
			x1 = j;
		}
		//�ҵ���Сֵ�±�x2���Ѵ�Сֵ��ֵ��min2
		else if (pht->ht[j].weight < min2&&pht->ht[j].parent == -1){
			min2 = pht->ht[j].weight;
			x2 = j;
		}
		//����x1��x2�ĸ����
		pht->ht[x1].parent = n + i;	//x1������±�
		pht->ht[x2].parent = n + i;	//x2������±�
		pht->ht[n + i].weight = min1 + min2;//������ȨֵΪ��Сֵ�Ӵ�Сֵ
		pht->ht[n + i].leftchild = x1;	//����������Ϊx1
		pht->ht[n + i].rightchild = x2;	//�������Һ��ӵ�x2
	}
	pht->root = 2 * n - 2;//�������������λ��
	pht->n = n;
	return pht;
}