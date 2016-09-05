#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int reverse(int x)
{
	long _x = x;
	bool is_neg = _x < 0;
	long y = 0;

	if (_x < 0)
		_x *= -1;

	while (_x) {
		y*=10;
		y+=_x % 10;
		_x/=10;
	}

	if (y > INT_MAX)
		return 0;

	if (is_neg)
		y *= -1;

	if (y < INT_MIN)
		return 0;

	return y;
}

int main() {
	int a = 1534236469;
	int b = -2147483648;
	int c = -2147483;
	int d = 2183648;
	printf("%d -> %d\n", a, reverse(a));
	printf("%d -> %d\n", b, reverse(b));
	printf("%d -> %d\n", c, reverse(c));
	printf("%d -> %d\n", d, reverse(d));
	return 0;
}
