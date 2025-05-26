#include <stdio.h>

int main(void) 
{
	/*17位身份证号*/
	// int a[] = {5,1,3,7,2,1,2,0,0,2,0,2,1,5,2,2,6};
	int a[17] = {0};
	printf("请输入17位身份证号前17位数字(连续输入，无需分隔）：\n");
    for(int i = 0; i < 17; i++)
    {
        // 使用格式控制，直接读取连续的数字字符并转换为整数
        char c;
        scanf(" %c", &c);  // 注意%c前面的空格，用于跳过空白字符
        a[i] = c - '0';   // 将字符转换为对应的数字
    }
	/*固定的校验码 */
	const int check[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int len = sizeof(a)/sizeof(a[0]);
	int sum = 0;
	char checkcode;
	for(int i = 0; i < len; i++)
	{
		/*系数相乘求和*/
		sum+=a[i]*check[i];
	}
	// printf("sum = %d\n",sum);
	// printf("the left number = %d\n",sum%11);
	switch (sum % 11) /*余数对应最后一位身份证号*/
	{
		case 0:   checkcode  = '1';break;
		case 1:   checkcode  = '0';break;
		case 2:   checkcode  = 'x';break;
		case 3:   checkcode  = '9';break;
		case 4:   checkcode  = '8';break;
		case 5:   checkcode  = '7';break;
		case 6:   checkcode  = '6';break;
		case 7:   checkcode  = '5';break;
		case 8:   checkcode  = '4';break;
		case 9:   checkcode  = '3';break;
		case 10:  checkcode  = '2';break;
	}
	// printf("the last checkcode is %c\n",checkcode);
	printf("the ID number is:\n");
	for(int i = 0; i < len; i++)
	{
		printf("%d", a[i]);
	}
	printf("%c\n",checkcode);
	return 0;
}
