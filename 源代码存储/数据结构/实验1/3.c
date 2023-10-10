#include <stdio.h>  
#include <stdlib.h>  
  
typedef int ElemType;  
  
typedef struct LNode{  
    ElemType data;  
    struct LNode *next;  
}LNode,*LinkList;  
  
// 创建循环链表  
LinkList CreateCircularLinkedList(int n) {  
    int i;  
    LinkList head, p, r;  
    head = (LinkList) malloc(sizeof(LNode)); // 创建头结点  
    head->data = 0; // 头结点不存储数据  
    head->next = head; // 头结点指向自己  
    r = head; // r指向头结点  
    for(i = 1; i <= n; i++) {  
        p = (LinkList) malloc(sizeof(LNode)); // 创建新节点  
        p->data = i; // 新节点的数据为i  
        p->next = head; // 新节点的下一节点为头结点  
        r->next = p; // 将r的下一节点指向新节点  
        r = p; // r指向新节点  
    }  
    return head;  
}  
  
// 打印循环链表  
void PrintCircularLinkedList(LinkList L) {  
    LinkList p = L->next; // p指向第一个节点  
    while(p != L) { // 只要p不是头结点  
        printf("%d ", p->data); // 打印节点的数据  
        p = p->next; // p指向下一个节点  
    }  
    printf("\n");  
}  
  
// 约瑟夫环问题  
void JosephusProblem(LinkList L, int m) {  
    LinkList p = L->next; // p指向第一个节点  
    int count = 0; // 计数器初始值为0  
    while(p != L) { // 只要p不是头结点  
        count++; // 计数器加1  
        if(count == m) { // 如果计数器等于m  
            printf("删除的元素为：%d\n", p->data); // 打印删除的元素的数据  
            p = p->next; // p指向下一个节点  
            count = 0; // 计数器归零  
        } else {  
            p = p->next; // p指向下一个节点  
        }  
    }  
}  
  
int main() {  
    int n, m;  
    printf("请输入元素个数n：");  
    scanf("%d", &n);  
    printf("请输入计数器m：");  
    scanf("%d", &m);  
    LinkList L = CreateCircularLinkedList(n); // 创建循环链表  
    printf("循环链表中的元素为：");  
    PrintCircularLinkedList(L); // 打印循环链表中的元素  
    JosephusProblem(L, m); // 约瑟夫环问题  
    return 0;  
}