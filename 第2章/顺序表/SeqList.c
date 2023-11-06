#include<stdio.h>
#include<stdlib.h>

#include "SeqList.h"
//�ر�ע����Ҫ����ǰ�涨���ͷ�ļ�����˫���ţ������c��ķ�����ͬ
SeqList SetNullList_Seq(int m)//������˳���
{
	//����ṹ��List�ռ�
	SeqList slist = (SeqList)malloc(sizeof(struct List));
	if (slist != NULL){
		slist->elem = (DataType*)malloc(sizeof(DataType)*m);
		//����˳���ռ䣬��СΪm��DataType�ռ�*/
		if (slist->elem){
			slist->Max = m;     //˳�������ֵ
			slist->n = 0;       //˳����ȸ�ֵΪ0
			return(slist);
		}
		else free(slist);
	}
	printf("out of space!!\n");
	return NULL;
}
int IsNullList_seq(SeqList slist)  //�ж�˳����Ƿ�Ϊ��
{
	return(slist->n == 0);  //���˳���ĳ����Ƿ�Ϊ��ʼ���õ�0
}

//�����Ա�slist��pλ��֮ǰ����x
int InsertPre_seq(SeqList slist, int p, DataType x)
{
	int q;
	if (slist->n >= slist->Max){ /*˳��������*/
		printf("overflow");
		return(0);
	}
	if (p<0 || p>slist->n){  //�������±�Ϊp��Ԫ��
		printf("not exist!\n");
		return(0);
	}
	for (q = slist->n - 1; q >= p; q--)//����λ���Լ�֮���Ԫ�غ���
		slist->elem[q + 1] = slist->elem[q];
	slist->elem[p] = x;  //����Ԫ��x
	slist->n = slist->n + 1;  //˳����ȼ�1
	return(1);
}
int DelIndex_seq(SeqList slist, int p) //ɾ���±�Ϊp��Ԫ��
{
	int q;
	if (p<0 || p>=slist->n){//�������±�Ϊp��Ԫ��
		printf("Not exist\n");
		return 0;
	}
	for (q = p; q<slist->n - 1; q++){ //pλ��֮���Ԫ����ǰ�ƶ�
		slist->elem[q] = slist->elem[q + 1];
	}
	slist->n = slist->n - 1; //˳����ȼ�1
	return 1;
}
int Locate_seq(SeqList slist, int x)//����ֵΪx��Ԫ��
{
	int q;
	for (q = 0; q<slist->n; q++){
		if (slist->elem[q] == x)//���ҳɹ������ض�Ӧ��λ��
			return q;
	}
	return -1;                   //����ʧ�ܣ�����-1
}

int binsearch(SeqList slist, int key, int *pos)
{
	int index = 1;//�Ƚϴ���
	int mid;
	int low = 0;
	int high = slist->n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (slist->elem[mid] == key) {
			*pos = mid;
			printf("�ҵ�,������%d�αȽ�\n", index);
			printf("Ҫ�ҵ�����%d��λ��%d��\n", key, mid);
			return 1;
		}
		else if (slist->elem[mid] > key)
			high = mid - 1;
		else 	low = mid + 1;
		index++;
	}
	*pos = low;
	printf("û���ҵ�,������%d�αȽ�\n", index - 1);
	printf("�ɽ��������뵽λ��%d��\n", *pos);
	return -1;
}
/*���Ԫ�ز����ڣ�pos��¼�����λ��*/
int binsearch_recursion(SeqList slist, int key, int low, int high, int *pos)
{
	int mid;
	if (low <= high)
	{
		mid = (low + high) / 2;
		if (slist->elem[mid] == key){
			printf("Ҫ�ҵ�����%d��λ��%d��\n", key, mid);
			return 1;
		}
		if (slist->elem[mid] > key)
			return binsearch_recursion(slist, key, low, mid - 1, mid);
		if (slist->elem[mid] < key)
			return binsearch_recursion(slist, key, mid + 1, high, mid + 1);
	}
	printf("û���ҵ�,�ɽ��������뵽λ��%d��\n", pos);
	return -1;
}
void print(SeqList slist)    //���˳���
{
	int i;
	for (i = 0; i<slist->n; i++)    //���α���˳��������
		printf("%d ", slist->elem[i]);
	printf("\n");
}
void DestoryList_Seq(SeqList slist)    //�ͷ�˳���
{
	free(slist);
}
