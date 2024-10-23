#include <stdio.h>
#include <stdlib.h>

//定义结点类型
typedef struct Node
{
    int data; // 数据域
    struct Node *next; // 指针域
}Node, *LinkedList;

// 初始化
LinkedList listinit()
{
    Node *L = (Node *)malloc(sizeof(Node));
    if(L == NULL)
    {
        printf("申请空间失败");
        exit(EXIT_FAILURE);
    }
    L->next = NULL;
    return L;
}

// 头插法创建链表
LinkedList LinkedListCreatH()
{
    Node *L = (Node *)malloc(sizeof(Node));
    L->next = NULL;

    int x;
    while (1)
    {
        scanf("%d", &x);
        if(x == -1)
        {
            break;
        }
        Node *p = (Node*)malloc(sizeof(Node));
        p->data = x;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

// 尾插法建立单链表
LinkedList LinkedListCreatT()
{
    Node *L = (Node *)malloc(sizeof(Node));
    L->next = NULL;

    Node* r = L;
    int x;
    while (1)
    {
        scanf("%d", &x);
        if(x == -1)
        {
            break;
        }
        Node *p = (Node*)malloc(sizeof(Node));
        p->data = x;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return L;
}

// 遍历
void printList(LinkedList L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d->",p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// 在链表中修改值为oldval的元素
LinkedList LinkedListReplace(LinkedList L,int oldval, int newval)
{
    Node *p = L->next;
    while(p != NULL)
    {
        if(p->data == oldval)
        {
            p->data = newval;
        }
        p = p->next;
    }
    return L;
}

// 插入 在第i个位置插入x的元素
LinkedList LinkedListInsert(LinkedList L, int i, int x)
{
    Node *prev = L; //前驱结点
    int tempi = 0;
    for ( tempi = 1; tempi < i; tempi++)
    {
       prev = prev->next;
    }
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = prev->next;
    prev->next = p;

    return L;
}

// 删除
LinkedList LinkedListDelete(LinkedList L,int x)
{
    Node *p, *pre; // pre为前驱结点，p为查找结点
    p = L->next;
    while(p->data != x)
    {
        pre = p;
        p = p->next;
    }
    pre->next = p->next;
    free(p);
    return L;
}

// 删除所有重复的值
void LinkedListDeleteAll(LinkedList L, int x) {
    Node *p = L->next; // 指向第一个节点
    Node *pre = L;     // 指向前一个节点，初始时指向头节点
    while (p != NULL) {
        if (p->data == x) {
            // 找到匹配的元素，删除它
            pre->next = p->next;
            free(p); // 释放节点内存
            p = pre->next; // 移动p到下一个节点
        } else {
            // 没有找到匹配的元素，移动pre和p到下一对节点
            pre = p;
            p = p->next;
        }
    }
}

// 查询
int FindLinkedList(LinkedList L, int val)
{
    Node* p = L->next;
    while (p != NULL)
    {
        if(p->data == val)
        {
            return p->data;
        }
        p = p->next;
    }
    return -1;
}

// 清空
void ClearLinkedList(LinkedList L)
{
    Node *pre = L;
    Node *now;
    while (pre->next != NULL)
    {
        now = pre->next;
        pre->next = now->next;
        free(now);
    }
}

// 销毁
void DestroyLinkedList(LinkedList L)
{
    ClearLinkedList(L);
    free(L);
}

// 判断空
int IsLinkedListEmpty(LinkedList L)
{
    return L->next == NULL;
}

// 计算长度
int GetLinkedListLength(LinkedList L)
{
    Node* p = L->next;
    int len = 0;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

int main(int argc, char const *argv[])
{
    // 创建
    LinkedList list;
    printf("请输入单链表的数据,以-1结尾\n");
    // list = LinkedListCreatT();
    list = LinkedListCreatH();
    printList(list);

    //插入
    int i;
    int x;
    printf("请输入插入数据的位置: ");
    scanf("%d", &i);
    printf("请输入插入数据的值: ");
    scanf("%d", &x);
    LinkedListInsert(list, i, x);
    printList(list);

    //修改
    printf("请输入修改的数据: ");
    scanf("%d", &i);
    printf("请输入修改后的值: ");
    scanf("%d", &x);
    LinkedListReplace(list, i, x);
    printList(list);

    //删除
    printf("请输入要删除的元素的值: ");
    scanf("%d", &x);
    LinkedListDeleteAll(list, x);
    printList(list);

    // 计算长度
    printf("链表长度为:%d\n", GetLinkedListLength(list));

    // 查询
    printf("请输入你要查询的值:");
    scanf("%d",&x);
    printf("查询值为%d的值的结果是%d\n", x, FindLinkedList(list, x));

    //销毁
    DestroyLinkedList(list);
    return 0;
}
