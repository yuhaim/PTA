#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, sum, absSum, temp;
	int stack[5], top = 0;

	scanf("%d %d", &a, &b);
	sum = a + b;
	absSum = abs(sum);

	if(sum<0) printf("-");

	if(absSum>=1000){
		temp = absSum;
		while(temp>=1000){
			stack[++top] = temp%1000;
			temp = temp/1000;
		}
		stack[++top] = temp;
		
		printf("%d,", stack[top--]);
		while(top){
			printf("%03d",stack[top--]);
			if(top) printf(",");
		}
	}else{
		printf("%d", absSum);
	}

	return 0;
}
