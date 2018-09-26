#include <stdio.h>

int main()
{
	int input;
	int stack[101];
	int top = 0;
	int sum = 0;

	const char *zero = "zero";
	const char *one = "one";
	const char *two = "two";
	const char *three = "three";
	const char *four = "four";
	const char *five = "five";
	const char *six = "six";
	const char *seven = "seven";
	const char *eight = "eight";
	const char *nine = "nine";

	const char *numbers[] = {zero, one, two, three, four, five, six, seven, eight, nine};

	scanf("%d", &input);

	while(input) {
		stack[++top] = input%10;
		input = input/10;
	}

	while(top) {
		sum += stack[top--];
	}

	while(sum) {
		stack[++top] = sum%10;
		sum = sum/10;
	}

	while(top) {
		printf("%s", numbers[stack[top--]]);
		if(top)
			printf(" ");
	}

	return 0;
}
