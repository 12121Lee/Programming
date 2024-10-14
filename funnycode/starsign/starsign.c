// 查询星座和生肖(22/10/28)
#include <stdio.h>
#include <stdlib.h>

static void show_xz(int month,int day); // 星座
static void show_sx(int year); // 生肖

int main(int argc, char const *argv[])
{
	system("clear");
	int year = 0,month = 0,day = 0;
	printf("输入您的出生日期:(eg.xxx-xxx-xxx)(按任意字母退出)\n");
	while (scanf("%d-%d-%d",&year,&month,&day) == 3)
	{
		if (year > 0 && (month >= 1 && month <= 12) && (day >=0 && day <= 31))
		{
			printf("星座:");
			show_xz(month,day);
			printf("生肖:");
			show_sx(year);
			printf("输入您的出生日期:(eg.xxx-xxx-xxx)(按任意字母退出)\n");
		}
		else
			printf("输入的年月日有误, 请重新输入!\n");
	}
	puts("Bye.");
	return 0;
}
static void show_xz(int month, int day) // 星座
{
   if ((month == 3 && day >= 21) || (month == 4 && day <= 19)){
   	    printf("白羊座\n");
   }
   else if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) {
   	    printf("金牛座\n");
   }
   else if ((month == 5 && day >= 21) || (month == 6 && day <= 21)) {
   	    printf("双子座\n");
   }
   else if ((month == 6 && day >= 22) || (month == 7 && day <= 22)) {
   	    printf("巨蟹座\n");
   }
   else if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) {
   	    printf("狮子座\n");
   }
   else if ((month == 8 && day >= 23)|| (month == 9 && day <= 22)) {
   	    printf("处女座\n");
   }
   else if ((month == 9 && day >= 23) || (month == 10 && day <= 23)) {
   	    printf("天秤座\n");
   }
   else if ((month == 10 && day >= 24) || (month == 11 && day <= 22)) {
   	    printf("天蝎座\n");
   }
   else if ((month == 11 && day >= 23) || (month == 12 && day <= 21)) {
   	    printf("射手座\n");
   }
   else if ((month == 12 && day >= 22) || (month == 1 && day <= 19)) {
   	    printf("摩羯座\n");
   }
   else if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) {
   	    printf("水瓶座\n");
   }
   else if ((month == 2 && day >= 19) || (month == 3 && day <= 20)) {
   	    printf("双鱼座\n");
   }
   else
   	printf("没有相关信息, 请检查您的输入是否有误!\n");
}
static void show_sx(int year) // 生肖
{
	switch(year%12) {
		case 4: printf("属鼠\n");break;
		case 5: printf("属牛\n");break;
		case 6: printf("属虎\n");break;
		case 7: printf("属兔\n");break;
		case 8: printf("属龙\n");break;
		case 9: printf("属蛇\n");break;
		case 10:printf("属马\n");break;
		case 11:printf("属羊\n");break;
		case 0: printf("属猴\n");break;
		case 1: printf("属鸡\n");break;
		case 2: printf("属狗\n");break;
		case 3: printf("属猪\n");break;
		default:printf("没有相关信息, 请检查您的输入是否有误!\n");
	}
}