#include <stdio.h>

int main()
{
	int K, entry = 1, nonNegative = 0;
	int firstItem, lastItem;
	int maxSubSum = 0;
	int maxFirst, maxLast;
	int currSubSum = 0;
	int currItem;
	int currFirst, currLast;
	int disguard = 0;

	scanf("%d",&K);

	while(scanf("%d", &currItem) != EOF){
		if(entry) {
			firstItem = currItem;
			entry = 0;
			currFirst = currItem;
			currLast = currItem;
			maxFirst = currItem;
			maxLast = currItem;
		}
		lastItem = currItem;

		if(disguard) { 
			currFirst = currItem;
			disguard = 0;
		}

		currSubSum += currItem;
		currLast = currItem;

		if(currSubSum<0) {
			currSubSum = 0;
			disguard = 1; 
		}

		if(currSubSum>maxSubSum || !nonNegative) {
			maxSubSum = currSubSum;
			maxFirst = currFirst;
			maxLast = currLast;
		}

		if(currItem>=0)	nonNegative = 1;
	}
	
	if(maxSubSum == 0 && !nonNegative){
		maxFirst = firstItem;
		maxLast = lastItem;
	}

	printf("%d %d %d\n", maxSubSum, maxFirst, maxLast);

	return 0;
}
