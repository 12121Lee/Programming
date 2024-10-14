//  重大城科书店销售管理系统
//@written by liu on 6th Feb 2022
#include "./main.h"
void init()
{
	system("clear");
    printf("--------欢迎来到重大城科书店销售管理系统------\n");
    printf("|                  1.注册                    |\n");
    printf("|                  2.登陆                    |\n");
    printf("|                  3.退出                    |\n");
    printf("----------------------------------------------\n");
	int choice = 0;
	printf("请输入您的选择:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:Register();break;
        case 2:Login();break;
        case 3:quit_system();break;
        default:printf("你输入的指令有误,请重新输入!\n");sleep(1);init();
    }
}
//注册
void Register() //将注册信息写进info.txt文本中
{
    char name[100],password[100];
    printf("请输入您的姓名:\n");
    scanf("%s", name);
    printf("请输入您的密码:\n");
    scanf("%s",password);
    FILE *fp = fopen(Account,"a");
    if (fp == NULL)
    {
        perror("打开文件失败!\n");
        return;
    }
    fprintf(fp,"%s %s\n",name,password);
    printf("信息录入成功!\n");
    fclose(fp);
    sleep(1);
	init();
    return;
}
//登陆
void Login()
{
    char name[100],password[100],name1[100],password1[100]; //name为读取的信息，name1为输入的信息
    printf("请输入您的姓名:\n");
    scanf("%s", name1);
    printf("请输入您的密码:\n");
    scanf("%s",password1);
    FILE *fp = fopen(Account,"a+");
    if (fp == NULL)
    {
        perror("打开文件失败!\n");
        return;
    }
    while (!feof(fp)) //feof函数:判断是否到了文件末尾
    {
         fscanf(fp,"%s %s\n",name,password);
        if (strncmp(name,name1,sizeof(name)) == 0 && strncmp(password,password1,sizeof(password)) == 0)
        {
            printf("登录成功!即将进入主菜单!\n");
            fclose(fp);
            sleep(2);
            main_menu();
            return;
        }
    }
    printf("登录失败!请重新登陆!\n");
    sleep(1);
    init();
}
//离开系统
void quit_system() 
{
	printf("请问您真的要退出系统吗?(yes/no)\n");
	char choice[10];
	scanf("%s", choice);
	if (strncmp(choice, "yes",3) == 0) //输入yes
	{
		printf("谢谢您的使用,期待您的下一次使用!\n"); //输入no
		exit(0);
	}
	else //输入no
	{
		init();
	}
	return;
}
//主菜单
void main_menu() //店员的菜单
{
    system("clear");
    printf("--------欢迎来到重大城科书店销售管理系统------\n");
    printf("|                  1.图书录入                |\n");
    printf("|                  2.图书输出                |\n");
    printf("|                  3.图书查询                |\n");
    printf("|                  4.图书修改                |\n");
    printf("|                  5.图书删除                |\n");
    printf("|                  6.图书排序                |\n");
    printf("|                  7.图书借阅                |\n");
    printf("|                  8.图书归还                |\n");
    printf("|                  9.图书信息保存            |\n");
    printf("|                  10.图书信息读取           |\n");
    printf("|                  11.退出系统               |\n");
    printf("----------------------------------------------\n");
    int choice = 0;
    printf("请输入您的选择:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:book_add();break;
        case 2:book_show();break;
        case 3:book_check();break;
        case 4:book_modify();break;
        case 5:book_remove();break;
        case 6:book_sort(list);break;
        case 7:book_borrow();break;
        case 8:book_back();break;
        case 9:book_save(FileName,list);break;
        case 10:book_load(FileName,list);break;
        case 11:quit_system(1);break;
        default:printf("你输入的指令有误,请重新输入!\n");sleep(1);main_menu();
    }
}
//1.图书录入
void book_add()
{
    struct Books books; //临时变量存储数据
    printf("请输入书籍的信息(编号,姓名,出版社,日期,数量,价格):\n");
    scanf("%d%s%s%s%d%f",&books.id,books.name,books.publisher,books.Date,&books.amount,&books.price);
    InsertNodeByHead(list,books);
    printf("您录入的书籍信息完成!\n");
    sleep(1);
    main_menu();
}
//2.图书输出
void book_show()
{
    PrintList(list);
    back_ask();
}
//3.图书查询
void book_check()
{
    printf("请输入查找的书名:\n");
    scanf("%s",tempBook.name);
    result = SearchByName(list,tempBook.name);
    if (result == NULL)
    {
        printf("%s未找到!\n",tempBook.name);
        sleep(1);
        main_menu();
    }
    else
    {
        printf("编号\t书名\t出版社\t\t日期\t\t数量\t价格\t\n");
        printf("%d\t%s\t%s\t%s\t%d\t%.1f\t\n", result->data.id,result->data.name,result->data.publisher,result->data.Date
        ,result->data.amount,result->data.price);
        back_ask();
    }
    return;
}
//4.图书修改
void book_modify()
{
    int choice = 0;
    printf("请输入您要修改的书籍:\n");
    scanf("%s",tempBook.name);
    result = SearchByName(list,tempBook.name); //找到要修改的书籍
    if (result == NULL) //未找到书籍
    {
        printf("%s不存在,修改图书失败!\n",tempBook.name);
        sleep(1);
        main_menu();
    }
    else
    {
        printf("您即将修改\033[0;31m%s\033[0m的书籍信息\n",tempBook.name);
        printf("1.编号\n");
        printf("2.书名\n");
        printf("3.出版社\n");
        printf("4.日期\n");
        printf("5.数量\n");
        printf("6.价格\n");
        printf("请输入修改的类型:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                printf("请输入新的编号:\n");
                scanf("%d",&result->data.id);
                book_save(FileName,list);
                printf("书籍信息修改完成!\n");
                sleep(1);
                main_menu();
                break;
            case 2: 
                printf("请输入新的书名:\n");
                scanf("%s",result->data.name);
                book_save(FileName,list);
                printf("书籍信息修改完成!\n");
                sleep(1);
                main_menu();
                break;
            case 3:
                printf("请输入新的出版社:\n");
                scanf("%s",result->data.publisher);
                book_save(FileName,list);
                printf("书籍信息修改完成!\n");
                sleep(1);
                main_menu();
                break;
            case 4:
                printf("请输入新的日期:\n");
                scanf("%s",result->data.Date);
                book_save(FileName,list);
                printf("书籍信息修改完成!\n");
                sleep(1);
                main_menu(); 
                break;
            case 5: 
                printf("请输入新的数量:\n");
                scanf("%d",&result->data.amount);
                book_save(FileName,list);
                printf("书籍信息修改完成!\n");
                sleep(1);
                main_menu();
                break;
            case 6: 
                printf("请输入新的价格:\n");
                scanf("%f",&result->data.price);
                book_save(FileName,list);
                printf("书籍信息修改完成!\n");
                sleep(1);
                main_menu();
                break;
            default:printf("输入有误!请重新输入:\n");sleep(1);main_menu();
        }
    }
}
//5.图书删除
void book_remove()
{
    printf("请输入要删除书籍的名字:\n");
    scanf("%s",tempBook.name);
    DeleteNodeByName(list,tempBook.name);
    book_save(FileName,list);
    back_ask();
}
//6.图书排序(冒泡排序)
void book_sort(struct Node *HeadNode)
{
    for ( struct Node *p = HeadNode->next; p != NULL; p = p->next)
    {
        for ( struct Node *q = HeadNode->next;q->next != NULL;q = q->next)
        {
            if (q->data.price > q->next->data.price) //价格排序
            {
                struct Books tempData = q->data;
                q->data = q->next->data;
                q->next->data = tempData;
            }
            
        }
    }
    PrintList(HeadNode);
    back_ask();
}
//7.图书借阅
void book_borrow() //书籍存在:书籍数量-n 书籍不存在:借阅失败
{
    int num = 0;
    printf("请输入您要借阅的书籍名:\n");
    scanf("%s",tempBook.name);
    result = SearchByName(list,tempBook.name);
    if (result == NULL)
    {
        printf("%s不存在!无法借阅!\n",tempBook.name);
        main_menu();
        return;
    }
    else
    {
        if (result->data.amount > 0)
        {
            printf("请输入您要借阅的书籍数量:\n");
            scanf("%d",&num);
            if (num > result->data.amount) //借阅的数量大于原有书籍数量
            {
               printf("借阅的书籍数量(%d本)应该小于总数量(%d)\n",num,result->data.amount);
               sleep(5);
               main_menu();
            }
            else if (num < 0)
            {
                printf("不合法的数量输入!\n");
                sleep(1);
                main_menu();
            }
            result->data.amount -= num;
            book_save(FileName,list);
            printf("借阅成功!\n");
            back_ask();
        }
        else
        {
            printf("%s无库存,借阅失败!\n",tempBook.name);
            sleep(1);
            main_menu();
        }
    }
     return;
}
//8.图书归还
void book_back()
{
    int num = 0;
    printf("请输入归还的书籍名:\n");
    scanf("%s",tempBook.name);
    result = SearchByName(list,tempBook.name);
    if (result == NULL)
    {
        printf("%s来源非法!无法归还!\n",tempBook.name);
        return;
    }
    else
    {
        printf("请输入您要归还的书籍数量:\n");
        scanf("%d",&num);
        result->data.amount += num;
        book_save(FileName,list);
        printf("归还成功!\n");
        back_ask();
    }
}
//9.图书信息保存
void book_save(const char *fileName,struct Node *HeadNode) //将书籍信息存到txt文件中
{
    FILE *fp = fopen(fileName,"w");
    struct Node* pMove = HeadNode->next;
    while (pMove != NULL)
    {
        fprintf(fp,"%d\t%s\t%s\t%s\t%d\t%.2f\n",pMove->data.id,pMove->data.name,pMove->data.publisher,pMove->data.Date,
        pMove->data.amount,pMove->data.price);
        pMove = pMove->next;
    }
    fclose(fp);
    back_ask();
}
//10.图书信息读取
void book_load(const char *fileName,struct Node *HeadNode)
{
    FILE *fp = fopen(fileName,"r");
    if (fp == NULL)
    {
        fp = fopen(fileName,"w+");
    }
    struct Books tempData;
    while (fscanf(fp,"%d\t%s\t%s\t%s\t%d\t%f\n",&tempData.id,tempData.name,tempData.publisher,
    tempData.Date,&tempData.amount,&tempData.price) != EOF)
    {
        InsertNodeByHead(list,tempData);
    }
    fclose(fp);
    //back_ask();
    printf("读取成功!\n");
    sleep(1);
    main_menu();
}
int main(int argc, char* argv[])
{
    list = CreateHead();
    init();
    main_menu();
    return 0;
}
