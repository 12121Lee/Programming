/*8、任意输入一个年月日，计算并输出这天是该年的第几天？*/

#include <stdio.h>
#include <stdbool.h>

bool Leap_Common(int yy);

int main(int argc, char const *argv[])
{
    int year, month, day;
    int which_day = 0;
    int Feb;
    printf("请输入一个年月日(eg:xxxx-xx-xx): ");
    scanf("%d-%d-%d", &year, &month, &day);

    if(Leap_Common(year))
        Feb = 29;
    else
        Feb = 28;


    switch (month)
    {
    case 1: // 31
        which_day = day;
        break;
    case 2: // 28或者29
        which_day = 31 + day;
        break;
    case 3: // 31
        which_day = 31 + day + Feb;
        break;
    case 4: // 30
        which_day =  31 + day + Feb + 31;
        break;
    case 5: // 31
        which_day =  31 + day + Feb + 31 + 30;
        break;
    case 6: // 30
        which_day =  31 + day + Feb + 31 + 30 + 31;
        break;
    case 7: // 31
        which_day =  31 + day + Feb + 31 + 30 + 31 + 30;
        break;
    case 8: // 31
        which_day = 31 + day + Feb + 31 + 30 + 31 + 30 + 31;
        break;
    case 9: // 30
        which_day = 31 + day + Feb + 31 + 30 + 31 + 30 + 31 + 31;
        break;
    case 10: // 31
        which_day = 31 + day + Feb + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        break;
    case 11: // 30
        which_day = 31 + day + Feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        break;
    case 12: // 31
        which_day = 31 + day + Feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        break;
    default:
        break;
    }
    printf("%d-%d-%d是%d年的第%d天\n",year, month, day, year, which_day);
    return 0;
}

bool Leap_Common(int yy)
{
    if((yy % 400 == 0) || (yy % 4 == 0 && yy % 100 != 0 ))
        return true;
    else
        return false;
}