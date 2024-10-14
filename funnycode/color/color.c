// 颜色显示
#include <stdio.h>

// general format control
#define RESET     "\033[0m"
#define HIGHLIGHT "\033[1m"
#define LOWLIGHT  "\033[2m"
#define UNDERLINE "\033[4m"
#define FLASH     "\033[5m"
#define REVERSE   "\033[7m"
#define HIDDEN    "\033[8m"
// forebackground
#define FBLACK    "\033[2;30m"
#define FRED      "\033[2;31m"
#define FGREEN    "\033[2;32m"
#define FYELLOW   "\033[2;33m"
#define FBLUE     "\033[2;34m"
#define FPINK     "\033[2;35m"
#define FCYAN     "\033[2;36m"
// background
#define BLACK     "\033[2;40m"
#define RED       "\033[2;41m"
#define GREEN     "\033[2;42m"
#define YELLOW    "\033[2;43m"
#define BLUE      "\033[2;44m"
#define PINK      "\033[2;45m"
#define CYAN      "\033[2;46m"

int main(int argc, char const *argv[])
{
	printf(HIGHLIGHT"Hello World\n"RESET);
	printf(FBLACK"Hello World\n"RESET);
	printf(PINK"Hello World\n"RESET);
	printf(LOWLIGHT"Hello World\n"RESET);
	printf(GREEN"Hello World\n"RESET);
	return 0;
}
