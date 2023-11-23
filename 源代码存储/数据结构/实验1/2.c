#include<stdio.h>
#include<malloc.h>

#define ERROR 0
#define OK 1

typedef int ElemType; /* 定义表元素的类型 */

typedef struct LNode { /* 线性表的单链表存储 */
    ElemType data;
    struct LNode* next;
} LNode, * LinkList;

LinkList CreateList(int n); /* 创建一个线性表 */
void PrintList(LinkList L); /* 输出带头结点单链表的所有元素 */
int GetElem(LinkList L, int i, ElemType* e); /* 查找某个位置的元素 */
int ListInsert(LinkList L, int i, ElemType e); /* 在指定位置插入元素 */
int DeleteList(LinkList L, int i); /* 删除指定位置的元素 */

LinkList CreateList(int n) {
    LNode* p, * q, * head;
    int i;
    head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;
    p = head;
    for (i = 0; i < n; i++) {
        q = (LinkList)malloc(sizeof(LNode));
        printf("input data %i:", i + 1);
        scanf("%d", &q->data); /* 输入元素值 */
        q->next = NULL; /* 结点指针域置空 */
        p->next = q; /* 新结点连在表末尾 */
        p = q;
    }
    return head;
}

void PrintList(LinkList L) {
    LNode* p;
    p = L->next; /* p指向单链表的第1个元素 */
    while (p != NULL) {
        printf("%5d", p->data);
        p = p->next;
    }
}

int ListInsert(LinkList L, int i, ElemType e) {
    LinkList p = L;
    int j = 0;
    while (p && (j < i - 1)) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) return ERROR;
    LinkList s = (LinkList)malloc(sizeof(LNode)); // 初始化
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

int DeleteList(LinkList L, int i) {
    LinkList p = L;
    int j = 0;
    while ((p->next) && (j < i - 1)) {
        p = p->next;
        j++;
    }
    if (!(p->next) || (j > i - 1)) {
        return ERROR;
    }
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s = p->next;
    p->next = s->next;
    free(s);
    return OK;
}

int GetElem(LinkList L, int i, ElemType* e) {
    LNode* p;
    int j = 1;
    p = L->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}

int main() {
    int n, i;
    ElemType e;
    LinkList L = NULL; /* 定义指向单链表的指针 */
    printf("please input n:"); /* 输入单链表的元素个数 */
    scanf("%d", &n);
    if (n > 0) {
        printf("\n1-Create LinkList:\n");
        L = CreateList(n);
        printf("\n2-Print LinkList:\n");
        PrintList(L);
        printf("\n3-GetElem from LinkList:\n");
        printf("input i=");
        scanf("%d", &i);
        if (GetElem(L, i, &e))
            printf("No%i is %d", i, e);
        else
            printf("not exists");
    }
    else printf("ERROR");

    printf("\nWHERE DO YOU WANT INSERT\n");
    scanf("%d", &i);
    printf("\nWHAT DO YOU WANT INSERT\n");
    scanf("%d", &n);
    if (ListInsert(L, i, n)) {
        printf("\n4-Print LinkList:\n");
        PrintList(L);
    }
    else printf("IE");
    printf("\nWHERE DO YOU WANT DELETE\n");
    scanf("%d", &i);
    if (DeleteList(L, i)) {
        printf("\n5-Print LinkList:\n");
        PrintList(L);
    }
    else printf("IE");
    return 0;
}