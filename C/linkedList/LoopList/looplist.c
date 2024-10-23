#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list
{
    int data;
    struct list *next;
}list;

// 初始化结点
list* initList()
{
    list *head = (list*)malloc(sizeof(list));
    if(head == NULL)
    {
        printf("创建失败，退出程序");
        exit(0);
    }
    else
    {
        head->next = NULL;
        return head;
    }
}

// 创建--插入数据
int create_list(list *head)
{
    int data;
    printf("请输入要插入的元素: ");
    scanf("%d", &data);
    list* node = initList();
    node->data = data;
    //初始化一个新的结点，准备进行链接
    if(head != NULL)
    {
        list* p = head;
        //找到最后一个数据
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = node;
        node->next = head;
        return 1;
    }
    else
    {
        printf("头结点已无元素\n");
        return 0;
    }
}

// 插入元素
list* insert_list(list* head,int pos, int data)
{
    list* node = initList();
    list*p = head;
    list *t;
    t = p;
    node->data = data;
    if(head != NULL)
    {
        for (int i = 1; i < pos; i++)
        {
            t = t->next;
        }
        node->next = t->next;
        t->next = node;
        return p;
    }
    return p;
}

// 删除元素
int delete_list(list* head)
{
    if(head == NULL)
    {
        printf("链表为空!\n");
        return 0;
    }
    list* temp = head;
    list* ptr = head->next;

    int del;
    printf("请输入你要删除的元素: ");
    scanf("%d",&del);

    while (ptr != head)
    {
        if (ptr->data == del)
        {
           if(ptr->next == head)
           {
                temp->next = head;
                free(ptr);
                return 1;
           }
           temp->next = ptr->next;
           free(ptr);
           return 1;
        }
        temp = temp->next;
        ptr = ptr->next;
    }
    printf("没有找到要删除的元素\n");
    return 0;
}

// 遍历元素
int display(list* head)
{
    if(head != NULL)
    {
        list* p = head;
        while (p->next != head)
        {
            printf("%d ",p->next->data);
            p = p->next;
        }
        printf("\n");
        return 1;
    }
    else
    {
        printf("头结点为空!\n");
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    list* head = initList();
    head->next = head;
    for (int i = 0; i < 5; i++)
    {
        create_list(head);
    }
    display(head);
    head = insert_list(head, 1, 10);
    display(head);

    delete_list(head);
    display(head);
    return 0;
}

