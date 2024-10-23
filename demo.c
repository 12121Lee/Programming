#include<stdio.h>
#include<stdlib.h>

#define FILENAME "demo.txt"
#define SIZE 100

void WriteToFile(char *buf, int size)
{
    FILE *fp = fopen(FILENAME, "w");
    if(fp == NULL)
    {
       perror("fopen error");
       exit(EXIT_FAILURE);
    }
    if(fwrite(buf, sizeof(char), size, fp) != size)
    {
        fprintf(stderr, "fwrite error");
        exit(EXIT_FAILURE);
    }
    fclose(fp);
}

void ReadFromFile(char *newbuf, int newsize)
{
    FILE* fp = fopen(FILENAME, "r");
    int ret = 0;
    if(fp == NULL)
    {
        perror("fopen error");
        exit(EXIT_FAILURE);
    }
    if((ret = fread(newbuf, sizeof(char), newsize, fp))!= newsize)
    {
        fprintf(stderr, "fread error");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", newbuf);
    // printf("ret = %d\n", ret);
    fclose(fp);
}

int main(int argc, char const *argv[])
{
    char buf[SIZE] = {0};
    char newbuf[SIZE] = {0};
    printf("input something:");
    fgets(buf, SIZE, stdin);
    WriteToFile(buf, SIZE);
    ReadFromFile(newbuf, SIZE);
    return 0;
}