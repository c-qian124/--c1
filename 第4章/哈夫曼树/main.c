#include<stdio.h>
#include<stdlib.h>
#include"huffman.h"
void main(){
	int *text;
	int num = 6, i = 0;		//numΪ��������Ҷ�ӽڵ����
	HuffTree pht;           //�����������	
	printf("���ļ�����Ľ����Ϣ��\n");
	/*scanf_s("%d\n", &num);
	for (i = 0; i < num; i++)
	scanf_s("%d", &text[i]);
	printf("\n");*/
	text = GetFrequency();
	printf("������������ǰ�������������������̬:\n");
	printf("weight   leftchild     rightchild    parent\n");
	for (i = 0; i < num; i++){
		printf("%2d       -1            -1           -1\n", text[i]);
	}
	printf("\n");
	pht = CreateHuffTree(num, text);//������������
	//�����������
	printf("�������������󣬱�����������������̬:\n");
	printf("ww     leftchild       rightchild     parent\n");
	for (i = 0; i < num * 2 - 1; i++){
		printf("%2d      %2d	       %2d           %2d\n",
			pht->ht[i].weight, pht->ht[i].leftchild, pht->ht[i].rightchild, pht->ht[i].parent);
	}
}