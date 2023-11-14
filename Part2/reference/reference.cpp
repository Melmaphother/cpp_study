#include <iostream>
int main() {
	int **a;
	int *&b = *a;
	int &*c;
	int &&d = 1;
	return 0;
    const int e = 0;
    const int* const f = &e;
}