#include <stdio.h>
#include <time.h>

void type1();
void type2();
void type3();

int main(void)
{
    type1();
    type2();
    type3();
    return 0;
}

void type1()
{
    time_t t;
    struct tm *tlocal;
    time(&t);
    tlocal = localtime(&t);
    printf("%d-%d-%d %d:%d:%d\n", tlocal->tm_year + 1900,tlocal->tm_mon + 1, tlocal->tm_mday, tlocal->tm_hour,
    tlocal->tm_min, tlocal->tm_sec);
}

void type2()
{
    time_t t;
    struct tm *tlocal;
    char buf[80];
    time(&t);
    tlocal = localtime(&t);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S",tlocal);
    printf("%s\n", buf);
}

void type3()
{
    time_t t;
    time(&t);
    printf("%s", asctime(localtime(&t)));
    printf("%s", ctime(&t));
}