#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
    int data;
    struct line *prev;
    struct line *next;
}line, *a;

// 创建
line* initLine(line* head)
{
    int number, pos = 1,input_data;
    printf("请输入创建结点的大小\n");
    scanf("%d", &number);
    if(number < 1)
    {
        return NULL;
    }
    //头结点创建
    head = (line*)malloc(sizeof(line));
    head->prev = NULL;
    head->next = NULL;
    printf("输入第%d个数据\n",pos++);
    scanf("%d", &input_data);
    head->data = input_data;

    line* list = head;
    while (pos <= number)
    {
        line* body = (line*)malloc(sizeof(line));
        body->prev = NULL;
        body->next = NULL;
        printf("输入第%d个数据\n",pos++);
        scanf("%d", &input_data);
        body->data = input_data;

        list->next = body;
        body->prev = list;
        list = list->next;
    }
    return head;
}

// 插入数据
line* insertLine(line* head, int data, int add)
{
    line* temp = (line*)malloc(sizeof(line));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    //插入到链表头,要特殊考虑
    if(add == 1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        line* body = head;
        //找到要插入位置的前一个结点
        for(int i = 1;i < add-1; i++)
        {
            body = body->next;
        }
        //判断条件为真，说明插入位置为链表尾
        if(body->next == NULL)
        {
            body->next = temp;
            temp->prev = body;
        }
        else
        {
            body->next->prev = temp;
            temp->next = body->next;
            body->next = temp;
            temp->prev = body;
        }
    }
    return head;
}

//删除元素
line* deleteLine(line* head, int data)
{
    line* list = head;
    while(list)
    {
        if(list->data == data)
        {
            list->prev->next = list->next;
            list->next->prev = list->prev;
            free(list);
            printf("--删除成功--\n");
            return head;
        }
        list = list->next;
    }
    printf("Error:没有找到该元素,没有产生删除\n");
    return head;
}

//遍历
void printLine(line* head)
{
    line* list = head;
    int pos = 1;
    while(list)
    {
        printf("第%d个数据是:%d\n",pos++, list->data);
        list = list->next;
    }
}


int main(int argc, char const *argv[])
{
    line* head = NULL;
    printf("创建双链表操作\n");
    head = initLine(head);
    printLine(head);
    
    printf("插入操作\n");
    head = insertLine(head, 40, 2);
    printLine(head);

    printf("删除操作\n");
    head = deleteLine(head, 2);
    printLine(head);


    return 0;
}
