

#include <iostream>

using namespace std;

int gcd (int x, int y) {
	int rem = x % y;
	if (rem == 0) {
		return y;
	}
	else {
		return gcd (y, rem);
	}
}

int main (int argc, char *argv[]) {
	int x = 8;
	int y = 12;
	printf ("\n%d", gcd (x, y));
	return 0;
}
