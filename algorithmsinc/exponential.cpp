
#include <iostream>

using namespace std;

int calcExp (int number, int power) {
	if (power == 1) {
		return number;
	}
	else {
		return number * calcExp (number, power - 1);
	}
}

int main (int argc, char *argv[]) {
	int number = 2;
	int power = 5;
	int result = calcExp (number, power);
	printf ("\n result = %d",result);
}
