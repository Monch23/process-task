#include <stdio.h>

int reverse(int num) {
	int reversed = 0;
	int reminder;
	while (num) {
		reminder = num % 10;
		num /= 10;
		reversed = reversed * 10 + reminder;
	}

	return reversed;
}

int main() {
	int num = 0;
	int reversed = 0;
	
	//puts("Input number");
	scanf("%d", &num);
	
	reversed = reverse(num);

	printf("Reversed number is %d \n", reversed);

	return 0;
}
