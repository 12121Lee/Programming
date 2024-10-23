#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 头节点结构
typedef struct Node
{
    int data; // 数据域
    struct Node *next; // 指针域
}node;

// 创建头节点
node* CreateNode()
{
    node* L = (node*)malloc(sizeof(node));
    if(L == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    L->next = NULL;
    return L;
}

// 初始化链表
node* CreateNewNode(int date)
{
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newnode->data = date;
    newnode->next = NULL;
    return newnode;
}

// 头插
void InsertAtHead(node* L, int data)
{
    node* newnode = CreateNewNode(data); // 创建新节点
    newnode->next = L->next;
    L->next = newnode;
    // node* newnode = (node*)malloc(sizeof(node));
    // newnode->data = data;
    // newnode->next = L;
    // return newnode;
}

// 尾插
void InsertAtTail(node* L, int data)
{
    node* newnode = CreateNewNode(data);

    if(L == NULL)
    {
        L = newnode;
    }
    
    node* last = L;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newnode;
}

// 按位置插入
void InsertByIndex(node* L, int index, int value)
{
    node* prev = L;
    for(int i = 0;i < index -1; i++) // index-1是为了到插入位置的前一个节点
    {
        prev = prev->next;
    }
    node* cur = CreateNewNode(value);
    cur->next = prev->next;
    prev->next = cur;
}

// 按位置删除
void deleteListByIndex(node* L, int index )
{
    if(index < 1)
    {
        printf("删除的位置不合理\n");
        return;
    }
    int i  = 0;
    node* prev = L, *cur;
    while(prev->next && i < index)
    {
        prev = prev->next;
        i++;
    }
    if(prev->next == NULL && i > index - 1)
    {
        printf("删除的位置超出表长,不合理\n");
        return;
    }
      cur = prev->next;
      prev->next = cur->next;
      free(cur);
}

// 删除指定的值
void deleteListByValue(node* L, int value)
{
    if(L->next == NULL)
    {
        printf("链表为空!\n");
        return;
    }
    node* prev = L;
    if(prev->next->data == value)
    {
        L = L->next;
        free(prev);
        return;
    }
    while(prev->next != NULL)
    {
        if(prev->next->data == value)
        {
            prev->next = prev->next->next;
            return;
        }
        prev = prev->next;
    }
    printf("未找到值!\n");
    return;
}

// 修改
void UpdateList(node* L, int oldValue, int newValue)
{
    if(L->next == NULL)
    {
        printf("链表为空\n");
        return;
    }
    node* cur = L->next;
    bool updated = false;
    while(cur != NULL)
    {
        if(cur->data == oldValue)
        {
            cur->data = newValue;
            updated = true;
        }
        cur = cur->next;
    }
    if(!updated)
    {
        printf("未找到值，无法修改!\n");
    }
}


// 查找
int FindList(node* L, int value)
{
    if(L->next == NULL)
    {
        printf("链表为空!\n");
        return -1;
    }
    node* cur = L->next;
    while (cur != NULL)
    {
        if(cur->data == value)
        {
            return cur->data;
        }
        cur = cur->next;
    }
    printf("未找到值!\n");
    return -1;
}


// 打印
void PrintList(node* L)
{
    node* temp = L->next;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 计算长度
int GetLen(node* L)
{
    int len = 0; // 初始化长度
    node* temp = L->next;
    if(L == NULL)
    {
        printf("链表为空!\n");
        return EXIT_FAILURE;
    }
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// 判断是否为空
bool IsEmpty(node* L)
{
    return L->next == NULL;
}

// 清空
void ClearList(node* L)
{
   node*p, *q;
    p = L->next;
    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

// 销毁
void DestroyList(node* L)
{
    ClearList(L);
    free(L);
}

int main(int argc, char const *argv[])
{
    node* L = CreateNode();
    // node *L = NULL;
    printf("头插法:");
    InsertAtHead(L, 1);
    InsertAtHead(L, 2);
    InsertAtHead(L, 3);
    InsertAtHead(L, 4);
    InsertAtHead(L, 5);
    PrintList(L);
    
    // ClearList(L);

    // printf("尾插法:");
    // InsertAtTail(L, 1);
    // InsertAtTail(L, 2);
    // InsertAtTail(L, 3);
    // InsertAtTail(L, 4);
    // InsertAtTail(L, 5);
    // PrintList(L);
    
    // printf("在index为%d插入数据%d: ",1, 6);
    // InsertByIndex(L, 1, 6);
    // PrintList(L);

    // printf("删除index为%d的数据:", 5);
    // deleteListByIndex(L, 5); // 超过了会出现内存泄露
    // PrintList(L);


    // printf("链表长度为%d\n", GetLen(L));

    printf("删除值为%d的数据:", 3);
    deleteListByValue(L, 3); // 内存泄漏的地方
    PrintList(L);


    // printf("查找6的结果为:%d\n", FindList(L, 6));


    // printf("更新%d的值为%d\n",6, 60);
    // UpdateList(L, 6, 60);
    // PrintList(L);

    // ClearList(L);
    // IsEmpty(L)?printf("链表为空\n"):printf("链表不为空\n");

    DestroyList(L);
    return 0;
}
