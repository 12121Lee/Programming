#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#define PATH "demo.txt"

int WriteToFile(char* str)
{
	int fd = open(PATH, O_WRONLY | O_CREAT);
	int size = 0;
	if (fd == -1)
	{
		perror("Error opening file");
		return -1;
	}
	if ((size = write(fd, str, strlen(str))) == -1)
	{
		perror("Error writing to file");
		return -1;
	}
	close(fd);
	return 0;
}

int ReadFromFile(char* buffer, int read_size)
{
	int fd = open(PATH, O_RDONLY);
	int size = 0;
	if (fd == -1)
	{
		perror("Error opening file");
		return -1;
	}
	if ((size = read(fd, buffer, read_size)) == -1)
	{
		perror("Error reading from file");
		return -1;
	}
	close(fd);
	printf("File contents: %s", buffer);
	return 0;
}
int main()
{
	char str[20];
	printf("Enter the string to write to file: ");
	fgets(str, 20, stdin);

	WriteToFile(str);
	ReadFromFile(str, strlen(str));
	return 0;
}