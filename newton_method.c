#include <stdio.h>
#include <math.h>

// f(x) = x^3 + 4x^2 - 10
double f(double x)
{
	return x * x*x + 4 * x*x - 10;
}
// f'(x) = 3x^2 + 8x
double f_prime(double x)
{
	return 3 * x*x + 8 * x;
}

int main()
{
	int nmax = 100;	// nmax = maximum iteration
	double x, x0, tol;	// x = intercept(root)

	x0 = -1;	// initial value
	tol = 1.0e-6;	// tolerance

	for (int n = 0; n < nmax; n++) {
		x = x0 - f(x0) / f_prime(x0);	// tangent equation to get intercept(root)
		if (fabs(x - x0) < tol)		//stop condition
		{
			printf("root is %lf\n", x);
			break;
		}
		x0 = x;	// initial value update
		printf("[iter:%d]  f(x):%lf  x:%lf\n", n, f(x), x);
	}
	return 0;
}
