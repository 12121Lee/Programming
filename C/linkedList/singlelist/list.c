#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*本程序用一级指针完成，需要返回新头节点，插入后需要更新头指针*/
//节点结构
typedef struct Node
{
    int data;
    struct Node *next;
}node;


// 创建新节点
node* createNode(int value)
{
    node* newNode = (node*) malloc(sizeof(node));
    if(newNode == NULL)
    {
        printf("malloc failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
//判空
int isEmpty(node* head)
{
    return head == NULL;
}

// 创建(头插法)
node* insertAtHead(node* head, int value)
{
    node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// 创建(尾插法)
node* insertAtTail(node* head, int value)
{
    node* newNode = createNode(value);
    if (head == NULL)
        return newNode; //链表为空，返回新节点
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head; // 返回原头节点
}

// 删除
node* deleteNode(node* head, int key)
{
    node* temp = head;
    node* prev = NULL;
    // 如果头节点是要删除的节点
    if(temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return head;
    }
    // 查找要删除的节点
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    // 如果没找到要删除的节点
    if(temp == NULL)
    {
        printf("未找到要删除的节点\n");
        return head;
    }
    // 断开连接并释放内存
    prev->next = temp->next;
    free(temp);
    return head;
    
}

// 打印
void showList(node* head)
{
    node* current = head;
    while(current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 查找
node* search(node* head, int key)
{
    node* current = head;
    while(current != NULL)
    {
        if(current->data == key)
            return current;
        current = current->next;
    }
    printf("未找到节点\n");
    return NULL;
}

// 修改
void modify(node* head, int oldValue, int newValue)
{
    node* current = head;
    while(current != NULL)
    {
        if(current->data == oldValue)
        {
            current->data = newValue; // 更新节点值
            return;
        }
        current = current->next;
    }
    printf("未找到节点\n");
}

// 清空
node* clearList(node* head)
{
    node* current = head;
    node* nextNode;
    while(current != NULL)
    {
        nextNode = current->next; // 保存下一个节点的指针
        free(current); // 释放当前节点
        current = nextNode; // 移动到下一个节点
    }
    return NULL; // 返回空指针，表示链表已清空
}

// 销毁
void destroyList(node* head)
{
    node* current = head;
    node* nextNode;
    while(current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// 排序

int main(int argc, char const *argv[])
{
    // 创建链表
   node* head = NULL;
   // 头插法插入
   head = insertAtHead(head, 1);
   head = insertAtHead(head, 2);
   head = insertAtHead(head, 3);
   //打印
   showList(head);
   // 清空
   head = clearList(head);
   //尾插法
   head = insertAtTail(head, 1);
   head = insertAtTail(head, 2);
   head = insertAtTail(head, 3);
   //打印
   showList(head);
   // 删除
   head = deleteNode(head, 2);
   showList(head);
   // 查找
   node* foundNode = search(head, 3);
   if(foundNode != NULL)
       printf("找到节点值: %d\n", foundNode->data);
   else
       printf("未找到节点\n");
   // 修改
   modify(head, 1, 4);
   showList(head);
   // 销毁
   destroyList(head);
   head = NULL; // 将头指针设置为NULL，防止悬空指针
   showList(head);

   return 0;
}
