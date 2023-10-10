#include <stdio.h>  
#include <stdlib.h>  
  
// 定义结构体  
typedef struct Node {  
    int data;  
    struct Node *next;  
} Node;  
  
// 定义函数初始化链表  
Node* initList(int arr[], int size) {  
    Node *head = (Node*)malloc(sizeof(Node)); // 创建头结点  
    head->next = NULL; // 初始时链表为空  
    Node *tail = head; // 定义尾节点为头结点  
  
    // 将数组元素添加到链表中  
    for (int i = 0; i < size; i++) {  
        Node *newNode = (Node*)malloc(sizeof(Node)); // 创建新节点  
        newNode->data = arr[i]; // 将数据添加到新节点中  
        newNode->next = NULL; // 新节点没有下一个节点  
        tail->next = newNode; // 将新节点添加到尾部  
        tail = newNode; // 更新尾节点位置  
    }  
    return head; // 返回头结点  
}  
  
// 定义函数打印链表  
void printList(Node *head) {  
    Node *temp = head->next; // 从第一个元素开始打印  
    while (temp != head) { // 当没有下一个元素时停止  
        printf("%d ", temp->data); // 打印元素数据  
        temp = temp->next; // 移动到下一个元素  
    }  
    printf("\n"); // 打印换行符  
}  
  
// 定义函数删除元素  
void deleteElement(Node *head, int m) {  
    Node *temp = head->next; // 从第一个元素开始  
    Node *prev = head; // 保存上一个元素位置  
    while (temp != head) { // 当没有下一个元素时停止  
        if (temp->data == m) { // 当找到要删除的元素时  
            prev->next = temp->next; // 将上一个元素的下一个元素设为当前元素的下一个元素  
            free(temp); // 释放当前元素内存  
            break; // 跳出循环  
        }  
        prev = temp; // 移动到下一个元素  
        temp = temp->next; // 移动到下一个元素  
    }  
}  
  
// 定义函数删除所有元素  
void deleteAll(Node *head) {  
    Node *temp = head->next; // 从第一个元素开始  
    while (temp != head) { // 当没有下一个元素时停止  
        free(temp); // 释放当前元素内存  
        temp = temp->next; // 移动到下一个元素  
    }  
    free(head); // 释放头结点内存  
}  
  
int main() {  
    int arr[] = {1, 2, 3, 4, 5}; // 初始化数组元素  
    int size = sizeof(arr) / sizeof(arr[0]); // 计算数组大小  
  
    Node *head = initList(arr, size); // 初始化链表  
    printList(head); // 打印链表  
  
    for (int i = 1; i <= 5; i++) { // 当还有大于一个元素时执行删除操作  
        deleteElement(head, i); // 删除元素  
        printList(head); // 打印链表  
    }  
    deleteAll(head); // 删除所有元素  
    return 0;  
}