#include <stdio.h>

int power(int num) {
	return num * num;
}

int main() {
	int num = 11;

	printf("power of %d is %d \n", num, power(num));

	return 0;
}
