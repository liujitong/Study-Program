#include<stdio.h>  
#include<malloc.h>  
#define ERROR 0  
#define OK 1  
#define STACK_INT_SIZE 10  /*存储空间初始分配量*/  
#define STACKINCREMENT 5  /*存储空间分配增量*/  
typedef  int ElemType; /*定义元素的类型*/  
typedef struct{  
    ElemType *base;  
    ElemType *top;  
    int stacksize;     /*当前已分配的存储空间*/  
}SqStack;  
  
int InitStack(SqStack *S);   /*构造空栈*/  
int push(SqStack *S,ElemType e); /*入栈*/  
int Pop(SqStack *S,ElemType *e);  /*出栈*/  
int CreateStack(SqStack *S);     /*创建栈*/  
void PrintStack(SqStack *S);   /*出栈并输出栈中元素*/  
  
int InitStack(SqStack *S){  
    S->base=(ElemType *)malloc(STACK_INT_SIZE *sizeof(ElemType));  
    if(!S->base) return ERROR;  
    S->top=S->base;  
    S->stacksize=STACK_INT_SIZE;  
    return OK;  
}/*InitStack*/  
  
int Push(SqStack *S,ElemType e){  
    if(S->top == S->base + S->stacksize) {  // 检查栈是否已满  
        S->base = (ElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType));  // 重新分配更多的内存  
        if(!S->base) return ERROR;  // 如果内存分配失败，返回错误  
        S->top = S->base + S->stacksize;  // 更新栈顶指针  
        S->stacksize += STACKINCREMENT;  // 更新栈的容量  
    }  
    *S->top = e;  // 将元素放入栈顶  
    S->top++;  // 更新栈顶指针  
    return OK;  
}/*Push*/  
  
int Pop(SqStack *S,ElemType *e){  
    if(S->top == S->base) return ERROR;  // 检查栈是否已空  
    *e = *--S->top;  // 取出栈顶元素并赋值给e  
    return OK;  
}/*Pop*/  
  
int CreateStack(SqStack *S){  
    int e;  
    if(InitStack(S))  
        printf("Init Success!\n");  
    else{  
        printf("Init Fail!\n");  
        return ERROR;  
    }  
    printf("input data:(Terminated by inputing a character)\n");  
    while(scanf("%d",&e))  
        Push(S,e);  
    return OK;  
}/*CreateStack*/  
  
void PrintStack(SqStack *S){  
    ElemType e;  
    while(Pop(S,&e))  
        printf("%d ",e);  // 这里应该是%d而不是%3d，因为我们需要打印整数，没有指定宽度  
}/*Pop_and_Print*/  

void TRANSFER_10_to_2(int n)
{
    printf("INPUT 2 NUM\n");
    SqStack sq;
    InitStack(&sq);
    while(n!=0)
    {
    Push(&sq,n%2);
    n=n/2;
    }
    while(Pop(&sq,&n)) printf("%d",n);
}
int main(){  
    // SqStack ss;  
    // printf("\n1-createStack\n");  
    // CreateStack(&ss);  
    // printf("\n2-Pop&Print\n");  
    // PrintStack(&ss); 
    //10转2
    TRANSFER_10_to_2(10);
    return 0;  
}