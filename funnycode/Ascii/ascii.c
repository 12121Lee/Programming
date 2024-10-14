#include <stdio.h>
#define RANGE 127

int main(void)
{
    int i;
    printf("十进制\tAscii\n");
    for ( i = 0; i <= RANGE; i++)
        printf("%2d----------%c\n", i, i);
    return 0;
}
  