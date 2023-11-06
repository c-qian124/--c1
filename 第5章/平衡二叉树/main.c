#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

//菜单
void menu()
{
	printf("\n");
	printf("*********************主菜单**********************\n");
	printf(" 1:连续插入数据     ");
	printf(" 2:查找数据        ");
	printf(" 3:删除特定数据\n");
	printf(" 4:中序遍历输出     ");
	printf(" 5:销毁当前AVL     ");
	printf(" 6:结束程序\n");
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
			printf("\t\t请插入数据, 输入-1结束插入\n");
			while (scanf_s("%d", &data))
			{
				if (data == -1)
					break;
				else
				{
					if (insertAVL(&p, data, &taller))
						printf("%d 插入成功;", data);
					else
						printf("\n%d 插入失败;\n", data);
				}
			}
			menu();
			getchar();
			break;
		case 2:
			printf("\n\t\t    请输入要查询的数: ");
			scanf_s("%d", &data);
			if (searchAVL(p, data) == FALSE)
			{
				printf("\t\t 查找失败 %d!\n", data);
			}
			else
			{
				printf("\t\t 查找成功 %d!\n", data);
			}
			menu();
			getchar();
			break;
		case 3:
			printf("\n\t\t 请输入要删除的数据: ");
			scanf_s("%d", &data);
			if (deleteAVL(&p, data, &shorter))
				printf("\n\t\t 删除成功");
			else
				printf("\n\t\t 删除失败");
			menu();
			getchar();
			break;
		case 4:
			printf("中序遍历输出 :");
			Inorder(p);
			menu();
			break;
		case 5:
			printf("是否摧毁整个树？（1.yes	2.no）");
			scanf_s("%d", &temp);
			getchar();
			system("cls");
			switch (temp)
			{
			case 1:
				destroyAVL(&p);
				printf("\n\t\t\t删除成功\n\n");
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