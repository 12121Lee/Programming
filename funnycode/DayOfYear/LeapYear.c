/*2、任意输入一个年份，判断其实闰年还是平年？*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int year;
    printf("请输入一个年份:");
    scanf("%d", &year);
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0 ))
        printf("%d是闰年.\n", year);
    else
        printf("%d是平年.\n", year);
    return 0;
}
