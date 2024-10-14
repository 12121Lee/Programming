#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 带头节点的单链表
typedef struct node
{
    int data;
    struct node *next;
}Node;

// 创建一个头节点，并返回一个指针指向它
Node * CreateNode()
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->next = NULL;
    return newNode;
}

// 初始化链表
Node* InitLinkedList(int data)
{
    Node* newNode = CreateNode();
    if(newNode == NULL)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printLinkedList(Node* head)
{
    Node* p = head->next;
    while(p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// 头插法
void insertNodeByHead(Node* head, int data)
{
    Node* p = InitLinkedList(data);
    p->next = head->next;
    head->next = p;
}

// 尾插法
void insertNodeByTail(Node* head, int data)
{
    Node *p = InitLinkedList(data);
    p->next = NULL;
    Node *tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = p;
}

// 计算长度
int Length(Node* head)
{
    int count = 0;
    Node* p = head->next;
    while(p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

void ListStatus(Node *head)
{
    if(head == NULL)
        printf("链表为空!\n");
    if(head->next == NULL)
        printf("链表不存在!\n");
}

// 销毁链表
void destroyList(Node* head)
{
    Node *p;
    while(head)
    {
        p = head;
        head = head->next;
        free(p);
    }
    printf("链表已经销毁!\n");
}

// 清空链表
void clearList(Node* head)
{
    Node*p, *q;
    p = head->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    head->next = NULL;
    printf("链表已经清空!\n");
}

int main(int argc, char const *argv[])
{
    Node* head = CreateNode();
    // printf("头插法(倒序):");
    // for(int i = 0; i < 10; i++)
    //     insertNodeByHead(head, i);
    // printLinkedList(head);

    printf("尾插法(顺序):");
    for(int i = 0; i < 10; i++)
        insertNodeByTail(head, i);
    printLinkedList(head);
    printf("共有%d个节点\n", Length(head));
    // destroyList(head);
    clearList(head);
    insertNodeByTail(head, 1);
    printLinkedList(head);
    return 0;
}
