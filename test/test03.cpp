//#include <quadmath.h>

extern "C" {
#include "quadmath.h"
}

#include <iostream>
int test03() {
	char* y = new char[1000];
	quadmath_snprintf(y, 1000, "%Qf", 1.0q);
	std::cout << y << std::endl;
	return 0;
}
