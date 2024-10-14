#ifndef __MAIN_H
#define __MAIN_H
//头文件
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//宏定义
#define Account "./info.txt"
#define FileName "./books.txt"
//结构体存放书籍信息
struct Books   //定义书籍结构体
{
    int id; //书籍编号
    char name[100]; //书籍名称
    char publisher[100]; //出版社
    char Date[100]; //出版日期
    int amount; //书籍数量
    float price; //书籍价格
};
//创建链表用于图书的相关操作
struct Node
{
    //int data;
    struct Books data;
    struct Node *next;
};
struct Node *list = NULL; //初始化链表
struct Books tempBook; //定义结构体对象
struct Node *result = NULL; //初始化查询
//函数定义
void init(); //登陆或者注册账号
void Register(); //注册
void Login();    //登录
void quit_system(); //退出系统
void main_menu(); //主菜单
void book_add();  // 1、图书录入
void book_show(); // 2、图书输出
void book_check(); // 3、图书查询
void book_modify(); // 4、图书修改
void book_remove(); // 5、图书删除
void book_sort(struct Node *HeadNode);       // 6、图书排序
void book_borrow();  // 7、图书借阅
void book_back(); // 8、图书归还
void book_save(const char *fileName,struct Node *HeadNode); // 9、图书信息保存
void book_load(const char *fileName,struct Node *HeadNode); // 10、图书信息读取
void back_ask(); //退出询问
void back_ask()
{
    char back[100];
    printf("操作完成,是否继续?(yes or no?):\n");
    scanf("%s",back);
    if (strncmp(back,"yes",3) == 0)
    {
        main_menu();
    }
    else
    {
        printf("欢迎您的下次使用!\n");
        exit(0);
    }
    return;
}
//创建表头:表头就是一个结构体变量
struct Node *CreateHead()
{
    struct Node *HeadNode = (struct Node *)malloc(sizeof(struct Node));
    HeadNode->next = NULL;
    return HeadNode;
}
//创建结点
struct Node *CreateNode(struct Books data) 
{
    struct Node *NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->next = NULL;
    return NewNode;
}
//插入(头插法)
struct Node *InsertNodeByHead(struct Node *HeadNode,struct Books data)
{
    struct Node *NewNode = CreateNode(data);
    NewNode->next = HeadNode->next;
    HeadNode->next = NewNode;
    return HeadNode;
}
//尾插法
struct Node *InsertNodeByTail(struct Node *HeadNode,struct Books data)
{
    struct Node *pMove = HeadNode;
    while (pMove->next != NULL) //pMove没有找到尾结点
    {
       pMove = pMove->next; //一直往下寻找
    }
    //找到尾结点后
    struct Node *NewNode = CreateNode(data);
    pMove->next =NewNode;
    NewNode->next = NULL;
    return HeadNode;
}
//指定位置删除
void DeleteNodeByName(struct Node *HeadNode, char *BookName)
{
    struct Node * PosLeftNode = HeadNode;
    struct Node * PosNode = HeadNode->next;
    while (PosNode != NULL && strcmp(PosNode->data.name,BookName))
    {
        PosLeftNode = PosNode;
        PosNode = PosLeftNode->next;
    }
    if (PosNode == NULL)
    {
        printf("%s已不存在!\n", BookName);
        return;
    }
    else
    {
        printf("删除成功!\n");
        PosLeftNode->next = PosNode->next;
        free(PosNode);
        PosNode = NULL;
    }
    
}
//打印链表
void PrintList(struct Node *HeadNode)
{
    struct Node *pMove = HeadNode->next;
     if (pMove == NULL)
    {
        printf("图书信息未被录入!\n");
        sleep(2);
        main_menu();
        return;
    }
    printf("编号\t书名\t出版社\t\t日期\t\t数量\t价格\t\n");
    while (pMove != NULL)
    {
        printf("%d\t%s\t%s\t%s\t%d\t%.1f\t\n", pMove->data.id,pMove->data.name,pMove->data.publisher,pMove->data.Date
        ,pMove->data.amount,pMove->data.price);
        pMove = pMove->next;
    }
    // printf("\n");
}
//查找
struct Node *SearchByName(struct Node *HeadNode,char *BookName)
{
    struct Node *posNode = HeadNode->next;
    while (posNode != NULL && strcmp(posNode->data.name,BookName))
    {
       posNode = posNode->next;
    }
    return posNode;
}
#endif // __MAIN__H