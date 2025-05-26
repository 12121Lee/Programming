/*9、任意输入2个日期（各自包含年月日），计算这2个日期之间一共有多少天？*/

#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool Leap_Common(int yy);
int Days(int yy, int mm, int dd);
int Diff_Days(int yy1, int mm1, int dd1, int yy2, int mm2, int dd2);

int main(int argc, char const *argv[])
{
    int yy1, mm1, dd1;
    int yy2, mm2, dd2;
    int days;

    printf("请输入第一个日期(eg:xxxx-xx-xx): ");
    scanf("%d-%d-%d", &yy1, &mm1, &dd1);
    printf("请输入第二个日期(eg:xxxx-xx-xx): ");
    scanf("%d-%d-%d", &yy2, &mm2, &dd2);
    
    if(yy1 == yy2)
        days = abs(Days(yy1,mm1, dd1) - Days(yy2, mm2, dd2));
    else
        days = Diff_Days(yy1, mm1, dd1, yy2, mm2, dd2);
    printf("%d-%d-%d到%d-%d-%d之间相差%d天\n",yy1, mm1, dd1, yy2, mm2, dd2, days);
    return 0;
}

bool Leap_Common(int yy)
{
    if((yy % 400 == 0) || (yy % 4 == 0 && yy % 100 != 0 ))
        return true;
    else
        return false;
}

// 同一年
int Days(int yy, int mm, int dd)
{
    int Feb;
    int which_day;

    if(Leap_Common(yy))
        Feb = 29;
    else
        Feb = 28;


    switch (mm)
    {
    case 1: // 31
        which_day = dd;
        break;
    case 2: // 28或者29
        which_day = 31 + dd;
        break;
    case 3: // 31
        which_day = 31 + dd + Feb;
        break;
    case 4: // 30
        which_day =  31 + dd + Feb + 31;
        break;
    case 5: // 31
        which_day =  31 + dd + Feb + 31 + 30;
        break;
    case 6: // 30
        which_day =  31 + dd + Feb + 31 + 30 + 31;
        break;
    case 7: // 31
        which_day =  31 + dd + Feb + 31 + 30 + 31 + 30;
        break;
    case 8: // 31
        which_day = 31 + dd + Feb + 31 + 30 + 31 + 30 + 31;
        break;
    case 9: // 30
        which_day = 31 + dd + Feb + 31 + 30 + 31 + 30 + 31 + 31;
        break;
    case 10: // 31
        which_day = 31 + dd + Feb + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        break;
    case 11: // 30
        which_day = 31 + dd + Feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        break;
    case 12: // 31
        which_day = 31 + dd + Feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        break;
    default:
        break;
    }
    return which_day;
}

int Diff_Days(int yy1, int mm1, int dd1, int yy2, int mm2, int dd2)
{
    int all_days = 0;
    int year;
    for(int i = yy1 + 1; i < yy2; i++)
    {
        if(Leap_Common(i))
            all_days += 366;
        else
            all_days += 365;
    }

    if(Leap_Common(yy1))
        year = 366;
    else
        year = 365;
    
    all_days = all_days + (year - Days(yy1, mm1, dd1)) + Days(yy2, mm2, dd2);
    return all_days;
}