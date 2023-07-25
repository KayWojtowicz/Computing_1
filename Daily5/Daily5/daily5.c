#include <stdio.h>

int smile(void);

int main(int argc, char* argv[])
{
	smile();
	printf("\n");
	smile();
	printf("\n");
	smile();
	printf("\n");
	return 0;
}

int smile(void)
{
	printf("  ****\n");
	printf(" * . .*\n");
	printf("*      *\n");
	printf("*  \\_/ *\n");
	printf(" *    *\n");
	printf("  ****\n");
	return;
}