#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define M 20
#define  elemtype  char
typedef struct
{
    elemtype stack[M];
    int top;
}stacknode;
void init(stacknode *st);
void push(stacknode *st,elemtype x);
void pop(stacknode *st);

void init(stacknode *st)
{
    st->top=0;
}

void push(stacknode *st,elemtype x)
{
        if (st->top == M ) {  // 如果栈满，这里需要处理一下  
        printf("Stack is full!\n");  
        return;  
    }  
    st->top++;  
    st->stack[st->top] = x;  
}

void pop(stacknode *st)
{
    if (st->top==0) {  // 如果栈空，这里需要处理一下  
        printf("Stack is empty!\n"); 
    }  
    st->top--;  

}

int main()
{
    char s[M];
    unsigned int i;
    stacknode *sp;
    printf("create a empty stack!\n");
    sp=malloc(sizeof(stacknode));
    init(sp);
    printf("input a expression:\n");
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='(')
            push(sp,s[i]);
        if(s[i]==')')
            pop(sp);
    }
    if(sp->top==0)
        printf("'('match')'!\n");
    else
        printf("'('not match')'!\n");
    return 0;
}
