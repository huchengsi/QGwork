#include<stdio.h>
#include<stdlib.h>
#include"../head/LQueue.h"
//FILE *stream;//��bug�õ�
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
		printf("�����ּ�ѡ��Ҫִ�еĲ���: ");
		scanf_s("%d", &x);
		setvbuf(stdin, NULL, _IONBF, 100);
		printf("\n");

		if (x == 2) exit(1);  //����2���˳�����

		if ('x' < '1' || 'x' > '11')
		{
			printf("�Ƿ�����");
			break;
		}
		switch (x)
		{
		case 1:  break; //����1������switch��䣬������һ��ѭ��
		case 3:  InitLQueue(lqueue); break;//ok
		case 4:
			printf("�������������\n");
			scanf_s("%s", a, 10);
			setvbuf(stdin, NULL, _IONBF, 100);
			if (!strcmp(a, Int))//�ж��û������Ŀ������
			{
				int *d=(int*)malloc(sizeof(int));
				printf("����������\n");
				scanf_s("%d", d);
				EnLQueue(lqueue,(void*)d);
				lqueue->rear->type = 1;
			}
			else if (!strcmp(a, Char))
			{
				char *d = (char*)malloc(sizeof(char));
				printf("����������\n");
				scanf_s("%c", &d);
				EnLQueue(lqueue, (void*)d);
				lqueue->rear->type = 2;
			}
			else if (!strcmp(a, Float))
			{
				float *d = (float*)malloc(sizeof(float));
				printf("����������\n");
				scanf_s("%f", &d);
				EnLQueue(lqueue, (void*)d);
				lqueue->rear->type = 3;
			}
			else if (!strcmp(a, Double))
			{
				double *d = (double*)malloc(sizeof(double));
				printf("����������\n");
				scanf_s("%lf", &d);
				EnLQueue(lqueue, (void*)d);
				lqueue->rear->type = 4;
			}; break;//
		case 5:  DeLQueue(lqueue); break;//ѭ����Ŀ�꣬һ������ָ��
		case 6:  ClearLQueue(lqueue); break;//ok
		case 7:  DestoryLQueue(lqueue); break;//ok
		case 8:  GetHeadLQueue(lqueue, e); break;
		case 9:  TraverseLQueue(lqueue,LPrint); break;
		


		default: setvbuf(stdin, NULL, _IONBF, 0); //���������������siwtch��䣬������һ��ѭ��
			printf("�������ֲ���ȷ\n");
			break;
		}
		setvbuf(stdin, NULL, _IONBF, 0);
	}
	while (1);
	return 0;
}


