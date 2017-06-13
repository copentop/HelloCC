# include <stdio.h>

void increment(int x)
{
	x = x + 1;
}

int main(int vargc , char argv[])
{
	int i = 1, j = 2;
	increment(i); /* now i becomes 2 */
	increment(j); /* now j becomes 3 */

	printf("i: %d, j: %d \n", i, j);
	return 0;
}
