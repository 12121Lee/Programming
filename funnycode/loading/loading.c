// 加载动画
#include "../head.h"
#define RESET     "\033[0m"
#define FYELLOW   "\033[2;33m"
int main(int argc, char const *argv[])
{
	char dot[100];
	memset(dot,0,sizeof(dot));
	if (argc != 2) {
		printf("Usage: %s count\n", argv[0]);
		exit(1);
	}
	if (atoi(argv[1]) < 0 || atoi(argv[1]) > 100) {
		printf("Usage: %s count(0<=count<=100)\n", argv[0]);
		exit(1);
	}
	printf(FYELLOW"Progress: [ %d%%] "RESET,atoi(argv[1]));
	printf("[");
	for (int j = 100-1; j >= 0; --j) {
		dot[j] = '.';
	    for (int i = 100-atoi(argv[1]); i < 100; ++i) {
		dot[i] = '#';
	    }
	    printf("%c", dot[j]);
    }
    printf("]");
	printf("\n");
	return 0;
}