#include <stdio.h>

int main()
{
	char input;
	int stack[102];
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

	while(scanf("%c", &input) && input!='\n') {
		sum += input - '0';
	}
    
    if(!sum) {
        printf("zero");
        return 0;
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
