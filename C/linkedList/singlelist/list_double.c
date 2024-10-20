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

// 创建(头插法),用二级指针
void insertAtHead(node** head, int value)
{
    node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// 创建(尾插法),用二级指针,不返回任何值
void insertAtTail(node** head, int value)
{
    node* newNode = createNode(value);
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    node* temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 删除
void deleteNode(node** head, int key)
{
    if(*head == NULL)
        return;
    node* current = *head;
    node* prev = NULL;
    // 如果要删除的节点是头节点
    if(current->data == key)
    {
        *head = current->next;
        free(current);
        return;
    }
    // 查找要删除的节点
    while(current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }
    // 如果找到了要删除的节点
    if(current != NULL)
    {
        prev->next = current->next;
        free(current);
    }
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
node* findNode(node* head, int key)
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
    printf("未找到值为%d的节点\n", oldValue);
}

// 清空
void clearList(node** head)
{
    node* current = *head;
    node* nextNode;
    while(current != NULL)
    {
        nextNode = current->next; // 保存下一个节点的指针
        free(current); // 释放当前节点
        current = nextNode; // 移动到下一个节点
    }
    *head = NULL; // 将头指针设置为NULL
}

// 销毁
void destroyList(node** head)
{
    clearList(head);
    free(*head);
    *head = NULL;
}

// 排序

int main(int argc, char const *argv[])
{
    // 创建链表
   node* head = NULL;
   // 头插法插入
   insertAtHead(&head, 1);
   insertAtHead(&head, 2);
   insertAtHead(&head, 3);
   //打印
   showList(head);
   // 清空
   clearList(&head);
   //尾插法
   insertAtTail(&head, 1);
   insertAtTail(&head, 2);
   insertAtTail(&head, 3);
   //打印
   showList(head);
   // 删除
   deleteNode(&head, 2);
   showList(head);
   // 查找
   findNode(head, 3);
   // 修改
   modify(head, 1, 4);
   showList(head);
   // 销毁
   destroyList(&head);
   showList(head);

   return 0;
}
