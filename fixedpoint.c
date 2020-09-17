#include <stdio.h>

// Bisection Method: multiply all parameters by power of 2
int main()
{
	// sa: shift amount
	// --> multiply constant value in equation
	int x1 = 1, x2 = 2, x3, y, sa = 1;

	x1 = (x1 << 1);
	x2 = (x2 << 1);
	sa = (sa << 1); // 2^1

	for (int i = 0; i < 5; i++) {
		while (x2 - x1 > 1) {	//x2-x1<2 : tolerance value
			x3 = (x1 + x2) / 2; //bisection
			y = (x3*x3*x3) + ((4*sa)*x3*x3) - (10*(sa)*(sa)*(sa)); // y = f(x3), f(x1) < 0, f(x2) > 0

			if (y > 0) {	//if f(x3) is opposite sign of f(x1)
				x2 = x3;
			}
			else {
				x1 = x3;
			}
			printf("root = %d, y = %d\n", x3, y);
		}
		x1 = (x1 << 1);
		x2 = (x2 << 1);
		sa = (sa << 1);
	}
}
