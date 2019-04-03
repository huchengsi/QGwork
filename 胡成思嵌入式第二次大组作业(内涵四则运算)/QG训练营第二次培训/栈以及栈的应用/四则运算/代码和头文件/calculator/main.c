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
	//第一个栈，用于转换中缀式为后缀式
	//第二个栈，用于计算
	int main()
	{
		while (1) {

			LinkStack *digit = (LinkStackPtr)malloc(sizeof(LinkStack*));   //数字栈
			LinkSymbolStack *symbol = (LinkSymbolPtr)malloc(sizeof(LinkSymbolStack*));    //符号栈
			initLStack(digit);
			initsymbol(symbol);
			float a, b;
			float result = 0;
			int i = 0;
			char ac[100] = { 0 };
			printf("请输入一个四则运算式：\n");
			scanf_s("%s", ac, 100);
			if (strlen(ac) < 3)
				continue;
			while (ac[i] != '\0' || i < strlen(ac))
			{


				if (judgedigit(ac[i]) || (i == 0 && ac[i] == '-') || (i != 0 && judgechar(ac[i - 1]) && ac[i] == '-') && ac[i] != '\0')//判断是不是数字
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
				if (ac[i] == '+' || (ac[i] == '-') || ac[i] == '*' || ac[i] == '/' || ac[i] == '(' || ac[i] == ')' || ac[i] == '\0')//判断是不是正常符号
				{
					int k = i;
					while (ac[k] == '+' || (ac[k] == '-' && !judgechar(ac[k - 1])) || ac[k] == '*' || ac[k] == '/' || ac[i] == '\0' || ac[i] == '(' || ac[i] == ')')
					{
						//printf("%c    ", ac[k]);
						if ((isEmptysymbol(symbol) && ac[k] != '\0'))//若为空这直接入栈
						{
							pushsymbol(symbol, ac[k]);
							//printf("    debugin:%c   ", symbol->top->symbol);

						}

						else if (judgerank(ac[k], symbol->top->symbol) && ac[k] != '\0' || symbol->top->symbol == '(')//入栈符号优先级高一些,入栈 有左括号，入栈
						{
							pushsymbol(symbol, ac[k]);
							//printf("    debugin:%c   ", symbol->top->symbol);

						}
						else if ((!judgerank(ac[k], symbol->top->symbol) && ac[k] != ')' || symbol->top->symbol == '(') && ac[k] != '(')  //入栈符号优先级小于等于栈顶，'('除外
						{
							while (!isEmptysymbol(symbol) || ac[k] != '\0' || symbol->top->symbol != '(')//清空符号栈或者到左括号为止
							{
								if (symbol->top->symbol != '(')//括号不能被运算
								{
									result = calculate(pop(digit), pop(digit), pops(symbol));//运算?括号不能被运算
									pushLStack(digit, result);//结果入数字栈
								}

								if (symbol->top == NULL || digit->top == NULL || symbol->top->symbol == '(')//清空完毕
									break;
								if (symbol->top != NULL && symbol->top->next != NULL && symbol->top->symbol != '(')//（如果需要被清空：即栈中还有符号存在）到左括号为止
								{
									symbol->top = symbol->top->next;//向后移动
								}

							}
							if (ac[k] != '\0')
								pushsymbol(symbol, ac[k]);         //还是要入栈					
						}
						else if (ac[k] == ')' || ac[i] == ')')                         //括号特判,一对括号间只会存在一个符号!!!!!!!
						{
							result = calculate(pop(digit), pop(digit), pops(symbol));//运算一次
							pushLStack(digit, result);//结果入数字栈
							pops(symbol);           //左括号出栈
						}
						if (ac[i] == '\0')//一切结束
							break;
						k++;
						if (!judgechar(ac[k]))/////////()后怎么办。。
							break;//////////
					}
					i = k;
				}
				else
					i++;
			}
			if (symbol->top != NULL && symbol->top->next == NULL)
			{
				result = calculate(pop(digit), pop(digit), pops(symbol));//运算一次
				pushLStack(digit, result);//结果入数字栈
			}

			while (symbol->top != NULL && symbol->top->next != NULL)//若最后还有没出栈的符号，全部出栈  ()怎么办
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


	/*计算，用ac[i - 1]或ac[i]作为判断结束的标志，如果结束，符号栈就要出完，而如果没有结束，符号栈还是按正常情况操作* /


	
/*1.左到右遍历每个数字和符号，是数字就输出。(ok)  2.若是符号，则判断优先级
    3.右括号或优先级不高于（>=）栈顶符号，则依次出栈输出。    
	4.从左到右遍历每个数字与符号，是数字就进栈。5.若是遇到符号，将栈
	顶数字出栈并运算。。。。。。。。。。待解决：多位数，浮点数，优先级，输入的
	应该是char还是float  注意：translate的输出直接相应地给了calculate
	第一步，输出translate代表其成功（float）第二步：完成calculate。第三步：
	结合这两个，得到最终版本。*/



