

#include<stdio.h>
#include<stdlib.h>
#include "SeqList.h"
void main()
{
	SeqList seqlist;
	int max, len, i, x;
	printf("����˳�������ֵ(<100)=");
	scanf_s("%d", &max);
	seqlist = SetNullList_Seq(max);//�����յ�˳���
	if (seqlist != NULL)
	{
		printf("����˳���ĳ���=");
		scanf_s("%d", &len);
	}
	printf("����˳����Ԫ�أ�");
	for (i = 0; i<len; i++)
	{
		scanf_s("%d", &x);
		InsertPre_seq(seqlist, i, x); //ͨ�����뽨��˳���
	}
	printf("˳����Ƿ�Ϊ�գ�1Ϊ�գ�0Ϊ�ǿգ�%d\n", IsNullList_seq(seqlist));
	printf("��ǰ˳����Ԫ���ǣ�");
	print(seqlist);               //���˳���
	scanf("%d", &key);
	temp = binsearch_recursion(zrx_alist, key, 0, zrx_alist->n - 1, pos);
	printf("%d\n", temp);
	//if (binsearch(zrx_alist, key, &pos)==-1)
	//{
	//	InsertPre_seq(zrx_alist, pos, key);
	//	printf("The list is after insert %d key:\n",key);
	//	//print(zrx_alist);
	//}
	//print(zrx_alist);
	
	DelIndex_seq(seqlist, 3);   //ɾ���±�Ϊ3��Ԫ��
	printf("ɾ���±�Ϊ3��Ԫ�غ��˳���:");
	print(seqlist);                   //���˳���
	InsertPre_seq(seqlist, 2, 99);  //���±�2λ��֮ǰ����99
	printf("���±�2λ��֮ǰ����99���˳���:");
	print(seqlist);                    //���˳���
	printf("����ֵΪ99��Ԫ���±�:");
	printf("%d\n", Locate_seq(seqlist, 99)); //����ֵΪ99��Ԫ���±�
	
	DestoryList_Seq(seqlist);	//����˳���
}
