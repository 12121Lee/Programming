// 除法带商
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int b = 0, c = 0, s = 0, y = 0; // b:被除数 c: 除数 s:商 y:余数
	printf("请输入除法算式:\n");
	scanf("%d/%d",&b,&c);
	if (c == 0) {
		printf("divisor can't be zero\n");
		exit(1);
	}
	if (b%c == 0) {
		s = b/c;
		y = 0;
		printf("%d/%d=%d\n", b, c, s);
	}
	else {
		s = b/c;
		y = b%c;
		printf("%d/%d=%d...%d\n", b, c, s, y);
	}
	return 0;
}