#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
Status AVLDepth(AVLNode bt)// ������������
{
	if (bt == NULL)
		return 0;
	int left = 1;
	int right = 1;
	left += AVLDepth(bt->leftchild);
	right += AVLDepth(bt->rightchild);
	return left > right ? left : right;
}
void Inorder(AVLNode bt)//�������
{
	if (bt == NULL) return;
	Inorder(bt->leftchild);
	printf("%d ", bt->data);
	Inorder(bt->rightchild);
}
Status searchAVL(AVLNode bt, DataType data)//����Data
{
	if (!bt)
		return FALSE;
	if (bt->data == data)
		return TRUE;
	else if (data < bt->data)
		return searchAVL(bt->leftchild, data);
	else
		return searchAVL(bt->rightchild, data);
}
void destroyAVL(PAVLTree bt)// ����AVL
{
	AVLNode p = *bt;
	if (p == NULL)
		return;
	destroyAVL(&(p->leftchild));
	destroyAVL(&(p->rightchild));
	*bt = NULL;
}
void leftRotate(AVLNode *bt)//����
{
	AVLNode p = *bt;
	AVLNode rc = (*bt)->rightchild;
	(*bt)->rightchild = rc->leftchild;
	rc->leftchild = (*bt);
	(*bt) = rc;
}
void rightRotate(AVLNode *bt)//	����
{
	AVLNode lc = (*bt)->leftchild;
	(*bt)->leftchild = lc->rightchild;
	lc->rightchild = (*bt);
	(*bt) = lc;
}
void leftBalance(AVLNode *bt)//����bt����ƽ�⴦��
{
	AVLNode lc = (*bt)->leftchild; //lcָ��bt������
	AVLNode lc_rc;
	switch (lc->bf)
	{
	case 0:
		(*bt)->bf = 1;  lc->bf = 0;   rightRotate(bt);
		break;
		//LL��, ������������
	case 1:
		(*bt)->bf = 0;  lc->bf = 0;  rightRotate(bt);
		break;
		//LR��, ������������, ����������
	case -1:
		lc_rc = lc->rightchild;
		switch (lc_rc->bf) //�޸�bt�������ӵ�ƽ������
		{
		case 1:    (*bt)->bf = -1; lc->bf = 0;  break;
		case 0:    (*bt)->bf = 0;  lc->bf = 0;  break;
		case -1:   (*bt)->bf = 0;  lc->bf = 1;  break;
		}
		lc_rc->bf = 0;
		leftRotate(&((*bt)->leftchild));
		rightRotate(bt);
		break;
	}//end 60
}
void rightBalance(AVLNode *bt)//����bt����ƽ�⴦��
{
	AVLNode rc = (*bt)->rightchild;
	AVLNode rc_lc;
	switch (rc->bf)
	{
		//�������, ɾ��ʱ��Ҫ����0, ��������ɾ���ڵ㲻ƽ�����
	case 0:
		(*bt)->bf = -1;  rc->bf = 0;  leftRotate(bt);
		break;
		//RR��, ������������
	case -1:
		(*bt)->bf = 0;  rc->bf = 0;  leftRotate(bt);
		break;
		//RL��, ������������������������
	case 1:
		rc_lc = rc->leftchild;
		switch (rc_lc->bf)
		{
		case 1:    (*bt)->bf = 0;  rc->bf = -1;  break;
		case 0:    (*bt)->bf = 0;  rc->bf = 0;   break;
		case -1:   (*bt)->bf = 1;  rc->bf = 0;   break;
		}
		rc_lc->bf = 0;
		rightRotate(&((*bt)->rightchild));
		leftRotate(bt);
		break;
	}//end 88
}
Status insertAVL(AVLNode *bt, DataType data, Status *more)//����
{
	if (*bt == NULL) //btΪ��, ������
	{
		*bt = (AVLNode)malloc(sizeof(struct AVLTreeNode));
		(*bt)->rightchild = (*bt)->leftchild = NULL;
		(*bt)->data = data;
		(*bt)->bf = 0;
		*more = TRUE;
	}
	else
	{
		//�����Ѵ��ں�data��ȵĽ��
		if (data == (*bt)->data)
		{
			*more = FALSE; return 0;//δ����
		}
		//����������
		else if (data < (*bt)->data)
		{
			//�������ַ���������
			//insertAVL(&((*bt)->leftchild), data, more); //�ݹ�ѭ��
			//if (FALSE == *more) return 0;//δ����
			if (insertAVL(&((*bt)->leftchild), data, more) == 0)
				return 0; //�ݹ�ѭ��,�ݹ����
			if (TRUE == *more)
			{
				switch ((*bt)->bf)// ���bt��ƽ������
				{
				case 1://ԭ���, ��ƽ��
					leftBalance(bt); *more = FALSE; break;
				case 0://ԭ�ȸ�, ����
					(*bt)->bf = 1; *more = TRUE; break;
				case -1://ԭ�Ҹ�, ��ȸ�
					(*bt)->bf = 0; *more = FALSE; break;
				}
			}//end 138
		}// end 131
		//����������
		else
		{
			//�������ַ���������
			//insertAVL(&((*bt)->rightchild), data, more);
			//if (FALSE == *more ) return 0;//δ����
			if (insertAVL(&((*bt)->rightchild), data, more) == 0)
				return 0; //�ݹ�ѭ��
			if (TRUE == *more)
			{
				switch ((*bt)->bf)
				{
				case 1: //ԭ���, ��ȸ�
					(*bt)->bf = 0; *more = FALSE; break;
				case 0: //ԭ�ȸ�, ���Ҹ�
					(*bt)->bf = -1;    *more = TRUE; break;
				case -1: //ԭ�Ҹ�, ��ƽ��
					rightBalance(bt); *more = FALSE; break;
				}
			}//end 159
		}// end 152
	}//end 123
	return 1;
}
Status deleteAVL(AVLNode *bt, DataType data, Status *less)//ɾ��
{
	AVLNode q = NULL;
	if ((*bt) == NULL) //����
	{
		*less = FALSE; return 0;
	}
	else if (data == (*bt)->data) //���
	{
		if ((*bt)->leftchild == NULL)  //������Ϊ��, ��������
		{
			(*bt) = (*bt)->rightchild; *less = TRUE;
		}
		else if ((*bt)->rightchild == NULL) //������Ϊ��, ��������
		{
			(*bt) = (*bt)->leftchild; *less = TRUE;
		}
		else    //��������������, �����������������ֵȡ��
		{
			q = (*bt)->leftchild;
			while (q->rightchild != NULL) q = q->rightchild;
			(*bt)->data = q->data;
			//�ݹ�ɾ������
			if (deleteAVL(&((*bt)->leftchild),q->data,less)==0)
				return 0;
			if (TRUE == *less)
			{
				switch ((*bt)->bf)
				{
				case 1:
					(*bt)->bf = 0;*less = TRUE;break;
				case 0:
					(*bt)->bf = AVLDepth((*bt)->leftchild) - 
					AVLDepth((*bt)->rightchild);
					*less = FALSE;break;
				case -1:
					rightBalance(bt);
					if ((*bt)->rightchild->bf == 0)
						*less = FALSE;
					else
						*less = TRUE;
					break;
				}
			}// end 200
		}// end 192
	}// end 182
	else if (data < (*bt)->data)  //�������м�������
	{
		//�ݹ�ɾ������
		if (deleteAVL(&((*bt)->leftchild), data, less) == 0) return 0;
		/*if (FALSE == *less)
		DO NOTHING;*/
		if (TRUE == *less)
		{
			switch ((*bt)->bf)
			{
			case 1:
				(*bt)->bf = 0;*less = TRUE;break;
			case 0:
				(*bt)->bf = -1;*less = FALSE;break;
			case -1:
				rightBalance(bt);
				if ((*bt)->rightchild->bf == 0)
					*less = FALSE;
				else
					*less = TRUE;
				break;
			}
		}// end 227
	}// end 221
	else    //�������м�������
	{
		//�ݹ�ɾ���Һ���
		if(deleteAVL(&((*bt)->rightchild),data,less)==0) return 0;
		/*if (FALSE == *less)
		DO NOTHING;*/
		if (TRUE == *less)
		{
			switch ((*bt)->bf)
			{
			case 1:
				leftBalance(bt);
				if ((*bt)->leftchild->bf == 0)
					*less = FALSE;
				else
					*less = TRUE;
				break;
			case 0:
				(*bt)->bf = 1;*less = FALSE; break;
			case -1:
				(*bt)->bf = 0;*less = TRUE; break;
			}
		}//end 251
	}// end 245
	return 1;
}