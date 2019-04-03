#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef float ElemType;
/*******************************数据********************************************/
typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;
	int	count;
}LinkStack;

Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s, ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s, int *length);//检测栈长度
Status pushLStack(LinkStack *s, ElemType data);//入栈
Status popLStack(LinkStack *s, ElemType *data);//出栈
double pop(LinkStackPtr mystack);
void push(LinkStackPtr mystack);
void judge(int a);
/**************************符号************************/
typedef  struct SymbolNode
{
	char symbol;
	struct SymbolNode *next;
}SymbolNode, *LinkSymbolPtr;

typedef  struct  SymbolStack {
	LinkSymbolPtr top;
	int	count;
}LinkSymbolStack;


//链栈
Status initsymbol(LinkSymbolStack *s);//初始化栈
Status isEmptysymbol(LinkSymbolStack *s);//判断栈是否为空
Status getTopsymbol(LinkSymbolStack *s,char *e);//得到栈顶元素
Status clearsymbol(LinkSymbolStack *s);//清空栈
Status destroysymbol(LinkSymbolStack *s);//销毁栈
Status symbolLength(LinkSymbolStack *s,int *length);//检测栈长度
Status pushsymbol(LinkSymbolStack *s,char data);//入栈
Status popsymbol(LinkSymbolStack *s,char *data);//出栈
char pops(LinkSymbolPtr mystack);
void pushs(LinkSymbolPtr mystack);
void judge(int a);
/********************************************************************************/


#endif // STACK_H_INCLUDED
