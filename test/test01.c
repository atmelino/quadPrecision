//#include <quadmath.h>
#include <stdlib.h>
#include <stdio.h>
#include "quadmath.h"

int test01() {
	__float128 r;
	char* message = "quadmath test 01";
	printf("%s\n", message);
	r = strtoflt128("1.2345678", NULL);

	return 0;
}
