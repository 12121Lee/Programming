#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define  FILENAME "student.txt"

struct student
{
    int num;            /*学号*/
    char name[15];      /*姓名*/
    double elective;    /*选修课*/
    double experiment;  /*实验课*/
    double required;    /*必修课*/
    double sum;         /*总分*/
};

struct student stu[50];

void menu();
void addStudent();
void searchStudent();
void removeStudent();
void modStudent();
void insertStudent();
void Sort();
void Sum();
void displayAll();
void Exit();

void Swap(struct student *stu1, struct  student *stu2);


int main(void)
{
    int choice;
    menu();
    scanf("%d",&choice);
    while(choice)
    {
        switch (choice)
        {
            case 1:addStudent();break;
            case 2:searchStudent();break;
            case 3:removeStudent();break;
            case 4:modStudent();break;
            case 5:insertStudent();break;
            case 6:Sort();break;
            case 7:Sum();break;
            case 8:displayAll();break;
            case 0:Exit();break;
            default:
                puts("错误输入!");
                break;
        }
        menu();
        scanf("%d",&choice);
    }
    Exit();
    return 0;
}

void menu()
{
    // system("clear");
    puts("|--------学生信息管理系统-------|");
    puts("|\t\t\t\t|");
    puts("|\t1.录入学生信息\t\t|");
    puts("|\t2.查找学生信息\t\t|");
    puts("|\t3.删除学生信息\t\t|");
    puts("|\t4.修改学生信息\t\t|");
    puts("|\t5.插入学生信息\t\t|");
    puts("|\t6.排序\t\t\t|");
    puts("|\t7.统计学生总数\t\t|");
    puts("|\t8.显示所有学生信息\t|");
    puts("|\t0.退出系统\t\t|");
    puts("|\t\t\t\t|");
    puts("|-------------------------------|");
    printf("请选择<0-8>:");
}

void addStudent()
{
    int i = 0;
    char ch[2];
    FILE* fp = fopen(FILENAME, "wb");
    printf("输入学生信息<y/n>: ");
    scanf("%s", ch);
    while(strcmp(ch, "y") == 0)
    {
        printf("学号:");
        scanf("%d", &stu[i].num);
        printf("姓名:");
        scanf("%s",stu[i].name);
        printf("选修课分数:");
        scanf("%lf",&stu[i].elective);
        printf("实验课分数:");
        scanf("%lf",&stu[i].experiment);
        printf("必修课分数:");
        scanf("%lf",&stu[i].required);
        stu[i].sum = stu[i].elective + stu[i].experiment + stu[i].required;
        if(fp == NULL)
        {
            fprintf(stderr, "%s", strerror(errno));
            exit(1);
        }
        if(fwrite(&stu[i], sizeof(struct student), 1, fp) == 1)
        {
            printf("%s被保存!", stu[i].name);
            i++;
        }
        printf("继续?<y/n>: ");
        scanf("%s", ch);
    }
    fclose(fp);
}

void searchStudent()
{
    int m = 0;
    int i;
    int num;
    FILE* fp = fopen(FILENAME, "rb");
    if(fp == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        exit(1);
    }
    while(!feof(fp))
    {
        if(fread(&stu[m], sizeof(struct student), 1, fp) == 1)
            m++;
    }
    fclose(fp);
    if(m == 0)
    {
        printf("文件中没有记录！\n");
        return;
    }
    printf("请输入查找的学号: ");
    scanf("%d", &num);
    for ( i = 0; i < m; i++)
    {
        if(stu[i].num == num)
        {
            printf("学号\t姓名\t选修课\t实验课\t必修课\t总分\n");
            printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", stu[i].num, stu[i].name,stu[i].elective, stu[i].experiment,stu[i].required,\
                stu[i].sum);
            break;
        }
    }
    if (i == m)
        printf("没有找到编号为%d的学生\n", num);
}

void removeStudent() // 学号为0会出错
{
    int m = 0,i, num;
    int j;
    char ch[2];
    FILE* fp = fopen(FILENAME, "r+");
    if(fp == NULL)
    {
        fprintf(stderr, "文件不存在!\n");
        return;
    }
    while(!feof(fp))
    {
        if(fread(&stu[m], sizeof(struct student), 1, fp) == 1)
            m++;
    }
    fclose(fp);
    if(m == 0)
    {
        fprintf(stderr,"文件中没有记录!\n");
        return;
    }

    printf("请输入学号: ");
    scanf("%d", &num);
    for ( i = 0; i < m; i++)
    {
        if(stu[i].num == num)
        {
            printf("找到了这条记录，是否删除?<y/n>");
            scanf("%s", ch);
            if (strcmp(ch,"y") == 0)
            {
                for(j = i;j < m;j++)
                {
                    stu[j] = stu[j + 1];
                }
                m--;
                if((fp = fopen(FILENAME, "wb")) == NULL)
                {
                    printf("文件不存在!\n");
                    return;
                }
                for(j = 0; j < m; j++)
                {
                    if((fwrite(&stu[j], sizeof(struct student), 1, fp)) != 1)
                    {
                        printf("文件无法保存");
                        return;
                    }
                }
                fclose(fp);
                printf("删除成功!\n");
            }
            else
            {
                printf("找到了记录，选择不删除!\n");
            }
            break;
        }
        else
        {
            printf("没有找到这名学生!\n");
        }
    }
}

void modStudent()
{

    int m = 0, i, j;
    int num;
    FILE *fp = fopen(FILENAME, "r+");
    if(fp == NULL)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }
    while(!feof(fp))
    {
        if(fread(&stu[m], sizeof(struct student), 1, fp) == 1)
            m++;
    }
    if(m == 0)
    {
        printf("文件为空!\n");
        fclose(fp);
        return;
    }
    displayAll();
    printf("请输入你要修改的学号: ");
    scanf("%d",&num);
    for(i = 0; i < m; i++)
    {
        if(stu[i].num == num)
        {
            printf("学生已被找到, 修改你的信息:\n");
            printf("姓名: ");
            scanf("%s", stu[i].name);
            printf("选修课: ");
            scanf("%lf", &stu[i].elective);
            printf("实验课: ");
            scanf("%lf", &stu[i].experiment);
            printf("必修课: ");
            scanf("%lf", &stu[i].required);
            printf("修改成功!\n");
            stu[i].sum = stu[i].elective + stu[i].experiment + stu[i].required;
            if((fp = fopen(FILENAME, "wb")) == NULL)
            {
                printf("不能打开文件!\n");
                return;
            }
            for (j = 0; j < m; j++)
            {
                if(fwrite(&stu[j], sizeof(struct student), 1, fp) != 1)
                    printf("不能保存!\n");
            }
            fclose(fp);
            break;
        }
    }
    if (i == m)
        printf("没有找到这名学生!\n");
}

void insertStudent()
{
    int snum, m = 0, i, j, k;
    FILE *fp;
    if((fp = fopen(FILENAME, "r+")) == NULL)
    {
        printf("文本不存在!\n");
        return;
    }
    while(!feof(fp))
    {
        if (fread(&stu[m], sizeof(struct student), 1, fp) == 1)
            m++;
    }
    if(m == 0)
    {
        printf("文件为空!\n");
        fclose(fp);
        return;
    }
//    displayAll();
    printf("请输入要插入的位置<学号>:\n");
    scanf("%d", &snum);
    for(i = 0; i < m; i++)
    {
        if (stu[i].num == snum)
            break;
        else //原来的代码没有这个判断,会导致如果插入的学号找不到会在结尾加具体数量的0
        {
            printf("没有匹配的学号!\n");
            return;
        }
    }
    for(j = m - 1; j > i; j--)
        stu[j+1] = stu[j];
    printf("现在请输入要插入的学生信息.\n");
    printf("学号: ");
    scanf("%d", &stu[i+1].num);
    for(k = 0;k < m; k++)
    {
        if (stu[k].num == stu[m].num)
        {
            printf("学号已经存在");
            fclose(fp);
            return;
        }
    }
    printf("姓名: ");
    scanf("%s", stu[i+1].name);
    printf("选修课: ");
    scanf("%lf", &stu[i+1].elective);
    printf("实验课: ");
    scanf("%lf", &stu[i+1].experiment);
    printf("必修课: ");
    scanf("%lf", &stu[i+1].required);
    stu[i+1].sum = stu[i+1].elective + stu[i+1].experiment + stu[i+1].required;
    printf("插入成功!\n");
    if((fp = fopen(FILENAME, "wb")) == NULL)
    {
        printf("不能打开!\n");
        return;
    }
    for(k = 0;k <= m; k++)
    {
        if(fwrite(&stu[k], sizeof(struct student), 1, fp) != 1)
            printf("不能保存!");
    }
    fclose(fp);
}

void Sort() {
    FILE *fp;
    int m = 0, i, j;
    if ((fp = fopen(FILENAME, "r+")) == NULL) {
        printf("文件不存在!\n");
        return;
    }
    while (!feof(fp)) {
        if (fread(&stu[m], sizeof(struct student), 1, fp) == 1)
            m++;
    }
    fclose(fp);
    if (m == 0)
    {
        printf("文件为空!\n");
        return;
    }
    if ((fp = fopen(FILENAME, "wb")) == NULL)
    {
        printf("文件不存在!\n");
        return;
    }
    for (i = 0; i < m ; i++)
    {
        for (j = i; j < m; j++)
        {
            if (stu[i].sum < stu[j].sum)
                Swap(&stu[i], &stu[j]);
        }
    }
    for(i = 0; i < m; i++)
    {
        if(fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
        {
            printf("不能保存文件!\n");
        }
    }
    fclose(fp);
    printf("保存成功\n");
}
void Sum()
{
    FILE *fp;
    int m = 0;
    if((fp = fopen(FILENAME, "rb")) == NULL)
    {
        printf("文件打开失败!\n");
        return;
    }
    while(!feof(fp))
    {
        if(fread(&stu[m], sizeof(struct student), 1, fp) == 1)
            m++;
    }
    if(m == 0)
    {
        printf("文件为空!\n");
        return;
    }
    fclose(fp);
    printf("全班一共有%d名学生\n", m);
}

void displayAll()
{
    int m = 0, n; //m:项数
    FILE* fp = fopen("student.txt", "rb");
    if(fp == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        exit(1);
    }
    while(!feof(fp))
    {
        if(fread(&stu[m], sizeof(struct student), 1, fp) == 1)
            m++;
    }
    if(m == 0)
    {
        fprintf(stderr,"文件为空!\n");
        return;
    }
    fclose(fp);
    printf("学号\t姓名\t选修课\t实验课\t必修课\t总分\n");
    for(n = 0;n < m;n++)
        printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", stu[n].num, stu[n].name,stu[n].elective, stu[n].experiment,stu[n].required,\
        stu[n].sum);
}

void Exit()
{
    puts("Bye!");
}

void Swap(struct student *stu1, struct  student *stu2)
{
    struct student temp;
    temp = *stu1;
    *stu1 = *stu2;
    *stu2 = temp;
}