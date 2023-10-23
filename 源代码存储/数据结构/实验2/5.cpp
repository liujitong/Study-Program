#include<stdio.h>
#include<stdlib.h>
#include<iostream>
//带头结点的循环单链表队列,只有一个尾指针
struct LQueue {
	int date;
	LQueue* next;
};
typedef struct
{
	LQueue* rear;
 
}SeqLQueue;
//循环队列构造函数,初始化空队列
int Create_Empty_Queue(SeqLQueue &mode)
{
	mode.rear = (LQueue*)malloc(sizeof(LQueue));
	if (!mode.rear)
	{
		printf("ERROR\n");
		return 0;
	}
	mode.rear->next = mode.rear;           //尾指针的下一个还是自己,空队列自循环
	printf("SUCESS\n");	
    return 1;
 
}
 
//入队函数,表尾插入
int Insertt(SeqLQueue& p, int e)
{
	LQueue* q;
	q = (LQueue*)malloc(sizeof(LQueue));
	if (!q)
	{
		printf("内存分配失败!\n");
		return 0;
	}
 
	q->date = e;
	q->next = p.rear->next;                     //构成循环，q的下一个是队列头,即原p.rear->next
	p.rear->next = q;                           //入队,插入到表尾之后	
	p.rear = q;                                 //更新表尾指针为q指针
	return 1;
}
 
//出队函数,表头出队
int Pop_Queue(SeqLQueue& p, int& e)
{
	if (p.rear == p.rear->next)
	{
		printf("EMPTY\n");
		return 0;
	}
 
	LQueue* q;                                   //用来保存需要出队的元素指针
	q = p.rear->next->next;                     //rear.next是头节点,头结点下一个节点才是首数据地址
	p.rear->next->next = q->next;               //从队列里面删除q节点
	e = q->date;
 
	if (q == p.rear)                             //如果队列就一个元素,让队列自循环
		p.rear = p.rear->next;
	free(q);
 
	return 1;
}
 
//判断是否空队列函数
bool Empty_Queue(SeqLQueue& p)
{
	if (p.rear == p.rear->next)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 
//遍历队列所有元素
void PRINT(SeqLQueue& p)
{
 
	LQueue* k;
	k = p.rear->next->next;
	while (k != p.rear->next)
	{
		printf("%d ", k->date);
		k = k->next;
	}
	printf("\n");
}
int main()
{
    SeqLQueue Cirecle;
    Cirecle.rear =(LQueue*)malloc(sizeof(LQueue));
    Create_Empty_Queue(Cirecle);				
	if(Empty_Queue(Cirecle)) std::cout<<"空"<<std::endl;					
    else printf("不空");
		Insertt(Cirecle, 18);
        Insertt(Cirecle, 13);
        Insertt(Cirecle, 28);
        Insertt(Cirecle, 24);
        Insertt(Cirecle, 26);	
		PRINT(Cirecle);

	printf("现在");
	if(Empty_Queue(Cirecle)) printf("不空");
    else printf("空");
	printf("现在chudui");
    int num;
    while (Empty_Queue(Cirecle))
    {
	Pop_Queue(Cirecle,num);
    std::cout<<num<<""<<std::endl;
    }
    std::cout<<std::endl;
    if(Empty_Queue(Cirecle)) printf("不空");					
    else printf("空");
	return 0;
}