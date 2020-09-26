#include <stdio.h>

// Bisection Method: multiply all parameters by power of 2
int main()
{
	// sa: shift amount
	// --> multiply constant value in equation
	short x1 = 1, x2 = 2, x3, signbit_y, sa = 1;

	// while "short" doesn't overflow
	for (int i = 0; i < 4; i++) {
		x1 = (x1 << 1);
		x2 = (x2 << 1);
		sa = (sa << 1); // 2^i
		while (x2 - x1 > 1) {	//x2-x1<2 : tolerance value
			x3 = (x1 + x2) / 2; //bisection
			signbit_y = (x3*x3*x3) + ((4 * sa)*x3*x3) - (10 * (sa)*(sa)*(sa)); // y = f(x3), f(x1) < 0, f(x2) > 0
			printf("%d <root(%d) < %d, y = %d\n", x1, x3, x2, signbit_y);
			if (signbit_y > 0) {	//if f(x3) is opposite sign of f(x1)
				x2 = x3;
			}
			else {
				x1 = x3;
			}
		}
	}

	// changed equation to avoid overflow
	for (int i = 0; i < 10; i++) {
		x1 = (x1 << 1);
		x2 = (x2 << 1);
		sa = (sa << 1); // 2^i
		while (x2 - x1 > 1) {	//x2-x1<2 : tolerance value
			x3 = (x1 + x2) / 2; //bisection
			signbit_y = (x3*x3)/sa + 4*x3 - (10*sa*sa)/x3;	// divided by x3*sa to avoid overflow
			printf("%d <root(%d) < %d, y = %d\n", x1, x3, x2, signbit_y);
			if (signbit_y >= 0) {	//if f(x3) is opposite sign of f(x1)
				x2 = x3;
			}
			else {
				x1 = x3;
			}
		}
	}


}
