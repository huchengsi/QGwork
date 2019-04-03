#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef float ElemType;
/*******************************����********************************************/
typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;
	int	count;
}LinkStack;

Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s, ElemType *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack *s, int *length);//���ջ����
Status pushLStack(LinkStack *s, ElemType data);//��ջ
Status popLStack(LinkStack *s, ElemType *data);//��ջ
double pop(LinkStackPtr mystack);
void push(LinkStackPtr mystack);
void judge(int a);
/**************************����************************/
typedef  struct SymbolNode
{
	char symbol;
	struct SymbolNode *next;
}SymbolNode, *LinkSymbolPtr;

typedef  struct  SymbolStack {
	LinkSymbolPtr top;
	int	count;
}LinkSymbolStack;


//��ջ
Status initsymbol(LinkSymbolStack *s);//��ʼ��ջ
Status isEmptysymbol(LinkSymbolStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopsymbol(LinkSymbolStack *s,char *e);//�õ�ջ��Ԫ��
Status clearsymbol(LinkSymbolStack *s);//���ջ
Status destroysymbol(LinkSymbolStack *s);//����ջ
Status symbolLength(LinkSymbolStack *s,int *length);//���ջ����
Status pushsymbol(LinkSymbolStack *s,char data);//��ջ
Status popsymbol(LinkSymbolStack *s,char *data);//��ջ
char pops(LinkSymbolPtr mystack);
void pushs(LinkSymbolPtr mystack);
void judge(int a);
/********************************************************************************/


#endif // STACK_H_INCLUDED
