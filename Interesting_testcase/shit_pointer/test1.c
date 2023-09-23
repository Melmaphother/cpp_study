#include <stdio.h>

int main() {
	int	 i = 0, q = 0;
	int *p = &i;
	//printf("%p %d\n", p, *p);
	q = *p++;
	//printf("%d\n", q);
    //printf("%d %d\n", p, *p);
}