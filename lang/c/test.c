#include <stdio.h>

int aa = 10;

void swap(int m , int n)
{
	int tmp;
	tmp = m;
	m = n;
	n = tmp;
	printf("m = %d, n = %d\n", m, n);
}

void swap2(int *m , int *n)
{
	int tmp;
	tmp = *m;
	*m = *n;
	*n = tmp;
}

void newl(void)
{
	int a = 10;
	printf("a=%d, &a=%p", a, &a);
}

int main(void)
{
	int a = 10, b = 2;
	swap(a,b);
	printf("m = %d, n = %d\n", a, b);
	swap2(&a,&b);
	printf("m = %d, n = %d\n", a, b);
	//system("neofetch");
	//newl();
	return 0;
}