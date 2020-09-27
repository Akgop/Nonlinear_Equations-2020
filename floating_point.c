#include <stdio.h>

// Bisection Method: multiply all parameters by power of 2
int main()
{
	// floating point method
	float x1 = 1, x2 = 2, x3, signbit_y;
	float tol = 1.0e-6;

	// while "short" doesn't overflow
	while(x2 - x1 > tol){
		x3 = (x1 + x2) / 2;
		signbit_y = x3 * x3*x3 + 4 * x3*x3 - 10;
		printf("x1(%.8f) < root(%.8f) < x2(%.8f), y = %.8f\n", x1, x3, x2, signbit_y);
		if (signbit_y >= 0) {	//if f(x3) is opposite sign of f(x1)
			x2 = x3;
		}
		else {
			x1 = x3;
		}
	}
}
