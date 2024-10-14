// 动态时钟
#include <stdio.h>
#include <time.h>

void cur_time(void){
    char *wday[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    time_t timep;
    struct tm *p;
    time(&timep);
    p=gmtime(&timep); /* 获取当前时间 */
    printf("%d/%02d/%02d ",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
    printf("%s %02d:%02d:%02d\n",wday[p->tm_wday],p->tm_hour+8,p->tm_min,p->tm_sec);
}
int main(int argc, char const *argv[])
{
	cur_time();
	return 0;
}