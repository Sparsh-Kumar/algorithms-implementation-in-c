
#include <iostream>
#include <stdlib.h>

using namespace std;

int CalcFact (int number) {
	if (number == 1) {
		return number;
	}
	else {
		return number * CalcFact (number - 1);
	}
}

int main (int argc, char *argv[]) {
	int number = 4;
	int result = CalcFact (number);
	printf ("\n Factorial of number = %d is %d",number,result);
	return 0;
}
