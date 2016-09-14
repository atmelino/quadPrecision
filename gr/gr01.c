#include <quadmath.h>
#include <stdlib.h>
#include <stdio.h>

int gr01() {
	__float128 c, c2, c2inv;
	int prec = 20;
	int width = 46;
	char buf[128];
	int n;
	double cd, cd2, cd2inv;

	cd = 300000000.;
	cd2 = cd * cd;
	cd2inv = 1. / cd2;

	c = 300000000.q;
	c2 = c * c;
	c2inv = 1. / c2;

	printf("%18f\n",cd);
	printf("%18f\n",cd2);
	printf("%18f\n",cd2inv);


	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, c);
	if ((size_t) n < sizeof buf)
		printf("%s\n", buf);

	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, c2);
	if ((size_t) n < sizeof buf)
		printf("%s\n", buf);

	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, c2inv);
	if ((size_t) n < sizeof buf)
		printf("%s\n", buf);

	return 0;
}
