#include"../head/calculator.h"
#include<stdio.h>
#include<stdlib.h>

int rank(char symbol1)
{
	switch (symbol1)
	{
	    case(')'): return 0;
	    case('+'):
	    case('-'): return 1;
	    case('*'):
	    case('/'): return 2;
	    case('('): return 3;
	
	    default:  return 0;
		    break;
	}
}
double calculate(double a, double b, char sy);
	//��һ��ջ������ת����׺ʽΪ��׺ʽ
	//�ڶ���ջ�����ڼ���
	int main()
	{
		while (1) {

			LinkStack *digit = (LinkStackPtr)malloc(sizeof(LinkStack*));   //����ջ
			LinkSymbolStack *symbol = (LinkSymbolPtr)malloc(sizeof(LinkSymbolStack*));    //����ջ
			initLStack(digit);
			initsymbol(symbol);
			float a, b;
			float result = 0;
			int i = 0;
			char ac[100] = { 0 };
			printf("������һ����������ʽ��\n");
			scanf_s("%s", ac, 100);
			if (strlen(ac) < 3)
				continue;
			while (ac[i] != '\0' || i < strlen(ac))
			{


				if (judgedigit(ac[i]) || (i == 0 && ac[i] == '-') || (i != 0 && judgechar(ac[i - 1]) && ac[i] == '-') && ac[i] != '\0')//�ж��ǲ�������
				{
					char ele[100];
					int k = i;
					while ((ac[k] >= '0'&&ac[k] <= '9') || ac[k] == '.' || (ac[k] == '-'&&judgechar(ac[k - 1])) || ac[k] == '-'&&k == 0)
						k++;
					memcpy(ele, &ac[i], k);
					//printf("%lf    ", atof(ele));
					pushLStack(digit, atof(ele));
					i = k;
				}
				if (ac[i] == '+' || (ac[i] == '-') || ac[i] == '*' || ac[i] == '/' || ac[i] == '(' || ac[i] == ')' || ac[i] == '\0')//�ж��ǲ�����������
				{
					int k = i;
					while (ac[k] == '+' || (ac[k] == '-' && !judgechar(ac[k - 1])) || ac[k] == '*' || ac[k] == '/' || ac[i] == '\0' || ac[i] == '(' || ac[i] == ')')
					{
						//printf("%c    ", ac[k]);
						if ((isEmptysymbol(symbol) && ac[k] != '\0'))//��Ϊ����ֱ����ջ
						{
							pushsymbol(symbol, ac[k]);
							//printf("    debugin:%c   ", symbol->top->symbol);

						}

						else if (judgerank(ac[k], symbol->top->symbol) && ac[k] != '\0' || symbol->top->symbol == '(')//��ջ�������ȼ���һЩ,��ջ �������ţ���ջ
						{
							pushsymbol(symbol, ac[k]);
							//printf("    debugin:%c   ", symbol->top->symbol);

						}
						else if ((!judgerank(ac[k], symbol->top->symbol) && ac[k] != ')' || symbol->top->symbol == '(') && ac[k] != '(')  //��ջ�������ȼ�С�ڵ���ջ����'('����
						{
							while (!isEmptysymbol(symbol) || ac[k] != '\0' || symbol->top->symbol != '(')//��շ���ջ���ߵ�������Ϊֹ
							{
								if (symbol->top->symbol != '(')//���Ų��ܱ�����
								{
									result = calculate(pop(digit), pop(digit), pops(symbol));//����?���Ų��ܱ�����
									pushLStack(digit, result);//���������ջ
								}

								if (symbol->top == NULL || digit->top == NULL || symbol->top->symbol == '(')//������
									break;
								if (symbol->top != NULL && symbol->top->next != NULL && symbol->top->symbol != '(')//�������Ҫ����գ���ջ�л��з��Ŵ��ڣ���������Ϊֹ
								{
									symbol->top = symbol->top->next;//����ƶ�
								}

							}
							if (ac[k] != '\0')
								pushsymbol(symbol, ac[k]);         //����Ҫ��ջ					
						}
						else if (ac[k] == ')' || ac[i] == ')')                         //��������,һ�����ż�ֻ�����һ������!!!!!!!
						{
							result = calculate(pop(digit), pop(digit), pops(symbol));//����һ��
							pushLStack(digit, result);//���������ջ
							pops(symbol);           //�����ų�ջ
						}
						if (ac[i] == '\0')//һ�н���
							break;
						k++;
						if (!judgechar(ac[k]))/////////()����ô�졣��
							break;//////////
					}
					i = k;
				}
				else
					i++;
			}
			if (symbol->top != NULL && symbol->top->next == NULL)
			{
				result = calculate(pop(digit), pop(digit), pops(symbol));//����һ��
				pushLStack(digit, result);//���������ջ
			}

			while (symbol->top != NULL && symbol->top->next != NULL)//�������û��ջ�ķ��ţ�ȫ����ջ  ()��ô��
			{

				a = pop(digit);
				b = pop(digit);
				char c = pops(symbol);
				result = calculate(a, b, c);
				pushLStack(digit, result);
				symbol->top = symbol->top->next;
			}
			printf("%lf\n", result);
			setvbuf(stdin, NULL, _IONBF, 0);
		}
		while (1);
		return 0;
	}
	Status judgedigit(char ac)
	{
		if ((ac >= '0'&&ac <= '9') || ac == '.')
			return SUCCESS;
		else
			return ERROR;
	}

	Status judgechar(char ac)
	{
		if (ac == '+' || ac == '-' || ac == '*' || ac == '/'||ac=='(')
			return SUCCESS;
		else
			return ERROR;
	}


	Status judgerank(char inside,char put)
	{
		if (rank(inside)>rank(put))//!!   debug
			return SUCCESS;
		else if(rank(inside) <= rank(put))
			return ERROR;
	}

	double calculate(double a, double b, char sy)
	{
		if (sy == '+')
			return a + b;
		else if (sy == '-')
			return a - b;
		else if (sy == '*')
			return a * b;
		else if (sy == '/')
			return a / b;
		else
			return;
	}


	/*���㣬��ac[i - 1]��ac[i]��Ϊ�жϽ����ı�־���������������ջ��Ҫ���꣬�����û�н���������ջ���ǰ������������* /


	
/*1.���ұ���ÿ�����ֺͷ��ţ������־������(ok)  2.���Ƿ��ţ����ж����ȼ�
    3.�����Ż����ȼ������ڣ�>=��ջ�����ţ������γ�ջ�����    
	4.�����ұ���ÿ����������ţ������־ͽ�ջ��5.�����������ţ���ջ
	�����ֳ�ջ�����㡣���������������������������λ���������������ȼ��������
	Ӧ����char����float  ע�⣺translate�����ֱ����Ӧ�ظ���calculate
	��һ�������translate������ɹ���float���ڶ��������calculate����������
	������������õ����հ汾��*/



