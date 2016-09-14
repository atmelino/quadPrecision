#include <quadmath.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	__float128 r;
	char* message = "quadmath test 01";
	printf("%s\n", message);
	r = strtoflt128("1.2345678", NULL);

	return 0;
}
