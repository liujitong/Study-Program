#include <malloc.h>
	#include <assert.h>
	#include<iostream>
	#include<stdio.h>
	typedef int ELEMTYPE;
	struct node {
		ELEMTYPE elem;
		struct node *next;
	};
	struct node *front;
	struct node *rear;
	int isEmpty()
	{
		return front == NULL;
	}
	void init()
	{
		rear= NULL;
	}
	void enqueue(ELEMTYPE item)
	{
	if (rear !=NULL) {
			rear->next=(struct node *)malloc(sizeof(struct node));
			rear->next->elem = item;
		rear->next->next = NULL;
			rear = rear->next;
	}
		else {
			front=rear=(struct node *)malloc(sizeof(struct node));
			front->elem = item;
	front->next = NULL;
		}
	}
	ELEMTYPE dequeue()
	{
		ELEMTYPE temp = front->elem;
	struct node *ltemp = front;
		assert(isEmpty()==0);
		front = front->next;
		free(ltemp);
		if (front==NULL) rear = NULL;
	return temp;
	}
	ELEMTYPE firstValue()
	{
		assert(isEmpty()==0);
		return front->elem;
    }

	int main()
	{
		init();
		enqueue(10);
		enqueue(20);
		enqueue(30);
		printf("%d\n",firstValue());
		printf("%d\n",dequeue());
	}
