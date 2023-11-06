#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

//�˵�
void menu()
{
	printf("\n");
	printf("*********************���˵�**********************\n");
	printf(" 1:������������     ");
	printf(" 2:��������        ");
	printf(" 3:ɾ���ض�����\n");
	printf(" 4:����������     ");
	printf(" 5:���ٵ�ǰAVL     ");
	printf(" 6:��������\n");
	printf("*************************************************");
}
/*40 48 8 8 5 12 30 9 10 -1*/
void main()
{
	int num, temp;
	DataType data;
	AVLNode p = NULL;
	Status taller = FALSE, shorter = FALSE;
	system("mode con: cols=55 lines=20");
	menu();
	while (1)
	{
		scanf_s("%d", &num);
		getchar();
		switch (num)
		{
		case 1:
			printf("\t\t���������, ����-1��������\n");
			while (scanf_s("%d", &data))
			{
				if (data == -1)
					break;
				else
				{
					if (insertAVL(&p, data, &taller))
						printf("%d ����ɹ�;", data);
					else
						printf("\n%d ����ʧ��;\n", data);
				}
			}
			menu();
			getchar();
			break;
		case 2:
			printf("\n\t\t    ������Ҫ��ѯ����: ");
			scanf_s("%d", &data);
			if (searchAVL(p, data) == FALSE)
			{
				printf("\t\t ����ʧ�� %d!\n", data);
			}
			else
			{
				printf("\t\t ���ҳɹ� %d!\n", data);
			}
			menu();
			getchar();
			break;
		case 3:
			printf("\n\t\t ������Ҫɾ��������: ");
			scanf_s("%d", &data);
			if (deleteAVL(&p, data, &shorter))
				printf("\n\t\t ɾ���ɹ�");
			else
				printf("\n\t\t ɾ��ʧ��");
			menu();
			getchar();
			break;
		case 4:
			printf("���������� :");
			Inorder(p);
			menu();
			break;
		case 5:
			printf("�Ƿ�ݻ�����������1.yes	2.no��");
			scanf_s("%d", &temp);
			getchar();
			system("cls");
			switch (temp)
			{
			case 1:
				destroyAVL(&p);
				printf("\n\t\t\tɾ���ɹ�\n\n");
				menu();
				break;
			}
			break;
		case 6:
			exit(0);
			break;
		default:
			menu();
			break;
		}
	}
}