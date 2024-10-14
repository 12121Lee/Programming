#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef struct node
{
    int data;
    struct node *next;
}Node;

// 初始化链表
Node* InitList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

// 判断头节点指针域是否为空
int ListEmpty(Node *head)
{
    if(head->next) //非空
    {
        return ERROR;
    }
    else
    {
        return OK;
    }
}

// 销毁单链表(从头节点开始, 依次释放所有节点)
void DestroyList(Node *head)
{
   Node *p;
   while (head)
   {
       p = head;
       head = head->next;
       free(p);
   }
}

// 清空单链表(依次释放所有节点, 头节点指针域置空)
void ClearList(Node *head)
{
    Node* p, *q;
    p = head->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    head->next = NULL;
}

// 计算链表长度
int ListLength(Node *head)
{
    int len = 0; 
    Node *p = head->next; // p指向第一个节点
    while (p)
    {
        len++; 
        p = p->next; 
    }
    return len;
}

// 获取链表中某个元素的内容,通过变量e返回
int GetElem(Node *head, int i, int value)
{
    int j = 1;
    Node *p = head->next; //向后扫描，直到p指向第i个元素或p为空
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if(!p || j > i)
    {
        return ERROR; //第i个元素不存在
    }
    value = p->data; //取第i个元素
    printf("第%d个元素的值为%d\n", i, value);
    return OK;
}

// 查找某个值. 找到返回地址
Node* LocateElem(Node *head, int value)
{
    Node* p = head->next;
    while(p&&p->data!=value)
    {
        p = p->next;
    }
    return p;
}

// 查找某个值. 找到返回序号
int LocateElem2(Node *head, int value)
{
    Node* p = head->next;
    int j = 1;
    while(p&&p->data!=value)
    {
        p = p->next;
        j++;
    }
    if(p)
    {
        return j;
    }
    else
    {
        return ERROR;
    }
}

// 在链表中第i个位置之前插入新的数据元素e
int ListInsert(Node *head, int i, int value)
{
    Node* p = head;
    int j = 0;
    while(p&&j<i-1) //寻找第i-1个节点, p指向i-1节点
    {
        p = p->next;
        ++j;
    }
    if(!p || j>i-1) // i小于1或者大于表长， 插入位置非法
    {
        return ERROR;
    }
    Node* s = (Node*)malloc(sizeof(Node)); // 生成新节点s,将节点s的数据域置为e
    s->data = value; 
    s->next = p->next;
    p->next = s;
    return OK;
}

// 删除链表中第i个位置的元素
int ListDelete(Node *head, int i)
{
    Node* p = head;
    int j = 0;
    while(p->next&&j<i-1) //寻找第i个节点, p指向i-1节点
    {
        p = p->next;
        ++j;
    }
    if(!(p->next) || j>i-1) // i小于1或者大于表长， 删除位置非法
    {
        return ERROR;
    }
    Node* q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

// 头插法
void CreateListHead(Node *head)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->next = head->next;
    head->next = p;
}

// 尾插法
void CreateListTail(Node *head, int n)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    p->data = n;
    Node *r = head;
    while (r->next)
    {
        r = r->next;
    }
    r->next = p;
    r = p;
}

// 打印链表
void displayList(Node *head)
{
    Node *p = head->next;
    while(p)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// 修改链表中指定元素的值
int ListChange(Node *head, int oldValue, int newValue)
{
    Node *p = head->next;
    while(p)
    {
        if(p->data == oldValue)
        {
            p->data = newValue;
        }
        else
        {
            return ERROR;
        }
        p = p->next;
    }
    return OK;
}

int main(int argc, char const *argv[])
{
    Node *head = InitList();
    for (int i = 1; i < 10; i++)
    {
        CreateListTail(head, i);
    }
    displayList(head);
    // ClearList(head);
    // displayList(head);
    if(ListDelete(head, 1))
    {
        printf("删除成功\n");
    }
    else
    {
        printf("删除失败\n");
    }
    displayList(head);
    if(ListChange(head, 30, 999))
    {
        printf("修改成功\n");
    }
    else
    {
        printf("修改失败\n");
    }
    displayList(head);
    return 0;
}
