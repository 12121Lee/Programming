/*10、任意输入一个日期（但只是有年和月，例如：2018-8），要求编程输出该年该月的日历*/

// 基姆拉尔森计算公式:W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7
// 在公式中d表示日期中的日数，m表示月份数，y表示年数。w表示星期，w的取值范围是0~6，0代表星期日，1~6星期一到星期六
// 注意:把一月和二月看成是上一年的十三月和十四月
#include<stdio.h>

int getWeek(int y, int m, int d);
void printCalendar(int y, int m);
int getDays(int y, int m);
int Leap_Common(int y);

int main(int argc, char const *argv[])
{
    int y, m;
    printf("输入你想查询的日期(eg.2002-03): ");
    scanf("%d-%d", &y, &m);
    printCalendar(y, m);
    return 0;
}
int getWeek(int y, int m, int d)
{
    int w;
    if(m == 1)
    {
        m = 13;
        y -= 1;
    }
    if(m == 2)
    {
        m = 14;
        y -= 1;
    }
    w = (d + 2 * m + (3 * (m + 1)) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
    return w;
}

void printCalendar(int y, int m)
{
    int w, days, i;
    w = getWeek(y, m, 1);  // 获取当月1日是星期几
    days = getDays(y, m);   // 获取当月的天数
    
    printf("\n      %d年%d月\n\n", y, m);  // 这里多加一个\n增加标题间距
    printf("日 一 二 三 四 五 六\n\n");  // 这里多加一个\n增加星期行间距
    
    // 打印前面的空格
    for(i = 0; i < w; i++) 
    {
        printf("   ");
    }
    
    // 打印日期
    for(i = 1; i <= days; i++) 
    {
        printf("%2d ", i);
        if((i + w) % 7 == 0 || i == days) 
        {
            printf("\n\n");  // 这里用两个\n增加行间距
        }
    }
}

int getDays(int y, int m)
{
    int days;
    switch(m)
    {
        case  1: days = 31; break;
        case  2: days = Leap_Common(y); break;
        case  3: days = 31;break;
        case  4: days = 30;break;
        case  5: days = 31;break;
        case  6: days = 30;break;
        case  7: days = 31;break;
        case  8: days = 31;break;
        case  9: days = 30;break;
        case 10: days = 31;break;
        case 11: days = 30;break;
        case 12: days = 31;break;
    }
    return days;
}

int Leap_Common(int y)
{
    if((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0 ))
        return 29;
    else
        return 28;
}