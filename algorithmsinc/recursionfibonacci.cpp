

#include <iostream>

using namespace std;

int CalcFib (int x) {
	if (x == 0) {
		return 0;
	}
	else if (x == 1) {
		return 1;
	}
	else {
		return CalcFib (x - 1) + CalcFib (x - 2);
	}
}

int main (int argc, char *argv[]) {
	int x = 4;
	int result = CalcFib (x);
	printf ("\n%d",result);
	return 0;
}
