#include <quadmath.h>
#include <stdlib.h>
#include <stdio.h>

/* How much energy is needed to accelerate a body of 1 kg mass to 1/10th of the speed of light? */

int gr02() {
	double md, cd, c2d, c2invd, betad, gamma2d, gammad, deltaEd, termd, gd, b2d,
			bd;
	__float128 mq, cq, c2q, c2invq, betaq, gamma2q, gammaq, deltaEq, termq, gq,
			b2q, bq;

	int prec = 20;
	int width = 46;
	char buf[128];
	int n;

	md = 1.0;
	cd = 300000000.;
	c2d = cd * cd;
	c2invd = 1. / c2d;
	betad = 0.1;
	gamma2d = 1. / (1 - betad * betad);
	gammad = sqrt(gamma2d);
	deltaEd = (gammad - 1.) * c2d;
	termd = deltaEd / md / c2d;
	gd = 1. + termd;
	b2d = 1. - 1. / (gd * gd);
	bd = sqrt(b2d);

	mq = 1.q;
	cq = 300000000.q;
	c2q = cq * cq;
	c2invq = 1. / c2q;
	betaq = 0.1q;
	gamma2q = 1.q / (1.q - betaq * betaq);
	gammaq = sqrt(gamma2q);
	deltaEq = (gammaq - 1.q) * c2q;
	termq = deltaEq / mq / c2q;
	gq = 1.q + termq;
	b2q = 1.q - 1.q / gq / gq;
	bq = sqrtq(b2q);

	printf("Beta\n");
	printf("double: %18f\n", betad);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, betaq);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	printf("Gamma\n");
	printf("double: %18f\n", gammad);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, gammaq);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	printf("Delta E\n");
	printf("double: %18f\n", deltaEd);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, deltaEq);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	printf("Delta E / m c^2\n");
	printf("double: %18f\n", termd);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, termq);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	printf("Gamma calculated\n");
	printf("double: %18f\n", gd);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, gq);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	printf("Beta^2 calculated\n");
	printf("double: %18f\n", b2d);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, b2q);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	printf("Beta calculated\n");
	printf("double: %18f\n", bd);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, bq);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	return 0;
}
