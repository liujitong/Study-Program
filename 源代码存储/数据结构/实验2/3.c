#include <assert.h>
#define MAXSIZE 100
typedef int ELEMTYPE;
struct queue {
    int front;
    int rear;
    ELEMTYPE elem[MAXSIZE];
};
struct queue q;
void init()
{
    q.front = q.rear = 0;
}
void enqueue(ELEMTYPE item)
{
    assert(((q.rear+1) % MAXSIZE) != q.front); 
    q.rear = (q.rear + 1) % MAXSIZE; // increment rear 
    q.elem[q.rear] = item;
}
    ELEMTYPE dequeue()	// dequeue element fro front of queue 
{
    assert(!isEmpty());	// there must be somethingtodequeue 
    q.front = (q.front + 1) % MAXSIZE;	// increment front 
    return q.elem[q.front]; // return value 
}
    ELEMTYPE firstValue() // get value of front element 
{
    assert(!isEmpty());
    return q.elem[(q.front+1) % MAXSIZE];
}
int isEmpty()	// TRUE is queue is empty 
{
return q.front == q.rear;
}
int main()
{
    init();
    enqueue(10); 	// q is (10)       
    enqueue(20); 	// q is (10,20)
    enqueue(30);	// q is (10,20,30)
    printf("%d",firstValue());	// will display 10 
    printf("%d",dequeue());		// will displa 10 
    return 0;
}
