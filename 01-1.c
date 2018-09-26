#include <stdio.h>
#include <stdlib.h>

int main()
{
	int K;
	int maxSum = 0;
	int currSubList = 0;
	int currItem;
	//int *list = NULL;

	scanf("%d",&K);
	//list = (int *)malloc(K, sizeof(int));

	while(scanf("%d", &currItem) != EOF){
		currSubList += currItem;
		if(currSubList<0) currSubList = 0;
		if(currSubList>maxSum) maxSum = currSubList;
	}
	
	printf("%d\n", maxSum);

	return 0;
}
