// 简易计算器
#include <stdio.h>

int main(int argc, char const *argv[])
{
	float a = 0,b = 0;
	char cal;
	printf("Enter the calculation:\n");
	scanf("%f%c%f",&a,&cal,&b);
	switch(cal) {
		case '+':printf("=%f\n", a+b);break;
		case '-':printf("=%f\n", a-b);break;
		case '*':printf("=%f\n", a*b);break;
		case '/':printf("=%f\n", a/b);break;
		case '%':printf("=%d\n", (int)a%(int)b);break;
		default :printf("Invalid input!\n");break;
	}
	return 0;
}