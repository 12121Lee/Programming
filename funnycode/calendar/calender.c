// 日历
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


void cal();
// it seems that I can't finish it
int main(int argc, char const *argv[])
{
	cal();
	return 0;
}
void cal()
{
	char buffer[1024];
	memset(buffer,0,1024);
    time_t timep;
    struct tm *p;
    time(&timep);
    p=localtime(&timep); /* 获取当前时间 */
    if (NULL == p) {
        printf("[%d]:%s\n",__LINE__,strerror(errno));
        exit(1);
    }
    switch(1+p->tm_mon) {
    	case 1:  strcpy(buffer,"一月");break;
    	case 2:  strcpy(buffer,"二月");break;
    	case 3:  strcpy(buffer,"三月");break;
    	case 4:  strcpy(buffer,"四月");break;
    	case 5:  strcpy(buffer,"五月");break;
    	case 6:  strcpy(buffer,"六月");break;
    	case 7:  strcpy(buffer,"七月");break;
    	case 8:  strcpy(buffer,"八月");break;
    	case 9:  strcpy(buffer,"九月");break;
    	case 10: strcpy(buffer,"十月");break;
    	case 11: strcpy(buffer,"十一月");break;
    	case 12: strcpy(buffer,"十二月");break;
    	default:printf("error!\n");
    }
    printf("      %s %d\n", buffer,1900+p->tm_year);
    printf("日 一 二 三 四 五 六\n");
}