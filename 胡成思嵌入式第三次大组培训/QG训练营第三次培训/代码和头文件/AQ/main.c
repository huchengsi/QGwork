#include"../head/AQueue.h"
#include<stdio.h>
#include<stdlib.h>
//
	int x = 1;
	void *e;
int main()
{
	char a[10];
	char Int[10] = "int";
	char Char[10] = "char";
	char Float[10] = "float";
	char Double[10] = "double";
	 AQueue *aqueue = (void*)malloc(sizeof(AQueue));
	 Mydata *Vdata = (Mydata*)malloc(sizeof(Mydata));

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
		printf("按数字键选择要执行的操作:\n ");
		scanf_s("%d", &x);
		setvbuf(stdin, NULL, _IONBF, 100);
		printf("\n");

		if (x == 2) exit(1);  //输入2，退出程序

		if ('x' < '1' || 'x' > '11')
		{
			printf("非法输入\n");
			break;
		}
		switch (x)
		{
		case 1:  break; //输入1，跳出switch语句，进入下一次循环
		case 3:  InitAQueue(aqueue); break;//ok
		case 4: 
                
                 printf("请输入入队类型\n");	 
                 scanf_s("%s", a, 10);
				 setvbuf(stdin, NULL, _IONBF, 100);
                 if (!strcmp(a, Int))//判断用户输入的目的类型
                 {
					   Mydata a;
	                   Mydata *d=&a;
					   d->type = 1;
	                   printf("请输入数据\n");
	                   scanf_s("%d", &(d->INT));
					 
					   EnAQueue(aqueue, (void*)d);
	                   
                  }
				 else if (!strcmp(a, Char))
				{
					 Mydata a;
					 Mydata *d = &a;
					 d->type = 2;
					 printf("请输入数据\n");
					 scanf_s("%c", &(d->CHAR));
					 EnAQueue(aqueue, (void*)d);
				}
				 else if (!strcmp(a, Float))
				 {
					 Mydata a;
					 Mydata *d = &a;
					 d->type = 3;
					 printf("请输入数据\n");
					 scanf_s("%f", &(d->FLOAT));
					 EnAQueue(aqueue, (void*)d);
				 }
				 else if (!strcmp(a, Double))
				 {
					 Mydata a;
					 Mydata *d = &a;
					 d->type = 4;
					 printf("请输入数据\n");
					 scanf_s("%lf", &(d->DOULBLE));
					 EnAQueue(aqueue, (void*)d);
				 }; break;//从尾部插入
		case 5:  DeAQueue(aqueue); break;//
		case 6:  ClearAQueue(aqueue); break;//
		case 7:  DestoryAQueue(aqueue); break;//
		case 8:    GetHeadAQueue(aqueue,e); break;//
		case 9:  TraverseAQueue(aqueue, APrint); break;
		


		default: ; //数字输入错误，跳出siwtch语句，进入下一次循环
			printf("输入数字不正确\n");
			break;
		}

	}
	while (1);
	return 0;
}


