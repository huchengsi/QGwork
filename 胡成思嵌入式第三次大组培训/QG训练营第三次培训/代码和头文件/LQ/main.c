#include<stdio.h>
#include<stdlib.h>
#include"../head/LQueue.h"
//FILE *stream;//调bug用的
void *e;
int main()
{
	//freopen_s(&stream,"Text.txt", "r", stdin);
	LQueue *lqueue = (LQueue*)malloc(sizeof(LQueue));
	char a[10];
	char Int[10] = "int";
	char Char[10] = "char";
	char Float[10] = "float";
	char Double[10] = "double";
	int x = 1;

	while (1) {

	
		printf("-------------操作选项-----------\n");
		printf("1:返回菜单");
		printf("          2:退出程序 \n");
		printf("3:初始化队列");
		printf("        4:入队 \n");
		printf("5:出队");
		printf("              6:清空队列 \n");
		printf("7:销毁队列");
		printf("          8:查看队头 \n");
		printf("9:遍历输出 \n");


		printf("--------------------------------\n");
		printf("按数字键选择要执行的操作: ");
		scanf_s("%d", &x);
		setvbuf(stdin, NULL, _IONBF, 100);
		printf("\n");

		if (x == 2) exit(1);  //输入2，退出程序

		if ('x' < '1' || 'x' > '11')
		{
			printf("非法输入");
			break;
		}
		switch (x)
		{
		case 1:  break; //输入1，跳出switch语句，进入下一次循环
		case 3:  InitLQueue(lqueue); break;//ok
		case 4:
			printf("请输入入队类型\n");
			scanf_s("%s", a, 10);
			setvbuf(stdin, NULL, _IONBF, 100);
			if (!strcmp(a, Int))//判断用户输入的目的类型
			{
				int *d=(int*)malloc(sizeof(int));
				printf("请输入数据\n");
				scanf_s("%d", d);
				EnLQueue(lqueue,(void*)d);
				lqueue->rear->type = 1;
			}
			else if (!strcmp(a, Char))
			{
				char *d = (char*)malloc(sizeof(char));
				printf("请输入数据\n");
				scanf_s("%c", &d);
				EnLQueue(lqueue, (void*)d);
				lqueue->rear->type = 2;
			}
			else if (!strcmp(a, Float))
			{
				float *d = (float*)malloc(sizeof(float));
				printf("请输入数据\n");
				scanf_s("%f", &d);
				EnLQueue(lqueue, (void*)d);
				lqueue->rear->type = 3;
			}
			else if (!strcmp(a, Double))
			{
				double *d = (double*)malloc(sizeof(double));
				printf("请输入数据\n");
				scanf_s("%lf", &d);
				EnLQueue(lqueue, (void*)d);
				lqueue->rear->type = 4;
			}; break;//
		case 5:  DeLQueue(lqueue); break;//循环的目标，一个整形指针
		case 6:  ClearLQueue(lqueue); break;//ok
		case 7:  DestoryLQueue(lqueue); break;//ok
		case 8:  GetHeadLQueue(lqueue, e); break;
		case 9:  TraverseLQueue(lqueue,LPrint); break;
		


		default: setvbuf(stdin, NULL, _IONBF, 0); //数字输入错误，跳出siwtch语句，进入下一次循环
			printf("输入数字不正确\n");
			break;
		}
		setvbuf(stdin, NULL, _IONBF, 0);
	}
	while (1);
	return 0;
}


