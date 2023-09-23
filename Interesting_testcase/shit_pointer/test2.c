#include <stdio.h>

int main() {
	int	 i = 0, q;
	int *p = &i;
	//printf("%p %d\n", p, *p);
	q = *p++;
	//printf("%d\n", q);
	//printf("%p %d\n", p, *p);
}