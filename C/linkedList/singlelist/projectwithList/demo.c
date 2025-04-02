#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

typedef struct Student
{
    int id;
    char name[20];
    int age;
    float score;
}Stu;

//定义结点类型
typedef struct Node
{
    Stu student; // 数据域
    struct Node *next; // 指针域
}Node, *LinkedList;

void menu();
void selectMenu();
void add(Node *L, Stu stu);
void delete(Node *L, Stu stu);
void find(Node *L, Stu stu);
void update(Node *L, Stu stu);

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
void LinkedListCreatH(Node* L, Stu stu)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->student = stu;
    p->next = L->next;
    L->next = p;
}

// // 尾插法建立单链表
// LinkedList LinkedListCreatT()
// {
//     Node *L = (Node *)malloc(sizeof(Node));
//     L->next = NULL;

//     Node* r = L;
//     int x;
//     while (1)
//     {
//         scanf("%d", &x);
//         if(x == -1)
//         {
//             break;
//         }
//         Node *p = (Node*)malloc(sizeof(Node));
//         p->data = x;
//         r->next = p;
//         r = p;
//     }
//     r->next = NULL;
//     return L;
// }

// 遍历
void printList(LinkedList L, Stu stu)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("编号:%d 姓名:%s, 年龄:%d, 分数:%.2f\n", p->student.id,p->student.name, p->student.age, p->student.score);
        p = p->next;
    }
    printf("\n");
}

// 在链表中修改值为oldval的元素
bool LinkedListReplace(LinkedList L,Stu stu, int newval)
{
    Node *p = L->next;
    while(p != NULL)
    {
        if(p->student.id == stu.id)
        {
            p->student.id = newval;
            printf("编号:%d 姓名:%s, 年龄:%d, 分数:%.2f\n", p->student.id,p->student.name, p->student.age, p->student.score);
            return true;
        }
        p = p->next;
    }
    return false;
}

// // 插入 在第i个位置插入x的元素
// LinkedList LinkedListInsert(LinkedList L, int i, int x)
// {
//     Node *prev = L; //前驱结点
//     int tempi = 0;
//     for ( tempi = 1; tempi < i; tempi++)
//     {
//        prev = prev->next;
//     }
//     Node *p = (Node *)malloc(sizeof(Node));
//     p->data = x;
//     p->next = prev->next;
//     prev->next = p;

//     return L;
// }

// 删除
bool LinkedListDelete(LinkedList L,Stu stu)
{
    Node *p, *pre; // pre为前驱结点，p为查找结点
    p = L->next;
    while(p)
    {
        if (p->student.id == stu.id)
        {
            pre->next = p->next;
            free(p);
            return true;
        }
        pre = p;
        p = p->next;
    }
    return false;
}

// // 删除所有重复的值
// void LinkedListDeleteAll(LinkedList L, int x) {
//     Node *p = L->next; // 指向第一个节点
//     Node *pre = L;     // 指向前一个节点，初始时指向头节点
//     while (p != NULL) {
//         if (p->data == x) {
//             // 找到匹配的元素，删除它
//             pre->next = p->next;
//             free(p); // 释放节点内存
//             p = pre->next; // 移动p到下一个节点
//         } else {
//             // 没有找到匹配的元素，移动pre和p到下一对节点
//             pre = p;
//             p = p->next;
//         }
//     }
// }

// 查询
void FindLinkedList(LinkedList L, Stu stu)
{
    Node* p = L->next;
    while (p != NULL)
    {
        if(p->student.id == stu.id)
        {
            printf("%d %s %d %.2f\n", p->student.id, p->student.name, p->student.age, p->student.score);
            return;
        }
        p = p->next;
    }
    printf("未找到编号为%d的学生\n", stu.id);
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

// // 判断空
// int IsLinkedListEmpty(LinkedList L)
// {
//     return L->next == NULL;
// }

// // 计算长度
// int GetLinkedListLength(LinkedList L)
// {
//     Node* p = L->next;
//     int len = 0;
//     while (p != NULL)
//     {
//         p = p->next;
//         len++;
//     }
//     return len;
// }

void add(Node *L, Stu stu)
{
    int n = 0;
    printf("录入学生的个数: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d个学生的编号,姓名,年龄和分数: ", i + 1);
        scanf("%d%s%d%f", &stu.id, stu.name, &stu.age, &stu.score);
        LinkedListCreatH(L, stu);
    }
    printf("学生信息：\n");
    printList(L, stu);
}

void delete(Node *L, Stu stu)
{
    printf("请输入需要删除的学生的编号: ");
    scanf("%d", &stu.id);
    if(LinkedListDelete(L, stu))
    {
        printf("删除后学生信息：\n");
        printList(L, stu);
    }
    else
    {
        printf("未找到编号为%d的学生\n", stu.id);
    }
}

void find(Node *L, Stu stu)
{
    printf("请输入需要查询的学生的编号: ");
    scanf("%d", &stu.id);
    FindLinkedList(L, stu);
}

void update(Node *L, Stu stu)
{
    int id;
    printf("请输入需要修改的学生的编号: ");
    scanf("%d", &stu.id);
    printf("请输入修改的编号: ");
    scanf("%d", &id);
    
    if(!LinkedListReplace(L, stu, id))
    {
        printf("未找到编号为%d的学生\n", stu.id);
    }
}

void menu()
{
    printf("1. 录入\n");
    printf("2. 删除\n");
    printf("3. 查询\n");
    printf("4. 修改\n");
    printf("5. 显示\n");
    printf("0. 退出\n");
    selectMenu();
}



void selectMenu()
{
    Node* L = listinit();
    Stu stu;
    memset(&stu, 0, sizeof(stu));

    while (1)
    {
        
        int choice;
        printf("请选择功能: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:add(L, stu);break;
            case 2:delete(L, stu);break;
            case 3:find(L,stu);break;
            case 4:update(L,stu);break;
            case 5:printList(L, stu);break;  // 显示所有学生信息
            case 0:DestroyLinkedList(L);exit(0);break;
            default:printf("输入有误，请重新输入!\n");menu();
        }
    }
    
}

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}