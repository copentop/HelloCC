# 	include <stdio.h>


int foo(void)
{
	int i;
	printf("%d\n", i);
	i = 777;
}

int main(int argc, char *argv[])
{
	foo();
	foo();
	return 0;
}
