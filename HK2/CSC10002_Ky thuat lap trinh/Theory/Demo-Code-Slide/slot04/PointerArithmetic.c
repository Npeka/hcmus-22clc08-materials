#include <stdio.h>

int main(){
	int n;
	int* p = &n;
	printf("%d\n", p);
	printf("%d", p + 1);

	return 0;
}


