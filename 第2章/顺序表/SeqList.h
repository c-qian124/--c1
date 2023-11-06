#ifndef SEQLIST_H
#define SEQLIST_H

typedef int DataType;     //����Ԫ�����Ͷ���Ϊ����
struct List
{
	int Max;  //˳�����������
	int n;    //˳�����
	DataType *elem; //˳���Ԫ����ʼλ��
};
typedef struct List *SeqList;  //˳������Ͷ���

//�������ܣ� ������˳���
//������� m�� ˳�����������
//����ֵ�� �յ�˳���
SeqList SetNullList_Seq(int m); 

//�������ܣ� �ж�˳����Ƿ�Ϊ��
//������� slist�� ˳���
//����ֵ�� �շ���1�����򷵻�0
int IsNullList_seq(SeqList slist); 

//�������ܣ� �����Ա�slist��pλ��֮ǰ����x
//������� slist�� ˳���
//������� p�� ����λ��
//������� x: �������Ԫ��
//����ֵ�� �ɹ�����1�����򷵻�0
int InsertPre_seq(SeqList slist, int p, DataType x);

//�������ܣ� ɾ���±�Ϊp��Ԫ��
//������� slist�� ˳���
//������� p�� ɾ��λ��
//����ֵ�� �ɹ�ɾ������1�����򷵻�0
int DelIndex_seq(SeqList slist, int p);

//�������ܣ� ����ֵΪx��Ԫ��
//������� slist�� ˳���
//������� x�� Ҫ���ҵ�Ԫ��
//����ֵ�� ���ҳɹ�����Ԫ����˳�����±꣬���򷵻�-1
int Locate_seq(SeqList slist, int x);

//�������ܣ� ���˳���
//������� slist�� ˳���
//����ֵ�� ��
void print(SeqList slist);                    

//�������ܣ� �ͷ�˳���
//������� slist�� ˳���
//����ֵ�� ��
void DestoryList_Seq(SeqList slist);         

#endif 