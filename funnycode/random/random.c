// 随机数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		printf("Usage: %s count\n", argv[0]);
		exit(1);
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < atoi(argv[1]); ++i) {
		printf("%d ", rand()%100);
	}
	printf("\n");
	return 0;
}
