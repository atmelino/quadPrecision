#include <quadmath.h>
#include <stdlib.h>
#include <stdio.h>

/* What is the velocity of a proton and 10^21eV energy? */

int gr04() {
	double md, cd, c2d, c2invd, betad, gamma2d, gammad, deltaEd, termd, gd, b2d,
			bd, vd, Nvd;
	__float128 mq, cq, c2q, c2invq, betaq, gamma2q, gammaq, deltaEq, termq, gq,
			b2q, bq, vq, Nvq;

	int prec = 20;
	int width = 46;
	char buf[128];
	int n;

	cd = 299792000.;
	c2d = cd * cd;
	c2invd = 1. / c2d;
	md=938272081.3;
	deltaEd = 1E21;
	termd = deltaEd / md ;
	gd = 1. + termd;
	b2d = 1. - 1. / (gd * gd);
	bd = sqrt(b2d);
	vd = bd * cd;
	Nvd=sqrt(2.*deltaEd/md);

	cq = 299792000.q;
	c2q = cq * cq;
	c2invq = 1. / c2q;
	mq=938272081.3q;
	deltaEq = 1E21q;
	termq = deltaEq / mq ;
	gq = 1.q + termq;
	b2q = 1.q - 1.q / gq / gq;
	bq = sqrtq(b2q);
	vq = bq * cq;
	Nvq=sqrtq(2.q*deltaEq/mq);

	printf("Relativistic\n");
	printf("Delta E\n");
	printf("double: %+.20e\n", deltaEd);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, deltaEq);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	printf("Delta E / m c^2\n");
	printf("double: %+.20e\n", termd);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, termq);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	printf("Gamma calculated\n");
	printf("double: %+.20e\n", gd);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, gq);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	printf("Beta^2 calculated\n");
	printf("double: %+.20e\n", b2d);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, b2q);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	printf("Beta calculated\n");
	printf("double: %+.20e\n", bd);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, bq);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	printf("Einstein velocity\n");
	printf("double: %+.20e\n", vd);
	n = quadmath_snprintf(buf, sizeof buf, "%+-#*.20Qe", width, vq);
	if ((size_t) n < sizeof buf)
		printf("quad  : %s\n", buf);

	return 0;
}
