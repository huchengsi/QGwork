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

		printf("-------------����ѡ��-----------\n");
		printf("1:���ز˵�");
		printf("          2:�˳����� \n");
		printf("3:��ʼ������");
		printf("        4:��� \n");
		printf("5:����");
		printf("              6:��ն��� \n");
		printf("7:���ٶ���");
		printf("          8:�鿴��ͷ \n");
		printf("9:������� \n");
		

		printf("--------------------------------\n");
		printf("�����ּ�ѡ��Ҫִ�еĲ���:\n ");
		scanf_s("%d", &x);
		setvbuf(stdin, NULL, _IONBF, 100);
		printf("\n");

		if (x == 2) exit(1);  //����2���˳�����

		if ('x' < '1' || 'x' > '11')
		{
			printf("�Ƿ�����\n");
			break;
		}
		switch (x)
		{
		case 1:  break; //����1������switch��䣬������һ��ѭ��
		case 3:  InitAQueue(aqueue); break;//ok
		case 4: 
                
                 printf("�������������\n");	 
                 scanf_s("%s", a, 10);
				 setvbuf(stdin, NULL, _IONBF, 100);
                 if (!strcmp(a, Int))//�ж��û������Ŀ������
                 {
					   Mydata a;
	                   Mydata *d=&a;
					   d->type = 1;
	                   printf("����������\n");
	                   scanf_s("%d", &(d->INT));
					 
					   EnAQueue(aqueue, (void*)d);
	                   
                  }
				 else if (!strcmp(a, Char))
				{
					 Mydata a;
					 Mydata *d = &a;
					 d->type = 2;
					 printf("����������\n");
					 scanf_s("%c", &(d->CHAR));
					 EnAQueue(aqueue, (void*)d);
				}
				 else if (!strcmp(a, Float))
				 {
					 Mydata a;
					 Mydata *d = &a;
					 d->type = 3;
					 printf("����������\n");
					 scanf_s("%f", &(d->FLOAT));
					 EnAQueue(aqueue, (void*)d);
				 }
				 else if (!strcmp(a, Double))
				 {
					 Mydata a;
					 Mydata *d = &a;
					 d->type = 4;
					 printf("����������\n");
					 scanf_s("%lf", &(d->DOULBLE));
					 EnAQueue(aqueue, (void*)d);
				 }; break;//��β������
		case 5:  DeAQueue(aqueue); break;//
		case 6:  ClearAQueue(aqueue); break;//
		case 7:  DestoryAQueue(aqueue); break;//
		case 8:    GetHeadAQueue(aqueue,e); break;//
		case 9:  TraverseAQueue(aqueue, APrint); break;
		


		default: ; //���������������siwtch��䣬������һ��ѭ��
			printf("�������ֲ���ȷ\n");
			break;
		}

	}
	while (1);
	return 0;
}


